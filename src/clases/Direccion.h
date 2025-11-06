#ifndef CLSDIRECCION_H_INCLUDED
#define CLSDIRECCION_H_INCLUDED

//DIRECCION
class Direccion{

    private:
        char _calle[20];
        int _numero;
        char _localidad[20];
        int _codigoPostal;
        char _provincia[20];

    public:

        //CONSTRUCTOR --> Se construye sin datos
        Direccion(){
            strcpy(_calle,"Sin Datos");
            _numero=0;
            strcpy(_localidad,"Sin Datos");
            _codigoPostal=0;
            strcpy(_provincia,"Sin Datos");
    }

        //SETTERS Y GETTERS

        void setCalle (const char* calle) {strcpy(_calle,calle);}
        void setNumero(int numero) { _numero = numero; }
        void setLocalidad (const char* localidad) {strcpy(_localidad,localidad);}
        void setCodigoPostal(int codigoPostal) { _codigoPostal = codigoPostal; }
        void setProvincia (const char* provincia) {strcpy(_provincia,provincia);}

        const char* getCalle() { return _calle; }
        int getNumero() { return _numero; }
        const char* getLocalidad() { return _localidad; }
        int getCodigoPostal() { return _codigoPostal; }
        const char* getProvincia() { return _provincia; }

        //CARGAR Y MOSTRAR

        void Cargar();

        void Mostrar(){ cout << "DIRECCION DEL PROVEEDOR:"<<endl; cout << _calle << " " << _numero << ", " << _localidad << " (CP: " << _codigoPostal << "), " << _provincia << endl; }

        string toString();
};

void Direccion::Cargar(){
    cout << "Calle: ";
    cargarCadena(_calle,20);
    cout << "Numero: ";
    cin >> _numero;
    cout << "Localidad: ";
    cargarCadena(_localidad,20);
    cout << "Codigo Postal: ";
    cin >> _codigoPostal;
    cout << "Provincia: ";
    cargarCadena(_provincia,20);
}

string Direccion::toString(){
    string direccionFormateada = "";

    string calle(_calle);
    string numero = to_string(_numero);
    string localidad(_localidad);
    string codigoPostal = to_string(_codigoPostal);
    string provincia(_provincia);

    direccionFormateada = calle + " " + numero + ", " + localidad + " (CP: " + codigoPostal + "), " + provincia;

    return direccionFormateada;
}

 
#endif // CLSDIRECCION_H_INCLUDED