#include "multi.h"
#include <thread>
#include <algorithm>

// Function to partition the list
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quicksort on a sub-list
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to perform multithreaded quicksort on a sub-list
void multithreaded_quicksort(std::vector<int>& arr, int low, int high, int depth) {
    if (depth >= 2 || low >= high) {
        quicksort(arr, low, high);
        return;
    }
    int pi = partition(arr, low, high);
    std::thread left_thread(multithreaded_quicksort, std::ref(arr), low, pi - 1, depth + 1);
    std::thread right_thread(multithreaded_quicksort, std::ref(arr), pi + 1, high, depth + 1);
    left_thread.join();
    right_thread.join();
}

// Function to perform the multithreaded quicksort on the entire list
void parallel_quicksort(std::vector<int>& arr) {
    multithreaded_quicksort(arr, 0, arr.size() - 1, 0);
}
