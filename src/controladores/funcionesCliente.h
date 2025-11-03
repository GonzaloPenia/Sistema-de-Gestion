#ifndef FUNCIONESCONTACTO_H_INCLUDED
    #include "funcionesContacto.h"
#endif

void cargarCliente();
void listarClientes();
void buscarCliente();
void modificarNombre();
void modificarTipo();
void modificarDireccionYContacto();
void modificarCantidadVentas();
void modificarNombreCliente();
void listarDeMayorAMenorVentas();
void listarDeMenorAMayorVentas();
void listaIdMenorAMayorCliente();
void listaIdMayorAMenorCliente();
void borrarLogicoCliente();
void borrarFisicoCliente();
void aumentarVentas();
void listaCuitMenorAMayorCliente();
void listaCuitMayorAMenorCliente();
void listaAlfabeticamenteCliente();
void recaudacionFactura(float recaudacion, int idCliente);
void recaudacionCredito(float recaudacion, int idCliente);
void listarRecaudacionPorCliente();
void elegirClienteRecaudacion();


void cargarCliente(){
    Cliente regCliente;
    ArchivoCliente regArchivoCliente;
    int id;
    bool repetido2;
    cout<<"CARGA DE NUEVO CLIENTE."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool aux=true;
    while (aux==true){
        bool continuar;
        do{
            cout<<"ID DEL CLIENTE A REGISTRAR: ";
            cin>>id;
            bool repetido = regArchivoCliente.verificarRepetido(id); //VERIFICAMOS QUE EL ID ESTE DISPONIBLE Y QUE NO HAYA REPETIDOS.
            repetido2=repetido;
            if(repetido){
                system ("cls");
                cout<<"CARGA DE NUEVO CLIENTE."<<endl<<endl;
                cout<<"ESTAS INTENTANDO USAR UN ID QUE YA ESTA SIENDO UTILIZADO, PRUEBA UNO DIFERENTE"<<endl;
            }else if (repetido==false){                            //NO HAY NINGUNA ENTIDAD CON ESE ID REGISTRADO
                regCliente.Cargar(id);
                system("cls");
                regCliente.Mostrar();
                continuar = confirmacion();
            }
        }while(!continuar);
          
        if(regArchivoCliente.escribirArchivo(regCliente)==true){
            if(repetido2!=true){
            cout<<"CLIENTE AGREGADO EXITOSAMENTE"<<endl;

            // Preguntar si desea agregar contactos
            int agregarContactos;
            cout << endl;
            cout << "DESEA AGREGAR CONTACTOS PARA ESTE CLIENTE? (1-SI, 0-NO): ";
            cin >> agregarContactos;

            if(agregarContactos == 1){
                system("cls");
                menuContactos(id, regCliente.getNombre());
            }

            aux = false;
            }
        }else{
            cout<<"NO SE PUDO AGREGAR EL CLIENTE"<<endl;
            aux = false;
        }
    }
}

void listarClientes(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    regCliente.leerArchivo();
    cout<<"-------------------------"<<endl;
}

void buscarCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    cout<<"BUSCAR UN CLIENTE."<<endl<<endl;

    cout<<"INGRESE EL METODO QUE QUIERE USAR PARA BUSCAR AL CLIENTE:"<<endl;
    cout<<"(1-BUSCAR POR ID  2-BUSCAR POR NOMBRE 3-BUSCAR POR CUIT)"<<endl;
    int metodo;
    cin>>metodo;
    switch (metodo) {

        case 1:
        cout<<"INGRESE EL ID DEL CLIENTE A BUSCAR: ";
        cin>>id;
        regCliente.encontrarCliente(id);
        break;

        case 2:
        cout<<"INGRESE EL NOMBRE DEL CLIENTE A BUSCAR: ";
        char nombre[50];
        //cin>>nombre;
        cargarCadena(nombre,50);
        regCliente.encontrarClienteNombre(nombre);
        break;

        case 3:
        cout<<"INGRESE EL CUIT DEL CLIENTE A BUSCAR: ";
        char cuit[13];
        cin>>cuit;
        regCliente.encontrarClienteCuit(cuit);
        break;

        default:
        cout<<"METODO NO VALIDO"<<endl;
        system("pause");
        system("cls");
        buscarCliente();
        break;
    break;
    }
}

void modificarTipo(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE TIPO"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regCliente.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
        /*else
        {
            cout<<"ENCONTRAMOS UN CLIENTE"<<endl;
            cout<<"-----------------------"<<endl;

        }*/
    }
    Cliente Cliente= regCliente.leerArchivo(pos);
    //Cliente.Mostrar();

    cout<<"INGRESE EL NUEVO TIPO QUE SE LE ASIGNARA AL CLIENTE "<<endl;
    cout<<"(0- Sin tipo, 1-Responsable Inscripto, 2-Monotributo, 3-Exento, 4-Cons.Final): ";
    int tipoCliente;
    cin>>tipoCliente;
    Cliente.setTipo(tipoCliente);
    bool flag= regCliente.modificarArchivo(pos, Cliente);
    system("cls");
    if(flag==true)
    {
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;

    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}

