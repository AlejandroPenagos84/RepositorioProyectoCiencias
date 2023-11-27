#ifndef MULTILISTAHIJO_H
#define MULTILISTAHIJO_H

#include "../../Estructuras/Hijo.h"
#include "../../Librerias/Cabecera.h"
#include<vector>

/**
 * @brief Clase MultilistaHijo
 *
 * Maneja la lógica para almacenar una lista de hijos con organización por categoría.
 */
class MultilistaHijo {
private:
    /**
     * @brief Arreglo de hijos.
     */
    Hijo *hijos;

    /**
     * @brief Posición libre actual en el arreglo de hijos.
     */
    int posLibre;

    /**
     * @brief Cabecera para organizar los hijos por categoría (en este caso, por edad).
     */
    Cabecera<std::string> *CEdad;

    /**
     * @brief Tamaño actual del arreglo de hijos.
     */
    int size;

public:
    /**
     * @brief Constructor de la clase.
     *
     * @param max Tamaño máximo del arreglo de hijos.
     */
    explicit MultilistaHijo(int max);

    /**
     * @brief Agrega un hijo a la multilista.
     *
     * @param hijo El hijo a agregar.
     */
    void AgregarHijo(Hijo hijo);

    /**
     * @brief Modifica la categoría de un hijo en la multilista.
     *
     * @param num Número de la categoría a modificar.
     * @param valor Nuevo valor para la categoría.
     * @param indice Índice en el arreglo de hijos a modificar.
     */
    void ModificarCategoria(int num, int valor, int indice);

    /**
     * @brief Elimina un hijo de la multilista.
     *
     * @param indiceArray Índice en el arreglo de hijos a eliminar.
     */
    void Eliminar(int indiceArray);

    /**
     * @brief Obtiene un hijo del arreglo.
     *
     * @param indiceArray Índice en el arreglo de hijos.
     * @return El hijo en la posición especificada.
     */
    Hijo getHijo(int indiceArray);

    /**
     * @brief Imprime la categoría de edad de los hijos en un rango específico.
     *
     * @param inicio Edad mínima del rango.
     * @param fin Edad máxima del rango.
     */
    void ImprimirEdad(int inicio, int fin);

    Cabecera<std::string> *getCabecera();

private:
    /**
     * @brief Organiza un hijo en la categoría especificada.
     *
     * @param cabecera Cabecera de la categoría.
     * @param indiceArray Índice en el arreglo de hijos.
     * @param siguienteIndice Índice del siguiente hijo en la categoría.
     * @param indiceCabecera Índice de la cabecera de la categoría.
     */
    void OrganizarCategoria(Cabecera<std::string> *&cabecera,
                            int indiceArray,
                            int Hijo::*siguienteIndice,
                            int indiceCabecera);

    /**
     * @brief Cambia la categoría de un hijo.
     *
     * @param cabecera Cabecera de la categoría.
     * @param atributo Atributo que se cambiará.
     * @param valor Nuevo valor para el atributo.
     * @param siguienteIndice Índice del atributo que se cambiará.
     * @param indiceArray Índice en el arreglo de hijos.
     * @param indiceCabeceraAntigua Índice de la cabecera antigua.
     * @param getCabecera Función para obtener la nueva cabecera.
     */
    void CambiarCategoria(
            Cabecera<std::string> *&cabecera,
            int Hijo::*atributo,
            int valor,
            int Hijo::*siguienteIndice,
            int indiceArray,
            int indiceCabeceraAntigua,
            int (MultilistaHijo::*getCabecera)(int));

    /**
     * @brief Obtiene la cabecera de la categoría de edad para un hijo en específico.
     *
     * @param indiceArray Índice en el arreglo de hijos.
     * @return La cabecera de la categoría de edad.
     */
    int getCabeceraEdad(int indiceArray);

    std::string *getElementos();
};

#endif
