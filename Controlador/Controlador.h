#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"
#include "ControlDAO/ControlDAO.h"

class ControlDAO;
class Vista;

class Controlador
{
private:
    Vista* vista;
    ControlDAO* controlDao;
    MultilistaPaises* multilistaPaises;

public:

    Controlador();
    void MostrarMenu();
    void PrimeraConsulta();
    void SegundaConsulta();
    void TeceraConsulta();
    void CuartaConsulta();
    void QuintaConsulta();

};

#endif
