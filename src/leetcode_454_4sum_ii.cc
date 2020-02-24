/**
 * 
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。

为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

输出:
2

解释:
两个元组如下:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_454_4sum_ii(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> mapSum;
        int rst=0;
        for (auto i : A) {
            for (auto j : B) {
                mapSum[i+j]++;
            }
        }

        for (auto i : C) {
            for (auto j : D) {
                int cd = - ( i + j );
                if(mapSum.find(cd) != mapSum.end())
                    rst += mapSum[cd];
            }
        }

        // cout << " rst " << rst << endl;

        return rst;
    }
};

TEST(leetcode_454_4sum_ii, leetcode_454_4sum_ii_1)
{
    Solution s;
    vector<int> A{1, 2};
    vector<int> B{-2,-1};
    vector<int> C{-1, 2};
    vector<int> D{0, 2};

    int ans = 2;
    EXPECT_EQ(s.leetcode_454_4sum_ii(A, B, C, D), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
