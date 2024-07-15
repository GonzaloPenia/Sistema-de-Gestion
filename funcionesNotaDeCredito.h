#ifndef FUNCIONESNOTADECREDITO_H_INCLUDED
#define FUNCIONESNOTADECREDITO_H_INCLUDED

///FUNCIONES PARA LA EMISION DE NOTAS DE CREDITO

int emisionMain(NotaDeCredito& regNotaDeCredito);

bool cargarCliente(NotaDeCredito& regNotaDeCredito);
bool cargarVendedor(NotaDeCredito& regNotaDeCredito);
bool cargarDatosVenta(NotaDeCredito& regNotaDeCredito);
void cargarDetalleVenta(NotaDeCredito& regNotaDeCredito);

void cargaArticulosEmision(NotaDeCredito& regNotaDeCredito);
void modificarDetalleVenta (NotaDeCredito& regNotaDeCredito);
void borrarItemDetalleVenta(NotaDeCredito& regNotaDeCredito);
void modificarDatosEmision(NotaDeCredito& regNotaDeCredito);
void mostrarVistaPrevia(NotaDeCredito& regNotaDeCredito);

int confirmacionNotaDeCredito (NotaDeCredito& regNotaDeCredito);
int cancelacionNotaDeCredito (NotaDeCredito& regNotaDeCredito);

void altaNotaDeCredito(NotaDeCredito& regNotaDeCredito);
void imprimirNotaDeCreditoDesdeArchivo(NotaDeCredito& regNotaDeCredito);
void imprimirNotaDeCredito(NotaDeCredito& regNotaDeCredito);
void actualizarStock(NotaDeCredito& regNotaDeCredito);


void cargaArticulosEmision(NotaDeCredito& regNotaDeCredito){
    int opcion;

    do{
        cargarDetalleVenta(regNotaDeCredito);
        systemClsEmisionNotaDeCredito();

        mostrarMenuContinuarCargaDetalle(); //1-SEGUIR CARGANDO, 0-TERMINAR CARGA
        cin>>opcion;
        while (opcion!=0&&opcion!=1){
            cout << "Opcion invalida. Vuelva a intentar." <<endl<<endl;
            mostrarMenuContinuarCargaDetalle(); //1-SEGUIR CARGANDO, 0-TERMINAR CARGA
            cin>>opcion;
        }

        if (opcion){
            cout << endl << "Usted ha decidido continuar la carga"<<endl<<endl;
        }else{
            cout << endl << "Usted ha decidido finalizar la carga"<<endl<<endl;
        }
        system ("pause");
        systemClsEmisionNotaDeCredito();

    }while(opcion);
    regNotaDeCredito.calcularImportes();
    regNotaDeCredito.mostrarDetalleCompleto();
    cout << endl;
    system ("pause");
    systemClsEmisionNotaDeCredito();
}

void modificarDatosEmision(NotaDeCredito& regNotaDeCredito){
    systemClsEmisionNotaDeCredito();
    mostrarSubmenuEmisionModificar();
    int sub_menu;
    cin >> sub_menu;
    systemClsEmisionNotaDeCredito();
    switch(sub_menu){

    case 1:
        cout<<"MODIFICAR DATOS DEL CLIENTE."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regNotaDeCredito.MostrarClienteEmision();
        cout << endl << "Proceda a ingresar el nuevo cliente." << endl << endl;
        cargarCliente(regNotaDeCredito);
        systemClsEmisionNotaDeCredito();
        break;

    case 2:
        cout<<"MODIFICAR DATOS DEL VENDEDOR."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regNotaDeCredito.MostrarVendedorEmision();
        cout << endl << "Proceda a ingresar el nuevo vendedor." << endl << endl;
        cargarVendedor(regNotaDeCredito);
        systemClsEmisionNotaDeCredito();
        break;

    case 3:
        cout<<"MODIFICAR DATOS DE VENTA."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regNotaDeCredito.MostrarDatosVentaEmision();
        cout << endl << "Proceda a ingresar los nuevos datos de venta." << endl << endl;
        cargarDatosVenta(regNotaDeCredito);
        systemClsEmisionNotaDeCredito();
        break;

    case 4:
        cout<<"MODIFICAR ITEMS DEL DETALLE DE VENTA"<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        modificarDetalleVenta(regNotaDeCredito);
        systemClsEmisionNotaDeCredito();
        break;

    case 0:
        cout << endl << "Usted ha decidido terminar la modificacion." << endl << endl;
        system ("pause");
        break;

    default:
        cout << endl << "Algo salio mal, intente nuevamente" << endl << endl;
        system ("pause");
        break;
    }
}

