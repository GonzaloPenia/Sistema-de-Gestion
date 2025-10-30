void cargarArticulo();
void buscarArticulo();
void listaDeArticulos();
void modificarDescripcion();
void modificarProveedor();
void modificarPrecio();
void borrarLogico();
void borrarFisico();
void listarArticuloPorPrecioDeMayorAMenor();
void listarArticuloPorPrecioDeMenorAMayor();
void listaArticuloPorIdDeMayorAMenor();
void listaArticuloPorIdDeMenorAMayor();
void modificarNombreProveedor();
void modificarDireccionProveedor();
void modificarContactoEmailProveedor();
void modificarEmailProveedor();
void modificarTelefonoFijoProveedor();
void modificarTelefonoMovilProveedor();

void cargarArticulo(){
    Articulo regArticulo;
    Proveedor regProveedor;
    ArchivoArticulo regArchivoArticulo("articulos.dat");
    ArchivoProveedor regArchivoProveedor("proveedores.dat");
    int id,id_proveedor;

    cout<<"CARGA DE NUEVO ARTICULO."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool aux=true;
    while (aux==true){
        bool continuar;

        int aux_proveedor;

        continuar=false;
        do{
            cout<<"ID DEL ARTICULO A REGISTRAR: ";
            cin>>id;
            bool repetido = regArchivoArticulo.verificarRepetido(id); //VERIFICAMOS QUE EL ID ESTE DISPONIBLE Y QUE NO HAYA REPETIDOS.
            if(repetido)
                {
                system ("cls");

                cout<<"ESTAS INTENTANDO USAR UN ID QUE YA ESTA SIENDO UTILIZADO, PRUEBA UNO DIFERENTE"<<endl<<endl;
                }

            else if (repetido==false){//NO HAY NINGUN ARTICULO CON ESE ID REGISTRADO
                cout<<"¿DESEA VINCULAR ESTE ARTICULO A UN PROVEEDOR YA EXISTENTE?: 1-SI 0-NO";

                cin>>aux_proveedor;

                if(aux_proveedor==0){//CARGA NORMAL, NO RELACIONA CON PROVEEDOR EXISTENTE

                        regArticulo.Cargar(id);//
                        system("cls");
                        regArticulo.Mostrar();

                        continuar = confirmacion();
                }

                else if(aux_proveedor!=0){ //RELACIONA CON PROVEEDOR EXISTENTE
                    int pos;
                    bool proveedor_repetido;
                    cout<<"ID DEL PROVEEDOR CON EL QUE DESEA VINCULAR ESTE ARTICULO: ";
                    cin>>id_proveedor;
                    proveedor_repetido= regArchivoProveedor.verificarRepetido(id_proveedor);

                    while(!proveedor_repetido){
                        cout<<"ESE ID DE PROVEEDOR NO COINCIDE CON NINGUN PROOVEDOR REGISTRADO, PRUEBE NUEVAMENTE: ";
                        cin>>id_proveedor;
                        proveedor_repetido= regArchivoProveedor.verificarRepetido(id_proveedor);
                    }

                    pos=regArchivoProveedor.buscarEnArchivo(id_proveedor);
                    regProveedor=regArchivoProveedor.leerArchivo(pos);

                    cout<<"SE ASOCIÓ EXITOSAMENTE EL PROVEEDOR CON ESTE ARTICULO. "<<endl;
                    cout<<"CONTINUE INGRESANDO LOS DATOS DEL ARTICULO. "<<endl;

                    regArticulo.Cargar(id,regProveedor);
                    system("cls");
                    regArticulo.Mostrar();

                    continuar = confirmacion();

                    }
                }
            }while(!continuar);


        if(regArchivoArticulo.escribirArchivo(regArticulo)==true)
        {
            cout<<"ARTICULO AGREGADO EXITOSAMENTE"<<endl;
            aux = false;
        }
        else{
            cout<<"NO SE PUDO AGREGAR EL ARTICULO"<<endl;
            aux = false;
        }
    }

}

