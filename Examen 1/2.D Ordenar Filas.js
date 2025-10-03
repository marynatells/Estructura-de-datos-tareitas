
function ordenarFilasMatriz() {
    const matriz = [
        [9, 3, 7],
        [1, 8, 4],
        [6, 2, 5]
    ];
    
    console.log("Matriz:\n");
    matriz.forEach(fila => console.log(fila));
    
    const matrizOrdenada = matriz.map(fila => [...fila].sort((a, b) => a - b));
    console.log("\nMatriz con filas ordenadas:");
    matrizOrdenada.forEach(fila => console.log(fila));
    return matrizOrdenada;
}

console.log("\n2D. Ordenar filas.");
ordenarFilasMatriz();