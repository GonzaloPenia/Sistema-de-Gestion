#ifndef FUNCIONESPRESUPUESTO_H_INCLUDED
#define FUNCIONESPRESUPUESTO_H_INCLUDED

void seccionPresupuesto(Presupuesto& regPresupuesto);

void cargaArticulosEmision(Presupuesto& regPresupuesto);
void modificarDatosEmision(Presupuesto& regPresupuesto);
void mostrarVistaPrevia(Presupuesto& regPresupuesto);
int confirmacionPresupuesto (Presupuesto& regPresupuesto, bool nuevoRegistro);
int cancelacionPresupuesto (Presupuesto& regPresupuesto);

int emisionMain(Presupuesto& regPresupuesto);

void altaPresupuesto(Presupuesto& regPresupuesto);
void imprimirPresupuesto(Presupuesto& regPresupuesto);
void actualizacionPresupuesto (Presupuesto& regPresupuesto);

bool cargarCliente(Presupuesto& regPresupuesto);
bool cargarVendedor(Presupuesto& regPresupuesto);
bool cargarDatosVenta(Presupuesto& regPresupuesto);
void cargarDetalleVenta(Presupuesto& regPresupuesto);

void modificarDetalleVenta (Presupuesto& regPresupuesto);
void borrarItemDetalleVenta(Presupuesto& regPresupuesto);

void mostrarEncabezadoPresupuestoResumido();
void mostrarEncabezadoPresupuestoArticulo();
Presupuesto buscarPresupuesto();
void modificarPresupuesto(Presupuesto& regPresupuesto);
int facturarPresupuesto(Presupuesto& regPresupuesto);
int listarPresupuestos();
void listarPresupuestosRangoFecha(Fecha fechaInicial, Fecha fechaFinal);
void listarPresupuestosCliente(Fecha fechaInicial, Fecha fechaFinal, int idCliente);
void listarPresupuestosArticulo(Fecha fechaInicial, Fecha fechaFinal, int idArticulo);

void seccionPresupuesto(Presupuesto& regPresupuesto){
    int menu=1;
    while(menu!=0){
        system ("cls");
        mostrarMenuPrincipalPresupuestos();
        cin>>menu;
        system ("cls");
        switch(menu){

	///CASE 1 - AGREGAR
        case 1: {
            Presupuesto regPresupuesto;
            emisionMain(regPresupuesto);
            system ("pause");
            break;
        }

	///CASE 2 - MODIFICAR
        case 2: {
            systemClsModificacionPresupuesto();
            regPresupuesto = buscarPresupuesto();
            cout << endl;
            mostrarEncabezadoPresupuestoResumido();
            regPresupuesto.MostrarPresupuestoResumen();
            cout << endl;
            system ("pause");
            modificarPresupuesto(regPresupuesto);
            system ("pause");
            break;
        }

    ///CASE 3 - CONVERTIR A FACTURA
        case 3: {
            systemClsFacturacionPresupuesto();
            regPresupuesto = buscarPresupuesto();
            cout << endl;
            mostrarEncabezadoPresupuestoResumido();
            regPresupuesto.MostrarPresupuestoResumen();
            cout << endl;
            system ("pause");
            systemClsFacturacionPresupuesto();
            menu = facturarPresupuesto(regPresupuesto);
            break;
        }

    ///CASE 4 - VISUALIZAR PRESUPUESTO
        case 4: {
            systemClsVisualizacionPresupuesto();
            regPresupuesto = buscarPresupuesto();
            cout << endl;
            mostrarEncabezadoPresupuestoResumido();
            regPresupuesto.MostrarPresupuestoResumen();
            cout << endl;
            system ("pause");
            systemClsVisualizacionPresupuesto();
            mostrarVistaPrevia(regPresupuesto);
            break;
        }


	///CASE 5 - LISTADOS
        case 5: {
            menu = listarPresupuestos();

            break;
        }

    ///CASE 0 - SALIR DEL MENU PRESUPUESTOS
        case 0:{
            cout << "0 - SALIDA DEL SUBMENU DE PRESUPUESTOS" << endl << endl;
            cout << "Usted ha decidido salir del Submenu de Presupuestos." << endl << endl;
            break;
        }

        default: {
            cout << "ERROR" << endl << endl;
            cout << "Algo salio mal, intente nuevamente" << endl << endl;
            system ("pause");
        }
        }
    }
}

