/**
 * 
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool leetcode_55_jump_game(vector<int>& nums) {

        // greedy
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;

        // 2 dynamic

//        if(nums.size()==0) return true;
//
//        vector<bool> dp(nums.size(), false);
//        dp[nums.size()-1] = true;
//        for (int i = nums.size()-2; i >= 0; i--) {
//
//            int j = i+1;
//            while(j-i<=nums[i] && j < nums.size()){
//                if(dp[j]==true) {dp[i] = true; break;}
//                j++;
//            }
//        }
//
//        return dp[0];
    }
};


TEST(leetcode_55_jump_game, leetcode_55_jump_game_6)
{
    Solution s;
    vector<int> in1 = {};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_55_jump_game(in1), ans);
}

TEST(leetcode_55_jump_game, leetcode_55_jump_game_5)
{
    Solution s;
    vector<int> in1 = {0, 0};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = false;
    EXPECT_EQ(s.leetcode_55_jump_game(in1), ans);
}

TEST(leetcode_55_jump_game, leetcode_55_jump_game_4)
{
    Solution s;
    vector<int> in1 = {0};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_55_jump_game(in1), ans);
}

TEST(leetcode_55_jump_game, leetcode_55_jump_game_3)
{
    Solution s;
    vector<int> in1 = {2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_55_jump_game(in1), ans);
}

TEST(leetcode_55_jump_game, leetcode_55_jump_game_1)
{
    Solution s;
    vector<int> in1 = {2,3,1,1,4};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = true;
    EXPECT_EQ(s.leetcode_55_jump_game(in1), ans);
}

TEST(leetcode_55_jump_game, leetcode_55_jump_game_2)
{
    Solution s;
    vector<int> in1 = {3,2,1,0,4};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    bool ans = false;
    EXPECT_EQ(s.leetcode_55_jump_game(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
