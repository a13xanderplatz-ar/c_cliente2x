// c_Cliente.hpp
#ifndef C_CLIENTE_HPP
#define C_CLIENTE_HPP

#include <string>

class c_Cliente {
private:
    char** nombres;
    char** apellidos;
    char** dni;
    char** telefono;
    float* montoCompra;
    int tamano;
    int capacidad;

    void redimensionar();  // Método privado para redimensionar arrays

public:
    // Constructores y destructor
    c_Cliente();
    c_Cliente(int capacidad_inicial);
    ~c_Cliente();

    // Métodos principales
    void ingresarCliente();
    void mostrarCliente(int index) const;
    void mostrarTodos() const;
    int getTotalClientes() const { return tamano; }
};

#endif