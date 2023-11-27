#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"
#include "ControlDAO/ControlDAO.h"

class ControlDAO;
class Vista;

/**
 * @brief Clase que representa el controlador de la aplicación.
 *
 * El controlador gestiona la interacción entre la vista, la lógica de la aplicación y la capa de acceso a datos.
 */
class Controlador
{
private:
    Vista* vista;  ///< Puntero a la instancia de la clase Vista.
    ControlDAO* controlDao; ///< Puntero a la instancia de la clase ControlDAO.
    MultilistaPaises* multilistaPaises; ///< Puntero a la instancia de la clase MultilistaPaises.

public:
    /**
     * @brief Constructor de la clase Controlador.
     *
     * Inicializa los punteros a la vista, al controlador DAO y a la multilista de países.
     */
    Controlador();

    /**
     * @brief Método para mostrar el menú principal de la aplicación.
     */
    void MostrarMenu();

    /**
     * @brief Método para realizar la primera consulta.
     */
    void PrimeraConsulta();

    /**
     * @brief Método para realizar la segunda consulta.
     */
    void SegundaConsulta();

    /**
     * @brief Método para realizar la tercera consulta.
     */
    void TeceraConsulta();

    /**
     * @brief Método para realizar la cuarta consulta.
     */
    void CuartaConsulta();

    /**
     * @brief Método para realizar la quinta consulta.
     */
    void QuintaConsulta();

};

#endif
