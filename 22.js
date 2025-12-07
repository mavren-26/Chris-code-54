// Tombstone Skyline - JavaScript (Node.js)
const fs = require('fs');

function minRemovalsToMountain(h) {
  const n = h.length;
  if (n < 3) return -1;
  // LIS ending at i
  const L = new Array(n).fill(0);
  let tails = [];
  for (let i = 0; i < n; ++i) {
    let val = h[i];
    let pos = lowerBound(tails, val);
    if (pos === tails.length) tails.push(val);
    else tails[pos] = val;
    L[i] = pos + 1;
  }
  // LIS from right => R
  const R = new Array(n).fill(0);
  tails = [];
  for (let i = n-1; i >= 0; --i) {
    let val = h[i];
    let pos = lowerBound(tails, val);
    if (pos === tails.length) tails.push(val);
    else tails[pos] = val;
    R[i] = pos + 1;
  }

  let maxMountain = 0;
  for (let i = 0; i < n; ++i) {
    if (L[i] >= 2 && R[i] >= 2) {
      maxMountain = Math.max(maxMountain, L[i] + R[i] - 1);
    }
  }
  return maxMountain === 0 ? -1 : n - maxMountain;
}

function lowerBound(arr, x) {
  let l = 0, r = arr.length;
  while (l < r) {
    const m = Math.floor((l + r) / 2);
    if (arr[m] < x) l = m + 1;
    else r = m;
  }
  return l;
}

const input = fs.readFileSync(0, 'utf8').trim().split(/\s+/);
if (input.length === 0) {
  const example = [2,1,4,7,3,2,5];
  console.log(minRemovalsToMountain(example)); // 2
} else {
  let idx = 0;
  const n = parseInt(input[idx++], 10);
  const h = [];
  for (let i = 0; i < n; ++i) h.push(parseInt(input[idx++], 10));
  console.log(minRemovalsToMountain(h));
}
