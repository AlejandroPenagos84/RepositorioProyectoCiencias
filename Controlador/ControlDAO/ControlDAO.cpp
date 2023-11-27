#include "ControlDAO.h"

ControlDAO::ControlDAO(Controlador *ctrl) : control(ctrl) {
    // Arboles con llaves secundarias y los datos completos
    hijosLlaveF = new RBTree<int, Hijo>;
    empleadosLlaveF = new RBTree<int, Empleado>;
    sucursalesLlaveF = new RBTree<int, Sucursal>;
    ciudadesLlaveF = new RBTree<int, Ciudad>;
    paises = new RBTree<int, Pais>;
    pos = 0;
}

/**
 * @brief Convierte un valor entero a un valor booleano.
 * @param value Valor entero a convertir.
 * @return Valor booleano resultante.
 */
bool intToBool(int value) {
    // Convierte cualquier valor distinto de cero a true, y cero a false
    return (value != 0);
}

/**
 * @brief Lee los datos de los hijos desde un archivo CSV.
 * @param filename Nombre del archivo a leer.
 */
void ControlDAO::LeerHijosDAO(const std::string &filename) {
    hijosLlaveF;
    pos = 0;
    // Abrir el archivo CSV
    std::ifstream file(filename);

    // Verificar si el archivo está abierto
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        // return data; // Devolver un vector vacío ya que hubo un error
    }

    // Leer el archivo línea por línea
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Dividir la línea en columnas usando una coma como delimitador
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Crear un objeto Hijo y llenarlo con los valores
        Hijo row;
        if (columns.size() >= 5) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.fechaNacimiento = column[3];
                row.estado = intToBool(std::stoi(columns[4]));

                // Agregar la fila al árbol
                hijosLlaveF->Insert(hijosLlaveF, hijosLlaveF->createNodo(row.pk, row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error al convertir los valores de las columnas a enteros: " << e.what() << std::endl;
            }
        }
    }
    // Cerrar el archivo
    file.close();
}

/**
 * @brief Lee los datos de los empleados desde un archivo CSV.
 * @param filename Nombre del archivo a leer.
 */
void ControlDAO::LeerEmpleadosDAO(const std::string &filename) {
    pos = 0;
    // Abrir el archivo CSV
    std::ifstream file(filename);

    // Verificar si el archivo está abierto
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        // return data; // Devolver un vector vacío ya que hubo un error
    }

    // Leer el archivo línea por línea
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Dividir la línea en columnas usando una coma como delimitador
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Crear un objeto Empleado y llenarlo con los valores
        Empleado row;
        if (columns.size() >= 21) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.apellido = columns[3];
                row.tipoIdentificacion = columns[4];
                row.numIdentificacion = columns[5];
                row.sexo = columns[6][0];
                row.telefonoCelular = columns[7];
                row.telefonoFijo = columns[8];
                row.email = columns[9];
                row.ciudadNacimiento = columns[10];
                row.paisNacimiento = columns[11];
                row.ciudadResidencia = columns[12];
                row.direccion = columns[13];
                row.tieneHijos = columns[14][0];
                row.actividadLaboral = columns[15];
                row.sucursalTrabajo = columns[16];
                row.barrio = columns[17];
                row.numHijos = std::stoi(columns[18]);
                row.fechaNacimiento = columns[19];
                row.estado = intToBool(std::stoi(columns[20]));

                // Agregar la fila al árbol
                empleadosLlaveF->Insert(empleadosLlaveF, empleadosLlaveF->createNodo(row.pk, row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error al convertir los valores de las columnas a enteros: " << e.what() << std::endl;
            }
        }
    }

    // Cerrar el archivo
    file.close();
}

/**
 * @brief Lee los datos de las sucursales desde un archivo CSV.
 * @param filename Nombre del archivo a leer.
 */
