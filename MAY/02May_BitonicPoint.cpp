class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Handle edge cases explicitly
            if (mid > 0 && mid < arr.size() - 1) {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                    return arr[mid]; // Bitonic point
                } else if (arr[mid] > arr[mid - 1]) {
                    low = mid + 1; // Move right
                } else {
                    high = mid - 1; // Move left
                }
            } else if (mid == 0) {
                return max(arr[0], arr[1]);
            } else if (mid == arr.size() - 1) {
                return max(arr[arr.size() - 1], arr[arr.size() - 2]);
            }
        }
        return -1; // Just in case, though constraints say bitonic point exists
    }
}; 