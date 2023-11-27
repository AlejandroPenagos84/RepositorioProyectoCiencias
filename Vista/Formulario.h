#ifndef FORMULARIO_H
#define FORMULARIO_H

#include "../Estructuras/Empleado.h"
#include "../Estructuras/Sucursal.h"
#include "../Estructuras/Hijo.h"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>

/**
 * @brief Clase que representa un formulario para capturar información sobre empleados, hijos y sucursales.
 */
class Formulario
{
public:
    /**
     * @brief Captura la información sobre los hijos de un empleado.
     * @param empleado Objeto de la clase Empleado al cual se agregarán los hijos.
     */
    void capturarInfoHijos(Empleado &empleado);

    /**
     * @brief Captura la información sobre un empleado.
     * @return Objeto de la clase Empleado con la información capturada.
     */
    Empleado capturarInfoEmpleado();

    /**
     * @brief Captura la información sobre una sucursal.
     * @return Objeto de la clase Sucursal con la información capturada.
     */
    Sucursal capturarInformacionSucursal();
};

#endif
