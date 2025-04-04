/**
 * 
给定一个整数数组 nums，将该数组升序排列。

 

示例 1：

输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= A.length <= 10000
-50000 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int partition(vector<int>& nums, int l, int r){
        int low = l;
        for (int i = l; i < r; i++) {
            if(nums[i] < nums[r]) swap(nums[i], nums[low++]);
        }

        swap(nums[low], nums[r]);

        return low;
    }
    void QuickSort(vector<int>& nums, int l, int r){
        if(l<r) {
            int mid = partition(nums, l, r);
            QuickSort(nums, l, mid-1);
            QuickSort(nums, mid+1, r);
        }
    }


    void Merge(vector<int>& nums, int left, int pivot, int right) {
        int n = right - left + 1; //储存元素总个数
        vector<int> tmp(n);
        int i = 0, l = left, r = pivot + 1;

        while(l <= pivot && r <= right){
            tmp[i++] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
        }

        while(l <= pivot){
            tmp[i++] = nums[l++];
        }

        while(r <= right){
            tmp[i++] = nums[r++];
        }

        for (int j = 0; j < n; ++j) {
            nums[left+j] = tmp[j];
        }
    }

    void MergeSort(vector<int>& nums, int left, int right){
        if(left < right){
            int pivot = (left + right)/2;
            MergeSort(nums, left, pivot);
            MergeSort(nums, pivot+1, right);
            Merge(nums, left, pivot, right);
        }
    }


    vector<int> leetcode_912_sort_an_array(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
};

TEST(leetcode_912_sort_an_array, leetcode_912_sort_an_array_1)
{
    Solution s;
    vector<int> in1 = {1, 4, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    vector<int> ans = {1, 2, 3, 4};
    EXPECT_EQ(s.leetcode_912_sort_an_array(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