void mostrarVistaPrevia(NotaDeCredito& regNotaDeCredito){
    systemClsEmisionNotaDeCredito();
    cout << "VISTA PREVIA DE LA NOTA DE CREDITO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl << endl;
    regNotaDeCredito.Mostrar();
    system ("pause");
}

int confirmacionNotaDeCredito (NotaDeCredito& regNotaDeCredito){

    systemClsEmisionNotaDeCredito();
    cout << "CONFIRMAR NOTA DE CREDITO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Usted esta a punto de CONFIRMAR la v." << endl << endl;
    //Fecha fecha;
    //fecha.cargarFechaSistema();
    //regNotaDeCredito.setFecha(fecha);
    regNotaDeCredito.Mostrar();
    bool confirmar;
    confirmar = confirmacion();
    systemClsEmisionNotaDeCredito();
    if (confirmar){
        cout << endl << "La nota de credito ha sido confirmada con exito." << endl << endl;
        altaNotaDeCredito(regNotaDeCredito);
        imprimirNotaDeCredito(regNotaDeCredito);
        recaudacionCredito(regNotaDeCredito.getImporteTotal(), regNotaDeCredito.getIdCliente());
        actualizarStock(regNotaDeCredito);
        return 0;
    } else {
        cout << endl << "Usted ha decidido no confirmar la nota de credito." << endl << endl;
        return 1;
    }
    system ("pause");
}

int cancelacionNotaDeCredito (NotaDeCredito& regNotaDeCredito){
    systemClsEmisionNotaDeCredito();
    cout << "CANCELAR NOTA DE CREDITO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Usted esta a punto de CANCELAR la nota de credito." << endl;
    bool cancelar;
    cancelar = confirmacion();
    systemClsEmisionNotaDeCredito();
    if (cancelar){
        cout << "La nota de credito ha sido cancelada con exito." << endl << endl;
        return 0;
    } else {
        cout << "Usted ha decidido no cancelar la nota de credito." << endl << endl;
        return 1;
    }
}

