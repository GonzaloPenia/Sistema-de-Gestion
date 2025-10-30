#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

///FUNCIONES GLOBALES

///MENU PRINCIPAL
void mostrarMenuPrincipal();
///MENUS PRINCIPALES DE LAS DISTINTAS SECCIONES
void mostrarMenuPrincipalEmision();
void mostrarMenuPrincipalClientes();
void mostrarMenuPrincipalArticulos();
void mostrarMenuPrincipalProveedores();
void mostrarMenuPrincipalConfiguraciones();
void mostrarMenuPrincipalPresupuestos();
///SUBMENUS DE LAS DISTINTAS SECCIONES
void mostrarSubMenuBajaArticulos();
void mostrarSubMenuListarArticulos();
void mostrarSubMenuModificarArticulos();
void mostrarSubMenuBajaProveedores();
void mostrarSubMenuListarProveedores();
void mostrarSubMenuModificarProveedores();
void mostrarSubMenuListarEmisiones();
void mostrarSubMenuListarFacturas();
void mostrarSubMenuListarNotasDeCredito();
void mostrarSubMenuListarPresupuestos();
void mostrarSubMenuBajaClientes();
void mostrarSubMenuListarClientes();
void mostrarSubMenuModificarCliente();
void mostrarSubMenuBajaVendedores();
void mostrarSubMenuModificarVendedores();
void mostrarSubMenuListarVendedores();
/// FUNCIONES GLOBALES
void cargarCadena();
void convertirMinuscula(char* palabra);
bool confirmacion();
void gotoxy(int x, int y);
void dibujarCuadro(int x1, int y1, int x2, int y2);
/// FUNCIONES PARA BORRAR LA PANTALLA Y MANTENER DISTINTOS TITULOS
void systemClsEmisionFactura();
void systemClsEmisionNotaDeCredito();
void systemClsListadoFactura();
void systemClsListadoNotaDeCredito();
void systemClsEmisionPresupuesto();
void systemClsBusquedaPresupuesto();
void systemClsModificacionPresupuesto();
void systemClsEliminacionPresupuesto();
void systemClsFacturacionPresupuesto();
void systemClsVisualizacionPresupuesto();


///MENU PRINCIPAL

void mostrarMenuPrincipal(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU PRINCIPAL"<<endl<<endl;

    cout<<"1 - MENU EMISION."<<endl;
    cout<<"2 - MENU CLIENTES."<<endl;
    cout<<"3 - MENU ARTICULOS."<<endl;
    cout<<"4 - MENU PROVEEDORES."<<endl;
    cout<<"5 - CONFIGURACIONES."<<endl;
    cout<<"----------------------"<<endl;
    cout<<"0 - FIN DEL PROGRAMA..."<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}



///MENUS PRINCIPALES DE LAS DISTINTAS SECCIONES

