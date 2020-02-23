/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "headers.h"

class Solution
{
public:
    int leetcode_3_longest_substring_without_repeating_characters(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;
        int rst = 0;

        while(l < s.size()){
            if (r+1 < s.size() && freq[s[r+1]] == 0) freq[s[++r]] ++;
            else freq[s[l++]]--;

            rst = max(rst, r-l+1);
        }

        return rst;
    }
};

TEST(leetcode_3_longest_substring_without_repeating_characters, leetcode_3_longest_substring_without_repeating_characters_1)
{
    Solution s;
    string in = "abcabcbb";
    int ans = 3;
    EXPECT_EQ(s.leetcode_3_longest_substring_without_repeating_characters(in), ans);
}

TEST(leetcode_3_longest_substring_without_repeating_characters, leetcode_3_longest_substring_without_repeating_characters_2)
{
    Solution s;
    string in = "pwwkew";
    int ans = 3;
    EXPECT_EQ(s.leetcode_3_longest_substring_without_repeating_characters(in), ans);
}

TEST(leetcode_3_longest_substring_without_repeating_characters, leetcode_3_longest_substring_without_repeating_characters_3)
{
    Solution s;
    string in = "bbbbb";
    int ans = 1;
    EXPECT_EQ(s.leetcode_3_longest_substring_without_repeating_characters(in), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}