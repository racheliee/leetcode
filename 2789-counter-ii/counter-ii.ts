type Counter = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): Counter {
    const initial = init;
    let ct = init;

    return {
        increment: () => {
            return ++ct;
        },
        decrement: () => {
            return --ct; // pre-increment is needed!!
        },
        reset: () => {
            ct = init;
            return ct;
        }

    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */