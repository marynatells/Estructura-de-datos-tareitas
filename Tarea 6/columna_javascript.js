function recorrerporcolumnas(matriz) {
   
    if (!matriz || matriz.length === 0 || !matriz[0] || matriz[0].length === 0) {
        console.log("La matriz está vacía");
        return;
    }
    
    const filas = matriz.length;
    const columnas = matriz[0].length;
    
    console.log("Recorrido por columnas:");
    for (let j = 0; j < columnas; j++) { 
        for (let i = 0; i < filas; i++) { 
            console.log(`Columna ${j}, Fila ${i}: ${matriz[i][j]}`);
        }
        console.log();
    }
}

const matriz = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

recorrerPorColumnas(matriz);