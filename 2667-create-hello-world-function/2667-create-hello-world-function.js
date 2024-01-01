/**
 * @return {Function}
 */
function createHelloWorld() {
    function f(){return "Hello World"}
    return f;
}

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */