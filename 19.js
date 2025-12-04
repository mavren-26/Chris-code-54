class DoubleHashSet {
  static EMPTY = 0;
  static OCC = 1;
  static DEL = 2;

  constructor(m) {
    this.m = m;
    this.keys = new Array(m).fill(null);
    this.state = new Array(m).fill(DoubleHashSet.EMPTY);
    this.distinct = 0;
  }

  h1(k) {
    let v = k % this.m;
    if (v < 0) v += this.m;
    return v;
  }

  h2(k) {
    return 1 + (Math.abs(k) % (this.m - 1));
  }

  search(k) {
    const a = this.h1(k), b = this.h2(k);
    for (let i = 0; i < this.m; i++) {
      const idx = (a + i * b) % this.m;
      if (this.state[idx] === DoubleHashSet.EMPTY) return false;
      if (this.state[idx] === DoubleHashSet.OCC && this.keys[idx] === k) return true;
    }
    return false;
  }

  insert(k) {
    if (this.search(k)) return;

    const a = this.h1(k), b = this.h2(k);
    let firstDel = -1;

    for (let i = 0; i < this.m; i++) {
      const idx = (a + i * b) % this.m;

      if (this.state[idx] === DoubleHashSet.EMPTY) {
        const pos = firstDel !== -1 ? firstDel : idx;
        this.keys[pos] = k;
        this.state[pos] = DoubleHashSet.OCC;
        this.distinct++;
        return;
      }
      if (this.state[idx] === DoubleHashSet.DEL && firstDel === -1) {
        firstDel = idx;
      }
    }

    if (firstDel !== -1) {
      this.keys[firstDel] = k;
      this.state[firstDel] = DoubleHashSet.OCC;
      this.distinct++;
    }
  }
}

// Driver
const fs = require("fs");
const data = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let idx = 0;

const m = parseInt(data[idx++]);
const q = parseInt(data[idx++]);

const s = new DoubleHashSet(m);

for (let i = 0; i < q; i++) {
  const x = parseInt(data[idx++]);
  s.insert(x);
  console.log(s.distinct);
}
