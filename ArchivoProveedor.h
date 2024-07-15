#ifndef CLSARCHIVOPROVEEDOR_H_INCLUDED
#define CLSARCHIVOPROVEEDOR_H_INCLUDED

class ArchivoProveedor{
private:

    char nombre[30];

public:
    ArchivoProveedor(const char *n="proveedores.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
        //estado=true;
    }
    const char *getNombre(){return nombre;}

    bool escribirArchivo(Proveedor Proveedor);
    Proveedor leerArchivo(int pos);
    void leerArchivo();
    bool modificarArchivo(int pos, Proveedor Proveedor);
    int buscarEnArchivo(int id);
    bool verificarRepetido(int id);
    int contarArchivo();
    void vectorizarArchivo(Proveedor registros[],int cantidad);

};

bool ArchivoProveedor::verificarRepetido(int id){
    Proveedor Proveedor;
    FILE *p=fopen(nombre,"rb");
    while(fread(&Proveedor,sizeof Proveedor,1,p)==1){
        if(Proveedor.getId()==id){
            cout<<"SE ENCONTRO COINCIDENCIA."<<endl<<endl;
            Proveedor.Mostrar();
            return true; //HAY UN REPETIDO
        }
    }
    return false; //NO SE ENCONTRO REPETICION, FALSE HABILITA LA CARGA DE LOS DEMAS DATOS
    fclose(p);
}

int ArchivoProveedor::buscarEnArchivo(int id){
    Proveedor Proveedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&Proveedor,sizeof Proveedor,1,p)==1){
        if(Proveedor.getId()==id){
            cout<<"SE ENCONTRO UN PROVEEDOR CON ESE ID:"<<endl<<endl;
            Proveedor.Mostrar();
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool ArchivoProveedor::escribirArchivo(Proveedor Proveedor){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&Proveedor,sizeof Proveedor,1,p);
    fclose(p);
    return true;
}

Proveedor ArchivoProveedor::leerArchivo(int pos){
    Proveedor Proveedor;
    //Proveedor.setEstado(false);
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return Proveedor;
    }
    fseek (p,sizeof(Proveedor)*pos,0);
    fread(&Proveedor,sizeof Proveedor,1,p);
    fclose(p);
    return Proveedor;
}

void ArchivoProveedor::leerArchivo(){
    Proveedor Proveedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&Proveedor,sizeof Proveedor,1,p)==1){
        Proveedor.Mostrar();
    }
    fclose(p);
}

bool ArchivoProveedor::modificarArchivo(int pos, Proveedor Proveedor){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return false;
    }
    fseek (p,sizeof(Proveedor)*pos,0);
    bool confirmacion=fwrite(&Proveedor,sizeof Proveedor,1,p);
    fclose(p);
    return confirmacion; //DEVUELVE CONFIRMACION EN CASO DE SER EXITOSO
}

int ArchivoProveedor::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Proveedor regProveedor;
    FILE *p=fopen("proveedores.dat","rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO(contarArchivo)";
    return false;
    }
    int contador = 0;
    while(fread(&regProveedor,sizeof regProveedor,1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoProveedor::vectorizarArchivo(Proveedor registros[],int cantidad){
    FILE *p;

    p = fopen("proveedores.dat", "rb");

    if(p == nullptr){
        return;
    }
    fread(registros, sizeof(Proveedor), cantidad, p);
    fclose(p);
}

#endif // CLSARCHIVOARTICULO_H_INCLUDED
