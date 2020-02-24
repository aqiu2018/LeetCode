/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

    Example 1:
    Input: "()"
    Output: true

    Example 2:
    Input: "()[]{}"
    Output: true

    Example 3:
    Input: "(]"
    Output: false

    Example 4:
    Input: "([)]"
    Output: false

    Example 5:
    Input: "{[]}"
    Output: true

*/


#include "headers.h"

class Solution
{
public:

    bool leetcode_5_ValidParentheses(string s) {

        stack<char> parenthese;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]){
                case '(':
                case '{':
                case '[':
                    parenthese.push(s[i]) ;
                    count ++;
                    break;
                case ')':
                    if (parenthese.size()>0 &&  parenthese.top() == '('){
                        parenthese.pop();
                    }
                    count --;
                    break;
                case '}':
                    if (parenthese.size()>0 && parenthese.top() == '{'){
                        parenthese.pop();
                    }
                    count --;
                    break;
                case ']':
                    if (parenthese.size()>0 && parenthese.top() == '['){
                        parenthese.pop();
                    }
                    count --;
                    break;
                default:
                    break;
            }
        }

        return (parenthese.size() == 0 ) ? ((count == 0) ? true : false) : false;
    }
};

TEST(leetcode_5_ValidParentheses, leetcode_5_ValidParentheses_1)
{
    Solution s;
    string in = "()[]{}";
    bool ans = true;
    EXPECT_EQ(s.leetcode_5_ValidParentheses(in), ans);
}

TEST(leetcode_5_ValidParentheses, leetcode_5_ValidParentheses_2)
{
    Solution s;
    string in = "()]{}";
    bool ans = false;
    EXPECT_EQ(s.leetcode_5_ValidParentheses(in), ans);
}

TEST(leetcode_5_ValidParentheses, leetcode_5_ValidParentheses_3)
{
    Solution s;
    string in = "(})";
    bool ans = false;
    EXPECT_EQ(s.leetcode_5_ValidParentheses(in), ans);
}

TEST(leetcode_5_ValidParentheses, leetcode_5_ValidParentheses_4)
{
    Solution s;
    string in = "";
    bool ans = true;
    EXPECT_EQ(s.leetcode_5_ValidParentheses(in), ans);
}

TEST(leetcode_5_ValidParentheses, leetcode_5_ValidParentheses_5)
{
    Solution s;
    string in = "(}";
    bool ans = false;
    EXPECT_EQ(s.leetcode_5_ValidParentheses(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
