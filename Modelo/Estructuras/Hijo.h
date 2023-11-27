#ifndef HIJO_H
#define HIJO_H

#include "Edad.h"
#include <string>

/**
 * @brief Estructura que representa a un hijo con sus atributos.
 */
struct Hijo
{
    int pk{}; ///< Clave primaria del hijo.
    int fk{}; ///< Clave foránea que relaciona al hijo con su padre o madre.
    std::string nombre{}; ///< Nombre del hijo.
    std::string fechaNacimiento{}; ///< Fecha de nacimiento del hijo en formato "dd/mm/yyyy".
    bool estado{true}; ///< Estado del hijo (activo o inactivo).
    int edad{}; ///< Edad del hijo calculada a partir de la fecha de nacimiento.

    int sigEdad{-1}; ///< Índice al siguiente hijo en la categoría de edad.

    /**
     * @brief Constructor por defecto de la estructura Hijo.
     *
     * Inicializa la edad del hijo utilizando la función calcularEdad y obtenerFechaDesdeString.
     */
    Hijo()
    {
        // Se supone que calcularEdad y obtenerFechaDesdeString están definidas
        edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));
    }
};

#endif
