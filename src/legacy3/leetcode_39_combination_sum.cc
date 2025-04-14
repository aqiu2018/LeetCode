/**
 * 
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<int>> m_ans;
    void helper(vector<int>& candidates, int target, int id, vector<int> rst) {
        if(target == 0) {
            m_ans.push_back(rst);
            return;
        }
        else if (id==candidates.size()) return;
        else if (id==candidates.size()-1) {
            if (target % candidates[id] == 0) {
                for(int j = 0; j < target/candidates[id]; j++) rst.push_back(candidates[id]);
                m_ans.push_back(rst);
            }
            return;
        }

        int val = candidates[id];
        for (int i = 0; i*val <= target; i++) {
            for(int j = 0; j < i; j++) rst.push_back(val);
            helper(candidates, target-i*val, id+1, rst);
            for(int j = 0; j < i; j++) rst.pop_back();
        }
    }

    vector<vector<int>> leetcode_39_combination_sum(vector<int>& candidates, int target) {
        if(target==0 || candidates.size()==0) return vector<vector<int>>();

//        vector<int> rst;
//        helper(candidates, target, 0, rst);
//        return m_ans;


//        vector<int> dp(target+1, 0);
        map<int, vector<vector<int>> > m;
//        dp[0] = 1;
        for (int i = 0; i < candidates.size(); ++i) {
            for (int j = candidates[i]; j <= target; ++j) {
//                dp[j] += dp[j - candidates[i]];
                if(j-candidates[i] == 0){
//                if(j-candidates[i] == 0 && m.count(j-candidates[i]) == 0){
                    if(m.count(j) == 0) m.insert(make_pair(j, vector<vector<int>>{{j}}));
                    else m[j].push_back(vector<int>{j});

                } else if (m.count(j - candidates[i]) != 0){
                    for(auto v : m[j - candidates[i]]){
                        v.push_back(candidates[i]);
                        m[j].push_back(v);
                    }
                }
            }
        }

        return m[target];
    }

};

TEST(leetcode_39_combination_sum, leetcode_39_combination_sum_2)
{
    Solution s;
    vector<int> in1 = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = {
            {7},
            {2,2,3}
    };
    EXPECT_EQ(s.leetcode_39_combination_sum(in1, target), ans);
}
TEST(leetcode_39_combination_sum, leetcode_39_combination_sum_1)
{
    Solution s;
    vector<int> in1 = {2,3,5};
    int target = 8;
    vector<vector<int>> ans = {
            {2,2,2,2},
            {2,3,3},
            {3,5}
    };
    EXPECT_EQ(s.leetcode_39_combination_sum(in1, target), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
