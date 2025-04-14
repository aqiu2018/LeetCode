/**
 * 
有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。
paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。
另外，没有花园有 3 条以上的路径可以进入或者离开。
你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。

示例 1：
输入：N = 3, paths = [[1,2],[2,3],[3,1]]
输出：[1,2,3]

 示例 2：
输入：N = 4, paths = [[1,2],[3,4]]
输出：[1,2,1,2]

 示例 3：
输入：N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
输出：[1,2,3,4]
 
提示：
1 <= N <= 10000
0 <= paths.size <= 20000
不存在花园有 4 条或者更多路径可以进入或离开。
保证存在答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flower-planting-with-no-adjacent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_1042_flower_planting_with_no_adjacent(int N, vector<vector<int>>& paths) {

        vector<int> ans(N,0);
        sort(paths.begin(), paths.end());
        vector<vector<int>> graph(N);
        for (auto path : paths) {
            graph[path[0]-1].push_back(path[1]-1);
            graph[path[1]-1].push_back(path[0]-1);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < N; ++i) {
            set<int> flower{1,2,3,4};
            for (int j = 0; j < graph[i].size(); ++j) {
                flower.erase(ans[graph[i][j]]);
            }
            ans[i] = *(flower.begin());
        }

        return ans;
    }
};

TEST(leetcode_1042_flower_planting_with_no_adjacent, leetcode_1042_flower_planting_with_no_adjacent_1)
{
    Solution s;
    int N = 3;
    vector<vector<int>> in3 = {{1,2},{2,3},{1,3}};
    vector<int> ans2 = {1,2,3};

    EXPECT_EQ(s.leetcode_1042_flower_planting_with_no_adjacent(N, in3), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
