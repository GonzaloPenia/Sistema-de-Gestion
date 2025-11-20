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
#include "clases/Direccion.h"
#include "clases/Fecha.h"
#include "clases/Vendedor.h"
#include "clsArchivo/ArchivoVendedor.h"
#include "controladores/funcionesVendedor.h"
#include "clases/Contacto.h"
#include "clases/Entidad.h"
#include "clases/Cliente.h"
#include "clases/Proveedor.h"
#include "clsArchivo/ArchivoProveedor.h"
#include "clsArchivo/ArchivoCliente.h"
#include "controladores/funcionesCliente.h"
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
                                    case 1: 
                                        gestionCarrito();
                                        system ("pause");
                                        break;
                                    
                                    //LISTADO DE FACTURAS
                                    case 2: 
                                        listadoDeFacturas();
                                        system ("pause");
                                        break;
                                    
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
                                //CARGAR CLIENTE
                                case 1: {
                                    cargarCliente();
                                    system ("pause");
                                    break;
                                }
                                //BUSCAR CLIENTE
                                case 2:{
                                    buscarCliente();
                                    system ("pause");
                                    break;
                                    }
                                //MODIFICAR CLIENTE
                                case 3:{
                                    int modificar;
                                    system ("cls");
                                    mostrarSubMenuModificarCliente();
                                    cin>>modificar;
                                    switch (modificar){
                                            case 1:
                                                modificarTipo();
                                                system ("pause");
                                                break;
                                                
                                            case 2:
                                                modificarDireccionYContacto();
                                                system("pause");
                                                break;
                                                
                                            case 3:
                                                modificarCantidadVentas();
                                                system("pause");
                                                break;
                                                
                                            case 4:
                                                modificarNombreCliente();
                                                system("pause");
                                                break;
                                                
                                            default:{

                                                break;
                                                }
                                            }
                                            break;
                                    }
                                //TODAS LAS LISTAS DE CLIENTES
                                case 4:
                                    int listar;
                                    cout<<"4-LISTAR CLIENTES."<<endl;
                                    cout<<"---------------------"<<endl;
                                    system ("cls");
                                    mostrarSubMenuListarClientes();
                                    cin>>listar;
                                    switch (listar){
                                            case 1:
                                            listarDeMayorAMenorVentas();
                                            system ("pause");
                                            break;


                                            case 2:
                                            listarDeMenorAMayorVentas();
                                            system ("pause");
                                            break;


                                            case 3:
                                            listaIdMenorAMayorCliente();
                                            system ("pause");
                                            break;

                                            case 4:
                                            listaIdMayorAMenorCliente();
                                            system ("pause");
                                            break;

                                            case 5:
                                            listaCuitMenorAMayorCliente();
                                            system ("pause");
                                            break;

                                            case 6:
                                            listaCuitMayorAMenorCliente();
                                            system ("pause");
                                            break;

                                            case 7:
                                            listaAlfabeticamenteCliente();
                                            system ("pause");
                                            break;

                                            case 8:
                                            listarClientes();
                                            system ("pause");
                                            break;

                                            case 9:
                                            listarRecaudacion();
                                            system ("pause");
                                            break;

                                            default:
                                                break;
                                            }
                                break;
                                
                                //DAR DE BAJA CLIENTES
                                case 5:
                                    int baja;
                                    mostrarSubMenuBajaClientes();
                                    cin>>baja;
                                    switch (baja){
                                            case 1:
                                                borrarLogicoCliente();
                                                system("pause");
                                                break;

                                            case 2:
                                                borrarFisicoCliente();
                                                system("pause");
                                                break;

                                            default:
                                                break;
                                    }
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
                    //Fin Switch Clientes
                    }
                    //"Fin While Clientes"
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
                                            modificarDescripcion();
                                            system("pause");
                                            break;


                                        case 2:
                                            modificarProveedor();
                                            system("pause");
                                            break;


                                        case 3:
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
                                    mostrarSubMenuListarArticulos();
                                    cin>>listar;
                                    switch (listar)
                                    {
                                    case 1:
                                    listarArticuloPorPrecioDeMayorAMenor();
                                    system ("pause");
                                    break;


                                    case 2:
                                    listarArticuloPorPrecioDeMenorAMayor();
                                    system ("pause");
                                    break;


                                    case 3:
                                    listaArticuloPorIdDeMayorAMenor();
                                    system ("pause");
                                    break;


                                    case 4:
                                    listaArticuloPorIdDeMenorAMayor();
                                    system ("pause");
                                    break;

                                    case 5:
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
                                    mostrarSubMenuBajaArticulos();
                                    cin>>baja;
                                    switch (baja)
                                    {

                                        case 1:
                                            borrarLogico();
                                            break;

                                        case 2:
                                            borrarFisico();
                                            break;

                                        default:
                                            break;

                                    }
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
                                //"Fin Switch Articulos"
                    }
                    //"Fin While Articulos"
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
                                //LISTAR PROVEEDORES
                                case 1: {
                                    cargarProveedor();
                                    system ("pause");
                                    break;
                                }

                                //BUSCAR PROVEEDOR
                                case 2: {
                                    system ("cls");
                                    buscarProveedor();
                                    system ("pause");
                                    break;
                                }
                                
                                //MODIFICAR PROVEEDOR
                                case 3: {
                                    system ("cls");
                                    int modificar;
                                    mostrarSubMenuModificarProveedores();
                                    cin>>modificar;
                                    switch (modificar){
                                            case 1 :
                                                modificarNombreProveedor();
                                                system ("pause");
                                                break;

                                            case 2 :
                                                modificarDireccionProveedor();
                                                cout << "ESTA FUNCION FUE REEMPLAZADA" << endl;
                                                system ("pause");
                                                break;

                                            default:
                                                break;
                                            }
                                    break;
                                }
                                
                                //LISTAR PROVEEDORES
                                case 4:{
                                    system ("cls");
                                    int listar;
                                    mostrarSubMenuListarProveedores();
                                    cin>>listar;
                                    switch (listar){
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

                                //ELIMINAR PROVEEDORES
                                case 5:{
                                    int borrar;
                                    mostrarSubMenuBajaProveedores();
                                    cin>>borrar;
                                    switch (borrar){
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

                                //SALIR PROVEEDORES
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
                            //"Fin Switch Proveedores"
                    }
                    //"Fin While Proveedores"
                    break;
                }

                ///CASE 5 - CONTACTOS
                case 5:{
                    int contacto;
                    system ("cls");
                    mostrarMenuContactos();
                    cin>>contacto;
                    system ("cls");
                    switch (contacto){
                            //AGREGAR CONTACTO;
                            case 1:
                                agregarContacto();                    
                                system ("pause");
                                break;
                            
                            //BUSCAR CONTACTO
                            case 2:
                                buscarContactoPorID();
                                system ("pause");
                                break;
                            //MODIFICAR CONTACTO
                            case 3:
                                system ("pause");
                                break;
                            
                            //LISTAR CONTACTO
                            case 4:
                                subMenuListarContactos();
                                int ListaContactos;
                                cin >> ListaContactos;
                                switch(ListaContactos){
                                        //LISTADO DE CONTACTOS
                                        case 1:{
                                            listarContactos();
                                            break;
                                        }
                                        
                                        //LISTAR POR ENTIDAD
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
                            //AGREGAR VENDEDOR
                            case 1: {
                                cout<<"1 - AGREGAR VENDEDOR."<<endl;
                                cout<<"---------------------"<<endl;
                                cargarVendedor();
                                system ("pause");
                                break;
                            }
                            //BUSCAR VENDEDOR
                            case 2:{
                                cout<<"2-BUSCAR VENDEDOR."<<endl;
                                cout<<"------------------"<<endl;
                                buscarVendedor();
                                system ("pause");
                                break;
                                }
                            
                            //MODIFICACIONES VENDEDOR
                            case 3:
                            int modificar;
                            cout<<"3-MODIFICAR VENDEDOR."<<endl;
                            cout<<"---------------------"<<endl;
                            system ("cls");
                            mostrarSubMenuModificarVendedores();
                            cin>>modificar;
                            switch (modificar){
                                //MODIFICAR SULEDO
                                case 1:
                                    modificarSueldoVendedor();
                                    system("pause");
                                    break;
                                    
                                //MODIFICAR VENTAS
                                case 2:
                                    modificarVentasVendedor();
                                    system("pause");
                                    break;
                                    
                                //MODIFICAR NOMBRE
                                case 3:
                                    modificarNombreVendedor();
                                    system("pause");
                                    break;
                                    
                                //MODIFICAR ANTIGUEDAD
                                case 4:
                                    modificarAntiguedadVendedor();
                                    system("pause");
                                    break;
                                    
                                //MODIFICAR EDAD
                                case 5:
                                    modificarEdadVendedor();
                                    system("pause");
                                    break;
                                    
                                //MODIFICAR DOMICILIO
                                case 6:
                                    modificarDomicilioVendedor();
                                    system("pause");
                                    break;
                                    
                                default:
                                    break;
                                    
                                }
                                break;
                            
                            //LISTADO DE VENDEDORES
                            case 4:

                                int listar;
                                system ("cls");
                                mostrarSubMenuListarVendedores();
                                cin>>listar;
                                switch (listar)
                                {
                                    case 1:
                                    listarDeMayorAMenorVentasVendedor();
                                    system ("pause");
                                    break;


                                    case 2:
                                    listarDeMenorAMayorVentasVendedor();
                                    system ("pause");
                                    break;


                                    case 3:
                                    listaAntiguedadMenorAMayorVendedor();
                                    system ("pause");
                                    break;


                                    case 4:
                                    listaAntiguedadMayorAMenorVendedor();
                                    system ("pause");
                                    break;

                                    case 5:
                                    listarVendedores();
                                    system ("pause");
                                    break;

                                    default:
                                        break;
                                    }
                            break;
                            
                            //BAJA DE VENDEDORES
                            case 5:
                                int baja;
                                system ("cls");
                                mostrarSubMenuBajaVendedores();
                                cin>>baja;
                                switch (baja)
                                {

                                    case 1:
                                        borrarLogicoVendedor();
                                        break;

                                    case 2:
                                    
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