void cargaArticulosEmision(Presupuesto& regPresupuesto){
    int opcion;

    do{
        cargarDetalleVenta(regPresupuesto);
        systemClsEmisionPresupuesto();

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
        systemClsEmisionPresupuesto();

    }while(opcion);
    regPresupuesto.calcularImportes();
    regPresupuesto.mostrarDetalleCompleto();
    cout << endl;
    system ("pause");
    systemClsEmisionPresupuesto();
}

void modificarDatosEmision(Presupuesto& regPresupuesto){
    systemClsEmisionPresupuesto();
    mostrarSubmenuEmisionModificar();
    int sub_menu;
    cin >> sub_menu;
    systemClsEmisionPresupuesto();
    switch(sub_menu){

    case 1:
        cout<<"MODIFICAR DATOS DEL CLIENTE."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regPresupuesto.MostrarClienteEmision();
        cout << endl << "Proceda a ingresar el nuevo cliente." << endl << endl;
        cargarCliente(regPresupuesto);
        systemClsEmisionPresupuesto();
        break;

    case 2:
        cout<<"MODIFICAR DATOS DEL VENDEDOR."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regPresupuesto.MostrarVendedorEmision();
        cout << endl << "Proceda a ingresar el nuevo vendedor." << endl << endl;
        cargarVendedor(regPresupuesto);
        systemClsEmisionPresupuesto();
        break;

    case 3:
        cout<<"MODIFICAR DATOS DE VENTA."<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        regPresupuesto.MostrarDatosVentaEmision();
        cout << endl << "Proceda a ingresar los nuevos datos de venta." << endl << endl;
        cargarDatosVenta(regPresupuesto);
        systemClsEmisionPresupuesto();
        break;

    case 4:
        cout<<"MODIFICAR ITEMS DEL DETALLE DE VENTA"<<endl;
        cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
        modificarDetalleVenta(regPresupuesto);
        systemClsEmisionPresupuesto();
        break;

    case 0:
        cout << endl << "Usted ha decidido terminar la modificacion." << endl << endl;
        system ("pause");
        break;

    default:
        cout << endl << "Algo salio mal, intente nuevamente" << endl << endl;
        system ("pause");
        return;
    }
}

void mostrarVistaPrevia(Presupuesto& regPresupuesto){
    systemClsEmisionPresupuesto();
    cout << "VISTA PREVIA DEL PRESUPUESTO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl << endl;
    //Fecha fecha;
    //fecha.cargarFechaSistema();
    //regPresupuesto.setFecha(fecha);
    regPresupuesto.Mostrar();
    system ("pause");
}

int confirmacionPresupuesto (Presupuesto& regPresupuesto, bool nuevoRegistro){
    systemClsEmisionPresupuesto();
    cout << "CONFIRMAR PRESUPUESTO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Usted esta a punto de CONFIRMAR el Presupuesto." << endl << endl;
    Fecha fecha;
    fecha.cargarFechaSistema();
    regPresupuesto.setFecha(fecha);
    regPresupuesto.Mostrar();
    bool confirmar;
    confirmar = confirmacion();
    systemClsEmisionPresupuesto();
    if (confirmar){
        if (nuevoRegistro){
            cout << endl << "El nuevo Presupuesto ha sido confirmado con exito." << endl << endl;
            altaPresupuesto(regPresupuesto);
            imprimirPresupuesto(regPresupuesto);
            return 0;
        } else {
            cout << endl << "El Presupuesto modificado ha sido confirmado con exito." << endl << endl;
            actualizacionPresupuesto (regPresupuesto);
            imprimirPresupuesto(regPresupuesto);
            return 0;
        }
    } else {
        cout << endl << "Usted ha decidido no confirmar el presupuesto." << endl << endl;
        return 1;
    }
    system ("pause");
}

