class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> m;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int k=0;
            int l=nums[i];
            while(nums[i]>0){
                k+=(nums[i]%10);
                nums[i]/=10;
            }
            m[k].push(l);
        }
        int cnt=-1;
        for(auto x:m){
            if(x.second.size()>=2){
                int k=x.second.top();
                x.second.pop();
                cnt=max(cnt,k+x.second.top());
            }
        }return cnt;
    }
};