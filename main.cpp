#include <iostream>
#include <vector>
#include "multi.h"

int main() {
    std::vector<int> arr = {3, 7, 1, 4, 9, 2, 6, 5, 8};
    parallel_quicksort(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
