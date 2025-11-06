#include <iostream>     // Entrada y salida estandar (cin, cout, >>, <<, endl, setw, setprecision, fixed)
#include <iomanip>      // Manipuladores de flujo (setw, setprecision, setfill, fixed)
#include <cstdlib>      // Gestion de memoria, generacion de numeros aleatorios, etc (srand, exit)
#include <windows.h>    // Interactuar con S.O. Windows (verificarArchivoExistente, gotoxy)
#include <cstdio>       // Entrada y salida de datos (fopen, fclose, fread, fwrite, fseek, ftell,
#include <cstring>      // Manipuladores de cadenas de caracteres (strcpy, strcmp, strlen, strstr, )
#include <vector>       // Proporciona la clase dinamica "vector" (push_back)
#include <ctime>        // Manipular y trabajar con fechas y tiempos (time)
#include <cctype>       // Analisis y conversion de caracteres (tolower)
#include <direct.h>     // Proporciona funciones para trabajar con archivos y directorios
#include <algorithm>

using namespace std;

#include "globales/funcionesGlobales.h"
//#include "globales/clsGlobales.h"
#include "clases/Direccion.h"
#include "clases/Fecha.h"

#include "clases/Vendedor.h"
#include "clsArchivo/ArchivoVendedor.h"
#include "controladores/funcionesVendedor.h"

#include "clases/Contacto.h"

#include "clases/Entidad.h"
#include "clases/Cliente.h"
#include "clsArchivo/ArchivoCliente.h"
#include "controladores/funcionesCliente.h"
#include "clases/Proveedor.h"
#include "clsArchivo/ArchivoProveedor.h"

#include "clases/Articulo.h"
#include "clsArchivo/ArchivoArticulo.h"
#include "controladores/funcionesArticulo.h"
#include "controladores/funcionesProveedor.h"
#include "controladores/funcionesEntidad.h"

#include "clases/Item.h"
#include "clases/Detalle.h"
#include "clases/Emision.h"
#include "clases/Factura.h"
#include "clsArchivo/ArchivoFactura.h"
#include "controladores/funcionesEmision.h"
#include "controladores/funcionesFactura.h"

// Incluir las implementaciones de funciones de carrito DESPUES de todas las clases
#include "controladores/funcionesCarrito.h"

