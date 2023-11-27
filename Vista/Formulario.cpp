#include <algorithm>
#include "Formulario.h"


void Formulario::capturarInfoHijos(Empleado& empleado)
{
    for (int i = 0; i < empleado.numHijos; ++i) {
        Hijo hijo;

        do {
            std::cout << "Nombre del hijo " << i + 1 << ": ";
            std::getline(std::cin, hijo.nombre);
            if (!std::all_of(hijo.nombre.begin(), hijo.nombre.end(), ::isalpha)) {
                std::cerr << "Error: El nombre debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(hijo.nombre.begin(), hijo.nombre.end(), ::isalpha));

        do {
            std::cout << "Fecha del hijo (DD/MM/AAAA): ";
            std::cin >> hijo.fechaNacimiento;
            if (!std::all_of(hijo.fechaNacimiento.begin(), hijo.fechaNacimiento.end(), ::isdigit)) {
                std::cerr << "Error: La fecha debe contener solo n�meros." << std::endl;
            }
        } while (!std::all_of(hijo.fechaNacimiento.begin(), hijo.fechaNacimiento.end(), ::isdigit));

        std::cin.ignore(); // Limpiar el buffer del teclado
    }
}

Empleado Formulario::capturarInfoEmpleado()
{
    Empleado empleado;

    try {
        do {
            std::cout << "Nombre: ";
            std::getline(std::cin, empleado.nombre);
            if (!std::all_of(empleado.nombre.begin(), empleado.nombre.end(), ::isalpha)) {
                std::cerr << "Error: El nombre debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.nombre.begin(), empleado.nombre.end(), ::isalpha));

        do {
            std::cout << "Apellido: ";
            std::getline(std::cin, empleado.apellido);
            if (!std::all_of(empleado.apellido.begin(), empleado.apellido.end(), ::isalpha)) {
                std::cerr << "Error: El apellido debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.apellido.begin(), empleado.apellido.end(), ::isalpha));

        do {
            std::cout << "Tipo de identificaci�n (C�dula de ciudadan�a, c�dula de extranjer�a o tarjeta de identidad): ";
            std::getline(std::cin, empleado.tipoIdentificacion);
            if (!std::all_of(empleado.tipoIdentificacion.begin(), empleado.tipoIdentificacion.end(), ::isalpha)) {
                std::cerr << "Error: El tipo de identificaci�n debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.tipoIdentificacion.begin(), empleado.tipoIdentificacion.end(), ::isalpha));

        do {
            std::cout << "N�mero de identificaci�n: ";
            std::getline(std::cin, empleado.numIdentificacion);
            if (!std::all_of(empleado.numIdentificacion.begin(), empleado.numIdentificacion.end(), ::isdigit)) {
                std::cerr << "Error: El n�mero de identificaci�n debe contener solo n�meros." << std::endl;
            }
        } while (!std::all_of(empleado.numIdentificacion.begin(), empleado.numIdentificacion.end(), ::isdigit));

        do {
            std::cout << "Sexo (F/M): ";
            std::cin >> empleado.sexo;
            if (empleado.sexo != 'F' && empleado.sexo != 'M' && empleado.sexo != 'f' && empleado.sexo != 'm') {
                std::cerr << "Error: Por favor, ingrese solo 'F' o 'M'." << std::endl;
            }
        } while (empleado.sexo != 'F' && empleado.sexo != 'M' && empleado.sexo != 'f' && empleado.sexo != 'm');

        do {
            std::cout << "Tel�fono celular: ";
            std::cin >> empleado.telefonoCelular;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error: El tel�fono celular debe ser un n�mero v�lido." << std::endl;
            }
        } while (std::cin.fail());

        do {
            std::cout << "Tel�fono fijo: ";
            std::cin >> empleado.telefonoFijo;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Error: El tel�fono fijo debe ser un n�mero v�lido." << std::endl;
            }
        } while (std::cin.fail());

        std::cin.ignore(); // Limpiar el buffer del teclado

        do {
            std::cout << "Email: ";
            std::cin >> empleado.email;
            // Puedes implementar una validaci�n m�s compleja para un formato de email espec�fico si es necesario
        } while (!std::all_of(empleado.email.begin(), empleado.email.end(),
                              [](char c) { return ::isalnum(c) || c == '@' || c == '.'; }));

        do {
            std::cout << "Fecha de Nacimiento (DD/MM/AAAA): ";
            std::cin >> empleado.fechaNacimiento;
            if (!std::all_of(empleado.fechaNacimiento.begin(), empleado.fechaNacimiento.end(), ::isdigit)) {
                std::cerr << "Error: La fecha de nacimiento debe contener solo n�meros." << std::endl;
            }
        } while (!std::all_of(empleado.fechaNacimiento.begin(), empleado.fechaNacimiento.end(), ::isdigit));

        do {
            std::cout << "Ciudad de Nacimiento: ";
            std::cin >> empleado.ciudadNacimiento;
            if (!std::all_of(empleado.ciudadNacimiento.begin(), empleado.ciudadNacimiento.end(), ::isalpha)) {
                std::cerr << "Error: La ciudad de nacimiento debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.ciudadNacimiento.begin(), empleado.ciudadNacimiento.end(), ::isalpha));

        do {
            std::cout << "Pa�s de Nacimiento: ";
            std::cin >> empleado.paisNacimiento;
            if (!std::all_of(empleado.paisNacimiento.begin(), empleado.paisNacimiento.end(), ::isalpha)) {
                std::cerr << "Error: El pa�s de nacimiento debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.paisNacimiento.begin(), empleado.paisNacimiento.end(), ::isalpha));

        do {
            std::cout << "Ciudad de Residencia: ";
            std::cin >> empleado.ciudadResidencia;
            if (!std::all_of(empleado.ciudadResidencia.begin(), empleado.ciudadResidencia.end(), ::isalpha)) {
                std::cerr << "Error: La ciudad de residencia debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.ciudadResidencia.begin(), empleado.ciudadResidencia.end(), ::isalpha));

        std::cin.ignore(); // Limpiar el buffer del teclado

        do {
            std::cout << "Direcci�n: ";
            std::getline(std::cin, empleado.direccion);
            // Puedes ajustar la validaci�n seg�n tus requisitos espec�ficos
        } while (!std::all_of(empleado.direccion.begin(), empleado.direccion.end(),
                              [](char c) { return ::isalnum(c) || ::isspace(c) || c == '.' || c == ','; }));

        do {
            std::cout << "Barrio: ";
            std::getline(std::cin, empleado.barrio);
            if (!std::all_of(empleado.barrio.begin(), empleado.barrio.end(), ::isalpha)) {
                std::cerr << "Error: El barrio debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.barrio.begin(), empleado.barrio.end(), ::isalpha));

        do {
            std::cout << "Actividad laboral (Artes, ciencias sociales, ingenier�as, �reas de la salud, otros): ";
            std::getline(std::cin, empleado.actividadLaboral);
            if (!std::all_of(empleado.actividadLaboral.begin(), empleado.actividadLaboral.end(), ::isalpha)) {
                std::cerr << "Error: La actividad laboral debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.actividadLaboral.begin(), empleado.actividadLaboral.end(), ::isalpha));

        // ... Continuar con el mismo patr�n para otras secciones ...

        do {
            std::cout << "�Tiene hijos? (S/N): ";
            std::cin >> empleado.tieneHijos;
            if (empleado.tieneHijos != 'S' && empleado.tieneHijos != 's' && empleado.tieneHijos != 'N' && empleado.tieneHijos != 'n') {
                std::cerr << "Error: Por favor, ingrese solo 'S' o 'N'." << std::endl;
            }
        } while (empleado.tieneHijos != 'S' && empleado.tieneHijos != 's' && empleado.tieneHijos != 'N' && empleado.tieneHijos != 'n');

        // Captura de informaci�n de los hijos si el empleado tiene hijos
        if (empleado.tieneHijos == 'S' || empleado.tieneHijos == 's') {
            do {
                std::cout << "N�mero de hijos: ";
                std::cin >> empleado.numHijos;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Error: El n�mero de hijos debe ser un n�mero v�lido." << std::endl;
                }
            } while (std::cin.fail());

            std::cin.ignore(); // Limpiar el buffer del teclado

            capturarInfoHijos(empleado);
        }

        // Captura de la sucursal en la que trabaja el empleado
        do {
            std::cout << "Nombre de la sucursal en la que trabaja: ";
            std::getline(std::cin, empleado.sucursalTrabajo);
            if (!std::all_of(empleado.sucursalTrabajo.begin(), empleado.sucursalTrabajo.end(), ::isalpha)) {
                std::cerr << "Error: El nombre de la sucursal debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(empleado.sucursalTrabajo.begin(), empleado.sucursalTrabajo.end(), ::isalpha));

        return empleado;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return Empleado();
    } catch (...) {
        std::cerr << "Error desconocido durante la captura de informaci�n del empleado." << std::endl;
        return Empleado();
    }
}

Sucursal Formulario::capturarInformacionSucursal() {
    Sucursal sucursal;

    try {
        do {
            std::cout << "Nombre de la sucursal: ";
            std::getline(std::cin, sucursal.nombre);
            if (!std::all_of(sucursal.nombre.begin(), sucursal.nombre.end(), ::isalpha)) {
                std::cerr << "Error: El nombre de la sucursal debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(sucursal.nombre.begin(), sucursal.nombre.end(), ::isalpha));

        do {
            std::cout << "Direcci�n de la sucursal: ";
            std::getline(std::cin, sucursal.direccion);
            // Puedes ajustar la validaci�n seg�n tus requisitos espec�ficos
        } while (!std::all_of(sucursal.direccion.begin(), sucursal.direccion.end(),
                              [](char c) { return ::isalnum(c) || ::isspace(c) || c == '.' || c == ','; }));

        do {
            std::cout << "Barrio de la sucursal: ";
            std::getline(std::cin, sucursal.barrio);
            if (!std::all_of(sucursal.barrio.begin(), sucursal.barrio.end(), ::isalpha)) {
                std::cerr << "Error: El barrio de la sucursal debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(sucursal.barrio.begin(), sucursal.barrio.end(), ::isalpha));

        do {
            std::cout << "Nombre del gerente de la sucursal: ";
            std::getline(std::cin, sucursal.nombreGerente);
            if (!std::all_of(sucursal.nombreGerente.begin(), sucursal.nombreGerente.end(), ::isalpha)) {
                std::cerr << "Error: El nombre del gerente debe contener solo letras." << std::endl;
            }
        } while (!std::all_of(sucursal.nombreGerente.begin(), sucursal.nombreGerente.end(), ::isalpha));

        // Puedes continuar con el mismo patr�n para otras secciones si las tienes

        return sucursal;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // funci�n devuelve un objeto Sucursal vac�o.
        return Sucursal();
    } catch (...) {
        std::cerr << "Error desconocido durante la captura de informaci�n de la sucursal." << std::endl;
        // funci�n devuelve un objeto Sucursal vac�o.
        return Sucursal();
    }
}

