/**
 * 
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 1：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int m_row;
    int m_col;
    int m_k;
    int m_ans;
    vector<vector<int>> m_index= {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    vector<vector<bool>> m_visited;
    void dfs(int i, int j){

        if(i<0 || i >= m_row || j < 0 || j >= m_col || m_visited[i][j]) return;
        int sum = 0, n = i;
        while(n){
            sum += n%10;
            n /= 10;
        }
        n = j;
        while(n){
            sum += n%10;
            n /= 10;
        }
        if(sum > m_k) return;

        m_visited[i][j] = true;
        m_ans++;

        for(auto p : m_index){
            dfs(i+p[0], j+p[1]);
        }

    }

    int leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof(int m, int n, int k) {

        m_row = m;
        m_col = n;
        m_k = k;
        m_ans = 0;
        if(m==0 || n == 0) return m_ans;
        vector<vector<bool>> visited(m_row, vector<bool>(m_col, false));
        m_visited = visited;
        dfs(0, 0);
        return m_ans;
    }
};

TEST(leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof, leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int m = 2, n = 3, k = 1;
    int ans = 3;
    EXPECT_EQ(s.leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof(m, n, k), ans);
}

TEST(leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof, leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof_2)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int m = 3, n = 1, k = 0;
    int ans = 1;
    EXPECT_EQ(s.leetcode_13_m_ji_qi_ren_de_yun_dong_fan_wei_lcof(m, n, k), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
