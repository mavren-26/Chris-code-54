function countActive(arr) {
    return arr.filter(x => x === 1).length;
}

console.log(countActive([1, -1, 0, 1, 1, -1]));
