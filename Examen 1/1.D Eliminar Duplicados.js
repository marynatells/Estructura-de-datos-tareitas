function eliminarDuplicados() {
    const arrayOriginal = [1, 2, 3, 2, 4, 5, 1, 6, 7, 5];
    
    console.log("Array original:", arrayOriginal);
    

    const arraySinDuplicados = [...new Set(arrayOriginal)];
    console.log("Array sin duplicados:", arraySinDuplicados);
    return arraySinDuplicados;
}

console.log("\n---1D. Eliminar duplicados.---");
eliminarDuplicados();
