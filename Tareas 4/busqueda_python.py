def busquedalineal(arr, num):

    for i in range(len(arr)):
        if arr[i] == num:
            return i
    return -1

arreglo = [2, 4, 6, 8, 10]
num = 8

resultado = busquedalineal(arreglo, num)

if resultado != -1:
    print(f"El elemento {num} fue encontrado en el indice {resultado}")
else:
    print(f"El elemento {num} no fue encontrado")