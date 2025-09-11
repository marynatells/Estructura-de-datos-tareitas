function busquedalineal(arr, num) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === num) {
            return i;
        }
    }
    return -1;
}

const arreglo = [2, 4, 6, 8, 10];
const num = 8;

const resultado = busquedalineal(arreglo, num);

if (resultado !== -1) {
    console.log(`El elemento ${num} fue encontrado en el indice ${resultado}`);
} else {
    console.log(`El elemento ${num} no fue encontrado`);
}
