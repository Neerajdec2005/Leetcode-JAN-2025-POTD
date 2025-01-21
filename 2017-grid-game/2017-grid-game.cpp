class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long x=0;
        for(int i=0;i<n;i++) x+=grid[0][i];
        long long cnt=LLONG_MAX;
        long long s=0;
        for(int i=0;i<n;i++){
            x-=grid[0][i];
            if(i>0) s+=grid[1][i-1];
            cnt=min(cnt,max(x,s));
        }
        return cnt;

    }
};