#pragma once
#include "Entidad.h"

class Vendedor: public Entidad {

private:
// _nombre, _direccion (_domicilio) y _estado heredados de Entidad
    int _id;
    int _cargo;
    int _sueldo;
    int _ventasRealizadas;
    int _aniosAntiguedad;
    Fecha _fechaIngreso;
    int _dni;
    int _edad;
    Fecha _fechaNacimiento;

public:

    Vendedor() : Entidad() {
        // _nombre y _estado heredados de Entidad()
        _id=0;
        _cargo=0;
        _sueldo = 0;
        _ventasRealizadas=0;
        _aniosAntiguedad=0;
        _dni = 0;
        _edad=0;
    }

    // setNombre() heredado de Entidad
    // setDireccion() heredado de Entidad (antes setDomicilio)
    // setEstado() heredado de Entidad
    void setId(int id){_id=id;}
    void setCargo(int cargo){_cargo=cargo;}
    void setSueldo(int sueldo){_sueldo=sueldo;}
    void setventasRealizadas(int ventasRealizadas){ _ventasRealizadas = ventasRealizadas;}
    void setaniosAntiguedad(int aniosAntiguedad){_aniosAntiguedad=aniosAntiguedad;}
    void setfechaIngreso(Fecha fechaIngreso){_fechaIngreso=fechaIngreso;}
    void setDni(int dni){_dni=dni;}
    void setEdad(int edad){_edad=edad;}
    void setFechaNacimiento(Fecha fechaNacimiento){_fechaNacimiento = fechaNacimiento;}

    // getNombre() heredado de Entidad
    // getDireccion() heredado de Entidad (antes getDomicilio)
    // getEstado() heredado de Entidad
    int getId(){return _id;}
    int getCargo(){return _cargo;}
    int getSueldo(){return _sueldo;}
    int getventasRealizadas(){return _ventasRealizadas;}
    int getaniosAntiguedad(){return _aniosAntiguedad;}
    Fecha getfechaIngreso(){return _fechaIngreso;}
    int getDni(){return _dni;}
    int getEdad(){return _edad;}
    Fecha getFechaNacimiento(){return _fechaNacimiento;}

    void Cargar(int dni);
    void Mostrar();
    void Mostrar(bool);

};

void Vendedor::Cargar(int id){
    setId(id);
    cout << "NOMBRE COMPLETO: ";
    cargarCadena(_nombre,50);
    cout << "DNI: ";
    cin >> _dni;
    cout << "-----------------------------------------------------------"<<endl;
    do{
        cout << "CARGO: ";
        cout << "1 PARA VENDEDOR, 2 PARA SUPERVISOR, 3 PARA ENCARGADO: ";
        cin>>_cargo;
    } while(_cargo<1 || _cargo>3);
    
    cout << "INGRESE EL SUELDO QUE PERCIBIRA EL EMPLEADO: $";
    cin>>_sueldo;
    
    cout << "INGRESE VENTAS REALIZADAS: ";
    cin>>_ventasRealizadas;
    
    cout << "INGRESE ANIOS DE ANTIGUEDAD: ";
    cin>>_aniosAntiguedad;
    
    cout << "-----------------------------------------------------------"<<endl;
    cout << "INGRESE FECHA DE INGRESO A LA ACTIVIDAD LABORAL: ";
    _fechaIngreso.Cargar();
    cout << "-----------------------------------------------------------"<<endl;
    cout << "INGRESE FECHA DE NACIMIENTO: "<<endl;
    _fechaNacimiento.Cargar();
    _edad = calcularEdad(_fechaNacimiento);
    cout << "EDAD: " << _edad << endl;
    cout << "-----------------------------------------------------------"<<endl;
    cout<<"INGRESE EL DOMICILIO: "<< endl;
    _direccion.Cargar();

    _estado=true;
}

void Vendedor::Mostrar(){
    
    cout << "DATOS PERSONALES:"<<endl;
    cout << "-----------------------------------------------------------"<<endl;
    cout <<"ID DE VENDEDOR: "<<_id<<endl;
    cout<<"NOMBRE: "<<_nombre<<endl; // usando propiedad heredada
    cout<<"DNI: "<<_dni<<endl;
    cout << "FECHA DE NACIMIENTO: ";
    _fechaNacimiento.Mostrar();
    cout<<"EDAD: "<<_edad<<endl;
    cout << "DOMICILIO: ";
    _direccion.Mostrar(); // usando propiedad heredada
    
    cout << "DATOS LABORALES:"<<endl;
    cout << "-----------------------------------------------------------"<<endl;
    cout << "1 PARA VENDEDOR, 2 PARA SUPERVISOR, 3 PARA ENCARGADO: ";
    cout<<"CARGO: "<<_cargo<<endl;
    cout<<"SUELDO: $"<<_sueldo<<endl;
    cout<<"VENTAS REALIZADAS: "<<_ventasRealizadas<<endl;
    cout<<"ANIOS DE ANTIGUEDAD: "<<_aniosAntiguedad<<endl;
    cout << "FECHA DE INGRESO A LA ACTIVIDAD LABORAL: "<<endl;;
    _fechaIngreso.Mostrar();
    cout << endl;
    cout << endl;
    cout << endl;
}

void Vendedor::Mostrar(bool){
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
    cout << left << setw(5) << _id << setw(15) << _nombre << setw(15) << _cargo << setw(15) << _ventasRealizadas << setw(15) << _aniosAntiguedad << endl;
} 
