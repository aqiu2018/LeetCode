/**
 * 
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_11_ContainerWithMostWater(vector<int>& height) {

//        int maxAera = 0;
//        for (int i = 0; i < height.size(); ++i) {
//            for (int j = i+1; j < height.size(); ++j) {
//                maxAera = max(maxAera, min(height[i], height[j]) * (j - i));
//            }
//        }

//        int l = 0, r = height.size() - 1, maxAera = 0;
//        while (l < r){
//            maxAera = max(maxAera, min(height[l], height[r]) * (r - l));
//            if (height[l] < height[r])
//                l++;
//            else
//                r--;
//        }

        int *left = &height[0], *right = &height[height.size() - 1], maxAera = 0;
        while (left != right){
            maxAera = max(maxAera, min(*left, *right) * (int)(right - left));
            if (*left < *right) left++;
            else right--;
        }

        left = nullptr; right = nullptr;
        return maxAera;
    }
};

TEST(leetcode_11_ContainerWithMostWater, leetcode_11_ContainerWithMostWater_1)
{
    Solution s;
    vector<int> in = {1,8,6,2,5,4,8,3,7};
    int ans = 49;
    EXPECT_EQ(s.leetcode_11_ContainerWithMostWater(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