void buscarArticulo(){
    ArchivoArticulo Archivo("articulos.dat");
    int id,pos;
    cout<<"BUSCAR UN ARTICULO POR ID."<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
    }
    else
    {
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
        }
    }

}

void listaDeArticulos(){
    ArchivoArticulo Archivo("data/articulos.dat");
    Archivo.leerArchivo();
    cout<<"-------------------------"<<endl;
}

void modificarDescripcion(){
    ArchivoArticulo Archivo("articulos.dat");
    int id,pos;
    cout<<"MODIFICACION DE DESCRIPCION"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN ARTICULO REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Articulo Articulo= Archivo.leerArchivo(pos);
    Articulo.Mostrar();
    cout<<"INGRESE LA NUEVA DESC. QUE SE LE ASIGNARA AL ARTICULO: "<<endl;
    char x[50];
    cargarCadena(x,50);
    Articulo.setDescripcion(x);

    bool flag= Archivo.modificarArchivo(pos, Articulo);
    if(flag==true)
    {
        cout<<"EL ARTICULO HA SIDO MODIFICADO DE FORMA CORRECTA";
    }
    else{
        cout<<"FALLO AL MODIFICAR EL ARTICULO";
    }

}

void modificarProveedor(){
    ArchivoArticulo Archivo("articulos.dat");
    int id,pos;
    cout<<"MODIFICACION DE PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN ARTICULO REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }

    // ¿DESEA INGRESAR UN NUEVO PROVEEDOR O BUSCAR UNO EXISTENTE?
    Articulo Articulo= Archivo.leerArchivo(pos);
    Articulo.Mostrar();

    cout<<"INGRESE EL NUEVO PROVEEDOR: "<<endl;
    cout<<"--------------------------- "<<endl;
    //Proveedor Proveedor;
    //Proveedor.Cargar();
    //Articulo.setProveedor(Proveedor);


    bool flag= Archivo.modificarArchivo(pos, Articulo);
    if(flag==true)
    {
        cout<<"EL ARTICULO HA SIDO MODIFICADO DE FORMA CORRECTA";
    }
    else{
        cout<<"FALLO AL MODIFICAR EL ARTICULO";
    }

}

void modificarPrecio(){
    ArchivoArticulo Archivo("articulos.dat");
    int id,pos;
    cout<<"INGRESE EL ID DEL ARTICULO CUYO PRECIO DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN ARTICULO REGISTRADO CON ESE ID"<<endl;
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
            cout<<"SE ENCONTRO UN REGISTRO"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Articulo Articulo= Archivo.leerArchivo(pos);
    Articulo.Mostrar();
    cout<<"INGRESE EL NUEVO PRECIO: "<<endl;

    bool flag= Archivo.modificarArchivo(pos, Articulo);
    if(flag==true)
    {
        cout<<"FECHA MODIFICADA DE FORMA CORRECTA";
    }
    else{
        cout<<"NO SE PUDO MODIFICAR LA FECHA";
    }

}

