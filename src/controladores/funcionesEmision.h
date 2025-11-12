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


#endif // FUNCIONESEMISION_H_INCLUDED
