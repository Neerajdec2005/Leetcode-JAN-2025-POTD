class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k=__builtin_popcount(num2);
        int x=0;
        for(int i=31;i>=0 && k;i--){
            if(num1&(1<<i)){
                k--;
                x+=(1<<i);
            }
        }
        for(int i=0;i<32 && k;i++){
            if((num1&(1<<i))==0){
                k--;
                x+=(1<<i);
            }
        }return x;
    }
};