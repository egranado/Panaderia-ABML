#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "rlutil.h"
#define waitkey rlutil::anykey("Presione una tecla para continuar...\n")

int compararFechaSistema(int dia, int mes, int anio){
    time_t actual = time(0);
    tm *tiempo_local = localtime(&actual);
    if(anio > (1900 + tiempo_local->tm_year)){
        return 1;
    }
    if(anio < (1900 + tiempo_local->tm_year)){
        return -1;
    }
    if(mes > (1 + tiempo_local->tm_mon)){
        return 1;
    }
    if(mes < (1 + tiempo_local->tm_mon)){
        return -1;
    }
    if(dia > tiempo_local->tm_mday){
        return 1;
    }
    return -1;
}

bool esBisiesto(int anio){
    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

void cargarCadena(char *pal, int tam){
    fflush(stdin);
    cin.getline(pal, tam);
}

void menuProductos(){
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(40, 8);
        cout << "Menú Productos";
        gotoxy(13, 10);
        cout << "Elija una opción (cualquier otro entero para volver al menú principal)";
        gotoxy(37, 13);
        cout << "1. Nuevo Producto";
        gotoxy(37, 15);
        cout << "2. Listar Producto";
        gotoxy(37, 17);
        cout << "3. Listar Productos";
        gotoxy(37, 19);
        cout << "4. Modificar Producto";
        gotoxy(37, 21);
        cout << "5. Eliminar Producto";
        gotoxy(37, 24);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                if(nuevoProducto()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Producto agregado" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo agregar el producto" << endl;
                    rlutil::resetColor();
                }
                break;
            case 2:
                listarProducto();
                break;
            case 3:
                listarProductos();
                break;
            case 4:
                if(modificarProducto()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Modificación del producto realizada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo realizar la modificación del producto" << endl;
                    rlutil::resetColor();
                }
                break;
            case 5:
                if(eliminarProducto()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Producto eliminado" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo eliminar el producto" << endl;
                    rlutil::resetColor();
                }
                break;
            default:
                return;
        }
        waitkey;
    }
    return;
}

void menuMateriasPrimas(){
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(40, 8);
        cout << "Menú Materias Primas";
        gotoxy(13, 10);
        cout << "Elija una opción (cualquier otro entero para volver al menú principal)";
        gotoxy(37, 13);
        cout << "1. Nueva Materia Prima";
        gotoxy(37, 15);
        cout << "2. Listar Materia Prima";
        gotoxy(37, 17);
        cout << "3. Listar Materias Primas";
        gotoxy(37, 19);
        cout << "4. Modificar Materia Prima";
        gotoxy(37, 21);
        cout << "5. Eliminar Materia Prima";
        gotoxy(37, 24);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                if(nuevaMateriaPrima()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Materia prima agregada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo agregar la materia prima" << endl;
                    rlutil::resetColor();
                }
                break;
            case 2:
                listarMateriaPrima();
                break;
            case 3:
                listarMateriasPrimas();
                break;
            case 4:
                if(modificarMateriaPrima()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Modificación de la materia prima realizada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo realizar la modificación de la materia prima" << endl;
                    rlutil::resetColor();
                }
                break;
            case 5:
                if(eliminarMateriaPrima()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Materia prima eliminada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo eliminar la materia prima" << endl;
                    rlutil::resetColor();
                }
                break;
            default:
                return;
        }
        waitkey;
    }
}

void menuProveedores(){
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(40, 8);
        cout << "Menú Proveedores";
        gotoxy(13, 10);
        cout << "Elija una opción (cualquier otro entero para volver al menú principal)";
        gotoxy(37, 13);
        cout << "1. Nuevo Proveedor";
        gotoxy(37, 15);
        cout << "2. Listar Proveedor";
        gotoxy(37, 17);
        cout << "3. Listar Proveedores";
        gotoxy(37, 19);
        cout << "4. Modificar Proveedor";
        gotoxy(37, 21);
        cout << "5. Eliminar Proveedor";
        gotoxy(37, 24);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                if(nuevoProveedor()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Proveedor agregado" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo agregar el proveedor" << endl;
                    rlutil::resetColor();
                }
                break;
            case 2:
                listarProveedor();
                break;
            case 3:
                listarProveedores();
                break;
            case 4:
                if(modificarProveedor()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Modificación del proveedor realizada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo realizar la modificación del proveedor" << endl;
                    rlutil::resetColor();
                }
                break;
            case 5:
                if(eliminarProveedor()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Proveedor eliminado" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo eliminar el proveedor" << endl;
                    rlutil::resetColor();
                }
                break;
            default:
                return;
        }
        waitkey;
    }
}

