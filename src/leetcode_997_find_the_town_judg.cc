/**
 * 
在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。

如果小镇的法官真的存在，那么：

小镇的法官不相信任何人。
每个人（除了小镇法官外）都信任小镇的法官。
只有一个人同时满足属性 1 和属性 2 。
给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。

如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。

 

示例 1：

输入：N = 2, trust = [[1,2]]
输出：2
示例 2：

输入：N = 3, trust = [[1,3],[2,3]]
输出：3
示例 3：

输入：N = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1
示例 4：

输入：N = 3, trust = [[1,2],[2,3]]
输出：-1
示例 5：

输入：N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
输出：3
 

提示：

1 <= N <= 1000
trust.length <= 10000
trust[i] 是完全不同的
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-town-judge
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_997_find_the_town_judg(int N, vector<vector<int>>& trust) {
        if(trust.size()==0) return N;

        unordered_map<int, pair<int, int>> m; // id, <follower, followee>
        for (auto t : trust) {
            if (m.count(t[0]) == 0) m[t[0]] = make_pair(1, 0);
            else  m[t[0]].first++;

            if (m.count(t[1]) == 0)  m[t[1]] = make_pair(0, 1);
            else m[t[1]].second++;
        }

        int cnt = 0;
        int ans = -1;
        for (auto mIt : m) {
            if (mIt.second.second == N-1 && mIt.second.first == 0) {
                cnt++;
                ans = mIt.first;
            }
        }
        return cnt==1?ans:-1;
    }
};
TEST(leetcode_997_find_the_town_judg, leetcode_997_find_the_town_judg_6)
{
    Solution s;
    vector<vector<int>> in3 = {};
    int N = 1;
    int ans2 = 1;
    EXPECT_EQ(s.leetcode_997_find_the_town_judg(N, in3), ans2);

}
TEST(leetcode_997_find_the_town_judg, leetcode_997_find_the_town_judg_5)
{
    Solution s;
    vector<vector<int>> in3 = {{2,3},{1,3},{1,4},{2,4},{4,3}};
    int N = 4;
    int ans2 = 3;
    EXPECT_EQ(s.leetcode_997_find_the_town_judg(N, in3), ans2);

}
TEST(leetcode_997_find_the_town_judg, leetcode_997_find_the_town_judg_4)
{
    Solution s;
    vector<vector<int>> in3 = {{2,3},{1,2}};
    int N = 3;
    int ans2 = -1;
    EXPECT_EQ(s.leetcode_997_find_the_town_judg(N, in3), ans2);

}

TEST(leetcode_997_find_the_town_judg, leetcode_997_find_the_town_judg_3)
{
    Solution s;
    vector<vector<int>> in3 = {{2,3},{1,3},{3,1}};
    int N = 3;
    int ans2 = -1;
    EXPECT_EQ(s.leetcode_997_find_the_town_judg(N, in3), ans2);

}

TEST(leetcode_997_find_the_town_judg, leetcode_997_find_the_town_judg_2)
{
    Solution s;
    vector<vector<int>> in3 = {{2,3},{1,3}};
    int N = 3;
    int ans2 = 3;
    EXPECT_EQ(s.leetcode_997_find_the_town_judg(N, in3), ans2);

}

TEST(leetcode_997_find_the_town_judg, leetcode_997_find_the_town_judg_1)
{
    Solution s;
    vector<vector<int>> in3 = {{1,2}};
    int N = 2;
    int ans2 = 2;
    EXPECT_EQ(s.leetcode_997_find_the_town_judg(N, in3), ans2);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