void borrarLogico(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL ARTICULO
    ArchivoArticulo Archivo("articulos.dat");
    int id,pos;
    cout<<"ELIMINAR UN ARTICULO."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=Archivo.buscarEnArchivo(id);
    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN ARTICULO REGISTRADO CON ESE ID"<<endl;
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

    Articulo Articulo = Archivo.leerArchivo(pos);
    Articulo.Mostrar();
    Articulo.setEstado(false);
    bool flag=Archivo.modificarArchivo(pos,Articulo);
    if(flag==true)
    {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

}

void borrarFisico(){ //ESTA FUNCION ADEMAS DE DAR DE BAJA, SOBREESCRIBIRÁ LOS DATOS
    ArchivoArticulo Archivo("articulos.dat");
    int id,pos;
    cout<<"ELIMINAR FISICO UN ARTICULO."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;
    pos=Archivo.buscarEnArchivo(id);
    if(pos==-1){
        cout<<"NO ENCONTRAMOS NINGUN ARTICULO REGISTRADO CON ESE ID"<<endl;
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

    Articulo Articulo = Archivo.leerArchivo(pos);
    Articulo.setId(0);
    //char n[30];
    //cargarCadena(n,30);
    //Articulo.setNombre(n);
    char d[50];
    cargarCadena(d,50);
    Articulo.setDescripcion(d);
    Articulo.setCosto(0);
    Articulo.setGananacia(0);
    Articulo.setPrecioVenta(0);
    //Proveedor Prov;
    //Prov.setCantidadCompras(0);
    //Prov.setEmailProveedor("");
    //Prov.setNombreProveedor("");
    //Prov.setTelefono(0);
    //Articulo.setProveedor(Prov);
    //Articulo.setUltimaActualizacionPrecio(0);
    Articulo.setUnidades(0);
    Articulo.setEstado(false);
    bool flag=Archivo.modificarArchivo(pos,Articulo);
    if(flag==true)
    {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
    }
    else
    {
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

}

void listarArticuloPorPrecioDeMayorAMenor(){
    ArchivoArticulo regArchivo("articulos.dat");

    int i, j,cantidad,posMaximo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vArticulos[j].getPrecioVenta() > vArticulos[posMaximo].getPrecioVenta() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMaximo];
                vArticulos[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar();
            }
    }

    delete [] vArticulos;
}

void listarArticuloPorPrecioDeMenorAMayor(){
    ArchivoArticulo regArchivo("articulos.dat");

    int i, j,cantidad,posMinimo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vArticulos[j].getPrecioVenta() < vArticulos[posMinimo].getPrecioVenta() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMinimo];
                vArticulos[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar();
            }
    }

    delete [] vArticulos;
}

void listaArticuloPorIdDeMayorAMenor(){
        ArchivoArticulo regArchivo("articulos.dat");

    int i, j,cantidad,posMaximo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vArticulos[j].getId() > vArticulos[posMaximo].getId() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMaximo];
                vArticulos[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar();
            }
    }

    delete [] vArticulos;
}

void listaArticuloPorIdDeMenorAMayor(){
    ArchivoArticulo regArchivo("articulos.dat");

    int i, j,cantidad,posMinimo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vArticulos[j].getId() < vArticulos[posMinimo].getId() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMinimo];
                vArticulos[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar();
            }
    }

    delete [] vArticulos;
}

/*

EXTENSION DE FUNCIONES DE PROVEEDOR

*/
void modificarNombreProveedor()

{
    ArchivoProveedor Archivo("proveedores.dat");
    ArchivoArticulo regArchivoArticulo("articulos.dat");
    int id,pos;
    cout<<"MODIFICACION DE NOMBRE DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN PROVEEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Proveedor regProveedor= Archivo.leerArchivo(pos);
    //regProveedor.Mostrar();
    cout<<"INGRESE EL NUEVO NOMBRE QUE SE LE ASIGNARA AL PROVEEDOR: "<<endl;
    char x[30];
    cargarCadena(x,30);
    regProveedor.setNombre(x);
    bool flag= Archivo.modificarArchivo(pos, regProveedor);

    int contador;
    contador=regArchivoArticulo.modificarArchivo(regProveedor);

    if(flag)
        {
        cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        cout<<contador<<" ARTICULOS FUERON AFECTADOS POR ESTE CAMBIO"<<endl;

        return;
        }

    else
        {
        cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
        return;
        }


}

