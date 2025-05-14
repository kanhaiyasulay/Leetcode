/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) 
{
    let val = init;
    let initVal = init;
    return {
        increment : () =>
        {
            val += 1;
            return val;
        },
        decrement : () =>
        {
            val -= 1;
            return val;
        },
        reset : () =>
        {
            val = initVal;
            return val;
        }
    }    
};

/**
 * const counter = createCounter(5)
 * console.log(counter.increment()); // 6
 * console.log(counter.reset()); // 5
 * console.log(counter.decrement()); // 4
 */
