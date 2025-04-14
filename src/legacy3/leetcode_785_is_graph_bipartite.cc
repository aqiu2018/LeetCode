/**
 * 
给定一个无向图graph，当这个图为二分图时返回true。
如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。

示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释:
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释:
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。
注意:

graph 的长度范围为 [1, 100]。
graph[i] 中的元素的范围为 [0, graph.length - 1]。
graph[i] 不会包含 i 或者有重复的值。
图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-graph-bipartite
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool helper(vector<vector<int>>& graph, vector<int>& cols, int ind, int color) {
        cols[ind] = color;

        for (auto index : graph[ind]) {
            if (cols[index] == cols[ind]) return false;
            if (cols[index] == 0 && !helper(graph, cols, index, -1*color)) return false;
        }

        return true;
    }

    bool leetcode_785_is_graph_bipartite(vector<vector<int>>& graph) {

        int N = graph.size();
        vector<int> cols(N, 0);
        for (int i = 0; i < graph.size(); ++i) {
            if (cols[i] == 0 && !helper(graph, cols, i, -1)) return false;
        }
        return true;
    }

};

TEST(leetcode_785_is_graph_bipartite, leetcode_785_is_graph_bipartite_6)
{
    Solution s;
    vector<vector<int>> in3 = {{}, {2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    bool ans2 = false;
    EXPECT_EQ(s.leetcode_785_is_graph_bipartite(in3), ans2);
}

TEST(leetcode_785_is_graph_bipartite, leetcode_785_is_graph_bipartite_5)
{
    Solution s;
    vector<vector<int>> in3 = {{}, {2,4}};
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_785_is_graph_bipartite(in3), ans2);
}

TEST(leetcode_785_is_graph_bipartite, leetcode_785_is_graph_bipartite_4)
{
    Solution s;
    vector<vector<int>> in3 = {{3}, {2,4}, {1},{0,4}, {1,3}};
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_785_is_graph_bipartite(in3), ans2);

}

TEST(leetcode_785_is_graph_bipartite, leetcode_785_is_graph_bipartite_3)
{
    Solution s;
    vector<vector<int>> in3 = {{1}, {0,3}, {3}, {1,2}};
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_785_is_graph_bipartite(in3), ans2);

}

TEST(leetcode_785_is_graph_bipartite, leetcode_785_is_graph_bipartite_2)
{
    Solution s;
    vector<vector<int>> in3 = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    bool ans2 = false;
    EXPECT_EQ(s.leetcode_785_is_graph_bipartite(in3), ans2);

}

TEST(leetcode_785_is_graph_bipartite, leetcode_785_is_graph_bipartite_1)
{
    Solution s;
    vector<vector<int>> in3 = {{1,3}, {0,2}, {1,3}, {0,2}};
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_785_is_graph_bipartite(in3), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
