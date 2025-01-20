class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int cnt=INT_MAX;
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]]=i;
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<m;j++){
                x=max(x,mp[mat[i][j]]);
            }cnt=min(x,cnt);
        }
        for(int i=0;i<m;i++){
            int x=0;
            for(int j=0;j<n;j++){
                x=max(x,mp[mat[j][i]]);
            }cnt=min(cnt,x);
        }
        return cnt;
    }
};