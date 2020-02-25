/**
 * 
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool leetcode_567_permutation_in_string(string s1, string s2) {


        vector<int> s1Hash(256, 0), slidewindow(256,0);
        for(int i =0; i < s1.size(); i++) {
            ++s1Hash[s1[i]];
            ++slidewindow[s2[i]];
        }

        if(s1Hash == slidewindow) return  true;

        for(int i=s1.size(); i<s2.size(); i++){
            ++slidewindow[s2[i]];
            --slidewindow[s2[i-s1.size()]];

            if(s1Hash == slidewindow) return  true;
        }

        return false;
    }
};


//        char* head = const_cast<char *>(s1.c_str());
//        char* p1 = head;
//        while(*p1 != ''){
//            cout<<" " << *p1++;
//        }
//        cout<<endl;

TEST(leetcode_567_permutation_in_string, leetcode_567_permutation_in_string_1)
{
    Solution s;
    string s1 = "ab", s2 = "eidbaooo";
    bool ans = true;
    EXPECT_EQ(s.leetcode_567_permutation_in_string(s1, s2), ans);
}

TEST(leetcode_567_permutation_in_string, leetcode_567_permutation_in_string_2)
{
    Solution s;
    string s1 = "ab", s2 = "eidboaooo";
    bool ans = false;
    EXPECT_EQ(s.leetcode_567_permutation_in_string(s1, s2), ans);
}

TEST(leetcode_567_permutation_in_string, leetcode_567_permutation_in_string_3)
{
    Solution s;
    string s1 = "ab", s2 = "b";
    bool ans = false;
    EXPECT_EQ(s.leetcode_567_permutation_in_string(s1, s2), ans);
}

TEST(leetcode_567_permutation_in_string, leetcode_567_permutation_in_string_4)
{
    Solution s;
    string s1 = "abc", s2 = "ababc";
    bool ans = true;
    EXPECT_EQ(s.leetcode_567_permutation_in_string(s1, s2), ans);
}

TEST(leetcode_567_permutation_in_string, leetcode_567_permutation_in_string_45)
{
    Solution s;
    string s1 = "aabc", s2 = "ababc";
    bool ans = false;
    EXPECT_EQ(s.leetcode_567_permutation_in_string(s1, s2), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
