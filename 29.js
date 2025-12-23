function permuteWithBlocked(nums, blocked) {
    const res = [];
    const free = [];
    const fixed = [...nums];

    for (let i = 0; i < nums.length; i++) {
        if (!blocked[i]) free.push(nums[i]);
    }

    free.sort((a, b) => a - b);
    const used = Array(free.length).fill(false);

    function backtrack(path) {
        if (path.length === free.length) {
            let idx = 0;
            const perm = [...fixed];
            for (let i = 0; i < nums.length; i++) {
                if (!blocked[i]) perm[i] = path[idx++];
            }
            res.push(perm);
            return;
        }

        for (let i = 0; i < free.length; i++) {
            if (used[i]) continue;
            if (i > 0 && free[i] === free[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            path.push(free[i]);
            backtrack(path);
            path.pop();
            used[i] = false;
        }
    }

    backtrack([]);
    return res;
}
