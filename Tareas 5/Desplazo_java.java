import java.util.Arrays;
import java.util.ArrayList;

public class desplazo {
    
    public static ArrayList<Integer> insertarYDesplazar(ArrayList<Integer> arreglo, int indice, int valor) {
        if (indice < 0 || indice >= arreglo.size()) {
            throw new IllegalArgumentException("Índice fuera de rango");
        }
        
        ArrayList<Integer> resultado = new ArrayList<>();
        
        for (int i = 0; i < indice; i++) {
            resultado.add(arreglo.get(i));
        }
        
        resultado.add(valor);

        for (int i = indice; i < arreglo.size() - 1; i++) {
            resultado.add(arreglo.get(i));
        }
        
        return resultado;
    }
    
    public static void main(String[] args) {
        ArrayList<Integer> arreglo = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
        
        System.out.println("Arreglo original: " + arreglo);
        System.out.println("Inserta el 0 en el indice 0");
        
        try {
            ArrayList<Integer> resultado = insertarYDesplazar(arreglo, 0, 0);
            System.out.println("Resultado: " + resultado);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}