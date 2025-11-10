#pragma once

class Cliente : public Entidad{

private:
    int _id;
    char _cuit[13];  // (CUIT: XX-XXXXXXXX-X o bien DNI: XXXXXXXX)
    int _tipo;  // (0- Sin tipo, 1-Responsable Inscripto, 2-Monotributo, 3-Exento, 4-Cons.Final)
    int _cantidadVentas;
    int _recaudacion;

public:

    Cliente(){
        _id=0;
        strcpy(_cuit,"Sin Datos");
        _tipo = 0;
        _cantidadVentas=0;
        _recaudacion=0;
    }

    void setId(int id){_id=id;}
    void setCuit(const char *cuit){strcpy(_cuit, cuit);}
    void setTipo(int tipo){
        if (tipo>=0 && tipo<=4){
            _tipo=tipo;
        } else{
            _tipo=0;
        }
    }
    void setcantidadVentas(int cantidadVentas){ _cantidadVentas = cantidadVentas;}
    void setRecaudacion(int recaudacion){_recaudacion = recaudacion;}

    int getId(){return _id;}
    const char* getCuit(){return _cuit;}
    int getTipo(){return _tipo;}
    int getcantidadVentas(){return _cantidadVentas;}
    int getRecaudacion(){return _recaudacion;}

    void Cargar(int identificador);
    void Mostrar();

};

void Cliente::Cargar(int identificador){
    _id=identificador;
    setId(_id);
    cout<<"CUIT: ";
    cin>>_cuit;
    cout << endl;
    Entidad::Cargar();
    cout << endl;
    cout<<"TIPO CLIENTE (0- Sin tipo, 1-Responsable Inscripto, 2-Monotributo, 3-Exento, 4-Cons.Final): ";
    int tipoCliente;
    cin >> tipoCliente;
    setTipo(tipoCliente);
    cout<<"CANTIDAD DE VENTAS: ";
    cin>>_cantidadVentas;
}

void Cliente::Mostrar(){
    cout<<"ID: "<<_id<<endl;
    cout<<"CUIT: "<<_cuit<<endl;
    Entidad::Mostrar();
    cout << "Tipo de Cliente: " << _tipo;
    if (_tipo==0){
        cout << " - Sin Tipo Asignado.";
    } else if (_tipo==1){
        cout << " - Responsable Inscripto.";
    } else if (_tipo==2){
        cout << " - Monotributo.";
    } else if (_tipo==3){
        cout << " - Exento.";
    } else if (_tipo==4){
        cout << " - Cons.Final.";
    }
    cout << endl;
    cout<<"Cantidad de ventas: "<<_cantidadVentas<<endl;
    cout<<"---------------------"<<endl<<endl;
}