/// 1 - FUNCIONES PRINCIPALES PARA EMISION DE NOTAS DE CREDITO
int emisionMain(NotaDeCredito& regNotaDeCredito){
    int menu=1;
    bool banderaPrimerIngreso=true;
    int contador=0;
    while(menu!=0){
        bool salida=false;
        int opcion=0;
        systemClsEmisionNotaDeCredito();
        if (banderaPrimerIngreso){

            if (!salida && contador>=1){
                opcion = 0;
                while (opcion!=1 && opcion!=2){
                    cout << "Ya hay un cliente cargado." << endl << endl;
                    regNotaDeCredito.MostrarClienteEmision();
                    cout << endl << "Desea conservarlo? (1-SI, 2-NO): ";
                    cin >> opcion;
                    cout << endl;
                    if (opcion==1){
                        cout << "Usted ha decidido conservar el cliente" << endl << endl;
                    } else if (opcion==2){
                        cout << "Usted ha decidido modificar el cliente" << endl << endl;
                    } else {
                        cout << "Opcion invalida. Vuelva a intentar" << endl << endl;
                    }
                }
                system ("pause");
                systemClsEmisionNotaDeCredito();
            }

            if (!salida&&(contador<1 || opcion == 2)){
                cout<<"CARGAR CLIENTE."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarCliente(regNotaDeCredito);
                salida ? contador : contador++;
                systemClsEmisionNotaDeCredito();
            }

            if (!salida && contador>=2){
                opcion = 0;
                while (opcion!=1 && opcion!=2){
                    cout << "Ya hay un vendedor cargado." << endl << endl;
                    regNotaDeCredito.MostrarVendedorEmision();
                    cout << endl << "Desea conservarlo? (1-SI, 2-NO): ";
                    cin >> opcion;
                    cout << endl;
                    if (opcion==1){
                        cout << "Usted ha decidido conservar el vendedor" << endl << endl;
                    } else if (opcion==2){
                        cout << "Usted ha decidido modificar el vendedor" << endl << endl;
                    } else {
                        cout << "Opcion invalida. Vuelva a intentar" << endl << endl;
                    }
                }
                system ("pause");
                systemClsEmisionNotaDeCredito();
            }

            if (!salida&&(contador<2 || opcion == 2)){
                cout<<"CARGAR VENDEDOR."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarVendedor(regNotaDeCredito);
                salida ? contador : contador++;
                systemClsEmisionNotaDeCredito();
            }

            if (!salida){
                cout<<"CARGAR DATOS DE VENTA."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarDatosVenta(regNotaDeCredito);
                systemClsEmisionNotaDeCredito();
            }
        } else{
            mostrarMenuSecundarioEmision();
            cin>>menu;
        }

        if (salida){
            menu = 0;
        }

        switch(menu){

            ///CASE 1 - CARGA DE ARTICULOS
            case 1: {
                if (!banderaPrimerIngreso){
                    systemClsEmisionNotaDeCredito();
                    cout << "Usted ha decidido cargar otro articulo." << endl << endl;
                }

                cargaArticulosEmision(regNotaDeCredito);

                if (banderaPrimerIngreso){
                    banderaPrimerIngreso = false;
                }

                break;
            }

            ///CASE 2 - MODIFICAR DATOS
            case 2: {
                modificarDatosEmision(regNotaDeCredito);

                break;
            }

            ///CASE 3 - BORRAR ITEM
            case 3: {
                borrarItemDetalleVenta(regNotaDeCredito);

                break;
            }

            ///CASE 4 - MOSTRAR VISTA PREVIA
            case 4: {
                mostrarVistaPrevia(regNotaDeCredito);

                break;
            }

            ///CASE 5 - CONFIRMACION FINAL
            case 5: {
                menu = confirmacionNotaDeCredito (regNotaDeCredito);
                system ("pause");
                systemClsEmisionNotaDeCredito();
                regNotaDeCredito.MostrarNotaDeCreditoEmitida();
                break;
            }

            ///CASE 0 - CANCELACION FINAL
            case 0: {
                menu = cancelacionNotaDeCredito(regNotaDeCredito);

                break;
            }

            ///DEFAULT - ERROR
            default:

                break;

        }
    }
    return 0;
}

