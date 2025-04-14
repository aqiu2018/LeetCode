/**
 * 
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

注意:
字符串长度 和 k 不会超过 104。

示例 1:

输入:
s = "ABAB", k = 2

输出:
4

解释:
用两个'A'替换为两个'B',反之亦然。
示例 2:

输入:
s = "AABABBA", k = 1

输出:
4

解释:
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_424_longest_repeating_character_replacement(string s, int k) {

//        string in="BAAAB";
        auto maxLen = 0, maxCnt = 0;
        int l=0, r = 0;
        vector<int> memo(128, 0);
        for (;r < s.size(); ++r) {
            memo[s[r]]++;
            maxCnt = max(maxCnt, memo[s[r]]);
            if(maxLen - maxCnt < k) maxLen++;
            else memo[s[r - maxLen]]--;
        }

        return maxLen;

        // 6 test cannot pass
        maxLen = 0;
        l=0, r = 1;

        char target;
        int maxLen, k1, k2;
        while (l<s.size()) {
            target = s[l];
            maxCnt = 1;
            k1 = k;
            maxLen = max(maxLen, maxCnt);
            while(r<s.size()){
                if(target == s[r] || k1 > 0){
                    if(target != s[r]) k1--;
                    if(k1==k) l++;
                    maxCnt++;
                    maxLen = max(maxLen, maxCnt);
                    r++;
                }
                else{
                    break;
                }
            }

            l++;
            r=l+1;
        }

        return maxLen;
    }
};

TEST(leetcode_424_longest_repeating_character_replacement, leetcode_424_longest_repeating_character_replacement_6)
{
    Solution s;
    string in="BAAAB";
    int k =2;
    int ans = 5;
    EXPECT_EQ(s.leetcode_424_longest_repeating_character_replacement(in, k), ans);
}

TEST(leetcode_424_longest_repeating_character_replacement, leetcode_424_longest_repeating_character_replacement_5)
{
    Solution s;
    string in="BBACCC";
    int k =2;
    int ans = 5;
    EXPECT_EQ(s.leetcode_424_longest_repeating_character_replacement(in, k), ans);
}

TEST(leetcode_424_longest_repeating_character_replacement, leetcode_424_longest_repeating_character_replacement_2)
{
    Solution s;
    string in="BBACC";
    int k =2;
    int ans = 4;
    EXPECT_EQ(s.leetcode_424_longest_repeating_character_replacement(in, k), ans);
}

TEST(leetcode_424_longest_repeating_character_replacement, leetcode_424_longest_repeating_character_replacement_1)
{
    Solution s;
    string in="AACAACCCBBABABBCCAAA";
    int k =2;
    int ans = 7;
    EXPECT_EQ(s.leetcode_424_longest_repeating_character_replacement(in, k), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
