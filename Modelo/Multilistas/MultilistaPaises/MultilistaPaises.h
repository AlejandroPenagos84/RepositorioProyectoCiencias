#ifndef MULTILISTAPAISES_H
#define MULTILISTAPAISES_H

#include "../../Estructuras/Pais.h"

/**
 * @brief Clase MultilistaPaises
 *
 * Maneja la lógica para almacenar una lista de países.
 */
class MultilistaPaises {
private:
    /**
     * @brief Arreglo de países.
     */
    Pais *paises;

    /**
     * @brief Posición libre actual en el arreglo de países.
     */
    int posLibre;

    /**
     * @brief Tamaño actual del arreglo de países.
     */
    int size;

public:
    /**
     * @brief Constructor de la clase.
     *
     * @param max Tamaño máximo del arreglo de países.
     */
    explicit MultilistaPaises(int max);

    /**
     * @brief Agrega un país a la multilista.
     *
     * @param pais El país a agregar.
     */
    void AgregarPais(Pais pais);

    /**
     * @brief Elimina un país de la multilista.
     *
     * @param indiceArray Índice en el arreglo de países a eliminar.
     */
    void EliminarPais(int indiceArray);

    /**
     * @brief Modifica un país en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de países a modificar.
     */
    void ModificarPais(int num, std::string nuevoDato, int indiceArray);

    /**
     * @brief Obtiene un país del arreglo.
     *
     * @param indiceArray Índice en el arreglo de países.
     * @return El país en la posición especificada.
     */
    Pais getPais(int indiceArray);

    /**
     * @brief Obtiene el tamaño actual del arreglo de países.
     *
     * @return El tamaño actual del arreglo de países.
     */
    int getSize();

    /**
     * @brief Obtiene los elementos del arreglo de países como un arreglo de cadenas.
     *
     * @return Un arreglo de cadenas con los elementos del arreglo de países.
     */
    std::string *getElementos();
};

#endif
