#include <string>

class Persona {
private:
    std::string nombre;
    int edad;
    std::string direccion;

public:
    Persona(std::string nombre, int edad, std::string direccion) {
        this->nombre = nombre;
        this->edad = edad;
        this->direccion = direccion;
    }

    // Métodos getter y setter
    std::string getNombre() { return nombre; }
    void setNombre(std::string nombre) { this->nombre = nombre; }
    int getEdad() { return edad; }
    void setEdad(int edad) { this->edad = edad; }
    std::string getDireccion() { return direccion; }
    void setDireccion(std::string direccion) { this->direccion = direccion; }
};