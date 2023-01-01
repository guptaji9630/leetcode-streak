// 980. Unique Paths III
class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int x, int y, int ex, int ey, int cnt, int &ans, vector<vector<int>> &vis)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1 || vis[x][y] == 1)
            return;
        if (x == ex && y == ey)
        {
            if (cnt == -1)
                ans++;
            return;
        }
        vis[x][y] = 1;
        dfs(grid, x + 1, y, ex, ey, cnt - 1, ans, vis);
        dfs(grid, x - 1, y, ex, ey, cnt - 1, ans, vis);
        dfs(grid, x, y + 1, ex, ey, cnt - 1, ans, vis);
        dfs(grid, x, y - 1, ex, ey, cnt - 1, ans, vis);
        vis[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int sx, sy, ex, ey;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] == 2)
                {
                    ex = i;
                    ey = j;
                }
                if (grid[i][j] == 0)
                    cnt++;
            }
        }
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(grid, sx, sy, ex, ey, cnt, ans, vis);
        return ans;
    }
};
