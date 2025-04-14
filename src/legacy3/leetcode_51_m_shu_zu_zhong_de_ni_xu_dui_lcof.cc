/**
 * 
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5
限制：
0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class BIT{
public:
    BIT(int n) : m_sum(n+1, 0) {}

    void Update(int i, int val) {
        while (i<m_sum.size()) {
            m_sum[i] += val;
            i += lowbit(i);
        }
    }

    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += m_sum[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    vector<int> m_sum;
    static inline int lowbit(int i) {return i&(-i);}
};

class Solution
{
public:
    int m_ans = 0;
    void Merge(vector<int>& nums, int left, int pivot, int right) {
        int n = right - left + 1; //储存元素总个数
        vector<int> tmp(n);
        int i = 0, l = left, r = pivot+1;

        while(l <= pivot && r <= right){
            // tmp[i++] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
            if (nums[l] <= nums[r]) {
                tmp[i++] = nums[l++];
                m_ans += (r-(pivot+1));
            }else {
                tmp[i++] = nums[r++];
            }
        }

        while(l <= pivot){
            tmp[i++] = nums[l++];
            m_ans += (r-(pivot+1));
        }

        while(r <= right){
            tmp[i++] = nums[r++];
        }

        for (int j = 0; j < n; ++j) {
            nums[left+j] = tmp[j];
        }
    }

    void MergeSort(vector<int>& nums, int left, int right){
        if(left < right){
            int pivot = left + (right - left)/2;
            MergeSort(nums, left, pivot);
            MergeSort(nums, pivot+1, right);
            Merge(nums, left, pivot, right);
        }
    }

    int leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof(vector<int>& nums) {
        // 1 merge sort
        // MergeSort(nums, 0, nums.size()-1 );

        // 2 BIT
        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int rank = 0;
        for (auto n : sorted) {
            ranks[n] = ++rank;
        }
        BIT tree(nums.size());

        for (int i = nums.size()-1; i >= 0; --i) {
            m_ans += tree.query(ranks[nums[i]] - 1);
            tree.Update(ranks[nums[i]], 1);
        }
        
        return m_ans;
    }
};
TEST(leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof, leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof_2)
{
    Solution s;
    vector<int> in2 = {1,3,2,3,1};
    int ans2 = 4;
    EXPECT_EQ(s.leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof(in2), ans2);
}

TEST(leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof, leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof_1)
{
    Solution s;
    vector<int> in2 = {7,5,6,4};
    int ans2 = 5;
    EXPECT_EQ(s.leetcode_51_m_shu_zu_zhong_de_ni_xu_dui_lcof(in2), ans2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
