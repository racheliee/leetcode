/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    // type checking with null is basically asking if null and the value are the same
    return ret = {
        toBe: function (v) {
            if (v !== val) throw new Error('Not Equal'); // don't add return statement
            return true;
        },
        notToBe: function (v) {
            if(v === val) throw new Error('Equal');
            return true;
        }
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */