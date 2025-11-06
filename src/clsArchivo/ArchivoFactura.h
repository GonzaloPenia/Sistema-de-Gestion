#ifndef ARCHIVOFACTURA_H_INCLUDED
#define ARCHIVOFACTURA_H_INCLUDED

///CLASE ARCHIVO: FACTURA
class ArchivoFactura{

private:
    char nombre[20];

public:
    ArchivoFactura(const char *n="../../data/facturas.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }
    const char *getNombre(){return nombre;}

    void leerArchivo();
    int agregarRegistro();
    int agregarRegistro(Factura reg);
    void crearArchivoVacio();
    int crearArchivoNuevo(Factura reg);
    Factura leerRegistro(int pos);
    bool listarRegistos();
    int contarRegistros();
    int buscarRegistro(int codigo);
    Factura buscarObjeto (int atributo);
    bool modificarRegistro (Factura regFactura, int pos);
    int verificarArchivoExistente();
    void leerArchBin_escribirArchTxt(const char* path_ArchBin);
};

void ArchivoFactura::leerArchivo(){
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

///ESCRITURA
//AGREGAR UN NUEVO REGISTRO AL FINAL DEL ARCHIVO
//SIN RECIBIR PARAMETROS. PIDE QUE SE CARGUE MIENTRAS SE EJECUTA.
int ArchivoFactura::agregarRegistro(){
    Factura reg;
    FILE *p;
    p = fopen(nombre, "ab");
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
int ArchivoFactura::agregarRegistro(Factura reg){
    FILE *p;
    p = fopen(nombre, "ab");
    if(p==NULL){
    cout << "No se pudo abrir o crear el archivo" << endl;
    return -1;
    }
    int valor = fwrite (&reg, sizeof reg, 1, p);
    fclose(p);
    return valor;
}

    //SOBREESCRIBIR UN ARCHIVO
void ArchivoFactura::crearArchivoVacio(){
    FILE *p;
    p = fopen(nombre, "wb");
    if(p==NULL){
        cout << "No se pudo crear el archivo" << endl;
    }
    fclose(p);
}

//SOBREESCRIBIR UN ARCHIVO
int ArchivoFactura::crearArchivoNuevo(Factura reg){
    FILE *p;
    p = fopen(nombre, "wb");
    if(p==NULL){
    cout << "No se pudo abrir o crear el archivo" << endl;
    return -1;
    }
    int valor = fwrite (&reg, sizeof reg, 1, p);
    fclose(p);
    return valor;
}

//LECTURA DE REGISTROS EN UNA POSICION
Factura ArchivoFactura::leerRegistro(int pos){
    Factura reg;
    //reg.setCodigoClase(-1);
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof(Factura)*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}

//LISTAR EL ARCHIVO COMPLETO
bool ArchivoFactura::listarRegistos(){
    Factura reg;
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL){
    cout << "NO SE PUDO ACCEDER AL ARCHIVO FACTURAS.DAT" << endl;
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
int ArchivoFactura::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Factura);
}

///BUSQUEDA

//BUSCAR UN REGISTRO EN BASE A UN CODIGO/ATRIBUTO - DEVUELVE LA POSICI�N
int ArchivoFactura::buscarRegistro(int codigo){
    Factura regFactura;
    FILE *p=fopen(nombre,"rb");

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

Factura ArchivoFactura::buscarObjeto (int atributo){
    Factura obj;
    FILE *p=fopen(nombre,"rb");

    return obj;

}

///MODIFICACION

//MODIFICAR UN REGISTRO
bool ArchivoFactura::modificarRegistro (Factura regFactura, int pos){
    FILE *p = fopen(nombre, "rb+");
    if (p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO";
        return -2;
    }
    fseek(p, pos*sizeof regFactura, 0);
    bool escribio = fwrite (&regFactura, sizeof regFactura, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoFactura::verificarArchivoExistente() {
    DWORD atributos = GetFileAttributesA(nombre); //obtiene los atributos del archivo especificado
    return (atributos != INVALID_FILE_ATTRIBUTES && //Si GetFileAttributesA retorna INVALID_FILE_ATTRIBUTES, significa que el archivo no existe o hay un error al intentar acceder a �l.
            !(atributos & FILE_ATTRIBUTE_DIRECTORY)); //Operacion "AND bit a bit" para verifica que el archivo no sea un directorio. V si lo es, F si no lo es.
}

void ArchivoFactura::leerArchBin_escribirArchTxt(const char* path_ArchBin) {

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


#endif // ARCHIVOFACTURA_H_INCLUDED