int cancelacionPresupuesto (Presupuesto& regPresupuesto){
    systemClsEmisionPresupuesto();
    cout << "CANCELAR PRESUPUESTO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Usted esta a punto de CANCELAR el presupuesto." << endl;
    bool cancelar;
    cancelar = confirmacion();
    systemClsEmisionPresupuesto();
    if (cancelar){
        cout << "El presupuesto ha sido cancelada con exito." << endl << endl;
        return 0;
    } else {
        cout << "Usted ha decidido no cancelar el presupuesto." << endl << endl;
        return 1;
    }
    system ("pause");
}

int emisionMain(Presupuesto& regPresupuesto){
    int menu=1;
    bool banderaPrimerIngreso=true;
    int contador=0;
    while(menu!=0){
        bool salida=false;
        int opcion=0;
        systemClsEmisionPresupuesto();
        if (banderaPrimerIngreso){

            if (!salida && contador>=1){
                opcion = 0;
                while (opcion!=1 && opcion!=2){
                    cout << "Ya hay un cliente cargado." << endl << endl;
                    regPresupuesto.MostrarClienteEmision();
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
                systemClsEmisionPresupuesto();
            }

            if (!salida&&(contador<1 || opcion == 2)){
                cout<<"CARGAR CLIENTE."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarCliente(regPresupuesto);
                salida ? contador : contador++;
                systemClsEmisionPresupuesto();
            }

            if (!salida && contador>=2){
                opcion = 0;
                while (opcion!=1 && opcion!=2){
                    cout << "Ya hay un vendedor cargado." << endl << endl;
                    regPresupuesto.MostrarVendedorEmision();
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
                systemClsEmisionPresupuesto();
            }

            if (!salida&&(contador<2 || opcion == 2)){
                cout<<"CARGAR VENDEDOR."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarVendedor(regPresupuesto);
                salida ? contador : contador++;
                systemClsEmisionPresupuesto();
            }

            if (!salida){
                cout<<"CARGAR DATOS DE VENTA."<<endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                salida = !cargarDatosVenta(regPresupuesto);
                systemClsEmisionPresupuesto();
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
                    systemClsEmisionPresupuesto();
                    cout << "Usted ha decidido cargar otro articulo." << endl << endl;
                }

                cargaArticulosEmision(regPresupuesto);

                if (banderaPrimerIngreso){
                    banderaPrimerIngreso = false;
                }

                break;
            }

            ///CASE 2 - MODIFICAR DATOS
            case 2: {
                modificarDatosEmision(regPresupuesto);

                break;
            }

            ///CASE 3 - BORRAR ITEM
            case 3: {
                borrarItemDetalleVenta(regPresupuesto);

                break;
            }

            ///CASE 4 - MOSTRAR VISTA PREVIA
            case 4: {
                mostrarVistaPrevia(regPresupuesto);

                break;
            }

            ///CASE 5 - CONFIRMACION FINAL
            case 5: {
                bool nuevoRegistro = true;
                menu = confirmacionPresupuesto(regPresupuesto, nuevoRegistro);
                system("pause");
                systemClsEmisionPresupuesto();
                regPresupuesto.MostrarPresupuestoEmitido();

                break;
            }

            ///CASE 0 - CANCELACION FINAL
            case 0: {
                menu = cancelacionPresupuesto(regPresupuesto);

                break;
            }

            ///DEFAULT - ERROR
            default:

                break;
        }
    }
    return 0;
}

bool cargarCliente(Presupuesto& regPresupuesto){                //OK
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
            systemClsEmisionPresupuesto();
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
            systemClsEmisionPresupuesto();
            continuar = false;
        } else{
            regPresupuesto.setCuitCliente(regArchivoCliente.leerArchivo(pos).getCuit());
            regPresupuesto.setNombreCliente(regArchivoCliente.leerArchivo(pos).getNombre());
            regPresupuesto.setIdCliente(regArchivoCliente.leerArchivo(pos).getId());
            regPresupuesto.setTipoCliente(regArchivoCliente.leerArchivo(pos).getTipo());
            regPresupuesto.setDireccion(regArchivoCliente.leerArchivo(pos).getDireccion());
            regPresupuesto.MostrarClienteEmision();
            continuar = confirmacion();
            systemClsEmisionPresupuesto();
        }

    }while (!continuar);
    return continuar;
}

