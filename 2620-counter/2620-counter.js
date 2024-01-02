/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let num = n;
    return () => n++;
    // return () => {n++} 이렇게 하면 null이 나온다.
    /* 이거는 가능
    return function() {
        return n++;
    }*/
}
/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */