#ifndef ARCHIVOARTICULO_H_INCLUDED
#define ARCHIVOARTICULO_H_INCLUDED

class ArchivoArticulo{
private:

    char nombre[30];

public:
    ArchivoArticulo(const char *n="../../data/articulos.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
        //estado=true;
    }
    const char *getNombre(){return nombre;}

    bool escribirArchivo(Articulo regArticulo);
    Articulo leerArchivo(int pos);
    void leerArchivo();
    bool modificarArchivo(int pos, Articulo Articulo);
    int modificarArchivo(Proveedor regProveedor);
    int buscarEnArchivo(int id);
    int buscarRegistro(int id);
    int buscarSinMostrar(int id);
    bool verificarRepetido(int id);
    int contarArchivo();
    vector<Articulo> buscarPorNombreParcial(const char* subcadena);
    vector<Articulo> VectorArticulos();
    void vectorizarArchivo(Articulo registros[],int cantidad);

};

bool ArchivoArticulo::verificarRepetido(int id){
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){
        if(regArticulo.getId()==id){
            cout<<endl<<"SE ENCONTRO COINCIDENCIA."<<endl<<endl;
            //regArticulo.Mostrar();
            return true; //HAY UN REPETIDO
        }
    }
    return false; //NO SE ENCONTRO REPETICION, FALSE HABILITA LA CARGA DE LOS DEMAS DATOS
    fclose(p);
}

int ArchivoArticulo::buscarEnArchivo(int id){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getId()==id){
            cout<<endl<<"SE ENCONTRO UN ARTICULO CON ESE ID: ";
            Articulo.Mostrar();
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

int ArchivoArticulo::buscarRegistro(int id){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getId()==id){
            cout<<endl<<"SE ENCONTRO UN ARTICULO CON ESE ID: " << Articulo.getDescripcion()<<endl<<endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

int ArchivoArticulo::buscarSinMostrar(int id){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getId()==id){
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool ArchivoArticulo::escribirArchivo(Articulo regArticulo){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&regArticulo,sizeof regArticulo,1,p);
    fclose(p);
    return true;
}

Articulo ArchivoArticulo::leerArchivo(int pos){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return Articulo;
    }
    fseek (p,sizeof(Articulo)*pos,0);
    fread(&Articulo,sizeof Articulo,1,p);
    fclose(p);
    return Articulo;
}

void ArchivoArticulo::leerArchivo(){
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){
        regArticulo.Mostrar();
    }
    fclose(p);
}

bool ArchivoArticulo::modificarArchivo(int pos, Articulo Articulo){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return false;
    }
    fseek (p,sizeof(Articulo)*pos,0);
    bool confirmacion=fwrite(&Articulo,sizeof Articulo,1,p);
    fclose(p);
    return confirmacion; //DEVUELVE CONFIRMACION EN CASO DE SER EXITOSO
}

int ArchivoArticulo::modificarArchivo(Proveedor regProveedor){
    Articulo Articulo;
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    int contador=0;
    int cambios=0;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        Proveedor auxProveedor;
        auxProveedor=Articulo.getProveedor();
        if(auxProveedor.getId() == regProveedor.getId())
        {
            Articulo.setProveedor(regProveedor);
            modificarArchivo(contador,Articulo);
            cambios++;
        }
        contador++;
    }
    fclose(p);
    return cambios;
}

int ArchivoArticulo::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO";
    return 0;
    }
    int contador = 0;
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){contador++;}
    fclose(p);
    return contador;
}

vector<Articulo> ArchivoArticulo::buscarPorNombreParcial(const char* subcadena) {//FUNCION PARA BUSCAR COINCIDENCIAS PARCIALES EN CADENAS DE CARACTERES
    FILE *p=fopen(nombre, "rb");
    vector<Articulo> resultados;
    Articulo regArticulo;

    if (p) {
        bool indicadorBusqEspecial = (subcadena[0] == '*');
        const char* sub = (indicadorBusqEspecial) ? subcadena + 1 : subcadena; //OPERADOR TERNARIO --> condicion ? verdadero : falso

        char subMinusc[30];
        strcpy(subMinusc, sub);
        convertirMinuscula(subMinusc);

        while (fread(&regArticulo, sizeof(regArticulo), 1, p) == 1) {
            char descripcion[50];
            strcpy(descripcion, regArticulo.getDescripcion());
            convertirMinuscula(descripcion);

            if ((!indicadorBusqEspecial && strncmp(descripcion, subMinusc, strlen(subMinusc)) == 0) ||
                (indicadorBusqEspecial && strstr(descripcion, subMinusc) != nullptr)) {
                resultados.push_back(regArticulo);
            }
            //strstr --> Busca subcadena en nombre. Devuelve ptr a 1�apariciOn de subcadena en cadena. nullptr si no se encuentra.
            //Coincidencia parcial --> registro se agrega a vector mediante push_back.
        }
        fclose(p);
    } else {
        cout << "Error al abrir el archivo para leer." << endl;
    }
    return resultados;
}

vector<Articulo> ArchivoArticulo::VectorArticulos(){ //MUESTRA EL ARTICULO QUE CORRESPONDE AL ID.
    vector<Articulo> vecArticulos;
    return vecArticulos;
}

void ArchivoArticulo::vectorizarArchivo(Articulo registros[],int cantidad){
    FILE *p;

   p = fopen(nombre, "rb");

   if(p == nullptr){
      return;
   }
   fread(registros, sizeof(Articulo), cantidad, p);
   fclose(p);
}

#endif // ARCHIVOARTICULO_H_INCLUDED
