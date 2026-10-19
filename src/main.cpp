
#include "client.h"
#include "io.h"
#include "dag.h"
#include <iostream>
#include "topo.h"
#include "optimize.h"
int main()
{
    // prompt the user to enter the input file name
    std::cout << "Enter the file to read data: ";
    std::string filename;
    std::cin >> filename;

    // read the clients from the input file
    std::vector<client> clients = readClients(filename);
    if (clients.empty())
    {
        std::cerr << "No clients found in the file.\n";
        return 1;
    }

    // build the DAG from the clients
    std::vector<std::vector<Edge>> adj = buildDAG(clients);
    // perform a topological sort on the DAG
    std::vector<int> order = topologicalSort(adj);
    // optimize the client selection based on the DAG and topological order
    OptimizationResult Result = optimize(adj, order);

    // print the results
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
    // write the results to the output file
    writeClients(filename, clients.size(), Result.revenue, Result.clients);

    return 0;
}