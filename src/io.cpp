#include "client.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

void writeClients(const std::string &inputName, int count, int revenue, const std::vector<int> &clients)
{

    size_t slash = inputName.find_last_of('/');
    std::string base;
    if (slash == std::string::npos)
        base = inputName;
    else
        base = inputName.substr(slash + 1);

    std::string outName = "output/out" + base;
    std::ofstream file(outName);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << outName << std::endl;
        return;
    }

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