#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <vector>

using namespace std;

// Incluir las clases globales
#include "../src/globales/funcionesGlobales.h"
#include "../src/globales/clsGlobales.h"
#include "../src/clases/Entidad.h"
#include "../src/clases/Proveedor.h"
#include "../src/clsArchivo/ArchivoProveedor.h"
#include "../src/clases/Articulo.h"
#include "../src/clsArchivo/ArchivoArticulo.h"

int main() {
    srand(time(NULL));

    // Leer proveedores existentes
    ArchivoProveedor archivoProveedor("./data/proveedores.dat");
    int cantidadProveedores = archivoProveedor.contarArchivo();

    if (cantidadProveedores == 0) {
        cout << "No hay proveedores en el archivo. Por favor, carga proveedores primero." << endl;
        return 1;
    }

    cout << "Se encontraron " << cantidadProveedores << " proveedores." << endl;

    // Vectorizar proveedores
    Proveedor* proveedores = new Proveedor[cantidadProveedores];
    archivoProveedor.vectorizarArchivo(proveedores, cantidadProveedores);

    // Crear archivo de articulos
    ArchivoArticulo archivoArticulo("./data/articulos.dat");

    // Fecha de hoy
    Fecha hoy(3, 11, 2025);

    // Lista de 30 articulos de ferreteria
    const char* descripciones[30] = {
        "Martillo STANLEY carpintero 16oz",
        "Destornillador TOTAL punta estrella PH2",
        "Destornillador TOTAL punta plana 6mm",
        "Pinza TRUPER universal 8 pulgadas",
        "Llave inglesa BAHCO ajustable 10 pulgadas",
        "Taladro electrico BLACK+DECKER 550W",
        "Set lijas NORTON grano 80-120-220",
        "Sierra manual IRWIN 18 pulgadas",
        "Cinta metrica STANLEY 5 metros",
        "Nivel burbuja STANLEY 60cm",
        "Alicate STANLEY corte diagonal 6 pulgadas",
        "Juego llaves allen BAHCO 1.5-10mm",
        "Pistola silicona TRUPER esqueleto",
        "Remachadora manual TRUPER pop",
        "Cortafierro TRAMONTINA 10 pulgadas",
        "Martillo goma STANLEY 450gr",
        "Serrucho BAHCO punta 22 pulgadas",
        "Arco sierra TRUPER con 3 hojas",
        "Grampa sargento IRWIN 12 pulgadas",
        "Espatula acero TRAMONTINA 4 pulgadas",
        "Brocha CONDOR cerda 3 pulgadas",
        "Rodillo pintura CONDOR espuma 9 pulgadas",
        "Mecha concreto BOSCH 8mm SDS-Plus",
        "Mecha madera BOSCH 10mm plana",
        "Mecha metal DEWALT 6mm HSS",
        "Disco corte DEWALT metal 7 pulgadas",
        "Disco lija DEWALT grano 100",
        "Guantes trabajo PROTEX cuero reforzado",
        "Lentes seguridad STEELPRO transparente",
        "Casco proteccion STEELPRO amarillo"
    };

    float precios[30] = {
        15500.0,   // Martillo
        8900.0,    // Destornillador estrella
        7800.0,    // Destornillador plano
        12300.0,   // Pinza
        18700.0,   // Llave inglesa
        89500.0,   // Taladro
        5600.0,    // Lijas
        14200.0,   // Sierra manual
        9800.0,    // Cinta metrica
        11500.0,   // Nivel
        13900.0,   // Alicate
        24500.0,   // Llaves allen
        6700.0,    // Pistola silicona
        19800.0,   // Remachadora
        16900.0,   // Cortafierro
        10200.0,   // Martillo goma
        17500.0,   // Serrucho
        8500.0,    // Arco sierra
        22400.0,   // Grampa
        4200.0,    // Espatula
        3800.0,    // Brocha
        7200.0,    // Rodillo
        12800.0,   // Mecha concreto
        9500.0,    // Mecha madera
        8200.0,    // Mecha metal
        15600.0,   // Disco corte
        6900.0,    // Disco lija
        11200.0,   // Guantes
        4500.0,    // Lentes
        18900.0    // Casco
    };

    // Generar 30 articulos
    for (int i = 0; i < 30; i++) {
        Articulo art;

        // ID secuencial (1 a 30)
        art.setId(i + 1);

        // Descripcion
        art.setDescripcion(descripciones[i]);

        // Unidades: 25 para todos
        art.setUnidades(25);

        // Ganancia aleatoria entre 5 y 20
        int ganancia = 5 + rand() % 16;
        art.setGananacia(ganancia);

        // Precio de venta
        float precio_venta = precios[i];
        art.setPrecioVenta(precio_venta);

        // Calcular costo a partir del precio de venta y ganancia
        float costo = precio_venta / (1 + ganancia / 100.0);
        art.setCosto(costo);

        // Fecha de actualizacion: hoy
        art.setUltimaActualizacionPrecio(hoy);

        // Proveedor aleatorio de los existentes
        int indexProveedor = rand() % cantidadProveedores;
        art.setProveedor(proveedores[indexProveedor]);

        // Estado: true
        art.setEstado(true);

        // Escribir en archivo
        if (archivoArticulo.escribirArchivo(art)) {
            cout << "Articulo " << (i+1) << " creado: " << descripciones[i] << endl;
        } else {
            cout << "Error al crear articulo " << (i+1) << endl;
        }
    }

    delete[] proveedores;

    cout << endl << "Proceso completado. Se generaron 30 articulos en articulos.dat" << endl;

    return 0;
}
