# Hoja de Ruta: Sistema de Múltiples Contactos por Entidad

## Objetivo
Implementar un sistema de gestión de contactos independiente que permita asociar múltiples contactos a Clientes y Proveedores, utilizando una arquitectura relacional con archivos binarios.

---

## Arquitectura Propuesta

### Modelo de Datos
```
Cliente/Proveedor (Entidad)
    |
    | (1 a N)
    |
Contactos
```

### Archivos del Sistema
- `data/clientes.dat` - Datos de clientes (sin contactos embebidos)
- `data/proveedores.dat` - Datos de proveedores (sin contactos embebidos)
- `data/contactos.dat` - **NUEVO** - Todos los contactos del sistema
- Relación: Cada contacto tiene un `idEntidad` y un `tipoEntidad` (C=Cliente, P=Proveedor)

---

## Paso a Paso de Implementación

### **FASE 1: Modificar la clase Contacto**

#### 1.1. Actualizar `clsGlobales.h` - Clase Contacto
**Cambios necesarios:**
- Agregar campo `int _idEntidad` (ID del cliente o proveedor al que pertenece)
- Agregar campo `char _tipoEntidad` ('C' para Cliente, 'P' para Proveedor)
- Agregar campo `int _idContacto` (ID único del contacto)
- Agregar campo `bool _estado` (para borrado lógico)
- Actualizar setters y getters correspondientes
- Modificar métodos `Cargar()` y `Mostrar()`

**Archivos a modificar:**
- `src/globales/clsGlobales.h`

---

### **FASE 2: Modificar la clase Entidad**

#### 2.1. Eliminar contacto embebido de Entidad
**Cambios necesarios:**
- Eliminar el atributo `Contacto _contacto`
- Eliminar `setContacto()` y `getContacto()`
- Modificar `Entidad::Cargar()` para NO cargar contacto
- Modificar `Entidad::Mostrar()` para NO mostrar contacto

**Archivos a modificar:**
- `src/clases/Entidad.h`

---

### **FASE 3: Crear Archivo de Gestión de Contactos**

#### 3.1. Crear `ArchivoContactos.h`
**Funcionalidades a implementar:**
```cpp
class ArchivoContactos {
    // CRUD básico
    int agregarContacto(Contacto& contacto);
    Contacto leerContacto(int idContacto);
    bool modificarContacto(int idContacto, Contacto& contacto);
    bool eliminarContacto(int idContacto); // Borrado lógico

    // Consultas relacionales
    int contarContactosPorEntidad(int idEntidad, char tipoEntidad);
    Contacto* listarContactosPorEntidad(int idEntidad, char tipoEntidad, int& cantidad);

    // Utilidades
    int obtenerProximoId();
    bool existeContacto(int idContacto);
};
```

**Archivo a crear:**
- `src/archivos/ArchivoContactos.h`

---

### **FASE 4: Crear Funciones de Gestión de Contactos**

#### 4.1. Crear `funcionesContacto.h`
**Funcionalidades a implementar:**
```cpp
// Menu de contactos para una entidad
void menuContactos(int idEntidad, char tipoEntidad);

// CRUD con interfaz de usuario
void agregarContacto(int idEntidad, char tipoEntidad);
void listarContactos(int idEntidad, char tipoEntidad);
void modificarContacto(int idEntidad, char tipoEntidad);
void eliminarContacto(int idEntidad, char tipoEntidad);
void buscarContactoPorNombre(int idEntidad, char tipoEntidad);
```

**Archivo a crear:**
- `src/controladores/funcionesContacto.h`

---

### **FASE 5: Integrar con Clientes**

#### 5.1. Actualizar `funcionesCliente.h`
**Cambios necesarios:**
- En el menú de Cliente, agregar opción "Gestionar Contactos"
- Al agregar cliente, preguntar si desea agregar contactos inmediatamente
- Al modificar cliente, permitir acceder a gestión de contactos
- Al mostrar cliente, mostrar cantidad de contactos asociados
- Al eliminar cliente (borrado lógico), eliminar sus contactos asociados

**Funciones a modificar:**
- `menuCliente()`
- `agregarCliente()`
- `modificarCliente()`
- `mostrarCliente()`
- `eliminarCliente()`

**Archivos a modificar:**
- `src/controladores/funcionesCliente.h`

---

### **FASE 6: Integrar con Proveedores**

#### 6.1. Actualizar `funcionesProveedor.h`
**Cambios necesarios:**
- En el menú de Proveedor, agregar opción "Gestionar Contactos"
- Al agregar proveedor, preguntar si desea agregar contactos inmediatamente
- Al modificar proveedor, permitir acceder a gestión de contactos
- Al mostrar proveedor, mostrar cantidad de contactos asociados
- Al eliminar proveedor (borrado lógico), eliminar sus contactos asociados

**Funciones a modificar:**
- `menuProveedor()`
- `agregarProveedor()`
- `modificarProveedor()`
- `mostrarProveedor()`
- `eliminarProveedor()`

**Archivos a modificar:**
- `src/controladores/funcionesProveedor.h`

---

### **FASE 7: Migración de Datos Existentes**

#### 7.1. Crear script de migración
**Funcionalidad:**
- Leer todos los clientes existentes de `clientes.dat`
- Extraer el contacto de cada cliente
- Crear nuevo registro en `contactos.dat` con:
  - `idEntidad` = ID del cliente
  - `tipoEntidad` = 'C'
  - Datos del contacto