bool cargarCliente(NotaDeCredito& regNotaDeCredito){
    ArchivoCliente regArchivoCliente;
    int opcion;
    int pos;
    bool continuar;
    do{
        ///ArchivoCliente archivoCliente;
        cout << "INGRESO DEL CLIENTE: " << endl;
        cout << "\t 1 - Por ID de cliente" << endl;
        cout << "\t 2 - Por CUIT" << endl;
        cout << "\t 3 - Por Razon Social" << endl;
        cout << "\t 0 - Cancelar emision" << endl;
        cout << endl << "Ingrese la opcion deseada: ";
        cin >> opcion;
        while (opcion<0 || opcion>3){
            cout << endl << "Opcion invalida. Intente de nuevo" << endl << endl;
            cout << "Ingrese la opcion deseada (1-ID, 2-CUIT, 3-RAZON SOCIAL, 0-CANCELAR): ";
            cin >> opcion;
            systemClsEmisionNotaDeCredito();
        }
        if (opcion == 1){
            cout << endl << "Ingrese el ID del Cliente: ";
            int idCliente;
            cin >> idCliente;
            pos = regArchivoCliente.buscarRegistro(idCliente);
        } else if (opcion == 2){
            cout << endl << "Ingrese el CUIT del Cliente: ";
            char cuitCliente[13];
            cargarCadena(cuitCliente,13);
            pos = regArchivoCliente.buscarRegistro(cuitCliente);
        } else if (opcion == 3){
            cout << endl << "Ingrese la razon social del Cliente: ";
            char nombre[50];
            cargarCadena(nombre,50);
            vector<Cliente> resultados;
            resultados = regArchivoCliente.buscarPorNombreParcial(nombre);
            cout << endl << "Resultados de la busqueda para \"" << nombre << "\":" << endl << endl;
            cout << left << setw(5) << "ID" << setw(55) << "Nombre" << setw(20) << "CUIT" << endl;
            cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
            for (Cliente& regCliente : resultados) {
                cout << left << setw(5) << regCliente.getId() << setw(55) << regCliente.getNombre() << setw(20) << regCliente.getCuit() << endl;
            }
            cout << endl << "Ingrese el ID de la opcion deseada, o 0 si no se encuentra: ";
            int idCliente;
            cin >> idCliente;
            pos = regArchivoCliente.buscarRegistro(idCliente);
        } else {
            continuar = false;
            return continuar;
        }
        if (pos == -1){
            cout << endl << "No se ha encontrado el cliente" << endl << endl;
            cout << "Intente de nuevo." << endl << endl;
            system ("pause");
            systemClsEmisionNotaDeCredito();
            continuar = false;
        } else{
            regNotaDeCredito.setCuitCliente(regArchivoCliente.leerArchivo(pos).getCuit());
            regNotaDeCredito.setNombreCliente(regArchivoCliente.leerArchivo(pos).getNombre());
            regNotaDeCredito.setIdCliente(regArchivoCliente.leerArchivo(pos).getId());
            regNotaDeCredito.setTipoCliente(regArchivoCliente.leerArchivo(pos).getTipo());
            regNotaDeCredito.setDireccion(regArchivoCliente.leerArchivo(pos).getDireccion());
            regNotaDeCredito.MostrarClienteEmision();
            continuar = confirmacion();
            systemClsEmisionNotaDeCredito();
        }

    }while (!continuar);
    return continuar;
}

bool cargarVendedor(NotaDeCredito& regNotaDeCredito){
    ArchivoVendedor regArchivoVendedor;
    int pos;
    bool continuar;
    do {
        cout << "INGRESO DEL VENDEDOR: " << endl << endl;
        regArchivoVendedor.listarArchivo();
        cout << "Ingrese el ID de la opcion deseada o 0 para salir: ";
        int idVendedor;
        cin >> idVendedor;
        if (idVendedor==0){
            continuar = false;
            return continuar;
        }
        pos = regArchivoVendedor.buscarEnArchivo(idVendedor);

        if (pos == -1){
            cout << endl << "No se ha encontrado el vendedor" << endl << endl;
            cout << "Intente de nuevo." << endl << endl;
            system ("pause");
            systemClsEmisionNotaDeCredito();
            continuar = false;
        } else{
            regNotaDeCredito.setNombreVendedor(regArchivoVendedor.leerArchivo(pos).getNombre());
            regNotaDeCredito.setIdVendedor(regArchivoVendedor.leerArchivo(pos).getId());
            regNotaDeCredito.MostrarVendedorEmision();
            continuar = confirmacion();
            systemClsEmisionNotaDeCredito();
        }
    }while (!continuar);
    return continuar;
}

