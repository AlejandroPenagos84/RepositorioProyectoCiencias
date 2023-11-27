#include "Controlador.h"

/**
 * @brief Constructor de la clase Controlador.
 *
 * Se encarga de inicializar los punteros a la vista, al controlador DAO y a la multilista de países.
 * Además, lee los datos de los archivos CSV y organiza la información en las estructuras de datos necesarias.
 */
Controlador::Controlador() {
    // Inicialización de punteros
    controlDao = new ControlDAO(this);
    vista = new Vista(this);
    multilistaPaises = new MultilistaPaises(18);

    // Lectura de datos desde archivos CSV
    controlDao->LeerHijosDAO(R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\hijos.csv)");
    controlDao->LeerEmpleadosDAO(R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\empleados.csv)");
    controlDao->LeerSucursalesDAO(R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\sucursales.csv)");
    controlDao->LeerCiudadesDAO(R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\ciudades.csv)");
    controlDao->LeerPaisesDAO(R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\paises.csv)");

    // Obtención de árboles y colas
    RBTree<int, Empleado> *arbolEmpleados = controlDao->getEmpleadosLlaveF();
    RBTree<int, Sucursal> *arbolSucursales = controlDao->getSucurcalesLlaveF();
    RBTree<int, Ciudad> *arbolCiudades = controlDao->getCiudadesLlaveF();
    RBTree<int, Pais> *arbolPaises = controlDao->getPaises();

    Queue<Nodo<int, Hijo> *> colaHijosF = controlDao->getHijosLlaveF()->inorden();
    Queue<Nodo<int, Empleado> *> colaEmpleadosF = controlDao->getEmpleadosLlaveF()->inorden();
    Queue<Nodo<int, Sucursal> *> colaSucursalesF = controlDao->getSucurcalesLlaveF()->inorden();
    Queue<Nodo<int, Ciudad> *> colaCiudadesF = controlDao->getCiudadesLlaveF()->inorden();
    Queue<Nodo<int, Pais> *> colaPaisesF = controlDao->getPaises()->inorden();

    // Organización de datos en las estructuras de la aplicación
    while (!colaHijosF.IsEmpty()) {
        if (arbolEmpleados->findNodo(colaHijosF.Front()->otroDato.fk) != nullptr) {
            arbolEmpleados->findNodo(colaHijosF.Front()->otroDato.fk)->otroDato.hijos->AgregarHijo(
                    colaHijosF.Dequeue()->otroDato);
        }
    }

    while (!colaEmpleadosF.IsEmpty()) {
        if (arbolSucursales->findNodo(colaEmpleadosF.Front()->otroDato.fk) != nullptr) {
            Empleado aux = colaEmpleadosF.Dequeue()->otroDato;
            (arbolSucursales->findNodo(aux.fk))->otroDato.empleados->AgregarEmpleado(aux);
        }
    }

    while (!colaSucursalesF.IsEmpty()) {
        if (arbolCiudades->findNodo(colaSucursalesF.Front()->otroDato.fk) != nullptr) {
            (arbolCiudades->findNodo(colaSucursalesF.Front()->otroDato.fk))->otroDato.sucursales->AgregarSucursal(
                    colaSucursalesF.Dequeue()->otroDato);
        }
    }

    while (!colaCiudadesF.IsEmpty()) {
        if (arbolPaises->findNodo(colaCiudadesF.Front()->otroDato.fk) != nullptr) {
            (arbolPaises->findNodo(colaCiudadesF.Front()->otroDato.fk))->otroDato.ciudades->AgregarCiudad(
                    colaCiudadesF.Dequeue()->otroDato);
        }
    }

    while (!colaPaisesF.IsEmpty()) {
        multilistaPaises->AgregarPais(colaPaisesF.Dequeue()->otroDato);
    }
}

/**
 * @brief Muestra el menú principal en la vista.
 */
void Controlador::MostrarMenu() {
    vista->MenuGlobal();
}