void ControlDAO::LeerSucursalesDAO(const std::string &filename) {
    pos = 0;
    // Abrir el archivo CSV
    std::ifstream file(filename);

    // Verificar si el archivo está abierto
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        // return data; // Devolver un vector vacío ya que hubo un error
    }

    // Leer el archivo línea por línea
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Dividir la línea en columnas usando una coma como delimitador
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Crear un objeto Sucursal y llenarlo con los valores
        Sucursal row;
        if (columns.size() >= 7) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.direccion = (columns[3]);
                row.barrio = (columns[4]);
                row.nombreGerente = (columns[5]);
                row.estado = intToBool(std::stoi(columns[6]));

                // Agregar la fila al árbol
                sucursalesLlaveF->Insert(sucursalesLlaveF, sucursalesLlaveF->createNodo(row.pk, row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error al convertir los valores de las columnas a enteros: " << e.what() << std::endl;
            }
        }
    }
    // Cerrar el archivo
    file.close();
    // return data;
}

/**
 * @brief Lee los datos de las ciudades desde un archivo CSV.
 * @param filename Nombre del archivo a leer.
 */
void ControlDAO::LeerCiudadesDAO(const std::string &filename) {
    pos = 0;
    // Abrir el archivo CSV
    std::ifstream file(filename);

    // Verificar si el archivo está abierto
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        // return data; // Devolver un vector vacío ya que hubo un error
    }

    // Leer el archivo línea por línea
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Dividir la línea en columnas usando una coma como delimitador
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Crear un objeto Ciudad y llenarlo con los valores
        Ciudad row;
        if (columns.size() >= 4) {
            try {
                row.pk = std::stoi(columns[0]);
                row.fk = std::stoi(columns[1]);
                row.nombre = (columns[2]);
                row.estado = intToBool(std::stoi(columns[3]));

                // Agregar la fila al árbol
                ciudadesLlaveF->Insert(ciudadesLlaveF, ciudadesLlaveF->createNodo(row.pk, row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error al convertir los valores de las columnas a enteros: " << e.what() << std::endl;
            }
        }
    }
    // Cerrar el archivo
    file.close();
    // return data;
}

/**
 * @brief Lee los datos de los países desde un archivo CSV.
 * @param filename Nombre del archivo a leer.
 */
void ControlDAO::LeerPaisesDAO(const std::string &filename) {
    pos = 0;
    // Abrir el archivo CSV
    std::ifstream file(filename);

    // Verificar si el archivo está abierto
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo!" << std::endl;
        // return data; // Devolver un vector vacío ya que hubo un error
    }

    // Leer el archivo línea por línea
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;

        // Dividir la línea en columnas usando una coma como delimitador
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }

        // Crear un objeto País y llenarlo con los valores
        Pais row;
        if (columns.size() >= 3) {
            try {
                row.pk = std::stoi(columns[0]);
                row.nombre = (columns[1]);
                row.estado = intToBool(std::stoi(columns[2]));

                // Agregar la fila al árbol
                paises->Insert(paises, paises->createNodo(row.pk, row));
                pos++;
            } catch (const std::invalid_argument &e) {
                std::cerr << "Error al convertir los valores de las columnas a enteros: " << e.what() << std::endl;
            }
        }
    }
    // Cerrar el archivo
    file.close();
    // return data;
}

/**
 * @brief Obtiene el árbol de hijos con llave primaria.
 * @return Puntero al árbol de hijos con llave primaria.
 */
RBTree<int, Hijo> *ControlDAO::getHijosLlaveF() const {
    return hijosLlaveF;
}

/**
 * @brief Obtiene el árbol de empleados con llave primaria.
 * @return Puntero al árbol de empleados con llave primaria.
 */
RBTree<int, Empleado> *ControlDAO::getEmpleadosLlaveF() const {
    return empleadosLlaveF;
}

/**
 * @brief Obtiene el árbol de sucursales con llave primaria.
 * @return Puntero al árbol de sucursales con llave primaria.
 */
RBTree<int, Sucursal> *ControlDAO::getSucursalesLlaveF() const {
    return sucursalesLlaveF;
}

/**
 * @brief Obtiene el árbol de ciudades con llave primaria.
 * @return Puntero al árbol de ciudades con llave primaria.
 */
RBTree<int, Ciudad> *ControlDAO::getCiudadesLlaveF() const {
    return ciudadesLlaveF;
}

/**
 * @brief Obtiene el árbol de países con llave primaria.
 * @return Puntero al árbol de países con llave primaria.
 */
RBTree<int, Pais> *ControlDAO::getPaises() const {
    return paises;
}

/**
 * @brief Modifica los datos de un hijo en el archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param updatedData Datos actualizados del hijo.
 */
