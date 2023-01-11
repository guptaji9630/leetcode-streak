// 1443. Minimum Time to Collect All Apples in a Tree
class Solution
{
public:
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &hasApple, int node)
    {
        visited[node] = true;
        int ans = 0;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int child = graph[node][i];
            if (!visited[child])
            {
                int temp = dfs(graph, visited, hasApple, child);
                if (temp > 0 || hasApple[child])
                {
                    ans += temp + 2;
                }
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> graph(n);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, hasApple, 0);
    }
};
