#include "MultilistaEmpleados.h"

// Métodos públicos que implementan los métodos de cambiar

/**
 * @brief Modifica un atributo de tipo string de un empleado en la multilista.
 *
 * @param num Número que identifica el atributo a modificar.
 * @param nuevoDato Nuevo valor para el atributo.
 * @param indice Índice del empleado en el arreglo.
 */
void MultilistaEmpleados::ModificarAtributo(int num, std::string &nuevoDato, int indice) {
    switch (num) {
        case 1: // 1 Actividad Laboral
            CambiarAtributo(arbolActividad,
                            &Empleado::actividadLaboral,
                            nuevoDato,
                            &Empleado::sigActividadLaboral,
                            CActividadLaboral,
                            indice,
                            arbolActividad->findNodo(empleados[indice].actividadLaboral)->otroDato,
                            indiceActividadLaboral);
            break;

        case 2: // 2 Ciudad Nacimiento
            CambiarAtributo(arbolCiudadNacimiento,
                            &Empleado::ciudadNacimiento,
                            nuevoDato,
                            &Empleado::sigCiudadNacimiento,
                            CCiudadNacimiento,
                            indice,
                            arbolCiudadNacimiento->findNodo(empleados[indice].ciudadNacimiento)->otroDato,
                            indiceCiudadNacimiento);
            break;

        case 3: // 3 Barrio
            CambiarAtributo(arbolBarrio, &Empleado::barrio,
                            nuevoDato,
                            &Empleado::sigBarrio,
                            CBarrio, indice,
                            arbolBarrio->findNodo(empleados[indice].barrio)->otroDato,
                            indiceBarrio);
            break;

        case 4: // 4 Sucursales
            CambiarAtributo(arbolSucursales,
                            &Empleado::sucursalTrabajo,
                            nuevoDato,
                            &Empleado::sigNombreSurcursal,
                            CSucursal,
                            indice,
                            arbolSucursales->findNodo(empleados[indice].sucursalTrabajo)->otroDato,
                            indiceSucursal);
            break;

        default: // En caso de que se ingrese otro número
            break;
    }
}

/**
 * @brief Modifica un atributo de las categorías de un empleado en la multilista.
 *
 * @param num Número que identifica la categoría a modificar.
 * @param valor Nuevo valor para la categoría.
 * @param indice Índice del empleado en el arreglo.
 */
void MultilistaEmpleados::ModificarCategoria(int num, int valor, int indice) {
    switch (num) {
        case 1:
            CambiarCategoria(CNumeroHijos,
                             &Empleado::numHijos,
                             valor,
                             &Empleado::sigNumHijos,
                             indice,
                             getCabeceraNumHijos(empleados[indice].numHijos),
                             &MultilistaEmpleados::getCabeceraNumHijos);
            break;

        case 2://FechaNacimiento
            CambiarCategoria(CEdad,
                             &Empleado::edad,
                             valor,
                             &Empleado::sigEdad,
                             indice,
                             getCabeceraEdad(empleados[indice].edad),
                             &MultilistaEmpleados::getCabeceraEdad);
            break;

        default:
            break;
    }
}

/**
 * @brief Modifica atributos de tipo string que no son parte de una cabecera en la multilista.
 *
 * @param num Número que identifica el atributo a modificar.
 * @param indice Índice del empleado en el arreglo.
 * @param nuevoDato Nuevo valor para el atributo.
 */
void MultilistaEmpleados::ModificarS(int num, int indice, std::string nuevoDato) {
    switch (num) {
        case 1:
            CambiarS(&Empleado::nombre, indice, std::move(nuevoDato));
            break;

        case 2:
            CambiarS(&Empleado::apellido, indice, std::move(nuevoDato));
            break;

        case 3:
            CambiarS(&Empleado::tipoIdentificacion, indice, std::move(nuevoDato));
            break;

        case 4:
            CambiarS(&Empleado::numIdentificacion, indice, std::move(nuevoDato));
            break;

        case 5:
            CambiarS(&Empleado::telefonoCelular, indice, std::move(nuevoDato));
            break;

        case 6:
            CambiarS(&Empleado::telefonoFijo, indice, std::move(nuevoDato));
            break;

        case 7:
            CambiarS(&Empleado::email, indice, std::move(nuevoDato));
            break;

        case 8:
            CambiarS(&Empleado::paisNacimiento, indice, std::move(nuevoDato));
            break;

        case 9:
            CambiarS(&Empleado::ciudadResidencia, indice, std::move(nuevoDato));
            break;

        case 10:
            CambiarS(&Empleado::direccion, indice, std::move(nuevoDato));
            break;

        default:
            // Opción por defecto, si no coincide con ninguna de las anteriores
            break;
    }
}

/**
 * @brief Elimina los valores de tipo char de un empleado en la multilista.
 *
 * @param num Número que identifica el atributo a modificar.
 * @param indice Índice del empleado en el arreglo.
 * @param nuevoDato Nuevo valor para el atributo.
 */
void MultilistaEmpleados::ModificarC(int num, int indice, char nuevoDato) {
    switch (num) {
        case 1:
            CambiarC(&Empleado::sexo, indice, (nuevoDato));
            break;

        case 2:
            CambiarC(&Empleado::tieneHijos, indice, nuevoDato);
            break;
        default:
            break;
    }
}