void modificarDireccionYContacto(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    Direccion regDireccion;
    Contacto regContacto;
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE DIRECCION Y CONTACTO"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regCliente.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }


    }
    Cliente Cliente= regCliente.leerArchivo(pos);
    //Cliente.Mostrar();
    cout<<"INGRESE QUE DESEA MODIFICAR DEL CLIENTE (1- DIRECCION, 2 - CONTACTO): "<<endl;
    int opcion;
    cin>>opcion;
    system("cls");
    switch(opcion){

        case 1:
        cout<<"INGRESE LA NUEVA DIRECCION"<<endl;
        regDireccion.Cargar();
        Cliente.setDireccion(regDireccion);


        break;


        case 2:
        // FUNCION OBSOLETA - Los contactos ahora se gestionan desde el menu principal
        cout<<"ESTA FUNCION FUE REEMPLAZADA"<<endl;
        cout<<"USE LA OPCION 6 'GESTIONAR CONTACTOS' DEL MENU PRINCIPAL"<<endl;
        break;



    }

    bool flag= regCliente.modificarArchivo(pos, Cliente);
    if(flag==true)
    {
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        cout<<"VAMOS BIEN!!!!"<<endl;
    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}

void modificarCantidadVentas(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id,pos;
    system("cls");
    cout<<"MODIFICACION DE CANTIDAD DE VENTAS"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regCliente.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }

    }
    Cliente Cliente= regCliente.leerArchivo(pos);
    //Cliente.Mostrar();

    cout<<"INGRESE LA NUEVA CANTIDAD DE VENTAS DEL CLIENTE "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    Cliente.setcantidadVentas(cantidadVentas);
    bool flag= regCliente.modificarArchivo(pos, Cliente);
    system("cls");
    if(flag==true)
    {
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;

    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}

void modificarNombreCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id,pos;
    cout<<"MODIFICACION DE NOMBRE"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= regCliente.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else{
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            return;
        }
    }
    Cliente Cliente= regCliente.leerArchivo(pos);
    cout<<"INGRESE EL NUEVO NOMBRE QUE SE LE ASIGNARA AL CLIENTE: "<<endl;
    char x[50];
    cargarCadena(x,50);
    Cliente.setNombre(x);
    bool flag= regCliente.modificarArchivo(pos, Cliente);
    if(flag==true)
    {
        cout<<endl;
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA";
    }
    else{
        cout<<"FALLO AL MODIFICAR EL ARTICULO";
    }

}

void listarDeMayorAMenorVentas(){
    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getcantidadVentas() > vClientes[posMaximo].getcantidadVentas() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(25) << "Razon Social" << setw(35) << "CUIT" << setw(15) << "Ventas" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(25) << vClientes[i].getNombre() << setw(35) << vClientes[i].getCuit() << setw(15) << vClientes[i].getcantidadVentas() << endl << endl;

            }
    }

    delete [] vClientes;
}

void listarDeMenorAMayorVentas(){
    ArchivoCliente regClientes("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regClientes.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regClientes.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getcantidadVentas() < vClientes[posMinimo].getcantidadVentas() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(25) << "Razon Social" << setw(35) << "CUIT" << setw(15) << "Ventas" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(25) << vClientes[i].getNombre() << setw(35) << vClientes[i].getCuit() << setw(15) << vClientes[i].getcantidadVentas() << endl << endl;

            }
    }

    delete [] vClientes;
}

void listaIdMenorAMayorCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getId() < vClientes[posMinimo].getId() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
}

void listaIdMayorAMenorCliente(){
        ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getId() > vClientes[posMaximo].getId() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
}

void borrarLogicoCliente(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL CLIENTE
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id,pos;
    int eliminar;
    cout<<"ELIMINAR UN CLIENTE."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=regCliente.buscarEnArchivo(id);

    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN CLIENTE REGISTRADO CON ESE ID"<<endl;
        system("pause");
        return;
    }
    else{
        if(pos==-2){
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
            system("pause");
            return;
        }
        else{
            cout<<"SE ENCONTRO UN REGISTRO"<<endl;
            system("pause");
        }
    }

    Cliente Cliente = regCliente.leerArchivo(pos);
    system("pause");
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE CLIENTE? (1-SI, 2-NO): ";
    cin>> eliminar;
    if(eliminar==1){
    Cliente.setEstado(false);
    bool flag=regCliente.modificarArchivo(pos,Cliente);
    if(flag==true)
    {
        // Eliminar todos los contactos asociados al cliente
        eliminarContactosDeEntidad(id);

        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        cout<<"CONTACTOS ASOCIADOS ELIMINADOS"<<endl;
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

    system("pause");
    }else {
        cout<<"NO SE BORRO NADA"<<endl;
    }
}

