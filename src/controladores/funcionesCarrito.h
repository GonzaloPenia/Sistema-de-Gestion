#ifndef FUNCIONES_CARRITO_H_INCLUDED
#define FUNCIONES_CARRITO_H_INCLUDED

void mostrarMenu() {
    cout << "MENU DE GESTION DEL CARRITO" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "1 - Agregar Articulo al Carrito" << endl;
    cout << "2 - Modificar Cantidad de un Item (En desarrollo)" << endl;
    cout << "3 - Eliminar Item del Carrito (En desarrollo)" << endl;
    cout << "4 - Vaciar Carrito" << endl;
    cout << "5 - Confirmar y Continuar" << endl;
    cout << "0 - Cancelar y Salir" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Ingrese una opcion: ";
}   


Articulo seleccionarArticulo() {
    int idArticulo;
    Articulo Articulo;
    ArchivoArticulo ArchivoArticulo;

    listaArticulosSimplificada();
    
    cout << endl << "Ingrese el ID del articulo que desea agregar al carrito: ";
    cin >> idArticulo;
    Articulo=ArchivoArticulo.obtenerArticulo(idArticulo);
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

Item conversionArticuloItem(Articulo& articulo, int cantidad, int tipoCliente) {
    int CantidadDeItems = cantidad;
    
    Item item(articulo, CantidadDeItems, tipoCliente);

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
    float importe = importeTotal; // Ya calculado en la factura
    cout << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << " RESUMEN DEL CARRITO" << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << " Cantidad de items: " << cantidadItems << endl;
    cout << fixed << setprecision(2);
    cout << " Total: $" << importe << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << endl;
}

void gestionCarrito() {
    int opcion = 1;
    Factura factura;
    while (opcion != 0) {
        systemClsEmisionFactura();
        // Mostrar resumen del carrito
        
        
        Detalle detalleActual = factura.getDetalleVenta();
        mostrarResumenCarrito(detalleActual, factura.getImporteTotal());

        // Mostrar detalle completo si hay items
        if (detalleActual.getTamActual() > 0) {
            //factura.mostrarDetalleCompleto();
            cout << endl;
        }
        
        mostrarMenu();
        cin >> opcion;


        switch (opcion) {
            
            case 1: {
                //LOOP PARA AGREGAR ARTICULOS HASTA CONFIRMAR
                systemClsEmisionFactura();
                cout << "AGREGAR ARTICULO AL CARRITO" << endl;
                Articulo articulo = seleccionarArticulo();
                cout << endl << "Articulo seleccionado:" << endl;
                articulo.Mostrar();
                int cantidad = pedirCantidad(articulo);
                cout << "Cantidad solicitada: " << cantidad << endl << endl;














                Item nuevoItem;
                nuevoItem = conversionArticuloItem( articulo, cantidad, factura.getTipoCliente() );

                nuevoItem.Mostrar();
                system("pause");
                // VALIDACION DE ID
                if (nuevoItem.getIdArticulo() != 0) factura = cargarItemEnFactura(factura, nuevoItem);

                system("pause");
                break;
            }

            
            case 2:
                // MODIFICAR CANTIDAD DE UN ITEM (por implementar).
                cout << endl << "Opcion en desarrollo..." << endl;
                system("pause");
                break;

            
            case 3:
                // ELIMINAR ITEM DEL CARRITO (por implementar)
                cout << endl << "Opcion en desarrollo..." << endl;
                system("pause");
                break;

            
            case 4: {
                // VACIAR CARRITO
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
                // CONFIRMAR Y CONTINUAR
                if (factura.getDetalleVenta().getTamActual() == 0) {
                    cout << endl << "EL CARRITO ESTA VACIO AGREGUE AL MENOS UN ARTICULO" << endl;
                    system("pause");
                    opcion = 1; // No salir del menu
                } else {
                    cout << endl << "CARRITO CONFIRMADO. CONTINUANDO..." << endl;
                    generarFactura(factura);
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
