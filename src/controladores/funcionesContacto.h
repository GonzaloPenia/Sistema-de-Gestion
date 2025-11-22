#ifndef FUNCIONESCONTACTO_H_INCLUDED
#define FUNCIONESCONTACTO_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ARCHIVOCONTACTO_H_INCLUDED
    #include "../clsArchivo/ArchivoContacto.h"
    #define ARCHIVOCONTACTO_H_INCLUDED
#endif

void listarClientesResumido();
void listarProveedoresResumido();

void listarContactosResumido(int idEntidad);
void listarContactosPorEntidadAux(int idEntidad);

int obtenerProximoIdContacto() {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        return 1; // Si el archivo no existe, el primer ID es 1
    }

    int maxId = 0;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdContacto() > maxId) {
            maxId = regContacto.getIdContacto();
        }
    }
    fclose(p);
    return maxId + 1;
}

int contarContactosPorEntidad(int idEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        return 0;
    }

    int contador = 0;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            contador++;
        }
    }
    fclose(p);
    return contador;
}

void listarContactosResumido(int idEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    cout << "CONTACTOS DISPONIBLES:" << endl;
    cout << left << setw(10) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    bool hayContactos = false;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            cout << left << setw(10) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono() << endl;
            hayContactos = true;
        }
    }

    if (!hayContactos) {
        cout << "NO HAY CONTACTOS REGISTRADOS PARA ESTA ENTIDAD" << endl;
    }

    fclose(p);
    cout << endl;
}

void eliminarContactosDeEntidad(int idEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb+");

    if (p == NULL) {
        cout << "ERROR AL ACCEDER AL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    int pos = 0;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            regContacto.setEstado(false);
            fseek(p, sizeof(Contacto) * pos, SEEK_SET);
            fwrite(&regContacto, sizeof(regContacto), 1, p);
            fseek(p, 0, SEEK_CUR); // Reposicionar para continuar leyendo
        }
        pos++;
    }
    fclose(p);
}

void listarContactosPorEntidad() {
    system("cls");

    cout << "=======================================" << endl;
    cout << "    VER CONTACTOS DE UNA ENTIDAD" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    cout << "SELECCIONE EL TIPO DE ENTIDAD:" << endl;
    cout << "1 - CLIENTE" << endl;
    cout << "2 - PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    system("cls");

    int idEntidad;

    switch(opcion) {
        case 1: // CLIENTE
            cout << "=======================================" << endl;
            cout << "     CONTACTOS DE CLIENTE" << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarClientesResumido();

            cout << "INGRESE EL ID DEL CLIENTE: ";
            cin >> idEntidad;

            cout << endl;
            cout << "CONTACTOS DEL CLIENTE ID " << idEntidad << ":" << endl;
            cout << "---------------------------------------" << endl;
            listarContactosPorEntidadAux(idEntidad);
            break;

        case 2: // PROVEEDOR
            cout << "=======================================" << endl;
            cout << "     CONTACTOS DE PROVEEDOR" << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarProveedoresResumido();

            cout << "INGRESE EL ID DEL PROVEEDOR: ";
            cin >> idEntidad;

            cout << endl;
            cout << "CONTACTOS DEL PROVEEDOR ID " << idEntidad << ":" << endl;
            cout << "---------------------------------------" << endl;
            listarContactosPorEntidadAux(idEntidad);
            break;

        default:
            cout << "OPCION INVALIDA" << endl;
            break;
    }

    cout << endl;
}

void listarContactosPorEntidadAux(int idEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;

    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << setw(15) <<endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;

    bool hayContactos = false;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            cout << left << setw(8) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono()
                 << setw(35) << regContacto.getEmail()
                 << endl;
            hayContactos = true;
        }
    }

    if (!hayContactos) {
        cout << "NO HAY CONTACTOS REGISTRADOS PARA ESTA ENTIDAD" << endl;
    }

    fclose(p);
    cout << endl;
}

void listarContactos(){
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }
    
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getEstado()) {
            regContacto.Mostrar();           
        }
    }

}

void agregarContacto() {
    ArchivoContacto archivoContacto;
    Contacto nuevoContacto;
    int IdEntidad;

    IdEntidad = nuevoContacto.Asociar();    
    nuevoContacto.setIdEntidad(IdEntidad);

    cout << endl;
    cout << "=======================================" << endl;
    cout << "       AGREGAR NUEVO CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Obtener el proximo ID
    int nuevoId = obtenerProximoIdContacto();
    nuevoContacto.setIdContacto(nuevoId);

    // Cargar datos del contacto
    nuevoContacto.Cargar();

    // Guardar en archivo
    if (archivoContacto.escribirArchivo(nuevoContacto)) {
        cout << endl;
        cout << "CONTACTO AGREGADO EXITOSAMENTE CON ID: " << nuevoId << endl;
        cout << "CONTACTO AGREGADO EXITOSAMENTE A LA ENTIDAD: " << IdEntidad << endl;
        
    } else {
        cout << "ERROR AL GUARDAR EL CONTACTO" << endl;
    }
}

