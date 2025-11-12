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

Factura eliminarItemDelCarrito(Factura& factura) {
    cout << "ELIMINAR ITEM DEL CARRITO (En desarrollo)" << endl;
    cout << "Esta funcionalidad estara disponible en futuras actualizaciones." << endl;
    return factura;
}

Factura modificarCarrito(Factura& factura) {
    cout << "MODIFICAR ITEM DEL CARRITO (En desarrollo)" << endl;
    cout << "Esta funcionalidad estara disponible en futuras actualizaciones." << endl;
    return factura;
}

Cliente elegirCliente(){
    Cliente cliente;
    ArchivoCliente archivoCliente;
    int idCliente;

    cout << "PARA CONTINUAR DEBE SELECCIONAR UN CLIENTE." << endl << endl;

    do {
        listarClientes();
        cout << endl << "INGRESE EL ID DEL CLIENTE AL QUE SE LE VA A VENDER: ";
        cin >> idCliente;

        cliente = archivoCliente.buscarCliente(idCliente);


        if (cliente.getId() == -1) {
            cout << endl << "ERROR: No se encontro un cliente con el ID " << idCliente << endl;
            cout << "Por favor, intente nuevamente." << endl << endl;
            system("pause");
            system("cls");
        }
    } while (cliente.getId() == -1);

    cout << endl << "Cliente seleccionado: " << cliente.getNombre() << endl;

    return cliente;
}

Vendedor elegirVendedor(){

    Vendedor vendedor;
    ArchivoVendedor archivoVendedor;
    int idVendedor;

    cout << "PARA CONTINUAR DEBE SELECCIONAR UN VENDEDOR." << endl << endl;

    do {
        listarVendedores();
        cout << endl << "INGRESE EL ID DEL VENDEDOR A CARGO DE LA VENTA: ";
        cin >> idVendedor;

        vendedor = archivoVendedor.buscarVendedor(idVendedor);

        if (vendedor.getId() == -1) {
            cout << endl << "ERROR: No se encontro un vendedor con el ID " << idVendedor << endl;
            cout << "Por favor, intente nuevamente." << endl << endl;
            system("pause");
            system("cls");
        }
    } while (vendedor.getId() == -1);

    cout << endl << "Vendedor seleccionado: " << vendedor.getNombre() << endl;

    return vendedor;
}

Factura cargarDatos ( Factura factura, Cliente cliente, Vendedor vendedor, int tipoCompra, char* condicionPago){
        factura.setIdVendedor    ( vendedor.getId() );
        factura.setNombreVendedor( vendedor.getNombre() );
        factura.setIdCliente     ( cliente.getId() );
        factura.setCuitCliente   ( cliente.getCuit() );
        factura.setTipoCliente   ( cliente.getTipo() );
        factura.setNombreCliente ( cliente.getNombre() );
        factura.setDireccion     ( cliente.getDireccion() );
        factura.setTipoCompra    (tipoCompra);
        factura.setCondicionPago (condicionPago);
        Fecha fechaActual;
        factura.setFecha(fechaActual);
        factura.setEstado(true);
        return factura;
}

void elegirDatosVenta(int& tipoCompra, char* condicionPago) {
    cout << endl << "DATOS DE LA VENTA" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Seleccione el tipo de compra:" << endl;
    cout << "1 - Contado Directo" << endl;
    cout << "2 - Cuenta Corriente" << endl;
    cout << "Ingrese una opcion (1 o 2): ";

    do {
        cin >> tipoCompra;
        if (tipoCompra != 1 && tipoCompra != 2) {
            cout << "Opcion invalida. Ingrese 1 o 2: ";
        }
    } while (tipoCompra != 1 && tipoCompra != 2);

    cout << endl << "Ingrese la condicion de pago (ej: Contado, 30 dias, 60 dias): ";
    cin.ignore();
    cin.getline(condicionPago, 35);

    cout << endl << "Datos de venta configurados correctamente." << endl;
    system("pause");
}

void vaciarCarrito(Factura& factura) {
    cout << "VACIAR CARRITO" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Esta seguro que desea vaciar todo el carrito?" << endl;

    if (confirmacion()) {
        Detalle detalleVacio;
        factura.setDetalleVenta(detalleVacio);
        factura.calcularImportes();
        cout << "Carrito vaciado exitosamente." << endl;
    }
}

Articulo elegirArticulo() {
    int idArticulo;
    Articulo Articulo;
    ArchivoArticulo ArchivoArticulo;

    cout << "AGREGAR ARTICULO AL CARRITO" << endl;
    
    listaArticulosSimplificada();
    
    cout << endl << "Ingrese el ID del articulo que desea agregar al carrito: ";
    cin >> idArticulo;
    Articulo=ArchivoArticulo.obtenerArticulo(idArticulo);
    cout << endl << "Articulo seleccionado:" << Articulo.getDescripcion() << endl;
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
    cout<<"EMISION DE FACTURA."<<endl;
    cout<<"---------------------"<<endl;
    int opcion = 1;
    Factura factura;
    Cliente cliente = elegirCliente();
    Vendedor vendedor = elegirVendedor();

    // Elegir tipo de compra y condicion de pago
    int tipoCompra;
    char condicionPago[35];
    
    while (opcion != 0) {
        systemClsEmisionFactura();
        
        cout<<"CLIENTE: "<< cliente.getNombre() <<endl;
        cout<<"VENDEDOR: "<< vendedor.getNombre() <<endl;
        Detalle detalleActual = factura.getDetalleVenta();

        // Mostrar detalle completo si hay items
        if (detalleActual.getTamActual() > 0) {
            factura.mostrarDetalleCompleto();
            cout << endl;
        }
        
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
                case 1: {
                    //LOOP PARA AGREGAR ARTICULOS HASTA CONFIRMAR
                    systemClsEmisionFactura();
                    Articulo articulo = elegirArticulo();
                    int cantidad = pedirCantidad(articulo);

                    Item nuevoItem = conversionArticuloItem( articulo, cantidad, factura.getTipoCliente() );

                    if (nuevoItem.getIdArticulo() != 0) factura = cargarItemEnFactura(factura, nuevoItem);
                    else cout << "Estas intentando ingresar un articulo con un ID inválido." << endl;

                    break;
                }
                
                case 2:
                    modificarCarrito(factura);
                    system("pause");
                    break;

                case 3:
                    eliminarItemDelCarrito(factura);
                    system("pause");
                    break;
                
                case 4: {
                    systemClsEmisionFactura();
                    vaciarCarrito(factura);
                    break;
                }

                // CONFIRMAR Y CONTINUAR
                case 5:
                    if (factura.getDetalleVenta().getTamActual() == 0) {
                        cout << endl << "EL CARRITO ESTA VACIO AGREGUE AL MENOS UN ARTICULO." << endl;
                        cout << endl << "TOQUE ENTER PARA CONTINUAR..." << endl;
                        system("pause");
                        opcion = 1;

                    } else {
                        // Cargar datos de la venta
                        elegirDatosVenta(tipoCompra, condicionPago);
                        factura = cargarDatos( factura, cliente, vendedor, tipoCompra, condicionPago );
                        generarFactura(factura);

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
