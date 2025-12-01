class LinearProbingHash {
    constructor(size) {
        this.size = size;
        this.table = new Array(size).fill(null);
        this.DELETED = "<DEL>";
    }

    insert(value) {
        let idx = value % this.size;
        const start = idx;

        while (this.table[idx] !== null && this.table[idx] !== this.DELETED) {
            if (this.table[idx] === value) return;
            idx = (idx + 1) % this.size;
            if (idx === start) return; // full
        }
        this.table[idx] = value;
    }

    search(value) {
        let idx = value % this.size;
        const start = idx;

        while (this.table[idx] !== null) {
            if (this.table[idx] === value) return idx;
            idx = (idx + 1) % this.size;
            if (idx === start) break;
        }
        return -1;
    }

    delete(value) {
        const idx = this.search(value);
        if (idx !== -1) this.table[idx] = this.DELETED;
    }
}

// Example
const h = new LinearProbingHash(10);
h.insert(10);
h.insert(20);
h.insert(17);
console.log(h.search(17));
h.delete(20);
console.log(h.search(20));
