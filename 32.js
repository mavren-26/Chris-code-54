function minWindow(s, t) {
    const need = new Map();
    for (let ch of t) need.set(ch, (need.get(ch) || 0) + 1);

    let missing = t.length;
    let left = 0, start = 0, minLen = Infinity;

    for (let right = 0; right < s.length; right++) {
        const ch = s[right];
        if (need.get(ch) > 0) missing--;
        need.set(ch, (need.get(ch) || 0) - 1);

        while (missing === 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            const leftChar = s[left];
            need.set(leftChar, (need.get(leftChar) || 0) + 1);
            if (need.get(leftChar) > 0) missing++;
            left++;
        }
    }
    return minLen === Infinity ? "" : s.slice(start, start + minLen);
}
