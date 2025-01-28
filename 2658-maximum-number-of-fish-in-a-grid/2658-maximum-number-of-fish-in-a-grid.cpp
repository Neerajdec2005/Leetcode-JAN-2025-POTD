class Solution {
public:
    int m,n;
    void rec(int i,int j,int& cnt,vector<vector<int>>& v){
        cnt+=v[i][j];
        if(v[i][j]==0) return;
        v[i][j]=0;
        if(i>0 && v[i-1][j]>0 && j>=0 && j<n) rec(i-1,j,cnt,v);
        if(j>0 && v[i][j-1]>0 && i>=0 && i<m) rec(i,j-1,cnt,v);
        if(j<n-1 && v[i][j+1] && i>=0 && i<m) rec(i,j+1,cnt,v);
        if(i<m-1 && v[i+1][j] && j>=0 && j<n) rec(i+1,j,cnt,v);
        else{
            return;
        }
    }


    int findMaxFish(vector<vector<int>>& v) {
        m=v.size();
        n=v[0].size();
        int cnt=0;
        int x=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rec(i,j,cnt,v);
                x=max(cnt,x);
                cnt=0;
            }
        }
        return x;
    }
};