/*
 * Author:
 * Date:
 * Name:
 */
int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    int n = matrix.size();
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minHeap.push(matrix[i][j]);
        }
    }

    int result = 0;
    while (k--) {
        result = minHeap.top();
        minHeap.pop();
    }

    return result;
}
