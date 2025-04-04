/**
 * 
有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)

输入: x = 3, y = 5, z = 4
输出: True
示例 2:

输入: x = 2, y = 6, z = 5
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/water-and-jug-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

using PII = pair<int, int>;

class Solution
{
public:
    bool leetcode_365_water_and_jug_problem(int x, int y, int z) {
//        mehod 1
//        if (x + y < z) return false;
//        if (x == 0 || y == 0) return z == 0 || x + y == z;
//        return z % gcd(x, y) == 0;

//        method 2
//        if (x + y < z) return false;
//        if (x == 0 || y == 0) return z == 0 || x + y == z;
//
//        if(y) while((x%=y) && (y%=x));
//        int n = x + y;
//        return z % n == 0;

//        https://www.bilibili.com/video/av35235691/?spm_id_from=333.788.videocard.3

//        method 3  用栈的，是dfs，若是bfs应该用队列
        stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());

            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            // 把 X 壶灌满。
            stk.emplace(x, remain_y);
            // 把 Y 壶灌满。
            stk.emplace(remain_x, y);
            // 把 X 壶倒空。
            stk.emplace(0, remain_y);
            // 把 Y 壶倒空。
            stk.emplace(remain_x, 0);
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
//        using 声明：2.5.1节，P60页；
//        auto：2.5.2节，P61；
//        decltype：2.5.3节，P62；
//        unordered_set：11.4节，P394；
//        hash 模板：11.4节，P396；
//        lambda 表达式：10.3.2节，P345；
//        emplace：9.3.1节，P308；

//        method 4
        if(x > y) swap(x, y);
        unordered_set<int> s;
        unordered_set<int> ss;
        bool stop = false;
        int sum = x;
        while(true){
            if(sum <= y) {
                if(s.find(sum) != s.end()) break;
                s.insert(sum);
                ss.insert(sum);
                ss.insert(sum+x);
                sum += x;
            }
            else {
                sum = sum % y;
            }

            if(s.find(z) != s.end()) return true;
        }

        if (ss.find(z) != ss.end()) return true;

        return false;




    }
};

TEST(leetcode_365_water_and_jug_problem, leetcode_365_water_and_jug_problem_1)
{
    Solution s;
    int in1 = 3, in2 = 5, in3 = 4;
    bool ans = true;
    EXPECT_EQ(s.leetcode_365_water_and_jug_problem(in1, in2, in3), ans);
}

TEST(leetcode_365_water_and_jug_problem, leetcode_365_water_and_jug_problem_2)
{
    Solution s;
    int in1 = 2, in2 = 6, in3 = 5;
    bool ans = false;
    EXPECT_EQ(s.leetcode_365_water_and_jug_problem(in1, in2, in3), ans);
}

TEST(leetcode_365_water_and_jug_problem, leetcode_365_water_and_jug_problem_3)
{
    Solution s;
    int in1 = 5, in2 = 3, in3 = 1;
    bool ans = true;
    EXPECT_EQ(s.leetcode_365_water_and_jug_problem(in1, in2, in3), ans);
}
TEST(leetcode_365_water_and_jug_problem, leetcode_365_water_and_jug_problem_4)
{
    Solution s;
    int in1 = 5, in2 = 5, in3 = 1;
    bool ans = false;
    EXPECT_EQ(s.leetcode_365_water_and_jug_problem(in1, in2, in3), ans);
}

TEST(leetcode_365_water_and_jug_problem, leetcode_365_water_and_jug_problem_5)
{
    Solution s;
    int in1 = 5, in2 = 3, in3 = 6;
    bool ans = true;
    EXPECT_EQ(s.leetcode_365_water_and_jug_problem(in1, in2, in3), ans);
}

TEST(leetcode_365_water_and_jug_problem, leetcode_365_water_and_jug_problem_6)
{
    Solution s;
    int in1 = 1, in2 = 2, in3 = 3;
    bool ans = true;
    EXPECT_EQ(s.leetcode_365_water_and_jug_problem(in1, in2, in3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
