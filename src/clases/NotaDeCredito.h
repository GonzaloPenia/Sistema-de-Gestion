#ifndef NOTADECREDITO_H_INCLUDED
#define NOTADECREDITO_H_INCLUDED

///CLASE DERIVADA DE EMISION: NOTA DE CR�DITO
class NotaDeCredito : public Emision{

private:
    int _id;

public:
    NotaDeCredito(){
        _id = 0;
    }

    int getId(){return _id;}
    void setId(int id){_id=id;}

    bool Cargar(){
        Emision::Cargar();
        return true; //TRUE CONFIRMA QUE SE CARGO LA FACTURA
    }

    void Mostrar(){ Emision::Mostrar();}

    void MostrarNotaDeCreditoEmitida();
    void MostrarNotaDeCreditoResumen();
    void MostrarNotaDeCreditoArticulo(int posArticulo);

    void escribirEnArchivoTexto();
};

void NotaDeCredito::MostrarNotaDeCreditoEmitida(){
    cout << "Nota de Credito Nro.: " << _id << endl << endl;
    Emision::Mostrar();
}

void NotaDeCredito::MostrarNotaDeCreditoResumen(){
    cout << fixed << setprecision(2);
    cout << left << setw(14) << getFecha().toString();
    cout << right << setw(6) << getId() << setw(4) << " " << setw(10) << getIdCliente() << setw(2) << " ";
    cout << left << setw(55) << getNombreCliente();
    cout << right << setw(11) << getImporteTotal() << endl;
}

void NotaDeCredito::MostrarNotaDeCreditoArticulo(int posArticulo){
    cout << fixed << setprecision(2);
    cout << left << setw(14) << getFecha().toString();
    cout << right << setw(6) << getId() << setw(4) << " " << setw(10) << getIdCliente() << setw(2) << " ";
    cout << left << setw(55) << getNombreCliente() << setw(9) << getIdVendedor();
    cout << right << setw(9) << getDetalleVenta().getItem(posArticulo).getCantidad()
                  << setw(11) << getDetalleVenta().getItem(posArticulo).getImporte() << endl;
}

void NotaDeCredito::escribirEnArchivoTexto() {
    const char* carpeta = "../output/NOTAS DE CREDITO";

    if (_mkdir(carpeta) != 0) {
        // La carpeta ya existe o hay un error
    }

    char nombre_ArchTxt[100];
    snprintf(nombre_ArchTxt, sizeof(nombre_ArchTxt), "%s/notaDeCredito_%d.txt", carpeta, getId());

    FILE* p = fopen(nombre_ArchTxt, "w");
    if (p==NULL){
        cout<<"FALLO EN LA APERTURA DEL ARCHIVO DE TEXTO PARA ESCRITURA";
        return;
    }

    ///DATOS GENERALES --> Faltan datos de empresa
    fprintf(p, "Nota De Credito Nro.: %d\t", getId());
    fprintf(p, "Fecha: %s\n\n", getFecha().toString().c_str());

    ///DATOS DEL CLIENTE
    fprintf(p, "\tDATOS DEL CLIENTE:\n");
    fprintf(p, "Nro. ID: %d - ", getIdCliente());
    fprintf(p, "Nombre: %s - ", getNombreCliente());
    fprintf(p, "CUIT: %s\n", getCuitCliente());
    fprintf(p, "Tipo de Cliente: %d - ", getTipoCliente());
    if (getTipoCliente()==1){
        fprintf(p, "Responsable Inscripto.");
    } else if (getTipoCliente()==2){
        fprintf(p, "Monotributo.");
    } else if (getTipoCliente()==3){
        fprintf(p, "Exento.");
    } else if (getTipoCliente()==4){
        fprintf(p, "Cons.Final.");
    }
    fprintf(p, "\nDomicilio: %s\n\n", getDireccionCliente().toString().c_str());

    ///DATOS DEL VENDEDOR
    fprintf(p, "\tDATOS DEL VENDEDOR:\n");
    fprintf(p, "Nro. ID: %d - ", getIdVendedor());
    fprintf(p, "Nombre: %s\n\n", getNombreVendedor());

    ///DATOS DE LA VENTA
    fprintf(p, "\tDATOS DE LA VENTA:\n");
    fprintf(p, "Tipo de Venta: %d - ", getTipoCompra());
    if (getTipoCompra()==1){
        fprintf(p, "Contado Directo.");
    } else if (getTipoCompra()==2){
        fprintf(p, "Cuenta Corriente.");
    }
    fprintf(p, "\nCondicion de Pago: %s\n\n", getCondicionPago());

    ///DATOS DEL DETALLE DE VENTA
    //ENCABEZADO
    stringstream lineaCompleta;
    stringstream lineaImporte;
    fprintf(p, "\tDETALLE DE VENTA:\n");
    lineaCompleta << setfill('-') << setw(106) << "-";
    fprintf(p, "%s\n", lineaCompleta.str().c_str());
    fprintf(p, "%-5s%11s%-9s%-55s%14s%11s\n", "Item", "Cantidad  ", "Cod.Art. ", "Descripcion", "P.Unitario    ", "Importe");
    fprintf(p, "%s\n", lineaCompleta.str().c_str());

    //DETALLE
    for (int i = 0; i < getDetalleVenta().getTamActual(); ++i) {
        getDetalleVenta().getItem(i).escribirArchivoTexto(p);
    }

    //IMPORTES
    fprintf(p, "\n%-11s", "Subtotal: ");
    fprintf(p, "%11.2f\n", getImporteSubtotal());
    fprintf(p, "%-11s", "Neto IVA: ");
    fprintf(p, "%11.2f\n", getImporteIVA());
    lineaImporte << setfill('-') << setw(31) << "-";
    fprintf(p, "%s\n", lineaImporte.str().c_str());
    fprintf(p, "%-11s", "T O T A L: ");
    fprintf(p, "%11.2f\n", getImporteTotal());
    fprintf(p, "%s\n", lineaImporte.str().c_str());

    ///CIERRE DEL ARCHIVO
    cout << "Archivo de texto creado exitosamente."<<endl<<endl;
    fclose(p);
}

#endif // NOTADECREDITO_H_INCLUDED
