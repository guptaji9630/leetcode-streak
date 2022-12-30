// 797. All Paths From Source to Target
class Solution
{
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int> &path, vector<vector<int>> &ans)
    {
        if (node == graph.size() - 1)
        {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < graph[node].size(); i++)
        {
            path.push_back(graph[node][i]);
            dfs(graph, graph[node][i], path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, path, ans);
        return ans;
    }
};
