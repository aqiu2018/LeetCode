/**
 * 
 * Copyright (c) 2018
 * 
 * @file
 * @author   qzc (1457615966@qq.com)
 * @date     2019-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-11-20
 * Modified By:    qzc (1457615966@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int Partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int low = left;
        for(int i = low; i < right;i++){
            if(nums[i] < pivot){
                swap(nums[i], nums[low]);
                low++;
            }
        }
        swap(nums[low], nums[right]);

        return low;
    }

    void QuickSort(vector<int>& nums, int left, int right) {
        if(left < right){
            int pivot = Partition(nums, left, right);
            QuickSort(nums, left, pivot-1);
            QuickSort(nums, pivot+1, right);
        }
    }

    void Merge(vector<int>& nums, int left, int pivot, int right) {
        int n = right - left + 1; //储存元素总个数
        vector<int> tmp(n);
        int i = 0, l = left, r = pivot+1;

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
//        MergeSort(nums, 0, nums.size()-1 );

        return nums;
    }
};

TEST(leetcode_912_sort_an_array, leetcode_912_sort_an_array_1)
{
    Solution s;
    vector<int> in = {5, 1, 2, 3};
    vector<int> ans = {1, 2, 3, 5};
    EXPECT_EQ(s.leetcode_912_sort_an_array(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
