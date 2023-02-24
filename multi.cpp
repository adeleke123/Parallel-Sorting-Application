#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

void quicksort(std::vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

void parallel_quicksort(std::vector<int>& arr, int left, int right, int depth) {
    if (depth <= 0 || left >= right) {
        quicksort(arr, left, right);
        return;
    }

    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    std::thread left_thread(parallel_quicksort, std::ref(arr), left, j, depth - 1);
    std::thread right_thread(parallel_quicksort, std::ref(arr), i, right, depth - 1);

    left_thread.join();
    right_thread.join();
}

int main() {
    std::vector<int> arr = {5, 3, 2, 7, 8, 1, 6, 4};
    int num_threads = 2;
    int depth = std::log2(num_threads);

    parallel_quicksort(arr, 0, arr.size() - 1, depth);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

