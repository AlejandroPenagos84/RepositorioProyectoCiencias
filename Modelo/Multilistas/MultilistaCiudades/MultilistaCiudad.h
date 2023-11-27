#ifndef MULTILISTACIUDAD_H
#define MULTILISTACIUDAD_H

#include "../../Estructuras/Ciudad.h"


/**
 * @brief Clase MultilistaCiudad
 *
 * Maneja la lógica para almacenar una lista de ciudades.
 */
class MultilistaCiudad {
private:
    /**
     * @brief Arreglo de ciudades.
     */
    Ciudad *ciudades;

    /**
     * @brief Posición libre actual en el arreglo de ciudades.
     */
    int posLibre;

    /**
     * @brief Tamaño actual del arreglo de ciudades.
     */
    int size;

public:
    /**
     * @brief Constructor de la clase.
     *
     * @param max Tamaño máximo del arreglo de ciudades.
     */
    explicit MultilistaCiudad(int max);

    /**
     * @brief Agrega una ciudad a la multilista.
     *
     * @param ciudad Objeto de la clase Ciudad que se agregará a la multilista.
     */
    void AgregarCiudad(Ciudad ciudad);


    /**
     * @brief Elimina una ciudad de la multilista.
     *
     */
    void EliminarCiudad(int indiceArray);

    /**
     * @brief Modifica una ciudad en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de ciudades a modificar.
     */
    void ModificarCiudad(int num, std::string nuevoDato, int indiceArray);

    /**
     * @brief Obtiene una ciudad del arreglo.
     *
     * @param indiceArray Índice en el arreglo de ciudades.
     * @return La ciudad en la posición especificada.
     */
    Ciudad getCiudad(int indiceArray);

    int getSize();

    std::string *getElementos();

};

#endif
