#pragma once

class Entidad{

protected:
    char _nombre [50];
    Direccion _direccion;
    Contacto _contacto;
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
    void setContacto(Contacto contacto) { _contacto = contacto; }
    void setEstado(bool estado){_estado = estado;}

    const char* getNombre(){return _nombre;}
    Direccion getDireccion(){ return _direccion; }
    Contacto getContacto(){ return _contacto; }
    bool getEstado(){return _estado;}

};

void Entidad::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(_nombre,50);
    _direccion.Cargar();
    _contacto.Cargar();
    _estado=true;
   //return true; //TRUE CONFIRMA QUE SE CARGO EL USUARIO
}

void Entidad::Mostrar(){
    cout<<"NOMBRE: "<<_nombre<<endl;
    _direccion.Mostrar();
    _contacto.Mostrar();
    cout << endl;
}
