#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED

class Detalle{

private:
    Item _detalleVenta[30]{};
    int _tamActual; // Tamaño actual del array
    bool _estado;

public:

    Detalle(){
        _tamActual = 0;
        _estado = false;
    }

    void setEstado(bool estado){_estado=estado;}
    void resetTamActual(){_tamActual=0;}

    int getTamActual() {return _tamActual; } //Método para obtener el tamaño del array
    bool getEstado() { return _estado; }
    //GETTER para obtener un item en una posición específica
    Item getItem(int pos) {
        if (pos >= 0 && pos <= _tamActual) {
            return _detalleVenta[pos];
        } else {
            cout << endl << "Posicion fuera de rango" << endl;
            return Item(); //Retorna un item vacío. Ver si es mejor hacer otra cosa cuando esta fuera de rango
        }
    }

    void Cargar ();
    void Mostrar ();

    void agregarItem(Item nuevoItem);
    void modificarItem(int pos, Item nuevoItem);
    void borrarItem(int pos);
};

void Detalle::Cargar(){

    int opcion;
    cout << "Desea cargar un item? (1-SI, 0-NO): ";
    cin >> opcion;

    while (opcion < 0 || opcion > 1){
        cout << "Opcion invalida. Pruebe otra vez."<<endl;
        cout << "Desea cargar un item? (1-SI, 0-NO): ";
        cin >> opcion;
    }

}

void Detalle::Mostrar(){
    for (int i=0; i<_tamActual; i++){
        _detalleVenta[i].Mostrar();
    }
}

    //AGREGA UN ITEM AL FINAL DEL VECTOR
void Detalle::agregarItem(Item nuevoItem) {
    if (_tamActual < 30) {
        _detalleVenta[_tamActual] = nuevoItem;
        _tamActual++;
    } else {
        cout << endl << "ATENCION. No se pudo cargar el Item ya que se ha alcanzado el maximo de items permitido."<< endl<<endl;// Ver que hacer cuando el array está lleno
    }
}

    //INGRESA UN ITEM EN UNA POSICION ESPECIFICA
void Detalle::modificarItem(int pos, Item nuevoItem) {
    if (pos >= 0 && pos <= _tamActual) {
        _detalleVenta[pos] = nuevoItem;
    } else {
        //VER QUE HACER SI ESTÁ FUERA DE RANGO
    }
}

    //BORRA UN ITEM DE UNA POSICION ESPECFICA
void Detalle::borrarItem(int pos){
    if (pos >= 0 && pos <= _tamActual) {
        int cantIteraciones = _tamActual - pos;
        for (int i=pos; i<cantIteraciones; i++){
            int nroItem = _detalleVenta[i].getNroItem();
            _detalleVenta[i] = _detalleVenta[i+1];
            _detalleVenta[i].setNroItem(nroItem);
        }
        _tamActual--;
    } else {
        //VER QUE HACER SI ESTÁ FUERA DE RANGO
    }
}

#endif // DETALLE_H_INCLUDED
