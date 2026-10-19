#include "dag.h"

std::vector<std::vector<Edge>> buildDAG(const std::vector<client> &clients)
{
    int n = clients.size();
    int START = 0;
    int END = n + 1;
    // adjacency list for the DAG
    std::vector<std::vector<Edge>> adj(n + 2);
    // start edges
    std::vector<int> inDegree(n + 2, 0);
    // end edges
    std::vector<int> outDegree(n + 2, 0);

    // checks if client j can rent right after client i
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            // if client i finishes before client j starts, add an edge from i to j
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
        // check if client i has no incoming edges, add an edge from START to i
        if (inDegree[i] == 0)
        {
            adj[START].push_back({i, 0});
        }
        // check if client i has no outgoing edges, add an edge from i to END
        if (outDegree[i] == 0)
        {
            adj[i].push_back({END, clients[i - 1].rev});
        }
    }
    return adj;
}
