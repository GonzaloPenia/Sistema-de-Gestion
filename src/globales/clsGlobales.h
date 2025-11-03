#ifndef CLSGLOBALES_H_INCLUDED
#define CLSGLOBALES_H_INCLUDED

///CLASES GLOBALES

    //FECHA
class Fecha{

    private:
        int dia, mes, anio;

    public:

        //CONSTRUCTOR --> Se construye con la fecha del sistema
        Fecha(){
            time_t t;
            struct tm *f;
            time(&t);
            f = localtime(&t);
            dia = f->tm_mday;
            mes = f->tm_mon+1;
            anio = f->tm_year+1900;
        }

        Fecha(int d, int m, int a){
            setDia(d);
            setMes(m);
            setAnio(a);
        }

        //Setters y Getters

        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}

        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        //Cargar y Mostrar

        void Cargar();
        void CargarFechaExistente();
        void cargarFechaSistema();

        void Mostrar(){cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}

        string toString();

        bool operator<=(const Fecha& otra);
        bool operator>=(const Fecha& otra);

};

void Fecha::Cargar(){

    do{
        cout<<"DIA: ";
        cin>>dia;
    }while(dia<1 || dia>31);

    do{
        cout<<"MES: ";
        cin>>mes;
    }while(mes<0 || mes>12);

    do{
        cout<<"ANIO: ";
        cin>>anio;
    }while(anio<0 || anio>9999);

}

void Fecha::CargarFechaExistente(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    //SE COMPRUEBA QUE SE ESTA PONIENDO UNA FECHA VALIDA
    time_t now = time(0);
    tm *ltm = localtime(&now);
    bool check_fecha=false;
    if(anio <=(1900 + ltm->tm_year)){
        if(anio==(1900 + ltm->tm_year)){
            if(mes<=(1 + ltm->tm_mon)){
                if(mes==(1 + ltm->tm_mon)){
                    if(dia<=(ltm->tm_mday)){
                        check_fecha=true;
                    }
                }else{check_fecha=true;}
            }
        }else{check_fecha=true;}
    }
    while(check_fecha!=true){
        cout<<"La fecha que desea ingresar esta en un formato incompatible o todavia no paso"<<endl<<"Ingrese una fecha valida."<<endl;
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
        if(anio <=(1900 + ltm->tm_year)){
            if(anio==(1900 + ltm->tm_year)){
                if(mes<=(1 + ltm->tm_mon)){
                    if(mes==(1 + ltm->tm_mon)){
                        if(dia<=(ltm->tm_mday)){
                            check_fecha=true;
                        }
                    }else{check_fecha=true;}
                }
            }else{check_fecha=true;}
        }
    }
}

void Fecha::cargarFechaSistema(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    dia = f->tm_mday;
    mes = f->tm_mon+1;
    anio = f->tm_year+1900;
}

string Fecha::toString(){
    string formatoFecha = "DD/MM/YYYY";
    string fechaFormateada = "";

    string DD = to_string(dia);
    string MM = to_string(mes);
    string YYYY = to_string(anio);

    // DD/MM/YYYY
    if (dia < 10){
        DD = "0" + to_string(dia);
    }
    if (mes < 10){
        MM = "0" + to_string(mes);
    }

    if (formatoFecha == "DD/MM/YYYY"){
        fechaFormateada = DD + "/" + MM + "/" + YYYY;
    }
    else if (formatoFecha == "YYYY/MM/DD"){
        fechaFormateada = YYYY + "/" + MM + "/" + DD;
    }
    else{
        fechaFormateada = DD + "/" + MM + "/" + YYYY;
    }

    return fechaFormateada;
}

bool Fecha::operator<=(const Fecha& otra) {
    if (anio < otra.anio) {
        return true;
    } else if (anio == otra.anio) {
        if (mes < otra.mes) {
            return true;
        } else if (mes == otra.mes) {
            return dia <= otra.dia;
        }
    }
    return false;
}

bool Fecha::operator>=(const Fecha& otra) {
    if (anio > otra.anio) {
        return true;
    } else if (anio == otra.anio) {
        if (mes > otra.mes) {
            return true;
        } else if (mes == otra.mes) {
            return dia >= otra.dia;
        }
    }
    return false;
}

int calcularEdad(Fecha& fechaNacimiento) {
    //Fecha actual del sistema
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);

    int diaActual = f->tm_mday;
    int mesActual = f->tm_mon + 1;
    int anioActual = f->tm_year + 1900;

    int edad = anioActual - fechaNacimiento.getAnio();

    if (mesActual < fechaNacimiento.getMes()) {
        edad--;
    } else if (mesActual == fechaNacimiento.getMes()) {
        if (diaActual < fechaNacimiento.getDia()) {
            edad--;
        }
    }

    return edad;
}

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

        void Mostrar(){ cout << _calle << " " << _numero << ", " << _localidad << " (CP: " << _codigoPostal << "), " << _provincia << endl; }

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

 


#endif // CLSGLOBALES_H_INCLUDED
