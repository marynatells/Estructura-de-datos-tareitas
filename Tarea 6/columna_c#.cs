using System;

class columna {
    static void RecorrerPorColumnas(int[,] matriz) {
        if (matriz == null || matriz.Length == 0) {
            Console.WriteLine("La matriz está vacía");
            return;
        }
        
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);
        
        Console.WriteLine("Recorrido por columnas:");
        for (int j = 0; j < columnas; j++) {     
            for (int i = 0; i < filas; i++) {    
                Console.WriteLine($"Columna {j}, Fila {i}: {matriz[i, j]}");
            }
            Console.WriteLine(); 
        }
    }
    
    static void Main() {
        int[,] matrizRectangular = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        
        RecorrerPorColumnas(matrizRectangular);
    }
}