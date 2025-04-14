/**
 * 
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释:
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int helper(string& word1, int i, string& word2, int j, vector<vector<int>>& memo){

        if(i == word1.size()) return word2.size() - j;
        if(j == word2.size()) return word1.size() - i;
        if(memo[i][j] > 0) return memo[i][j];

        int ans = 0;
        if(word1[i] == word2[j]) return helper(word1, i+1, word2, j+1, memo);
        else {
            int insertCnt = helper(word1, i, word2, j+1, memo);
            int deleteCnt = helper(word1, i+1, word2, j, memo);
            int replaceCnt = helper(word1, i+1, word2, j+1, memo);
            ans = min(insertCnt, min(deleteCnt, replaceCnt)) + 1;
        }

        return memo[i][j] = ans;
    }
    int leetcode_72_edit_distance(string word1, string word2) {

        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n));

        return helper(word1, 0, word2, 0, memo);
    }
};

TEST(leetcode_72_edit_distance, leetcode_72_edit_distance_1)
{
    Solution s;
    string word1 = "horse", word2 = "ros";
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 3;
    EXPECT_EQ(s.leetcode_72_edit_distance(word1, word2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
