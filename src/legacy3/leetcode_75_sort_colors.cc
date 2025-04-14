/**
 * 
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-colors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    void leetcode_75_sort_colors(vector<int>& nums) {
        int zero=-1, one=0, two=nums.size();
        while (one<two){
            if(nums[one] == 2) swap(nums[one], nums[--two]);
            else if(nums[one] == 1) one++;
            else if(nums[one] == 0) swap(nums[++zero], nums[one++]);
        }
    }
};

TEST(leetcode_75_sort_colors, leetcode_75_sort_colors_2)
{
    Solution s;
    vector<int> in1 = {1};
    vector<int> ans = {1};
    s.leetcode_75_sort_colors(in1);
    EXPECT_EQ(in1, ans);
}

TEST(leetcode_75_sort_colors, leetcode_75_sort_colors_1)
{
    Solution s;
    vector<int> in1 = {2,0,2,1,1,0};
    vector<int> ans = {0,0,1,1,2,2};
    s.leetcode_75_sort_colors(in1);
    EXPECT_EQ(in1, ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
