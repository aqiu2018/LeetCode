/**
 *
 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 */
#include "headers.h"

class Solution
{
public:
    unordered_map<char, string> mMap;
    vector<string> leetcode_17_letter_combinations_of_a_phone_number(string digits) {

        vector<string> ans;
        if(digits.empty()) return ans;
        mMap.insert(make_pair('2', "abc"));
        mMap.insert(make_pair('3', "def"));
        mMap.insert(make_pair('4', "ghi"));
        mMap.insert(make_pair('5', "jkl"));
        mMap.insert(make_pair('6', "mno"));
        mMap.insert(make_pair('7', "pqrs"));
        mMap.insert(make_pair('8', "tuv"));
        mMap.insert(make_pair('9', "wxyz"));

        ans.push_back("");
        for(auto c : digits){
            string s = mMap[c];
            int n = ans.size();
            for (int j = 0; j < n; ++j) {
                string tmp = ans.front();
                ans.erase(ans.begin());
                for (int i = 0; i < s.size(); ++i) {
                    ans.push_back(tmp+s[i]);
                }
            }
        }
        return ans;

//        string ss = "23456789";
//        string test = "abc";
//        for(auto c : ss){
//            int n = 3*(c-'2');
//            string dest;
//            for(int i = 0; i < 3; i++) dest += test[i]+n;
//            if(c=='7') dest+='s';
//            mMap.insert(make_pair(c, dest));
//        }

        return ans;
    }
};

TEST(leetcode_17_letter_combinations_of_a_phone_number, leetcode_17_letter_combinations_of_a_phone_number_1)
{
    Solution s;
    string in1 = "23";
    vector<string> ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_EQ(s.leetcode_17_letter_combinations_of_a_phone_number(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
