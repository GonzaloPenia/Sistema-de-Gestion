#ifndef FUNCIONESCONTACTO_H_INCLUDED
    #include "funcionesContacto.h"
#endif

void cargarProveedor();
void buscarProveedor();
void seleccionarProveedorExistente();
void modificarNombreProveedor();
void modificarDireccionProveedor();
// FUNCIONES OBSOLETAS - Ahora se gestionan los contactos a traves del menu de contactos
// void modificarContactoEmailProveedor();
// void modificarEmailProveedor();
// void modificarTelefonoFijoProveedor();
// void modificarTelefonoMovilProveedor();
void borrarProveedorLogico();
void borrarProveedorFisico();

void listaDeProveedores();
void listarProveedoresPorIdMayorAMenor();
void listarProveedoresPorIdMenorAMayor();
void listarProveedoresPorMayorCantidadDeCompras();
void listarProveedoresPorMenorCantidadDeCompras();

void cargarProveedor(){
    Proveedor regProveedor;
    ArchivoProveedor regArchivoProveedor;
    int id;
    cout<<"CARGA DE NUEVO PROVEEDOR."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool aux=true;
    while (aux==true){
        bool continuar;
        do{
            cout<<"ID DEL PROVEEDOR A REGISTRAR: ";
            cin>>id;
            bool repetido = regArchivoProveedor.verificarRepetido(id); //VERIFICAMOS QUE EL ID ESTE DISPONIBLE Y QUE NO HAYA REPETIDOS.
            if(repetido){
                system ("cls");
                cout<<"ESTAS INTENTANDO USAR UN ID QUE YA ESTA SIENDO UTILIZADO, PRUEBA UNO DIFERENTE"<<endl;
                cout<<"ID DEL PROVEEDOR A REGISTRAR: ";
            } else if (repetido==false){                            //NO HAY NINGUN PROVEEDOR CON ESE ID REGISTRADO
                regProveedor.Cargar(id);
                system("cls");
                regProveedor.Mostrar();
                continuar = confirmacion();
            }
        }while(!continuar);
        if(regArchivoProveedor.escribirArchivo(regProveedor)==true){
            cout<<"PROVEEDOR AGREGADO EXITOSAMENTE"<<endl;

            // Preguntar si desea agregar contactos
            int agregarContactos;
            cout << endl;
            cout << "DESEA AGREGAR CONTACTOS PARA ESTE PROVEEDOR? (1-SI, 0-NO): ";
            cin >> agregarContactos;

            if(agregarContactos == 1){
                system("cls");
                menuContactos(id, regProveedor.getNombre());
            }

            aux = false;
        } else {
            cout<<"NO SE PUDO AGREGAR EL PROVEEDOR"<<endl;
            aux = false;
        }
    }
}

void buscarProveedor()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    int id,pos;
    cout<<"BUSCAR UN PROVEEDOR POR ID."<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;
    pos= Archivo.buscarEnArchivo(id);
    if(pos==-1)
    {
        cout<<"NO HAY NINGUN PROVEEDOR CON ESE ID"<<endl;
    }
    else
    {
        if(pos==-2)
        {
            cout<<"FALLO EN EL ACCESO AL ARCHIVO"<<endl;
        }
    }

}

void listaDeProveedores()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    Archivo.leerArchivo();
}

void seleccionarProveedorExistente()
{

}

void modificarNombreProveedor()

{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
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

/* FUNCION OBSOLETA - Los contactos ahora se gestionan a traves del menu de contactos
void modificarContactoEmailProveedor()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");

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
*/

/* FUNCION OBSOLETA - Los contactos ahora se gestionan a traves del menu de contactos
void modificarEmailProveedor()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");

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
    cout<<"¿ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
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
*/

/* FUNCION OBSOLETA - Los contactos ahora se gestionan a traves del menu de contactos
void modificarTelefonoMovilProveedor()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
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

    cout<<"¿ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
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
*/

/* FUNCION OBSOLETA - Los contactos ahora se gestionan a traves del menu de contactos
void modificarTelefonoFijoProveedor()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
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

    cout<<"¿ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
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
*/

void modificarDireccionProveedor()
    {
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
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
void borrarProveedorLogico()
{ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL ARTICULO
    ArchivoProveedor Archivo("../../data/proveedores.dat");
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

    Proveedor Proveedor = Archivo.leerArchivo(pos);
    Proveedor.Mostrar();
    Proveedor.setEstado(false);
    bool flag=Archivo.modificarArchivo(pos,Proveedor);
    if(flag==true)
    {
        // Eliminar todos los contactos asociados al proveedor
        eliminarContactosDeEntidad(id);

        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        cout<<"CONTACTOS ASOCIADOS ELIMINADOS"<<endl;
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

}

void borrarProveedorFisico(){ //ESTA FUNCION ADEMAS DE DAR DE BAJA, SOBREESCRIBIR� LOS DATOS
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    int id,pos;
    cout<<"BORRAR FISICO PROVEEDOR."<<endl;
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

    Proveedor Proveedor = Archivo.leerArchivo(pos);
    Proveedor.setId(0);
    char n[30];
    cargarCadena(n,30);
    Proveedor.setNombre(n);
    char d[50];
    cargarCadena(d,50);
    /*Proveedor.setEmail(d);*/
    /*Proveedor.setTelefono(0);*/
    Proveedor.setCantidadCompras(0);
    Proveedor.setEstado(false);
    bool flag=Archivo.modificarArchivo(pos,Proveedor);
    if(flag==true)
    {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
    }
    else
    {
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

}

void listarProveedoresPorIdMayorAMenor(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMaximo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getId() > vProveedor[posMaximo].getId() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMaximo];
                vProveedor[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {            
            vProveedor[i].Mostrar();
            }
    }

    delete [] vProveedor;
}

void listarProveedoresPorIdMenorAMayor(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMinimo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getId() < vProveedor[posMinimo].getId() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMinimo];
                vProveedor[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar();
            }
    }

    delete [] vProveedor;
}

void listarProveedoresPorMayorCantidadDeCompras(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMaximo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getCantidadCompras() > vProveedor[posMaximo].getCantidadCompras() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMaximo];
                vProveedor[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar();
            }
    }

    delete [] vProveedor;
}

void listarProveedoresPorMenorCantidadDeCompras(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMinimo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getCantidadCompras() < vProveedor[posMinimo].getCantidadCompras() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMinimo];
                vProveedor[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar();
            }
    }

    delete [] vProveedor;
}
