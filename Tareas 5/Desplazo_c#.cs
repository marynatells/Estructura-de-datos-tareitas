using System;
using System.Collections.Generic;
using System.Linq;

class desplazo
{
    static List<int> InsertarYDesplazar(List<int> arreglo, int indice, int valor)
    {
        if (indice < 0 || indice >= arreglo.Count)
        {
            throw new ArgumentOutOfRangeException("Índice fuera de rango");
        }
        
        List<int> resultado = new List<int>();
        
        resultado.AddRange(arreglo.Take(indice));
        resultado.Add(valor);
        resultado.AddRange(arreglo.Skip(indice).Take(arreglo.Count - indice - 1));
        
        return resultado;
    }
    
    static void Main()
    {
        List<int> arreglo = new List<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        Console.WriteLine("Arreglo original: " + string.Join(" ", arreglo));
        Console.WriteLine("Inserta el 0 en el indice 9");
        
        try
        {
            List<int> resultado = InsertarYDesplazar(arreglo, 9, 0);
            Console.WriteLine("Resultado: " + string.Join(" ", resultado));
        }
        catch (ArgumentOutOfRangeException e)
        {
            Console.WriteLine("Error: " + e.Message);
        }
    }
}