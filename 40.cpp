#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterToRight(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1);
    std::stack<int> s; // Stack to store indices of elements

    for (int i = 0; i < n; i++) {
        while (!s.empty() && nums[i] > nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 5, 2, 10, 8};
    std::vector<int> result = nextGreaterToRight(nums);

    for (int val : result) {
        std::cout << val << " ";
    }

    return 0;
}
