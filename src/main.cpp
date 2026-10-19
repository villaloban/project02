
#include "client.h"
#include "io.h"
#include "dag.h"
#include <iostream>
#include "topo.h"
#include "optimize.h"
int main()
{
    std::cout << "Enter the file to read data: ";
    std::string filename;
    std::cin >> filename;

    std::vector<client> clients = readClients(filename);
    if (clients.empty())
    {
        std::cerr << "No clients found in the file.\n";
        return 1;
    }

    std::vector<std::vector<Edge>> adj = buildDAG(clients);
    std::vector<int> order = topologicalSort(adj);
    OptimizationResult Result = optimize(adj, order);

    std::cout << "There are " << clients.size() << " clients in this file\n";
    std::cout << "Optimal revenue earned is " << Result.revenue << "\n";
    std::cout << "Clients contributing to this optimal revenue: ";
    for (size_t i = 0; i < Result.clients.size(); ++i)
    {
        std::cout << Result.clients[i];
        if (i < Result.clients.size() - 1)
            std::cout << ", ";
    }
    std::cout << "\n";
    writeClients(filename, clients.size(), Result.revenue, Result.clients);

    return 0;
}