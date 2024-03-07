/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    
    let ans = [];
    
    arr.forEach((item, index) => {
        let a = fn(item, index);
        ans.push(a);
    })
    return ans;
    
};