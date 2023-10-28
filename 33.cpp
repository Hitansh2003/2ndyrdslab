#include <iostream>
#include <vector>

int trapRainwater(const std::vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0; // Cannot trap water with less than 3 bars.
    }

    int left = 0;       // Left pointer.
    int right = n - 1;  // Right pointer.
    int leftMax = 0;    // Maximum height on the left side.
    int rightMax = 0;   // Maximum height on the right side.
    int trappedWater = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] > leftMax) {
                leftMax = height[left];
            } else {
                trappedWater += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] > rightMax) {
                rightMax = height[right];
            } else {
                trappedWater += rightMax - height[right];
            }
            right--;
        }
    }

    return trappedWater;
}

int main() {
    std::vector<int> elevationMap = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trapRainwater(elevationMap);
    std::cout << "The trapped rainwater is: " << trappedWater << std::endl;

    return 0;
}
