#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include "rlutil.h"

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int, int, int);
        bool cargar();
        void mostrar();
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
};

class Producto{
    private:
        char codigo[10];
        char descripcion[25];
        int stock;
        float precio;
        bool estado;
    public:
        Producto(const char*, const char*, int, float, bool);
        bool cargar();
        void mostrar(int);
        bool grabarEnDisco();
        bool leerDeDisco(int);
        bool modificarEnDisco(int);
        const char *getCodigo();
        const char *getDescripcion();
        int getStock();
        float getPrecio();
        bool getEstado();
        void setCodigo(const char*);
        void setDescripcion(const char*);
        void setStock(int);
        void setPrecio(float);
        void setEstado(bool);
};

class MateriaPrima{
    private:
        char codigo[10];
        char descripcion[25];
        char codigoProveedor[10];
        int stock;
        float precio;
        bool estado;
    public:
        MateriaPrima(const char*, const char*, const char*, int, float, bool);
        bool cargar();
        void mostrar(int);
        bool grabarEnDisco();
        bool leerDeDisco(int);
        bool modificarEnDisco(int);
        const char *getCodigo();
        const char *getDescripcion();
        const char *getCodigoProveedor();
        int getStock();
        float getPrecio();
        bool getEstado();
        void setCodigo(const char*);
        void setDescripcion(const char*);
        void setCodigoProveedor(const char*);
        void setStock(int);
        void setPrecio(float);
        void setEstado(bool);
};

class Proveedor{
    private:
        char codigo[10];
        char nombreEmpresa[20];
        char telefono[15];
        char email[30];
        bool estado;
    public:
        Proveedor(const char*, const char*, const char*, const char*, bool);
        bool cargar();
        void mostrar(int);
        bool grabarEnDisco();
        bool leerDeDisco(int);
        bool modificarEnDisco(int);
        const char *getCodigo();
        const char *getNombreEmpresa();
        const char *getTelefono();
        const char *getEmail();
        bool getEstado();
        void setCodigo(const char*);
        void setNombreEmpresa(const char*);
        void setTelefono(const char*);
        void setEmail(const char*);
        void setEstado(bool);
};

class Venta{
    private:
        int idVenta;
        Fecha fechaVenta;
        char formaPago;
        char codigoProducto[10];
        int cantidad;
        float total;
        bool estado;
    public:
        Venta();
        bool cargar();
        void mostrar(int);
        bool grabarEnDisco();
        bool leerDeDisco(int);
        bool modificarEnDisco(int);
        int getIdVenta();
        Fecha getFechaVenta();
        const char getFormaPago();
        const char* getCodigoProducto();
        int getCantidad();
        float getTotal();
        bool getEstado();
        void setIdVenta(int);
        void setFechaVenta(Fecha);
        void setFormaPago(const char);
        void setCodigoProducto(const char*);
        void setCantidad(int);
        void setTotal(float);
        void setEstado(bool);
};

class Reporte{
    private:
        int cantVentas;
        float totalVentas;
        int ventaMax;
        float valorVentaMax;
        char formaPagoMax;
    public:
        Reporte(int, float, int, float, const char);
        void mostrar();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        int getCantVentas();
        float getTotalVentas();
        int getVentaMax();
        float getValorVentaMax();
        const char getFormaPagoMax();
        void setCantVentas(int);
        void setTotalVentas(float);
        void setVentaMax(int);
        void setValorVentaMax(float);
        void setFormaPagoMax(const char);
};

