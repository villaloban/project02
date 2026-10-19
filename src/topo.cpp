#include "topo.h"
#include <queue>
std::vector<int> topologicalSort(const std::vector<std::vector<Edge>> &adj)
{
    int VertexCount = adj.size();
    std::vector<int> inDegree(VertexCount, 0);
    for (int v = 0; v < VertexCount; ++v)
    {
        for (const Edge &e : adj[v])
        {
            inDegree[e.to]++;
        }
    }
    std::queue<int> queue;
    for (int v = 0; v < VertexCount; ++v)
    {
        if (inDegree[v] == 0)
        {
            queue.push(v);
        }
    }
    std::vector<int> result;
    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop();
        result.push_back(v);
        for (const Edge &e : adj[v])
        {
            if (--inDegree[e.to] == 0)
            {
                queue.push(e.to);
            }
        }
    }
    return result;
}
