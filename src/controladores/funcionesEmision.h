#ifndef FUNCIONESEMISION_H_INCLUDED
#define FUNCIONESEMISION_H_INCLUDED

///FUNCIONES GLOBALES DENTRO DE LA CLASE BASE EMISION

///MENUS DE EMISION
void mostrarMenuSecundarioEmision();
void mostrarSubmenuEmisionModificar();
void mostrarMenuContinuarCargaDetalle();
///FORMATO DETALLE
void mostrarEncabezadoDetalle();
void menuMostrarImportes(Factura& regFactura);
///FUNCIONES DE LISTADOS
Fecha rangoFecha (Fecha& fechaInicial);
void mostrarEncabezadoEmisionResumida();
void mostrarEncabezadoEmisionArticulo();
void listarFacturas();
void listarFacturasRangoFecha(Fecha fechaInicial, Fecha fechaFinal);
void listarFacturasCliente(Fecha fechaInicial, Fecha fechaFinal, int idCliente);
void listarFacturasArticulo(Fecha fechaInicial, Fecha fechaFinal, int idArticulo);
void listarNotasDeCreditoRangoFecha(Fecha fechaInicial, Fecha fechaFinal);
void listarNotasDeCreditoCliente(Fecha fechaInicial, Fecha fechaFinal, int idCliente);
void listarNotasDeCreditoArticulo(Fecha fechaInicial, Fecha fechaFinal, int idArticulo);
void listarNotasDeCredito();
void listarEmisiones();

///MENUS DE EMISION

//MENU SECUNDARIO EMISION (UNIVERSAL: FACTURA, NOTA DE CR�DITO, PRESUPUESTO)
void mostrarMenuSecundarioEmision(){
    cout<<"QUE DESEA HACER A CONTINUACION?"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"1 - CARGAR OTRO ARTICULO"<<endl;
    cout<<"2 - MODIFICAR DATOS"<<endl;
    cout<<"3 - BORRAR ARTICULO CARGADO"<<endl;
    cout<<"4 - MOSTRAR VISTA PREVIA"<<endl;
    cout<<"5 - CONFIRMAR CARGA"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"0 - CANCELAR CARGA"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

//SUBMENU DE EMISION: MODIFICAR DATOS (UNIVERSAL: FACTURA, NOTA DE CR�DITO, PRESUPUESTO)
void mostrarSubmenuEmisionModificar(){
    cout<<"MODIFICAR DATOS"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"1 - MODIFICAR CLIENTE"<<endl;
    cout<<"2 - MODIFICAR VENDEDOR"<<endl;
    cout<<"3 - MODIFICAR DATOS VENTA"<<endl;
    cout<<"4 - MODIFICAR ITEMS"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"0 - TERMINAR MODIFICACION"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

//MENU DE DECISION PARA CONTINUAR O TERMINAR LA CARGA DE LOS ARTICULOS EN UN DETALLE (UNIVERSAL: FACTURA, NOTA DE CR�DITO, PRESUPUESTO)
void mostrarMenuContinuarCargaDetalle(){
    cout<<"CONTINUAR LA CARGA DE ARTICULOS?"<<endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout<<"1 - SEGUIR CARGANDO"<<endl;
    cout<<"0 - TERMINAR CARGA"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

///FORMATO DETALLE

//ENCABEZADO PARA TODOS LOS DETALLES DE VENTA (UNIVERSAL: FACTURA, NOTA DE CR�DITO, PRESUPUESTO)
void mostrarEncabezadoDetalle(){
    cout << endl;
    cout << left << setw(5) << "Item";
    cout << right << setw(11) << "Cantidad  ";
    cout << left << setw(9) << "Cod.Art. " << setw(55) << "Descripcion";
    cout << right << setw(14) << "P.Unitario    " << setw(11) << "Importe" << endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;
}

void menuMostrarImportes(Factura& regFactura){
    /*float importeSubtotal = calcImporteSubtotal(regFactura);
    float importeIVA = calcImporteIVA(regFactura);
    float importeTotal = calcImporteTotal(importeSubtotal, importeIVA);*/
    cout << endl;
    cout << left << setw(15) << "Subtotal:" << setw(1) << "$" << setw(15) << regFactura.getImporteSubtotal() << endl;
    cout << left << setw(15) << "Neto IVA:" <<  setw(1) << "$" << setw(15) << regFactura.getImporteIVA() << endl;
    cout << setfill('-') << setw(31) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "TOTAL:" <<  setw(1) << "$" << setw(15) << regFactura.getImporteTotal() << endl;
    /*
    regFactura.setImporteSubtotal(importeSubtotal);
    regFactura.setImporteIVA(importeIVA);
    regFactura.setImporteTotal(importeTotal);
    */
}

///FUNCIONES DE LISTADOS

Fecha rangoFecha (Fecha& fechaInicial){
    Fecha fechaFinal;
    cout<<"Debera ingresar el rango de Fechas."<<endl<<endl;
    cout<<"\tFECHA INICIAL: "<<endl;
    fechaInicial.Cargar();
    cout<<endl<<"\tFECHA FINAL: "<<endl;
    fechaFinal.Cargar();
    return fechaFinal;
}


void mostrarEncabezadoEmisionResumida(){
    cout << setfill('-') << setw(103) << "-" << setfill(' ') << endl;
    cout << left << setw(14) << "FECHA" << setw(6) << "NUMERO" << setw(4) << " " << setw(10) << "ID.CLIENTE"
                 << setw(2) << " " << setw(55) << "RAZON SOCIAL";
    cout << right << setw(12) << "IMPORTE" << endl;
    cout << setfill('-') << setw(103) << "-" << setfill(' ') << endl;
}

void mostrarEncabezadoEmisionArticulo(){
    cout << setfill('-') << setw(122) << "-" << setfill(' ') << endl;
    cout << left << setw(14) << "FECHA" << setw(6) << "NUMERO" << setw(4) << " " << setw(10) << "ID.CLIENTE"
                 << setw(2) << " " << setw(55) << "RAZON SOCIAL" << setw(9) << "VENDEDOR" << setw(10) << "CANTIDAD";
    cout << right << setw(12) << "IMPORTE ART." << endl;
    cout << setfill('-') << setw(122) << "-" << setfill(' ') << endl;
}


void listarFacturas(){
    ArchivoFactura regArchivoFactura;

    mostrarEncabezadoEmisionResumida();

    regArchivoFactura.listarRegistos();
}

void listarFacturasRangoFecha(Fecha fechaInicial, Fecha fechaFinal){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    mostrarEncabezadoEmisionResumida();

    int cantidad = regArchivoFactura.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if(regFactura.getFecha()>=fechaInicial && regFactura.getFecha()<=fechaFinal){
            regFactura.MostrarFacturaResumen();
        }
    }
    cout << endl;
}

void listarFacturasCliente(Fecha fechaInicial, Fecha fechaFinal, int idCliente){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    mostrarEncabezadoEmisionResumida();

    int cantidad = regArchivoFactura.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if(regFactura.getFecha()>=fechaInicial && regFactura.getFecha()<=fechaFinal){
            if (regFactura.getIdCliente() == idCliente){
                regFactura.MostrarFacturaResumen();
            }
        }
    }
    cout << endl;
}

void listarFacturasArticulo(Fecha fechaInicial, Fecha fechaFinal, int idArticulo){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    mostrarEncabezadoEmisionArticulo();

    int cantidad = regArchivoFactura.contarRegistros();

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if(regFactura.getFecha()>=fechaInicial && regFactura.getFecha()<=fechaFinal){
            for (int j=0; i<regFactura.getDetalleVenta().getTamActual(); i++){
                if (regFactura.getDetalleVenta().getItem(j).getIdArticulo() == idArticulo){
                    regFactura.MostrarFacturaArticulo(j);
                }
            }
        }
    }
    cout << endl;
}

