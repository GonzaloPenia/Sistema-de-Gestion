#ifndef FUNCIONESCONTACTO_H_INCLUDED
#define FUNCIONESCONTACTO_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ARCHIVOCONTACTO_H_INCLUDED
    #include "../clsArchivo/ArchivoContacto.h"
    #define ARCHIVOCONTACTO_H_INCLUDED
#endif

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

// Cuenta cuantos contactos activos tiene una entidad
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

// Listar todos los contactos activos de una entidad
void listarContactosPorEntidad() {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    int idEntidad;

    cout << "DE QUE ENTIDAD QUERRIA VER LOS CONTACTOS? ";
    cin >> idEntidad;
    

    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << setw(15) << "ENTIDAD" <<endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;

    bool hayContactos = false;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad && regContacto.getEstado()) {
            cout << left << setw(8) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono()
                 << setw(35) << regContacto.getEmail()
                 << setw(20) << regContacto.getIdEntidad() << endl;
            hayContactos = true;
        }
    }

    if (!hayContactos) {
        cout << "NO HAY CONTACTOS REGISTRADOS PARA ESTA ENTIDAD" << endl;
    }

    fclose(p);
    cout << endl;
}

void listarContactosPorEntidad(int idEntidad) {
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

    /*PRIMERO OBJETO CLIENTE = MAURISIO
    INT CONTACTO AUX
    CONTACTO AUX = MAURISIO.GETID()
    CONTACTO AUX BUSCAR EN CONTACTOS.DAT TODOS LOS CONTACTOS ASOCIADOS A ESTE ID   
    
    
    
    */

}

// Agregar un nuevo contacto a una entidad ya existente
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

// Agregar un nuevo contacto a una entidad durante su creacion
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

// Modificar un contacto existente
void modificarContacto(int idEntidad) {
    ArchivoContacto archivoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "        MODIFICAR CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    // Listar contactos de la entidad
    listarContactosPorEntidad();

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
    listarContactosPorEntidad();

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

// Buscar contacto por ID
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
