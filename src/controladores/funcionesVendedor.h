void cargarVendedor();
void mostrarVendedor();
void buscarVendedor();
void listarDeMayorAMenorVentasVendedor();
void listarDeMenorAMayorVentasVendedor();
void listaAntiguedadMenorAMayorVendedor();
void listaAntiguedadMayorAMenorVendedor();
void listarVendedores();
void borrarLogicoVendedor();
void modificarNombreVendedor();
void modificarVentasVendedor();
void modificarSueldoVendedor();
void modificarAntiguedadVendedor();
void modificarEdadVendedor();
void modificarDomicilioVendedor();


void cargarVendedor(){
    Vendedor regVendedor;
    ArchivoVendedor regArchivoVendedor;
    int id;
    cout<<"CARGA DE NUEVO VENDEDOR."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool aux=true;
    while (aux==true){
        bool continuar;
        do{
            cout<<"ID DEL VENDEDOR A REGISTRAR: ";
            cin>>id;
            bool repetido = regArchivoVendedor.verificarRepetido(id); //VERIFICAMOS QUE EL ID ESTE DISPONIBLE Y QUE NO HAYA REPETIDOS.
            if(repetido){
                system ("cls");
                cout<<endl<<endl;
                cout<<"ESTAS INTENTANDO USAR UN ID QUE YA ESTA SIENDO UTILIZADO, PRUEBA UNO DIFERENTE"<<endl;
                cargarVendedor();

            }else if (repetido==false){                            //NO HAY NINGUN VENDEDOR CON ESE ID REGISTRADO
                regVendedor.Cargar(id);
                system("cls");
                regVendedor.Mostrar();
                continuar = confirmacion();
            }
        }while(!continuar);
        if(regArchivoVendedor.escribirArchivo(regVendedor)==true){
            cout<<"VENDEDOR AGREGADO EXITOSAMENTE"<<endl;
            aux = false;
        }else{
            cout<<"NO SE PUDO AGREGAR EL VENDEDOR"<<endl;
            aux = false;
        }
    }
}

void mostrarVendedor(){
    ArchivoVendedor regArchivoVendedor;
    Vendedor regVendedor;

    for(int i=0; i<=regVendedor.getId(); i++){
        regArchivoVendedor.leerArchivo();
        //regVendedor.Mostrar();
    }
}

void buscarVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    cout<<"BUSCAR UN VENDEDOR POR ID."<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;
    regVendedor.encontrarVendedor(id);

}

void listarDeMayorAMenorVentasVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMaximo;

    Vendedor *vVendedores;

    cantidad=regVendedor.contarArchivo();
    vVendedores = new Vendedor[cantidad];

    if(vVendedores == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedores, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedores[j].getventasRealizadas() > vVendedores[posMaximo].getventasRealizadas() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Vendedor aux = vVendedores[i];
                vVendedores[i] = vVendedores[posMaximo];
                vVendedores[posMaximo] = aux;
                }
        }
        
    if(cantidad!=0){
        
        cout << left << setw(25) << "Razon Social" << setw(35) << "Cargo" << setw(15) << "Ventas" << endl;
            for(int i=0; i<cantidad; i++)
        {
        if(vVendedores[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(25) << vVendedores[i].getNombre() << setw(35) << vVendedores[i].getCargo() << setw(15) << vVendedores[i].getventasRealizadas() << endl << endl;

            }
        }


        }
    

    delete [] vVendedores;
}

void listarDeMenorAMayorVentasVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMinimo;

    Vendedor *vVendedor;

    cantidad=regVendedor.contarArchivo();
    vVendedor = new Vendedor[cantidad];

    if(vVendedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedor[j].getventasRealizadas() < vVendedor[posMinimo].getventasRealizadas() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Vendedor aux = vVendedor[i];
                vVendedor[i] = vVendedor[posMinimo];
                vVendedor[posMinimo] = aux;
                }
        }
    cout << left << setw(25) << "Razon Social" << setw(35) << "Cargo" << setw(15) << "Ventas" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vVendedor[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(25) << vVendedor[i].getNombre() << setw(35) << vVendedor[i].getCargo() << setw(15) << vVendedor[i].getventasRealizadas() << endl << endl;

            }
    }

    delete [] vVendedor;
}

void listaAntiguedadMenorAMayorVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMinimo;

    Vendedor *vVendedor;

    cantidad=regVendedor.contarArchivo();
    vVendedor = new Vendedor[cantidad];

    if(vVendedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedor[j].getaniosAntiguedad() < vVendedor[posMinimo].getaniosAntiguedad() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Vendedor aux = vVendedor[i];
                vVendedor[i] = vVendedor[posMinimo];
                vVendedor[posMinimo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Nombre" << setw(15) << "Antiguedad" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vVendedor[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << vVendedor[i].getId() << setw(55) << vVendedor[i].getNombre() << setw(15) << vVendedor[i].getaniosAntiguedad() << endl << endl;

            }
    }

    delete [] vVendedor;
}

void listaAntiguedadMayorAMenorVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMaximo;

    Vendedor *vVendedor;

    cantidad=regVendedor.contarArchivo();
    vVendedor = new Vendedor[cantidad];

    if(vVendedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedor[j].getaniosAntiguedad() > vVendedor[posMaximo].getaniosAntiguedad() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Vendedor aux = vVendedor[i];
                vVendedor[i] = vVendedor[posMaximo];
                vVendedor[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Nombre" << setw(15) << "Antiguedad" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vVendedor[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << vVendedor[i].getId() << setw(55) << vVendedor[i].getNombre() << setw(15) << vVendedor[i].getaniosAntiguedad() << endl << endl;

            }
    }

    delete [] vVendedor;
}

void listarVendedores(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    regVendedor.leerArchivo();
    cout<<"-------------------------"<<endl;
}

void borrarLogicoVendedor(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL CLIENTE
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    cout<<"ELIMINAR UN VENDEDOR."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=regVendedor.buscarEnArchivo(id);
    system("pause");
    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN VENDEDOR REGISTRADO CON ESE ID"<<endl;
        return;
    }
    else{
        if(pos==-2){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
        else{
            cout<<"SE ENCONTRO UN REGISTRO"<<endl;
        }
    }

    Vendedor Vendedor = regVendedor.leerArchivo(pos);
    Vendedor.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE VENDEDOR? (1-SI, 2-NO)";
    int opcion;
    cin>>opcion;
    if(opcion==1){
    Vendedor.setEstado(false);
    bool flag=regVendedor.modificarArchivo(pos,Vendedor);
    if(flag==true)
    {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

    system("pause");
    }else {
        cout<<"NO SE BORRO NADA"<<endl;
    }

}

void borrarFisicoVendedor(){ //ESTA FUNCION PONDRA TODOS LOS VALORES EN 0 DEL CLIENTE
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    int a;
    a=rand();    
    
    cout<<"ELIMINAR UN VENDEDOR."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=regVendedor.buscarEnArchivo(id);
    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN VENDEDOR REGISTRADO CON ESE ID"<<endl;
        return;
    }
    else{
        if(pos==-2){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
        else{
            cout<<"SE ENCONTRO UN REGISTRO"<<endl;
        }
    }

   Vendedor Vendedor = regVendedor.leerArchivo(pos);
   Vendedor.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE VENDEDOR? (1-SI, 2-NO)";
    int opcion;
    cin>>opcion;
    if(opcion==1){
    char d[50];
    cargarCadena(d,50);
    Vendedor.setId(a-1);
    Vendedor.setCargo(0);
    Vendedor.setventasRealizadas(0);
    Vendedor.setaniosAntiguedad(0);
    Vendedor.setNombre(d);
    Vendedor.setDni(0);
    Vendedor.setEdad(0);
    Vendedor.setEstado(false);
    bool flag=regVendedor.modificarArchivo(pos,Vendedor);
        if(flag==true)
        {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        system("pause");
        }
     else
     {
        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
        system("pause");
     }
    }else{
        cout<<"NO SE BORRO NADA"<<endl;
        system("pause");
    }

}

void modificarNombreVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE NOMBRE"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regVendedor.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
        else
        {
            cout<<"ENCONTRAMOS UN VENDEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Vendedor Vendedor= regVendedor.leerArchivo(pos);
    //Cliente.Mostrar();
    cout<<"INGRESE EL NUEVO NOMBRE QUE SE LE ASIGNARA AL CLIENTE: "<<endl;
    char x[50];
    cargarCadena(x,50);
    Vendedor.setNombre(x);
    bool flag= regVendedor.modificarArchivo(pos, Vendedor);
    if(flag==true)
    {
        cout<<endl;
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarVentasVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE VENTAS REALIZADAS"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regVendedor.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }

    }
    Vendedor Vendedor= regVendedor.leerArchivo(pos);
    

    cout<<"INGRESE LA NUEVA CANTIDAD DE VENTAS DEL VENDEDOR "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    Vendedor.setventasRealizadas(cantidadVentas);
    bool flag= regVendedor.modificarArchivo(pos, Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarSueldoVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE SUELDO DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regVendedor.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }

    }
    Vendedor Vendedor= regVendedor.leerArchivo(pos);
    

    cout<<"INGRESE EL NUEVO SUELDO DEL VENDEDOR "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    Vendedor.setSueldo(cantidadVentas);
    bool flag= regVendedor.modificarArchivo(pos, Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarAntiguedadVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION ANTIGUEDAD DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regVendedor.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }

    }
    Vendedor Vendedor= regVendedor.leerArchivo(pos);
    

    cout<<"INGRESE LA NUEVA ANTIGUEDAD DEL VENDEDOR "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    Vendedor.setaniosAntiguedad(cantidadVentas);
    bool flag= regVendedor.modificarArchivo(pos, Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarEdadVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION EDAD DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regVendedor.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }

    }
    Vendedor Vendedor= regVendedor.leerArchivo(pos);
    

    cout<<"INGRESE LA NUEVA EDAD DEL VENDEDOR "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    Vendedor.setEdad(cantidadVentas);
    bool flag= regVendedor.modificarArchivo(pos, Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarDomicilioVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    Direccion regDireccion;    ;
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE DOMICILIO DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regVendedor.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }


    }
    Vendedor Vendedor= regVendedor.leerArchivo(pos);
    cout<<"INGRESE EL NUEVO DOMICILIO"<<endl;
    regDireccion.Cargar();
    Vendedor.setDireccion(regDireccion); // heredado de Entidad    

    bool flag= regVendedor.modificarArchivo(pos, Vendedor);
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

//fin