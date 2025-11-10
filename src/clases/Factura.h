#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include <sstream>  // Para stringstream

///CLASE DERIVADA DE EMISION: FACTURA
class Factura : public Emision{

private:
    int _id;

public:
    Factura(){
        _id = 0;
    }

    int getId(){return _id;}
    void setId(int id){_id=id;}

    bool Cargar(){
        Emision::Cargar();
        return true; //TRUE CONFIRMA QUE SE CARGO LA FACTURA
    }

    void Mostrar(){ Emision::Mostrar(); }

    void MostrarFacturaEmitida();
    void MostrarFacturaResumen();
    void MostrarFacturaArticulo(int posArticulo);

};

void Factura::MostrarFacturaEmitida(){
    cout << "Factura Nro.: " << _id << endl << endl;
    Emision::Mostrar();
}

void Factura::MostrarFacturaResumen(){
    cout << fixed << setprecision(2);
    cout << left << setw(14) << getFecha().toString();
    cout << right << setw(6) << getId() << setw(4) << " " << setw(10) << getIdCliente() << setw(2) << " ";
    cout << left << setw(55) << getNombreCliente();
    cout << right << setw(11) << getImporteTotal() << endl;
}

void Factura::MostrarFacturaArticulo(int posArticulo){
    cout << fixed << setprecision(2);
    cout << left << setw(14) << getFecha().toString();
    cout << right << setw(6) << getId() << setw(4) << " " << setw(10) << getIdCliente() << setw(2) << " ";
    cout << left << setw(55) << getNombreCliente() << setw(9) << getIdVendedor();
    cout << right << setw(9) << getDetalleVenta().getItem(posArticulo).getCantidad()
                  << setw(11) << getDetalleVenta().getItem(posArticulo).getImporte() << endl;
}



#endif // FACTURA_H_INCLUDED
