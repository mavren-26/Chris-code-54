// double_hash_table.js
class DoubleHashTable {
  static EMPTY = 0;
  static OCC = 1;
  static DEL = 2;

  constructor(m) {
    this.m = m;
    this.keys = new Array(m).fill(null);
    this.state = new Array(m).fill(DoubleHashTable.EMPTY);
  }

  h1(k){ let v = k % this.m; if (v < 0) v += this.m; return v; }
  h2(k){ return 1 + (Math.abs(k) % (this.m - 1)); }

  search(k){
    const a = this.h1(k), b = this.h2(k);
    for(let i=0;i<this.m;i++){
      const idx = (a + i*b) % this.m;
      if (this.state[idx] === DoubleHashTable.EMPTY) return false;
      if (this.state[idx] === DoubleHashTable.OCC && this.keys[idx] === k) return true;
    }
    return false;
  }

  insert(k){
    if (this.search(k)) return;
    const a = this.h1(k), b = this.h2(k);
    let firstDel = -1;
    for(let i=0;i<this.m;i++){
      const idx = (a + i*b) % this.m;
      if (this.state[idx] === DoubleHashTable.EMPTY) {
        const put = firstDel !== -1 ? firstDel : idx;
        this.keys[put] = k; this.state[put] = DoubleHashTable.OCC; return;
      }
      if (this.state[idx] === DoubleHashTable.DEL && firstDel === -1) firstDel = idx;
    }
    if (firstDel !== -1) { this.keys[firstDel] = k; this.state[firstDel] = DoubleHashTable.OCC; }
  }

  delete(k){
    const a = this.h1(k), b = this.h2(k);
    for(let i=0;i<this.m;i++){
      const idx = (a + i*b) % this.m;
      if (this.state[idx] === DoubleHashTable.EMPTY) return;
      if (this.state[idx] === DoubleHashTable.OCC && this.keys[idx] === k) {
        this.state[idx] = DoubleHashTable.DEL; this.keys[idx] = null; return;
      }
    }
  }

  dump(){
    return this.state.map((s,i) => s===DoubleHashTable.OCC ? String(this.keys[i]) : "EMPTY").join(" ");
  }
}

// Example driver for Problem 1 reading from stdin:
if (require.main === module) {
  const fs = require('fs');
  const data = fs.readFileSync(0,'utf8').trim().split(/\s+/);
  if (!data.length) process.exit(0);
  let idx = 0;
  const m = parseInt(data[idx++],10), n = parseInt(data[idx++],10);
  const ht = new DoubleHashTable(m);
  for (let i=0;i<n;i++){
    const cmd = data[idx++];
    if (cmd === "INSERT") { ht.insert(parseInt(data[idx++],10)); }
    else if (cmd === "DELETE") { ht.delete(parseInt(data[idx++],10)); }
    else if (cmd === "SEARCH") { console.log(ht.search(parseInt(data[idx++],10)) ? "YES" : "NO"); }
    else if (cmd === "PRINT") { console.log(ht.dump()); }
  }
}
