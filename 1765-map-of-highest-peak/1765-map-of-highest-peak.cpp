class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> x(m,vector<int>(n,n+m));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    x[i][j]=0;
                }else{
                    if(i>0) x[i][j]=min(x[i][j],x[i-1][j]+1);
                    if(j>0) x[i][j]=min(x[i][j],x[i][j-1]+1);
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i<m-1) x[i][j]=min(x[i][j],x[i+1][j]+1);
                if(j<n-1) x[i][j]=min(x[i][j],x[i][j+1]+1);
            }
        }
        return x;
    }
};