int main(){
    int menu=1;
    while(menu!=0){
        int sub_menu=1;
        system ("cls");
        mostrarMenuPrincipal();
        cin>>menu;
        switch(menu){

        ///CASE 1 - EMISION
        case 1: {
            while(sub_menu!=0){
                system ("cls");
                mostrarMenuPrincipalEmision();
                cin>>sub_menu;
                system ("cls");
                switch(sub_menu){

                    //EMISION DE FACTURAS
                    case 1: {
                        cout<<"1-EMISION DE FACTURA."<<endl;
                        cout<<"---------------------"<<endl;
                        menuGestionCarrito();
                        system ("pause");
                        break;
                    }

                    //LISTADO DE FACTURAS Y NOTAS DE CREDITO
                    case 2: {
                        cout<<"2-LISTADO DE FACTURAS"<<endl; /// SOLO NOTA DE CREDITO
                        listarEmisiones();
                        system ("pause");
                        break;
                    }

                    case 0: {
                        cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;
                        cout << "Usted ha decidido salir del Menu de Emision." << endl << endl;
                        system ("pause");
                        break;
                    }

                    default:
                        cout << "ERROR" << endl << endl;
                        cout << "Algo salio mal, intente nuevamente" << endl << endl;
                        system ("pause");
                        break;
                }
            }
            break;
        }

        ///CASE 2 - CLIENTES
        case 2: {
            while(sub_menu!=0){
                system ("cls");
                mostrarMenuPrincipalClientes();
                cin>>sub_menu;
                system ("cls");
                switch(sub_menu){
                    case 1: {
                        cargarCliente();
                        system ("pause");
                        break;
                    }

                    case 2:{
                        buscarCliente();
                        system ("pause");
                        break;
                        }

                    case 3:{
                        int modificar;
                        system ("cls");
                        mostrarSubMenuModificarCliente();
                        cin>>modificar;
                        switch (modificar)
                        {

                            case 1:{
                                modificarTipo();
                                system ("pause");
                                break;
                                }


                            case 2:{
                                modificarDireccionYContacto();
                                system("pause");
                                break;
                                }

                            case 3:{
                                modificarCantidadVentas();
                                system("pause");
                                break;
                                }

                            case 4:{

                                modificarNombreCliente();
                                system("pause");
                                break;
                                }

                            default:{

                                break;
                                }
                            }
                            break;
                        }
///TODAS LAS LISTAS DE CLIENTES
                    case 4:
                        int listar;
                        cout<<"4-LISTAR CLIENTES."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuListarClientes();
                        cin>>listar;
                        switch (listar)
                        {
                        case 1:
                        cout<<"1-LISTAR DE MAYOR A MENOR VENTAS."<<endl;
                        cout<<"----------------------------"<<endl;
                        system("cls");
                        listarDeMayorAMenorVentas();
                        system ("pause");
                        break;


                        case 2:
                        cout<<"2-LISTAR DE MENOR A MAYOR VENTAS."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listarDeMenorAMayorVentas();
                        system ("pause");
                        break;


                        case 3:
                        cout<<"3-ORDENAR POR ID DE MENOR A MAYOR."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listaIdMenorAMayorCliente();
                        system ("pause");
                        break;


                        case 4:
                        cout<<"4-ORDENAR POR ID DE MAYOR A MENOR."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listaIdMayorAMenorCliente();
                        system ("pause");
                        break;

                        case 5:
                        cout<<"5-LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listaCuitMenorAMayorCliente();
                        system ("pause");
                        break;

                        case 6:
                        cout<<"6-LISTAR POR CUIT DE MAYOR A MENOR."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listaCuitMayorAMenorCliente();
                        system ("pause");
                        break;

                        case 7:
                        cout<<"7-LISTAR ALFABETICAMENTE."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listaAlfabeticamenteCliente();
                        system ("pause");
                        break;

                        case 8:
                        cout<<"8-LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listarClientes();
                        system ("pause");
                        break;

                        case 9:
                        cout<<"9 - ORDENAR POR RECAUDACION."<<endl;
                        cout<<"--------------------"<<endl;
                        system("cls");
                        listarRecaudacion();
                        system ("pause");
                        break;

                        default:
                            break;
                        }
                    break;
///DAR DE BAJA CLIENTES
                    case 5:
                        int baja;
                        cout<<"5-BAJA CLIENTE."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuBajaClientes();
                        cin>>baja;
                        switch (baja)
                        {

                            case 1:
                                cout<<"1-BAJA LOGICA."<<endl;
                                cout<<"---------------------"<<endl;
                                borrarLogicoCliente();
                                system("pause");
                                break;

                            case 2:
                                cout<<"2-BAJA FISICA."<<endl;
                                cout<<"---------------------"<<endl;
                                borrarFisicoCliente();
                                system("pause");
                                break;

                            default:
                                break;

                        }
                        //system ("pause");
                        break;

                    case 0:{
                        cout << "0 - SALIDA DEL MENU DE CLIENTES" << endl << endl;
                        cout << "Usted ha decidido salir del Menu de Clientes." << endl << endl;
                        system ("pause");
                        break;
                        }
                    default:{
                        cout << "ERROR" << endl << endl;
                        cout << "Algo salio mal, intente nuevamente" << endl << endl;
                        system ("pause");
                        break;
                    }
                }
                cout << endl << "Fin Switch Clientes" << endl << endl;
            }
            cout << endl << "Fin While Clientes" << endl << endl;
            break;
        }

        ///CASE 3 - ARTICULOS
        case 3: {
            while(sub_menu!=0){
                system ("cls");
                mostrarMenuPrincipalArticulos();
                cin>>sub_menu;
                system ("cls");
                switch(sub_menu){

                    case 1:
                        cout<<"1-AGREGAR ARTICULO."<<endl;
                        cout<<"--------------------"<<endl;
                        cargarArticulo();
                        system ("pause");
                        break;

                    case 2:
                        cout<<"2-BUSCAR ARTICULO."<<endl;
                        cout<<"------------------"<<endl;
                        buscarArticulo();
                        system ("pause");
                        break;


                    case 3:
                        int modificar;
                        cout<<"3-MODIFICAR ARTICULO."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuModificarArticulos();
                        cin>>modificar;
                        switch (modificar){

                            case 1:
                                cout<<"1-MODIFICAR DESCRIPCION."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarDescripcion();
                                system("pause");
                                break;


                            case 2:
                                cout<<"2-MODIFICAR PROVEEDOR/ARTICULO."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarProveedor();
                                system("pause");
                                break;


                            case 3:
                                cout<<"3-MODIFICAR PRECIO."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarPrecio();
                                system("pause");
                                break;

                            default:
                                break;
                            }
                        //system ("pause");
                        break;

                    //------------------------------------------------------------------

                    case 4:
                        int listar;
                        cout<<"4-LISTAR ARTIUCULOS."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuListarArticulos();
                        cin>>listar;
                        switch (listar)
                        {
                        case 1:
                        cout<<"1-LISTAR DE MAYOR A MENOR PRECIO."<<endl;
                        cout<<"----------------------------"<<endl;
                        listarArticuloPorPrecioDeMayorAMenor();
                        system ("pause");
                        break;


                        case 2:
                        cout<<"2-LISTAR DE MENOR A MAYOR PRECIO."<<endl;
                        cout<<"--------------------"<<endl;
                        listarArticuloPorPrecioDeMenorAMayor();
                        system ("pause");
                        break;


                        case 3:
                        cout<<"3-ORDENAR POR ID DE MENOR A MAYOR."<<endl;
                        cout<<"--------------------"<<endl;
                        listaArticuloPorIdDeMayorAMenor();
                        system ("pause");
                        break;


                        case 4:
                        cout<<"4-ORDENAR POR ID DE MAYOR A MENOR."<<endl;
                        cout<<"--------------------"<<endl;
                        listaArticuloPorIdDeMenorAMayor();
                        system ("pause");
                        break;

                        case 5:
                        cout<<"5-LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
                        cout<<"--------------------"<<endl;
                        listaDeArticulos();
                        system ("pause");
                        break;

                        default:
                            break;
                        }
                        //system ("pause");
                        break;

                    //------------------------------------------------------------------

                    case 5:
                        int baja;
                        cout<<"5-BAJA ARTICULO."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuBajaArticulos();
                        cin>>baja;
                        switch (baja)
                        {

                            case 1:
                                cout<<"1-BAJA LOGICA."<<endl;
                                cout<<"---------------------"<<endl;
                                borrarLogico();
                                break;

                            case 2:
                                cout<<"2-BAJA FISICA."<<endl;
                                cout<<"---------------------"<<endl;
                                borrarFisico();
                                break;

                            default:
                                break;

                        }
                        //system ("pause");
                        break;

                    //------------------------------------------------------------------
                    case 0:
                        cout << "0 - SALIDA DEL MENU DE ARTICULOS" << endl << endl;
                        cout << "Usted ha decidido salir del Menu de Articulos." << endl << endl;
                        system ("pause");
                        break;

                    default:
                        cout << "ERROR" << endl << endl;
                        cout << "Algo salio mal, intente nuevamente" << endl << endl;
                        system ("pause");
                        break;
                }
                cout << endl << "Fin Switch Articulos" << endl << endl;
            }
            cout << endl << "Fin While Articulos" << endl << endl;
            break;
        }

        ///CASE 4 - PROVEEDORES
        case 4: {
            while(sub_menu!=0){
                system ("cls");
                mostrarMenuPrincipalProveedores();
                cin>>sub_menu;
                system ("cls");
                switch(sub_menu){
                    case 1: {
                        //cout<<"1 - AGREGAR PROVEEDOR."<<endl;
                        system ("cls");
                        cargarProveedor();
                        system ("pause");
                        break;
                    }

                    case 2: {
                        //cout<<"2 - BUSCAR PROVEEDOR."<<endl;
                        system ("cls");
                        buscarProveedor();
                        system ("pause");
                        break;
                    }

                    case 3: {
                        //cout<<"2 - MODIFICAR PROVEEDOR."<<endl;
                        system ("cls");
                        int modificar;
                        mostrarSubMenuModificarProveedores();
                        cin>>modificar;
                        switch (modificar)
                            {
                            case 1 :
                                modificarNombreProveedor();
                                system ("pause");
                                break;

                            case 2 :
                                // FUNCION OBSOLETA - Usar opcion 6 "GESTIONAR CONTACTOS"
                                cout << "ESTA FUNCION FUE REEMPLAZADA" << endl;
                                cout << "USE LA OPCION 6 'GESTIONAR CONTACTOS' DEL MENU PRINCIPAL" << endl;
                                system ("pause");
                                break;

                            case 3 :
                                // FUNCION OBSOLETA - Usar opcion 6 "GESTIONAR CONTACTOS"
                                cout << "ESTA FUNCION FUE REEMPLAZADA" << endl;
                                cout << "USE LA OPCION 6 'GESTIONAR CONTACTOS' DEL MENU PRINCIPAL" << endl;
                                system ("pause");
                                break;

                            case 4 :
                                // FUNCION OBSOLETA - Usar opcion 6 "GESTIONAR CONTACTOS"
                                cout << "ESTA FUNCION FUE REEMPLAZADA" << endl;
                                cout << "USE LA OPCION 6 'GESTIONAR CONTACTOS' DEL MENU PRINCIPAL" << endl;
                                system ("pause");
                                break;

                            case 5 :
                                // FUNCION OBSOLETA - Usar opcion 6 "GESTIONAR CONTACTOS"
                                cout << "ESTA FUNCION FUE REEMPLAZADA" << endl;
                                cout << "USE LA OPCION 6 'GESTIONAR CONTACTOS' DEL MENU PRINCIPAL" << endl;
                                system ("pause");
                                break;

                            case 6 :
                                modificarDireccionProveedor();
                                system ("pause");
                                break;
                            default:
                                break;
                            }
                        break;
                    }

                    case 4:{
                        //cout<<"3 - LISTAR PROVEEDOR."<<endl;
                        system ("cls");
                        int listar;
                        mostrarSubMenuListarProveedores();
                        cin>>listar;
                        switch (listar)
                             {
                            case 1:
                                system ("cls"); 
                                listarProveedoresPorIdMayorAMenor();
                                system ("pause");
                                break;
                            case 2:
                                system ("cls");    
                                listarProveedoresPorIdMenorAMayor();
                                system ("pause");
                                break;
                            case 3:
                                system ("cls");
                                listarProveedoresPorMayorCantidadDeCompras();
                                system ("pause");
                                break;
                            case 4:
                                system ("cls");
                                listarProveedoresPorMenorCantidadDeCompras();
                                system ("pause");
                                break;

                            case 5:
                                system ("cls");
                                listaDeProveedores();
                                system ("pause");
                                break;

                            default:
                                break;
                            }
                        break;
                    }

                    case 5:{
                        //cout<<"4 - ELIMINAR PROVEEDOR."<<endl;
                        int borrar;
                        mostrarSubMenuBajaProveedores();
                        cin>>borrar;
                        switch (borrar)
                            {
                            case 1:
                                borrarProveedorLogico();
                                break;
                            case 2:
                                borrarProveedorFisico();
                                break;

                            default:
                                break;
                            }
                        break;
                    }

                    case 0:
                        cout << "0 - SALIDA DEL MENU DE PROVEEDORES" << endl << endl;
                        cout << "Usted ha decidido salir del Menu de Proveedores." << endl << endl;
                        system ("pause");
                        break;

                    default:
                        cout << "ERROR" << endl << endl;
                        cout << "Algo salio mal, intente nuevamente" << endl << endl;
                        system ("pause");
                        break;
                }
                cout << endl << "Fin Switch Proveedores" << endl << endl;
            }
            cout << endl << "Fin While Proveedores" << endl << endl;
            break;
        }

        ///CASE 5 - CONTACTOS
        case 5:{
            int listar;
            system ("cls");
            mostrarMenuContactos();
            cin>>listar;
            system ("cls");
            switch (listar)
                    {
                case 1:
                    //AGREGAR CONTACTO;
                    

                    agregarContacto();                    
                    system ("pause");
                    break;
                case 2:
                    //BUSCAR CONTACTO
                    buscarContactoPorID();
                    system ("pause");
                    break;
                case 3:
                    //MODIFICAR CONTACTO
                    system ("pause");
                    break;
                case 4:
                    //LISTAR CONTACTO
                    subMenuListarContactos();
                    int ListaContactos;
                    cin >> ListaContactos;
                    switch(ListaContactos){

                        case 1:{
                            listarContactos();
                            break;

                        }
                        case 2:{
                            listarContactosPorEntidad();

                            break;
                        }

                        case 0: {

                            cout << "VOLVIENDO AL MENU DE CONTACTOS..." <<endl;
                            system ("pause");

                            break;
                        }



                        default: 
                            break;
                    }
                    
                    system ("pause");
                    break;

                case 5:
                    //ELIMINAR CONTACTO
                    system ("pause");
                    break;

                default:
                    break;
                }
            break;
            }

        ///CASE 6 - CONFIGURACIONES
        case 6: {
            while(sub_menu!=0){
                system ("cls");
                mostrarMenuPrincipalConfiguraciones();
                cin>>sub_menu;
                system ("cls");
                switch(sub_menu){
                    case 1: {
                        cout<<"1 - AGREGAR VENDEDOR."<<endl;
                        cout<<"---------------------"<<endl;
                        cargarVendedor();
                        system ("pause");
                        break;
                    }

                    case 2:{
                        cout<<"2-BUSCAR VENDEDOR."<<endl;
                        cout<<"------------------"<<endl;
                        buscarVendedor();
                        system ("pause");
                        break;
                        }

                        case 3:{
                        int modificar;
                        cout<<"3-MODIFICAR VENDEDOR."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuModificarVendedores();
                        cin>>modificar;
                        switch (modificar)
                        {


                            case 1:{
                                cout<<"1-MODIFICAR SUELDO."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarSueldoVendedor();
                                system("pause");
                                break;
                                }


                            case 2:{
                                cout<<"2-MODIFICAR VENTAS REALIZADAS."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarVentasVendedor();
                                system("pause");
                                break;
                                }

                            case 3:{
                                cout<<"3-MODIFICAR NOMBRE."<<endl;///MODIFICAR NOMBRE
                                cout<<"---------------------"<<endl;
                                modificarNombreVendedor();
                                system("pause");
                                break;
                                }

                            case 4:{
                                cout<<"4-MODIFICAR ANTIGUEDAD."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarAntiguedadVendedor();
                                system("pause");
                                break;
                                }

                            case 5:{
                                cout<<"5-MODIFICAR EDAD."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarEdadVendedor();
                                system("pause");
                                break;
                                }

                            case 6:{
                                cout<<"6-MODIFICAR DOMICILIO."<<endl;
                                cout<<"---------------------"<<endl;
                                modificarDomicilioVendedor();
                                system("pause");
                                break;
                                }


                            default:{

                                break;
                                }
                            }
                            break;
                        }

                    case 4:

                        int listar;
                        cout<<"4-LISTAR VENDEDORES."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuListarVendedores();
                        cin>>listar;
                        switch (listar)
                        {
                            case 1:
                            cout<<"1-LISTAR DE MAYOR A MENOR VENTAS."<<endl;
                            cout<<"----------------------------"<<endl;
                            system("cls");
                            listarDeMayorAMenorVentasVendedor();
                            system ("pause");
                            break;


                            case 2:
                            cout<<"2-LISTAR DE MENOR A MAYOR VENTAS."<<endl;
                            cout<<"--------------------"<<endl;
                            system("cls");
                            listarDeMenorAMayorVentasVendedor();
                            system ("pause");
                            break;


                            case 3:
                            cout<<"3-ORDENAR POR ANTIGUEDAD DE MENOR A MAYOR."<<endl;
                            cout<<"--------------------"<<endl;
                            system("cls");
                            listaAntiguedadMenorAMayorVendedor();
                            system ("pause");
                            break;


                            case 4:
                            cout<<"4-ORDENAR POR ANTIGUEDAD DE MAYOR A MENOR."<<endl;
                            cout<<"--------------------"<<endl;
                            system("cls");
                            listaAntiguedadMayorAMenorVendedor();
                            system ("pause");
                            break;

                            case 5:
                            cout<<"5-LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
                            cout<<"--------------------"<<endl;
                            system("cls");
                            listarVendedores();
                            system ("pause");
                            break;

                            default:
                                break;
                            }
                    break;

                    case 5:
                        int baja;
                        cout<<"5-BAJA VENDEDORES."<<endl;
                        cout<<"---------------------"<<endl;
                        system ("cls");
                        mostrarSubMenuBajaVendedores();
                        cin>>baja;
                        switch (baja)
                        {

                            case 1:
                                cout<<"1-BAJA LOGICA."<<endl;
                                cout<<"---------------------"<<endl;
                                borrarLogicoVendedor();
                                break;

                            case 2:
                            system("cls");
                                cout<<"2-BAJA FISICA."<<endl;
                                cout<<"---------------------"<<endl;
                                borrarFisicoVendedor();
                                break;

                            default:
                                break;

                        }
                        //system ("pause");
                        break;

                    case 0:
                        cout << "0 - SALIDA DEL MENU DE CONFIGURACIONES" << endl << endl;
                        cout << "Usted ha decidido salir del Menu de Configuraciones." << endl << endl;
                        system ("pause");
                        break;

                    default:
                        cout << "ERROR" << endl << endl;
                        cout << "Algo salio mal, intente nuevamente" << endl << endl;
                        system ("pause");
                        break;
                }
                cout << endl << "Fin Switch Configuraciones" << endl << endl;
            }
            cout << endl << "Fin While Configuraciones" << endl << endl;
            break;
        }

        ///CASE 0 - SALIDA DEL PROGRAMA
        case 0: {
            cout<<endl<<"Usted ha decidido salir del programa."<<endl<<endl;
            system ("pause");
            break;
        }

        ///DEFAULT - ERROR
        default:
            cout<<endl<<"Algo salio mal. El programa ha finalizado incorrectamente."<<endl;
            system ("pause");
            return -1;
        }
    }

    cout<<endl<<"El programa ha finalizado correctamente."<<endl<<endl;
    system ("pause");
    return 0;
}
