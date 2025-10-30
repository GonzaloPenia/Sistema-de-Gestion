#ifndef ARCHIVONOTADECREDITO_H_INCLUDED
#define ARCHIVONOTADECREDITO_H_INCLUDED

///CLASE ARCHIVO: NOTA DE CREDITO
class ArchivoNotaDeCredito{

private:
    char _nombre[20];

public:

    ArchivoNotaDeCredito(){strcpy(_nombre,"../data/notasDeCredito.dat");}

///M�TODOS

    ///ESCRITURA

    //AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
    //SIN RECIBIR PARAMETROS. PIDE QUE SE CARGUE MIENTRAS SE EJECUTA
    int AgregarRegistro(){
        NotaDeCredito regNotaDeCredito;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        regNotaDeCredito.Cargar();
        int valor = fwrite (&regNotaDeCredito, sizeof regNotaDeCredito, 1, p);
        fclose(p);
        return valor;
    }

    //AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
    //RECIBE UN OBJETO Y LO AGREGA
    int AgregarRegistro(NotaDeCredito regNotaDeCredito){
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        int valor = fwrite (&regNotaDeCredito, sizeof regNotaDeCredito, 1, p);
        fclose(p);
        return valor;
    }

    //SOBREESCRIBIR UN ARCHIVO
    void crearArchivoVacio(){
        FILE *p;
        p = fopen(_nombre, "wb");
        if(p==NULL){
            cout << "No se pudo crear el archivo" << endl;
        }
        fclose(p);
    }

    //SOBREESCRIBIR UN ARCHIVO
    int crearArchivoNuevo(NotaDeCredito regNotaDeCredito){
        FILE *p;
        p = fopen(_nombre, "wb");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        int valor = fwrite (&regNotaDeCredito, sizeof regNotaDeCredito, 1, p);
        fclose(p);
        return valor;
    }

    ///LECTURA Y LISTADO

    //LECTURA DE REGISTROS EN UNA POSICI�N
    NotaDeCredito leerRegistro(int pos){
        NotaDeCredito regNotaDeCredito;
        //regNotaDeCredito.setCodigoClase(-1);
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return regNotaDeCredito;
        fseek(p, sizeof(NotaDeCredito)*pos,0);
        fread(&regNotaDeCredito, sizeof regNotaDeCredito,1, p);
        fclose(p);
        return regNotaDeCredito;
    }

    //LISTAR EL ARCHIVO COMPLETO
    bool listarRegistos(){
        NotaDeCredito regNotaDeCredito;
        FILE *p;
        p = fopen(_nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&regNotaDeCredito, sizeof regNotaDeCredito, 1, p)==1 ){
        regNotaDeCredito.MostrarNotaDeCreditoResumen();
        cout << endl;
        }
        fclose(p);
        return true;
    }

    ///CONTADO

    //CONTAR TOTAL DE REGISTROS
    int contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(NotaDeCredito);
    }

    ///BUSQUEDA

    //BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE LA POSICI�N
    int buscarRegistro(int codigo){
        NotaDeCredito regNotaDeCredito;
        FILE *p=fopen(_nombre,"rb");

        if(p==NULL){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO";
            return -2;
        }
        int pos=0;
        while(fread(&regNotaDeCredito,sizeof (NotaDeCredito),1,p)==1){
            if(regNotaDeCredito.getId()==codigo){
                cout<<"SE ENCONTRO UN REGISTRO CON ESE CODIGO:"<<endl<<endl;
                regNotaDeCredito.Mostrar();
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        return -1;
    }

    //BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE EL OBJETO
    NotaDeCredito buscarObjeto (int atributo){
        NotaDeCredito regNotaDeCredito;
        FILE *p=fopen(_nombre,"rb");
        //regNotaDeCredito.setAtributo(-1);
        if(p==NULL){
            return regNotaDeCredito;
        }
        while(fread(&regNotaDeCredito, sizeof (NotaDeCredito), 1,p) ==1){
            /*if(regNotaDeCredito.getAtributo() == atributo){
                fclose(p);
                return regNotaDeCredito;
            }*/
        }
        fclose(p);
        //regNotaDeCredito.setAtributo(-1);
        return regNotaDeCredito;
    }

    ///MODIFICACION

    //MODIFICAR UN REGISTRO
    bool modificarRegistro (NotaDeCredito regNotaDeCredito, int pos){
        FILE *p = fopen(_nombre, "rb+");
        if (p==NULL){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO";
            return -2;
        }
        fseek(p, pos*sizeof regNotaDeCredito, 0);
        bool escribio = fwrite (&regNotaDeCredito, sizeof regNotaDeCredito, 1, p);
        fclose(p);
        return escribio;
    }

    int verificarArchivoExistente() {
        DWORD atributos = GetFileAttributesA(_nombre); //obtiene los atributos del archivo especificado
        return (atributos != INVALID_FILE_ATTRIBUTES && //Si GetFileAttributesA retorna INVALID_FILE_ATTRIBUTES, significa que el archivo no existe o hay un error al intentar acceder a �l.
                !(atributos & FILE_ATTRIBUTE_DIRECTORY)); //Operacion "AND bit a bit" para verifica que el archivo no sea un directorio. V si lo es, F si no lo es.
    }

    void leerArchBin_escribirArchTxt(const char* path_ArchBin) {

        // Abrir archivo binario para lectura
        FILE* p = fopen(path_ArchBin, "rb");
        if (p==NULL){
            cout<<"FALLO EN LA APERTURA DEL ARCHIVO BINARIO PARA LECTURA";
            return;
        }

        // Leer y escribir cada registro a un archivo de texto individual
        NotaDeCredito regNotaDeCredito;
        int contador = 1;
        while (fread(&regNotaDeCredito, sizeof(NotaDeCredito), 1, p)) {
            // Crear nombre de archivo de texto
            char path_ArchTxt[50];
            snprintf(path_ArchTxt, sizeof(path_ArchTxt), "factura_%d.txt", contador);    //snprintf --> Genera una cadena formateada en un b�fer, asegurando que no se sobrepase el tama�o del b�fer.

            // Abrir archivo de texto para escritura
            FILE* q = fopen(path_ArchTxt, "w");
            if (q==NULL){
                cout<<"FALLO EN LA APERTURA DEL ARCHIVO DE TEXTO PARA ESCRITURA";
                fclose(p);
                return;
            }

            // Escribir el contenido del registro en el archivo de texto
            fprintf(q, "Nota de Credito:\nID: %d\nNombre: %s\nFecha: %s\nTotal: $%.2f\n\n",     //fprintf --> Escribe una cadena formateada en un archivo
                    regNotaDeCredito.getId(), regNotaDeCredito.getNombreCliente(), regNotaDeCredito.getFecha().toString(), regNotaDeCredito.getImporteTotal());
            fclose(q);
            contador++;
        }

        fclose(p);
        cout << "Archivos de texto creados exitosamente.\n";
    }
};

#endif // ARCHIVONOTADECREDITO_H_INCLUDED
