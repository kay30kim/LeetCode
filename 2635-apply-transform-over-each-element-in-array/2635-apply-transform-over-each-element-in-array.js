/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    // 1) In-Memory
    // for (let i = 0; i <arr.length; i++)
    //     arr[i] = fn(arr[i], i);
    // return arr;
    // 2) Declare arrary
    // const newArr = new Array(arr.length);
    // for (const i in arr) {
    //     newArr[i] = fn(arr[i], Number(i)); // 그냥 i는 char
    // }
    // 3) Push
    const newArr = [];
    for (let i = 0; i <arr.length; i++) {
        newArr.push(fn(arr[i], i));
    }
    return newArr;
};