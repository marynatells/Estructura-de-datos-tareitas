#include <iostream>
#include <vector>
using namespace std;

int busquedalineal(const vector<int>& arr, int num) {

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arreglo = {2, 4, 6, 8 ,10};
    int num = 8;
    
    int resultado = busquedalineal(arreglo, num);
    
    if (resultado != -1) {
        cout << "El elemento " << num << " fue encontrado en el indice " << resultado << endl;
    } else {
        cout << "El elemento " << num << " no fue encontrado" << endl;
    }
    
    return 0;
}