void menuVentas(){
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(40, 8);
        cout << "Menú Ventas" << endl;
        gotoxy(13, 10);
        cout << "Elija una opción (cualquier otro entero para volver al menú principal)";
        gotoxy(37, 13);
        cout << "1. Nueva Venta";
        gotoxy(37, 15);
        cout << "2. Listar Venta";
        gotoxy(37, 17);
        cout << "3. Listar Ventas";
        gotoxy(37, 19);
        cout << "4. Modificar Venta";
        gotoxy(37, 21);
        cout << "5. Eliminar Venta";
        gotoxy(37, 24);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                if(nuevaVenta()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Venta agregada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo agregar la venta" << endl;
                    rlutil::resetColor();
                }
                break;
            case 2:
                listarVenta();
                break;
            case 3:
                listarVentas();
                break;
            case 4:
                if(modificarVenta()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Modificación de la venta realizada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo realizar la modificación de la venta" << endl;
                    rlutil::resetColor();
                }
                break;
            case 5:
                if(eliminarVenta()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Venta eliminada" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo eliminar la venta" << endl;
                    rlutil::resetColor();
                }
                break;
            default:
                return;
        }
        waitkey;
    }
}

void menuReporte(){
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(40, 8);
        cout << "Menú Reporte";
        gotoxy(13, 10);
        cout << "Elija una opción (cualquier otro entero para volver al menú principal)";
        gotoxy(37, 13);
        cout << "1. Generar Reporte";
        gotoxy(37, 15);
        cout << "2. Mostrar Reporte";
        gotoxy(37,18);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                if(generarReporte()){
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Reporte generado" << endl;
                    rlutil::resetColor();
                } else{
                    rlutil::setColor(rlutil::RED);
                    cout << "No se pudo generar el reporte" << endl;
                    rlutil::resetColor();
                }
                break;
            case 2:
                mostrarReporte();
                break;
            default:
                return;
        }
        waitkey;
    }
}

void menuConfiguracion(){
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(40, 8);
        cout << "Menú Configuración";
        gotoxy(13, 10);
        cout << "Elija una opción (cualquier otro entero para volver al menú principal)";
        gotoxy(37, 13);
        cout << "1. Realizar Backup";
        gotoxy(37, 15);
        cout << "2. Restaurar Backup";
        gotoxy(37, 18);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                if(confirmarEleccion()){
                    rlutil::cls();
                    if(realizarBackup()){
                        rlutil::setColor(rlutil::GREEN);
                        cout << "Backup realizado con éxito" << endl;
                        rlutil::resetColor();
                    } else{
                        rlutil::setColor(rlutil::RED);
                        cout << "No se pudo realizar el backup" << endl;
                        rlutil::resetColor();
                    }
                }
                break;
            case 2:
                if(confirmarEleccion()){
                    rlutil::cls();
                    if(restaurarBackup()){
                        rlutil::setColor(rlutil::GREEN);
                        cout << "Archivos de backup restaurados sobre los archivos de datos del sistema con éxito" << endl;
                        rlutil::resetColor();
                    } else{
                        rlutil::setColor(rlutil::RED);
                        cout << "No se pudieron restaurar los archivos de backup" << endl;
                        rlutil::resetColor();
                    }
                }
                break;
            default:
                return;
        }
        waitkey;
    }
}

