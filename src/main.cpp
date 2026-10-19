
#include "client.h"
#include "io.h"
#include "dag.h"
#include <iostream>
#include "topo.h"
#include "optimize.h"
int main()
{
    writeClients("data/data2.txt", 3, 220, {1, 3});
    std::vector<client> clients = readClients("data/data2.txt");
    std::vector<std::vector<Edge>> adj = buildDAG(clients);
    // comment out for debugging the adjacency list
    for (size_t v = 0; v < adj.size(); ++v)
    {
        std::cout << v << ":";
        for (const Edge &e : adj[v])
            std::cout << " (" << e.to << "," << e.weight << ")";
        std::cout << "\n";
    }

    // comment out debugg for topo sorting
    std::cout << "Topological order: ";
    std::vector<int> order = topologicalSort(adj);
    for (int v : order)
        std::cout << v << " ";
    std::cout << "\n";

        return 0;
}