Fecha::Fecha(int dia = 0, int mes = 0, int anio = 0){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

bool Fecha::cargar(){
    cout << "Ingresar el día: ";
    cin >> dia;
    cout << "Ingresar el mes: ";
    cin >> mes;
    cout << "Ingresar el año: ";
    cin >> anio;
    if(!(comprobarFechaValida(dia, mes, anio))){
        cout << "Se debe ingresar una fecha válida" << endl;
        return false;
    }
    if(compararFechaSistema(dia, mes, anio) == 1){
        cout << "La fecha de la venta debe ser anterior o igual a la fecha actual" << endl;
        return false;
    }
    return true;
}

void Fecha::mostrar(){
    cout << dia << "/" << mes << "/" << anio << endl;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

void Fecha::setDia(int dia){
    this->dia = dia;
}

void Fecha::setMes(int mes){
    this->mes = mes;
}

void Fecha::setAnio(int anio){
    this->anio = anio;
}

Producto::Producto(const char *codigo = "0000", const char *descripcion = "Vacía", int stock = 0, float precio = 0, bool estado = true){
    strcpy(this->codigo, codigo);
    strcpy(this->descripcion, descripcion);
    this->stock = stock;
    this->precio = precio;
    this->estado = estado;
}

bool Producto::cargar(){
    cout << "Ingresar el código: ";
    cargarCadena(codigo, 10);
    if(strlen(codigo) == 0 || isspace(codigo[0])){
        cout << "El código no puede estar vacío" << endl;
        return false;
    }
    if(buscarPosCodigoProducto(codigo) >= 0){
        cout << "El código de producto ya existe en el sistema" << endl;
        return false;
    }
    cout << "Ingresar la descripción: ";
    cargarCadena(descripcion, 25);
    if(strlen(descripcion) == 0 || isspace(descripcion[0])){
        cout << "La descripción no puede estar vacía" << endl;
        return false;
    }
    cout << "Ingresar el stock: ";
    cin >> stock;
    if(stock < 0){
        cout << "El stock no puede ser negativo" << endl;
        return false;
    }
    cout << "Ingresar el precio: ";
    cin >> precio;
    if(precio <= 0){
        cout << "El precio debe ser positivo" << endl;
        return false;
    }
    estado = true;
    return true;
}

void Producto::mostrar(int columna){
    gotoxy(5, columna);
    cout << codigo;
    gotoxy(20,columna);
    cout << descripcion;
    gotoxy(50, columna);
    cout << stock;
    gotoxy(60, columna);
    cout << precio;
}

bool Producto::grabarEnDisco(){
    FILE *archivoProductos;
    archivoProductos = fopen(ARCHIVO_PRODUCTOS, "ab");
    if(archivoProductos == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoProductos);
    fclose(archivoProductos);
    return estaEscrito;
}

bool Producto::leerDeDisco(int pos){
    FILE *archivoProductos;
    archivoProductos = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(archivoProductos == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoProductos, sizeof(*this) * pos, 0);
    bool estaLeido = fread(this, sizeof(*this), 1, archivoProductos);
    fclose(archivoProductos);
    return estaLeido;
}

bool Producto::modificarEnDisco(int pos){
    FILE *archivoProductos;
    archivoProductos = fopen(ARCHIVO_PRODUCTOS, "rb+");
    if(archivoProductos == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoProductos, sizeof(*this) * pos, 0);
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoProductos);
    fclose(archivoProductos);
    return estaEscrito;
}

const char *Producto::getCodigo(){
    return codigo;
}

const char *Producto::getDescripcion(){
    return descripcion;
}

int Producto::getStock(){
    return stock;
}

float Producto::getPrecio(){
    return precio;
}

bool Producto::getEstado(){
    return estado;
}

void Producto::setCodigo(const char *codigo){
    strcpy(this->codigo, codigo);
}

void Producto::setDescripcion(const char *descripcion){
    strcpy(this->descripcion, descripcion);
}

void Producto::setStock(int stock){
    this->stock = stock;
}

void Producto::setPrecio(float precio){
    this->precio = precio;
}

void Producto::setEstado(bool estado){
    this->estado = estado;
}

MateriaPrima::MateriaPrima(const char *codigo = "0000", const char *descripcion = "Vacía", const char *codigoProveedor = "0000",
int stock = 0, float precio = 0, bool estado = true){
        strcpy(this->codigo, codigo);
        strcpy(this->descripcion, descripcion);
        strcpy(this->codigoProveedor, codigoProveedor);
        this->stock = stock;
        this->precio = precio;
        this->estado = estado;
}

bool MateriaPrima::cargar(){
    int pos;
    cout << "Ingresar el código: ";
    cargarCadena(codigo, 10);
    if(strlen(codigo) == 0 || isspace(codigo[0])){
        cout << "El código no puede estar vacío" << endl;
        return false;
    }
    if(buscarPosCodigoMateriaPrima(codigo) >= 0){
        cout << "El código de materia prima ya existe en el sistema" << endl;
        return false;
    }
    cout << "Ingresar la descripción: ";
    cargarCadena(descripcion, 25);
    if(strlen(descripcion) == 0 || isspace(descripcion[0])){
        cout << "La descripción no puede estar vacía" << endl;
        return false;
    }
    cout << "Ingresar el código del proveedor: ";
    cargarCadena(codigoProveedor, 10);
    if(strlen(codigoProveedor) == 0 || isspace(codigoProveedor[0])){
        cout << "El código del proveedor no puede estar vacío" << endl;
        return false;
    }
    pos = buscarPosCodigoProveedor(codigoProveedor);
    if(pos < 0){
        cout << "No existe el código del proveedor en el sistema" << endl;
        return false;
    }
    cout << "Ingresar el stock: ";
    cin >> stock;
    if(stock < 0){
        cout << "El stock no puede ser negativo" << endl;
        return false;
    }
    cout << "Ingresar el precio: ";
    cin >> precio;
    if(precio <= 0){
        cout << "El precio debe ser positivo" << endl;
        return false;
    }
    estado = true;
    return true;
}

void MateriaPrima::mostrar(int columna){
    gotoxy(5, columna);
    cout << codigo;
    gotoxy(20, columna);
    cout << descripcion;
    gotoxy(50, columna);
    cout << codigoProveedor;
    gotoxy(71, columna);
    cout << stock;
    gotoxy(81, columna);
    cout << precio;
}

bool MateriaPrima::grabarEnDisco(){
    FILE *archivoMateriasPrimas;
    archivoMateriasPrimas = fopen(ARCHIVO_MATERIAS_PRIMAS, "ab");
    if(archivoMateriasPrimas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoMateriasPrimas);
    fclose(archivoMateriasPrimas);
    return estaEscrito;
}
bool MateriaPrima::leerDeDisco(int pos){
    FILE *archivoMateriasPrimas;
    archivoMateriasPrimas = fopen(ARCHIVO_MATERIAS_PRIMAS, "rb");
    if(archivoMateriasPrimas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoMateriasPrimas, sizeof(*this) * pos, 0);
    bool estaLeido = fread(this, sizeof(*this), 1, archivoMateriasPrimas);
    fclose(archivoMateriasPrimas);
    return estaLeido;
}

bool MateriaPrima::modificarEnDisco(int pos){
    FILE *archivoMateriasPrimas;
    archivoMateriasPrimas = fopen(ARCHIVO_MATERIAS_PRIMAS, "rb+");
    if(archivoMateriasPrimas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoMateriasPrimas, sizeof(*this) * pos, 0);
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoMateriasPrimas);
    fclose(archivoMateriasPrimas);
    return estaEscrito;
}

