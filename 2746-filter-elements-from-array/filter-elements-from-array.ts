type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
    let ret: number[] = [];
    const len = arr.length;

    for(let i = 0; i < len; ++i) {
        if(fn(arr[i], i))
            ret.push(arr[i]);
    }

    return ret;
};