/**
 * @brief Realiza la primera consulta y muestra los resultados en la vista.
 *
 * Permite al usuario seleccionar un país, una ciudad y una sucursal para luego mostrar estadísticas
 * relacionadas con los empleados de esa sucursal, como la cantidad de empleados sin hijos y la cantidad
 * de empleados con diferentes números de hijos.
 */
void Controlador::PrimeraConsulta() {
    // Selección de país
    int numPais = vista->MostrarElementos(multilistaPaises->getElementos(), multilistaPaises->getSize());
    delete[] multilistaPaises->getElementos();
    Pais auxPais = multilistaPaises->getPais(numPais);

    // Selección de ciudad
    int numCiudad = vista->MostrarElementos(auxPais.ciudades->getElementos(), auxPais.ciudades->getSize());
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);
    auxPais.ciudades->getElementos();

    // Selección de sucursal
    int numSucursal = vista->MostrarElementos(auxCiudad.sucursales->getElementos(), auxCiudad.sucursales->getSize());
    Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(numSucursal);
    delete[] auxCiudad.sucursales->getElementos();

    // Conteo de empleados según ciertos criterios
    int *arregloValidaciones = new int[5];
    for (int i = 0; i < 5; i++) {
        arregloValidaciones[i] = 0;
    }

    for (int i = 0; i < auxSucursal.empleados->getNumEmpleados(); i++) {
        Empleado auxEmpleado = auxSucursal.empleados->getEmpleado(i);
        if (auxEmpleado.estado) {
            if (auxEmpleado.tieneHijos == 'N') {
                arregloValidaciones[0]++;
            } else {
                for (int k = 0; k < 4; k++) {
                    if (auxEmpleado.hijos->getCabecera()[k].indice != -1) {
                        arregloValidaciones[k + 1]++;
                    }
                }
            }
        }
    }

    // Mostrar resultados en la vista
    vista->MenuPrimeraConsulta(arregloValidaciones);
    delete[] arregloValidaciones;
}


/**
 * @brief Realiza la segunda consulta y muestra los empleados que tienen un número de hijos en un rango específico.
 *
 * Permite al usuario seleccionar un rango de número de hijos y luego muestra los empleados de todas las sucursales
 * que cumplen con ese criterio, agrupados por país, ciudad y sucursal.
 */
void Controlador::SegundaConsulta() {
    // Selección del rango de número de hijos
    int auxNumRango = vista->MenuMostrarRangosNumHijos();

    // Iteración sobre países
    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);
        vista->Imprimir("\t" + auxPais.nombre);

        // Iteración sobre ciudades
        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);
            vista->Imprimir("\t\t" + auxCiudad.nombre);

            // Iteración sobre sucursales
            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucusal = auxCiudad.sucursales->getSucursal(k);

                // Obtener el índice del arreglo correspondiente al rango de número de hijos
                int indiceC = auxSucusal.empleados->getArreglosRangoHijos()[auxNumRango].indice;

                // Iteración sobre empleados en el rango de número de hijos
                while (indiceC != -1) {
                    vista->Imprimir("\t\t\t" + auxSucusal.empleados->getEmpleado(indiceC).nombre +
                                    " " + auxSucusal.empleados->getEmpleado(indiceC).apellido);
                    indiceC = auxSucusal.empleados->getEmpleado(indiceC).sigNumHijos;
                }
            }
        }
    }
}


/**
 * @brief Realiza la tercera consulta y muestra la actividad laboral de los empleados agrupada por ciudad de nacimiento.
 *
 * Permite al usuario seleccionar un país y una ciudad, luego muestra la actividad laboral de los empleados en esa ciudad,
 * agrupada por nombre de ciudad y actividad laboral.
 */
