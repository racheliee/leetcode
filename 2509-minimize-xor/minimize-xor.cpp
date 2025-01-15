class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bit_cnt = __builtin_popcount(num2);

        int res = 0;
        // add bits where num1 has bits set
        for(int i = 31; i >= 0 && bit_cnt; --i){
            if(num1 & (1 << i)){
                res += (1 << i);
                --bit_cnt;
            }
        }

        // add bits from lowest bit where num1 doesn't have a set bit
        for(int i = 0; i <= 31 && bit_cnt; ++i){
            if(!(num1 & (1 << i))){
                res += (1 << i);
                --bit_cnt;
            }
        }

        return res;
    }
};