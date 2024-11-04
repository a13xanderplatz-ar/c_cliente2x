#include "c_Cliente.hpp"
#include <iostream>
#include <cstring>

c_Cliente::c_Cliente() {
    tamano = 0;
    capacidad = 1;
    
    nombres = new char*[capacidad];
    apellidos = new char*[capacidad];
    dni = new char*[capacidad];
    telefono = new char*[capacidad];
    montoCompra = new float[capacidad];
    
    for(int i = 0; i < capacidad; i++) {
        nombres[i] = nullptr;
        apellidos[i] = nullptr;
        dni[i] = nullptr;
        telefono[i] = nullptr;
        montoCompra[i] = 0.0f;
    }
}

c_Cliente::~c_Cliente() {
    for(int i = 0; i < tamano; i++) {
        delete[] nombres[i];
        delete[] apellidos[i];
        delete[] dni[i];
        delete[] telefono[i];
    }
    delete[] nombres;
    delete[] apellidos;
    delete[] dni;
    delete[] telefono;
    delete[] montoCompra;
}

void c_Cliente::redimensionar() {
    capacidad = capacidad + 1;
    
    char** nuevos_nombres = new char*[capacidad];
    char** nuevos_apellidos = new char*[capacidad];
    char** nuevos_dni = new char*[capacidad];
    char** nuevos_telefono = new char*[capacidad];
    float* nuevos_montos = new float[capacidad];
    
    for(int i = 0; i < tamano; i++) {
        nuevos_nombres[i] = nombres[i];
        nuevos_apellidos[i] = apellidos[i];
        nuevos_dni[i] = dni[i];
        nuevos_telefono[i] = telefono[i];
        nuevos_montos[i] = montoCompra[i];
    }
    
    delete[] nombres;
    delete[] apellidos;
    delete[] dni;
    delete[] telefono;
    delete[] montoCompra;
    
    nombres = nuevos_nombres;
    apellidos = nuevos_apellidos;
    dni = nuevos_dni;
    telefono = nuevos_telefono;
    montoCompra = nuevos_montos;
}

void c_Cliente::ingresarCliente() {
    if(tamano >= capacidad) {
        redimensionar();
    }
    
    char temp[100];
    std::cout << "\n=== Ingreso de Nuevo Cliente ===" << std::endl;
    
    std::cin.ignore();
    std::cout << "Ingrese nombres: ";
    std::cin.getline(temp, 100);
    nombres[tamano] = new char[strlen(temp) + 1];
    strcpy(nombres[tamano], temp);
    
    std::cout << "Ingrese apellidos: ";
    std::cin.getline(temp, 100);
    apellidos[tamano] = new char[strlen(temp) + 1];
    strcpy(apellidos[tamano], temp);
    
    std::cout << "Ingrese DNI: ";
    std::cin.getline(temp, 100);
    dni[tamano] = new char[strlen(temp) + 1];
    strcpy(dni[tamano], temp);
    
    std::cout << "Ingrese telefono: ";
    std::cin.getline(temp, 100);
    telefono[tamano] = new char[strlen(temp) + 1];
    strcpy(telefono[tamano], temp);
    
    std::cout << "Ingrese monto de compra: S/. ";
    std::cin >> montoCompra[tamano];
    
    tamano++;
    std::cout << "\nCliente registrado exitosamente!" << std::endl;
}

void c_Cliente::mostrarCliente(int index) const {
    if(index >= 0 && index < tamano) {
        std::cout << "\n=== Datos del Cliente ===" << std::endl;
        std::cout << "Nombres: " << nombres[index] << std::endl;
        std::cout << "Apellidos: " << apellidos[index] << std::endl;
        std::cout << "DNI: " << dni[index] << std::endl;
        std::cout << "Telefono: " << telefono[index] << std::endl;
        std::cout << "Monto de compra: S/. " << montoCompra[index] << std::endl;
        std::cout << "=========================" << std::endl;
    } else {
        std::cout << "indice de cliente inválido." << std::endl;
    }
}

void c_Cliente::mostrarTodos() const {
    if(tamano == 0) {
        std::cout << "\nNo hay clientes registrados." << std::endl;
        return;
    }
    
    std::cout << "\n=== Lista de Todos los Clientes ===" << std::endl;
    for(int i = 0; i < tamano; i++) {
        std::cout << "\nCliente #" << (i + 1) << std::endl;
        mostrarCliente(i);
    }
}