const char *MateriaPrima::getCodigo(){
    return codigo;
}

const char *MateriaPrima::getDescripcion(){
    return descripcion;
}

const char *MateriaPrima::getCodigoProveedor(){
    return codigoProveedor;
}

int MateriaPrima::getStock(){
    return stock;
}

float MateriaPrima::getPrecio(){
    return precio;
}

bool MateriaPrima::getEstado(){
    return estado;
}

void MateriaPrima::setCodigo(const char *codigo){
    strcpy(this->codigo, codigo);
}

void MateriaPrima::setDescripcion(const char *descripcion){
    strcpy(this->descripcion, descripcion);
}

void MateriaPrima::setCodigoProveedor(const char *codigoProveedor){
    strcpy(this->codigoProveedor, codigoProveedor);
}

void MateriaPrima::setStock(int stock){
    this->stock = stock;
}

void MateriaPrima::setPrecio(float precio){
    this->precio = precio;
}

void MateriaPrima::setEstado(bool estado){
    this->estado = estado;
}

Proveedor::Proveedor(const char *codigo = "0000", const char *nombreEmpresa = "Vacío", const char *telefono = "000", const char *email = "Vacío", bool estado = true){
    strcpy(this->codigo, codigo);
    strcpy(this->nombreEmpresa, nombreEmpresa);
    strcpy(this->telefono, telefono);
    strcpy(this->email, email);
    this->estado = estado;
}

bool Proveedor::cargar(){
    cout << "Ingresar el código: ";
    cargarCadena(codigo, 10);
    if(strlen(codigo) == 0 || isspace(codigo[0])){
        cout << "El código no puede estar vacío" << endl;
        return false;
    }
    if(buscarPosCodigoProveedor(codigo) >= 0){
        cout << "El código de proveedor ya existe en el sistema" << endl;
        return false;
    }
    cout << "Ingresar el nombre de la empresa: ";
    cargarCadena(nombreEmpresa, 20);
    if(strlen(nombreEmpresa) == 0 || isspace(nombreEmpresa[0])){
        cout << "El nombre de la empresa no puede estar vacía" << endl;
        return false;
    }
    cout << "Ingresar el teléfono: ";
    cargarCadena(telefono, 15);
    if(strlen(telefono) == 0 || isspace(telefono[0])){
        cout << "El teléfono no puede estar vacío" << endl;
        return false;
    }
    cout << "Ingresar el email: ";
    cargarCadena(email, 30);
    if(strlen(email) == 0 || isspace(email[0])){
        cout << "El email no puede estar vacío" << endl;
        return false;
    }
    estado = true;
    return true;
}