void modificarContactoEmailProveedor()
{
    ArchivoProveedor Archivo("proveedores.dat");
    ArchivoArticulo regArchivoArticulo("articulos.dat");

    int id,pos,confirmacion;
    cout<<"MODIFICACION DE CONTACTO-EMAIL DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN PROVEEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Proveedor regProveedor= Archivo.leerArchivo(pos);
    cout<<"ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    regProveedor.Mostrar();

    cin>>confirmacion;

    if(confirmacion==1)
    {
    Contacto regContacto = regProveedor.getContacto();

    cout<<"INGRESE EL NUEVO CONTACTO-EMAIL 1: "<<endl;
    char contacto_email1[30];
    cargarCadena(contacto_email1,30);
    regContacto.setContactoEmailNro1(contacto_email1);

    cout<<"INGRESE EL NUEVO CONTACTO-EMAIL 2: "<<endl;
    char contacto_email2[30];
    cargarCadena(contacto_email2,30);
    regContacto.setContactoEmailNro2(contacto_email2);

    cout<<"INGRESE EL NUEVO CONTACTO-EMAIL 3: "<<endl;
    char contacto_email3[30];
    cargarCadena(contacto_email3,30);
    regContacto.setContactoEmailNro3(contacto_email3);


    regProveedor.setContacto(regContacto);
    bool flag = Archivo.modificarArchivo(pos,regProveedor);
    int contador;
    contador=regArchivoArticulo.modificarArchivo(regProveedor);
    if(flag)
        {
        cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;;
        cout<<contador<<" ARTICULOS FUERON AFECTADOS POR ESTE CAMBIO"<<endl;
        return;
        }

    else
        {
        cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
        return;
        }
    }
}

void modificarEmailProveedor()
{
    ArchivoProveedor Archivo("proveedores.dat");
    ArchivoArticulo regArchivoArticulo("articulos.dat");

    int id,pos,confirmacion;
    cout<<"MODIFICACION DE EMAIL DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN PROVEEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Proveedor regProveedor= Archivo.leerArchivo(pos);
    cout<<"�ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    regProveedor.Mostrar();

    cin>>confirmacion;

    if(confirmacion==1)
    {

    Contacto regContacto = regProveedor.getContacto();


    cout<<"INGRESE EL NUEVO EMAIL 1: "<<endl;
    char email1[30];
    cargarCadena(email1,30);

    regContacto.setEmailNro1(email1);
    cout<<"INGRESE EL NUEVO EMAIL 2: "<<endl;
    char email2[30];
    cargarCadena(email2,30);
    regContacto.setEmailNro2(email2);

    cout<<"INGRESE EL NUEVO EMAIL 3: "<<endl;
    char email3[30];
    cargarCadena(email3,30);
    regContacto.setEmailNro3(email3);


    regProveedor.setContacto(regContacto);

    bool flag = Archivo.modificarArchivo(pos,regProveedor);
    int contador;
    contador=regArchivoArticulo.modificarArchivo(regProveedor);

    if(flag)
        {
        cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;;
        cout<<contador<<" ARTICULOS FUERON AFECTADOS POR ESTE CAMBIO"<<endl;
        return;
        }

    else
        {
        cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
        return;
        }
    }
}

void modificarTelefonoMovilProveedor()
{
    ArchivoProveedor Archivo("proveedores.dat");
    ArchivoArticulo regArchivoArticulo("articulos.dat");
    int id,pos,confirmacion;
    cout<<"MODIFICACION DE TELEFONO MOVIL DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN PROVEEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Proveedor regProveedor= Archivo.leerArchivo(pos);

    cout<<"�ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    regProveedor.Mostrar();

    cin>>confirmacion;

    if(confirmacion==1)
    {

    Contacto regContacto = regProveedor.getContacto();

    cout<<"INGRESE EL NUEVO TELEFONO MOVIL 1: "<<endl;
    char movil1[30];
    cargarCadena(movil1,30);
    regContacto.setContactoMovilNro1(movil1);

    cout<<"INGRESE EL NUEVO TELEFONO MOVIL 2: "<<endl;
    char movil2[30];
    cargarCadena(movil2,30);
    regContacto.setContactoMovilNro2(movil2);

    cout<<"INGRESE EL NUEVO TELEFONO MOVIL 3: "<<endl;
    char movil3[30];
    cargarCadena(movil3,30);
    regContacto.setContactoMovilNro3(movil3);


    regProveedor.setContacto(regContacto);
    bool flag = Archivo.modificarArchivo(pos,regProveedor);

    int contador;
    contador=regArchivoArticulo.modificarArchivo(regProveedor);

    if(flag)
        {
        cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;;
        cout<<contador<<" ARTICULOS FUERON AFECTADOS POR ESTE CAMBIO"<<endl;
        return;
        }

    else
        {
        cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
        return;
        }
    }
}

