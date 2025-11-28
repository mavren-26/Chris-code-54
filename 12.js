class HashLP {
  constructor(n) {
    this.n = n;
    this.table = Array(n).fill(-1);
  }

  insert(key) {
    let idx = key % this.n;
    let start = idx;
    while (this.table[idx] !== -1 && this.table[idx] !== -2) {
      idx = (idx + 1) % this.n;
      if (idx === start) return;
    }
    this.table[idx] = key;
  }

  search(key) {
    let idx = key % this.n;
    let start = idx;
    while (this.table[idx] !== -1) {
      if (this.table[idx] === key) return idx;
      idx = (idx + 1) % this.n;
      if (idx === start) break;
    }
    return -1;
  }

  delete(key) {
    let pos = this.search(key);
    if (pos !== -1) this.table[pos] = -2;
  }
}