void Controlador::TeceraConsulta() {
    // Selección del país
    int numPais = vista->MostrarElementos(multilistaPaises->getElementos(), multilistaPaises->getSize());
    delete[] multilistaPaises->getElementos();
    Pais auxPais = multilistaPaises->getPais(numPais);

    // Selección de la ciudad
    int numCiudad = vista->MostrarElementos(auxPais.ciudades->getElementos(), auxPais.ciudades->getSize());
    delete[] auxPais.ciudades->getElementos();
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);

    // Estructura para almacenar información auxiliar
    struct EstructuraAuxAL {
        std::string actividadLaboral;
        std::string nombreEmpleado;
        std::string apellidoEmpleado;
    };

    struct EstructuraAuxCiudadN {
        std::string nombre; // Nombre de la ciudad
        RBTree<std::string, EstructuraAuxAL> *arbolActividadLaboral = new RBTree<std::string, EstructuraAuxAL>;
    };

    // Árbol para organizar la información por ciudad de nacimiento
    RBTree<std::string, EstructuraAuxCiudadN> *arbolCiudadNacimiento = new RBTree<std::string, EstructuraAuxCiudadN>;

    // Iteración sobre las sucursales de la ciudad
    for (int i = 0; i < auxCiudad.sucursales->getSize(); i++) {
        Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(i);
        Cabecera<std::string> *pCabeceraCiudadNacimiento = auxSucursal.empleados->getCCiudadNacimiento();
        int indiceCabecera = 0;

        // Iteración sobre las cabeceras de ciudad de nacimiento
        while (pCabeceraCiudadNacimiento[indiceCabecera].atributo != "" ||
               pCabeceraCiudadNacimiento[indiceCabecera].indice != -1) {
            int indice = pCabeceraCiudadNacimiento[indiceCabecera].indice;
            EstructuraAuxCiudadN auxiliarCN;
            auxiliarCN.nombre = auxSucursal.empleados->getEmpleado(indice).ciudadNacimiento;

            // Iteración sobre los empleados de la ciudad de nacimiento
            while (indice != -1) {
                EstructuraAuxAL auxiliarAL;
                auxiliarAL.actividadLaboral = auxSucursal.empleados->getEmpleado(indice).actividadLaboral;
                auxiliarAL.nombreEmpleado = auxSucursal.empleados->getEmpleado(indice).nombre;
                auxiliarAL.apellidoEmpleado = auxSucursal.empleados->getEmpleado(indice).apellido;

                auxiliarCN.arbolActividadLaboral->Insert(auxiliarCN.arbolActividadLaboral,
                                                         auxiliarCN.arbolActividadLaboral->createNodo(
                                                                 auxiliarAL.actividadLaboral, auxiliarAL));

                indice = auxSucursal.empleados->getEmpleado(indice).sigCiudadNacimiento;
            }

            arbolCiudadNacimiento->Insert(arbolCiudadNacimiento,
                                          arbolCiudadNacimiento->createNodo(auxiliarCN.nombre, auxiliarCN));
            indiceCabecera++;
        }
    }

    // Cola con las ciudades de nacimiento
    Queue<Nodo<std::string, EstructuraAuxCiudadN> *> ciudadesNacimiento = arbolCiudadNacimiento->inorden();

    // Iteración sobre las ciudades de nacimiento
    while (!ciudadesNacimiento.IsEmpty()) {
        EstructuraAuxCiudadN auxCN = ciudadesNacimiento.Dequeue()->otroDato;

        // Cola con las actividades laborales
        Queue<Nodo<std::string, EstructuraAuxAL> *> actividadLaboral = auxCN.arbolActividadLaboral->inorden();

        // Iteración sobre las actividades laborales
        while (!actividadLaboral.IsEmpty()) {
            EstructuraAuxAL auxAl = actividadLaboral.Dequeue()->otroDato;

            // Impresión de la información
            vista->Imprimir(auxCN.nombre + "-" + auxAl.actividadLaboral);
            vista->Imprimir("\t\t" + auxAl.nombreEmpleado + "-" + auxAl.apellidoEmpleado);
        }
    }

    // Liberar memoria
    delete arbolCiudadNacimiento;
}