// Métodos privados con los que cambio los atributos

/**
 * @brief Cambia un atributo de tipo string de un empleado en la multilista.
 *
 * @param atributo Puntero al atributo de tipo string.
 * @param indiceArray Índice del empleado en el arreglo.
 * @param nuevoDato Nuevo valor para el atributo.
 */
void MultilistaEmpleados::CambiarS(std::string Empleado::*atributo, int indiceArray, std::string nuevoDato) {
    empleados[indiceArray].*atributo = std::move(nuevoDato);
}

/**
 * @brief Cambia un atributo de tipo char de un empleado en la multilista.
 *
 * @param atributo Puntero al atributo de tipo char.
 * @param indiceArray Índice del empleado en el arreglo.
 * @param nuevoDato Nuevo valor para el atributo.
 */
void MultilistaEmpleados::CambiarC(char Empleado::*atributo, int indiceArray, char nuevoDato) {
    empleados[indiceArray].*atributo = nuevoDato;
}

/**
 * @brief Cambia un atributo y lo reubica en la lista de cabeceras.
 *
 * Este método es para los datos tipo string, donde no existe un rango.
 *
 * @param arbol Arbol del atributo.
 * @param atributo Puntero al atributo.
 * @param nuevoValor Nuevo valor para el atributo.
 * @param siguienteIndice Puntero al siguiente índice.
 * @param cabecera Cabecera.
 * @param indiceArrayEmpleado Posición del empleado en el array.
 * @param indiceCabecera Índice de la cabecera.
 * @param nuevoAtributoIndice Índice que hace referencia a los índices de las cabeceras.
 */
void MultilistaEmpleados::CambiarAtributo(
        RBTree<std::string, int> *&arbol,
        std::string Empleado::*atributo,
        std::string nuevoValor,
        int Empleado::*siguienteIndice,
        Cabecera<std::string> *&cabecera,
        int indiceArrayEmpleado,
        int indiceCabecera,
        int &nuevoAtributoIndice
) {
    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabecera].indice;

    indiceAnterior = indiceArreglo;
    indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;

    // Encuentra la posición del empleado en el arreglo
    while (indiceArreglo != indiceArrayEmpleado) {
        indiceAnterior = indiceArreglo;
        indiceArreglo = empleados[indiceArreglo].*siguienteIndice;
        indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;
    }

    // Cambia el valor del atributo
    empleados[indiceArrayEmpleado].*atributo = std::move(nuevoValor);

    // Actualiza los punteros en la lista de cabeceras
    if (indiceArreglo == cabecera[indiceCabecera].indice)
        cabecera[indiceCabecera].indice = indiceSiguiente;
    else
        empleados[indiceAnterior].*siguienteIndice = indiceSiguiente;

    // Si la cabecera está vacía, actualiza el índice de la cabecera y el atributo
    if (cabecera[indiceCabecera].indice == -1) {
        nuevoAtributoIndice--;
    }

    // Reorganiza el árbol después del cambio
    Reorganizar(arbol,
                cabecera,
                atributo,
                nuevoAtributoIndice,
                siguienteIndice,
                indiceArrayEmpleado);
}

/**
 * @brief Cambia un atributo y lo reubica en la lista de cabeceras.
 *
 * Este método es para los datos tipo string, donde ya existe un rango.
 *
 * @param cabecera Cabecera.
 * @param atributo Puntero al atributo.
 * @param valor Nuevo valor para el atributo.
 * @param siguienteIndice Puntero al siguiente índice.
 * @param indiceArray Posición del empleado en el array.
 * @param indiceCabeceraAntigua Índice de la cabecera antigua.
 * @param getCabecera Función para obtener la nueva cabecera.
 */
void MultilistaEmpleados::CambiarCategoria(
        Cabecera<std::string> *&cabecera,
        int Empleado::*atributo,
        int valor,
        int Empleado::*siguienteIndice,
        int indiceArray,
        int indiceCabeceraAntigua,
        int (MultilistaEmpleados::*getCabecera)(int)
) {
    int indiceAnterior;
    int indiceSiguiente;
    int indiceArreglo = cabecera[indiceCabeceraAntigua].indice;

    indiceAnterior = indiceArreglo;
    indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;

    // Encuentra la posición del empleado en el arreglo
    while (indiceArreglo != indiceArray) {
        indiceAnterior = indiceArreglo;
        indiceArreglo = empleados[indiceArreglo].*siguienteIndice;
        indiceSiguiente = empleados[indiceArreglo].*siguienteIndice;
    }

    // Cambia el valor del atributo
    empleados[indiceArray].*atributo = valor;

    // Actualiza los punteros en la lista de cabeceras
    if (indiceArreglo == cabecera[indiceCabeceraAntigua].indice)
        cabecera[indiceCabeceraAntigua].indice = indiceSiguiente;
    else {
        empleados[indiceArreglo].*siguienteIndice = indiceSiguiente;
    }

    // Organiza la nueva categoría después del cambio
    OrganizarCategoria(cabecera,
                       indiceArray,
                       siguienteIndice,
                       (this->*getCabecera)(indiceArray));
}