bool cargarDatosVenta(NotaDeCredito& regNotaDeCredito){
    bool continuar;
    do {
        cout << "INGRESO DE LOS DATOS DE VENTA:" << endl << endl;
        cout << "Ingrese el tipo de compra que desea realizar:" << endl;
        cout << "\t 1 - Contado Directo" << endl;
        cout << "\t 2 - Cuenta Corriente" << endl;
        cout << endl << "Ingrese la opcion deseada o 0 para salir: ";
        int tipoCompra;
        cin >> tipoCompra;

        while (tipoCompra<0 || tipoCompra>2){
            systemClsEmisionNotaDeCredito();
            cout << endl << "\tATENCION: Opcion invalida. Intente de nuevo" << endl<<endl;
            cout << "Ingrese el tipo de compra que desea realizar:" << endl;
            cout << "\t 1 - Contado Directo" << endl;
            cout << "\t 2 - Cuenta Corriente" << endl;
            cout << endl << "Ingrese la opcion deseada o 0 para salir: ";
            cin >> tipoCompra;
        }

        if (tipoCompra==0){
            continuar = false;
            return continuar;
        }

        cout << endl << "Ingrese la condicion de pago: ";
        char condicionPago[35];
        cargarCadena(condicionPago,35);

        cout << endl << "Datos de venta seleccionados:" << endl;
        cout << "\t Tipo de venta: ";
        if (tipoCompra == 1){
            cout << "Contado Directo" << endl;
        } else{
            cout << "Cuenta Corriente" << endl;
        }
        cout << "\t Condicion de Pago: " << condicionPago << endl;

        regNotaDeCredito.setTipoCompra(tipoCompra);
        regNotaDeCredito.setCondicionPago(condicionPago);

        continuar = confirmacion();
        systemClsEmisionNotaDeCredito();
    }while (!continuar);
    return continuar;
}

void cargarDetalleVenta(NotaDeCredito& regNotaDeCredito){
    NotaDeCredito auxNotaDeCredito;
    auxNotaDeCredito = regNotaDeCredito;    //AUX FACTURA ES UNA COPIA DE LA FACTURA ORIGINAL
    Detalle detalleAux{};

    Item regItem;
    bool continuar;
    int pos;
    bool banderaPrimerIngreso=true;
    do {
        for (int j=0; j<regNotaDeCredito.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regNotaDeCredito.getDetalleVenta().getItem(j));
        }

        ///CARGAR
        if (!banderaPrimerIngreso){
            mostrarMenuSecundarioEmision();
        }
        do{
            cout<<"CARGAR ARTICULOS"<<endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << "INGRESO DE LOS ARTICULOS." << endl << endl;
            cout << "Ingrese la descripcion del articulo: ";
            ArchivoArticulo regArchivoArticulo;
            char descripcion[30];
            cargarCadena(descripcion,30);
            vector<Articulo> resultados;
            resultados = regArchivoArticulo.buscarPorNombreParcial(descripcion);
            cout << endl << "Resultados de la busqueda para \"" << descripcion << "\":" << endl << endl;
            cout << endl;
            cout << left << setw(10) << "Cod.Art." << setw(55) << "Descripcion" << setw(14) << "P.Unitario" << setw(12) << "Stock Actual" << endl;
            cout << setfill('-') << setw(91) << "-" << setfill(' ') << endl;

            for (Articulo& regArticulo : resultados) {
                cout << fixed << setprecision(2);
                cout << left << setw(10) << regArticulo.getId() << setw(55) << regArticulo.getDescripcion();
                cout << right << setw(10) << float(regArticulo.getPrecioVenta()) << setw(4) << " " << setw(10) << regArticulo.getUnidades() << endl;
            }
            cout << endl << "Ingrese el codigo del articulo deseado o 0 si no se encuentra: ";
            int idArticulo;
            cin >> idArticulo;
            pos = regArchivoArticulo.buscarRegistro(idArticulo);
            if (pos == -1){
                cout << endl << "No se ha encontrado el articulo" << endl << endl;
                cout << "Intente de nuevo." << endl << endl;
                system ("pause");
                systemClsEmisionNotaDeCredito();
                continuar = false;
            } else {
                Articulo regArticulo;
                regArticulo = regArchivoArticulo.leerArchivo(pos);
                cout << "Ingrese la cantidad solicitada: ";
                int cantidad;
                cin >> cantidad;
                int tipoCliente = regNotaDeCredito.getTipoCliente();
                regItem.Cargar(regArticulo, cantidad, tipoCliente);
                mostrarEncabezadoDetalle();
                regItem.Mostrar();
                continuar = confirmacion();
            }
            systemClsEmisionNotaDeCredito();

        }while (!continuar);
        regItem.setNroItem(detalleAux.getTamActual()+1);
        detalleAux.agregarItem(regItem);
        auxNotaDeCredito.setDetalleVenta(detalleAux);
        auxNotaDeCredito.calcularImportes();
        auxNotaDeCredito.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionNotaDeCredito();
        if (!continuar){
            detalleAux.resetTamActual();
        }
    }while (!continuar);
    regNotaDeCredito.setDetalleVenta(detalleAux);
}

