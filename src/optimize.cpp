#include "optimize.h"
#include <vector>

// find the optimal revenue for the given DAG and topological order
OptimizationResult optimize(const std::vector<std::vector<Edge>> &adj, const std::vector<int> &topoOrder)
{
    int vertexCount = adj.size();
    int START = 0;
    int END = vertexCount - 1;
    // f[v] stores the maximum revenue achievable starting from vertex v
    std::vector<int> f(vertexCount, 0);
    // op[v] stores the next vertex in the optimal path starting from vertex v
    std::vector<int> op(vertexCount, -1);

    // process vertices in reverse topological order to compute f[v] and op[v]
    for (int k = vertexCount - 1; k >= 0; --k)
    {
        int v = topoOrder[k];
        // skip the END vertex as it has no outgoing edges
        if (v == END)
        {
            continue;
        }
        // try the next best, keep the one that makes the most money
        int best = -1;
        for (const Edge &edge : adj[v])
        {
            int candidate = edge.weight + f[edge.to];
            if (candidate > best)
            {
                best = candidate;
                op[v] = edge.to;
            }
        }
        f[v] = best;
    }
    // reconstruct the optimal path from START to END using the op array
    std::vector<int> clients;
    int vert = op[START];
    while (vert != END)
    {
        clients.push_back(vert);
        vert = op[vert];
    }
    return OptimizationResult{f[START], clients};
}