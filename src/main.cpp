/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include "task_1.h"

int main() {
    std::cout << "Task 1" << std::endl;
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> A(N);

        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        long long sum = 0;

        for (int i = 0; i < N - 2; ++i) {
            std::vector<int> medians;
            for (int j = i; j < std::min(i + 3, N); ++j) {
                if ((j - i + 1) % 2 != 0) { // Odd-sized subarray
                    std::vector<int> subarray(A.begin() + i, A.begin() + j + 1);
                    std::sort(subarray.begin(), subarray.end());
                    int median = subarray[subarray.size() / 2];
                    medians.push_back(median);
                }
            }

            int min_median = *std::min_element(medians.begin(), medians.end());
            for (int j = i; j < N; ++j) {
                if (A[j] == min_median) {
                    A.erase(A.begin() + j);
                    break;
                }
            }
            N--; // Decrease array size

            sum += min_median;
        }

        for (int i = 0; i < N; ++i) {
            sum += A[i];
        }

        std::cout << sum << std::endl;
    }
    std::cout << "Task 2" << std::endl;
    // call for task 2
    std::cout << "Task 3" << std::endl;
    // call for task 3
    std::cout << "Task 4" << std::endl;
    // call for task 4
    std::cout << "Task 5" << std::endl;
    // call for task 5
    return 0;
}
