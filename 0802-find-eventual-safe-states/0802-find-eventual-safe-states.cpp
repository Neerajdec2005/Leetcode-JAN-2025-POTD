class Solution {
public:

    vector<bool> safe;

    bool check(vector<vector<int>>& graph, vector<int>& vis,int c){
        vis[c]=1;
        bool x=true;
        for(int m:graph[c]){
            if(vis[m]==0){
                x&=check(graph,vis,m);
            }else if(vis[m]==1){
                return safe[c]=false;
            }else if(vis[m]==2) x&= safe[m];
        }
        vis[c]=2;
        return safe[c]=x;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> vis(n);
        safe=vector<bool>(n,true);

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                check(graph,vis,i);
            }
        }
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};