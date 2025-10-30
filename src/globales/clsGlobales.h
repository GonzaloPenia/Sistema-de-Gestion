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

    //CONTACTO
class Contacto{

    private:
        char _telFijoNro1[20];
        char _telFijoNro2[20];
        char _telFijoNro3[20];
        char _telMovilNro1[20];
        char _telMovilNro2[20];
        char _telMovilNro3[20];
        char _contactoMovilNro1[30];
        char _contactoMovilNro2[30];
        char _contactoMovilNro3[30];
        char _emailNro1[40];
        char _emailNro2[40];
        char _emailNro3[40];
        char _contactoEmailNro1[30];
        char _contactoEmailNro2[30];
        char _contactoEmailNro3[30];

    public:

        //CONSTRUCTOR --> Se construye sin datos
        Contacto(){
            strcpy(_telFijoNro1,"Sin Datos");
            strcpy(_telFijoNro2,"Sin Datos");
            strcpy(_telFijoNro3,"Sin Datos");
            strcpy(_telMovilNro1,"Sin Datos");
            strcpy(_telMovilNro2,"Sin Datos");
            strcpy(_telMovilNro3,"Sin Datos");
            strcpy(_contactoMovilNro1,"Sin Datos");
            strcpy(_contactoMovilNro2,"Sin Datos");
            strcpy(_contactoMovilNro3,"Sin Datos");
            strcpy(_emailNro1,"Sin Datos");
            strcpy(_emailNro2,"Sin Datos");
            strcpy(_emailNro3,"Sin Datos");
            strcpy(_contactoEmailNro1,"Sin Datos");
            strcpy(_contactoEmailNro2,"Sin Datos");
            strcpy(_contactoEmailNro3,"Sin Datos");
        }

        //SETTERS Y GETTERS

        void setTelFijoNro1 (const char* telFijo) {strcpy(_telFijoNro1,telFijo);}
        void setTelFijoNro2 (const char* telFijo) {strcpy(_telFijoNro2,telFijo);}
        void setTelFijoNro3 (const char* telFijo) {strcpy(_telFijoNro3,telFijo);}
        void setTelMovilNro1 (const char* telMovil) {strcpy(_telMovilNro1,telMovil);}
        void setTelMovilNro2 (const char* telMovil) {strcpy(_telMovilNro2,telMovil);}
        void setTelMovilNro3 (const char* telMovil) {strcpy(_telMovilNro3,telMovil);}
        void setContactoMovilNro1 (const char* contactoMovil) {strcpy(_contactoMovilNro1,contactoMovil);}
        void setContactoMovilNro2 (const char* contactoMovil) {strcpy(_contactoMovilNro2,contactoMovil);}
        void setContactoMovilNro3 (const char* contactoMovil) {strcpy(_contactoMovilNro3,contactoMovil);}
        void setEmailNro1 (const char* email) {strcpy(_emailNro1,email);}
        void setEmailNro2 (const char* email) {strcpy(_emailNro2,email);}
        void setEmailNro3 (const char* email) {strcpy(_emailNro3,email);}
        void setContactoEmailNro1 (const char* contactoEmail) {strcpy(_contactoEmailNro1,contactoEmail);}
        void setContactoEmailNro2 (const char* contactoEmail) {strcpy(_contactoEmailNro2,contactoEmail);}
        void setContactoEmailNro3 (const char* contactoEmail) {strcpy(_contactoEmailNro3,contactoEmail);}

        const char* getTelFijoNro1() { return _telFijoNro1; }
        const char* getTelFijoNro2() { return _telFijoNro2; }
        const char* getTelFijoNro3() { return _telFijoNro3; }
        const char* getTelMovilNro1() { return _telMovilNro1; }
        const char* getTelMovilNro2() { return _telMovilNro2; }
        const char* getTelMovilNro3() { return _telMovilNro3; }
        const char* getContactoMovilNro1() { return _contactoMovilNro1; }
        const char* getContactoMovilNro2() { return _contactoMovilNro2; }
        const char* getContactoMovilNro3() { return _contactoMovilNro3; }
        const char* getEmailNro1() { return _emailNro1; }
        const char* getEmailNro2() { return _emailNro2; }
        const char* getEmailNro3() { return _emailNro3; }
        const char* getContactoEmailNro1() { return _contactoEmailNro1; }
        const char* getContactoEmailNro2() { return _contactoEmailNro2; }
        const char* getContactoEmailNro3() { return _contactoEmailNro3; }

        //CARGAR Y MOSTRAR

        void Cargar();

        void Mostrar();

};

void Contacto::Cargar(){
    cout << "Tel.Fijo Nro.1: ";
    cargarCadena(_telFijoNro1,20);
    cout << "Tel.Fijo Nro.2: ";
    cargarCadena(_telFijoNro2,20);
    cout << "Tel.Fijo Nro.3: ";
    cargarCadena(_telFijoNro3,20);
    cout << "Tel.Movil Nro.1: ";
    cargarCadena(_telMovilNro1,20);
    cout << "Contacto Movil Nro.1: ";
    cargarCadena(_contactoMovilNro1,30);
    cout << "Tel.Movil Nro.2: ";
    cargarCadena(_telMovilNro2,20);
    cout << "Contacto Movil Nro.2: ";
    cargarCadena(_contactoMovilNro2,30);
    cout << "Tel.Movil Nro.3: ";
    cargarCadena(_telMovilNro3,20);
    cout << "Contacto Movil Nro.3: ";
    cargarCadena(_contactoMovilNro3,30);
    cout << "Email Nro.1: ";
    cargarCadena(_emailNro1,40);
    cout << "Contacto Email Nro.1: ";
    cargarCadena(_contactoEmailNro1,30);
    cout << "Email Nro.2: ";
    cargarCadena(_emailNro2,40);
    cout << "Contacto Email Nro.2: ";
    cargarCadena(_contactoEmailNro2,30);
    cout << "Email Nro.3: ";
    cargarCadena(_emailNro3,40);
    cout << "Contacto Email Nro.3: ";
    cargarCadena(_contactoEmailNro3,30);
}

void Contacto::Mostrar(){
    cout << "Tel.Fijo Nro.1: " << _telFijoNro1 << endl;
    cout << "Tel.Fijo Nro.2: " << _telFijoNro2 << endl;
    cout << "Tel.Fijo Nro.3: " << _telFijoNro3 << endl;
    cout << "Tel.Movil Nro.1: " << _telMovilNro1 << " (" << _contactoMovilNro1 << ")" << endl;
    cout << "Tel.Movil Nro.2: " << _telMovilNro2 << " (" << _contactoMovilNro2 << ")" << endl;
    cout << "Tel.Movil Nro.3: " << _telMovilNro3 << " (" << _contactoMovilNro3 << ")" << endl;
    cout << "Email Nro.1: " << _emailNro1 << " (" << _contactoEmailNro1 << ")" << endl;
    cout << "Email Nro.2: " << _emailNro2 << " (" << _contactoEmailNro2 << ")" << endl;
    cout << "Email Nro.3: " << _emailNro3 << " (" << _contactoEmailNro3 << ")" << endl;
}



#endif // CLSGLOBALES_H_INCLUDED