int contarRegistrosVentas(){
    FILE *archivoVentas;
    int cantReg;
    archivoVentas = fopen(ARCHIVO_VENTAS, "rb");
    if(archivoVentas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fseek(archivoVentas, 0, 2);
    cantReg = ftell(archivoVentas) / sizeof(Venta);
    fclose(archivoVentas);
    return cantReg;
}

bool nuevoProducto(){
    Producto regProd;
    if(regProd.cargar()){
        return regProd.grabarEnDisco();
    }
    return false;
}

void listarProducto(){
    Producto regProd;
    char codigo[10];
    int posCodigo;
    cout << "Código del producto a listar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoProducto(codigo);
    if(posCodigo < 0){
        cout << "No existe el producto en el sistema" << endl;
        return;
    }
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Descripción";
    gotoxy(50, 1);
    cout << "Stock";
    gotoxy(60, 1);
    cout << "Precio";
    if(regProd.leerDeDisco(posCodigo)){
        regProd.mostrar(3);
    }
    cout << endl << endl;
}

int buscarPosCodigoProducto(const char *codigo){
    Producto regProd;
    int pos = 0, posLec = 0;
    while(regProd.leerDeDisco(posLec++)){
        if(strcmp(regProd.getCodigo(), codigo) == 0 && regProd.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}

void listarProductos(){
    Producto regProd;
    int posLec = 0, columna = 3;
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Descripción";
    gotoxy(50, 1);
    cout << "Stock";
    gotoxy(60, 1);
    cout << "Precio";
    while(regProd.leerDeDisco(posLec++)){
        if(regProd.getEstado() == true){
            regProd.mostrar(columna++);
        }
    }
    cout << endl << endl;
}

bool modificarProducto(){
    Producto regProd;
    char codigo[10];
    int posCodigo, stock, opcion;
    float precio;
    cout << "Código del producto a modificar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoProducto(codigo);
    if(posCodigo < 0){
        cout << "No existe el producto en el sistema" << endl;
        return false;
    }
    if(regProd.leerDeDisco(posCodigo) == false){
        return false;
    }
    while(true){
        cout << "Ingresar 1 para modificar el stock, 2 para el precio o 0 para cancelar: ";
        cin >> opcion;
        if(opcion == 1 || opcion == 2 || opcion == 0){
            break;
        }
    }
    if(opcion == 0){
        return false;
    }
    rlutil::cls();
    if(opcion == 1){
        cout << "Nuevo stock: ";
        cin >> stock;
        if(stock < 0){
            cout << "El stock no puede ser negativo" << endl;
            return false;
        }
        regProd.setStock(stock);
    }
    if(opcion == 2){
        cout << "Nuevo precio: ";
        cin >> precio;
        if(precio <= 0){
            cout << "El precio debe ser positivo" << endl;
            return false;
        }
        regProd.setPrecio(precio);
    }
    return regProd.modificarEnDisco(posCodigo);
}

bool eliminarProducto(){
    Producto regProd;
    char codigo[10];
    int posCodigo;
    cout << "Código del producto a eliminar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoProducto(codigo);
    if(posCodigo < 0){
        cout << "No existe el producto en el sistema" << endl;
        return false;
    }
    if(regProd.leerDeDisco(posCodigo) == false){
        return false;
    }
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Descripción";
    gotoxy(50, 1);
    cout << "Stock";
    gotoxy(60, 1);
    cout << "Precio";
    regProd.mostrar(3);
    cout << endl << endl;
    if(!confirmarEleccion()){
        return false;
    }
    regProd.setEstado(false);
    return regProd.modificarEnDisco(posCodigo);
}

bool nuevaMateriaPrima(){
    MateriaPrima regMatPrima;
    if(regMatPrima.cargar()){
        return regMatPrima.grabarEnDisco();
    }
    return false;
}

int buscarPosCodigoProveedor(const char *codigo){
    Proveedor regProv;
    int pos = 0, posLec = 0;
    while(regProv.leerDeDisco(posLec++)){
        if(strcmp(regProv.getCodigo(), codigo) == 0 && regProv.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}

void listarMateriaPrima(){
    MateriaPrima regMatPrim;
    char codigo[10];
    int posCodigo;
    cout << "Código de la materia prima a listar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoMateriaPrima(codigo);
    if(posCodigo < 0){
        cout << "No existe la materia prima en el sistema" << endl;
        return;
    }
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Descripción";
    gotoxy(50, 1);
    cout << "Código Proveedor";
    gotoxy(71, 1);
    cout << "Stock";
    gotoxy(81, 1);
    cout << "Precio";
    if(regMatPrim.leerDeDisco(posCodigo)){
        regMatPrim.mostrar(3);
    }
    cout << endl << endl;
}

int buscarPosCodigoMateriaPrima(const char *codigo){
    MateriaPrima regMatPrim;
    int pos = 0, posLec = 0;
    while(regMatPrim.leerDeDisco(posLec++)){
        if(strcmp(regMatPrim.getCodigo(), codigo) == 0 && regMatPrim.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}

void listarMateriasPrimas(){
    MateriaPrima regMatPrim;
    int posLec = 0, columna = 3;
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Descripción";
    gotoxy(50, 1);
    cout << "Código Proveedor";
    gotoxy(71, 1);
    cout << "Stock";
    gotoxy(81, 1);
    cout << "Precio";
    while(regMatPrim.leerDeDisco(posLec++)){
        if(regMatPrim.getEstado() == true){
            regMatPrim.mostrar(columna++);
        }
    }
    cout << endl << endl;
}

bool modificarMateriaPrima(){
    MateriaPrima regMatPrim;
    char codigo[10];
    int posCodigo, stock, opcion;
    float precio;
    cout << "Código de la materia prima a modificar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoMateriaPrima(codigo);
    if(posCodigo < 0){
        cout << "No existe la materia prima en el sistema" << endl;
        return false;
    }
    if(regMatPrim.leerDeDisco(posCodigo) == false){
        return false;
    }
    while(true){
        cout << "Ingresar 1 para modificar el stock, 2 para el precio o 0 para cancelar: ";
        cin >> opcion;
        if(opcion == 1 || opcion == 2 || opcion == 0){
            break;
        }
    }
    if(opcion == 0){
        return false;
    }
    rlutil::cls();
    if(opcion == 1){
        cout << "Nuevo stock: ";
        cin >> stock;
        if(stock < 0){
            cout << "El stock no puede ser negativo" << endl;
            return false;
        }
        regMatPrim.setStock(stock);
    }
    if(opcion == 2){
        cout << "Nuevo precio: ";
        cin >> precio;
        if(precio <= 0){
            cout << "El precio debe ser positivo" << endl;
            return false;
        }
        regMatPrim.setPrecio(precio);
    }
    return regMatPrim.modificarEnDisco(posCodigo);
}

bool eliminarMateriaPrima(){
    MateriaPrima regMatPrim;
    char codigo[10];
    int posCodigo;
    cout << "Código de la materia prima a eliminar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoMateriaPrima(codigo);
    if(posCodigo < 0){
        cout << "No existe la materia prima en el sistema" << endl;
        return false;
    }
    if(regMatPrim.leerDeDisco(posCodigo) == false){
        return false;
    }
    if(!confirmarEleccion()){
        return false;
    }
    regMatPrim.setEstado(false);
    return regMatPrim.modificarEnDisco(posCodigo);
}

bool nuevoProveedor(){
    Proveedor regProv;
    if(regProv.cargar()){
        return regProv.grabarEnDisco();
    }
    return false;
}

void listarProveedor(){
    Proveedor regProv;
    char codigo[10];
    int posCodigo;
    cout << "Código del proveedor a listar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoProveedor(codigo);
    if(posCodigo < 0){
        cout << "No existe el proveedor en el sistema" << endl;
        return;
    }
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Nombre Empresa";
    gotoxy(45, 1);
    cout << "Teléfono";
    gotoxy(65, 1);
    cout << "Email";
    if(regProv.leerDeDisco(posCodigo)){
        regProv.mostrar(3);
    }
    cout << endl << endl;
}

void listarProveedores(){
    Proveedor regProv;
    int posLec = 0, columna = 3;
    gotoxy(5, 1);
    cout << "Código";
    gotoxy(20, 1);
    cout << "Nombre Empresa";
    gotoxy(45, 1);
    cout << "Teléfono";
    gotoxy(65, 1);
    cout << "Email";
    while(regProv.leerDeDisco(posLec++)){
        if(regProv.getEstado() == true){
            regProv.mostrar(columna++);
        }
    }
    cout << endl << endl;
}

bool modificarProveedor(){
    Proveedor regProv;
    char codigo[10], telefono[15], email[30];
    int posCodigo, opcion;
    cout << "Código del proveedor a modificar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoProveedor(codigo);
    if(posCodigo < 0){
        cout << "No existe el proveedor en el sistema" << endl;
        return false;
    }
    if(regProv.leerDeDisco(posCodigo) == false){
        return false;
    }
    while(true){
        cout << "Ingresar 1 para modificar el teléfono, 2 para el email o 0 para cancelar: ";
        cin >> opcion;
        if(opcion == 1 || opcion == 2 || opcion == 0){
            break;
        }
    }
    if(opcion == 0){
        return false;
    }
    rlutil::cls();
    if(opcion == 1){
        cout << "Nuevo teléfono: ";
        cargarCadena(telefono, 15);
        if(strlen(telefono) == 0 || isspace(telefono[0])){
            cout << "El teléfono no puede estar vacío" << endl;
            return false;
        }
        regProv.setTelefono(telefono);
    }
    if(opcion == 2){
        cout << "Nuevo email: ";
        cargarCadena(email, 30);
        if(strlen(email) == 0 || isspace(email[0])){
            cout << "El email no puede estar vacío" << endl;
            return false;
        }
        regProv.setEmail(email);
    }
    return regProv.modificarEnDisco(posCodigo);
}

bool eliminarProveedor(){
    Proveedor regProv;
    char codigo[10];
    int posCodigo;
    cout << "Código del proveedor a eliminar: ";
    cargarCadena(codigo, 10);
    rlutil::cls();
    posCodigo = buscarPosCodigoProveedor(codigo);
    if(posCodigo < 0){
        cout << "No existe el proveedor en el sistema" << endl;
        return false;
    }
    if(regProv.leerDeDisco(posCodigo) == false){
        return false;
    }
    if(!confirmarEleccion()){
        return false;
    }
    regProv.setEstado(false);
    return regProv.modificarEnDisco(posCodigo);
}

bool nuevaVenta(){
    Venta regVenta;
    if(regVenta.cargar()){
        return regVenta.grabarEnDisco();
    }
    return false;
}

bool comprobarFechaValida(int dia, int mes, int anio){
    if(dia < 1 || dia > 31){
        return false;
    }
    if(mes < 1 || mes > 12){
        return false;
    }
    if(anio < 2017 || anio > 2099){
        return false;
    }
    if(dia == 31 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
        return false;
    }
    if(mes == 2 && (!esBisiesto(anio) && dia > 28)){
        return false;
    }
    if(mes == 2 && esBisiesto(anio) && dia > 29){
        return false;
    }
    return true;
}

void listarVenta(){
    Venta regVenta;
    int idVenta, posId;
    cout << "ID de la venta a listar: ";
    cin >> idVenta;
    rlutil::cls();
    posId = buscarPosIdVenta(idVenta);
    if(posId < 0){
        cout << "No existe la venta en el sistema" << endl;
        return;
    }
    gotoxy(5, 1);
    cout << "ID Venta";
    gotoxy(18, 1);
    cout << "Fecha";
    gotoxy(31, 1);
    cout << "Forma Pago";
    gotoxy(46, 1);
    cout << "Código Producto";
    gotoxy(66, 1);
    cout << "Cantidad";
    gotoxy(79, 1);
    cout << "Total";
    if(regVenta.leerDeDisco(posId)){
        regVenta.mostrar(3);
    }
    cout << endl << endl;
}

int buscarPosIdVenta(int idVenta){
    Venta regVenta;
    int pos = 0, posLec = 0;
    while(regVenta.leerDeDisco(posLec++)){
        if(regVenta.getIdVenta() == idVenta && regVenta.getEstado() == true){
            return pos;
        }
        pos++;
    }
    return -1;
}

void listarVentas(){
    Venta regVenta;
    int posLec = 0, columna = 3;
    gotoxy(5, 1);
    cout << "ID Venta";
    gotoxy(18, 1);
    cout << "Fecha";
    gotoxy(31, 1);
    cout << "Forma Pago";
    gotoxy(46, 1);
    cout << "Código Producto";
    gotoxy(66, 1);
    cout << "Cantidad";
    gotoxy(79, 1);
    cout << "Total";
    while(regVenta.leerDeDisco(posLec++)){
        if(regVenta.getEstado() == true){
            regVenta.mostrar(columna++);
        }
    }
    cout << endl << endl;
}

bool modificarVenta(){
    Venta regVenta;
    int idVenta, posIdVenta, opcion, posCodigo, cantidad;
    char formaPago;
    float total;
    cout << "ID de la venta a modificar: ";
    cin >> idVenta;
    rlutil::cls();
    posIdVenta = buscarPosIdVenta(idVenta);
    if(posIdVenta < 0){
        cout << "No existe la venta en el sistema" << endl;
        return false;
    }
    if(regVenta.leerDeDisco(posIdVenta) == false){
        return false;
    }
    while(true){
        cout << "Ingresar 1 para modificar la forma de pago, 2 para la cantidad o 0 para volver: ";
        cin >> opcion;
        if(opcion == 1 || opcion == 2 || opcion == 0){
            break;
        }
    }
    if(opcion == 0){
        return false;
    }
    rlutil::cls();
    if(opcion == 1){
    cout << "Nueva forma de pago (E, D o C): ";
        cin >> formaPago;
        formaPago = toupper(formaPago);
        if(formaPago != 'E' && formaPago != 'D' && formaPago != 'C'){
            cout << "La forma de pago debe ser E, D o C" << endl;
            return false;
        }
        regVenta.setFormaPago(formaPago);
    }
    if(opcion == 2){
        cout << "Nueva cantidad: ";
        cin >> cantidad;
        if(cantidad <= 0){
            cout << "La cantidad de productos debe ser positiva" << endl;
            return false;
        }
        Producto aux;
        posCodigo = buscarPosCodigoProducto(regVenta.getCodigoProducto());
        if(posCodigo < 0){
            cout << "No existe el código del producto en el sistema" << endl;
            return false;
        }
        aux.leerDeDisco(posCodigo);
        if(cantidad > aux.getStock() + regVenta.getCantidad()){
        cout << "No hay stock suficiente del producto para esa cantidad" << endl;
        return false;
        }
        aux.setStock(aux.getStock() + regVenta.getCantidad() - cantidad);
        aux.modificarEnDisco(posCodigo);
        total = cantidad * aux.getPrecio();
        regVenta.setCantidad(cantidad);
        regVenta.setTotal(total);
    }
    return regVenta.modificarEnDisco(posIdVenta);
}

bool eliminarVenta(){
    Venta regVenta;
    int idVenta, posIdVenta, opcion, posCodigo;
    cout << "ID de la venta a eliminar: ";
    cin >> idVenta;
    rlutil::cls();
    posIdVenta = buscarPosIdVenta(idVenta);
    if(posIdVenta < 0){
        cout << "No existe la venta en el sistema" << endl;
        return false;
    }
    if(regVenta.leerDeDisco(posIdVenta) == false){
        return false;
    }
    if(!confirmarEleccion()){
        return false;
    }
    while(true){
        cout << "Ingresar 1 para devolver la cantidad de productos de la venta al stock del sistema o 0 sino: ";
        cin >> opcion;
        if(opcion == 1 || opcion == 0){
            break;
        }
    }
    if(opcion == 1){
        Producto aux;
        posCodigo = buscarPosCodigoProducto(regVenta.getCodigoProducto());
        aux.leerDeDisco(posCodigo);
        aux.setStock(aux.getStock() + regVenta.getCantidad());
        aux.modificarEnDisco(posCodigo);
    }
    regVenta.setEstado(false);
    return regVenta.modificarEnDisco(posIdVenta);
}

bool generarReporte(){
    Reporte regReporte;
    regReporte.setCantVentas(calcularCantVentas());
    regReporte.setTotalVentas(calcularTotalVentas());
    regReporte.setVentaMax(calcularVentaMax());
    regReporte.setValorVentaMax(calcularValorVentaMax());
    regReporte.setFormaPagoMax(calcularFormaPagoMax());
    return regReporte.grabarEnDisco();
}

int calcularCantVentas(){
    int cantVentas = 0, posLec = 0;
    Venta regVenta;
    while(regVenta.leerDeDisco(posLec++)){
        if(regVenta.getEstado() == true){
            cantVentas++;
        }
    }
    return cantVentas;
}

float calcularTotalVentas(){
    int posLec = 0;
    float totalVentas = 0;
    Venta regVenta;
    while(regVenta.leerDeDisco(posLec++)){
        if(regVenta.getEstado() == true){
            totalVentas += regVenta.getTotal();
        }
    }
    return totalVentas;
}

int calcularVentaMax(){
    int idVentaMax = 0;
    float valorVentaMax = 0;
    int posLec = 0;
    Venta regVenta;
    while(regVenta.leerDeDisco(posLec++) == 1){
        if(regVenta.getEstado() == true && regVenta.getTotal() > valorVentaMax){
            idVentaMax = regVenta.getIdVenta();
            valorVentaMax = regVenta.getTotal();
        }
    }
    return idVentaMax;
}

float calcularValorVentaMax(){
    int posLec = 0;
    float valorVentaMax = 0;
    Venta regVenta;
    while(regVenta.leerDeDisco(posLec++)){
        if(regVenta.getEstado() == true && regVenta.getTotal() > valorVentaMax){
            valorVentaMax = regVenta.getTotal();
        }
    }
    return valorVentaMax;
}

char calcularFormaPagoMax(){
    int contE = 0, contD = 0, contC = 0, posLec = 0;
    Venta regVenta;
    while(regVenta.leerDeDisco(posLec++)){
        if(regVenta.getEstado() == true){
            if(toupper(regVenta.getFormaPago()) == 'E'){
                contE++;
            } else if(toupper(regVenta.getFormaPago()) == 'D'){
                contD++;
            } else if(toupper(regVenta.getFormaPago()) == 'C'){
                contC++;
            }
        }
    }
    if(contE >= contD && contE >= contC){
        return 'E';
    }
    if(contD > contE && contD >= contC){
        return 'D';
    }
    if(contC > contE && contC > contD){
        return 'C';
    }
    return 'X';
}

void mostrarReporte(){
    Reporte regRepor;
    if(regRepor.leerDeDisco(0)){
        dibujarRectangulo(22, 5, 50, 20);
        regRepor.mostrar();
    } else{
        cout << "Aún no se generó el reporte" << endl;
    }
}

bool confirmarEleccion(){
    int opcion;
    while(true){
        cout << "Ingresar 1 para confirmar o 0 para cancelar: ";
        cin >> opcion;
        if(opcion == 1){
            return true;
        }
        if(opcion == 0){
            return false;
        }
    }
}

int contarRegistrosProductos(){
    FILE *archivoProductos;
    int cantReg;
    archivoProductos = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(archivoProductos == NULL){
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fseek(archivoProductos, 0, 2);
    cantReg = ftell(archivoProductos) / sizeof(Producto);
    fclose(archivoProductos);
    return cantReg;
}

int contarRegistrosMateriasPrimas(){
    FILE *archivoMateriasPrimas;
    int cantReg;
    archivoMateriasPrimas = fopen(ARCHIVO_MATERIAS_PRIMAS, "rb");
    if(archivoMateriasPrimas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fseek(archivoMateriasPrimas, 0, 2);
    cantReg = ftell(archivoMateriasPrimas) / sizeof(MateriaPrima);
    fclose(archivoMateriasPrimas);
    return cantReg;
}

int contarRegistrosProveedores(){
    FILE *archivoProveedores;
    int cantReg;
    archivoProveedores = fopen(ARCHIVO_PROVEEDORES, "rb");
    if(archivoProveedores == NULL){
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fseek(archivoProveedores, 0, 2);
    cantReg = ftell(archivoProveedores) / sizeof(Proveedor);
    fclose(archivoProveedores);
    return cantReg;
}

int contarRegistrosReporte(){
    FILE *archivoReporte;
    int cantReg;
    archivoReporte = fopen(ARCHIVO_REPORTE, "rb");
    if(archivoReporte == NULL){
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }
    fseek(archivoReporte, 0, 2);
    cantReg = ftell(archivoReporte) / sizeof(Reporte);
    fclose(archivoReporte);
    return cantReg;
}

bool realizarBackup(){
    FILE *archivoProductosBkp;
    FILE *archivoMateriasPrimasBkp;
    FILE *archivoProveedoresBkp;
    FILE *archivoVentasBkp;
    FILE *archivoReporteBkp;
    Producto regProd;
    MateriaPrima regMatPrim;
    Proveedor regProv;
    Venta regVenta;
    Reporte regRepor;
    int cantReg;
    bool estaGrabado;
    archivoProductosBkp = fopen(ARCHIVO_PRODUCTOS_BACKUP, "wb");
    if(archivoProductosBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    cantReg = contarRegistrosProductos();
    for(int i = 0; i < cantReg; i++){
        if(regProd.leerDeDisco(i) == false && cantReg != 0){
            cout << "Error al leer del disco" << endl;
            return false;
        }
        estaGrabado = fwrite(&regProd, sizeof(Producto), 1, archivoProductosBkp);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoProductosBkp);
    archivoMateriasPrimasBkp = fopen(ARCHIVO_MATERIAS_PRIMAS_BACKUP, "wb");
    if(archivoMateriasPrimasBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    cantReg = contarRegistrosMateriasPrimas();
    for(int i = 0; i < cantReg; i++){
        if(regMatPrim.leerDeDisco(i) == false && cantReg != 0){
            cout << "Error al leer del disco" << endl;
            return false;
        }
        estaGrabado = fwrite(&regMatPrim, sizeof(MateriaPrima), 1, archivoMateriasPrimasBkp);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoMateriasPrimasBkp);
    archivoProveedoresBkp = fopen(ARCHIVO_PROVEEDORES_BACKUP, "wb");
    if(archivoProveedoresBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    cantReg = contarRegistrosProveedores();
    for(int i = 0; i < cantReg; i++){
        if(regProv.leerDeDisco(i) == false && cantReg != 0){
            cout << "Error al leer del disco" << endl;
            return false;
        }
        estaGrabado = fwrite(&regProv, sizeof(Proveedor), 1, archivoProveedoresBkp);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoProveedoresBkp);
    archivoVentasBkp = fopen(ARCHIVO_VENTAS_BACKUP, "wb");
    if(archivoVentasBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    cantReg = contarRegistrosVentas();
    for(int i = 0; i < cantReg; i++){
        if(regVenta.leerDeDisco(i) == false && cantReg != 0){
            cout << "Error al leer del disco" << endl;
            return false;
        }
        estaGrabado = fwrite(&regVenta, sizeof(Venta), 1, archivoVentasBkp);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoVentasBkp);
    archivoReporteBkp = fopen(ARCHIVO_REPORTE_BACKUP, "wb");
    if(archivoReporteBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    cantReg = contarRegistrosReporte();
    for(int i = 0; i < cantReg; i++){
        if(regRepor.leerDeDisco(i) == false && cantReg != 0){
            cout << "Error al leer del disco" << endl;
            return false;
        }
        estaGrabado = fwrite(&regRepor, sizeof(Reporte), 1, archivoReporteBkp);
            if(estaGrabado == false){
                cout << "Error al grabar en el archivo" << endl;
                return false;
            }
    }
    fclose(archivoReporteBkp);
    return true;
}

bool restaurarBackup(){
    FILE *archivoProductos;
    FILE *archivoMateriasPrimas;
    FILE *archivoProveedores;
    FILE *archivoVentas;
    FILE *archivoReporte;
    FILE *archivoProductosBkp;
    FILE *archivoMateriasPrimasBkp;
    FILE *archivoProveedoresBkp;
    FILE *archivoVentasBkp;
    FILE *archivoReporteBkp;
    Producto regProd;
    MateriaPrima regMatPrim;
    Proveedor regProv;
    Venta regVenta;
    Reporte regRepor;
    bool estaGrabado;
    archivoProductos = fopen(ARCHIVO_PRODUCTOS, "wb");
    if(archivoProductos == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    archivoProductosBkp = fopen(ARCHIVO_PRODUCTOS_BACKUP, "rb");
    if(archivoProductosBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        fclose(archivoProductos);
        return false;
    }
    while(fread(&regProd, sizeof(Producto), 1, archivoProductosBkp) == 1){
        estaGrabado = fwrite(&regProd, sizeof(Producto), 1, archivoProductos);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoProductos);
    fclose(archivoProductosBkp);
    archivoMateriasPrimas = fopen(ARCHIVO_MATERIAS_PRIMAS, "wb");
    if(archivoMateriasPrimas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    archivoMateriasPrimasBkp = fopen(ARCHIVO_MATERIAS_PRIMAS_BACKUP, "rb");
    if(archivoMateriasPrimasBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        fclose(archivoMateriasPrimas);
        return false;
    }
    while(fread(&regMatPrim, sizeof(MateriaPrima), 1, archivoMateriasPrimasBkp) == 1){
        estaGrabado = fwrite(&regMatPrim, sizeof(MateriaPrima), 1, archivoMateriasPrimas);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoMateriasPrimas);
    fclose(archivoMateriasPrimasBkp);
    archivoProveedores = fopen(ARCHIVO_PROVEEDORES, "wb");
    if(archivoProveedores == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    archivoProveedoresBkp = fopen(ARCHIVO_PROVEEDORES_BACKUP, "rb");
    if(archivoProveedoresBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        fclose(archivoProveedores);
        return false;
    }
    while(fread(&regProv, sizeof(Proveedor), 1, archivoProveedoresBkp) == 1){
        estaGrabado = fwrite(&regProv, sizeof(Proveedor), 1, archivoProveedores);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoProveedores);
    fclose(archivoProveedoresBkp);
    archivoVentas = fopen(ARCHIVO_VENTAS, "wb");
    if(archivoVentas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    archivoVentasBkp = fopen(ARCHIVO_VENTAS_BACKUP, "rb");
    if(archivoVentasBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        fclose(archivoVentas);
        return false;
    }
    while(fread(&regVenta, sizeof(Venta), 1, archivoVentasBkp) == 1){
        estaGrabado = fwrite(&regVenta, sizeof(Venta), 1, archivoVentas);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoVentas);
    fclose(archivoVentasBkp);
    archivoReporte = fopen(ARCHIVO_REPORTE, "wb");
    if(archivoReporte == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    archivoReporteBkp = fopen(ARCHIVO_REPORTE_BACKUP, "rb");
    if(archivoReporteBkp == NULL){
        cout << "Error al abrir el archivo" << endl;
        fclose(archivoReporte);
        return false;
    }
    while(fread(&regRepor, sizeof(Reporte), 1, archivoReporteBkp) == 1){
        estaGrabado = fwrite(&regRepor, sizeof(Reporte), 1, archivoReporte);
        if(estaGrabado == false){
            cout << "Error al grabar en el archivo" << endl;
            return false;
        }
    }
    fclose(archivoReporte);
    fclose(archivoReporteBkp);
    return true;
}

void dibujarRectangulo(int x, int y, int ancho, int alto){
    for(int i = x; i <= x + ancho; i++){
        gotoxy(i, y);
        cout << '#';
        gotoxy(i, y + alto);
        cout << '#';
    }
    for(int i = y; i <= y + alto; i++){
        gotoxy(x, i);
        cout << '#';
        gotoxy(x + ancho, i);
        cout << '#';
    }

}

#endif // FUNCIONES_H_INCLUDED
