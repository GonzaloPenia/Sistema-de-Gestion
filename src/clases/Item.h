#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item{

private:

    int _nroItem;
    int _idArticulo;
    char _descripcion[40];
    float _precioUnitario;
    float _cantidad;
    float _importe;
    bool _estado;

public:

    Item (){
        _nroItem = 0;
        _idArticulo=0;
        strcpy(_descripcion,"");
        _precioUnitario=0;
        _cantidad=0;
        _importe=0;
        _estado=false;
    }

    void setNroItem(int nroItem) { _nroItem = nroItem; }
    void setIdArticulo(int idArticulo) { _idArticulo = idArticulo; }
    void setDescripcion (const char* descripcion) {strcpy(_descripcion,descripcion);}
    void setPrecioUnitario(float precioUnitario) { _precioUnitario = precioUnitario; }
    void setCantidad(float cantidad) { _cantidad = cantidad; }
    void setImporte(float importe) { _importe = importe; }
    void setEstado(bool estado){_estado=estado;}

    int getNroItem() { return _nroItem; }
    int getIdArticulo() { return _idArticulo; }
    const char* getDescripcion() { return _descripcion; }
    float getPrecioUnitario() { return _precioUnitario; }
    float getCantidad() { return _cantidad; }
    float getImporte() { return _importe; }
    bool getEstado() { return _estado; }

    void Cargar(Articulo regArticulo, int cantidad, int tipoCliente);
    void Mostrar();
    void escribirArchivoTexto(FILE *p);

};

void Item::Cargar (Articulo regArticulo, int cantidad, int tipoCliente){
    float valorIVA = 1.21;
    _nroItem = 1;
    _idArticulo=regArticulo.getId();
    strcpy(_descripcion,regArticulo.getDescripcion());
    _cantidad=cantidad;

    int costo = regArticulo.getCosto();
    int ganancia = regArticulo.getGanancia();
    
    if (tipoCliente == 1 || tipoCliente == 2){    
        _precioUnitario= costo * ( 1 + ganancia/100.0 );
        _importe=_precioUnitario*cantidad*valorIVA;
    } else {
        _precioUnitario=(costo * ( 1 + ganancia/100.0 ) )* valorIVA;
        _importe=_precioUnitario*cantidad;
    }

    _estado=true;
}

void Item::Mostrar (){
    cout << fixed << setprecision(2);
    cout << right << setw(3) << _nroItem << setw(2) << " " << setw(9) << _cantidad << setw(2) << " "
                  << setw(7) << _idArticulo << setw(2) << " ";
    cout << left << setw(55) << _descripcion;
    cout << right << setw(10) << _precioUnitario << setw(4) << " " << setw(11) << _importe << endl;
}

void Item::escribirArchivoTexto(FILE *p) {
    fprintf(p,"%3d%2s%9.2f%2s%7d%2s%-55s%10.2f%4s%11.2f\n", _nroItem, " ", _cantidad, " ", _idArticulo, " ", _descripcion, _precioUnitario, " ", _importe);
}

#endif // ITEM_H_INCLUDED