void agregarContacto(int IdEntidad) {
    ArchivoContacto archivoContacto;
    Contacto Contacto;
        
    Contacto.setIdEntidad(IdEntidad);

    cout << endl;
    cout << "=======================================" << endl;
    cout << "       AGREGAR UN CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    int nuevoId = obtenerProximoIdContacto();
    Contacto.setIdContacto(nuevoId);

    Contacto.Cargar();

    if (archivoContacto.escribirArchivo(Contacto)) {
        cout << endl;
        cout << "EL CONTACTO " << Contacto.getIdContacto() << " SE AGREGÓ EXITOSAMENTE" << endl;
        
    } else {
        cout << "ERROR AL GUARDAR EL CONTACTO" << endl;
    }
}

void modificarContacto() {
    system("cls");

    cout << "=======================================" << endl;
    cout << "        MODIFICAR CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    cout << "SELECCIONE EL TIPO DE ENTIDAD:" << endl;
    cout << "1 - CONTACTOS DE CLIENTE" << endl;
    cout << "2 - CONTACTOS DE PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    system("cls");

    int idEntidad;
    ArchivoContacto archivoContacto;

    switch(opcion) {
        case 1: // CLIENTE
            cout << "=======================================" << endl;
            cout << "  MODIFICAR CONTACTO DE CLIENTE" << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarClientesResumido();

            cout << "INGRESE EL ID DEL CLIENTE: ";
            cin >> idEntidad;

            system("cls");
            cout << "=======================================" << endl;
            cout << "  CONTACTOS DEL CLIENTE ID " << idEntidad << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarContactosResumido(idEntidad);

            if (contarContactosPorEntidad(idEntidad) == 0) {
                return;
            }
            break;

        case 2: // PROVEEDOR
            cout << "=======================================" << endl;
            cout << "  MODIFICAR CONTACTO DE PROVEEDOR" << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarProveedoresResumido();

            cout << "INGRESE EL ID DEL PROVEEDOR: ";
            cin >> idEntidad;

            system("cls");
            cout << "=======================================" << endl;
            cout << "  CONTACTOS DEL PROVEEDOR ID " << idEntidad << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarContactosResumido(idEntidad);

            if (contarContactosPorEntidad(idEntidad) == 0) {
                return;
            }
            break;

        default:
            cout << "OPCION INVALIDA" << endl;
            return;
    }

    // Solicitar ID del contacto a modificar
    int idContacto;
    cout << "INGRESE EL ID DEL CONTACTO A MODIFICAR: ";
    cin >> idContacto;

    // Buscar el contacto en el archivo
    FILE *p = fopen("../../data/contactos.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }

    Contacto regContacto;
    int pos = 0;
    bool encontrado = false;

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdContacto() == idContacto &&
            regContacto.getIdEntidad() == idEntidad &&
            regContacto.getEstado()) {
            encontrado = true;
            break;
        }
        pos++;
    }
    fclose(p);

    if (!encontrado) {
        cout << "NO SE ENCONTRO EL CONTACTO O NO PERTENECE A ESTA ENTIDAD" << endl;
        return;
    }

    // Mostrar datos actuales
    system("cls");
    cout << endl;
    cout << "DATOS ACTUALES DEL CONTACTO:" << endl;
    regContacto.Mostrar();
    cout << endl;

    // Menu de modificacion
    cout << "QUE DESEA MODIFICAR?" << endl;
    cout << "1 - NOMBRE" << endl;
    cout << "2 - TELEFONO" << endl;
    cout << "3 - AMBOS" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int opcionMod;
    cin >> opcionMod;

    if (opcionMod == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    cout << endl;

    switch(opcionMod) {
        case 1: // Solo nombre
            cout << "INGRESE EL NUEVO NOMBRE: ";
            char nuevoNombre[30];
            cargarCadena(nuevoNombre, 30);
            regContacto.setNombreContacto(nuevoNombre);
            break;

        case 2: // Solo telefono
            cout << "INGRESE EL NUEVO TELEFONO: ";
            char nuevoTelefono[20];
            cargarCadena(nuevoTelefono, 20);
            regContacto.setNroTelefono(nuevoTelefono);
            break;

        case 3: // Ambos
            cout << "INGRESE EL NUEVO NOMBRE: ";
            char nombre[30];
            cargarCadena(nombre, 30);
            regContacto.setNombreContacto(nombre);

            cout << "INGRESE EL NUEVO TELEFONO: ";
            char telefono[20];
            cargarCadena(telefono, 20);
            regContacto.setNroTelefono(telefono);
            break;

        default:
            cout << "OPCION INVALIDA" << endl;
            return;
    }

    // Guardar cambios
    if (archivoContacto.modificarArchivo(pos, regContacto)) {
        cout << endl;
        cout << "CONTACTO MODIFICADO EXITOSAMENTE" << endl;
        cout << endl;
        cout << "DATOS ACTUALIZADOS:" << endl;
        regContacto.Mostrar();
    } else {
        cout << "ERROR AL MODIFICAR EL CONTACTO" << endl;
    }

    cout << endl;
}

