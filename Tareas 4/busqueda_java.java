public class {

    public static int busquedalineal(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arreglo = {2, 4, 6, 8, 10};
        int num = 8;
        
        int resultado = busquedaLineal(arreglo, num);
        
        if (resultado != -1) {
            System.out.println("El elemento " + num + " fue encontrado en el indice " + resultado);
        } else {
            System.out.println("El elemento " + num + " no fue encontrado");
        }
    }
}
