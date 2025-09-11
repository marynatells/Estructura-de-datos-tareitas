def recorrerporcolumnas(matriz):
    
    filas = len(matriz)
    columnas = len(matriz[0])
    
    print("Recorrido por columnas:")
    for j in range(columnas):     
        for i in range(filas):    
            print(f"Columna {j}, Fila {i}: {matriz[i][j]}")
        print() 

# Ejemplo de uso
matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

recorrer_por_columnas(matriz)