bool cargarVendedor(Presupuesto& regPresupuesto){               //OK
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
            systemClsEmisionPresupuesto();
            continuar = false;
        } else{
            regPresupuesto.setNombreVendedor(regArchivoVendedor.leerArchivo(pos).getNombre());
            regPresupuesto.setIdVendedor(regArchivoVendedor.leerArchivo(pos).getId());
            regPresupuesto.MostrarVendedorEmision();
            continuar = confirmacion();
            systemClsEmisionPresupuesto();
        }
    }while (!continuar);
    return continuar;
}

bool cargarDatosVenta(Presupuesto& regPresupuesto){             //OK
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
            systemClsEmisionPresupuesto();
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

        regPresupuesto.setTipoCompra(tipoCompra);
        regPresupuesto.setCondicionPago(condicionPago);

        continuar = confirmacion();
        systemClsEmisionPresupuesto();
    }while (!continuar);
    return continuar;
}

void cargarDetalleVenta(Presupuesto& regPresupuesto){           //OK
    Presupuesto auxPresupuesto;
    auxPresupuesto = regPresupuesto;    //AUX FACTURA ES UNA COPIA DE LA FACTURA ORIGINAL
    Detalle detalleAux{};

    Item regItem;
    bool continuar;
    int pos;
    bool banderaPrimerIngreso=true;
    do {
        for (int j=0; j<regPresupuesto.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regPresupuesto.getDetalleVenta().getItem(j));
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
                systemClsEmisionPresupuesto();
                continuar = false;
            } else {
                Articulo regArticulo;
                regArticulo = regArchivoArticulo.leerArchivo(pos);
                cout << "Ingrese la cantidad solicitada: ";
                int cantidad;
                cin >> cantidad;
                int tipoCliente = regPresupuesto.getTipoCliente();
                regItem.Cargar(regArticulo, cantidad, tipoCliente);
                mostrarEncabezadoDetalle();
                regItem.Mostrar();
                continuar = confirmacion();
            }
            systemClsEmisionPresupuesto();

        }while (!continuar);
        regItem.setNroItem(detalleAux.getTamActual()+1);
        detalleAux.agregarItem(regItem);
        auxPresupuesto.setDetalleVenta(detalleAux);
        auxPresupuesto.calcularImportes();
        auxPresupuesto.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionPresupuesto();
        if (!continuar){
            detalleAux.resetTamActual();
        }
    }while (!continuar);
    regPresupuesto.setDetalleVenta(detalleAux);
}

void modificarDetalleVenta (Presupuesto& regPresupuesto){       //OK
    Presupuesto auxPresupuesto;
    auxPresupuesto = regPresupuesto;
    Detalle detalleAux{};
    Item regItem;
    bool continuar;
    int pos;
    int nroItem;

    do {
        for (int j=0; j<regPresupuesto.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regPresupuesto.getDetalleVenta().getItem(j));
        }
        regPresupuesto.calcularImportes();
        regPresupuesto.mostrarDetalleCompleto();

        ///MODIFICAR

        do{
            cout << endl << "MODIFICACION DE LOS ARTICULOS." << endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << endl << "Seleccione el Nro. de Item que desea modificar o 0 para salir: ";
            cin >> nroItem;

            while (nroItem < 0 || nroItem > regPresupuesto.getDetalleVenta().getTamActual()){
                systemClsEmisionPresupuesto();
                cout << endl << "MODIFICACION DE LOS ARTICULOS." << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << endl << "\t ATENCION: Opcion fuera de rango. Intente de nuevo" << endl << endl;
                regPresupuesto.mostrarDetalleCompleto();
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
                int tipoCliente = regPresupuesto.getTipoCliente();
                regItem.Cargar(regArticulo, cantidad, tipoCliente);
                mostrarEncabezadoDetalle();
                regItem.Mostrar();
            }
            continuar = confirmacion();
            systemClsEmisionPresupuesto();

        }while (!continuar);

        regItem.setNroItem(nroItem);
        pos = nroItem - 1;
        detalleAux.modificarItem(pos, regItem);

        auxPresupuesto.setDetalleVenta(detalleAux);
        auxPresupuesto.calcularImportes();
        auxPresupuesto.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionPresupuesto();
        if (!continuar){
            detalleAux.resetTamActual();
        }

    }while (!continuar);
    regPresupuesto.setDetalleVenta(detalleAux);
}

