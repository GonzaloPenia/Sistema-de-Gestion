#ifndef FUNCIONES_CARRITO_H_INCLUDED
#define FUNCIONES_CARRITO_H_INCLUDED

Articulo seleccionarArticulo() {
    int idArticulo;
    Articulo Articulo;
    ArchivoArticulo ArchivoArticulo;
    listarArticuloPorPrecioDeMayorAMenor();
    
    cout << endl << "Ingrese el ID del articulo que desea agregar al carrito: ";
    //FALTA VALIDACION
    cin >> idArticulo;
    Articulo=ArchivoArticulo.leerArchivo(idArticulo);
    return Articulo;
}

bool validarStockDisponible(Articulo& articulo, float cantidad) {
    if (articulo.getUnidades() < cantidad) {
        cout << endl << "ERROR: Stock insuficiente!" << endl;
        cout << "Stock disponible: " << articulo.getUnidades() << endl;
        cout << "Cantidad solicitada: " << cantidad << endl << endl;
        return false;
    }
    return true;
}

Item crearItemDesdeArticulo(Articulo& articulo, float cantidad, int tipoCliente) {
    // Validar que el articulo tenga ID valido
    if (articulo.getId() == 0) {
        cout << endl << "ERROR: Articulo invalido." << endl;
        return Item(); // Retorna item vacio
    }

    // Crear el item usando el constructor
    Item item(articulo, cantidad, tipoCliente);

    return item;
}

int pedirCantidad(Articulo& articulo) {
    int cantidad;
    bool cantidadValida = false;

    do {
        cout << endl << "Ingrese la cantidad deseada: ";
        cin >> cantidad;

        if (cantidad <= 0) {
            cout << "La cantidad debe ser mayor a 0. Intente nuevamente." << endl;
        } else if (!validarStockDisponible(articulo, cantidad)) {
            cout << "Intente nuevamente con una cantidad valida." << endl;
        } else {
            cantidadValida = true;
        }
    } while (!cantidadValida);

    return cantidad;
}

Factura cargarItemEnFactura(Factura& factura, Item& nuevoItem) {
    // Obtener el detalle actual de la factura
    Detalle detalleTemp = factura.getDetalleVenta();

    // Asignar número de item correcto
    nuevoItem.setNroItem(detalleTemp.getTamActual() + 1);

    // Agregar el item al detalle
    detalleTemp.agregarItem(nuevoItem);

    // Actualizar la factura con el nuevo detalle
    factura.setDetalleVenta(detalleTemp);

    // Recalcular importes
    factura.calcularImportes();

    cout << endl << "Articulo agregado exitosamente al carrito!" << endl;

    return factura;
}

void mostrarResumenCarrito(Detalle& detalle, float importeTotal) {
    int cantidadItems = detalle.getTamActual();

    cout << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << " RESUMEN DEL CARRITO" << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << " Cantidad de items: " << cantidadItems << endl;
    cout << fixed << setprecision(2);
    cout << " Total: $" << importeTotal << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << endl;
}

void menuGestionCarrito() {
    int opcion = 1;
    while (opcion != 0) {
        systemClsEmisionFactura();
        Factura factura;
        // Mostrar resumen del carrito
        Detalle detalleActual = factura.getDetalleVenta();
        mostrarResumenCarrito(detalleActual, factura.getImporteTotal());

        // Mostrar detalle completo si hay items
        if (detalleActual.getTamActual() > 0) {
            factura.mostrarDetalleCompleto();
            cout << endl;
        }

        Factura auxFactura = factura; // Copia para modificaciones temporales

        cout << "GESTION DEL CARRITO" << endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        cout << "1 - Agregar articulo al carrito" << endl;
        cout << "2 - Modificar cantidad de un item" << endl;
        cout << "3 - Eliminar item del carrito" << endl;
        cout << "4 - Vaciar carrito completo" << endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        cout << "5 - CONFIRMAR Y CONTINUAR" << endl;
        cout << "0 - CANCELAR" << endl << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                //LOOP PARA AGREGAR ARTICULOS HASTA CONFIRMAR
                systemClsEmisionFactura();
                cout << "AGREGAR ARTICULO AL CARRITO" << endl;
                Articulo articulo = seleccionarArticulo();
                int cantidad = pedirCantidad(articulo);

                Item nuevoItem;
                nuevoItem = crearItemDesdeArticulo( articulo, cantidad, factura.getTipoCliente() );

                // Solo agregar si el item es válido (ID != 0)
                if (nuevoItem.getIdArticulo() != 0) {
                    factura = cargarItemEnFactura(factura, nuevoItem);
                }

                system("pause");
                break;
            }

            case 2:
                // Modificar cantidad (por implementar)
                cout << endl << "Opcion en desarrollo..." << endl;
                system("pause");
                break;

            case 3:
                // Eliminar item (por implementar)
                cout << endl << "Opcion en desarrollo..." << endl;
                system("pause");
                break;

            case 4: {
                // Vaciar carrito
                systemClsEmisionFactura();
                cout << "VACIAR CARRITO" << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << "Esta seguro que desea vaciar todo el carrito?" << endl;

                if (confirmacion()) {
                    Detalle detalleVacio;
                    factura.setDetalleVenta(detalleVacio);
                    factura.calcularImportes();
                    cout << "Carrito vaciado exitosamente." << endl;
                }
                break;
            }

            case 5:
                // Confirmar y continuar
                if (factura.getDetalleVenta().getTamActual() == 0) {
                    cout << endl << "ERROR: El carrito esta vacio. Agregue al menos un articulo." << endl;
                    system("pause");
                    opcion = 1; // No salir del menu
                } else {
                    cout << endl << "Carrito confirmado. Continuando..." << endl;
                    system("pause");
                    opcion = 0; // Salir del menu
                }
                break;

            case 0:
                cout << endl << "Gestion del carrito cancelada." << endl;
                system("pause");
                break;

            default:
                cout << endl << "Opcion invalida." << endl;
                system("pause");
                break;
        }
    }
}

#endif // FUNCIONES_CARRITO_H_INCLUDED
