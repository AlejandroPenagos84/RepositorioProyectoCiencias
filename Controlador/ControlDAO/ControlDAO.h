#ifndef CONTROLDAO_H
#define CONTROLDAO_H

#include "../Controlador.h"
#include "fstream"
#include <vector>

class Controlador;

/**
 * @brief La clase ControlDAO se encarga de realizar operaciones de lectura y escritura en archivos para las entidades
 *        Hijo, Empleado, Sucursal, Ciudad y País, y mantiene árboles de búsqueda para acceder eficientemente a los datos.
 */
class ControlDAO {
private:
    Controlador *control;

    // Con los árboles buscaré los índices según la llave primaria

    // Árboles con llaves secundarias y los datos completos
    RBTree<int, Hijo> *hijosLlaveF;
    RBTree<int, Empleado> *empleadosLlaveF;
    RBTree<int, Sucursal> *sucursalesLlaveF;
    RBTree<int, Ciudad> *ciudadesLlaveF;
    RBTree<int, Pais> *paises;

public:
    /**
     * @brief Constructor de la clase ControlDAO.
     * @param ctrl Puntero al controlador principal.
     */
    explicit ControlDAO(Controlador *ctrl);

    /**
     * @brief Obtiene el árbol de países.
     * @return Puntero al árbol de países.
     */
    RBTree<int, Pais> *getPaises() const;

private:
    int pos;

public:
    /**
     * @brief Obtiene el árbol de hijos.
     * @return Puntero al árbol de hijos.
     */
    RBTree<int, Hijo> *getHijosLlaveF() const;

    /**
     * @brief Obtiene el árbol de empleados.
     * @return Puntero al árbol de empleados.
     */
    RBTree<int, Empleado> *getEmpleadosLlaveF() const;

    /**
     * @brief Obtiene el árbol de sucursales.
     * @return Puntero al árbol de sucursales.
     */
    RBTree<int, Sucursal> *getSucursalesLlaveF() const;

    /**
     * @brief Obtiene el árbol de ciudades.
     * @return Puntero al árbol de ciudades.
     */
    RBTree<int, Ciudad> *getCiudadesLlaveF() const;

    // Métodos para el archivo de Hijos

    /**
     * @brief Lee los datos de los hijos desde un archivo.
     * @param filename Nombre del archivo a leer.
     */
    void LeerHijosDAO(const std::string &filename);

    /**
     * @brief Agrega un nuevo hijo a la base de datos.
     */
    void AgregarHijoDAO();

    /**
     * @brief Elimina un hijo de la base de datos.
     */
    void EliminarHijoDAO();

    /**
     * @brief Modifica los datos de un hijo en la base de datos.
     * @param filename Nombre del archivo a modificar.
     * @param updatedData Datos actualizados del hijo.
     */
    void ModificarHijoDAO(const std::string &filename, const Hijo &updatedData);

    // Métodos para el archivo de Empleados

    /**
     * @brief Lee los datos de los empleados desde un archivo.
     * @param filename Nombre del archivo a leer.
     */
    void LeerEmpleadosDAO(const std::string &filename);

    /**
     * @brief Agrega un nuevo empleado a la base de datos.
     */
    void AgregarEmpleadoDAO();

    /**
     * @brief Elimina un empleado de la base de datos.
     */
    void EliminarEmpleadoDAO();

    /**
     * @brief Modifica los datos de un empleado en la base de datos.
     * @param filename Nombre del archivo a modificar.
     * @param updatedData Datos actualizados del empleado.
     */
    void ModificarEmpleadoDAO(const std::string &filename, const Empleado &updatedData);

    // Métodos para el archivo de Sucursales

    /**
     * @brief Lee los datos de las sucursales desde un archivo.
     * @param filename Nombre del archivo a leer.
     */
    void LeerSucursalesDAO(const std::string &filename);

    /**
     * @brief Agrega una nueva sucursal a la base de datos.
     */
    void AgregarSucursalDAO();

    /**
     * @brief Elimina una sucursal de la base de datos.
     */
    void EliminarSucursalDAO();

    /**
     * @brief Modifica los datos de una sucursal en la base de datos.
     * @param filename Nombre del archivo a modificar.
     * @param updatedData Datos actualizados de la sucursal.
     */
    void ModificarSucursalDAO(const std::string &filename, const Sucursal &updatedData);

    // Método para el archivo de Ciudades

    /**
     * @brief Lee los datos de las ciudades desde un archivo.
     * @param filename Nombre del archivo a leer.
     */
    void LeerCiudadesDAO(const std::string &filename);

    /**
     * @brief Agrega una nueva ciudad a la base de datos.
     */
    void AgregarCiudadDAO();

    /**
     * @brief Elimina una ciudad de la base de datos.
     */
    void EliminarCiudadDAO();

    /**
     * @brief Modifica los datos de una ciudad en la base de datos.
     * @param filename Nombre del archivo a modificar.
     * @param updatedData Datos actualizados de la ciudad.
     */
    void ModificarCiudadDAO(const std::string &filename, const Ciudad &updatedData);

    // Métodos para el archivo de Países

    /**
     * @brief Lee los datos de los países desde un archivo.
     * @param filename Nombre del archivo a leer.
     */
    void LeerPaisesDAO(const std::string &filename);

    /**
     * @brief Agrega un nuevo país a la base de datos.
     */
    void AgregarPaisDAO();

    /**
     * @brief Elimina un país de la base de datos.
     */
    void EliminarPaisDAO();

    /**
     * @brief Modifica los datos de un país en la base de datos.
     * @param filename Nombre del archivo a modificar.
     * @param updatedData Datos actualizados del país.
     */
    void ModificarPaisDAO(const std::string &filename, const Pais &updatedData);
};

#endif
