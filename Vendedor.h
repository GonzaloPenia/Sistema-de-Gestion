#pragma once

class Vendedor {

private:
    int _id;
    int _cargo;
    int _sueldo;
    int _ventasRealizadas;
    int _aniosAntiguedad;
    Fecha _fechaIngreso;
    char _nombre [40];
    //char _apellido[40];
    int _dni;
    int _edad;
    Direccion _domicilio;
    Fecha _fechaNacimiento;
    bool _estado;

public:

    Vendedor(){
        _id=0;
        _cargo=0;
        _sueldo = 0;
        _ventasRealizadas=0;
        _aniosAntiguedad=0;
        strcpy(_nombre,"Sin Datos");
        //strcpy(_apellido,"Sin Datos");
        _dni = 0;
        _edad=0;
        _estado = false;

    }

    void setId(int id){_id=id;}
    void setCargo(int cargo){_cargo=cargo;}
    void setSueldo(int sueldo){_sueldo=sueldo;}
    void setventasRealizadas(int ventasRealizadas){ _ventasRealizadas = ventasRealizadas;}
    void setaniosAntiguedad(int aniosAntiguedad){_aniosAntiguedad=aniosAntiguedad;}
    void setfechaIngreso(Fecha fechaIngreso){_fechaIngreso=fechaIngreso;}
    void setNombre (const char *nombre){strcpy(_nombre, nombre);}
    //void setApellido (const char *apellido){strcpy(_apellido, apellido);}
    void setDni(int dni){_dni=dni;}
    void setEdad(int edad){_edad=edad;}
    void setDomicilio(Direccion domicilio){_domicilio = domicilio;}
    void setFechaNacimiento(Fecha fechaNacimiento){_fechaNacimiento = fechaNacimiento;}
    void setEstado (bool estado){_estado = estado;}

    int getId(){return _id;}
    int getCargo(){return _cargo;}
    int getSueldo(){return _sueldo;}
    int getventasRealizadas(){return _ventasRealizadas;}
    int getaniosAntiguedad(){return _aniosAntiguedad;}
    Fecha getfechaIngreso(){return _fechaIngreso;}
    char *getNombre(){return _nombre;}
    //char *getApellido(){return _apellido;}
    int getDni(){return _dni;}
    int getEdad(){return _edad;}
    Direccion getDomicilio(){return _domicilio;}
    Fecha getFechaNacimiento(){return _fechaNacimiento;}
    bool getEstado(){return _estado;}

    void Cargar(int dni);
    void Mostrar();

};

void Vendedor::Cargar(int id){
    setId(id);
    cout << "NOMBRE COMPLETO: ";
    cargarCadena(_nombre,40);
    cout << "DNI: ";
    cin >> _dni;
    cout << "CARGO: ";
    cin>>_cargo;    
    cout << "SUELDO: ";
    cin>>_sueldo;
    cout << "VENTAS REALIZADAS: ";
    cin>>_ventasRealizadas;
    cout << "ANIOS DE ANTIGUEDAD: ";
    cin>>_aniosAntiguedad;
    cout << "FECHA DE INGRESO: ";
    _fechaIngreso.Cargar();
    cout<<"EDAD: ";
    cin>>_edad;
    cout << "FECHA DE NACIMIENTO: ";
    _fechaNacimiento.Cargar();
    cout<<"DOMICILIO: ";
    _domicilio.Cargar();
    
    _estado=true;
}

void Vendedor::Mostrar(){
    cout <<"ID: "<<_id<<endl;
    cout<<"NOMBRE: "<<_nombre<<endl;
    //cout<<"APELLIDO: "<<_apellido<<endl;
    cout<<"DNI: "<<_dni<<endl;
    cout<<"CARGO: "<<_cargo<<endl;
    cout<<"SUELDO: "<<_sueldo<<endl;
    cout<<"VENTAS REALIZADAS: "<<_ventasRealizadas<<endl;
    cout<<"ANIOS DE ANTIGUEDAD: "<<_aniosAntiguedad<<endl;
    cout << "FECHA DE INGRESO: ";
    _fechaIngreso.Mostrar();
    cout << endl;
    cout<<"EDAD: "<<_edad<<endl;
    cout << "DOMICILIO: ";
    _domicilio.Mostrar();
    cout << endl;
    cout << "FECHA DE NACIMIENTO: ";
    _fechaNacimiento.Mostrar();
    cout << endl;
}
