/**
 * 
有效括号字符串 仅由 "(" 和 ")" 构成，并符合下述几个条件之一：

空字符串
连接，可以记作 AB（A 与 B 连接），其中 A 和 B 都是有效括号字符串
嵌套，可以记作 (A)，其中 A 是有效括号字符串
类似地，我们可以定义任意有效括号字符串 s 的 嵌套深度 depth(S)：

s 为空时，depth("") = 0
s 为 A 与 B 连接时，depth(A + B) = max(depth(A), depth(B))，其中 A 和 B 都是有效括号字符串
s 为嵌套情况，depth("(" + A + ")") = 1 + depth(A)，其中 A 是有效括号字符串
例如：""，"()()"，和 "()(()())" 都是有效括号字符串，嵌套深度分别为 0，1，2，而 ")(" 和 "(()" 都不是有效括号字符串。

 

给你一个有效括号字符串 seq，将其分成两个不相交的子序列 A 和 B，且 A 和 B 满足有效括号字符串的定义（注意：A.length + B.length = seq.length）。

现在，你需要从中选出 任意 一组有效括号字符串 A 和 B，使 max(depth(A), depth(B)) 的可能取值最小。

返回长度为 seq.length 答案数组 answer ，选择 A 还是 B 的编码规则是：如果 seq[i] 是 A 的一部分，那么 answer[i] = 0。否则，answer[i] = 1。即便有多个满足要求的答案存在，你也只需返回 一个。

 

示例 1：

输入：seq = "(()())"
输出：[0,1,1,1,1,0]
示例 2：

输入：seq = "()(())()"
输出：[0,0,0,1,1,0,1,1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_1111_maximum_nesting_parentheses(string seq) {

        if(seq.size() == 0) return  vector<int>{};
        vector<int> ans(seq.size());
        stack<int> s;
        s.push(0);
        for (int i = 1; i < seq.size(); ++i) {
            if(seq[i] == '(') {
                if(s.empty() || s.top() == 0) s.push(1);
                else s.push(0);
                ans[i] = s.top();
            }
            else {
                ans[i] = s.top();
                s.pop();
            }

        }
        return ans;
    }
};
TEST(leetcode_1111_maximum_nesting_parentheses, leetcode_1111_maximum_nesting_parentheses_3)
{
    Solution s;
    string in1= "()(())()";
    vector<int> ans = {0,0,0,1,1,0,1,1};
    EXPECT_EQ(s.leetcode_1111_maximum_nesting_parentheses(in1), ans);
}

TEST(leetcode_1111_maximum_nesting_parentheses, leetcode_1111_maximum_nesting_parentheses_1)
{
    Solution s;
    string in1= "(()())";
    vector<int> ans = {0,1,1,1,1,0};
    EXPECT_EQ(s.leetcode_1111_maximum_nesting_parentheses(in1), ans);
}

TEST(leetcode_1111_maximum_nesting_parentheses, leetcode_1111_maximum_nesting_parentheses_2)
{
    Solution s;
    string in1= "(()(()))";
    vector<int> ans = {0,1,1,0,1,1,0,0};
    EXPECT_EQ(s.leetcode_1111_maximum_nesting_parentheses(in1), ans);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
