/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    
    let cache = {}
    return function(...args) {
        const key = JSON.stringify(args)
        if(typeof cache[key] !== "undefined"){
            return cache[key]
        }
        const value = fn(...args)
        cache[key] = value
        return value
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */