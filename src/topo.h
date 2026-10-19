#pragma once
#include "dag.h"
#include <vector>

std::vector<int> topologicalSort(const std::vector<std::vector<Edge>> &adj);