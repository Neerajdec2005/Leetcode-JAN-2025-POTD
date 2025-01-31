class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void finding_islands(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, int &id, int &n)
    {
        if(i < 0 || j < 0 || i>=n || j >=n || grid[i][j] == 0)
        {
            return;
        }
        vis[i][j] = id;
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            finding_islands(grid, vis, x, y, id, n);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int id = 1;
        int res = 0;
        vector<vector<int>> grid_copy = grid;
        vector<vector<int>> vis(n, vector<int> (n, 0));

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    finding_islands(grid_copy, vis,i, j, id, n);
                    id++;
                }
            }
        }

        map<int, int> size_islands;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(vis[i][j])
                {
                    size_islands[vis[i][j]]++;
                }

            }
        }
        if(size_islands.size()==1 && size_islands[1] == n * n) return n * n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(grid[i][j] == 0)
                {
                    int cnt = 1;
                    set<int> s;
                    int up = 0,down = 0, right = 0, left = 0;

                    if(i - 1 >= 0) up = vis[i - 1][j];
                    if(j - 1 >= 0) left = vis[i][j - 1];
                    if(i + 1 < n) down = vis[i + 1][j];
                    if(j + 1 < n) right = vis[i][j + 1];


                    s.insert(up);
                    s.insert(down);
                    s.insert(left);
                    s.insert(right);

            
                    for (const int& val : s) 
                    {
                        if(val !=0 )cnt+=size_islands[val];
                    }
                    res = max(cnt, res);
                }
            }
        }

        return res;
    }
};