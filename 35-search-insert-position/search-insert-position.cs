public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int s = 0, e = nums.Length-1, ans = nums.Length;

        if(nums[0] > target) return 0;

        while(s <= e)
        {
            int mid = (s+e) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e = mid-1;
            else
            {
                ans = mid;
                s = mid + 1;
            }
        }

        return ans+1;
    }
}