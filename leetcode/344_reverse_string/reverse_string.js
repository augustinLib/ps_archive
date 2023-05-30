/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function(s) {
    s = s.reverse()
};

/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString2 = function(s) {
    var left = 0;
    var right = s.length-1;

    while (left < right) {
        var temp = s[left]
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
};