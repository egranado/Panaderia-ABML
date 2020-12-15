#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cctype>

using namespace std;

const char *ARCHIVO_PRODUCTOS = "productos.dat";
const char *ARCHIVO_MATERIAS_PRIMAS = "materiasPrimas.dat";
const char *ARCHIVO_PROVEEDORES = "proveedores.dat";
const char *ARCHIVO_VENTAS = "ventas.dat";
const char *ARCHIVO_REPORTE = "reporte.dat";
const char *ARCHIVO_PRODUCTOS_BACKUP = "productos.bkp";
const char *ARCHIVO_MATERIAS_PRIMAS_BACKUP = "materiasPrimas.dat";
const char *ARCHIVO_PROVEEDORES_BACKUP = "proveedores.dat";
const char *ARCHIVO_VENTAS_BACKUP = "ventas.bkp";
const char *ARCHIVO_REPORTE_BACKUP = "reporte.bkp";

#include "prototipos.h"
#include "clases.h"
#include "funciones.h"
#include "rlutil.h"
#define waitkey rlutil::anykey("Presione una tecla para continuar...\n")

int main(){
    setlocale(LC_ALL, "Spanish");
    rlutil::setBackgroundColor(rlutil::GREY);
    rlutil::setColor(rlutil::BLACK);
    rlutil::saveDefaultColor();
    rlutil::setConsoleTitle("Base de datos del negocio");
    int opcion;
    while(true){
        rlutil::cls();
        dibujarRectangulo(10, 5, 75, 25);
        gotoxy(24, 8);
        cout << "¡Bienvenido al sistema de gestión de la panadería!";
        gotoxy(15, 10);
        cout << "Elija una opción (cualquier otro ingreso para cerrar el programa)";
        gotoxy(37, 13);
        cout << "1. Productos";
        gotoxy(37, 15);
        cout << "2. Proveedores";
        gotoxy(37, 17);
        cout << "3. Materias Primas";
        gotoxy(37, 19);
        cout << "4. Ventas";
        gotoxy(37, 21);
        cout << "5. Reporte";
        gotoxy(37, 23);
        cout << "6. Configuración";
        gotoxy(37, 26);
        cout << "Opción: ";
        cin >> opcion;
        rlutil::cls();
        switch(opcion){
            case 1:
                menuProductos();
                break;
            case 2:
                menuProveedores();
                break;
            case 3:
                menuMateriasPrimas();
                break;
            case 4:
                menuVentas();
                break;
            case 5:
                menuReporte();
                break;
            case 6:
                menuConfiguracion();
                break;
            default:
                return 0;
        }
    }
    return 0;
}
