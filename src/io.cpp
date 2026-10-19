#include "client.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// read clients from a file
// each line in the file contains three integers: start, end, and revenue
std::vector<client> readClients(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }
    // Read the file content here
    std::vector<client> clients;
    int start, end, rev;
    while (file >> start >> end >> rev)
    {
        // Process each line of the file here
        clients.push_back({start, end, rev});
    }

    file.close();
    return clients;
}

// write the results of the optimal client selection to a file
// inputName: the name of the input file
// count: the number of clients in the input file
// revenue: the optimal revenue earned
// clients: the list of client indices contributing to the optimal revenue
void writeClients(const std::string &inputName, int count, int revenue, const std::vector<int> &clients)
{

    // determine the output file name based on the input file name
    size_t slash = inputName.find_last_of('/');
    std::string base;
    // extract the base name of the input file without the directory path
    if (slash == std::string::npos)
        base = inputName;
    else
        base = inputName.substr(slash + 1);

    // create the output file name by prefixing the base name with "output/out"
    std::string outName = "output/out" + base;
    // open the output file for writing
    std::ofstream file(outName);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << outName << std::endl;
        return;
    }
    // write the results to the output file
    file << "There are " << count << " clients in this file" << std::endl;
    file << "Optimal revenue earned is " << revenue << std::endl;
    file << "Clients contributing to this optimal revenue: ";
    for (size_t i = 0; i < clients.size(); ++i)
    {
        if (i > 0)
            file << ", ";
        file << clients[i];
    }
    file << std::endl;
    file.close();
}