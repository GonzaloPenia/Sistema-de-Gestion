void generarFactura(Factura& factura){
    ArchivoFactura ArchivoFactura("../../data/facturas.dat");

    // Calcular el ID autoincrementable
    int cantidadFacturas = ArchivoFactura.contarRegistros();
    int nuevoId;

    if (cantidadFacturas > 0) {
        // Buscar el ID maximo existente
        int maxId = 0;
        for (int i = 0; i < cantidadFacturas; i++) {
            Factura facturaTemp = ArchivoFactura.leerRegistro(i);
            if (facturaTemp.getId() > maxId) {
                maxId = facturaTemp.getId();
            }
        }
        nuevoId = maxId + 1;
    } else {
        nuevoId = 1; // Primera factura
    }

    // Asignar el ID a la factura
    factura.setId(nuevoId);

    // Guardar la factura
    if (ArchivoFactura.agregarRegistro(factura)){
        cout << endl << "==================================================" << endl;
        cout << "La factura Nro. " << nuevoId << " ha sido emitida correctamente." << endl;
        cout << "==================================================" << endl << endl;
        system("pause");
    }
    else{
        cout << "Hubo un error al momento de intentar guardar la factura." << endl;
        system("pause");
    }
}
///FUNCIONES PARA LA EMISION DE FACTURAS


