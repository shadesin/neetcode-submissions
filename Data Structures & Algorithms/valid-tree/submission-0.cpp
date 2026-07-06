class Solution {
public:
    void dfs(vector<vector<int>> &adjlist, unordered_map<int ,bool> &visited, int node)
    {
        if(visited[node])
        {
            return;
        }
        visited[node] = true;

        for(auto x : adjlist[node])
        {
            if(!visited[x])
            {
                dfs(adjlist, visited, x);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // validTree if graph is connected and number of edges = number of nodes - 1

        if(edges.size() != n - 1)
        {
            return false;
        }

        unordered_map<int, bool> visited;

        vector<vector<int>>adjlist(n, vector<int>());

        for(auto x : edges)
        {
            int a = x[0];
            int b = x[1];

            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        

        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adjlist, visited, i);
                c++;
                if(c > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