/**
 * @brief Realiza la cuarta consulta y muestra la información de las sucursales que tienen un número de empleados igual o superior al proporcionado.
 *
 * El usuario proporciona un número y se muestran las sucursales que cumplen con el criterio, incluyendo información como el nombre, nombre del gerente, barrio y número de empleados.
 */
void Controlador::CuartaConsulta() {
    // Solicitar al usuario el número para el rango
    int numRango = vista->PedirElemento();

    // Estructura auxiliar para almacenar información de las sucursales
    struct EstructuAux {
        int numEmpleados;
        std::string nombre;
        std::string nombreGerente;
        std::string barrio;
    };

    // Árbol para organizar la información por número de empleados
    RBTree<int, EstructuAux> *arbolEstructuras = new RBTree<int, EstructuAux>;

    // Iteración sobre los países, ciudades y sucursales
    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);

        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);

            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(k);

                // Crear estructura auxiliar con información de la sucursal
                EstructuAux aux;
                aux.numEmpleados = auxSucursal.empleados->getNumEmpleados();
                aux.nombre = auxSucursal.nombre;
                aux.barrio = auxSucursal.barrio;
                aux.nombreGerente = auxSucursal.nombreGerente;

                // Insertar en el árbol por número de empleados
                arbolEstructuras->Insert(arbolEstructuras,
                                         arbolEstructuras->createNodo(auxSucursal.empleados->getNumEmpleados(), aux));
            }
        }
    }

    // Cola con las sucursales ordenadas por número de empleados
    Queue<Nodo<int, EstructuAux> *> colaSucursales = arbolEstructuras->inorden();

    // Iteración sobre las sucursales
    while (!colaSucursales.IsEmpty()) {
        EstructuAux auxDatos = colaSucursales.Dequeue()->otroDato;
        if (auxDatos.numEmpleados >= numRango) {
            // Mostrar información de la sucursal que cumple con el criterio
            vista->Imprimir("Nombre: " + auxDatos.nombre);
            vista->Imprimir("Nombre Gerente: " + auxDatos.nombreGerente);
            vista->Imprimir("Barrio: " + auxDatos.barrio);
            vista->Imprimir("Numero empleados: " + std::to_string(auxDatos.numEmpleados) + "\n\n");
        }
    }

    // Liberar memoria
    delete arbolEstructuras;
}


/**
 * @brief Realiza la quinta consulta y muestra información detallada de las sucursales, incluyendo el número de hombres y mujeres empleados.
 *
 * Se muestra información jerárquica de países, ciudades y sucursales, incluyendo el nombre de la sucursal, el nombre del gerente, y el número de hombres y mujeres empleados.
 */
void Controlador::QuintaConsulta() {
    // Iteración sobre los países
    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);
        vista->Imprimir("\t" + auxPais.nombre);

        // Iteración sobre las ciudades
        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);
            vista->Imprimir("\t\t" + auxCiudad.nombre);

            // Iteración sobre las sucursales
            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(k);

                // Obtener información detallada de la sucursal
                std::string nombreSucursal = "\t\t\tNombre Sucursal " + auxSucursal.nombre;
                std::string nombreSucursalG = "\t\t\tNombre Gerente " + auxSucursal.nombreGerente;
                std::string numHombres =
                        "\t\t\t\tNúmero de Hombres " + std::to_string(auxSucursal.empleados->getNumHombres());
                std::string numMujeres =
                        "\t\t\t\tNúmero de Mujeres " + std::to_string(auxSucursal.empleados->getNumMujeres());

                // Mostrar la información de la sucursal
                vista->Imprimir(nombreSucursal);
                vista->Imprimir(nombreSucursalG);
                vista->Imprimir(numHombres);
                vista->Imprimir(numMujeres);
            }
        }
    }
}

