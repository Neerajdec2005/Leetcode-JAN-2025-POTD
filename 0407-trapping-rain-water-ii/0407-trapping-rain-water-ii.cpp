class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int cnt=0;
        int m=h.size();
        int n=h[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > p;
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    p.push({h[i][j],{i,j}});
                    v[i][j]=1;
                }
            }
        }
        int mx=0;
        while(!p.empty()){
            int r=p.top().second.first;
            int c=p.top().second.second;
            int k=p.top().first;

            mx=max(mx,k);
            p.pop();
            int p1[4]={0,0,-1,1};
            int p2[4]={1,-1,0,0};

            for(int i=0;i<4;i++){
                int l1=r+p1[i];
                int l2=c+p2[i];
                if(l1>=0 && l1<m && l2>=0 && l2<n && v[l1][l2]==0){
                    p.push({h[l1][l2],{l1,l2}});
                    v[l1][l2]=1;
                    if(h[l1][l2]<mx) cnt+=(mx-h[l1][l2]);
                }
            }

        }
        return cnt;
    }
};