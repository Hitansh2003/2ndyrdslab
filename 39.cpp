#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> findFirstNegativeInWindow(const vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;

    deque<int> negIndices; // Store the indices of negative numbers

    // Process the first window
    for (int i = 0; i < k; i++) {
        if (nums[i] < 0) {
            negIndices.push_back(i);
        }
    }

    // Process the rest of the array
    for (int i = k; i < n; i++) {
        // If there is a negative number in the previous window, add it to the result
        if (!negIndices.empty()) {
            result.push_back(nums[negIndices.front()]);
        } else {
            result.push_back(0); // No negative number in the window
        }

        // Remove indices that are outside the current window
        while (!negIndices.empty() && negIndices.front() <= i - k) {
            negIndices.pop_front();
        }

        // Add the current index to the deque if the current number is negative
        if (nums[i] < 0) {
            negIndices.push_back(i);
        }
    }

    // Process the last window
    if (!negIndices.empty()) {
        result.push_back(nums[negIndices.front()]);
    } else {
        result.push_back(0);
    }

    return result;
}

int main() {
    vector<int> nums = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = findFirstNegativeInWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
