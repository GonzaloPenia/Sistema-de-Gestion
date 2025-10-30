#ifndef ARCHIVOPRESUPUESTO_H_INCLUDED
#define ARCHIVOPRESUPUESTO_H_INCLUDED

///CLASE ARCHIVO: FACTURA
class ArchivoPresupuesto{

private:
    char _nombre[20];

public:

    ///CONSTRUCTOR
    ArchivoPresupuesto(){strcpy(_nombre,"../data/presupuestos.dat");}
    //ArchivoPresupuesto(const char* nombre){ strcpy(_nombre, nombre); }

    ///M�TODOS
    int AgregarRegistro();
    int AgregarRegistro(Presupuesto regPresupuesto);
    void crearArchivoVacio();
    int crearArchivoNuevo(Presupuesto regPresupuesto);
    Presupuesto leerRegistro(int pos);
    bool listarRegistos();
    int contarRegistros();
    int buscarRegistro(int codigo);
    Presupuesto buscarObjeto (int atributo);
    bool modificarRegistro (Presupuesto regPresupuesto, int pos);
    int verificarArchivoExistente();

};

    ///ESCRITURA

    //AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
    //SIN RECIBIR PARAMETROS. PIDE QUE SE CARGUE MIENTRAS SE EJECUTA
    int ArchivoPresupuesto::AgregarRegistro(){
        Presupuesto regPresupuesto;
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        regPresupuesto.Cargar();
        int valor = fwrite (&regPresupuesto, sizeof regPresupuesto, 1, p);
        fclose(p);
        return valor;
    }

    //AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
    //RECIBE UN OBJETO Y LO AGREGA
    int ArchivoPresupuesto::AgregarRegistro(Presupuesto regPresupuesto){
        FILE *p;
        p = fopen(_nombre, "ab");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        int valor = fwrite (&regPresupuesto, sizeof regPresupuesto, 1, p);
        fclose(p);
        return valor;
    }

    //SOBREESCRIBIR UN ARCHIVO
    void ArchivoPresupuesto::crearArchivoVacio(){
        FILE *p;
        p = fopen(_nombre, "wb");
        if(p==NULL){
            cout << "No se pudo crear el archivo" << endl;
        }
        fclose(p);
    }

    //SOBREESCRIBIR UN ARCHIVO
    int ArchivoPresupuesto::crearArchivoNuevo(Presupuesto regPresupuesto){
        FILE *p;
        p = fopen(_nombre, "wb");
        if(p==NULL){
        cout << "No se pudo abrir o crear el archivo" << endl;
        return -1;
        }
        int valor = fwrite (&regPresupuesto, sizeof regPresupuesto, 1, p);
        fclose(p);
        return valor;
    }

    ///LECTURA Y LISTADO

    //LECTURA DE REGISTROS EN UNA POSICI�N
    Presupuesto ArchivoPresupuesto::leerRegistro(int pos){
        Presupuesto regPresupuesto;
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL){
            cout << endl << "ERROR AL INGRESAR AL ARCHIVO." << endl << endl;
            return regPresupuesto;
        } else {
            fseek(p, sizeof(Presupuesto)*(pos-1),0);
            fread(&regPresupuesto, sizeof regPresupuesto,1, p);
            //cout << endl << "Se ha encontrado un presupuesto." << endl << endl;
        }
        fclose(p);
        return regPresupuesto;
    }

    //LISTAR EL ARCHIVO COMPLETO
    bool ArchivoPresupuesto::listarRegistos(){
        Presupuesto regPresupuesto;
        FILE *p;
        p = fopen(_nombre, "rb");
        if (p == NULL){
        cout << "No se pudo abrir " << endl;
        return false;
        }
        while (fread(&regPresupuesto, sizeof regPresupuesto, 1, p)==1 ){
        regPresupuesto.MostrarPresupuestoEmitido();
        cout << endl;
        }
        fclose(p);
        return true;
    }

    ///CONTADO

    //CONTAR TOTAL DE REGISTROS
    int ArchivoPresupuesto::contarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Presupuesto);
    }

    ///BUSQUEDA

    //BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE LA POSICI�N
    int ArchivoPresupuesto::buscarRegistro(int codigo){
        Factura regPresupuesto;
        FILE *p=fopen(_nombre,"rb");

        if(p==NULL){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO";
            return -2;
        }
        int pos=0;
        while(fread(&regPresupuesto,sizeof (Factura),1,p)==1){
            if(regPresupuesto.getId()==codigo){
                cout<<"SE ENCONTRO UN REGISTRO CON ESE CODIGO:"<<endl<<endl;
                regPresupuesto.Mostrar();
                fclose(p);
                return pos;
            }
            pos++;
        }
        fclose(p);
        return -1;
    }

    //BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE EL OBJETO
    Presupuesto ArchivoPresupuesto::buscarObjeto (int atributo){
        Presupuesto regPresupuesto;
        FILE *p=fopen(_nombre,"rb");
        //regPresupuesto.setAtributo(-1);
        if(p==NULL){
            return regPresupuesto;
        }
        while(fread(&regPresupuesto, sizeof (Presupuesto), 1,p) ==1){
            /*if(regPresupuesto.getAtributo() == atributo){
                fclose(p);
                return regPresupuesto;
            }*/
        }
        fclose(p);
        //regPresupuesto.setAtributo(-1);
        return regPresupuesto;
    }

    ///MODIFICACION

    //MODIFICAR UN REGISTRO
    bool ArchivoPresupuesto::modificarRegistro (Presupuesto regPresupuesto, int pos){
        FILE *p = fopen(_nombre, "rb+");
        if (p==NULL){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO";
            return -2;
        }
        fseek(p, pos*sizeof regPresupuesto, 0);
        bool escribio = fwrite (&regPresupuesto, sizeof regPresupuesto, 1, p);
        fclose(p);
        return escribio;
    }

    int ArchivoPresupuesto::verificarArchivoExistente() {
        DWORD atributos = GetFileAttributesA(_nombre); //obtiene los atributos del archivo especificado
        return (atributos != INVALID_FILE_ATTRIBUTES && //Si GetFileAttributesA retorna INVALID_FILE_ATTRIBUTES, significa que el archivo no existe o hay un error al intentar acceder a �l.
                !(atributos & FILE_ATTRIBUTE_DIRECTORY)); //Operacion "AND bit a bit" para verifica que el archivo no sea un directorio. V si lo es, F si no lo es.
    }


#endif // ARCHIVOPRESUPUESTO_H_INCLUDED
