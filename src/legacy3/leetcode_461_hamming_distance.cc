/**
 * 
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hamming-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_461_hamming_distance(int x, int y) {

        int i = 0, cnt = 0;
        int n = 0;
        while( x!=0 || y != 0){
//            cout << " n " << n++ << " x " << x << " y " << y << " ans " << (x & y) << endl;
            cnt += 0x1 & (x ^ y);
            x = x >> 1;
            y = y >> 1;
        }
        return cnt;
    }
};

TEST(leetcode_461_hamming_distance, leetcode_461_hamming_distance_3)
{
    Solution s;
    int in1 = 0, in2 =pow(2, 31)-1;
    int ans = 31;
    EXPECT_EQ(s.leetcode_461_hamming_distance(in1, in2), ans);
}

TEST(leetcode_461_hamming_distance, leetcode_461_hamming_distance_2)
{
    Solution s;
    int in1 = 0, in2 =pow(2, 31)-1;
    int ans = 31;
    EXPECT_EQ(s.leetcode_461_hamming_distance(in1, in2), ans);
}

TEST(leetcode_461_hamming_distance, leetcode_461_hamming_distance_1)
{
    Solution s;
    int in1 = 1, in2 =4;
    int ans = 2;
    EXPECT_EQ(s.leetcode_461_hamming_distance(in1, in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
