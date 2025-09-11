using System;

class buscar
{
    static int busquedalineal(int[] arr, int num)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] == num)
            {
                return i;
            }
        }
        return -1;
    }
    
    static void Main()
    {
        int[] arreglo = { 2, 4, 6, 8, 10};
        int num = 8;
        int resultado = BusquedaLineal(arreglo, num);
        if (resultado != -1)
        {
            Console.WriteLine($"El elemento {num} fue encontrado en el indice {resultado} del array");
        }
        else
        {
            Console.WriteLine($"El elemento {num} no fue encontrado");
        }
    }
}