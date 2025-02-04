function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    let ret: number[] = [];
    const len: number = arr.length;

    for(let i = 0; i < len; ++i){
        ret.push(fn(arr[i], i));
    }

    return ret;
};