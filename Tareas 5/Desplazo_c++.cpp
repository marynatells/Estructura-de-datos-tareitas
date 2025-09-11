#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<int> insertarYDesplazar(const std::vector<int>& arreglo, int indice, int valor) {
    if (indice < 0 || indice >= arreglo.size()) {
        throw std::out_of_range("Índice fuera de rango");
    }
    
    std::vector<int> resultado;
    
    for (int i = 0; i < indice; i++) {
        resultado.push_back(arreglo[i]);
    }
    
       resultado.push_back(valor);
    
       for (int i = indice; i < arreglo.size() - 1; i++) {
        resultado.push_back(arreglo[i]);
    }
    
    return resultado;
}

int main() {
    std::vector<int> arreglo = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Arreglo original: ";
    for (int num : arreglo) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Inserta el 0 en el indice 0" << std::endl;
    
    try {
        std::vector<int> resultado = insertarYDesplazar(arreglo, 0, 0);
        
        std::cout << "Resultado: ";
        for (int num : resultado) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
     std::cout << "increible";
    return 0;
}