void ControlDAO::ModificarHijoDAO(const std::string &filename, const Hijo &updatedData) {
    // Abrir el archivo CSV existente para lectura y escritura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Leer todas las líneas del archivo CSV
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Cerrar el archivo de entrada
    inputFile.close();

    // Buscar y modificar la fila que coincide con la clave primaria
    bool found = false;
    for (std::string &row : lines) {
        std::istringstream iss(row);
        std::vector<std::string> columns;

        while (getline(iss, line, ',')) {
            columns.push_back(line);
        }

        // Convertir la primera columna a entero para comparar con la clave primaria
        int pk = std::stoi(columns[0]);

        if (pk == updatedData.pk) {
            // Actualizar los valores de la fila encontrada
            std::ostringstream oss;
            oss << updatedData.pk << ","
                << updatedData.fk << ","
                << updatedData.nombre << ","
                << updatedData.fechaNacimiento;
            row = oss.str();
            found = true;
            break;
        }
    }

    // Si no se encontró la clave primaria, imprimir un mensaje y salir
    if (!found) {
        std::cerr << "Primary key not found!" << std::endl;
        return;
    }

    // Abrir el archivo CSV para escritura
    std::ofstream outputFile(filename);

    // Escribir todas las líneas (modificadas y no modificadas) en el archivo
    for (const std::string &row : lines) {
        outputFile << row << "\n";
    }

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "CSV file updated successfully!" << std::endl;
}

/**
 * @brief Modifica los datos de un empleado en el archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param updatedData Datos actualizados del empleado.
 */
void ControlDAO::ModificarEmpleadoDAO(const std::string &filename, const Empleado &updatedData) {
    // Abrir el archivo CSV existente para lectura y escritura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Leer todas las líneas del archivo CSV
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Cerrar el archivo de entrada
    inputFile.close();

    // Buscar y modificar la fila que coincide con la clave primaria
    bool found = false;
    for (std::string &row : lines) {
        std::istringstream iss(row);
        std::vector<std::string> columns;

        while (getline(iss, line, ',')) {
            columns.push_back(line);
        }

        // Convertir la primera columna a entero para comparar con la clave primaria
        int pk = std::stoi(columns[0]);

        if (pk == updatedData.pk) {
            // Actualizar los valores de la fila encontrada
            std::ostringstream oss;
            oss << updatedData.pk << ","
                << updatedData.fk << ","
                << updatedData.nombre << ","
                << updatedData.apellido << ","
                << updatedData.tipoIdentificacion << ","
                << updatedData.numIdentificacion << ","
                << updatedData.sexo << ","
                << updatedData.telefonoCelular << ","
                << updatedData.telefonoFijo << ","
                << updatedData.email << ","
                << updatedData.ciudadNacimiento << ","
                << updatedData.paisNacimiento << ","
                << updatedData.ciudadResidencia << ","
                << updatedData.direccion << ","
                << updatedData.tieneHijos << ","
                << updatedData.actividadLaboral << ","
                << updatedData.sucursalTrabajo << ","
                << updatedData.barrio << ","
                << updatedData.numHijos << ","
                << updatedData.fechaNacimiento << ","
                << updatedData.estado;
            row = oss.str();
            found = true;
            break;
        }
    }

    // Si no se encontró la clave primaria, imprimir un mensaje y salir
    if (!found) {
        std::cerr << "Primary key not found!" << std::endl;
        return;
    }

    // Abrir el archivo CSV para escritura
    std::ofstream outputFile(filename);

    // Escribir todas las líneas (modificadas y no modificadas) en el archivo
    for (const std::string &row : lines) {
        outputFile << row << "\n";
    }

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "CSV file updated successfully!" << std::endl;
}

/**
 * @brief Modifica los datos de una sucursal en el archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param updatedData Datos actualizados de la sucursal.
 */
