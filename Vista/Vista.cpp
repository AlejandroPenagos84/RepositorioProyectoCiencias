#include "Vista.h"

// Configurar según la localización del sistema

/**
 * @brief Constructor de la clase Vista.
 * @param ctrl Puntero a un objeto de la clase Controlador.
 */
Vista::Vista(Controlador *ctrl) {
    controlador = ctrl;
}

/**
 * @brief Método que representa el menú global de la aplicación.
 * Permite al usuario realizar diversas acciones como ingresar datos, realizar consultas, o salir del programa.
 */
void Vista::MenuGlobal() {
    while (true) {
        switch (MostrarMenu()) {
            default:
                Imprimir("Opcion no valida");
                break; // Agrega un break aquí para salir del switch

            case 1:
                IngresarDatos();
                break;

            case 2:
                ElegirConsulta();
                break;

            case 3:
                // Aquí se pondría todo para que copie lo que está dentro de los archivos
                return; // Utiliza 'return' para salir del método y, por lo tanto, del bucle
        }
    }
}

/**
 * @brief Método que muestra un menú con opciones y devuelve la opción seleccionada por el usuario.
 * @return Opción seleccionada por el usuario.
 */
int Vista::MostrarMenu() {
    int num;
    Imprimir("Sucursales");
    Imprimir("\t1. Ingresar nuevos datos:");
    Imprimir("\t2. Consultar:");
    Imprimir("\t3. Salir:");
    Imprimir("Ingresa una opción: ");

    std::cin >> num;
    return num;
}

/**
 * @brief Método para ingresar datos en el formulario.
 * Captura información sobre empleados y sucursales.
 */
void Vista::IngresarDatos() {
    int numEmpleados;
    Imprimir("Ingrese el número de empleados: ");
    std::cin >> numEmpleados;
    std::cin.ignore(); // Limpiar el buffer del teclado

    //List<Empleado> empleados;
    for (int i = 0; i < numEmpleados; ++i) {
        Imprimir("\nCapturando información del empleado " + std::to_string(i + 1) + ":");
        //empleados.addLast(formulario.capturarInfoEmpleado());
    }

    // Capturar información de sucursales
    int numSucursales;
    Imprimir("\nIngrese el número de sucursales: ");
    std::cin >> numSucursales;
    std::cin.ignore(); // Limpiar el buffer del teclado

    //List<Sucursal> sucursales;
    for (int i = 0; i < numSucursales; ++i) {
        Imprimir("\nCapturando información de la sucursal " + std::to_string(i + 1) + ":");
        //sucursales.addLast(formulario.capturarInformacionSucursal());
    }
}

/**
 * @brief Método que muestra un menú de consultas y devuelve la opción seleccionada por el usuario.
 * @return Opción seleccionada por el usuario.
 */
int Vista::MenuConsultas() {
    int opcion;
    std::cout << "Consultas" << std::endl;

    std::cout << "\t1. Número total de personas que trabajan en una sucursal\n"
                 "clasificados en rangos de edades " << std::endl;

    std::cout << "\t2. Listado de los nombres y apellidos de aquellos que tienen  \n"
                 "un número de hijos dado : " << std::endl;

    std::cout << "\t3. Nombre y apellidos de las personas que viven en una ciudad dada: " << std::endl;

    std::cout << "\t4. Número de sucursales en las que trabaja un número de personas superior a\n"
                 " un número dado" << std::endl;

    std::cout << "\t5. Obtener el número de hombres y el número de hombres y mujeres" << std::endl;

    std::cout << "\t6. Lista de trabajadores de de edad dada" << std::endl;

    std::cout << "\t7. Salir" << std::endl;

    std::cout << "Ingresa una opción: ";

    std::cin >> opcion;

    return opcion;
}

/**
 * @brief Método que ejecuta una consulta específica según la opción seleccionada por el usuario.
 */
void Vista::ElegirConsulta() {
    int opcion = MenuConsultas();

    switch (opcion) {
        case 1:
            controlador->PrimeraConsulta();
            break;
        case 2:
            controlador->SegundaConsulta();
            break;
        case 3:
            controlador->TeceraConsulta();
            break;
        case 4:
            controlador->CuartaConsulta();
            break;
        case 5:
            controlador->QuintaConsulta();
            break;
        default:
            break;
    }
}

/**
 * @brief Método que muestra elementos de un arreglo de cadenas y devuelve la opción seleccionada por el usuario.
 * @param arreglo Arreglo de cadenas a mostrar.
 * @param tam Tamaño del arreglo.
 * @return Opción seleccionada por el usuario.
 */
int Vista::MostrarElementos(std::string *arreglo, int tam) {
    int opcion;

    for (int i = 0; i < tam; i++) {
        Imprimir(std::to_string(i + 1) + ". " + arreglo[i]);
    }

    while (true) {
        Imprimir("Ingrese su opción: ");
        std::cin >> opcion;

        if (std::cin.fail()) {
            // La entrada no es un número entero
            std::cin.clear(); // Limpiar la bandera de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar la entrada incorrecta
        } else if (opcion >= 1 && opcion <= tam) {
            // La opción es válida
            return opcion - 1;
        }

        // Mostrar mensaje de error y repetir el bucle
        Imprimir("Opción inválida. Intente de nuevo.");
    }
}

/**
 * @brief Método que muestra el resultado de la primera consulta.
 * @param arreglo Arreglo de resultados de la consulta.
 */
void Vista::MenuPrimeraConsulta(int *arreglo) {
    Imprimir("Sin hijos: " + std::to_string(arreglo[0]));
    Imprimir("0 a 5: " + std::to_string(arreglo[1]));
    Imprimir("6 a 10: " + std::to_string(arreglo[2]));
    Imprimir("11 a 18: " + std::to_string(arreglo[3]));
    Imprimir("Más de 18: " + std::to_string(arreglo[4]));
}

/**
 * @brief Método que muestra un menú para seleccionar rangos de número de hijos.
 * @return Opción seleccionada por el usuario.
 */
int Vista::MenuMostrarRangosNumHijos() {
    int opcion;
    Imprimir("1. Sin hijos: ");
    Imprimir("2. 1 a 2: ");
    Imprimir("3. 3 a 4: ");
    Imprimir("4. Más de 4 : ");

    Imprimir("Ingresa una opción: ");
    std::cin >> opcion;
    return opcion - 1;
}

/**
 * @brief Método estático para imprimir mensajes en la consola.
 * @param m Mensaje a imprimir.
 */
void Vista::Imprimir(std::string m) {
    std::cout << m << std::endl;
}

/**
 * @brief Método que solicita al usuario ingresar un número.
 * @return Número ingresado por el usuario.
 */
int Vista::PedirElemento() {
    int opcion;
    Imprimir("Elige el número: ");
    std::cin >> opcion;
    return opcion;
}
