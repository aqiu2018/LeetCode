/**
 * 
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]
进阶:

给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
要求算法的空间复杂度为O(n)。
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/counting-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_338_counting_bits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; ++i) {
            int x = i;
            int cnt = 0;
            while(x){
                x = x & (x-1);
                cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;

        vector<int> ans1;
        for (int i = 0; i <= num; ++i) {
            ans1[i] += ans1[i&(i-1)]+1;
        }

        return ans1;
    }
};

TEST(leetcode_338_counting_bits, leetcode_338_counting_bits_1)
{
    Solution s;
    int in1 = 2;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    vector<int> ans = {0,1,1};
    EXPECT_EQ(s.leetcode_338_counting_bits(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