void borrarItemDetalleVenta(Presupuesto& regPresupuesto){       //OK
    Presupuesto auxPresupuesto;
    auxPresupuesto = regPresupuesto;
    Detalle detalleAux{};
    bool continuar;
    int nroItem;

    systemClsEmisionPresupuesto();
    cout << "BORRAR ARTICULO CARGADO." << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;

    do {
        for (int j=0; j<regPresupuesto.getDetalleVenta().getTamActual(); j++){
            detalleAux.agregarItem(regPresupuesto.getDetalleVenta().getItem(j));
        }

        regPresupuesto.calcularImportes();
        do{
            regPresupuesto.mostrarDetalleCompleto();

            ///BORRAR
            cout << endl << "BORRADO DE ARTICULOS." << endl;
            cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
            cout << endl << "Seleccione el Nro. de Item que desea borrar o 0 para no borrar nada: ";
            cin >> nroItem;

            while (nroItem < 0 || nroItem > regPresupuesto.getDetalleVenta().getTamActual()){
                systemClsEmisionPresupuesto();
                cout << endl << "BORRADO DE ARTICULOS." << endl;
                cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
                cout << endl << "\t ATENCION: Opcion fuera de rango. Intente de nuevo" << endl << endl;
                regPresupuesto.mostrarDetalleCompleto();
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
            systemClsEmisionPresupuesto();

        }while (!continuar);

        detalleAux.borrarItem(nroItem-1);

        auxPresupuesto.setDetalleVenta(detalleAux);
        auxPresupuesto.calcularImportes();
        auxPresupuesto.mostrarDetalleCompleto();

        ///CONFIRMAR
        continuar = confirmacion();
        systemClsEmisionPresupuesto();
        if (!continuar){
            detalleAux.resetTamActual();
        }

    }while (!continuar);
    regPresupuesto.setDetalleVenta(detalleAux);
    regPresupuesto.calcularImportes();

}

void altaPresupuesto(Presupuesto& regPresupuesto){              //OK
    ArchivoPresupuesto archiPresupuesto;
    int idPresupuesto;
    if (archiPresupuesto.verificarArchivoExistente()){
        idPresupuesto = archiPresupuesto.contarRegistros();
    } else {
        idPresupuesto = 0;
    }
    Fecha fecha;
    fecha.cargarFechaSistema();
    regPresupuesto.setFecha(fecha);
    regPresupuesto.setId(idPresupuesto+1);
    archiPresupuesto.AgregarRegistro(regPresupuesto);
}

void actualizacionPresupuesto (Presupuesto& regPresupuesto){
    ArchivoPresupuesto archiPresupuesto;
    int idPresupuesto = regPresupuesto.getId();
    Fecha fecha;
    fecha.cargarFechaSistema();
    regPresupuesto.setFecha(fecha);
    archiPresupuesto.modificarRegistro(regPresupuesto, idPresupuesto-1);
}

void imprimirPresupuesto(Presupuesto& regPresupuesto){          //OK
    regPresupuesto.escribirEnArchivoTexto();
}

void mostrarEncabezadoPresupuestoResumido(){
    cout << setfill('-') << setw(111) << "-" << setfill(' ') << endl;
    cout << left << setw(14) << "FECHA" << setw(6) << "NUMERO" << setw(4) << " " << setw(10) << "ID.CLIENTE"
                 << setw(2) << " " << setw(55) << "RAZON SOCIAL" << setw(9) << "VENDEDOR";
    cout << right << setw(12) << "IMPORTE" << endl;
    cout << setfill('-') << setw(111) << "-" << setfill(' ') << endl;
}

void mostrarEncabezadoPresupuestoArticulo(){
    cout << setfill('-') << setw(122) << "-" << setfill(' ') << endl;
    cout << left << setw(14) << "FECHA" << setw(6) << "NUMERO" << setw(4) << " " << setw(10) << "ID.CLIENTE"
                 << setw(2) << " " << setw(55) << "RAZON SOCIAL" << setw(9) << "VENDEDOR" << setw(10) << "CANTIDAD";
    cout << right << setw(12) << "IMPORTE ART." << endl;
    cout << setfill('-') << setw(122) << "-" << setfill(' ') << endl;
}

Presupuesto buscarPresupuesto(){
    ArchivoPresupuesto regArchivoPresupuesto;
    Presupuesto regPresupuesto;
    int nroPresupuesto;
    cout << "Ingrese el Nro. de Presupuesto que desea: ";
    cin >> nroPresupuesto;

    regPresupuesto = regArchivoPresupuesto.leerRegistro(nroPresupuesto);

    return regPresupuesto;

}

void modificarPresupuesto(Presupuesto& regPresupuesto){
    int menu=1;
    while(menu!=0){
        bool salida=false;
        systemClsModificacionPresupuesto();
        mostrarMenuSecundarioEmision();
        cin>>menu;

        if (salida){
            menu = 0;
        }

        switch(menu){

            ///CASE 1 - CARGA DE ARTICULOS
            case 1: {
                systemClsModificacionPresupuesto();
                cout << "Usted ha decidido cargar otro articulo." << endl << endl;
                cargaArticulosEmision(regPresupuesto);

                break;
            }

            ///CASE 2 - MODIFICAR DATOS
            case 2: {
                modificarDatosEmision(regPresupuesto);

                break;
            }

            ///CASE 3 - BORRAR ITEM
            case 3: {
                borrarItemDetalleVenta(regPresupuesto);

                break;
            }

            ///CASE 4 - MOSTRAR VISTA PREVIA
            case 4: {
                mostrarVistaPrevia(regPresupuesto);

                break;
            }

            ///CASE 5 - CONFIRMACION FINAL
            case 5: {
                bool nuevoRegistro = false;
                menu = confirmacionPresupuesto(regPresupuesto, nuevoRegistro);

                break;
            }

            ///CASE 0 - CANCELACION FINAL
            case 0: {
                menu = cancelacionPresupuesto(regPresupuesto);

                break;
            }

            ///DEFAULT - ERROR
            default:

                break;

        }
    }
}

int facturarPresupuesto(Presupuesto& regPresupuesto){
    Factura regFactura;
    regFactura.setIdCliente(regPresupuesto.getIdCliente());

    regFactura.setCuitCliente(regPresupuesto.getCuitCliente());
    regFactura.setTipoCliente(regPresupuesto.getTipoCliente());
    regFactura.setDireccion(regPresupuesto.getDireccionCliente());
    regFactura.setNombreCliente(regPresupuesto.getNombreCliente());
    regFactura.setIdVendedor(regPresupuesto.getIdVendedor());
    regFactura.setNombreVendedor(regPresupuesto.getNombreVendedor());
    regFactura.setTipoCompra(regPresupuesto.getTipoCompra());
    regFactura.setCondicionPago(regPresupuesto.getCondicionPago());
    regFactura.setDetalleVenta(regPresupuesto.getDetalleVenta());
    regFactura.setImporteSubtotal(regPresupuesto.getImporteSubtotal());
    regFactura.setImporteIVA(regPresupuesto.getImporteIVA());
    regFactura.setImporteTotal(regPresupuesto.getImporteTotal());
    regFactura.setFecha(regPresupuesto.getFecha());
    regFactura.setEstado(regPresupuesto.getEstado());
    int facturo;
    facturo = confirmacionFactura(regFactura);
    systemClsEmisionFactura();
    regFactura.MostrarFacturaEmitida();
    return facturo;
}

int listarPresupuestos(){

    int opcion=1;
    while (opcion!=0){
        system ("cls");
        mostrarSubMenuListarPresupuestos();
        cin >> opcion;
        switch (opcion){

            case 1: {   ///LISTADO POR RANGO DE FECHA
                systemClsListadoPresupuesto();
                Fecha fechaInicial, fechaFinal;
                fechaFinal = rangoFecha(fechaInicial);
                systemClsListadoPresupuesto();

                cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;

                listarPresupuestosRangoFecha(fechaInicial, fechaFinal);
                system ("pause");
                break;
            }

            case 2: {   ///LISTADO POR CLIENTE Y RANGO DE FECHA
                systemClsListadoPresupuesto();
                Fecha fechaInicial, fechaFinal;
                fechaFinal = rangoFecha(fechaInicial);
                systemClsListadoPresupuesto();

                cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;

                cout << endl << "Ingrese el Id del Cliente: ";
                int idCliente;
                cin >> idCliente;

                ArchivoCliente regArchivoCliente;

                while (regArchivoCliente.buscarRegistro(idCliente)==-1){
                    cout << endl << "No se ha encontrado un cliente con ese id." << endl;
                    cout << endl << "Ingrese el Id del Cliente: ";
                    cin >> idCliente;
                }

                listarPresupuestosCliente(fechaInicial, fechaFinal, idCliente);
                system ("pause");
                break;
            }

            case 3: {   ///LISTADO POR ARTICULO Y RANGO DE FECHA
                systemClsListadoPresupuesto();
                Fecha fechaInicial, fechaFinal;
                fechaFinal = rangoFecha(fechaInicial);
                systemClsListadoPresupuesto();

                cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;

                cout << endl << "Ingrese el Id del Articulo: ";
                int idArticulo;
                cin >> idArticulo;

                ArchivoArticulo regArchivoArticulo;

                while (regArchivoArticulo.buscarRegistro(idArticulo)){
                    cout << endl << "Ingrese el Id del Articulo: ";
                    cin >> idArticulo;
                }

                listarPresupuestosArticulo(fechaInicial, fechaFinal, idArticulo);

                system ("pause");
                break;
            }

            case 0:
                cout << endl << "0 - VOLVER ATRAS" << endl << endl;
                cout << "Usted ha decidido salir del Listado de Presupuestos." << endl << endl;
                break;

            default:
                cout << endl << "ERROR" << endl << endl;
                cout << "Algo salio mal, intente nuevamente" << endl << endl;
                system ("pause");
                break;
        }
    }

    return opcion;
}

void listarPresupuestosRangoFecha(Fecha fechaInicial, Fecha fechaFinal){
    ArchivoPresupuesto regArchivoPresupuesto;
    Presupuesto regPresupuesto;

    mostrarEncabezadoPresupuestoResumido();

    int cantidad = regArchivoPresupuesto.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regPresupuesto = regArchivoPresupuesto.leerRegistro(i);
        if(regPresupuesto.getFecha()>=fechaInicial && regPresupuesto.getFecha()<=fechaFinal){
            regPresupuesto.MostrarPresupuestoResumen();
        }
    }
    cout << endl;
}

