#ifndef CONTROLDAO_H
#define CONTROLDAO_H
#include "../Controlador.h"
#include "fstream"
#include <vector>


class Controlador;

class ControlDAO {
private:
    Controlador* control;

    // Con los arboles buscaré los indices segun la llave primaria

    //Arboles con llaves secundarias y los datos completos
    RBTree<int,Hijo>* hijosLlaveF;
    RBTree<int,Empleado>* empleadosLlaveF;
    RBTree<int, Sucursal>* sucurcalesLlaveF;
    RBTree<int,Ciudad>* ciudadesLlaveF;
    RBTree<int,Pais>* paises;
public:
    RBTree<int, Pais> *getPaises() const;

private:
    int pos;
public:

    explicit ControlDAO(Controlador* ctrl);
    void LeerHijosDAO(const std::string &filename);
    void LeerEmpleadosDAO(const std::string &filename);
    void LeerSucursalesDAO(const std::string &filename);
    void LeerCiudadesDAO(const std::string &filename);
    void LeerPaisesDAO(const std::string &filename);


    RBTree<int, Hijo> *getHijosLlaveF() const;

    RBTree<int, Empleado> *getEmpleadosLlaveF() const;

    RBTree<int, Sucursal> *getSucurcalesLlaveF() const;

    RBTree<int, Ciudad> *getCiudadesLlaveF() const;

    // Metodos Para el Archivo de Hijos
    void AgregarHijoDAO();

    void EliminarHijoDAO();

    void ModificarHijoDAO(const std::string& filename, const Hijo& updatedData);

    // Metodos Para el Archivo de Empleados
    void AgregarEmpleadoDAO();

    void EliminarEmpleadoDAO();

    void ModificarEmpleadoDAO(const std::string &filename, const Empleado &updatedData);


    //Metodos para el archivo de sucursales
    void AgregarSucursalDAO();

    void EliminarSucursalDAO();

    void ModificarSucursalDAO(const std::string &filename, const Sucursal &updatedData);


    // Metodo para el archivo de Ciudades
    void AgregarCiudadDAO();

    void EliminarCiudadDAO();

    void ModificarCiudadDAO(const std::string &filename, const Ciudad &updatedData);


    //Metodos para el archivo de Ciudades
    void AgregarPaisDAO();

    void EliminarPaisDAO();

    void ModificarPaisDAO(const std::string &filename, const Pais &updatedData);

};


#endif
/*

 */