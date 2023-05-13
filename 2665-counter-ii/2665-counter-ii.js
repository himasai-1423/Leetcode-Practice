/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var temp = init;
    let increment = () => {
        return ++temp;
    }
    
    let decrement = () => {
        return --temp;
    }
    
    let reset = () => {
        return temp=init;
    }
    
    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */