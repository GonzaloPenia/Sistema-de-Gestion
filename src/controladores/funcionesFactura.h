#ifndef FUNCIONESFACTURA_H_INCLUDED
#define FUNCIONESFACTURA_H_INCLUDED

///FUNCIONES PARA LA EMISION DE FACTURAS

int emisionMain(Factura& regFactura);

bool cargarCliente(Factura& regFactura);
bool cargarVendedor(Factura& regFactura);
bool cargarDatosVenta(Factura& regFactura);
void cargarDetalleVenta(Factura& regFactura);

void cargaArticulosEmision(Factura& regFactura);
void modificarDetalleVenta (Factura& regFactura);
void borrarItemDetalleVenta(Factura& regFactura);
void modificarDatosEmision(Factura& regFactura);
void mostrarVistaPrevia(Factura& regFactura);

int confirmacionFactura (Factura& regFactura);
int cancelacionFactura (Factura& regFactura);

void altaFactura(Factura& regFactura);
void imprimirFacturaDesdeArchivo(Factura& regFactura);
void imprimirFactura(Factura& regFactura);
void actualizarStock(Factura& regFactura);


void cargaArticulosEmision(Factura& regFactura){
    int opcion;

    do{
        cargarDetalleVenta(regFactura);
        systemClsEmisionFactura();

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
        systemClsEmisionFactura();

    }while(opcion);
    regFactura.calcularImportes();
    regFactura.mostrarDetalleCompleto();
    cout << endl;
    system ("pause");
    systemClsEmisionFactura();
}

void modificarDatosEmision(Factura& regFactura){
    systemClsEmisionFactura();
    mostrarSubmenuEmisionModificar();
    int sub_menu;
    cin >> sub_menu;
    systemClsEmisionFactura();
    switch(sub_menu){

    case 1:
        cout<<"MODIFICAR DATOS DEL CLIENTE."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regFactura.MostrarClienteEmision();
        cout << endl << "Proceda a ingresar el nuevo cliente." << endl << endl;
        cargarCliente(regFactura);
        systemClsEmisionFactura();
        break;

    case 2:
        cout<<"MODIFICAR DATOS DEL VENDEDOR."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regFactura.MostrarVendedorEmision();
        cout << endl << "Proceda a ingresar el nuevo vendedor." << endl << endl;
        cargarVendedor(regFactura);
        systemClsEmisionFactura();
        break;

    case 3:
        cout<<"MODIFICAR DATOS DE VENTA."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regFactura.MostrarDatosVentaEmision();
        cout << endl << "Proceda a ingresar los nuevos datos de venta." << endl << endl;
        cargarDatosVenta(regFactura);
        systemClsEmisionFactura();
        break;

    case 4:
        cout<<"MODIFICAR ITEMS DEL DETALLE DE VENTA"<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        modificarDetalleVenta(regFactura);
        systemClsEmisionFactura();
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

void mostrarVistaPrevia(Factura& regFactura){
    systemClsEmisionFactura();
    cout << "VISTA PREVIA DE LA FACTURA." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl << endl;
    regFactura.Mostrar();
    system ("pause");
}

int confirmacionFactura (Factura& regFactura){

    systemClsEmisionFactura();
    cout << "CONFIRMAR FACTURA." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Usted esta a punto de CONFIRMAR la factura." << endl << endl;
    //Fecha fecha;
    //fecha.cargarFechaSistema();
    //regFactura.setFecha(fecha);
    regFactura.Mostrar();
    bool confirmar;
    confirmar = confirmacion();
    systemClsEmisionFactura();
    if (confirmar){
        cout << endl << "La factura ha sido confirmada con exito." << endl << endl;
        altaFactura(regFactura);
        imprimirFactura(regFactura);
        recaudacionFactura(regFactura.getImporteTotal(), regFactura.getIdCliente());
        
        actualizarStock(regFactura);
        return 0;
    } else {
        cout << endl << "Usted ha decidido no confirmar la factura." << endl << endl;
        return 1;
    }
    system ("pause");
}

int cancelacionFactura (Factura& regFactura){
    systemClsEmisionFactura();
    cout << "CANCELAR FACTURA." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Usted esta a punto de CANCELAR la factura." << endl;
    bool cancelar;
    cancelar = confirmacion();
    systemClsEmisionFactura();
    if (cancelar){
        cout << "La factura ha sido cancelada con exito." << endl << endl;
        return 0;
    } else {
        cout << "Usted ha decidido no cancelar la factura." << endl << endl;
        return 1;
    }
}

/// 1 - FUNCIONES PRINCIPALES PARA EMISION DE FACTURAS
int emisionMain(Factura& regFactura){
    int menu=1;
    bool banderaPrimerIngreso=true;
    int contador=0;
    while(menu!=0){
        bool salida=false;
        int opcion=0;
        systemClsEmisionFactura();
        if (banderaPrimerIngreso){

            if (!salida && contador>=1){
                opcion = 0;
                while (opcion!=1 && opcion!=2){
                    cout << "Ya hay un cliente cargado." << endl << endl;
                    regFactura.MostrarClienteEmision();
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
                systemClsEmisionFactura();
            }

            if (!salida&&(contador<1 || opcion == 2)){
                cout<<"CARGAR CLIENTE."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarCliente(regFactura);
                salida ? contador : contador++;
                systemClsEmisionFactura();
            }

            if (!salida && contador>=2){
                opcion = 0;
                while (opcion!=1 && opcion!=2){
                    cout << "Ya hay un vendedor cargado." << endl << endl;
                    regFactura.MostrarVendedorEmision();
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
                systemClsEmisionFactura();
            }

            if (!salida&&(contador<2 || opcion == 2)){
                cout<<"CARGAR VENDEDOR."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarVendedor(regFactura);
                salida ? contador : contador++;
                systemClsEmisionFactura();
            }

            if (!salida){
                cout<<"CARGAR DATOS DE VENTA."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarDatosVenta(regFactura);
                systemClsEmisionFactura();
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
                    systemClsEmisionFactura();
                    cout << "Usted ha decidido cargar otro articulo." << endl << endl;
                }

                cargaArticulosEmision(regFactura);

                if (banderaPrimerIngreso){
                    banderaPrimerIngreso = false;
                }

                break;
            }

            ///CASE 2 - MODIFICAR DATOS
            case 2: {
                modificarDatosEmision(regFactura);

                break;
            }

            ///CASE 3 - BORRAR ITEM
            case 3: {
                borrarItemDetalleVenta(regFactura);

                break;
            }

            ///CASE 4 - MOSTRAR VISTA PREVIA
            case 4: {
                mostrarVistaPrevia(regFactura);

                break;
            }

            ///CASE 5 - CONFIRMACION FINAL
            case 5: {
                menu = confirmacionFactura (regFactura);
                system ("pause");
                systemClsEmisionFactura();
                regFactura.MostrarFacturaEmitida();
                break;
            }

            ///CASE 0 - CANCELACION FINAL
            case 0: {
                menu = cancelacionFactura(regFactura);

                break;
            }

            ///DEFAULT - ERROR
            default:

                break;

        }
    }
    return 0;
}

bool cargarCliente(Factura& regFactura){                //OK
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
            systemClsEmisionFactura();
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
            systemClsEmisionFactura();
            continuar = false;
        } else{
            regFactura.setCuitCliente(regArchivoCliente.leerArchivo(pos).getCuit());
            regFactura.setNombreCliente(regArchivoCliente.leerArchivo(pos).getNombre());
            regFactura.setIdCliente(regArchivoCliente.leerArchivo(pos).getId());
            regFactura.setTipoCliente(regArchivoCliente.leerArchivo(pos).getTipo());
            regFactura.setDireccion(regArchivoCliente.leerArchivo(pos).getDireccion());
            regFactura.MostrarClienteEmision();
            continuar = confirmacion();
            systemClsEmisionFactura();
        }

    }while (!continuar);
    return continuar;
}

bool cargarVendedor(Factura& regFactura){               //OK
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
            systemClsEmisionFactura();
            continuar = false;
        } else{
            regFactura.setNombreVendedor(regArchivoVendedor.leerArchivo(pos).getNombre());
            regFactura.setIdVendedor(regArchivoVendedor.leerArchivo(pos).getId());
            regFactura.MostrarVendedorEmision();
            continuar = confirmacion();
            systemClsEmisionFactura();
        }
    }while (!continuar);
    return continuar;
}

bool cargarDatosVenta(Factura& regFactura){             //OK
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
            systemClsEmisionFactura();
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

        regFactura.setTipoCompra(tipoCompra);
        regFactura.setCondicionPago(condicionPago);

        continuar = confirmacion();
        systemClsEmisionFactura();
    }while (!continuar);
    return continuar;
}

void cargarDetalleVenta(Factura& regFactura){           //OK
    Factura auxFactura;
    auxFactura = regFactura;    //AUX FACTURA ES UNA COPIA DE LA FACTURA ORIGINAL
    Detalle detalleAux{};

    Item regItem;
    bool continuar;
    int pos;
    bool banderaPrimerIngreso=true;
    do {
        for (int j=0; j<regFactura.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regFactura.getDetalleVenta().getItem(j));
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
                
                
                int costo = regArticulo.getCosto();
                int ganancia = regArticulo.getGanancia();
                float precioVenta = costo + (costo * ganancia / 100.0f);

                cout << right << setw(10) << float(precioVenta) << setw(4) << " " << setw(10) << regArticulo.getUnidades() << endl;
            }
            cout << endl << "Ingrese el codigo del articulo deseado o 0 si no se encuentra: ";
            int idArticulo;
            cin >> idArticulo;
            pos = regArchivoArticulo.buscarRegistro(idArticulo);
            if (pos == -1){
                cout << endl << "No se ha encontrado el articulo" << endl << endl;
                cout << "Intente de nuevo." << endl << endl;
                system ("pause");
                systemClsEmisionFactura();
                continuar = false;
            } else {
                Articulo regArticulo;
                regArticulo = regArchivoArticulo.leerArchivo(pos);
                cout << "Ingrese la cantidad solicitada: ";
                int cantidad;
                cin >> cantidad;
                int tipoCliente = regFactura.getTipoCliente();
                regItem.Cargar(regArticulo, cantidad, tipoCliente);
                mostrarEncabezadoDetalle();
                regItem.Mostrar();
                continuar = confirmacion();
            }
            systemClsEmisionFactura();

        }while (!continuar);
        regItem.setNroItem(detalleAux.getTamActual()+1);
        detalleAux.agregarItem(regItem);
        auxFactura.setDetalleVenta(detalleAux);
        auxFactura.calcularImportes();
        auxFactura.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionFactura();
        if (!continuar){
            detalleAux.resetTamActual();
        }
    }while (!continuar);
    regFactura.setDetalleVenta(detalleAux);
}

void modificarDetalleVenta (Factura& regFactura){       //OK
    Factura auxFactura;
    auxFactura = regFactura;
    Detalle detalleAux{};
    Item regItem;
    bool continuar;
    int pos;
    int nroItem;

    do {
        for (int j=0; j<regFactura.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regFactura.getDetalleVenta().getItem(j));
        }
        regFactura.calcularImportes();
        regFactura.mostrarDetalleCompleto();

        ///MODIFICAR

        do{
            cout << endl << "MODIFICACION DE LOS ARTICULOS." << endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << endl << "Seleccione el Nro. de Item que desea modificar o 0 para salir: ";
            cin >> nroItem;

            while (nroItem < 0 || nroItem > regFactura.getDetalleVenta().getTamActual()){
                systemClsEmisionFactura();
                cout << endl << "MODIFICACION DE LOS ARTICULOS." << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << endl << "\t ATENCION: Opcion fuera de rango. Intente de nuevo" << endl << endl;
                regFactura.mostrarDetalleCompleto();
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
                int tipoCliente = regFactura.getTipoCliente();
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

        auxFactura.setDetalleVenta(detalleAux);
        auxFactura.calcularImportes();
        auxFactura.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionFactura();
        if (!continuar){
            detalleAux.resetTamActual();
        }

    }while (!continuar);
    regFactura.setDetalleVenta(detalleAux);
}

void borrarItemDetalleVenta(Factura& regFactura){       //OK
    Factura auxFactura;
    auxFactura = regFactura;
    Detalle detalleAux{};
    bool continuar;
    int nroItem;

    systemClsEmisionFactura();
    cout << "BORRAR ARTICULO CARGADO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;

    do {
        for (int j=0; j<regFactura.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regFactura.getDetalleVenta().getItem(j));
        }

        regFactura.calcularImportes();
        do{
            regFactura.mostrarDetalleCompleto();

            ///BORRAR
            cout << endl << "BORRADO DE ARTICULOS." << endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << endl << "Seleccione el Nro. de Item que desea borrar o 0 para salir: ";
            cin >> nroItem;

            while (nroItem < 0 || nroItem > regFactura.getDetalleVenta().getTamActual()){
                systemClsEmisionFactura();
                cout << endl << "BORRADO DE ARTICULOS." << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << endl << "\t ATENCION: Opcion fuera de rango. Intente de nuevo" << endl << endl;
                regFactura.mostrarDetalleCompleto();
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

        auxFactura.setDetalleVenta(detalleAux);
        auxFactura.calcularImportes();
        auxFactura.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionFactura();
        if (!continuar){
            detalleAux.resetTamActual();
        }

    }while (!continuar);
    regFactura.setDetalleVenta(detalleAux);
    regFactura.calcularImportes();

}

void altaFactura(Factura& regFactura){                  //OK
    ArchivoFactura archiFactura;
    int idFactura;
    if (archiFactura.verificarArchivoExistente()){
        idFactura = archiFactura.contarRegistros();
    } else {
        idFactura = 0;
    }
    Fecha fecha;
    fecha.cargarFechaSistema();
    regFactura.setFecha(fecha);
    regFactura.setId(idFactura+1);
    archiFactura.AgregarRegistro(regFactura);
}

void imprimirFactura(Factura& regFactura){              //OK
    regFactura.escribirEnArchivoTexto();
}

void imprimirFacturaDesdeArchivo(Factura& regFactura){
    ArchivoFactura regArchivoFactura;
    regArchivoFactura.leerArchBin_escribirArchTxt("../../data/facturas.dat");
}

void actualizarStock(Factura& regFactura){

    int cantEgreso, id, pos, unidades_en_stock, unidades_actualizadas;

    Articulo regArticulo;
    ArchivoArticulo regArchivoArticulo;

    for (int i=0; i<regFactura.getDetalleVenta().getTamActual(); i++){
        id = regFactura.getDetalleVenta().getItem(i).getIdArticulo();
        cantEgreso = regFactura.getDetalleVenta().getItem(i).getCantidad();

        pos = regArchivoArticulo.buscarSinMostrar(id);
        regArticulo = regArchivoArticulo.leerArchivo(pos);

        unidades_en_stock=regArticulo.getUnidades();
        unidades_actualizadas=unidades_en_stock-cantEgreso;
        regArticulo.setUnidades(unidades_actualizadas);

        regArchivoArticulo.modificarArchivo(pos,regArticulo);
    }
}

#endif // FUNCIONESFACTURA_H_INCLUDED