void listarEmisiones(){
    int opcion=1;
    while (opcion!=0){
        system ("cls");
        //mostrarSubMenuListarEmisiones();       

            
                system("cls");
                mostrarSubMenuListarFacturas();
                int opcion2;
                cin >> opcion2;
                switch (opcion2){

                    case 1: {   ///LISTADO POR RANGO DE FECHA
                        systemClsListadoFactura();
                        Fecha fechaInicial, fechaFinal;
                        fechaFinal = rangoFecha(fechaInicial);
                        systemClsListadoFactura();
                        cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;
                        listarFacturasRangoFecha(fechaInicial, fechaFinal);
                        system ("pause");
                        break;
                    }

                    case 2: {   ///LISTADO POR CLIENTE Y RANGO DE FECHA
                        systemClsListadoFactura();
                        Fecha fechaInicial, fechaFinal;
                        fechaFinal = rangoFecha(fechaInicial);
                        systemClsListadoFactura();
                        cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;
                        cout << endl << "Ingrese el Id del Cliente: ";
                        int idCliente;
                        cin >> idCliente;

                        ArchivoContacto regArchivoCliente;

                        while (regArchivoCliente.buscarRegistro(idCliente)==-1){
                            cout << endl << "No se ha encontrado un cliente con ese id." << endl;
                            cout << endl << "Ingrese el Id del Cliente: ";
                            cin >> idCliente;
                        }
                        listarFacturasCliente(fechaInicial, fechaFinal, idCliente);
                        system ("pause");
                        break;
                    }

                    case 3: {   ///LISTADO POR ARTICULO Y RANGO DE FECHA
                        systemClsListadoFactura();
                        Fecha fechaInicial, fechaFinal;
                        fechaFinal = rangoFecha(fechaInicial);
                        systemClsListadoFactura();
                        cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;
                        cout << endl << "Ingrese el Id del Articulo: ";
                        int idArticulo;
                        cin >> idArticulo;

                        ArchivoArticulo regArchivoArticulo;

                        while (regArchivoArticulo.buscarRegistro(idArticulo)==-1){
                            cout << endl << "No se ha encontrado un cliente con ese id." << endl;
                            cout << endl << "Ingrese el Id del Articulo: ";
                            cin >> idArticulo;
                        }

                        listarFacturasArticulo(fechaInicial, fechaFinal, idArticulo);
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

#endif // FUNCIONESEMISION_H_INCLUDED
