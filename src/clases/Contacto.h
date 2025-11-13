#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED

#include <cstring>
#include <iostream>
using namespace std;

#ifndef FUNCIONESGLOBALES_H_INCLUDED
    #include "../globales/funcionesGlobales.h"
#endif

//CONTACTO - Sistema relacional con Clientes y Proveedores
class Contacto{

    private:
        int _idContacto;           // ID unico del contacto
        int _idEntidad;            // ID del cliente o proveedor al que pertenece
        char _nombreContacto[30];
        char _nroTelefono[20];
        char _email[40];
        bool _estado;              // true = activo, false = eliminado (borrado logico)

    public:

        //CONSTRUCTOR --> Se construye sin datos
        Contacto(){
            _idContacto = 0;
            _idEntidad = 0;
            strcpy(_nombreContacto,"Sin Datos");
            strcpy(_nroTelefono,"Sin Datos");
            strcpy(_email,"Sin Datos");
            _estado = false;
        }

        //SETTERS Y GETTERS

        void setIdContacto(int idContacto) { _idContacto = idContacto; }
        void setIdEntidad(int idEntidad) { _idEntidad = idEntidad; }
        void setNombreContacto(const char* nombreContacto) { strcpy(_nombreContacto, nombreContacto); }
        void setNroTelefono(const char* nroTelefono) { strcpy(_nroTelefono, nroTelefono); }
        void setEmail(const char* email) { strcpy(_email, email); }
        void setEstado(bool estado) { _estado = estado; }

        int getIdContacto() { return _idContacto; }
        int getIdEntidad() { return _idEntidad; }
        const char* getNombreContacto() { return _nombreContacto; }
        const char* getNroTelefono() { return _nroTelefono; }
        const char* getEmail() { return _email; }
        bool getEstado() { return _estado; }

        //CARGAR Y MOSTRAR

        void Cargar();

        void Mostrar();

        int Asociar();

};

void Contacto::Cargar(){
    cout << "Ingrese el nombre del contacto: ";
    cargarCadena(_nombreContacto, 30);
    cout << "Ingrese el numero de telefono del contacto: ";
    cargarCadena(_nroTelefono, 20);
    cout << "Ingrese el email del contacto: ";
    cargarCadena(_email, 40);
    _estado = true;
}

void Contacto::Mostrar(){
    cout << endl;
    cout << "FICHA DE CONTACTO:" << endl;
    cout << "ID Contacto: " << _idContacto << endl;
    cout << "Nombre del contacto: " << _nombreContacto << endl;
    cout << "Numero de telefono: " << _nroTelefono << endl;
    cout << "Email: " << _email << endl;
    //cout << "Este contacto pertence a la entidad: "<<_idEntidad << endl;
}

int Contacto::Asociar(){

    int IdEntidad;
    cout << "A que entidad lo quiere asociar?"<< endl;
    cin >> IdEntidad;

    return IdEntidad;
}
#endif // CONTACTO_H_INCLUDED