void ControlDAO::ModificarSucursalDAO(const std::string &filename, const Sucursal &updatedData) {
    // Abrir el archivo CSV existente para lectura y escritura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Leer todas las líneas del archivo CSV
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Cerrar el archivo de entrada
    inputFile.close();

    // Buscar y modificar la fila que coincide con la clave primaria
    bool found = false;
    for (std::string &row : lines) {
        std::istringstream iss(row);
        std::vector<std::string> columns;

        while (getline(iss, line, ',')) {
            columns.push_back(line);
        }

        // Convertir la primera columna a entero para comparar con la clave primaria
        int pk = std::stoi(columns[0]);

        if (pk == updatedData.pk) {
            // Actualizar los valores de la fila encontrada
            std::ostringstream oss;
            oss << updatedData.pk << ","
                << updatedData.fk << ","
                << updatedData.nombre << ","
                << updatedData.direccion << ","
                << updatedData.barrio << ","
                << updatedData.nombreGerente << ","
                << updatedData.estado;
            row = oss.str();
            found = true;
            break;
        }
    }

    // Si no se encontró la clave primaria, imprimir un mensaje y salir
    if (!found) {
        std::cerr << "Primary key not found!" << std::endl;
        return;
    }

    // Abrir el archivo CSV para escritura
    std::ofstream outputFile(filename);

    // Escribir todas las líneas (modificadas y no modificadas) en el archivo
    for (const std::string &row : lines) {
        outputFile << row << "\n";
    }

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "CSV file updated successfully!" << std::endl;
}

/**
 * @brief Modifica los datos de una ciudad en el archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param updatedData Datos actualizados de la ciudad.
 */
void ControlDAO::ModificarCiudadDAO(const std::string &filename, const Ciudad &updatedData) {
    // Abrir el archivo CSV existente para lectura y escritura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error abriendo el archivo para lectura!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Leer todas las líneas del archivo CSV
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Cerrar el archivo de entrada
    inputFile.close();

    // Buscar y modificar la fila que coincide con la clave primaria
    bool found = false;
    for (std::string &row : lines) {
        std::istringstream iss(row);
        std::vector<std::string> columns;

        while (getline(iss, line, ',')) {
            columns.push_back(line);
        }

        // Convertir la primera columna a entero para comparar con la clave primaria
        int pk = std::stoi(columns[0]);

        if (pk == updatedData.pk) {
            // Actualizar los valores de la fila encontrada
            std::ostringstream oss;
            oss << updatedData.pk << ","
                << updatedData.fk << ","
                << updatedData.nombre << ","
                << updatedData.estado;
            row = oss.str();
            found = true;
            break;
        }
    }

    // Si no se encontró la clave primaria, imprimir un mensaje y salir
    if (!found) {
        std::cerr << "Clave primaria no encontrada!" << std::endl;
        return;
    }

    // Abrir el archivo CSV para escritura
    std::ofstream outputFile(filename);

    // Escribir todas las líneas (modificadas y no modificadas) en el archivo
    for (const std::string &row : lines) {
        outputFile << row << "\n";
    }

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "Archivo CSV actualizado exitosamente!" << std::endl;
}

/**
 * @brief Modifica los datos de un país en el archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param updatedData Datos actualizados del país.
 */
void ControlDAO::ModificarPaisDAO(const std::string &filename, const Pais &updatedData) {
    // Abrir el archivo CSV existente para lectura y escritura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    // Leer todas las líneas del archivo CSV
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Cerrar el archivo de entrada
    inputFile.close();

    // Buscar y modificar la fila que coincide con la clave primaria
    bool found = false;
    for (std::string &row : lines) {
        std::istringstream iss(row);
        std::vector<std::string> columns;

        while (getline(iss, line, ',')) {
            columns.push_back(line);
        }

        // Convertir la primera columna a entero para comparar con la clave primaria
        int pk = std::stoi(columns[0]);

        if (pk == updatedData.pk) {
            // Actualizar los valores de la fila encontrada
            std::ostringstream oss;
            oss << updatedData.pk << ","
                << updatedData.nombre << ","
                << updatedData.estado;
            row = oss.str();
            found = true;
            break;
        }
    }

    // Si no se encontró la clave primaria, imprimir un mensaje y salir
    if (!found) {
        std::cerr << "Primary key not found!" << std::endl;
        return;
    }

    // Abrir el archivo CSV para escritura
    std::ofstream outputFile(filename);

    // Escribir todas las líneas (modificadas y no modificadas) en el archivo
    for (const std::string &row : lines) {
        outputFile << row << "\n";
    }

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "CSV file updated successfully!" << std::endl;
}

