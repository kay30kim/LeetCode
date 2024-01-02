/**
 * @param {string} val
 * @return {Object}
 */
/* 1) Function expression
var expect = function(val) {
    return {//function (){ // function(){} 이렇게 하면 안 됨
    toBe : (val2) => {
        if (val !== val2) throw new Error("Not Equal");
        return true;
    },
    notToBe: (val2) => {
        if (val === val2) throw new Error("Equal");
        return true;
    }
    // 잘못된 방법
    // function toBe(val2) {
    //     return val == val2;
    // }
    // function notToBe(val2) {
    //     return val != val2;
    // }
    };
};*/
// 2) ES6 Classes
class Expect {
    constructor(val) {
        this.val = val;
    }
    toBe(val2) {
        if (this.val !== val2)
            throw new Error("Not Equal");
        return true;
    }
    notToBe(val2) {
        if (this.val === val2)
            throw new Error("Equal");
        return true;
    }
}
function expect(val){
    return new Expect(val);
}


/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */