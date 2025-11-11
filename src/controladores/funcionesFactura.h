void generarFactura(Factura factura){
    ArchivoFactura ArchivoFactura("../../data/facturas.dat");
    
    if (ArchivoFactura.agregarRegistro(factura)){
        cout<<"La factura ha sido emitida correctamente y se ha guardado en el archivo."<<endl;
    }
    else{
        cout<<"Hubo un error al momento de intentar guardar la factura."<<endl;
    }
    ;
}
///FUNCIONES PARA LA EMISION DE FACTURAS