/**
 * @brief Agrega un nuevo hijo al final del archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param newData Datos del nuevo hijo a agregar.
 */
void ControlDAO::AgregarHijoDAO(const std::string &filename, const Hijo &newData) {
    // Abrir el archivo CSV existente para escritura en modo append
    std::ofstream outputFile(filename, std::ios::app);

    // Verificar si el archivo se abrió correctamente
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Escribir la nueva fila al final del archivo
    outputFile << newData.pk << ","
               << newData.fk << ","
               << newData.nombre << ","
               << newData.fechaNacimiento << "\n";

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "New child added to CSV file successfully!" << std::endl;
}

/**
 * @brief Agrega un nuevo empleado al final del archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param newData Datos del nuevo empleado a agregar.
 */
void ControlDAO::AgregarEmpleadoDAO(const std::string &filename, const Empleado &newData) {
    // Abrir el archivo CSV existente para escritura en modo append
    std::ofstream outputFile(filename, std::ios::app);

    // Verificar si el archivo se abrió correctamente
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Escribir la nueva fila al final del archivo
    outputFile << newData.pk << ","
               << newData.fk << ","
               << newData.nombre << ","
               << newData.apellido << ","
               << newData.tipoIdentificacion << ","
               << newData.numIdentificacion << ","
               << newData.sexo << ","
               << newData.telefonoCelular << ","
               << newData.telefonoFijo << ","
               << newData.email << ","
               << newData.ciudadNacimiento << ","
               << newData.paisNacimiento << ","
               << newData.ciudadResidencia << ","
               << newData.direccion << ","
               << newData.tieneHijos << ","
               << newData.actividadLaboral << ","
               << newData.sucursalTrabajo << ","
               << newData.barrio << ","
               << newData.numHijos << ","
               << newData.fechaNacimiento << ","
               << newData.estado << "\n";

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "New employee added to CSV file successfully!" << std::endl;
}

/**
 * @brief Agrega datos de una sucursal al final del archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param newData Datos de la nueva sucursal a agregar.
 */
void ControlDAO::AgregarSucursalDAO(const std::string &filename, const Sucursal &newData) {
    // Abrir el archivo CSV existente para lectura y escritura
    std::fstream file(filename, std::ios::in | std::ios::out | std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error opening file for reading and writing!" << std::endl;
        return;
    }

    // Construir una cadena con los datos de la nueva sucursal
    std::ostringstream oss;
    oss << newData.pk << ","
        << newData.fk << ","
        << newData.nombre << ","
        << newData.direccion << ","
        << newData.barrio << ","
        << newData.nombreGerente << ","
        << newData.estado;

    // Escribir la cadena al final del archivo
    file << oss.str() << "\n";

    // Cerrar el archivo
    file.close();

    std::cout << "Sucursal added to CSV file successfully!" << std::endl;
}

/**
 * @brief Agrega una nueva ciudad al final del archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param newData Datos de la nueva ciudad a agregar.
 */
void ControlDAO::AgregarCiudadDAO(const std::string &filename, const Ciudad &newData) {
    // Abrir el archivo CSV existente para escritura en modo append
    std::ofstream outputFile(filename, std::ios::app);

    // Verificar si el archivo se abrió correctamente
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Escribir la nueva fila al final del archivo
    outputFile << newData.pk << ","
               << newData.fk << ","
               << newData.nombre << ","
               << newData.estado << "\n";

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "New city added to CSV file successfully!" << std::endl;
}

/**
 * @brief Agrega un nuevo país al final del archivo CSV.
 *
 * @param filename Nombre del archivo CSV.
 * @param newData Datos del nuevo país a agregar.
 */
void ControlDAO::AgregarPaisDAO(const std::string &filename, const Pais &newData) {
    // Abrir el archivo CSV existente para escritura en modo append
    std::ofstream outputFile(filename, std::ios::app);

    // Verificar si el archivo se abrió correctamente
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }

    // Escribir la nueva fila al final del archivo
    outputFile << newData.pk << ","
               << newData.nombre << ","
               << newData.estado << "\n";

    // Cerrar el archivo de salida
    outputFile.close();

    std::cout << "New country added to CSV file successfully!" << std::endl;
}