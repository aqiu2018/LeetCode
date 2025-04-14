/**
给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    struct CmpByValue{
        bool operator()(int& lhs, int& rhs){
            return lhs < rhs;
        }
    };

    int leetcode_719_find_k_th_smallest_pair_distance(vector<int>& nums, int k) {

        int n = nums.size(), N = 1000000;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                cnt[abs(nums[i]-nums[j])]++;
            }
        }

        for (int l = 0; l < N; ++l) {
            if(cnt[l]>=k) return l;
            k-=cnt[l];
        }
        return -1;
        
//        int n  = nums.size();
//        priority_queue<int, vector<int>, less<int> > q;
////        priority_queue<int, vector<int>, CmpByValue > q;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i+1; j < n; ++j) {
//                int val = abs(nums[i]-nums[j]);
//                if(q.size()<k) q.push(val);
//                else if(val < q.top()){
//                    q.pop();
//                    q.push(val);
//                }
//            }
//        }
//
//
//        return q.size() == k ? q.top() : 0;
    }
};
TEST(leetcode_719_find_k_th_smallest_pair_distance, leetcode_719_find_k_th_smallest_pair_distance_2)
{
    Solution s;

    vector<int> in1 = {1, 3, 3,4,5};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int in3 = 2;
    int ans = 1;
    EXPECT_EQ(s.leetcode_719_find_k_th_smallest_pair_distance(in1, in3), ans);
}

TEST(leetcode_719_find_k_th_smallest_pair_distance, leetcode_719_find_k_th_smallest_pair_distance_1)
{
    Solution s;

    vector<int> in1 = {1, 1, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int in3 = 1;
    int ans = 0;
    EXPECT_EQ(s.leetcode_719_find_k_th_smallest_pair_distance(in1, in3), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
