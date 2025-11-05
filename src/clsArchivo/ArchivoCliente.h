#pragma once

//Clientes

class ArchivoCliente:public Entidad{

private:

    char nombre[30];

public:
    ArchivoCliente(const char *n="../../data/clientes.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
        //estado=true;
    }
    const char *getNombre(){return nombre;}
    bool escribirArchivo(Cliente regCliente);
    Cliente leerArchivo(int pos);
    void leerArchivo();
    bool modificarArchivo(int pos, Cliente regCliente);
    vector<Cliente> buscarPorNombreParcial(const char* subcadena);
    int buscarEnArchivo(int id);
    int buscarRegistro(int id);
    int buscarRegistro(const char* cuit);
    bool verificarRepetido(int id);
    int contarArchivo();
    void vectorizarArchivo(Cliente registros[],int cantidad);
    void encontrarCliente(int id);
    void encontrarClienteNombre(const char* nombre);
    void encontrarClienteCuit(const char* cuit);
    int buscarSinMostrar(int id);
    void encontrarClienteRecaudacion(int id);

};

bool ArchivoCliente::verificarRepetido(int id){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){
        if(regCliente.getId()==id){
            cout<<"SE ENCONTRO COINCIDENCIA."<<endl<<endl;
            //regCliente.Mostrar();
            return true; //HAY UN REPETIDO
        }
    }
    return false; //NO SE ENCONTRO REPETICION, FALSE HABILITA LA CARGA DE LOS DEMAS DATOS
    fclose(p);
}

int ArchivoCliente::buscarEnArchivo(int id){

    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        //cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }

    int contador=0;
    while(fread(&regCliente, sizeof (regCliente),1,p)==1){
        if(regCliente.getId()==id){
            cout<<endl<<"SE ENCONTRO UN CLIENTE: "<<endl;
            //regCliente.getNombre()
            regCliente.Mostrar();
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

int ArchivoCliente::buscarRegistro(int id){

    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        //cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }

    int contador=0;
    while(fread(&regCliente, sizeof (regCliente),1,p)==1){
        if(regCliente.getId()==id && regCliente.getEstado()==true){
            cout<<endl<<"SE ENCONTRO UN CLIENTE CON ESE ID: "<<endl<<endl;
            cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regCliente.getId() << setw(55) << regCliente.getNombre() << setw(15) << regCliente.getCuit() << endl << endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

int ArchivoCliente::buscarRegistro(const char* cuit){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){
        if(strcmp(regCliente.getCuit(),cuit)==0 && regCliente.getEstado()==true){
            cout<<endl<<"SE ENCONTRO UN CLIENTE CON ESE ID: "<<endl<<endl;
            cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regCliente.getId() << setw(55) << regCliente.getNombre() << setw(15) << regCliente.getCuit() << endl << endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool ArchivoCliente::escribirArchivo(Cliente regCliente){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&regCliente,sizeof (regCliente),1,p);
    fclose(p);
    return true;
}

Cliente ArchivoCliente::leerArchivo(int pos){
    Cliente regCliente;
    //Entidad.setEstado(false);
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return regCliente;
    }
    fseek (p,sizeof(Cliente)*pos,0);
    fread(&regCliente,sizeof (regCliente),1,p);
    fclose(p);
    return regCliente;
}

void ArchivoCliente::leerArchivo(){
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return ;
    }
    cout << left << setw(5) << "ID" << setw(55) << "NOMBRE" << setw(15) << "CUIT" << endl;
    while(fread(&regCliente, sizeof (regCliente),1,p)==1){
        if(regCliente.getEstado()){
            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regCliente.getId() << setw(55) << regCliente.getNombre() << setw(15) << regCliente.getCuit() << endl << endl;
        }
    }
    fclose(p);
    return;
}

bool ArchivoCliente::modificarArchivo(int pos, Cliente regCliente){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return false;
    }
    fseek (p,sizeof(regCliente)*pos,0);
    bool confirmacion=fwrite(&regCliente,sizeof (regCliente),1,p);
    fclose(p);
    return confirmacion; //DEVUELVE CONFIRMACION EN CASO DE SER EXITOSO
}

//FUNCION PARA BUSCAR COINCIDENCIAS PARCIALES EN CADENAS DE CARACTERES
vector<Cliente> ArchivoCliente::buscarPorNombreParcial(const char* subcadena) {
    FILE *p=fopen(nombre, "rb");
    vector<Cliente> resultados;
    Cliente regCliente;

    if (p) {
        bool indicadorBusqEspecial = (subcadena[0] == '*');
        const char* sub = (indicadorBusqEspecial) ? subcadena + 1 : subcadena; //OPERADOR TERNARIO --> condicion ? verdadero : falso

        char subMinusc[30];
        strcpy(subMinusc, sub);
        convertirMinuscula(subMinusc);

        while (fread(&regCliente, sizeof(regCliente), 1, p) == 1) {
            if (regCliente.getEstado()==true){
                char nombre[50];
                strcpy(nombre, regCliente.getNombre());
                convertirMinuscula(nombre);

                if ((!indicadorBusqEspecial && strncmp(nombre, subMinusc, strlen(subMinusc)) == 0) ||
                    (indicadorBusqEspecial && strstr(nombre, subMinusc) != nullptr)) {
                    resultados.push_back(regCliente);
                }
                //strstr --> Busca subcadena en nombre. Devuelve ptr a 1�aparici�n de subcadena en cadena. nullptr si no se encuentra.
                //Coincidencia parcial --> registro se agrega a vector mediante push_back.
            }
        }
        fclose(p);
    } else {
        cout << "Error al abrir el archivo para leer." << endl;
    }
    return resultados;
}

int ArchivoCliente::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO";
    return false;
    }
    int contador = 0;
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoCliente::vectorizarArchivo(Cliente registros[],int cantidad){
    FILE *p;

   p = fopen("../../data/clientes.dat", "rb");

   if(p == nullptr){
      return;
   }
   fread(registros, sizeof(Cliente), cantidad, p);
   fclose(p);
}

void ArchivoCliente::encontrarCliente(int id){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }



    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(regCliente.getId()==id){
            if(regCliente.getEstado()){
                regCliente.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
            }
        }


    }
    fclose(p);
}

void ArchivoCliente::encontrarClienteNombre(const char* nombre){
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }



    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(strcmp(regCliente.getNombre(),nombre)==0){
            if(regCliente.getEstado()){
                regCliente.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE NOMBRE"<<endl;
            }
        }


    }
    fclose(p);
}

void ArchivoCliente::encontrarClienteCuit(const char* cuit){
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }



    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(strcmp(regCliente.getCuit(),cuit)==0){
            if(regCliente.getEstado()){
                regCliente.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE CUIT"<<endl;
            }
        }


    }
    fclose(p);
}

int ArchivoCliente::buscarSinMostrar(int id){

    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        //cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }

    int contador=0;
    while(fread(&regCliente, sizeof (regCliente),1,p)==1){
        if(regCliente.getId()==id){

            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

void ArchivoCliente::encontrarClienteRecaudacion(int id){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(regCliente.getId()==id){
            if(regCliente.getEstado()){
                cout << left << setw(25) << "Nombre o Razon Social" << setw(35) << "Recaudacion" << endl;
                cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
                cout << left << setw(25) << regCliente.getNombre() << setw(35) << regCliente.getRecaudacion() << endl;
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
            }
        }
    }
    fclose(p);
}
