/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s = s.replace(/[^A-Za-z0-9]/g, "").toLowerCase()
    var p = s.split("").reverse().join("")

    return s==p
};