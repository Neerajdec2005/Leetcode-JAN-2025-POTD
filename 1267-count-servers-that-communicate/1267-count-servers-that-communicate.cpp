class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            int x=0;
            for(int j=0;j<n;j++) x+=grid[i][j];
            if(x>1){
                cnt+=x;
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1)
                    grid[i][j]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]>0){
                    if(grid[j][i]==1) y++;
                    x++;
                }
            }if(x>1) cnt+=y;
        }
        return cnt;

    }
};