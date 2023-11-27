#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Edad.h"
#include "../Multilistas/MultilistaHijos/MultilistaHijo.h"
#include <string>

/**
 * @brief Estructura que representa a un empleado.
 */
struct Empleado {
    int pk; ///< Clave primaria del empleado.
    int fk; ///< Clave foránea del empleado.

    std::string nombre; ///< Nombre del empleado.
    std::string apellido; ///< Apellido del empleado.
    std::string tipoIdentificacion; ///< Tipo de identificación del empleado.
    std::string numIdentificacion; ///< Número de identificación del empleado.
    char sexo; ///< Género del empleado.
    std::string telefonoCelular; ///< Número de teléfono celular del empleado.
    std::string telefonoFijo; ///< Número de teléfono fijo del empleado.
    std::string email; ///< Correo electrónico del empleado.

    std::string ciudadNacimiento; ///< Ciudad de nacimiento del empleado.
    std::string paisNacimiento; ///< País de nacimiento del empleado.
    std::string ciudadResidencia; ///< Ciudad de residencia del empleado.
    std::string direccion; ///< Dirección del empleado.

    char tieneHijos; ///< Indica si el empleado tiene hijos o no.
    std::string actividadLaboral; ///< Actividad laboral del empleado.
    std::string sucursalTrabajo; ///< Sucursal de trabajo del empleado.
    std::string barrio; ///< Barrio de residencia del empleado.
    int numHijos; ///< Número de hijos del empleado.
    std::string fechaNacimiento; ///< Fecha de nacimiento del empleado.
    bool estado; ///< Estado del empleado (activo/inactivo).
    MultilistaHijo* hijos; ///< Multilista que almacena la información de los hijos del empleado.
    int edad; ///< Edad del empleado.

    // Estas variables se inicializan con -1 para indicar que no tienen un siguiente dato asociado.
    int sigSexo{-1}; ///< Índice del siguiente empleado por género.
    int sigActividadLaboral{-1}; ///< Índice del siguiente empleado por actividad laboral.
    int sigEdad{-1}; ///< Índice del siguiente empleado por edad.
    int sigNombreSurcursal{-1}; ///< Índice del siguiente empleado por sucursal de trabajo.
    int sigCiudadNacimiento{-1}; ///< Índice del siguiente empleado por ciudad de nacimiento.
    int sigBarrio{-1}; ///< Índice del siguiente empleado por barrio de residencia.
    int sigNumHijos{-1}; ///< Índice del siguiente empleado por número de hijos.

    /**
     * @brief Constructor por defecto de la estructura Empleado.
     */
    Empleado()
    {
        // Se inicializa la multilista de hijos con un límite de 5 hijos por empleado.
        hijos = new MultilistaHijo(5);
        // Se calcula la edad del empleado en base a la fecha de nacimiento.
        edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));
    }
};

#endif
