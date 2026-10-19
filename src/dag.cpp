#include "dag.h"

std::vector<std::vector<Edge>> buildDAG(const std::vector<client> &clients)
{
    int n = clients.size();
    int START = 0;
    int END = n + 1;
    std::vector<std::vector<Edge>> adj(n + 2);
    std::vector<int> inDegree(n + 2, 0);
    std::vector<int> outDegree(n + 2, 0);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j && clients[i - 1].end <= clients[j - 1].start)
            {
                adj[i].push_back({j, clients[i - 1].rev});
                inDegree[j]++;
                outDegree[i]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (inDegree[i] == 0)
        {
            adj[START].push_back({i, 0});
        }
        if (outDegree[i] == 0)
        {
            adj[i].push_back({END, clients[i - 1].rev});
        }
    }
    return adj;
}