void borrarFisicoCliente(){ //ESTA FUNCION PONDRA TODOS LOS VALORES EN 0 DEL CLIENTE
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id,pos;
    int a;
    int eliminar;
    a=rand();

    cout<<"ELIMINAR UN CLIENTE."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=regCliente.buscarEnArchivo(id);
    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN CLIENTE REGISTRADO CON ESE ID"<<endl;
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

    Cliente Cliente = regCliente.leerArchivo(pos);
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE CLIENTE? (1-SI, 2-NO): ";
    cin>> eliminar;
    if(eliminar==1){

        char d[50];
        cargarCadena(d,50);
        Contacto Contacto;
        Direccion Direccion;
        Cliente.setNombre(d);
        Cliente.setId(a-1);
        Cliente.setCuit(0);
        Cliente.setcantidadVentas(0);
        Cliente.setTipo(0);
        // Cliente.setContacto(Contacto); // OBSOLETO - contactos ahora son independientes
        Cliente.setDireccion(Direccion);
        Cliente.setEstado(false);
        bool flag=regCliente.modificarArchivo(pos,Cliente);
        if(flag==true)
        {
            cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
        }
        else
        {
            cout<<"NO SE PUDO BORRAR EL REGISTRO";
        }
    }else{
        cout<<"NO SE BORRO NADA"<<endl;
    }
}

void aumentarVentas(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id,pos;
    cout<<"AUMENTAR VENTAS DE UN CLIENTE."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE EL CUAL DESEA AUMENTAR VENTAS: ";
    cin>> id;
    pos=regCliente.buscarEnArchivo(id);
    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN CLIENTE REGISTRADO CON ESE ID"<<endl;
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
    Cliente Cliente = regCliente.leerArchivo(pos);

    cout<<"INGRESE LA CANTIDAD DE VENTAS QUE QUIERE AUMENTAR: ";
    int aux;
    cin>>aux;
    Cliente.setcantidadVentas(Cliente.getcantidadVentas()+aux);
    bool flag=regCliente.modificarArchivo(pos,Cliente);
    if(flag==true)
    {
        cout<<"REGISTRO AUMENTADO DE FORMA CORRECTA";
    }
    else
    {
        cout<<"NO SE PUDO AUMENTAR EL REGISTRO";
    }
}

void listaCuitMenorAMayorCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];
    int resultado;

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {

                resultado = strcmp(vClientes[posMinimo].getCuit(),vClientes[j].getCuit());

                if(resultado > 0)
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
        {

        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

        }
    }

    delete [] vClientes;
}

void listaCuitMayorAMenorCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];
    int resultado;

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                resultado = strcmp(vClientes[posMaximo].getCuit(),vClientes[j].getCuit());

                if(resultado < 0)
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
}

void listaAlfabeticamenteCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];
    int resultado;

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                resultado = strcmp(vClientes[posMaximo].getNombre(),vClientes[j].getNombre());

                if(resultado > 0)
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
}

void recaudacionFactura(float recaudacion, int idCliente){
    ArchivoCliente regArchivoCliente("../../data/clientes.dat");
    Cliente Cliente;

    int pos;
    int recaudacionaux;
    system("cls");

    pos = regArchivoCliente.buscarSinMostrar(idCliente);

    Cliente = regArchivoCliente.leerArchivo(pos);

    recaudacionaux=Cliente.getRecaudacion();
    Cliente.setRecaudacion(recaudacionaux+recaudacion);
    
    bool flag = regArchivoCliente.modificarArchivo(pos, Cliente);
    system("cls");

}

void recaudacionCredito(float recaudacion, int idCliente){
    ArchivoCliente regArchivoCliente("../../data/clientes.dat");
    Cliente Cliente;

    int pos;
    int recaudacionaux;
    system("cls");

    pos = regArchivoCliente.buscarSinMostrar(idCliente);

    Cliente = regArchivoCliente.leerArchivo(pos);

    recaudacionaux=Cliente.getRecaudacion();
    Cliente.setRecaudacion(recaudacionaux-recaudacion);
    bool flag = regArchivoCliente.modificarArchivo(pos, Cliente);
    system("cls");

}

void listarRecaudacion(){
    ArchivoCliente regCliente("../../data/clientes.dat");

    int opcion;
    cout<<"CONSULTAS DE RECAUDACION"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"1 - RECAUDACION POR CLIENTE."<<endl;
    cout<<"2 - ELEGIR CLIENTE PARA RECAUDACION."<<endl;
    cin>>opcion;
    system("cls");
    switch(opcion){
        case 1:
        listarRecaudacionPorCliente();

        break;

        case 2:
        elegirClienteRecaudacion();

        break;
    }
}

void listarRecaudacionPorCliente(){
    ArchivoCliente regClientes("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regClientes.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regClientes.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getRecaudacion() < vClientes[posMinimo].getRecaudacion() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(25) << "Nombre o Razon Social" << setw(35) << "Recaudacion" << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {


            cout << left << setw(25) << vClientes[i].getNombre() << setw(35) << vClientes[i].getRecaudacion() << endl;

            }
    }

    delete [] vClientes;
}

void elegirClienteRecaudacion(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    cout<<"INGRESE EL ID DEL CLIENTE A BUSCAR: ";
    cin>>id;
    system("cls");
    regCliente.encontrarClienteRecaudacion(id);
}
//fin
