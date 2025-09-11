def insertarydesplazar(arreglo, indice, valor):

    if indice < 0 or indice >= len(arreglo):
        raise ValueError("Índice fuera de rango")
    
    return arreglo[:indice] + [valor] + arreglo[indice:-1]

# Uso
arreglo = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(arreglo)
print("Inserta el 33 en el indice 2")
resultado = insertar_y_desplazar(arreglo, 2, 33)
print(resultado)
print("Phyton lo hace")