void listarPresupuestosCliente(Fecha fechaInicial, Fecha fechaFinal, int idCliente){
    ArchivoPresupuesto regArchivoPresupuesto;
    Presupuesto regPresupuesto;

    mostrarEncabezadoPresupuestoResumido();

    int cantidad = regArchivoPresupuesto.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regPresupuesto = regArchivoPresupuesto.leerRegistro(i);
        if(regPresupuesto.getFecha()>=fechaInicial && regPresupuesto.getFecha()<=fechaFinal){
            if (regPresupuesto.getIdCliente() == idCliente){
                regPresupuesto.MostrarPresupuestoResumen();
            }
        }
    }
    cout << endl;
}

void listarPresupuestosArticulo(Fecha fechaInicial, Fecha fechaFinal, int idArticulo){
    ArchivoPresupuesto regArchivoPresupuesto;
    Presupuesto regPresupuesto;

    mostrarEncabezadoPresupuestoArticulo();

    int cantidad = regArchivoPresupuesto.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regPresupuesto = regArchivoPresupuesto.leerRegistro(i);
        if(regPresupuesto.getFecha()>=fechaInicial && regPresupuesto.getFecha()<=fechaFinal){
            for (int j=0; i<regPresupuesto.getDetalleVenta().getTamActual(); i++){
                if (regPresupuesto.getDetalleVenta().getItem(j).getIdArticulo() == idArticulo){
                    regPresupuesto.MostrarPresupuestoArticulo(j);
                }
            }
        }
    }
    cout << endl;
}

#endif // FUNCIONESPRESUPUESTO_H_INCLUDED