void mostrarMenuPrincipalEmision(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU EMISION"<<endl<<endl;

    cout<<"1 - EMITIR FACTURA."<<endl;
    cout<<"2 - LISTAR FACTURAS."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarMenuPrincipalClientes(){
    cout<<"MENU CLIENTES"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"1 - AGREGAR CLIENTE."<<endl;
    cout<<"2 - BUSCAR CLIENTE."<<endl;
    cout<<"3 - MODIFICAR CLIENTE."<<endl;
    cout<<"4 - LISTAR CLIENTES."<<endl;
    cout<<"5 - ELIMINAR CLIENTE."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarMenuPrincipalArticulos(){
    cout<<"MENU ARTICULOS"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - AGREGAR ARTICULO."<<endl;
    cout<<"2 - BUSCAR ARTICULO."<<endl;
    cout<<"3 - MODIFICAR ARTICULO."<<endl;
    cout<<"4 - LISTAR ARTICULOS."<<endl;
    cout<<"5 - ELIMINAR ARTICULO."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarMenuPrincipalProveedores(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU PROVEEDORES"<<endl<<endl;

    cout<<"1 - AGREGAR PROVEEDOR."<<endl;
    cout<<"2 - BUSCAR PROVEEDOR."<<endl;
    cout<<"3 - MODIFICAR PROVEEDOR."<<endl;
    cout<<"4 - LISTAR PROVEEDORES."<<endl;
    cout<<"5 - ELIMINAR PROVEEDOR."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarMenuPrincipalConfiguraciones(){
    cout<<"MENU CONFIGURACIONES"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"1 - AGREGAR VENDEDOR."<<endl;
    cout<<"2 - BUSCAR VENDEDOR."<<endl;
    cout<<"3 - MODIFICAR VENDEDOR."<<endl;
    cout<<"4 - LISTAR VENDEDORES."<<endl;
    cout<<"5 - ELIMINAR VENDEDOR."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarMenuPrincipalPresupuestos(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU PRESUPUESTOS"<<endl<<endl;
    cout<<"1 - AGREGAR PRESUPUESTO."<<endl;
    cout<<"2 - MODIFICAR PRESUPUESTO."<<endl;
    cout<<"3 - CONVERTIR PRESUPUESTO A FACTURA."<<endl;
    cout<<"4 - VISUALIZAR PRESUPUESTO."<<endl;
    cout<<"5 - LISTAR PRESUPUESTOS."<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}



///SUBMENUS DE LAS DISTINTAS SECCIONES

    //ARTICULOS

void mostrarSubMenuModificarArticulos(){
    cout<<"MODIFICAR ATRIBUTOS ARTICULOS"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - MODIFICAR DESCRIPCION."<<endl;
    cout<<"2 - MODIFICAR PROVEEDOR/ARTICULO."<<endl;
    cout<<"3 - MODIFICAR PRECIO."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarArticulos(){
    cout<<"LISTAR ARTICULOS"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - LISTAR DE MAYOR A MENOR PRECIO."<<endl;
    cout<<"2 - LISTAR DE MENOR A MAYOR PRECIO."<<endl;
    cout<<"3 - ORDENAR POR ID DE MAYOR A MAYOR."<<endl;
    cout<<"4 - ORDENAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"5 - LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuBajaArticulos(){
    cout<<"BAJA ARTICULOS"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

    //PROVEEDORES

void mostrarSubMenuBajaProveedores(){
    cout<<"BAJA PROVEEDOR."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarProveedores(){
    cout<<"LISTA PROVEEDORES."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - LISTAR POR ID DE MAYOR A MENOR."<<endl;
    cout<<"2 - LISTAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"3 - LISTAR POR CANTIDAD DE COMPRAS DE MAYOR A MENOR."<<endl;
    cout<<"4 - LISTAR POR CANTIDAD DE COMPRAS DE MENOR A MAYOR."<<endl;
    cout<<"5 - LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarProveedores(){
    cout<<"MODIFICAR PROVEEDOR."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - MODIFICAR NOMBRE DEL PROVEEDOR."<<endl;
    cout<<"2 - MODIFICAR CONTACTO EMAIL DEL PROVEEDOR."<<endl;
    cout<<"3 - MODIFICAR EMAIL DEL PROVEEDOR."<<endl;
    cout<<"4 - MODIFICAR TELEFONO MOVIL DEL PROVEEDOR."<<endl;
    cout<<"5 - MODIFICAR TELEFONO FIJO DEL PROVEEDOR."<<endl;
    cout<<"6 - MODIFICAR DIRECCION DEL PROVEEDOR."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

    //EMISION

void mostrarSubMenuListarEmisiones(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"LISTA DE EMISIONES"<<endl<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - LISTAR FACTURAS"<<endl;
   cout<<"2 - LISTAR NOTAS DE CREDITO"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarFacturas(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"LISTA DE FACTURAS"<<endl<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - POR RANGO DE FECHA"<<endl;
    cout<<"2 - POR CLIENTE Y RANGO DE FECHA"<<endl;
    cout<<"3 - POR ARTICULO Y RANGO DE FECHA"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarNotasDeCredito(){
    dibujarCuadro(1,1,77,3);
    gotoxy(26,2);
    cout<<"LISTA DE NOTAS DE CREDITO"<<endl<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - POR RANGO DE FECHA"<<endl;
    cout<<"2 - POR CLIENTE Y RANGO DE FECHA"<<endl;
    cout<<"3 - POR ARTICULO Y RANGO DE FECHA"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarPresupuestos(){
    dibujarCuadro(1,1,77,3);
    gotoxy(26,2);
    cout<<"LISTA DE PRESUPUESTOS"<<endl<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - POR RANGO DE FECHA"<<endl;
    cout<<"2 - POR CLIENTE Y RANGO DE FECHA"<<endl;
    cout<<"3 - POR ARTICULO Y RANGO DE FECHA"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

    //CLIENTES

void mostrarSubMenuBajaClientes(){
    cout<<"BAJA CLIENTES"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarClientes(){
    cout<<"LISTAR CLIENTES"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - LISTAR DE MAYOR A MENOR VENTAS."<<endl;
    cout<<"2 - LISTAR DE MENOR A MAYOR VENTAS."<<endl;
    cout<<"3 - ORDENAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"4 - ORDENAR POR ID DE MAYOR A MENOR."<<endl;
    cout<<"5 - ORDENAR POR CUIT DE MENOR A MAYOR."<<endl;
    cout<<"6 - ORDENAR POR CUIT DE MAYOR A MENOR."<<endl;
    cout<<"7 - LISTAR ALFABETICAMENTE."<<endl;
    cout<<"8 - LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"9 - ORDENAR POR RECAUDACION."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarCliente(){
    cout<<"MODIFICAR ATRIBUTOS CLIENTES"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - MODIFICAR TIPO."<<endl;
    cout<<"2 - MODIFICAR DIRECCION/CONTACTO."<<endl;
    cout<<"3 - MODIFICAR CANTIDAD DE VENTAS."<<endl;
    cout<<"4 - MODIFICAR NOMBRE."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

    //VENDEDORES

void mostrarSubMenuBajaVendedores(){
    cout<<"BAJA VENDEDORES"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarVendedores(){
    cout<<"MODIFICAR ATRIBUTOS VENDEDOR"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - MODIFICAR SUELDO."<<endl;
    cout<<"2 - MODIFICAR VENTAS REALIZADAS."<<endl;
    cout<<"3 - MODIFICAR NOMBRE."<<endl;
    cout<<"4 - MODIFICAR ANTIGUEDAD."<<endl;
    cout<<"5 - MODIFICAR EDAD."<<endl;
    cout<<"6 - MODIFICAR DOMICILIO."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarVendedores(){
    cout<<"LISTAR VENDEDORES"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - LISTAR DE MAYOR A MENOR VENTAS."<<endl;
    cout<<"2 - LISTAR DE MENOR A MAYOR VENTAS."<<endl;
    cout<<"3 - ORDENAR POR ANTIGUEDAD DE MENOR A MAYOR."<<endl;
    cout<<"4 - ORDENAR POR ANTIGUEDAD DE MENOR A MAYOR."<<endl;
    cout<<"5 - LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}


/// FUNCIONES GLOBALES

    //PERMITE CARGAR UNA CADENA DE CARACTERES INDICANDO LA CADENA Y EL TAMA�O DE LA MISMA
void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

    //PERMITE CONVERTIR A MINUSCULA UNA CADENA DE CARACTERES
void convertirMinuscula(char* palabra) {
    while (*palabra) {
        *palabra = tolower(static_cast<unsigned char>(*palabra));
        palabra++;
    }
}

    //DA LA OPCION DE CONFIRMAR UNA DECISION. DEVUELVE TRUE SI SE CONFIRMA, Y FALSE SI SE DESEA MODIFICAR.
bool confirmacion (){
    char opcion[3]{};
    bool confirmacion;
    bool bandera = true;
    while (bandera){
        bandera = false;
        cout << endl << "Esta conforme con su seleccion (1-SI, 2-NO): ";
        cargarCadena(opcion,3);
        if (strcmp(opcion,"1")==0||strcmp(opcion,"s")==0||strcmp(opcion,"S")==0||strcmp(opcion,"SI")==0||strcmp(opcion,"si")==0){
            confirmacion = true;
            cout << endl << "La opcion ha sido confirmada sin modificacion!" << endl << endl;
        } else if (strcmp(opcion,"2")==0||strcmp(opcion,"n")==0||strcmp(opcion,"N")==0||strcmp(opcion,"NO")==0||strcmp(opcion,"no")==0){
            cout << endl << "Esta seguro que desea modificar su seleccion (1-SI, 2-NO): ";
            cargarCadena(opcion,3);
            if (strcmp(opcion,"1")==0||strcmp(opcion,"s")==0||strcmp(opcion,"S")==0||strcmp(opcion,"SI")==0||strcmp(opcion,"si")==0){
                confirmacion = false;
                cout << endl << "Usted ha decidido modificar el ingreso." << endl << endl;
            } else if (strcmp(opcion,"2")==0||strcmp(opcion,"n")==0||strcmp(opcion,"N")==0||strcmp(opcion,"NO")==0||strcmp(opcion,"no")==0){
                bandera = true;
            }
        } else {
            cout << endl << "La opcion ingresada es invalida. Vuelva a intentarlo." << endl << endl;
            bandera = true;
        }
    }
    system ("pause");
    system ("cls");
    return confirmacion;
}

    //FUNCION QUE PERMITE SITUAR EL CURSOR EN UNA COORDENADA
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

    //FUNCION QUE DIBUJA UN CUADRO PARA LOS TITULOS
void dibujarCuadro(int x1, int y1, int x2, int y2){
    int i;

    for (i=x1; i<x2; i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
    }

    for (i=y1; i<y2; i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}

    gotoxy(x1,y1); cout<< "\332";
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}



/// FUNCIONES PARA BORRAR LA PANTALLA Y MANTENER DISTINTOS TITULOS

void systemClsEmisionFactura(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout << "EMISION DE FACTURA" << endl << endl;
}

void systemClsEmisionNotaDeCredito(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(26,2);
    cout << "EMISION DE NOTA DE CREDITO" << endl << endl;
}

void systemClsListadoFactura(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout << "LISTADO DE FACTURAS" << endl << endl;
}

void systemClsListadoNotaDeCredito(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(26,2);
    cout << "LISTADO DE NOTA DE CREDITO" << endl << endl;
}

void systemClsEmisionPresupuesto(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(27,2);
    cout << "EMISION DE PRESUPUESTO" << endl << endl;
}

void systemClsListadoPresupuesto(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(27,2);
    cout << "LISTADO DE PRESUPUESTOS" << endl << endl;
}

void systemClsModificacionPresupuesto(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "MODIFICACION DE PRESUPUESTO" << endl << endl;
}

void systemClsEliminacionPresupuesto(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "ELIMINACION DE PRESUPUESTO" << endl << endl;
}

void systemClsFacturacionPresupuesto(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "FACTURACION DE PRESUPUESTO" << endl << endl;
}

void systemClsVisualizacionPresupuesto(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(23,2);
    cout << "VISUALIZACION DE PRESUPUESTO" << endl << endl;
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
