#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED

class Articulo{
private:
    int id;
    //char nombre[30];
    int unidades;
    char descripcion[50];
    float costo;
    int ganancia;
    float precio_venta;
    Fecha ultima_actualizacion_precio;
    Proveedor proveedor;
    bool estado;

public:
    Articulo(const char *n="NOMBRE"){ //CONSTRUCTOR
        strcpy(descripcion, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }

    Articulo(Fecha aux){
        ultima_actualizacion_precio=aux;
        estado=true;
    }

    Articulo(int d, int m, int a){ //CONSTRUCTOR
        ultima_actualizacion_precio.setDia(d);
        ultima_actualizacion_precio.setMes(m);
        ultima_actualizacion_precio.setAnio(a);
        estado=true;
    }

    int getId(){return id;}
    //const char* getNombre(){return nombre;}
    int getUnidades(){return unidades;}
    const char* getDescripcion(){return descripcion;}
    int getCosto(){return costo;}
    int getGanancia(){return ganancia;}
    int getPrecioVenta(){return precio_venta;}
    Fecha getUltimaActualizacionPrecio(){return ultima_actualizacion_precio;}
    Proveedor getProveedor(){return proveedor;}
    bool getEstado(){return estado;}

    void setId(const int i){id=i;}
    //void setNombre(const char *n){strcpy(nombre,n);}
    void setUnidades(const int u){unidades=u;}
    void setDescripcion(const char *d){strcpy(descripcion, d);}
    void setCosto(const int c){costo=c;}
    void setGananacia(const int g){ganancia=g;}
    void setPrecioVenta(const int pv){precio_venta=pv;}
    void setUltimaActualizacionPrecio(Fecha fa){ultima_actualizacion_precio=fa;}
    void setProveedor(Proveedor p){proveedor=p;}
    void setEstado(bool est){estado=est;}


    bool Cargar(int id);
    bool Cargar(int id, Proveedor auxProveedor);

    void Mostrar();
};

bool Articulo::Cargar(int identificador){

    setId(identificador);
    cout<<"DESCRIPCION DEL ARTICULO: ";
    cargarCadena(descripcion,49);
    cout<<"CANTIDAD DE UNIDADES EN STOCK: ";
    cin>>unidades;
    cout<<"PRECIO DE COSTO: $";
    cin>>costo;
    cout<<"MARGEN DE GANANCIA (%): "; //PORCENTAJE
    cin>>ganancia;
    cout<<"PRECIO VENTA: $";
    precio_venta=costo * (1+ganancia/100.0);
    cout << precio_venta<< endl;
    cout<<"FECHA DE ACTUALIZACION DE PRECIO: ";
    ultima_actualizacion_precio.cargarFechaSistema();
    ultima_actualizacion_precio.Mostrar();


    cout<<"ID DEL PROVEEDOR: ";
    ArchivoProveedor regArchivoProveedor;
    bool repetido;
    int id_proveedor;
    cin>>id_proveedor;
    repetido = regArchivoProveedor.verificarRepetido(id_proveedor);
    while (repetido==true)
    {
        if(repetido){
        system ("cls");
        cout<<"ESTAS INTENTANDO USAR UN ID QUE YA ESTA SIENDO UTILIZADO, PRUEBA UNO DIFERENTE"<<endl<<endl;
        cin>>id_proveedor;
        repetido = regArchivoProveedor.verificarRepetido(id_proveedor);
        }
    }

    proveedor.Cargar(id_proveedor);

    estado=true;
    return true; //TRUE CONFIRMA QUE SE CARGO EL USUARIO
}

bool Articulo::Cargar(int identificador, Proveedor auxProveedor){
    setId(identificador);
    cout<<"DESCRIPCION DEL ARTICULO: ";
    cargarCadena(descripcion,49);
    cout<<"CANTIDAD DE UNIDADES EN STOCK: ";
    cin>>unidades;
    cout<<"PRECIO DE COSTO: $";
    cin>>costo;
    cout<<"MARGEN DE GANANCIA (%): "; //PORCENTAJE
    cin>>ganancia;
    cout<<"PRECIO VENTA: $";
    precio_venta=costo * (1+ganancia/100.0);
    cout << precio_venta<< endl;
    cout<<"FECHA DE ACTUALIZACION DE PRECIO: ";
    ultima_actualizacion_precio.cargarFechaSistema();
    ultima_actualizacion_precio.Mostrar();

    setProveedor(auxProveedor);

    estado=true;
    return true; //TRUE CONFIRMA QUE SE CARGO EL USUARIO
}

void Articulo::Mostrar(){
    if(estado==true)
    {
        cout<<endl;
        cout<<"ID: ";
        cout<<id<<endl;
        cout<<"DESCRIPCION: ";
        cout<<descripcion<<endl;
        cout<<"CANTIDAD DE UNIDADES: ";
        cout<<unidades<<endl;
        cout<<"COSTO: ";
        cout<<costo<<endl;
        cout<<"GANANCIA (%): "; //PORCENTAJE
        cout<<ganancia<<endl;
        cout<<"PRECIO VENTA: ";
        cout<<precio_venta<<endl;
        cout<<"ULTIMA FECHA ACTUALIZACION DE PRECIO: ";
        ultima_actualizacion_precio.Mostrar();
        proveedor.Mostrar();
    }
}

#endif // CLSARTICULO_H_INCLUDED
