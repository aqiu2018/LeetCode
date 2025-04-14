/**
 * 
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<string> mStr;
    void Recursive(int l, int r, string c){
        stringstream ss(c);
        string str;
        while(true) {
            ss>>str;
            if(ss.fail()) return str;

            break;
        }

        if(l>r) return;
        else if(l==0 && r== 0) mStr.push_back(c);
        else {
            if(l>0) Recursive(l-1, r, c+"(");
            if(r>0) Recursive(l, r-1, c+")");
        }
    }
    vector<string> leetcode_22_generate_parentheses(int n) {

        Recursive(n, n, "");
        return mStr;
    }
};

TEST(leetcode_22_generate_parentheses, leetcode_22_generate_parentheses_1)
{
    Solution s;
    int in1 = 3;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    vector<string> ans = {
            "((()))",
            "(()())",
            "(())()",
            "()(())",
            "()()()"
    };
    EXPECT_EQ(s.leetcode_22_generate_parentheses(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
