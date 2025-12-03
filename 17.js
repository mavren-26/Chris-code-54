class StringHashTable {
    constructor(size = 10) {
        this.size = size;
        this.table = Array.from({ length: size }, () => []);
    }

    hash(str) {
        let sum = 0;
        for (let c of str) sum += c.charCodeAt(0);
        return sum % this.size;
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

    getChain(key) {
        return this.table[this.hash(key)];
    }
}
