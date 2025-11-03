#ifndef EMISION_H_INCLUDED
#define EMISION_H_INCLUDED

///CLASE BASE: EMISION
class Emision{

private:
    int _idCliente;
    char _cuitCliente[13]; // (CUIT: XX-XXXXXXXX-X o bien DNI: XXXXXXXX)
    int _tipoCliente; // (1-Responsable Inscripto, 2-Monotributo, 3-Exento, 4-Cons.Final)
    char _nombreCliente[30];
    Direccion _direccionCliente;
    int _idVendedor;
    char _nombreVendedor[30];
    int _tipoCompra; // (1-Contado Directo, 2-Cuenta Corriente)
    char _condicionPago[35];
    Detalle _detalleVenta;
    float _importeSubtotal;
    float _importeIVA;
    float _importeTotal;
    Fecha _fecha;
    bool _estado;

public:

    //CONSTRUCTOR - DECLARACION Y DEFINICION
    Emision(){
        _idCliente=0;
        strcpy(_cuitCliente,"Sin Datos");
        _tipoCliente=0;
        strcpy(_nombreCliente,"Sin Datos");
        _idVendedor=0;
        strcpy(_nombreVendedor,"Sin Datos");
        _tipoCompra=0;
        strcpy(_condicionPago,"Sin Datos");
        _importeSubtotal=0;
        _importeIVA=0;
        _importeTotal=0;
        _estado=false;
    }

    void setIdCliente(int idCliente) { _idCliente = idCliente; }
    void setCuitCliente (const char* cuitCliente) {strcpy(_cuitCliente,cuitCliente);}
    void setTipoCliente(int tipoCliente) { _tipoCliente = tipoCliente; }
    void setDireccion(Direccion direccionCliente) { _direccionCliente = direccionCliente; }
    void setNombreCliente (const char* nombreCliente) {strcpy(_nombreCliente,nombreCliente);}
    void setIdVendedor(int idVendedor) { _idVendedor = idVendedor; }
    void setNombreVendedor (const char* nombreVendedor) {strcpy(_nombreVendedor,nombreVendedor);}
    void setTipoCompra(int tipoCompra) { _tipoCompra = tipoCompra; }
    void setCondicionPago (const char* condicionPago) {strcpy(_condicionPago,condicionPago);}
    void setDetalleVenta(Detalle detalle) { _detalleVenta = detalle; }
    void setImporteSubtotal(float importe) { _importeSubtotal = importe; }
    void setImporteIVA(float importe) { _importeIVA = importe; }
    void setImporteTotal(float importe) { _importeTotal = importe; }
    void setFecha(Fecha fecha) { _fecha = fecha; }
    void setEstado(bool estado){_estado=estado;}

    int getIdCliente() { return _idCliente; }
    const char* getCuitCliente() { return _cuitCliente; }
    int getTipoCliente() { return _tipoCliente; }
    const char* getNombreCliente() { return _nombreCliente; }
    Direccion getDireccionCliente(){ return _direccionCliente; }
    int getIdVendedor() { return _idVendedor; }
    const char* getNombreVendedor() { return _nombreVendedor; }
    int getTipoCompra() { return _tipoCompra; }
    const char* getCondicionPago() { return _condicionPago; }
    Detalle getDetalleVenta(){ return _detalleVenta; }
    float getImporteSubtotal() { return _importeSubtotal; }
    float getImporteIVA() { return _importeIVA; }
    float getImporteTotal() { return _importeTotal; }
    Fecha getFecha(){ return _fecha; }
    bool getEstado(){return _estado;}

    void Cargar();
    void Mostrar();
    void MostrarClienteEmision();
    void MostrarVendedorEmision();
    void MostrarDatosVentaEmision();
    void calcularImportes();
    void mostrarDetalleCompleto();

};

void Emision::Cargar(){

}

