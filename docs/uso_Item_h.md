# Uso de Item.h en el Sistema de Gestión

Este documento describe cómo y dónde se utiliza el archivo `Item.h` en el proyecto.

## Descripción General

La clase `Item` representa un artículo individual dentro de una venta o factura. Contiene información sobre el artículo, cantidad, y precios.

## Inclusión Directa

### main.cpp
- **Línea 37**: `#include "clases/Item.h"`
  - El archivo se incluye en el archivo principal del programa.

## Uso de la Clase Item

### 1. Detalle.h - Uso Principal

La clase `Detalle` es el principal consumidor de la clase `Item`:

#### Atributos
- **Línea 7**: `Item _detalleVenta[30]{}`
  - Array que almacena hasta 30 items de venta

#### Métodos Getter
- **Línea 24**: `Item getItem(int pos)`
  - Retorna un Item en la posición especificada
- **Línea 29**: Retorna `Item()` vacío cuando está fuera de rango

#### Métodos de Gestión
- **Línea 36**: `void agregarItem(Item nuevoItem)`
  - Declaración del método para agregar un nuevo item
- **Línea 37**: `void modificarItem(int pos, Item nuevoItem)`
  - Declaración del método para modificar un item existente
- **Línea 62**: Implementación de `agregarItem(Item nuevoItem)`
  - Agrega un nuevo item al array de detalles
- **Línea 67**: Manejo de error cuando se alcanza el máximo de items permitido
- **Línea 72**: Implementación de `modificarItem(int pos, Item nuevoItem)`
  - Modifica un item en una posición específica

### 2. funcionesFactura.h - Operaciones de Factura

Se utiliza la clase Item para operaciones de gestión de facturas:

- **Línea 470**: `Item regItem`
  - Variable local para operaciones con items
- **Línea 554**: `Item regItem`
  - Variable local para operaciones con items
- **Línea 571**: Mensaje: "Seleccione el Nro. de Item que desea modificar"
- **Línea 580**: Mensaje: "Seleccione el Nro. de Item que desea modificar"
- **Línea 647**: Mensaje: "Seleccione el Nro. de Item que desea borrar"
- **Línea 656**: Mensaje: "Seleccione el Nro. de Item que desea borrar"
- **Línea 660**: `Item regItem`
  - Variable local para operaciones de borrado

### 3. funcionesEmision.h - Visualización

- **Línea 70**: `cout << left << setw(5) << "Item"`
  - Impresión del encabezado "Item" en tablas de emisión

### 4. Emision.h - Formato de Salida

- **Línea 206**: `cout << left << setw(5) << "Item"`
  - Formato de encabezado de tabla para emisiones

### 5. Factura.h - Generación de Archivos

- **Línea 113**: `fprintf(p, "%-5s%11s%-9s%-55s%14s%11s\n", "Item", ...)`
  - Formato de impresión para archivos de factura con columnas:
    - Item
    - Cantidad
    - Cod.Art.
    - Descripción
    - P.Unitario
    - Importe

## Archivos de Salida

Los archivos de texto generados en las carpetas `output/PRESUPUESTOS` y `output/NOTAS DE CREDITO` incluyen la palabra "Item" en sus encabezados de tabla.

## Flujo de Uso Típico

1. Un `Item` se crea con información de un `Articulo`, cantidad y tipo de cliente
2. El `Item` se agrega a un objeto `Detalle` mediante `agregarItem()`
3. El `Detalle` puede contener hasta 30 items
4. Los items pueden ser modificados o borrados mediante las funciones en `funcionesFactura.h`
5. Los items se visualizan y se generan en archivos de salida (facturas, presupuestos, notas de crédito)

## Estructura de Datos

```
Factura/Presupuesto/Nota de Crédito
    └── Detalle
            └── Item[30] (array de items)
                    ├── Información del artículo
                    ├── Cantidad
                    └── Precios
```

## Notas Importantes

- El límite máximo de items por detalle es de **30 items**
- Cuando se intenta agregar más items del permitido, se muestra un mensaje de error
- Si se solicita un item fuera de rango, se retorna un `Item()` vacío
