#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

class Producto;
class MateriaPrima;
class Proveedor;
class Venta;

/* Compara los parámetros con la fecha del sistema. Devuelve -1 si es una fecha anterior y 1 si es posterior */
int compararFechaSistema(int, int, int);

/* Devuelve si un año es bisiesto o no */
bool esBisiesto(int anio);

/* Carga en un vector de caracteres una cadena ingresada por teclado*/
void cargarCadena(char *, int);

/* Muestra el menú de productos */
void menuProductos();

/* Muestra el menú de materias primas */
void menuMateriasPrimas();

/* Muestra el menú de proveedores */
void menuProveedores();

/* Muestra el menú de ventas */
void menuVentas();

/* Muestra el menú de reporte */
void menuReporte();

/* Muestra el menú de configuración */
void menuConfiguracion();

/* Realiza el alta de un nuevo producto */
bool nuevoProducto();

/* Lista las propiedades del producto si existe el código */
void listarProducto();

/* Lista las propiedades de todos los productos */
void listarProductos();

/* Permite modificar las propiedades de un producto buscado por código */
bool modificarProducto();

/* Realiza la baja lógica de un producto */
bool eliminarProducto();

/* Realiza el alta de una nueva materia prima */
bool nuevaMateriaPrima();

/* Lista las propiedades de la materia prima si existe el código */
void listarMateriaPrima();

/* Lista las propiedades de todas las materias primas */
void listarMateriasPrimas();

/* Permite modificar las propiedades de una materia prima buscada por código */
bool modificarMateriaPrima();

/* Realiza la baja lógica de una materia prima */
bool eliminarMateriaPrima();

/* Realiza el alta de un nuevo proveedor */
bool nuevoProveedor();

/* Lista las propiedades del proveedor si existe el código */
void listarProveedor();

/* Lista las propiedades de todos los proveedores */
void listarProveedores();

/* Permite modificar las propiedades de un proveedor buscado por código */
bool modificarProveedor();

/* Realiza la baja lógica de un proveedor */
bool eliminarProveedor();

/* Realiza el alta de una nueva venta */
bool nuevaVenta();

/* Lista las propiedades de la venta si existe el ID de venta */
void listarVenta();

/* Lista las propiedades de todas las ventas */
void listarVentas();

/* Permite modificar las propiedades de una venta buscada por su ID de venta */
bool modificarVenta();

/* Realiza la baja lógica de una venta */
bool eliminarVenta();

/* Genera el archivo reporte con los datos de los archivos */
bool generarReporte();

/* Muestra las propiedades del reporte si este existe */
void mostrarReporte();

/* Devuelve la cantidad de registros de ventas que hay en el archivo */
int contarRegistrosVentas();

/* Lista el producto si el código ingresado por el usuario existe en el archivo */
void listarProducto();

/* Devuelve como entero la posición del parámetro si existe en el archivo, sino -1 */
int buscarPosCodigoProducto(const char *);

/* Devuelve como entero la posición del parámetro si existe en el archivo, sino -1 */
int buscarPosCodigoProveedor(const char *);

/* Devuelve como entero la posición del parámetro si existe en el archivo, sino -1 */
int buscarPosCodigoMateriaPrima(const char *);

/* Devuelve true si la fecha es válida, false en otro caso */
bool comprobarFechaValida(int, int, int);

/* Devuelve como entero la posición del parámetro si existe en el archivo, sino -1 */
int buscarPosIdVenta(int);

/* Devuelve la cantidad de registros de ventas activas que hay en el archivo */
int calcularCantVentas();

/* Devuelve el monto total acumulado de las ventas activas que hay en el archivo */
float calcularTotalVentas();

/* Devuelve el ID de la venta activa de mayor monto en el archivo */
int calcularVentaMax();

/* Devuelve el monto de la venta máxima en el archivo */
float calcularValorVentaMax();

/* Devuelve el caracter correspondiente a la forma de pago más usada */
char calcularFormaPagoMax();

/* Devuelve, a través de un ingreso, un valor bool para realizar la opción elegida o no */
bool confirmarEleccion();

/* Genera archivos de copia de seguridad de cada uno de los archivos de datos del sistema */
bool realizarBackup();

/* Restaura los archivos de backup sobre los archivos de datos del sistema */
bool restaurarBackup();

/* Devuelve la cantidad de registros de productos que hay en el archivo */
int contarRegistrosProductos();

/* Devuelve la cantidad de registros de materias primas que hay en el archivo */
int contarRegistrosMateriasPrimas();

/* Devuelve la cantidad de registros de proveedores que hay en el archivo */
int contarRegistrosProveedores();

/* Devuelve la cantidad de registros de reporte que hay en el archivo */
int contarRegistrosReporte();

/* Imprime un rectángulo en pantalla según las coordenadas de inicio, el ancho y el alto*/
void dibujarRectangulo(int, int, int, int);

#endif // PROTOTIPOS_H_INCLUDED