// Eliminar un contacto (con menu de seleccion)
void eliminarContacto() {
    system("cls");

    cout << "=======================================" << endl;
    cout << "         ELIMINAR CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    cout << "SELECCIONE EL TIPO DE ENTIDAD:" << endl;
    cout << "1 - CONTACTOS DE CLIENTE" << endl;
    cout << "2 - CONTACTOS DE PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    system("cls");

    int idEntidad;
    ArchivoContacto archivoContacto;

    switch(opcion) {
        case 1: // CLIENTE
            cout << "=======================================" << endl;
            cout << "   ELIMINAR CONTACTO DE CLIENTE" << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarClientesResumido();

            cout << "INGRESE EL ID DEL CLIENTE: ";
            cin >> idEntidad;

            system("cls");
            cout << "=======================================" << endl;
            cout << "  CONTACTOS DEL CLIENTE ID " << idEntidad << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarContactosResumido(idEntidad);

            if (contarContactosPorEntidad(idEntidad) == 0) {
                return;
            }
            break;

        case 2: // PROVEEDOR
            cout << "=======================================" << endl;
            cout << "  ELIMINAR CONTACTO DE PROVEEDOR" << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarProveedoresResumido();

            cout << "INGRESE EL ID DEL PROVEEDOR: ";
            cin >> idEntidad;

            system("cls");
            cout << "=======================================" << endl;
            cout << "  CONTACTOS DEL PROVEEDOR ID " << idEntidad << endl;
            cout << "=======================================" << endl;
            cout << endl;

            listarContactosResumido(idEntidad);

            if (contarContactosPorEntidad(idEntidad) == 0) {
                return;
            }
            break;

        default:
            cout << "OPCION INVALIDA" << endl;
            return;
    }

    // Solicitar ID del contacto a eliminar
    int idContacto;
    cout << "INGRESE EL ID DEL CONTACTO A ELIMINAR: ";
    cin >> idContacto;

    // Buscar el contacto en el archivo
    FILE *p = fopen("../../data/contactos.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }

    Contacto regContacto;
    int pos = 0;
    bool encontrado = false;

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdContacto() == idContacto &&
            regContacto.getIdEntidad() == idEntidad &&
            regContacto.getEstado()) {
            encontrado = true;
            break;
        }
        pos++;
    }
    fclose(p);

    if (!encontrado) {
        cout << "NO SE ENCONTRO EL CONTACTO O NO PERTENECE A ESTA ENTIDAD" << endl;
        return;
    }

    // Mostrar datos del contacto y confirmar eliminacion
    system("cls");
    cout << endl;
    cout << "ATENCION: VA A ELIMINAR EL SIGUIENTE CONTACTO:" << endl;
    regContacto.Mostrar();
    cout << endl;
    cout << "=======================================" << endl;
    cout << "ESTA SEGURO QUE DESEA ELIMINAR ESTE CONTACTO?" << endl;
    cout << "1 - SI, ELIMINAR" << endl;
    cout << "0 - NO, CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int confirmacion;
    cin >> confirmacion;

    if (confirmacion == 1) {
        regContacto.setEstado(false);
        if (archivoContacto.modificarArchivo(pos, regContacto)) {
            cout << endl;
            cout << "=======================================" << endl;
            cout << "  CONTACTO ELIMINADO EXITOSAMENTE" << endl;
            cout << "=======================================" << endl;
        } else {
            cout << endl;
            cout << "ERROR AL ELIMINAR EL CONTACTO" << endl;
        }
    } else {
        cout << endl;
        cout << "OPERACION CANCELADA - EL CONTACTO NO FUE ELIMINADO" << endl;
    }

    cout << endl;
}

void buscarContactoPorID() {
    ArchivoContacto archivoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "      BUSCAR CONTACTO POR ID" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    int idContactoBuscar;
    cout << "INGRESE EL ID DEL CONTACTO A BUSCAR: ";
    cin >> idContactoBuscar;

    FILE *p = fopen("../../data/contactos.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << setw(15)  << "ENTIDAD" << endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;

    Contacto regContacto;
    bool encontrado = false;

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdContacto() == idContactoBuscar &&
            regContacto.getEstado()) {
            cout << left << setw(8) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono()
                 << setw(35) << regContacto.getEmail()
                 << setw(15) << regContacto.getIdEntidad() << endl;
            encontrado = true;
            break; // Salir del bucle porque el ID es unico
        }
    }

    if (!encontrado) {
        cout << "NO SE ENCONTRO EL CONTACTO CON ID: " << idContactoBuscar << endl;
    }

    fclose(p);
    cout << endl;
}



#endif // FUNCIONESCONTACTO_H_INCLUDED
