#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Articulo;
class ArchivoArticulo;

class Item{

private:

    int _nroItem;
    int _idArticulo;
    char _descripcion[40];
    float _precioUnitario;
    float _cantidad;
    float _importe;
    bool _estado;

    void calcularPrecioYImporte(float costo, int ganancia, int tipoCliente);

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

    // Constructor para crear items en facturas
    Item(Articulo& articulo, float cantidad, int tipoCliente);

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

    // Metodo para obtener el articulo original desde el archivo
    // Util para reconstruir informacion del catalogo si es necesario
    Articulo obtenerArticuloOriginal() const;

    void Cargar(Articulo regArticulo, int cantidad, int tipoCliente);
    void Mostrar();
    void escribirArchivoTexto(FILE *p);

};

// Metodo privado para calcular precio e importe segun tipo de cliente
void Item::calcularPrecioYImporte(float costo, int ganancia, int tipoCliente){
    float valorIVA = 1.21;

    // Tipo 1 y 2: Responsable Inscripto y Monotributo (IVA discriminado)
    // Tipo 3 y 4: Exento y Consumidor Final (IVA incluido)
    if (tipoCliente == 1 || tipoCliente == 2){
        _precioUnitario = costo * (1 + ganancia/100.0);
        _importe = _precioUnitario * _cantidad * valorIVA;
    } else {
        _precioUnitario = (costo * (1 + ganancia/100.0)) * valorIVA;
        _importe = _precioUnitario * _cantidad;
    }
}

// Constructor que crea un Item desde un Articulo
// Uso: Item item(articulo, cantidad, tipoCliente);
Item::Item(Articulo& articulo, float cantidad, int tipoCliente){
    _nroItem = 1; // Se ajusta luego al agregarlo al Detalle
    _idArticulo = articulo.getId();
    strcpy(_descripcion, articulo.getDescripcion());
    _cantidad = cantidad;

    calcularPrecioYImporte(articulo.getCosto(), articulo.getGanancia(), tipoCliente);

    _estado = true;
}

// Metodo para obtener el articulo original desde el archivo
// Retorna el Articulo actual del catalogo (puede tener datos actualizados)
Articulo Item::obtenerArticuloOriginal() const {
    ArchivoArticulo archivo;
    int pos = archivo.buscarSinMostrar(_idArticulo);

    if (pos != -1) {
        return archivo.leerArchivo(pos);
    }

    // Si no se encuentra, retorna un articulo vacio
    return Articulo();
}

// Metodo que mantiene compatibilidad con codigo existente
void Item::Cargar (Articulo regArticulo, int cantidad, int tipoCliente){
    _nroItem = 1;
    _idArticulo = regArticulo.getId();
    strcpy(_descripcion, regArticulo.getDescripcion());
    _cantidad = cantidad;

    calcularPrecioYImporte(regArticulo.getCosto(), regArticulo.getGanancia(), tipoCliente);

    _estado = true;
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
