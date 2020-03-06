/**
 * 
给定两个以升序排列的整形数组 nums1 和 nums2, 以及一个整数 k。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2。

找到和最小的 k 对数字 (u1,v1), (u2,v2) ... (uk,vk)。

示例 1:

输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
输出: [1,2],[1,4],[1,6]
解释: 返回序列中的前 3 对数：
     [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
示例 2:

输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
输出: [1,1],[1,1]
解释: 返回序列中的前 2 对数：
     [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
示例 3:

输入: nums1 = [1,2], nums2 = [3], k = 3
输出: [1,3],[2,3]
解释: 也可能序列中所有的数对都被返回:[1,3],[2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    struct CmpByValue{
        bool operator()(pair<int, pair<int, int>> &k1, pair<int, pair<int, int>> &k2){
            return k1.first+k1.second.first > k2.first+k2.second.first;
        }
    };
    vector<vector<int>> leetcode_373_find_k_pairs_with_smallest_sums(vector<int>& nums1, vector<int>& nums2, int k){

        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> ans;
        if(len1==0 || len2 == 0) return ans;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CmpByValue> q;
        for (int i = 0; i < len1; ++i) {
            q.push(pair<int, pair<int, int>>(nums1[i], pair<int, int>(nums2[0], 0)));
        }

        for (int j = 0; j < k && !q.empty(); ++j) {
            auto t = q.top();
            q.pop();
            ans.push_back(vector<int>{t.first, t.second.first});

            if(t.second.second < len2 - 1 ){
                t.second.first = nums2[++t.second.second];
                q.push(t);
            }
        }

        return ans;
    }
};

TEST(leetcode_373_find_k_pairs_with_smallest_sums, leetcode_373_find_k_pairs_with_smallest_sums_1)
{
    Solution s;
    vector<int> in1 = {1, 7, 11};
    vector<int> in2 = {2, 4, 6};
    vector<vector<int>> ans;
    ans.push_back(vector<int>{1, 2});
    ans.push_back(vector<int>{1, 4});
    ans.push_back(vector<int>{1, 6});
    EXPECT_EQ(s.leetcode_373_find_k_pairs_with_smallest_sums(in1, in2, 3), ans);
}

//TEST(leetcode_373_find_k_pairs_with_smallest_sums, leetcode_373_find_k_pairs_with_smallest_sums_2)
//{
//    Solution s;
//    vector<int> in1 = {1, 2, 3};
//    vector<int> in2 = {1, 2, 3};
//    vector<vector<int>> ans;
//    ans.push_back(vector<int>{1, 2});
//    ans.push_back(vector<int>{1, 4});
//    ans.push_back(vector<int>{1, 6});
//    EXPECT_EQ(s.leetcode_373_find_k_pairs_with_smallest_sums(in1, in2, 3), ans);
//}

TEST(leetcode_373_find_k_pairs_with_smallest_sums, leetcode_373_find_k_pairs_with_smallest_sums_3)
{
    Solution s;
    vector<int> in1 = {1, 1, 2};
    vector<int> in2 = {1, 2, 3};
    vector<vector<int>> ans;
    ans.push_back(vector<int>{1, 1});
    ans.push_back(vector<int>{1, 1});
    ans.push_back(vector<int>{2, 1});
    ans.push_back(vector<int>{1, 2});
    ans.push_back(vector<int>{1, 2});
    ans.push_back(vector<int>{2, 2});
    ans.push_back(vector<int>{1, 3});
    ans.push_back(vector<int>{1, 3});
    ans.push_back(vector<int>{2, 3});
    EXPECT_EQ(s.leetcode_373_find_k_pairs_with_smallest_sums(in1, in2, 9), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
