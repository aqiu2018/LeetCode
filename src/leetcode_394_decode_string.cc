/**
 * 
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    string leetcode_394_decode_string(string s) {

        string t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = 10 * cnt + s[i] - '0';
            } else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0;
                t.clear();
            } else if (s[i] == ']') {
                int k = s_num.top(); s_num.pop();
                for (int j = 0; j < k; ++j) s_str.top() += t;
                t = s_str.top();
                s_str.pop();
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }
};

TEST(leetcode_394_decode_string, leetcode_394_decode_string_5)
{
    Solution s;
    string in("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    string ans = "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef";
    EXPECT_EQ(s.leetcode_394_decode_string(in), ans);
}

TEST(leetcode_394_decode_string, leetcode_394_decode_string_4)
{
    Solution s;
    string in("2[abc]3[cd]ef");
    string ans = "abcabccdcdcdef";
    EXPECT_EQ(s.leetcode_394_decode_string(in), ans);
}

TEST(leetcode_394_decode_string, leetcode_394_decode_string_3)
{
    Solution s;
    string in("3[a]2[b4[F]c]");
//    string in("2[abc]3[cd]ef");
    string ans = "aaabFFFFcbFFFFc";
//    string ans = "abcabccdcdcdef";
    EXPECT_EQ(s.leetcode_394_decode_string(in), ans);
}

TEST(leetcode_394_decode_string, leetcode_394_decode_string_2)
{
    Solution s;
    string in("3[a2[c]]");
    string ans = "accaccacc";
    EXPECT_EQ(s.leetcode_394_decode_string(in), ans);
}

TEST(leetcode_394_decode_string, leetcode_394_decode_string_1)
{
    Solution s;
    string in("3[a]2[bc]");
    string ans = "aaabcbc";
    EXPECT_EQ(s.leetcode_394_decode_string(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
