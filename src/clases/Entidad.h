#pragma once
#include <cstring>
#include <iostream>
using namespace std;

#ifndef FUNCIONESGLOBALES_H_INCLUDED
    #include "../globales/funcionesGlobales.h"
#endif

class Entidad{

protected:
    char _nombre [50];
    Direccion _direccion;
    bool _estado;

public:
    Entidad(){
        strcpy(_nombre,"Sin Datos");
        _estado=false;
    }

    void Cargar();
    void Mostrar();

    void setNombre(const char *n){strcpy(_nombre, n);}
    void setDireccion(Direccion direccion) { _direccion = direccion; }
    void setEstado(bool estado){_estado = estado;}

    const char* getNombre(){return _nombre;}
    Direccion getDireccion(){ return _direccion; }
    bool getEstado(){return _estado;}

};

void Entidad::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(_nombre,50);
    _direccion.Cargar();
    _estado=true;
}

void Entidad::Mostrar(){
    cout<<"NOMBRE: "<<_nombre<<endl;
    _direccion.Mostrar();
    cout << endl;
}
