/**
 * 
 * Copyright (c) 2018
节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

示例1:
 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:
 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
提示：

节点数量n在[0, 1e5]范围内。
节点编号大于等于 0 小于 n。
图中可能存在自环和平行边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/route-between-nodes-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool helper(unordered_map<int, vector<int>>& m, int index, int target, vector<bool>& visited) {
        if (index == target) return true;
        if (visited[index] == true) return false;

        visited[index] = true;
        for (int i = 0; i < m[index].size(); i++) {
            if(helper(m, m[index][i], target, visited)) return true;
        }
        visited[index] = false;

        return false;
    }

    bool leetcode_04_01_m_route_between_nodes_lcci(int n, vector<vector<int>>& graph, int start, int target) {
        unordered_map<int, vector<int>> m;
        for (auto g : graph) {
            if (start == target && (g[0]==start || g[1]==start)) return true;
            if (g[0]==g[1]) continue;
            m[g[0]].push_back(g[1]);
        }
        vector<bool> visited(n, false);
        // return helper(m, start, target, visited);

        queue<int> s{{start}};
        while (!s.empty()) {
            int tmp = s.front();s.pop();
            if (tmp == target) return true;

            visited[tmp] = true;

            if (m.count(tmp) == 0) continue;

            for (auto c : m[tmp]) {
                if (visited[c] == false){
                    s.push(c);
                }
            }
        }
        return false;
    }
};

TEST(leetcode_04_01_m_route_between_nodes_lcci, leetcode_04_01_m_route_between_nodes_lcci_2)
{
    Solution s;
    int n = 3;
    int start = 0;
    int target = 2;
    vector<vector<int>> graph = {{0,1},{0,1},{1,2}};
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_04_01_m_route_between_nodes_lcci(n, graph, start, target), ans2);

}
TEST(leetcode_04_01_m_route_between_nodes_lcci, leetcode_04_01_m_route_between_nodes_lcci_1)
{
    Solution s;
    int n = 3;
    int start = 0;
    int target = 2;
    vector<vector<int>> graph = {{0,1},{0,2},{1,2},{1,2}};
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_04_01_m_route_between_nodes_lcci(n, graph, start, target), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
