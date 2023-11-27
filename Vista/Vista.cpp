#include "Vista.h"
// Configurar según la localización del sistema

Vista::Vista()
{

}

void Vista::MenuGlobal() {
    while (true) {
        switch (MostrarMenu()) {
            default:
                std::cout << "Opcion no valida" << std::endl;
                break; // Agrega un break aquí para salir del switch

            case 1:
                IngresarDatos();
                break;

            case 2:
                std::cout << "CONSULTARR: " << std::endl; // Temporal
                break;

            case 3:
                // Aquí se pondría todo para que copie lo que está dentro de los archivos
                return; // Utiliza 'return' para salir del método y, por lo tanto, del bucle
        }
    }
}

int Vista::MostrarMenu() {
    int num;
    std::cout<<"Sucursales"<<std::endl;
    std::cout<<"\t1. Ingresar nuevos datos: "<<std::endl;
    std::cout<<"\t2. Consultar: "<<std::endl;
    std::cout<<"\t3. Salir: "<<std::endl;
    std::cout<<"Ingresa una opción: ";

    std::cin>>num;
    return num;
}

void Vista::IngresarDatos()
{
    int numEmpleados;
    std::cout << "Ingrese el número de empleados: ";
    std::cin >> numEmpleados;
    std::cin.ignore(); // Limpiar el buffer del teclado

    //List<Empleado> empleados;
    for (int i = 0; i < numEmpleados; ++i) {
        std::cout << "\nCapturando información del empleado " << i + 1 << ":\n";
        //empleados.addLast(formulario.capturarInfoEmpleado());
    }

    // Capturar información de sucursales
    int numSucursales;
    std::cout << "\nIngrese el número de sucursales: ";
    std::cin >> numSucursales;
    std::cin.ignore(); // Limpiar el buffer del teclado

    //List<Sucursal> sucursales;
    for (int i = 0; i < numSucursales; ++i) {
        std::cout << "\nCapturando información de la sucursal " << i + 1 << ":\n";
        //sucursales.addLast(formulario.capturarInformacionSucursal());
    }
}


void Vista::MenuConsultas()
{
    std::cout<<"Consultas"<<std::endl;

    std::cout<<"\t1. Número total de personas que trabajan en una sucursal\n"
               "clasificados en rangos de edades "<<std::endl;

    std::cout<<"\t2. Listado de los nombres y apellidos de aquellos que tienen  \n"
               "un número de hijos dado : "<<std::endl;

    std::cout<<"\t3. Nombre y apellidos de las personas que viven en una ciudad dada: "<<std::endl;

    std::cout<<"\t4. Número de sucursales en las que trabaja un número de personas superior a\n"
               " un número dado"<<std::endl;

    std::cout<<"\t5. Obtener el número de hombres y el número de hombres y mujeres"<<std::endl;

    std::cout<<"\t6. Lista de trabajadores de de edad dada"<<std::endl;

    std::cout<<"\t7. Salir"<<std::endl;

    std::cout<<"Ingresa una opción: ";
}


int Vista::MostrarElementos(std::string* arreglo, int tam) {
    int opcion;

    for (int i = 0; i < tam; i++) {
        std::cout << (i + 1) << ". " << arreglo[i] << std::endl;
    }

    while (true) {
        std::cout << "Ingrese su opción: ";
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
        std::cout << "Opción inválida. Intente de nuevo." << std::endl;
    }
}

void Vista::MenuPrimeraConsulta(int* arreglo)
{
    std::cout<<"Sin hijos: "<<arreglo[0]<<std::endl;
    std::cout<<"0 a 5: "<<arreglo[1]<<std::endl;
    std::cout<<"6 a 10: "<<arreglo[2]<<std::endl;
    std::cout<<"11 a 18: "<<arreglo[3]<<std::endl;
    std::cout<<"Más de 18: "<<arreglo[4]<<std::endl;
}

int Vista::MenuMostrarRangosNumHijos()
{
    int opcion;
    std::cout<<"1. Sin hijos: "<<std::endl;
    std::cout<<"2. 1 a 2: "<<std::endl;
    std::cout<<"3. 3 a 4: "<<std::endl;
    std::cout<<"4. Más de 4 : "<<std::endl;

    std::cout<<"Ingresa una opción: ";
    std::cin>>opcion;
    return opcion;
}

void Vista::Imprimir(std::string m)
{
    std::cout<<m<<std::endl;
}

int Vista::PedirElemento()
{
    int opcion;
    std::cout<<"Elige el número: "<<std::endl;
    std::cin>>opcion;
    return opcion;
}