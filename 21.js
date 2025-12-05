function compact(arr) {
    return arr.filter(x => x !== -1);
}

console.log(compact([5, -1, 7, 9, -1, 3]));
