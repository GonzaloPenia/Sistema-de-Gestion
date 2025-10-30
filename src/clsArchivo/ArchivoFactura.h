#ifndef ARCHIVOFACTURA_H_INCLUDED
#define ARCHIVOFACTURA_H_INCLUDED

///CLASE ARCHIVO: FACTURA
class ArchivoFactura{

private:
    char _nombre[20];

public:

    ArchivoFactura(){strcpy(_nombre,"../data/facturas.dat");}

///M�TODOS

    ///ESCRITURA

    //AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
    //SIN RECIBIR PARAMETROS. PIDE QUE SE CARGUE MIENTRAS SE EJECUTA
    int AgregarRegistro(){
        Factura reg;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        reg.Cargar();
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }

    //AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
    //RECIBE UN OBJETO Y LO AGREGA
    int AgregarRegistro(Factura reg){
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        int valor = fwrite (&reg, sizeof reg, 1, p);
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
    int crearArchivoNuevo(Factura reg){
        FILE *p;
        p = fopen(_nombre, "wb");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        int valor = fwrite (&reg, sizeof reg, 1, p);
        fclose(p);
        return valor;
    }

    ///LECTURA Y LISTADO

    //LECTURA DE REGISTROS EN UNA POSICI�N
    Factura leerRegistro(int pos){
        Factura reg;
        //reg.setCodigoClase(-1);
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof(Factura)*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

    //LISTAR EL ARCHIVO COMPLETO
    bool listarRegistos(){
        Factura reg;
        FILE *p;
        p = fopen(_nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&reg, sizeof reg, 1, p)==1 ){
        reg.MostrarFacturaResumen();
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
        return tam/sizeof(Factura);
    }

    ///BUSQUEDA

    //BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE LA POSICI�N
    int buscarRegistro(int codigo){
        Factura regFactura;
        FILE *p=fopen(_nombre,"rb");

        if(p==NULL){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO";
            return -2;
        }
        int pos=0;
        while(fread(&regFactura,sizeof (Factura),1,p)==1){
            if(regFactura.getId()==codigo){
                cout<<"SE ENCONTRO UN REGISTRO CON ESE CODIGO:"<<endl<<endl;
                regFactura.Mostrar();
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        return -1;
    }

    //BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE EL OBJETO
    Factura buscarObjeto (int atributo){
        Factura obj;
        FILE *p=fopen(_nombre,"rb");
        //obj.setAtributo(-1);
        if(p==NULL){
            return obj;
        }
        while(fread(&obj, sizeof (Factura), 1,p) ==1){
            /*if(obj.getAtributo() == atributo){
                fclose(p);
                return obj;
            }*/
        }
        fclose(p);
        //obj.setAtributo(-1);
        return obj;
    }

    ///MODIFICACION

    //MODIFICAR UN REGISTRO
    bool modificarRegistro (Factura regFactura, int pos){
        FILE *p = fopen(_nombre, "rb+");
        if (p==NULL){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO";
            return -2;
        }
        fseek(p, pos*sizeof regFactura, 0);
        bool escribio = fwrite (&regFactura, sizeof regFactura, 1, p);
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
        Factura regFactura;
        int contador = 1;
        while (fread(&regFactura, sizeof(Factura), 1, p)) {
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
            fprintf(q, "Factura:\nID: %d\nNombre: %s\nFecha: %s\nTotal: $%.2f\n\n",     //fprintf --> Escribe una cadena formateada en un archivo
                    regFactura.getId(), regFactura.getNombreCliente(), regFactura.getFecha().toString(), regFactura.getImporteTotal());
            fclose(q);
            contador++;
        }

        fclose(p);
        cout << "Archivos de texto creados exitosamente."<<endl<<endl;
    }
};

#endif // ARCHIVOFACTURA_H_INCLUDED