void modificarTelefonoFijoProveedor()
{
    ArchivoProveedor Archivo("proveedores.dat");
    ArchivoArticulo regArchivoArticulo("articulos.dat");
    int id,pos,confirmacion;
    cout<<"MODIFICACION DE TELEFONO FIJO DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN PROVEEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Proveedor regProveedor= Archivo.leerArchivo(pos);

    cout<<"�ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    regProveedor.Mostrar();

    cin>>confirmacion;

    if(confirmacion==1)
    {

    Contacto regContacto = regProveedor.getContacto();

    cout<<"INGRESE EL NUEVO TELEFONO FIJO 1: "<<endl;
    char tel_fijo1[30];
    cargarCadena(tel_fijo1,30);
    regContacto.setTelFijoNro1(tel_fijo1);

    cout<<"INGRESE EL NUEVO TELEFONO FIJO 2: "<<endl;
    char tel_fijo2[30];
    cargarCadena(tel_fijo2,30);
    regContacto.setTelFijoNro2(tel_fijo2);

    cout<<"INGRESE EL NUEVO TELEFONO FIJO 3: "<<endl;
    char tel_fijo3[30];
    cargarCadena(tel_fijo3,30);
    regContacto.setTelFijoNro3(tel_fijo3);


    regProveedor.setContacto(regContacto);
    bool flag = Archivo.modificarArchivo(pos,regProveedor);

    int contador;
    contador=regArchivoArticulo.modificarArchivo(regProveedor);

    if(flag)
        {
        cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;;
        cout<<contador<<" ARTICULOS FUERON AFECTADOS POR ESTE CAMBIO"<<endl;
        return;
        }

    else
        {
        cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
        return;
        }
    }

}

void modificarDireccionProveedor()
    {
    ArchivoProveedor Archivo("proveedores.dat");
    ArchivoArticulo regArchivoArticulo("articulos.dat");
    int id,pos,confirmacion;
    cout<<"MODIFICACION DE LA DIRECCION DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR REGISTRADO CON ESE ID."<<endl;
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
            cout<<"ENCONTRAMOS UN PROVEEDOR"<<endl;
            cout<<"-----------------------"<<endl;

        }
    }
    Proveedor regProveedor= Archivo.leerArchivo(pos);

    cout<<"ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    regProveedor.Mostrar();

    cin>>confirmacion;

    if(confirmacion==1)
    {

    Direccion regDireccion = regProveedor.getDireccion();

    cout<<"INGRESE CALLE: "<<endl;
    char calle[20];
    cargarCadena(calle,20);
    regDireccion.setCalle(calle);

    cout<<"INGRESE ALTURA: "<<endl;
    int altura;
    cin>>altura;
    regDireccion.setNumero(altura);

    cout<<"INGRESE EL CODIGO POSTAL: "<<endl;
    int codigo_postal;
    cin>>codigo_postal;
    regDireccion.setCodigoPostal(codigo_postal);

    cout<<"INGRESE LA LOCALIDAD: "<<endl;
    char localidad[20];
    cargarCadena(localidad,20);
    regDireccion.setLocalidad(localidad);

    cout<<"INGRESE LA PROVINCIA: "<<endl;
    char provincia[20];
    cargarCadena(provincia,20);
    regDireccion.setProvincia(provincia);

    regProveedor.setDireccion(regDireccion);

    bool flag = Archivo.modificarArchivo(pos,regProveedor);

    int contador;
    contador=regArchivoArticulo.modificarArchivo(regProveedor);

    if(flag)
        {
        cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;;
        cout<<contador<<" ARTICULOS FUERON AFECTADOS POR ESTE CAMBIO"<<endl;
        return;
        }

    else
        {
        cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
        return;
        }
    }
}