void Proveedor::mostrar(int columna){
    gotoxy(5, columna);
    cout << codigo;
    gotoxy(20, columna);
    cout << nombreEmpresa;
    gotoxy(45, columna);
    cout << telefono;
    gotoxy(65, columna);
    cout << email;
}

bool Proveedor::grabarEnDisco(){
    FILE *archivoProveedores;
    archivoProveedores = fopen(ARCHIVO_PROVEEDORES, "ab");
    if(archivoProveedores == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoProveedores);
    fclose(archivoProveedores);
    return estaEscrito;
}
bool Proveedor::leerDeDisco(int pos){
    FILE *archivoProveedores;
    archivoProveedores = fopen(ARCHIVO_PROVEEDORES, "rb");
    if(archivoProveedores == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoProveedores, sizeof(*this) * pos, 0);
    bool estaLeido = fread(this, sizeof(*this), 1, archivoProveedores);
    fclose(archivoProveedores);
    return estaLeido;
}

bool Proveedor::modificarEnDisco(int pos){
    FILE *archivoProveedores;
    archivoProveedores = fopen(ARCHIVO_PROVEEDORES, "rb+");
    if(archivoProveedores == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoProveedores, sizeof(*this) * pos, 0);
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoProveedores);
    fclose(archivoProveedores);
    return estaEscrito;
}

const char *Proveedor::getCodigo(){
    return codigo;
}

const char *Proveedor::getNombreEmpresa(){
    return nombreEmpresa;
}

const char *Proveedor::getTelefono(){
    return telefono;
}

const char *Proveedor::getEmail(){
    return email;
}

bool Proveedor::getEstado(){
    return estado;
}

void Proveedor::setCodigo(const char *codigo){
    strcpy(this->codigo, codigo);
}

void Proveedor::setNombreEmpresa(const char *nombreEmpresa){
    strcpy(this->nombreEmpresa, nombreEmpresa);
}

void Proveedor::setTelefono(const char *telefono){
    strcpy(this->telefono,telefono);
}

void Proveedor::setEmail(const char *email){
    strcpy(this->email, email);
}

void Proveedor::setEstado(bool estado){
    this->estado = estado;
}

Venta::Venta(){
    idVenta = 0;
    fechaVenta.setDia(0);
    fechaVenta.setMes(0);
    fechaVenta.setAnio(0);
    formaPago = 'X';
    strcpy(codigoProducto, "0000");
    cantidad = 0;
    total = 0;
    estado = true;
}

bool Venta::cargar(){
    int pos;
    Producto aux;
    idVenta = contarRegistrosVentas() + 1;
    if(!fechaVenta.cargar()){
        return false;
    }
    cout << "Ingresar la forma de pago (E para efectivo, D para débito o C para crédito): ";
    cin >> formaPago;
    formaPago = toupper(formaPago);
    if(formaPago != 'E' && formaPago != 'D' && formaPago != 'C'){
        cout << "La forma de pago debe ser E, D o C" << endl;
        return false;
    }
    cout << "Ingresar el código del producto: ";
    cargarCadena(codigoProducto, 10);
    pos = buscarPosCodigoProducto(codigoProducto);
    if(pos < 0){
        cout << "No existe el código del producto en el sistema" << endl;
        return false;
    }
    cout << "Ingresar la cantidad de productos: ";
    cin >> cantidad;
    if(cantidad <= 0){
        cout << "La cantidad de productos debe ser mayor a cero" << endl;
        return false;
    }
    aux.leerDeDisco(pos);
    if(cantidad > aux.getStock()){
        cout << "No hay stock suficiente del producto para esa cantidad" << endl;
        return false;
    }
    aux.setStock(aux.getStock() - cantidad);
    aux.modificarEnDisco(pos);
    total = cantidad * aux.getPrecio();
    estado = true;
    return true;
}

void Venta::mostrar(int columna){
    gotoxy(5, columna);
    cout << idVenta;
    gotoxy(18, columna);
    fechaVenta.mostrar();
    gotoxy(31, columna);
    cout << formaPago;
    gotoxy(46, columna);
    cout << codigoProducto;
    gotoxy(66, columna);
    cout << cantidad;
    gotoxy(79, columna);
    cout << "$" << total;
}

