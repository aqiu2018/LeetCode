/**
 * 
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    bool leetcode_202_happy_number(int n) {
        long sum = 0;
        unordered_set<long> s{n};
        int result = 0;
        while (true) {
            sum = 0;
            while(n != 0) {
                result = n%10;
                n = n/10;
                sum += result * result;
            }
            if (sum == 1) return true;
            if (s.count(sum)) return false;
            s.insert(sum);
            n = sum;
        }
    }
};

TEST(leetcode_202_happy_number, leetcode_202_happy_number_3)
{
    Solution s;
    int in2 = 0;
    bool ans2 = false;
    EXPECT_EQ(s.leetcode_202_happy_number(in2), ans2);
}

TEST(leetcode_202_happy_number, leetcode_202_happy_number_2)
{
    Solution s;
    int in2 = 2;
    bool ans2 = false;
    EXPECT_EQ(s.leetcode_202_happy_number(in2), ans2);
}

TEST(leetcode_202_happy_number, leetcode_202_happy_number_1)
{
    Solution s;
    int in2 = 19;
    bool ans2 = true;
    EXPECT_EQ(s.leetcode_202_happy_number(in2), ans2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
