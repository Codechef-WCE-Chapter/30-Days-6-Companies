function combinationSum3(k: number, n: number): number[][] {
    const res: number[][] = [];
  function recurse(i = 0, c = 1, r: number[] = [], s = 0): void {
    if (i === k) {
      if (s === n) {
        res.push(r.slice());
      }
    }
    if (i >= k || c > 9) {
      return;
    }
    r.push(c);
    recurse(i + 1, c + 1, r, s + c);
    r.pop();
    recurse(i, c + 1, r, s);
  }
  recurse();
  return res;
};