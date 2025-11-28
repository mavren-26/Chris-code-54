function countProbes(arr, n) {
  let table = Array(n).fill(-1);
  let res = [];

  for (let key of arr) {
    let idx = key % n;
    let start = idx;
    let probes = 1;

    while (table[idx] !== -1) {
      idx = (idx + 1) % n;
      probes++;
      if (idx === start) break;
    }

    table[idx] = key;
    res.push(probes);
  }
  return res;
}

console.log(countProbes([10, 20, 30, 25, 35], 10));
