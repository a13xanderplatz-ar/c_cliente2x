// Hello World program 
// ANSI Codes
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"//comando para limpiar pantlla
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>//ayuda en el desenpeño de la pantalla 
    #include <termios.h>
    #define CLEAR_COMMAND "clear"//comando para limpiar pantalla
#endif


#include "c_Cliente.hpp"
#include <iostream>

int main() {
    c_Cliente sistema;
    int opcion;
    
    do {
        std::cout << "\n=== MENU SISTEMA DE CLIENTES ===" << std::endl;
        std::cout << "1. Ingresar nuevo cliente" << std::endl;
        std::cout << "2. Mostrar todos los clientes" << std::endl;
        std::cout << "3. Mostrar cliente especifico" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1:
                sistema.ingresarCliente();
                break;
                
            case 2:
                sistema.mostrarTodos();
                break;
                
            case 3: {
                int index;
                std::cout << "Ingrese el numero de cliente (1-" << sistema.getTotalClientes() << "): ";
                std::cin >> index;
                sistema.mostrarCliente(index - 1);
                break;
            }
            
            case 4:
                std::cout << "¡Gracias por usar el sistema!" << std::endl;
                break;
                
            default:
                std::cout << "Opcion invalida. Por favor intente nuevamente." << std::endl;
        }
    } while(opcion != 4);
    
    return 0;
}