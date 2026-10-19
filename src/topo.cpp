#include "topo.h"
#include <queue>
// use a queue based DCO topological sort algorithm
std::vector<int> topologicalSort(const std::vector<std::vector<Edge>> &adj)
{
    int VertexCount = adj.size();
    // compute the in-degree of each vertex
    std::vector<int> inDegree(VertexCount, 0);
    for (int v = 0; v < VertexCount; ++v)
    {
        for (const Edge &e : adj[v])
        {
            inDegree[e.to]++;
        }
    }
    // if they have no incoming edges, add them to the queue
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
        // update the queue with the next vertex to process
        int v = queue.front();
        queue.pop();
        result.push_back(v);
        // remove the incoming edges from the current vertex
        // if no neighbors are left with incoming edges, add them to the queue
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
