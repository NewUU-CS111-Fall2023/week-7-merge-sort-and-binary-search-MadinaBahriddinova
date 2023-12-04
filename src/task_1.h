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

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> frequencyMap;
    
    // Count frequency of each element
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Custom comparator for priority queue (min heap based on frequency)
    auto comparator = [](std::pair<int, int>& a, std::pair<int, int>& b) {
        return a.second > b.second;
    };
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> minHeap(comparator);

    // Push elements into minHeap based on frequency
    for (auto& entry : frequencyMap) {
        minHeap.push(entry);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Extract top k frequent elements from minHeap
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    // Reverse the result vector to get elements in descending order of frequency
    std::reverse(result.begin(), result.end());

    return result;
}
