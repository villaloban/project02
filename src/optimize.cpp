#include "optimize.h"
#include <vector>

OptimizationResult optimize(const std::vector<std::vector<Edge>> &adj, const std::vector<int> &topoOrder)
{
    int vertexCount = adj.size();
    int START = 0;
    int END = vertexCount - 1;
    std::vector<int> f(vertexCount, 0);
    std::vector<int> op(vertexCount, -1);

    for (int k = vertexCount - 1; k >= 0; --k)
    {
        int v = topoOrder[k];
        if (v == END)
        {
            continue;
        }
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
    std::vector<int> clients;
    int vert = op[START];
    while (vert != END)
    {
        clients.push_back(vert);
        vert = op[vert];
    }
    return OptimizationResult{f[START], clients};
}