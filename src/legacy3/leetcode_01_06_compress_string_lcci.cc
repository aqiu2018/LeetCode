/**
 * 
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compress-string-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    string leetcode_01_06_compress_string_lcci(string S) {

        string ans="";
        char pre=' ';
        int len = 0, cnt = 0;
        for(auto s : S){
            if(pre==s) cnt++;
            else {
                if(pre !=' ') ans+= pre +to_string(cnt);
                pre = s;
                cnt=1;
                len+=2;
            }
        }
        if(cnt != 0) ans+= pre +to_string(cnt);

        return len>=S.size() ? S : ans;
    }
};

TEST(leetcode_01_06_compress_string_lcci, leetcode_01_06_compress_string_lcci_5)
{
    Solution s;
    string in = "ab";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "ab";
    EXPECT_EQ(s.leetcode_01_06_compress_string_lcci(in), ans);
}

TEST(leetcode_01_06_compress_string_lcci, leetcode_01_06_compress_string_lcci_4)
{
    Solution s;
    string in = "aa";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "aa";
    EXPECT_EQ(s.leetcode_01_06_compress_string_lcci(in), ans);
}
TEST(leetcode_01_06_compress_string_lcci, leetcode_01_06_compress_string_lcci_3)
{
    Solution s;
    string in = "a";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "a";
    EXPECT_EQ(s.leetcode_01_06_compress_string_lcci(in), ans);
}

TEST(leetcode_01_06_compress_string_lcci, leetcode_01_06_compress_string_lcci_2)
{
    Solution s;
    string in = "abbccd";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "abbccd";
    EXPECT_EQ(s.leetcode_01_06_compress_string_lcci(in), ans);
}

TEST(leetcode_01_06_compress_string_lcci, leetcode_01_06_compress_string_lcci_1)
{
    Solution s;
    string in = "aabcccccaaa";
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    string ans = "a2b1c5a3";
    EXPECT_EQ(s.leetcode_01_06_compress_string_lcci(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