bool Venta::grabarEnDisco(){
    FILE *archivoVentas;
    archivoVentas = fopen(ARCHIVO_VENTAS, "ab");
    if(archivoVentas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoVentas);
    fclose(archivoVentas);
    return estaEscrito;
}
bool Venta::leerDeDisco(int pos){
    FILE *archivoVentas;
    archivoVentas = fopen(ARCHIVO_VENTAS, "rb");
    if(archivoVentas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoVentas, sizeof(*this) * pos, 0);
    bool estaLeido = fread(this, sizeof(*this), 1, archivoVentas);
    fclose(archivoVentas);
    return estaLeido;
}

bool Venta::modificarEnDisco(int pos){
    FILE *archivoVentas;
    archivoVentas = fopen(ARCHIVO_VENTAS, "rb+");
    if(archivoVentas == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoVentas, sizeof(*this) * pos, 0);
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoVentas);
    fclose(archivoVentas);
    return estaEscrito;
}

int Venta::getIdVenta(){
    return idVenta;
}

Fecha Venta::getFechaVenta(){
    return fechaVenta;
}

const char Venta::getFormaPago(){
    return formaPago;
}

const char *Venta::getCodigoProducto(){
    return codigoProducto;
}

int Venta::getCantidad(){
    return cantidad;
}

float Venta::getTotal(){
    return total;
}

bool Venta::getEstado(){
    return estado;
}

void Venta::setIdVenta(int idVenta){
    this->idVenta = idVenta;
}

void Venta::setFechaVenta(Fecha fechaVenta){
    this->fechaVenta = fechaVenta;
}

void Venta::setFormaPago(const char formaPago){
    this->formaPago = formaPago;
}

void Venta::setCodigoProducto(const char *codigoProducto){
    strcpy(this->codigoProducto, codigoProducto);
}

void Venta::setCantidad(int cantidad){
    this->cantidad = cantidad;
}

void Venta::setTotal(float total){
    this->total = total;
}

void Venta::setEstado(bool estado){
    this->estado = estado;
}

Reporte::Reporte(int cantVentas = 0, float totalVentas = 0, int ventaMax = 0, float valorVentaMax = 0, const char formaPagoMax = 'X'){
    this->cantVentas = cantVentas;
    this->totalVentas = totalVentas;
    this->ventaMax = ventaMax;
    this->valorVentaMax = valorVentaMax;
    this->formaPagoMax = formaPagoMax;
}

void Reporte::mostrar(){
    gotoxy(33, 11);
    cout << "Cantidad de ventas: " << cantVentas;
    gotoxy(33, 13);
    cout << "Acumulado por las ventas: $" << totalVentas;
    gotoxy(33, 15);
    cout << "ID venta máxima: " << ventaMax;
    gotoxy(33, 17);
    cout << "Valor de la venta máxima: $" << valorVentaMax;
    gotoxy(33, 19);
    cout << "Forma de pago más usada: " << formaPagoMax;
    gotoxy(1, 29);
}

bool Reporte::grabarEnDisco(){
    FILE *archivoReporte;
    archivoReporte = fopen(ARCHIVO_REPORTE, "wb");
    if(archivoReporte == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    bool estaEscrito = fwrite(this, sizeof(*this), 1, archivoReporte);
    fclose(archivoReporte);
    return estaEscrito;
}
bool Reporte::leerDeDisco(int pos){
    FILE *archivoReporte;
    archivoReporte = fopen(ARCHIVO_REPORTE, "rb");
    if(archivoReporte == NULL){
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    fseek(archivoReporte, sizeof(*this) * pos, 0);
    bool estaLeido = fread(this, sizeof(*this), 1, archivoReporte);
    fclose(archivoReporte);
    return estaLeido;
}

int Reporte::getCantVentas(){
    return cantVentas;
}

float Reporte::getTotalVentas(){
    return totalVentas;
}

int Reporte::getVentaMax(){
    return ventaMax;
}

float Reporte::getValorVentaMax(){
    return valorVentaMax;
}

const char Reporte::getFormaPagoMax(){
    return formaPagoMax;
}

void Reporte::setCantVentas(int cantVentas){
    this->cantVentas = cantVentas;
}

void Reporte::setTotalVentas(float totalVentas){
    this->totalVentas = totalVentas;
}

void Reporte::setVentaMax(int ventaMax){
    this->ventaMax = ventaMax;
}

void Reporte::setValorVentaMax(float valorVentaMax){
    this->valorVentaMax = valorVentaMax;
}

void Reporte::setFormaPagoMax(const char formaPagoMax){
    this->formaPagoMax = formaPagoMax;
}

#endif // CLASES_H_INCLUDED