void modificarDetalleVenta (NotaDeCredito& regNotaDeCredito){
    NotaDeCredito auxNotaDeCredito;
    auxNotaDeCredito = regNotaDeCredito;
    Detalle detalleAux{};
    Item regItem;
    bool continuar;
    int pos;
    int nroItem;

    do {
        for (int j=0; j<regNotaDeCredito.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regNotaDeCredito.getDetalleVenta().getItem(j));
        }
        regNotaDeCredito.calcularImportes();
        regNotaDeCredito.mostrarDetalleCompleto();

        ///MODIFICAR

        do{
            cout << endl << "MODIFICACION DE LOS ARTICULOS." << endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << endl << "Seleccione el Nro. de Item que desea modificar o 0 para salir: ";
            cin >> nroItem;

            while (nroItem < 0 || nroItem > regNotaDeCredito.getDetalleVenta().getTamActual()){
                systemClsEmisionFactura();
                cout << endl << "MODIFICACION DE LOS ARTICULOS." << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << endl << "\t ATENCION: Opcion fuera de rango. Intente de nuevo" << endl << endl;
                regNotaDeCredito.mostrarDetalleCompleto();
                cout << endl << "Seleccione el Nro. de Item que desea modificar o 0 para salir: ";
                cin >> nroItem;
            }

            if (nroItem!=0){
                cout << endl << "Ingrese el ID del nuevo Articulo: ";
                int idArticulo;
                cin >> idArticulo;
                Articulo regArticulo;
                ArchivoArticulo archiArticulos;
                pos = archiArticulos.buscarRegistro(idArticulo);
                regArticulo = archiArticulos.leerArchivo(pos);
                cout << "Ingrese la cantidad solicitada: ";
                int cantidad;
                cin >> cantidad;
                int tipoCliente = regNotaDeCredito.getTipoCliente();
                regItem.Cargar(regArticulo, cantidad, tipoCliente);
                mostrarEncabezadoDetalle();
                regItem.Mostrar();
            }
            continuar = confirmacion();
            systemClsEmisionFactura();

        }while (!continuar);

        regItem.setNroItem(nroItem);
        pos = nroItem - 1;
        detalleAux.modificarItem(pos, regItem);

        auxNotaDeCredito.setDetalleVenta(detalleAux);
        auxNotaDeCredito.calcularImportes();
        auxNotaDeCredito.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionFactura();
        if (!continuar){
            detalleAux.resetTamActual();
        }

    }while (!continuar);
    regNotaDeCredito.setDetalleVenta(detalleAux);
}

