class Solution {
    bool isBipartite(int n, vector<vector<int>>& graph) {
        vector<int> color(n+1 ,-1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it:graph[node]){
                        if(color[it]==-1){
                            color[it]=!color[node];
                            q.push(it);
                        }
                        else if(color[it]==color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
    int depthofbfs(int src, int n, vector<vector<int>>& adj){
        vector<int> vis(n+1, 0);
        int level =0;
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            level++;
            int sz= q.size();
            for(int j=0; j<sz; j++){
                int node = q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
        return level;
    }
    int maxcompdist(int n, vector<vector<int>>& adj, vector<int>& nodes){
        int maxdepth = INT_MIN;
        for(auto src:nodes){
            maxdepth = max(maxdepth, depthofbfs(src, n, adj));
        }
        return maxdepth;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool bipartite = isBipartite(n, adj);
        if(!bipartite) return -1;
        vector<int> vis(n+1, 0);
        vector<vector<int>> components;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                vector<int> nodes;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    nodes.push_back(node);
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                components.push_back(nodes);
            }
        }

        int sum = 0;
        for(int i=0; i<components.size(); i++){
            sum+=maxcompdist(n, adj, components[i]);
        }
        return sum;



    }
};