
#ifndef FORMULARIO_H
#define FORMULARIO_H
#include "../Estructuras/Empleado.h"
#include "../Estructuras/Sucursal.h"
#include "../Estructuras/Hijo.h"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <limits>

class Formulario
{
public:
    void capturarInfoHijos(Empleado &);
    Empleado capturarInfoEmpleado();
    Sucursal capturarInformacionSucursal();
};

#endif
