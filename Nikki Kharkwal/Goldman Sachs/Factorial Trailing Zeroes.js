/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let flag = 0;
  //Just need to keep the track of number of 5.
    for (let i = 5; i <= n; i *= 5) {
        flag += Math.floor(n / i);
    }
    return flag;
};
