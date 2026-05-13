class Solution {
public:

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        // Check right child
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            swap(nums[i], nums[largest]);

            // Heapify affected subtree
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Extract elements one by one
        for (int i = n - 1; i > 0; i--) {

            // Move current root to end
            swap(nums[0], nums[i]);

            // Heapify reduced heap
            heapify(nums, i, 0);
        }

        return nums;
    }
};