#ifndef FUNCIONESCONTACTO_H_INCLUDED
#define FUNCIONESCONTACTO_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ARCHIVOCONTACTO_H_INCLUDED
    #include "../clsArchivo/ArchivoContacto.h"
    #define ARCHIVOCONTACTO_H_INCLUDED
#endif

// ============================================
// FUNCIONES AUXILIARES
// ============================================

// Obtener el proximo ID disponible para un nuevo contacto
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

// Contar cuantos contactos activos tiene una entidad
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

// Eliminar todos los contactos de una entidad (borrado logico)
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

// ============================================
// FUNCIONES PRINCIPALES
// ============================================

// Listar todos los contactos activos de una entidad
void listarContactosPorEntidad(int idEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << endl;
    cout << setfill('-') << setw(93) << "-" << setfill(' ') << endl;

    bool hayContactos = false;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            cout << left << setw(8) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono()
                 << setw(35) << regContacto.getEmail() << endl;
            hayContactos = true;
        }
    }

    if (!hayContactos) {
        cout << "NO HAY CONTACTOS REGISTRADOS PARA ESTA ENTIDAD" << endl;
    }

    fclose(p);
    cout << endl;
}

// Agregar un nuevo contacto a una entidad
void agregarContacto(int idEntidad) {
    ArchivoContacto archivoContacto;
    Contacto nuevoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "       AGREGAR NUEVO CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Obtener el proximo ID
    int nuevoId = obtenerProximoIdContacto();
    nuevoContacto.setIdContacto(nuevoId);
    nuevoContacto.setIdEntidad(idEntidad);

    // Cargar datos del contacto
    nuevoContacto.Cargar();

    // Guardar en archivo
    if (archivoContacto.escribirArchivo(nuevoContacto)) {
        cout << endl;
        cout << "CONTACTO AGREGADO EXITOSAMENTE CON ID: " << nuevoId << endl;
    } else {
        cout << "ERROR AL GUARDAR EL CONTACTO" << endl;
    }
}

// Modificar un contacto existente
void modificarContacto(int idEntidad) {
    ArchivoContacto archivoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "        MODIFICAR CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Listar contactos de la entidad
    listarContactosPorEntidad(idEntidad);

    int cantidadContactos = contarContactosPorEntidad(idEntidad);
    if (cantidadContactos == 0) {
        return;
    }

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
    cout << endl;
    cout << "DATOS ACTUALES:" << endl;
    regContacto.Mostrar();
    cout << endl;

    // Modificar datos
    cout << "INGRESE LOS NUEVOS DATOS:" << endl;
    regContacto.Cargar();

    // Guardar cambios
    if (archivoContacto.modificarArchivo(pos, regContacto)) {
        cout << endl;
        cout << "CONTACTO MODIFICADO EXITOSAMENTE" << endl;
    } else {
        cout << "ERROR AL MODIFICAR EL CONTACTO" << endl;
    }
}

// Eliminar un contacto (borrado logico)
void eliminarContacto(int idEntidad) {
    ArchivoContacto archivoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "         ELIMINAR CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Listar contactos de la entidad
    listarContactosPorEntidad(idEntidad);

    int cantidadContactos = contarContactosPorEntidad(idEntidad);
    if (cantidadContactos == 0) {
        return;
    }

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

    // Confirmar eliminacion
    cout << endl;
    regContacto.Mostrar();
    cout << endl;
    cout << "ESTA SEGURO QUE DESEA ELIMINAR ESTE CONTACTO? (1-SI, 0-NO): ";
    int confirmacion;
    cin >> confirmacion;

    if (confirmacion == 1) {
        regContacto.setEstado(false);
        if (archivoContacto.modificarArchivo(pos, regContacto)) {
            cout << endl;
            cout << "CONTACTO ELIMINADO EXITOSAMENTE" << endl;
        } else {
            cout << "ERROR AL ELIMINAR EL CONTACTO" << endl;
        }
    } else {
        cout << "OPERACION CANCELADA" << endl;
    }
}

// Buscar contacto por nombre dentro de una entidad
void buscarContactoPorNombre(int idEntidad) {
    ArchivoContacto archivoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "     BUSCAR CONTACTO POR NOMBRE" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    char nombreBuscar[30];
    cout << "INGRESE EL NOMBRE A BUSCAR: ";
    cargarCadena(nombreBuscar, 30);

    // Convertir a minusculas para busqueda case-insensitive
    char nombreMinusc[30];
    strcpy(nombreMinusc, nombreBuscar);
    convertirMinuscula(nombreMinusc);

    FILE *p = fopen("../../data/contactos.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << endl;
    cout << setfill('-') << setw(93) << "-" << setfill(' ') << endl;

    Contacto regContacto;
    bool encontrado = false;

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            char nombreContacto[30];
            strcpy(nombreContacto, regContacto.getNombreContacto());
            convertirMinuscula(nombreContacto);

            // Buscar si el nombre buscado esta contenido en el nombre del contacto
            if (strstr(nombreContacto, nombreMinusc) != nullptr) {
                cout << left << setw(8) << regContacto.getIdContacto()
                     << setw(30) << regContacto.getNombreContacto()
                     << setw(20) << regContacto.getNroTelefono()
                     << setw(35) << regContacto.getEmail() << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "NO SE ENCONTRARON CONTACTOS CON ESE NOMBRE" << endl;
    }

    fclose(p);
    cout << endl;
}

// Menu principal de gestion de contactos
void menuContactos(int idEntidad, const char* nombreEntidad) {
    int opcion;

    do {
        system("cls");
        cout << "========================================" << endl;
        cout << "       GESTION DE CONTACTOS" << endl;
        cout << "  ENTIDAD: " << nombreEntidad << " (ID: " << idEntidad << ")" << endl;
        cout << "========================================" << endl;
        cout << "1. AGREGAR NUEVO CONTACTO" << endl;
        cout << "2. LISTAR TODOS LOS CONTACTOS" << endl;
        cout << "3. MODIFICAR CONTACTO" << endl;
        cout << "4. ELIMINAR CONTACTO" << endl;
        cout << "5. BUSCAR CONTACTO POR NOMBRE" << endl;
        cout << "6. VER CANTIDAD DE CONTACTOS" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "========================================" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarContacto(idEntidad);
                system("pause");
                break;
            case 2:
                listarContactosPorEntidad(idEntidad);
                system("pause");
                break;
            case 3:
                modificarContacto(idEntidad);
                system("pause");
                break;
            case 4:
                eliminarContacto(idEntidad);
                system("pause");
                break;
            case 5:
                buscarContactoPorNombre(idEntidad);
                system("pause");
                break;
            case 6:
                cout << endl;
                cout << "CANTIDAD DE CONTACTOS ACTIVOS: " << contarContactosPorEntidad(idEntidad) << endl;
                cout << endl;
                system("pause");
                break;
            case 0:
                cout << "VOLVIENDO AL MENU ANTERIOR..." << endl;
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
                system("pause");
                break;
        }
    } while (opcion != 0);
}

#endif // FUNCIONESCONTACTO_H_INCLUDED
