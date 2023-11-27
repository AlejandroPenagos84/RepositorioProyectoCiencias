#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include "Formulario.h"
#include <limits>
#include "../Controlador/Controlador.h"

class Controlador;

/**
 * @brief Clase que representa la interfaz de usuario.
 */
class Vista
{
private:
    Formulario formulario;    /**< Objeto de la clase Formulario utilizado en la vista. */
    Controlador* controlador;  /**< Puntero a un objeto de la clase Controlador. */

public:
    /**
     * @brief Constructor de la clase Vista.
     * @param ctrl Puntero a un objeto de la clase Controlador.
     */
    Vista(Controlador* ctrl);

    /**
     * @brief Método para mostrar el menú principal y obtener la opción seleccionada por el usuario.
     * @return Opción seleccionada por el usuario.
     */
    int MostrarMenu();

    /**
     * @brief Método para ingresar datos en el formulario.
     */
    void IngresarDatos();

    /**
     * @brief Método que representa el menú global de la aplicación.
     */
    void MenuGlobal();

    /**
     * @brief Método que muestra un menú de consultas y devuelve la opción seleccionada por el usuario.
     * @return Opción seleccionada por el usuario.
     */
    int MenuConsultas();

    /**
     * @brief Método para mostrar elementos de un arreglo de cadenas y devuelve la opción seleccionada por el usuario.
     * @param arreglo Arreglo de cadenas a mostrar.
     * @param tam Tamaño del arreglo.
     * @return Opción seleccionada por el usuario.
     */
    int MostrarElementos(std::string* arreglo, int tam);

    /**
     * @brief Método que representa el menú para mostrar rangos de número de hijos.
     * @return Opción seleccionada por el usuario.
     */
    int MenuMostrarRangosNumHijos();

    /**
     * @brief Método que representa el menú de la primera consulta y recibe un arreglo como parámetro.
     * @param arreglo Arreglo de enteros.
     */
    void MenuPrimeraConsulta(int* arreglo);

    /**
     * @brief Método para pedir al usuario un elemento y devuelve la opción seleccionada.
     * @return Opción seleccionada por el usuario.
     */
    int PedirElemento();

    /**
     * @brief Método para elegir el tipo de consulta a realizar.
     */
    void ElegirConsulta();

    /**
     * @brief Método estático para imprimir mensajes en la consola.
     * @param m Mensaje a imprimir.
     */
    static void Imprimir(std::string m);

private:

};

#endif
