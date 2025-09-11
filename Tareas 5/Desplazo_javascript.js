function insertarYDesplazar(arreglo, indice, valor) {
    if (indice < 0 || indice >= arreglo.length) {
        throw new Error("Índice fuera de rango");
    }
    
    let resultado = arreglo.slice(0, indice);
    resultado.push(valor);
    resultado = resultado.concat(arreglo.slice(indice, arreglo.length - 1));
    
    return resultado;
}


const arreglo = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

console.log("Arreglo original:", arreglo);
console.log("Inserta el 45 en el indice 3");

try {
    const resultado = insertarYDesplazar(arreglo, 3, 45);
    console.log("Resultado:", resultado);
} catch (error) {
    console.log("Error:", error.message);
}
