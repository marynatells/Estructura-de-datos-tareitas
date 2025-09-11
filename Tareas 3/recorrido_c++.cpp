#include <iostream>
#include <vector>

int main() {
    std::vector<int> arreglo = {2, 4, 6, 8};

    for (int i = 0; i < arreglo.size(); ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}