#ifndef CLSPROVEEDOR_H_INCLUDED
#define CLSPROVEEDOR_H_INCLUDED


void listarContactosPorEntidadAux(int idEntidad);

class Proveedor: public Entidad{
    private:
        int _id;
        int _cantidad_compras;
        //bool _estado;
    public:

    Proveedor(){}

    Proveedor(char,Direccion, Contacto, bool , int, int, bool); //CONSTRUCTOR DE LA CLASE PROVEEDOR

    Proveedor(int id, int cantidad_compras, char nombre, Direccion direccion){
        _id=id;
        _cantidad_compras=cantidad_compras;
        _estado=true;
        _nombre[50]=nombre;
        _direccion=direccion;
        // _contacto=contacto; // OBSOLETO - contactos ahora son independientes
        _estado=true;
    }

    //////INICIO DE SETS Y GETS

    int getId(){return _id;}
    int getCantidadCompras(){return _cantidad_compras;}

    void setId(const int p){_id=p;}
    void setCantidadCompras(const int cc){_cantidad_compras=cc;}
    void setEstado(const bool e){_estado=e;}

    void Mostrar();
    void Mostrar(bool);
    void Cargar(int identificador);
};

void Proveedor::Cargar(int identificador){
    _id=identificador;
    setId(_id);

    Entidad::Cargar();

    cout<<"CANTIDAD DE COMPRAS REALIZADAS A ESTE PROVEEDOR: ";
    cin>>_cantidad_compras;
    setCantidadCompras(_cantidad_compras);

    setEstado(true);
}

void Proveedor::Mostrar(){

    cout<<"ID PROVEEDOR: "<<_id<<endl;
    cout<<"NOMBRE PROVEEDOR: "<<_nombre<<endl;
    cout<<"CANTIDAD DE COMPRAS REALIZADAS: "<<_cantidad_compras<<endl;
    cout<<endl;
    _direccion.Mostrar();
    cout<<endl;
    cout<<"CONTACTOS DEL PROVEEDOR:"<<endl;
    listarContactosPorEntidadAux(_id);
    cout<<endl;
}
void Proveedor::Mostrar(bool){

    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
    cout << left << setw(5) << _id << setw(55) << _nombre << setw(15) << _cantidad_compras << endl << endl;

}
#endif // CLSPROVEEDOR_H_INCLUDED
