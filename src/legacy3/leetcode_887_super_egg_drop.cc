/**
你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
你的目标是确切地知道 F 的值是多少。
无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

示例 1：
输入：K = 1, N = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
如果它没碎，那么我们肯定知道 F = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。

示例 2：
输入：K = 2, N = 6
输出：3

 示例 3：
输入：K = 3, N = 14
输出：4

 来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/super-egg-drop
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_887_super_egg_drop(int K, int N) {

        //dp[i][j] 表示的是在第i次移动且使用第j个鸡蛋测试第 dp[i-1][j-1]+1 层
        vector<vector<int>> dp(N + 1, vector<int>(K + 1));
        int m = 0;
        while (dp[m][K] < N) {
            ++m;
            for (int j = 1; j <= K; ++j) {
                dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
            }
        }
        return m;

        // dp[i][j] 表示有i个鸡蛋，j层楼要测需要的最小操作数
//        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
//        for (int j = 1; j <= N; ++j) dp[1][j] = j;
//
//        for (int i = 2; i <= K; ++i) {
//            for (int j = 1; j <= N; ++j) {
//                dp[i][j] = j;
//                for (int k = 1; k < j; ++k) {
//                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
//                }
//            }
//        }
//        return dp[K][N];

//        if(K==1) return N;
//
//        int ans = 0;
//
//        int n = N;
//        bool isPowOf2 = true;
//        int cnt = 0;
//        while(n){
//            cout << " n " << n << endl;
//            if((n&0x1) == 1) cnt++;
//            if(cnt > 1) {
//                isPowOf2 = false;
//                break;
//            }
//            n=n>>1;
//        }
//        int maxDepth = log(N) / log(2)+1;
//        cout << "N " << N << " log N " << log(N) << " log(2) "
//        << log(2) << " maxDepth " << maxDepth
//        <<" isPowOf2 " << isPowOf2 << endl;
//        if(isPowOf2) return maxDepth;
//
//        if(K >= maxDepth) return maxDepth;
//
//        int mid = N;
//        while(true){
//            if(K==1) return ans + mid - 1;
//            K--;
//            ans++;
//            cout << "before " << mid << endl;
//            int x = (K == 1 && ans == 1)? mid % 2 : 0;
//            mid = mid/2 + x;
//            cout << "after " << mid << endl;
//        }
    }
};

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_12)
{
    Solution s;
    int in1 = 2, in2 = 9;
    int ans = 4;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_11)
{
    Solution s;
    int in1 = 3, in2 = 8;
    int ans = 4;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}


TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_10)
{
    Solution s;
    int in1 = 2, in2 = 4;
    int ans = 3;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}


TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_1)
{
    Solution s;
    int in1 = 2, in2 = 6;
    int ans = 3;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_2)
{
    Solution s;
    int in1 = 2, in2 = 2;
    int ans = 2;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_3)
{
    Solution s;
    int in1 = 3, in2 = 3;
    int ans = 2;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_7)
{
    Solution s;
    int in1 = 2, in2 = 7;
    int ans = 4;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_8)
{
    Solution s;
    int in1 = 1, in2 = 2;
    int ans = 2;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

TEST(leetcode_887_super_egg_drop, leetcode_887_super_egg_drop_9)
{
    Solution s;
    int in1 = 3, in2 = 14;
    int ans = 4;
    EXPECT_EQ(s.leetcode_887_super_egg_drop(in1, in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