- Repetir para proveedores con `tipoEntidad` = 'P'

**Archivo a crear:**
- `src/migracion/migrarContactos.h`
- Opción en menú principal: "Migrar datos de contactos (solo una vez)"

---

### **FASE 8: Actualizar Cliente.h y Proveedor.h**

#### 8.1. Ajustar Cargar() y Mostrar()
**Cambios necesarios:**
- `Cliente::Cargar()` - Ya no carga contacto embebido
- `Cliente::Mostrar()` - Opcionalmente mostrar cantidad de contactos
- `Proveedor::Cargar()` - Ya no carga contacto embebido
- `Proveedor::Mostrar()` - Opcionalmente mostrar cantidad de contactos

**Archivos a modificar:**
- `src/clases/Cliente.h`
- `src/clases/Proveedor.h`

---

### **FASE 9: Pruebas y Validación**

#### 9.1. Plan de pruebas
1. **Crear contactos:**
   - Agregar múltiples contactos a un cliente
   - Agregar múltiples contactos a un proveedor
   - Verificar que se guarden correctamente en `contactos.dat`

2. **Listar contactos:**
   - Verificar que se listen solo los contactos del cliente/proveedor seleccionado
   - Verificar separación entre contactos de clientes y proveedores

3. **Modificar contactos:**
   - Modificar datos de un contacto
   - Verificar persistencia

4. **Eliminar contactos:**
   - Eliminar contacto (borrado lógico)
   - Verificar que no se muestre en listados

5. **Eliminar entidad:**
   - Eliminar un cliente con contactos
   - Verificar que sus contactos también se eliminen (borrado lógico)

6. **Migración:**
   - Ejecutar migración en datos existentes
   - Verificar integridad de datos migrados

---

## Estructura de Archivos Final

```
Sistema-de-Gestion/
├── data/
│   ├── clientes.dat          (sin contactos embebidos)
│   ├── proveedores.dat       (sin contactos embebidos)
│   ├── contactos.dat         (NUEVO - archivo relacional)
│   ├── articulos.dat
│   ├── vendedores.dat
│   └── facturas.dat
├── src/
│   ├── clases/
│   │   ├── Entidad.h         (MODIFICAR - sin contacto embebido)
│   │   ├── Cliente.h         (MODIFICAR - ajustar Cargar/Mostrar)
│   │   └── Proveedor.h       (MODIFICAR - ajustar Cargar/Mostrar)
│   ├── globales/
│   │   └── clsGlobales.h     (MODIFICAR - nueva estructura Contacto)
│   ├── archivos/
│   │   └── ArchivoContactos.h (NUEVO)
│   ├── controladores/
│   │   ├── funcionesCliente.h     (MODIFICAR)
│   │   ├── funcionesProveedor.h   (MODIFICAR)
│   │   └── funcionesContacto.h    (NUEVO)
│   └── migracion/
│       └── migrarContactos.h      (NUEVO)
└── PROVISORIOS/
    └── hoja-de-ruta-contactos.md
```

---

## Ventajas de esta Arquitectura

1. **Escalabilidad:** Cantidad ilimitada de contactos por entidad
2. **Normalización:** No hay redundancia de datos
3. **Flexibilidad:** Fácil agregar campos adicionales a contactos
4. **Reutilización:** La lógica de contactos es independiente
5. **Integridad:** Al eliminar entidad, se eliminan sus contactos
6. **Consultas:** Fácil buscar todos los contactos de una entidad

---

## Consideraciones Importantes

### Borrado Lógico
- Usar campo `_estado` para marcar como eliminado
- No borrar físicamente los registros
- Filtrar registros con `_estado = false` en listados

### IDs Únicos
- Contactos tienen ID único autoincremental
- No reutilizar IDs de contactos eliminados
- Mantener integridad referencial con `idEntidad`

### Validaciones
- Verificar que el `idEntidad` exista antes de crear contacto
- Validar formato de email
- Validar formato de teléfono
- Prevenir contactos duplicados (mismo nombre y teléfono)

---

## Tiempo Estimado de Implementación

- **Fase 1:** 30 minutos
- **Fase 2:** 20 minutos
- **Fase 3:** 1 hora
- **Fase 4:** 1 hora
- **Fase 5:** 45 minutos
- **Fase 6:** 45 minutos
- **Fase 7:** 30 minutos
- **Fase 8:** 20 minutos
- **Fase 9:** 1 hora (pruebas exhaustivas)

**Total estimado:** 6 horas

---

## Orden de Ejecución Recomendado

1. Fase 1 (Modificar Contacto)
2. Fase 3 (Crear ArchivoContactos)
3. Fase 4 (Crear funcionesContacto)
4. Fase 2 (Modificar Entidad)
5. Fase 8 (Actualizar Cliente y Proveedor)
6. Fase 5 (Integrar con Clientes)
7. Fase 6 (Integrar con Proveedores)
8. Fase 7 (Migración de datos)
9. Fase 9 (Pruebas)

---

## Notas Finales

- **Backup:** Respaldar archivos `.dat` existentes antes de comenzar
- **Git:** Hacer commits frecuentes al finalizar cada fase
- **Testing:** Probar cada fase antes de continuar con la siguiente
- **Documentación:** Comentar el código nuevo adecuadamente

---

**Fecha de creación:** 2025-11-03
**Versión:** 1.0
