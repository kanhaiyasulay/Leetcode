class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& nums, int s, int mid, int e)
    {
        // Count reverse pairs before merging
        int j = mid + 1;
        for (int i = s; i <= mid; i++) {
            while (j <= e && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // Standard merge
        int left = s, right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= e) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= e) temp.push_back(nums[right++]);

        for (int i = s; i <= e; i++) {
            nums[i] = temp[i - s];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e)
    {
        if (s >= e) return;
        int mid = (s + e) / 2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);
        merge(nums, s, mid, e);
    }

    int reversePairs(vector<int>& nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
