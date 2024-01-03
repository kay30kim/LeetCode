/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let val = init;
    function increment() {
        return ++val;
    }
    function decrement() {
        return --val;
    }
    function reset() {
        val = init;
        return val;
    }
    return {increment, decrement, reset};
    /*
    const inital = init;
    return {
        increment: () => {
            val++;
            return val;
        },
        decrement : () => {
            val--;
            return val;
        },
        reset : () => {
            val = inital;
            return val;
        }
    }*/
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */