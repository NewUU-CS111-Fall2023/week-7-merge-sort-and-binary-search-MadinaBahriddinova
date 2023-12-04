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
    int n;
    std::cin >> n;

    std::vector<int> Y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> Y[i];
    }

    // Calculate the initial beautifulness
    long long initial_beautifulness = 0;
    for (int i = 0; i < n; ++i) {
        initial_beautifulness += std::abs(Y[i] - (i + 1));
    }

    // Try swapping elements to maximize beautifulness
    long long max_beautifulness = initial_beautifulness;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Swap elements Y[i] and Y[j]
            std::swap(Y[i], Y[j]);

            long long curr_beautifulness = 0;
            for (int k = 0; k < n; ++k) {
                curr_beautifulness += std::abs(Y[k] - (k + 1));
            }

            // Update max_beautifulness if the current beautifulness is greater
            max_beautifulness = std::max(max_beautifulness, curr_beautifulness);

            // Swap back to restore the original permutation
            std::swap(Y[i], Y[j]);
        }
    }

    std::cout << max_beautifulness << std::endl;

    std::cout << "Task 3" << std::endl;
    int t;
    std::cin >> t;

    while (t--) {
        int N, M;
        std::cin >> N >> M;

        std::vector<int> A(N), B(M);

        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        for (int i = 0; i < M; ++i) {
            std::cin >> B[i];
        }

        std::vector<int> merged(N + M);

        int i = 0, j = 0, k = 0;

        while (i < N && j < M) {
            if (A[i] >= B[j]) {
                merged[k++] = A[i++];
            } else {
                merged[k++] = B[j++];
            }
        }

        while (i < N) {
            merged[k++] = A[i++];
        }

        while (j < M) {
            merged[k++] = B[j++];
        }

        std::sort(merged.begin(), merged.end(), std::greater<int>());

        for (int x = 0; x < N + M; ++x) {
            std::cout << merged[x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Task 4" << std::endl;
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int kth_smallest = kthSmallest(matrix, k);
    std::cout << "The kth smallest element in the matrix is: " << kth_smallest << std::endl;

    std::cout << "Task 5" << std::endl;
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int k;
    std::cin >> k;

    std::vector<int> kMostFrequent = topKFrequent(nums, k);

    std::cout << "The " << k << " most frequent elements are: ";
    for (int element : kMostFrequent) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
    return 0;
}
