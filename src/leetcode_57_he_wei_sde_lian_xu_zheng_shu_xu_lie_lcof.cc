/**
 * 
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<int>> leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof(int target) {

        if(target==0) return vector<vector<int>>{0};
        vector<vector<int>> ans;
        int l=0,r=1,sum=1;
        while(l<r){
            if(sum==target){
                vector<int>ans1;
                for (int i = l; i <= r; ++i) {
                    if(i==0) continue;
                    ans1.push_back(i);
                }
                ans.push_back(ans1);
                sum+=++r;
            }
            if(sum>target) {
                sum-=l++;
            }
            else sum+=++r;
        }

        return ans;
    }
};

TEST(leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof, leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof_2)
{
    Solution s;
    int in = 9;
    vector<vector<int>> ans = {{2,3,4},{4,5}};
    EXPECT_EQ(s.leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof(in), ans);
}
TEST(leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof, leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof_1)
{
    Solution s;
    int in = 15;
    vector<vector<int>> ans = {{1,2,3,4,5},{4,5,6},{7,8}};
    EXPECT_EQ(s.leetcode_57_he_wei_sde_lian_xu_zheng_shu_xu_lie_lcof(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
