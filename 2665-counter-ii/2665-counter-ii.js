/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let temp = init;
    return new Proxy({}, {
        get: (target, key) => {
            switch(key) {
                case "increment":
                    return () => ++temp;
                case "decrement":
                    return () => --temp;
                case "reset":
                    return () => (temp = init);
                default:
                    throw Error("Wrong Method")
            }
        },
    });
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */