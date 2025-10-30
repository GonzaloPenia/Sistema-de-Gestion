#pragma once

class ArchivoVendedor{
private:

    char nombre[30];

public:
    ArchivoVendedor(const char *n="../data/vendedores.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
        //estado=true;
    }
    const char *getNombre(){return nombre;}

    bool escribirArchivo(Vendedor regVendedor);
    void listarArchivo();
    Vendedor leerArchivo(int pos);
    void leerArchivo();
    bool modificarArchivo(int pos, Vendedor regVendedor);
    int buscarEnArchivo(int id);
    bool verificarRepetido(int id);
    vector<Vendedor> buscarPorNombreParcial(const char* subcadena);
    void encontrarVendedor(int id);
    int contarArchivo();
    void vectorizarArchivo(Vendedor registros[],int cantidad);

};

bool ArchivoVendedor::verificarRepetido(int id){
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){
        if(regVendedor.getId()==id){
            cout<<endl<<"SE ENCONTRO COINCIDENCIA."<<endl<<endl;
            system("pause");
            //regVendedor.Mostrar();
            return true; //HAY UN REPETIDO
        }
    }
    return false; //NO SE ENCONTRO REPETICION, FALSE HABILITA LA CARGA DE LOS DEMAS DATOS
    fclose(p);
}

int ArchivoVendedor::buscarEnArchivo(int id){
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){
        if(regVendedor.getId()==id){
            cout<<endl<<"SE ENCONTRO UN VENDEDOR CON ESE ID: "<<regVendedor.getNombre()<<endl<<endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool ArchivoVendedor::escribirArchivo(Vendedor regVendedor){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&regVendedor,sizeof (regVendedor),1,p);
    fclose(p);
    return true;
}

void ArchivoVendedor::listarArchivo(){
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl<<endl;
        return;
    }
    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){
        if (regVendedor.getEstado()==true){
            cout << regVendedor.getId() << " - " << regVendedor.getNombre() << endl;
        }
    }
    cout << endl;
    fclose(p);
}

Vendedor ArchivoVendedor::leerArchivo(int pos){
    Vendedor regVendedor;
    regVendedor.setEstado(false);
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return regVendedor;
    }
    fseek (p,sizeof(regVendedor)*pos,0);
    fread(&regVendedor,sizeof (regVendedor),1,p);
    fclose(p);
    return regVendedor;
}

void ArchivoVendedor::leerArchivo(){
    Vendedor regVendedor;
    FILE *p=fopen("../data/vendedores.dat","rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return ;
    }


    cout << left << setw(15) << "Cargo" << setw(35) << "Nombre" << setw(15) << "Sueldo" << endl;
    while(fread(&regVendedor, sizeof (regVendedor),1,p)==1){
        if(regVendedor.getEstado()){
        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(15) << regVendedor.getCargo() << setw(35) << regVendedor.getNombre() << setw(15) << regVendedor.getSueldo() << endl << endl;
        }
    }
    fclose(p);
    return;
}

bool ArchivoVendedor::modificarArchivo(int pos, Vendedor regVendedor){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return false;
    }
    fseek (p,sizeof(regVendedor)*pos,0);
    bool confirmacion=fwrite(&regVendedor,sizeof (regVendedor),1,p);
    fclose(p);
    return confirmacion; //DEVUELVE CONFIRMACION EN CASO DE SER EXITOSO
}

//FUNCION PARA BUSCAR COINCIDENCIAS PARCIALES EN CADENAS DE CARACTERES
vector<Vendedor> ArchivoVendedor::buscarPorNombreParcial(const char* subcadena) {
    FILE *p=fopen(nombre, "rb");
    vector<Vendedor> resultados;
    Vendedor regVendedor;

    if (p) {
        while (fread(&regVendedor, sizeof(regVendedor), 1, p) == 1) {
            if (strstr(regVendedor.getNombre(), subcadena) != nullptr) { //strstr --> Busca subcadena en nombre. Devuelve ptr a 1�aparici�n de subcadena en cadena. nullptr si no se encuentra.
                resultados.push_back(regVendedor); //Coincidencia parcial --> registro se agrega a vector mediante push_back.
            }
        }
        fclose(p);
    } else {
        cout << "Error al abrir el archivo para leer." << endl;
    }
    return resultados;
}

void ArchivoVendedor::encontrarVendedor(int id){
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }



    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){

        if(regVendedor.getId()==id){
            if(regVendedor.getEstado()){
            regVendedor.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
            }
        }

    }
    fclose(p);
}

int ArchivoVendedor::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Vendedor regVendedor;
    FILE *p=fopen("../data/vendedores.dat","rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO";
    return false;
    }
    int contador = 0;
    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoVendedor::vectorizarArchivo(Vendedor registros[],int cantidad){
    FILE *p;

   p = fopen("../data/vendedores.dat", "rb");

   if(p == nullptr){
      return;
   }
   fread(registros, sizeof(Vendedor), cantidad, p);
   fclose(p);
}