void borrarItemDetalleVenta(NotaDeCredito& regNotaDeCredito){
    NotaDeCredito auxNotaDeCredito;
    auxNotaDeCredito = regNotaDeCredito;
    Detalle detalleAux{};
    bool continuar;
    int nroItem;

    systemClsEmisionNotaDeCredito();
    cout << "BORRAR ARTICULO CARGADO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;

    do {
        for (int j=0; j<regNotaDeCredito.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regNotaDeCredito.getDetalleVenta().getItem(j));
        }

        regNotaDeCredito.calcularImportes();
        do{
            regNotaDeCredito.mostrarDetalleCompleto();

            ///BORRAR
            cout << endl << "BORRADO DE ARTICULOS." << endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << endl << "Seleccione el Nro. de Item que desea borrar o 0 para salir: ";
            cin >> nroItem;

            while (nroItem < 0 || nroItem > regNotaDeCredito.getDetalleVenta().getTamActual()){
                systemClsEmisionFactura();
                cout << endl << "BORRADO DE ARTICULOS." << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << endl << "\t ATENCION: Opcion fuera de rango. Intente de nuevo" << endl << endl;
                regNotaDeCredito.mostrarDetalleCompleto();
                cout << endl << "Seleccione el Nro. de Item que desea borrar o 0 para salir: ";
                cin >> nroItem;
            }
            if (nroItem!=0){
                Item regItem;
                regItem = detalleAux.getItem(nroItem-1);
                mostrarEncabezadoDetalle();
                regItem.Mostrar();
            }
            continuar = confirmacion();
            systemClsEmisionFactura();

        }while (!continuar);

        detalleAux.borrarItem(nroItem-1);

        auxNotaDeCredito.setDetalleVenta(detalleAux);
        auxNotaDeCredito.calcularImportes();
        auxNotaDeCredito.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionFactura();
        if (!continuar){
            detalleAux.resetTamActual();
        }

    }while (!continuar);
    regNotaDeCredito.setDetalleVenta(detalleAux);
    regNotaDeCredito.calcularImportes();

}

void altaNotaDeCredito(NotaDeCredito& regNotaDeCredito){
    ArchivoNotaDeCredito regArchivoNotaDeCredito;
    int idNotaDeCredito;
    if (regArchivoNotaDeCredito.verificarArchivoExistente()){
        idNotaDeCredito = regArchivoNotaDeCredito.contarRegistros();
    } else {
        idNotaDeCredito = 0;
    }
    Fecha fecha;
    fecha.cargarFechaSistema();
    regNotaDeCredito.setFecha(fecha);
    regNotaDeCredito.setId(idNotaDeCredito+1);
    regArchivoNotaDeCredito.AgregarRegistro(regNotaDeCredito);
}

void imprimirNotaDeCreditoDesdeArchivo(NotaDeCredito& regNotaDeCredito){
    ArchivoNotaDeCredito regArchivoNotaDeCredito;
    regArchivoNotaDeCredito.leerArchBin_escribirArchTxt("notasDeCredito.dat");
}

void imprimirNotaDeCredito(NotaDeCredito& regNotaDeCredito){
    regNotaDeCredito.escribirEnArchivoTexto();
}

void actualizarStock(NotaDeCredito& regNotaDeCredito){

    int cantIngreso, id, pos, unidades_en_stock, unidades_actualizadas;

    Articulo regArticulo;
    ArchivoArticulo regArchivoArticulo;

    for (int i=0; i<regNotaDeCredito.getDetalleVenta().getTamActual(); i++){
        id = regNotaDeCredito.getDetalleVenta().getItem(i).getIdArticulo();
        cantIngreso = regNotaDeCredito.getDetalleVenta().getItem(i).getCantidad();

        pos = regArchivoArticulo.buscarSinMostrar(id);
        regArticulo = regArchivoArticulo.leerArchivo(pos);

        unidades_en_stock=regArticulo.getUnidades();
        unidades_actualizadas=unidades_en_stock+cantIngreso;
        regArticulo.setUnidades(unidades_actualizadas);

        regArchivoArticulo.modificarArchivo(pos,regArticulo);
    }
}


#endif // FUNCIONESNOTADECREDITO_H_INCLUDED
