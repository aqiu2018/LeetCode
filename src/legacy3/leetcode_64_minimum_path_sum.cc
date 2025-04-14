/**
 * 
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:

    typedef unordered_map<string, int> Map;
    Map* map = new Map;
    int m = 0;
    int n = 0;
//    unordered_map<string, int>* map = new unordered_map<string, int>;
    int Iteration(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0) return INT_MAX;
        if(i== 0 && j == 0) return grid[i][j];
        m++;
        return min(Iteration(grid, i-1, j), Iteration(grid, i, j-1)) + grid[i][j];
    }

    int Iteration2(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0) return INT_MAX;
        if(i== 0 && j == 0) return grid[i][j];

        string key = to_string(i) + " " + to_string(j);
        m++;
//        cout<< " key " << key.c_str() << endl;
//        Map::iterator iter = map->find(key);
//        if(iter != map->end()) return iter->second;
        if(map->find(key) != map->end()) return map->find(key)->second;
        n++;

        int rst = min(Iteration2(grid, i-1, j), Iteration2(grid, i, j-1)) + grid[i][j];
        map->insert(pair<string, int>(key, rst));

        return rst;
    }

    int leetcode_64_minimum_path_sum(vector<vector<int>>& grid) {

        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();

        // 1. 递归
        // 1.1
        // 1.2 f(i, j) = min{ f(i - 1, j) , f(i, j - 1)} + f(i, j)  ------- ( i [0, row] j [0, col])
        int rst = 0;
        rst = Iteration(grid, row - 1, col - 1);

        // 2. 递归 + 备忘录
        cout << " Iteration2 " << endl;
//        rst = Iteration2(grid, row - 1, col - 1);
        cout<< " m " << m << " n "<<n<< endl;
        return rst;


        // 3. 动态规划
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(i == 0 && j == 0) {dp[i][j] = grid[i][j]; continue;}
                dp[i][j] = min((i-1>=0)?dp[i-1][j]:INT_MAX, (j-1>=0)?dp[i][j-1]:INT_MAX) + grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};

TEST(leetcode_64_minimum_path_sum, leetcode_64_minimum_path_sum_1)
{
    Solution s;
    vector<vector<int>> in = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int ans = 7;
    EXPECT_EQ(s.leetcode_64_minimum_path_sum(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
