class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n);
        vector<long long> suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+nums[i];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]>=suf[i+1]) cnt++;
        }return cnt;
    }
};