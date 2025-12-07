// Falling Tombstones - JavaScript
const fs = require('fs');

function simulateFalling(s, T) {
  const n = s.length;
  const standing = Array.from(s).map(c => c === '1');
  const cnt = new Array(n).fill(0);
  for (let i = 0; i < n; ++i) {
    if (i-1 >= 0 && standing[i-1]) cnt[i]++;
    if (i+1 < n && standing[i+1]) cnt[i]++;
  }
  let q = [];
  for (let i = 0; i < n; ++i) {
    if (standing[i] && cnt[i] < T) q.push(i);
  }
  let days = 0;
  while (q.length > 0) {
    days++;
    const next = [];
    for (const i of q) {
      if (!standing[i]) continue;
      standing[i] = false;
      for (const nb of [i-1, i+1]) {
        if (nb >= 0 && nb < n && standing[nb]) {
          cnt[nb]--;
          if (cnt[nb] < T) next.push(nb);
        }
      }
    }
    q = next;
  }
  return [standing.map(x => x ? '1' : '0').join(''), days];
}

const input = fs.readFileSync(0,'utf8').trim().split(/\s+/);
if (input.length === 0) {
  const [final, days] = simulateFalling("1101101", 1);
  console.log(final);
  console.log(days);
} else {
  const s = input[0];
  const T = parseInt(input[1], 10);
  const [final, days] = simulateFalling(s, T);
  console.log(final);
  console.log(days);
}
