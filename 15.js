function countCollisions(values, size) {
    const table = new Array(size).fill(null);
    let collisions = 0;

    for (let v of values) {
        let idx = v % size;
        while (table[idx] !== null) {
            collisions++;
            idx = (idx + 1) % size;
        }
        table[idx] = v;
    }
    return collisions;
}

console.log(countCollisions([12, 22, 32, 42], 10));
