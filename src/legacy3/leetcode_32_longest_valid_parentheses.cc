/**
 * 
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_32_longest_valid_parentheses(string s) {

        int res = 0, start = 0;
        stack<int> m;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='(') m.push(i);
            else if(s[i]==')'){
                if(m.empty()) start = i+1;
                else{
                    m.pop();
                    res = m.empty()?max(res, i-start+1): max(res, i-m.top());
                }
            }
        }
        return res;

//        if(s.size()==0) return 0;
//
//        vector<int> dp_ans(s.size(), 0);
//        vector<int> dp(s.size(), 0);
//        vector<bool> dp_bool(s.size(), false);
//        stack<char> Stack;
//        stack<int> StackIndex;
//        Stack.push(s[0]);
//        StackIndex.push(0);
//        for (int i = 1; i < s.size(); ++i) {
//            if(!Stack.empty() && Stack.top() =='('  && s[i] == ')'){
//                Stack.pop();
//
//                if(dp_bool[i-1] == true)
//                    dp[i] = 2 + dp[i-1] + (StackIndex.top()-1>=0 && dp_bool[StackIndex.top()-1]==true?dp[StackIndex.top()-1]:0);
//                else
//                    dp[i] = 2 + (i-2>=0 && dp_bool[i-2]==true ? dp[i-2] : 0);
//
//                StackIndex.pop();
//                dp_bool[i]=true;
//            }else{
//                Stack.push(s[i]);
//                StackIndex.push(i);
//                dp[i] = dp[i-1];
//            }
//
//            dp_ans[i] = max(dp_ans[i-1], dp[i]);
//
//        }
//
//        return dp_ans[s.size()-1];
    }
};

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_8)
{
    Solution s;
    string in1 = "())";
    cout << " size " << in1.size() << endl;
    int ans = 2;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_7)
{
    Solution s;
    string in1 = "((()()))";
    cout << " size " << in1.size() << endl;
    int ans = 8;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_6)
{
    Solution s;
    string in1 = "";
    cout << " size " << in1.size() << endl;
    int ans = 0;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_5)
{
    Solution s;
    string in1 = "(";
    cout << " size " << in1.size() << endl;
    int ans = 0;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_4)
{
    Solution s;
    string in1 = "(()(()()((()))(((";
    cout << " size " << in1.size() << endl;
    int ans = 10;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_3)
{
    Solution s;
    string in1 = ")()())()";
    cout << " size " << in1.size() << endl;
    int ans = 4;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_2)
{
    Solution s;
    string in1 = ")()())";
    cout << " size " << in1.size() << endl;
    int ans = 4;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

TEST(leetcode_32_longest_valid_parentheses, leetcode_32_longest_valid_parentheses_1)
{
    Solution s;
    string in1 = "(()";
    cout << " size " << in1.size() << endl;
    int ans = 2;
    EXPECT_EQ(s.leetcode_32_longest_valid_parentheses(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