void Emision::Mostrar(){
    cout << "Fecha: ";
    _fecha.Mostrar();
    cout << endl << "---DATOS DEL CLIENTE:" << endl;
    cout << "ID: " << _idCliente << " - ";
    cout << "NOMBRE: " << _nombreCliente << endl;
    cout << "CUIT: " << _cuitCliente << " - ";
    cout << "Tipo de Cliente: " << _tipoCliente;
    if (_tipoCliente==1){
        cout << " - Responsable Inscripto.";
    } else if (_tipoCliente==2){
        cout << " - Monotributo.";
    } else if (_tipoCliente==3){
        cout << " - Exento.";
    } else if (_tipoCliente==4){
        cout << " - Cons.Final.";
    }
    cout << endl;
    cout << "Domicilio: ";
    _direccionCliente.Mostrar();
    cout << endl << "---DATOS DEL VENDEDOR:" << endl;
    cout << "ID: " << _idVendedor << " - ";
    cout << "NOMBRE: " << _nombreVendedor << endl;
    cout << endl << "---DATOS DE LA COMPRA:" << endl;
    cout << "Tipo Compra: " << _tipoCompra;
    if (_tipoCompra==1){
        cout << " - Contado Directo.";
    } else if (_tipoCompra==2){
        cout << " - Cuenta Corriente.";
    }
    cout << " - Condicion de pago: " << _condicionPago << endl << endl;
    //DETALLE DE LA VENTA
    mostrarDetalleCompleto();
    cout << endl;
}

void Emision::MostrarClienteEmision(){
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "El cliente actual es:" << endl;
    cout << "\t ID: " << _idCliente << endl;
    cout << "\t Nombre: " << _nombreCliente << endl;
    cout << "\t CUIT: " << _cuitCliente << endl;
    cout << "\t Tipo: " << _tipoCliente << " - ";
    if (_tipoCliente == 1){
        cout << "Responsable Inscripto";
    } else if (_tipoCliente == 2){
        cout << "Monotributo";
    } else if (_tipoCliente == 3){
        cout << "Exento";
    } else if (_tipoCliente == 4){
        cout << "Consumidor Final";
    }
    cout << endl << "\t Direccion: ";
    _direccionCliente.Mostrar();
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
}

void Emision::MostrarVendedorEmision(){
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "El vendedor actual es:"<<endl;
    cout << "\t ID: " << getIdVendedor() << endl;
    cout << "\t Nombre: " << getNombreVendedor() << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
}

void Emision::MostrarDatosVentaEmision(){
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Los datos de venta seleccionados actualmente:" << endl;
    cout << "\t Tipo de compra: ";
    if (getTipoCompra() == 1){
        cout << "Contado Directo" << endl;
    } else{
        cout << "Cuenta Corriente" << endl;
    }
    cout << "\t Condicion de Pago: " << getCondicionPago() << endl;
}

void Emision::calcularImportes(){
//IMPORTE SUBTOTAL
    _importeSubtotal = 0;
    float tipoIVA;
    if (_tipoCliente==1 || _tipoCliente==2){
        tipoIVA = 1.21;
    } else{
        tipoIVA = 1;
    }

    for (int i=0; i<_detalleVenta.getTamActual(); i++){
        _importeSubtotal += (_detalleVenta.getItem(i).getImporte()/tipoIVA);
    }

//IMPORTE NETO IVA
    _importeIVA = 0;

    if (_tipoCliente==1 || _tipoCliente==2){
        tipoIVA = 0.21;
    } else{
        tipoIVA = 0;
    }

    for (int i=0; i<_detalleVenta.getTamActual(); i++){
        _importeIVA +=((_detalleVenta.getItem(i).getImporte()/1.21)*tipoIVA);
    }

//IMPORTE TOTAL
    _importeTotal = _importeSubtotal + _importeIVA;



}

    //MUESTRA EL DETALLE COMPLETO (UNIVERSAL: FACTURA, NOTA DE CR�DITO, PRESUPUESTO)
void Emision::mostrarDetalleCompleto(){
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "DETALLE DE VENTA" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    //ENCABEZADO DETALLE
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;
    cout << left << setw(5) << "Item";
    cout << right << setw(11) << "Cantidad  ";
    cout << left << setw(9) << "Cod.Art. " << setw(55) << "Descripcion";
    cout << right << setw(14) << "P.Unitario    " << setw(11) << "Importe" << endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;
    //DETALLE
    _detalleVenta.Mostrar();
    //IMPORTES
    cout << endl;
    cout << left << setw(15) << "Subtotal:" << setw(1) << "$";
    cout << right << setw(15) << _importeSubtotal << endl;
    cout << left << setw(15) << "Neto IVA:" <<  setw(1) << "$";
    cout << right << setw(15) << _importeIVA << endl;
    cout << setfill('-') << setw(31) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "TOTAL:" <<  setw(1) << "$";
    cout << right << setw(15) << _importeTotal << endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;

}

#endif // EMISION_H_INCLUDED
