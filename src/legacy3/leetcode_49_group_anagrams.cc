/**
 * 
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<string>> leetcode_49_group_anagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(auto s : strs){
            string ss = s;
            sort(ss.begin(), ss.end());

            auto iter = m.find(ss);
            if(iter == m.end())
                m.insert(make_pair(ss, vector<string>{s}));
            else iter->second.push_back(s);
        }

        for(auto mm : m){
            ans.push_back(mm.second);
        }

        return ans;
    }
};

TEST(leetcode_49_group_anagrams, leetcode_49_group_anagrams_1)
{
    Solution s;
    vector<string> in1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = {
            {"ate","eat","tea"},
            {"nat","tan"},
            {"bat"}
    };
    EXPECT_EQ(s.leetcode_49_group_anagrams(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
