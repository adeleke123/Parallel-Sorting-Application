#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

using namespace std;

// Function to partition the list
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quicksort on a sub-list
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to perform multithreaded quicksort on a sub-list
void multithreaded_quicksort(vector<int>& arr, int low, int high, int depth) {
    if (depth >= 2 || low >= high) {
        quicksort(arr, low, high);
        return;
    }
    int pi = partition(arr, low, high);
    thread left_thread(multithreaded_quicksort, ref(arr), low, pi - 1, depth + 1);
    thread right_thread(multithreaded_quicksort, ref(arr), pi + 1, high, depth + 1);
    left_thread.join();
    right_thread.join();
}

// Function to perform the multithreaded quicksort on the entire list
void parallel_quicksort(vector<int>& arr) {
    multithreaded_quicksort(arr, 0, arr.size() - 1, 0);
}

int main() {
    vector<int> arr = {3, 7, 1, 4, 9, 2, 6, 5, 8};
    parallel_quicksort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
