#include "Controlador.h"

Controlador::Controlador() {
    controlDao = new ControlDAO(this);

    multilistaPaises = new MultilistaPaises(18);

    controlDao->LeerHijosDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\hijos.csv)");
    controlDao->LeerEmpleadosDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\empleados.csv)");
    controlDao->LeerSucursalesDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\sucursales.csv)");
    controlDao->LeerCiudadesDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\ciudades.csv)");
    controlDao->LeerPaisesDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\paises.csv)");

    RBTree<int, Empleado> *arbolEmpleados = controlDao->getEmpleadosLlaveF();
    RBTree<int, Sucursal> *arbolSucursales = controlDao->getSucurcalesLlaveF();
    RBTree<int, Ciudad> *arbolCiudades = controlDao->getCiudadesLlaveF();
    RBTree<int, Pais> *arbolPaises = controlDao->getPaises();

    //Cola Con la Clave de los hijos
    Queue<Nodo<int, Hijo> *> colaHijosF = controlDao->getHijosLlaveF()->inorden();

    //Cola con la clave empleados
    Queue<Nodo<int, Empleado> *> colaEmpleadosF = controlDao->getEmpleadosLlaveF()->inorden();

    //Cola Sucursales
    Queue<Nodo<int, Sucursal> *> colaSucursalesF = controlDao->getSucurcalesLlaveF()->inorden();

    //Cola Ciudad
    Queue<Nodo<int, Ciudad> *> colaCiudadesF = controlDao->getCiudadesLlaveF()->inorden();

    //Cola Paises
    Queue<Nodo<int, Pais> *> colaPaisesF = controlDao->getPaises()->inorden();

    while (!colaHijosF.IsEmpty()) {
        if (arbolEmpleados->findNodo(colaHijosF.Front()->otroDato.fk) != nullptr) {
            // Busca el nodo con la llave foranea
            // recordando que la llave foranea en uno es la primaria en otro

            // Ya con el dato, le digo a la multilista de hijos de ese empleado que agregue
            // el hijo que esta en la cola
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

void Controlador::MostrarMenu() {
    vista.MenuGlobal();
}

void Controlador::PrimeraConsulta() {

    int numPais = vista.MostrarElementos(multilistaPaises->getElementos(),
                                         multilistaPaises->getSize());

    delete[] multilistaPaises->getElementos();

    Pais auxPais = multilistaPaises->getPais(numPais);

    int numCiudad = vista.MostrarElementos(auxPais.ciudades->getElementos(), auxPais.ciudades->getSize());
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);

    auxPais.ciudades->getElementos();

    int numSucursal = vista.MostrarElementos(auxCiudad.sucursales->getElementos(), auxCiudad.sucursales->getSize());
    Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(numSucursal);

    delete[] auxCiudad.sucursales->getElementos();
    int *arregloValidaciones = new int[5];

    for (int i = 0; i < 5; i++)
        arregloValidaciones[i] = 0;

    for (int i = 0; i < auxSucursal.empleados->getNumEmpleados(); i++) {
        Empleado auxEmpleado = auxSucursal.empleados->getEmpleado(i);
        if (auxEmpleado.estado) {
            if (auxEmpleado.tieneHijos == 'N') arregloValidaciones[0]++;
            else {
                for (int k = 0; k < 4; k++) {
                    if (auxEmpleado.hijos->getCabecera()[k].indice != -1) {
                        arregloValidaciones[k + 1]++;
                    }
                }
            }
        }
    }
    vista.MenuPrimeraConsulta(arregloValidaciones);
    delete[] arregloValidaciones;
}

void Controlador::SegundaConsulta() {
    int auxNumRango = vista.MenuMostrarRangosNumHijos();

    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);
        vista.Imprimir(auxPais.nombre);

        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);
            vista.Imprimir(auxCiudad.nombre);

            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucusal = auxCiudad.sucursales->getSucursal(k);

                int indiceC = auxSucusal.empleados->getArreglosRangoHijos()[auxNumRango].indice;

                while (indiceC - 1) {
                    vista.Imprimir((auxSucusal.empleados->getEmpleado(indiceC).nombre));
                    vista.Imprimir((auxSucusal.empleados->getEmpleado(indiceC).apellido));
                    indiceC = (auxSucusal.empleados->getEmpleado(indiceC).sigNumHijos);
                }
            }
        }
    }
}

