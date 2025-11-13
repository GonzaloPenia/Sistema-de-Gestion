void listarFacturas(){
    ArchivoFactura archivo("../../data/facturas.dat");
    Factura regFactura;

    int cantidad = archivo.contarRegistros();

    if(cantidad <= 0){
        cout << "No hay facturas para mostrar." << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){
        regFactura = archivo.leerRegistro(i);
        regFactura.Mostrar();
    }
    system("pause");
}

void listarFacturasRangoFecha(Fecha fechaInicial, Fecha fechaFinal){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    int cantidad = regArchivoFactura.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if(regFactura.getFecha()>=fechaInicial && regFactura.getFecha()<=fechaFinal){
            regFactura.MostrarFacturaResumen();
        }
    }
}

void listarFacturasCliente(int idCliente){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    int cantidad = regArchivoFactura.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if (regFactura.getIdCliente() == idCliente){
            regFactura.MostrarFacturaResumen();
        }
        
    }
}

void listarFacturasArticulo(int idArticulo){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    int cantidad = regArchivoFactura.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
            for (int j=0; j<regFactura.getDetalleVenta().getTamActual(); j++){
                if (regFactura.getDetalleVenta().getItem(j).getIdArticulo() == idArticulo){
                    regFactura.MostrarFacturaArticulo(j);
                }
            }
    }
}

void generarFactura(Factura& factura){
    ArchivoFactura ArchivoFactura("../../data/facturas.dat");

    // Verificar si el archivo existe
    int verificacion = ArchivoFactura.verificarArchivoExistente();

    if (verificacion == 0) {
        ArchivoFactura.crearArchivoVacio();
    }

    // Calcular el ID autoincrementable
    int cantidadFacturas = ArchivoFactura.contarRegistros();
    int nuevoId;

    if (cantidadFacturas > 0) {
        // Buscar el ID maximo existente
        int maxId = 0;
        for (int i = 0; i < cantidadFacturas; i++) {
            Factura facturaTemp = ArchivoFactura.leerRegistro(i);
            if (facturaTemp.getId() > maxId) {
                maxId = facturaTemp.getId();
            }
        }
        nuevoId = maxId + 1;
    } else if (cantidadFacturas == 0) {
        nuevoId = 1; // Primera factura
    } else {
        cout << "ERROR: No se pudo acceder al archivo para contar registros." << endl;
        system("pause");
        return;
    }

    // Asignar el ID a la factura
    factura.setId(nuevoId);

    // Guardar la factura
    if (ArchivoFactura.agregarRegistro(factura)){
        cout << endl << "==================================================" << endl;
        cout << "La factura Nro. " << nuevoId << " ha sido emitida correctamente." << endl;
        cout << "==================================================" << endl << endl;
        system("pause");
    }
    else{
        cout << endl << "ERROR: Hubo un error al momento de intentar guardar la factura." << endl;
        system("pause");
    }
}

void listadoDeFacturas(){
    
    cout<<"2-LISTADO DE FACTURAS"<<endl;
    
    int opcion=1;
    while (opcion!=0){
        system ("cls");
        //mostrarSubMenuListarEmisiones();       

            
                system("cls");
                mostrarSubMenuListarFacturas();
                int opcion2;
                cin >> opcion2;
                switch (opcion2){

                    case 1: {   ///LISTAR TODAS LAS FACTURAS
                        systemClsListadoFactura();
                        listarFacturas();
                        break;
                    }
                    
                    case 2: {   ///LISTADO POR RANGO DE FECHA
                        systemClsListadoFactura();
                        Fecha fechaInicial, fechaFinal;
                        fechaFinal = rangoFecha(fechaInicial);
                        systemClsListadoFactura();
                        cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;
                        listarFacturasRangoFecha(fechaInicial, fechaFinal);
                        system ("pause");
                        break;
                    }

                    case 3: {   ///LISTADO POR CLIENTE
                        systemClsListadoFactura();
                        Fecha fechaInicial, fechaFinal;
                        fechaFinal = rangoFecha(fechaInicial);
                        systemClsListadoFactura();
                        cout << endl << "Ingrese el Id del Cliente: ";
                        int idCliente;
                        cin >> idCliente;

                        ArchivoCliente regArchivoCliente;

                        while (regArchivoCliente.buscarRegistro(idCliente)==-1){
                            cout << endl << "No se ha encontrado un cliente con ese id." << endl;
                            cout << endl << "Ingrese el Id del Cliente: ";
                            cin >> idCliente;
                        }
                        listarFacturasCliente(idCliente);
                        system ("pause");
                        break;
                    }

                    case 4: {   ///LISTADO POR ARTICULO 
                        systemClsListadoFactura();
                        cout << endl << "Ingrese el Id del Articulo: ";
                        int idArticulo;
                        cin >> idArticulo;

                        ArchivoArticulo regArchivoArticulo;

                        while (regArchivoArticulo.buscarRegistro(idArticulo)==-1){
                            cout << endl << "No se ha encontrado un cliente con ese id." << endl;
                            cout << endl << "Ingrese el Id del Articulo: ";
                            cin >> idArticulo;
                        }

                        listarFacturasArticulo(idArticulo);
                        system ("pause");
                        break;
                    }

                    case 0:
                        cout << endl << "0 - VOLVER ATRAS" << endl << endl;
                        cout << "Usted ha decidido salir del Listado de Facturas." << endl << endl;
                        opcion = 0;
                        system ("pause");
                        break;

                    default:
                        cout << endl << "ERROR" << endl << endl;
                        cout << "Algo salio mal, intente nuevamente" << endl << endl;
                        system ("pause");
                        break;
                }        
    }
}

