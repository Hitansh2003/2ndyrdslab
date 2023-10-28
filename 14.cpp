#include <iostream>
#include <vector>

using namespace std;

int findFloor(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    int floor = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            floor = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return floor;
}

int findCeiling(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    int ceiling = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            ceiling = arr[mid];
            end = mid - 1;
        }
    }

    return ceiling;
}

int findPeak(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        } else if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return arr[start];
}

int findMinimum(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return arr[start];
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    cout << "Floor of " << target << ": " << findFloor(arr, target) << endl;
    cout << "Ceiling of " << target << ": " << findCeiling(arr, target) << endl;
    cout << "Peak element: " << findPeak(arr) << endl;
    cout << "Minimum element: " << findMinimum(arr) << endl;

    return 0;
}