void Controlador::TeceraConsulta() {

    int numPais = vista.MostrarElementos(multilistaPaises->getElementos(),
                                         multilistaPaises->getSize());

    delete[] multilistaPaises->getElementos();

    Pais auxPais = multilistaPaises->getPais(numPais);

    int numCiudad = vista.MostrarElementos(auxPais.ciudades->getElementos(), auxPais.ciudades->getSize());
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);


    struct EstructuraAuxAL {
        std::string actividadLaboral;
        std::string nombreEmpleado;
        std::string apellidoEmpleado;
    };

    struct EstructuraAuxCiudadN {
        std::string nombre; // Nombre de la ciudad
        RBTree<std::string, EstructuraAuxAL> *arbolActividadLaboral = new RBTree<std::string, EstructuraAuxAL>; // Indice Arreglo grande / Nombre de la activida laboral
    };


    RBTree<std::string, EstructuraAuxCiudadN>* arbolCiudadNacimiento = new RBTree<std::string, EstructuraAuxCiudadN>;

    for (int i = 0; i < auxCiudad.sucursales->getSize(); i++) {
        Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(i);
        Cabecera<std::string> *pCabeceraCiudadNacimiento = auxSucursal.empleados->getCCiudadNacimiento();
        int indiceCabera = 0;
        while (pCabeceraCiudadNacimiento[indiceCabera].atributo != "" ||
               pCabeceraCiudadNacimiento[indiceCabera].indice != -1)
        {

            int indice = pCabeceraCiudadNacimiento[indiceCabera].indice;
            EstructuraAuxCiudadN auxiliarCN;
            auxiliarCN.nombre = auxSucursal.empleados->getEmpleado(indice).ciudadNacimiento;
            while (indice != -1)
            {
                EstructuraAuxAL auxiliarAL;

                auxiliarAL.actividadLaboral = auxSucursal.empleados->getEmpleado(indice).actividadLaboral;
                auxiliarAL.nombreEmpleado = auxSucursal.empleados->getEmpleado(indice).nombre;
                auxiliarAL.apellidoEmpleado = auxSucursal.empleados->getEmpleado(indice).apellido;

                auxiliarCN.arbolActividadLaboral->Insert(auxiliarCN.arbolActividadLaboral,
                                                         auxiliarCN.arbolActividadLaboral->createNodo(auxiliarAL.actividadLaboral,auxiliarAL));

                indice = auxSucursal.empleados->getEmpleado(indice).sigCiudadNacimiento;
            }

            arbolCiudadNacimiento->Insert(arbolCiudadNacimiento,
                                          arbolCiudadNacimiento->createNodo(auxiliarCN.nombre, auxiliarCN));
            indiceCabera++;
        }
    }

    Queue<Nodo<std::string, EstructuraAuxCiudadN> *> ciudadesNacimiento = arbolCiudadNacimiento->inorden();
    while (!ciudadesNacimiento.IsEmpty()) {
        EstructuraAuxCiudadN auxCN = ciudadesNacimiento.Dequeue()->otroDato;
        Queue<Nodo<std::string, EstructuraAuxAL> *> actividadLaboral = auxCN.arbolActividadLaboral->inorden();

        while (!actividadLaboral.IsEmpty()) {
            EstructuraAuxAL auxAl = actividadLaboral.Dequeue()->otroDato;
            vista.Imprimir(auxCN.nombre + "-" + auxAl.actividadLaboral);
            vista.Imprimir("\t\t"+auxAl.nombreEmpleado + "-" + auxAl.apellidoEmpleado);
        }
    }

    delete arbolCiudadNacimiento;
}

void Controlador::CuartaConsulta() {
    int numRango = vista.PedirElemento();

    struct EstructuAux {
        int numEmpleados;
        std::string nombre;
        std::string nombreGerente;
        std::string barrio;
    };
    // Numero de empleado, Indice
    RBTree<int, EstructuAux> *arbolEstructuras = new RBTree<int, EstructuAux>;

    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);

        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);

            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(k);

                EstructuAux aux;
                aux.numEmpleados = auxSucursal.empleados->getNumEmpleados();
                aux.nombre = auxSucursal.nombre;
                aux.barrio = auxSucursal.barrio;
                aux.nombreGerente = auxSucursal.nombreGerente;


                arbolEstructuras->Insert(arbolEstructuras,arbolEstructuras->createNodo(auxSucursal.empleados->getNumEmpleados(),aux));
            }
        }
    }

    Queue<Nodo<int,EstructuAux>*> colaSucursales = arbolEstructuras->inorden();

    while(!colaSucursales.IsEmpty())
    {
        EstructuAux auxDatos = colaSucursales.Dequeue()->otroDato;
        if(auxDatos.numEmpleados >= numRango)
        {
            vista.Imprimir("Nombre: " + auxDatos.nombre);
            vista.Imprimir("Nombre Gerente: "+auxDatos.nombreGerente);
            vista.Imprimir("Barrio: "+auxDatos.barrio);
            vista.Imprimir("Numero empleados: "+ std::to_string(auxDatos.numEmpleados) +"\n\n");
        }
    }
}

void Controlador::QuintaConsulta() {
    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);
        vista.Imprimir("\t" + auxPais.nombre);
        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);
            vista.Imprimir("\t\t" + auxCiudad.nombre);
            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucusal = auxCiudad.sucursales->getSucursal(k);

                std::string nombreSucursal = "\t\t\tNombre Sucursal " + auxSucusal.nombre;
                std::string nombreSucursalG = "\t\t\tNombre Gerente " + auxSucusal.nombreGerente;
                std::string numHombre =
                        "\t\t\t\tNúmero de Hombres " + std::to_string(auxSucusal.empleados->getNumHombres());;
                std::string numMujeres =
                        "\t\t\t\tNúmero de Mujeres " + std::to_string(auxSucusal.empleados->getNumMujeres());

                vista.Imprimir(nombreSucursal);
                vista.Imprimir(nombreSucursalG);
                vista.Imprimir(numHombre);
                vista.Imprimir(numMujeres);
            }
        }
    }
}
