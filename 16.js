class HashTable {
    constructor(size = 10) {
        this.size = size;
        this.table = Array.from({ length: size }, () => []);
    }

    hash(key) {
        return key % this.size;
    }

    insert(key) {
        const idx = this.hash(key);
        if (!this.table[idx].includes(key)) {
            this.table[idx].push(key);
        }
    }

    search(key) {
        return this.table[this.hash(key)].includes(key);
    }

    remove(key) {
        const idx = this.hash(key);
        this.table[idx] = this.table[idx].filter(x => x !== key);
    }
}
