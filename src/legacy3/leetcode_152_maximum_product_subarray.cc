/**
 * 
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_152_maximum_product_subarray(vector<int>& nums) {

        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        log(INFO_) << "values are ";
        copy(nums.begin(), nums.end(), log(" "));
        log() << endl;

        vector<int> newNums;
        long preValue = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i]==0 && newNums.size() != 0 && newNums.back()==0) continue;
            else if(newNums.size() != 0 && newNums.back()==0) {
                preValue = nums[i];
                if(i == nums.size()-1) {
                    newNums.push_back(preValue);
                    continue;
                }
            }else if(nums[i] == 0){
                newNums.push_back(preValue);;
                newNums.push_back(0);
                continue;
            }

            long n = preValue * nums[i];
            if(n < 0) {
                newNums.push_back(preValue);
                preValue = nums[i];
                if(i == nums.size()-1) newNums.push_back(preValue);
                continue;
            }
            preValue = n;
            if(i == nums.size()-1) newNums.push_back(preValue);
        }
        log(INFO_) << "values are ";
        copy(newNums.begin(), newNums.end(), log(" "));
        log() << endl;

//        int ans = newNums[0];
//        vector<int> dp(newNums.size(), 0);
//        dp[0] = newNums[0];
//        for (int j = 1; j < newNums.size(); ++j) {
//            dp[j] =
//            ans = max(ans, )
//        }

        int ans = nums[0], n = nums.size();
        vector<int> f(n, 0), g(n,0);
        f[0] = nums[0]; g[0] = nums[0];
        for (int j = 1; j < n; ++j) {
            f[j] = max(nums[j], max(f[j-1]*nums[j], g[j-1]*nums[j]) );
            g[j] = min(nums[j], min(f[j-1]*nums[j], g[j-1]*nums[j]) );
            ans = max(ans, f[j]);
        }
        return ans;
    }
};

TEST(leetcode_152_maximum_product_subarray, leetcode_152_maximum_product_subarray_1)
{
    Solution s;
    vector<int> in1 = {2,3,-2,4, 0, 3, -2};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 6;
    EXPECT_EQ(s.leetcode_152_maximum_product_subarray(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
