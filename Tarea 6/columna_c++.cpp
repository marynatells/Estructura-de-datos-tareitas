#include <iostream>
#include <vector>
using namespace std;

void recorrerporcolumnas(const vector<vector<int>>& matriz) {
    
    if (matriz.empty() || matriz[0].empty()) {
        cout << "La matriz está vacía" << endl;
        return;
    }
    
    int filas = matriz.size();
    int columnas = matriz[0].size();
    
    cout << "Recorrido por columnas:" << endl;
    for (int j = 0; j < columnas; j++) { 
        for (int i = 0; i < filas; i++) {  
            cout << "Columna " << j << ", Fila " << i << ": " 
                 << matriz[i][j] << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matriz = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    recorrer_por_columnas(matriz);
    return 0;
}