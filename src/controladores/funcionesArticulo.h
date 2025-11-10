#include "../clases/Articulo.h"
#include "../clases/Proveedor.h"
#include "../clsArchivo/ArchivoArticulo.h"
#include "../clsArchivo/ArchivoProveedor.h"


void cargarArticulo();
void buscarArticulo();
void listaDeArticulos();
void listaArticulosSimplificada();
void modificarDescripcion();
void modificarProveedor();
void modificarPrecio();
void borrarLogico();
void borrarFisico();
void listarArticuloPorPrecioDeMayorAMenor();
void listarArticuloPorPrecioDeMenorAMayor();
void listaArticuloPorIdDeMayorAMenor();
void listaArticuloPorIdDeMenorAMayor();

void cargarArticulo(){
    Articulo regArticulo;
    Proveedor regProveedor;
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
    ArchivoProveedor regArchivoProveedor("../../data/proveedores.dat");
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
    ArchivoArticulo Archivo("../../data/articulos.dat");
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
    ArchivoArticulo Archivo("../../data/articulos.dat");
    Archivo.leerArchivo();
    cout<<"-------------------------"<<endl;
}

void listaArticulosSimplificada(){
    ArchivoArticulo Archivo("../../data/articulos.dat");
    Articulo regArticulo;
    FILE *p=fopen(Archivo.getNombre(),"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    cout << "LISTA A DE ARTICULOS:" << endl;
    cout << "--------------------------------" << endl;
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){
        if(regArticulo.getEstado()==true){
            cout << "ID: " << regArticulo.getId() << " | DESCRIPCION: " << regArticulo.getDescripcion() << " | PRECIO VENTA: $" << regArticulo.getCosto() * (1 + regArticulo.getGanancia() / 100.0) << endl;
        }
    }
    fclose(p);
}

void modificarDescripcion(){
    ArchivoArticulo Archivo("../../data/articulos.dat");
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
    ArchivoArticulo Archivo("../../data/articulos.dat");
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
    ArchivoArticulo Archivo("../../data/articulos.dat");
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
    ArchivoArticulo Archivo("../../data/articulos.dat");
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
    ArchivoArticulo Archivo("../../data/articulos.dat");
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
    //Articulo.setPrecioVenta(0);
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
    ArchivoArticulo regArchivo("../../data/articulos.dat");

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
                    
                int precioVenta = vArticulos[j].getCosto() * ( 1 + vArticulos[j].getGanancia()/100.0 );
                int precioVentaMax = vArticulos[posMaximo].getCosto() * ( 1 + vArticulos[posMaximo].getGanancia()/100.0 );

                if( precioVenta > precioVentaMax )
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
    ArchivoArticulo regArchivo("../../data/articulos.dat");

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
                
                int precioVenta = vArticulos[j].getCosto() * ( 1 + vArticulos[j].getGanancia()/100.0 );
                int precioVentaMin = vArticulos[posMinimo].getCosto() * ( 1 + vArticulos[posMinimo].getGanancia()/100.0 );
                
                if( precioVenta > precioVentaMin )
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
        ArchivoArticulo regArchivo("../../data/articulos.dat");

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
    ArchivoArticulo regArchivo("../../data/articulos.dat");

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
