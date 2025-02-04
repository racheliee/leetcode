function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    const len: number = arr.length;

    for(let i = 0; i < len; ++i){
        arr[i] = fn(arr[i], i);
    }

    return arr;
};