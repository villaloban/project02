#pragma once
#include "client.h"
#include <string>
#include <vector>

struct Edge
{
    int to;
    int weight;
};

std::vector<std::vector<Edge>> buildDAG(const std::vector<client> &clients);