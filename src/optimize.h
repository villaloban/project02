#pragma once
#include "dag.h"
#include <vector>

struct OptimizationResult
{
    int revenue;
    std::vector<int> clients;
};

OptimizationResult optimize(const std::vector<std::vector<Edge>> &adj, const std::vector<int> &topoOrder);