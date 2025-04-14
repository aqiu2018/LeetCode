/**
 * 
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    string leetcode_151_reverse_words_in_a_string(string s) {
        // method1
//        stringstream isStr(s);
//        s = "";
//        string str;
//        while(isStr >> str)
//        {
//            str.erase(0, str.find_first_not_of(' '));
//            if(str == "") continue;
//
//            if(s=="") s = str;
//            else s=str+" "+s;
//        }
//
//        return s;

        //method 2
        reverse(s.begin(), s.end());
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1, s.size());

        int l = 0, r = s.size(), r_bak = 0;
        while(true){
            r_bak = s.find_first_of(' ', l);
            if(r_bak == string::npos) r_bak = s.size();
            r = r_bak -1;

            while(l<r) {
                swap(s[l++], s[r--]);
            }

            l = s.find_first_not_of(' ', r_bak);
            if(l == string::npos) break;

            int delSpace = l - r_bak - 1;
            if(delSpace >= 1) {
                s.erase(r_bak, delSpace);
                l = l - delSpace;
            }
        }

        return s;
    }
};

TEST(leetcode_151_reverse_words_in_a_string, leetcode_151_reverse_words_in_a_string_1)
{
    Solution s;
    string in = "the sky is blue";
    string ans = "blue is sky the";
    EXPECT_EQ(s.leetcode_151_reverse_words_in_a_string(in), ans);
}

TEST(leetcode_151_reverse_words_in_a_string, leetcode_151_reverse_words_in_a_string_2)
{
    Solution s;
    string in = "  hello world!  ";
    string ans = "world! hello";
    EXPECT_EQ(s.leetcode_151_reverse_words_in_a_string(in), ans);
}

TEST(leetcode_151_reverse_words_in_a_string, leetcode_151_reverse_words_in_a_string_3)
{
    Solution s;
    string in = "a good   example";
    string ans = "example good a";
    EXPECT_EQ(s.leetcode_151_reverse_words_in_a_string(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
