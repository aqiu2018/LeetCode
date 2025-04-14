/**
 * 
给你一个整数数组 arr 和一个整数 difference，请你找出 arr 中所有相邻元素之间的差等于给定 difference 的等差子序列，并返回其中最长的等差子序列的长度。

 

示例 1：

输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。
示例 2：

输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。
示例 3：

输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。
 

提示：

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_1218_longest_arithmetic_subsequence_of_given_difference(vector<int>& arr, int difference) {

        log(INFO_) << "values are \n";
        copy(arr.begin(), arr.end(), log(" "));
        log() << endl;

        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); ++i) {
//            cout << "i " << i << " arr " << arr[i] << endl;
            if(m.count(arr[i]-difference) != 0) {
                m[arr[i]] = max(m[arr[i]], m[arr[i]-difference]+1);
            }
            else if(m.count(arr[i]) == 0) m[arr[i]] = 1;
//            else m[arr[i]] = max(m[arr[i]], m[arr[i]-difference]+1);

            ans = max(ans, m[arr[i]]);
        }

        return ans;
    }
};

TEST(leetcode_1218_longest_arithmetic_subsequence_of_given_difference, leetcode_1218_longest_arithmetic_subsequence_of_given_difference_5)
{
    Solution s;
    vector<int> in1 = {1};
    int difference = -2;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_1218_longest_arithmetic_subsequence_of_given_difference(in1, difference), ans);
}

TEST(leetcode_1218_longest_arithmetic_subsequence_of_given_difference, leetcode_1218_longest_arithmetic_subsequence_of_given_difference_4)
{
    Solution s;
    vector<int> in1 = {1,5,5,4,7,8,6,5,4,3,2,0,1,-2};
    int difference = -2;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 6;
    EXPECT_EQ(s.leetcode_1218_longest_arithmetic_subsequence_of_given_difference(in1, difference), ans);
}

TEST(leetcode_1218_longest_arithmetic_subsequence_of_given_difference, leetcode_1218_longest_arithmetic_subsequence_of_given_difference_3)
{
    Solution s;
    vector<int> in1 = {1,5,7,8,5,3,4,2,1};
    int difference = -2;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_1218_longest_arithmetic_subsequence_of_given_difference(in1, difference), ans);
}
TEST(leetcode_1218_longest_arithmetic_subsequence_of_given_difference, leetcode_1218_longest_arithmetic_subsequence_of_given_difference_2)
{
    Solution s;
    vector<int> in1 = {1,3,5,7};
    int difference = 1;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_1218_longest_arithmetic_subsequence_of_given_difference(in1, difference), ans);
}

TEST(leetcode_1218_longest_arithmetic_subsequence_of_given_difference, leetcode_1218_longest_arithmetic_subsequence_of_given_difference_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3, 4};
    int difference = 1;
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 4;
    EXPECT_EQ(s.leetcode_1218_longest_arithmetic_subsequence_of_given_difference(in1, difference), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
