#pragma once
#include "client.h"
#include <string>
#include <vector>

std::vector<client> readClients(const std::string &filename);
void writeClients(const std::string &inputName, int count, int revenue, const std::vector<int> &clients);