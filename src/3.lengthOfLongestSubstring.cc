/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-30
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0, n = s.size(), res = 0;
        unordered_set<char> hash_set;
        while (left < n && right < n)
        {
            if (hash_set.count(s[right]) == 0)
            {
                hash_set.insert(s[right]);
                right++;
                res = max(res, right - left);
            }
            else
            {
                hash_set.erase(s[left]);
                left++;
            }
        }
        return res;
    }
};

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_1)
{
    Solution s;
    string in = "abcabcbb";
    int ans = 3;
    EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_2)
{
    Solution s;
    string in = "bbbbb";
    int ans = 1;
    EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_3)
{
    Solution s;
    string in = "pwwkew";
    int ans = 3;
    EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_4)
{
    Solution s;
    string in = "aab";
    int ans = 2;
    EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

TEST(lengthOfLongestSubstring, lengthOfLongestSubstring_5)
{
    Solution s;
    string in = "dvdf";
    int ans = 3;
    EXPECT_EQ(s.lengthOfLongestSubstring(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}