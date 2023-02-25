#ifndef MULTI_H
#define MULTI_H

#include <vector>

int partition(std::vector<int>& arr, int low, int high);
void quicksort(std::vector<int>& arr, int low, int high);
void multithreaded_quicksort(std::vector<int>& arr, int low, int high, int depth);
void parallel_quicksort(std::vector<int>& arr);

#endif
