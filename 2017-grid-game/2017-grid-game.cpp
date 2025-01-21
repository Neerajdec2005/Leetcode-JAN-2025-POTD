class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<long long> pre1(n+1);
        vector<long long> pre2(n+1);
        for(int i=1;i<=n;i++) pre1[i]=pre1[i-1]+grid[0][i-1];
        for(int i=1;i<=n;i++) pre2[i]=pre2[i-1]+grid[1][i-1];
        long long cnt=LLONG_MAX;
        for(int i=0;i<n;i++){
            cnt=min(cnt,max(pre1[n]-pre1[i+1],pre2[i]));
        }
        return cnt;

    }
};