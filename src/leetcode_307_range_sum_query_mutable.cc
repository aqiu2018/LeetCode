/**
 * 
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
说明:

数组仅可以在 update 函数下进行修改。
你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class NumArray {
public:
    vector<int> m_nums;
    vector<int> m_tree;
    void buildTree(int start, int end, int node){
        if(start == end) {
            m_tree[node] = m_nums[start];
            return;
        }

        int mid = (start + end)/2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        buildTree(start, mid, left_node);
        buildTree(mid + 1, end, right_node);
        m_tree[node] = m_tree[left_node] + m_tree[right_node];
    }

    NumArray(vector<int>& nums) {
        assert(nums.size()>0);

        int nodeCnt = 2;
        while(nodeCnt < nums.size()){
            nodeCnt *= 2;
        }
        nodeCnt *= 2;
        // cout << " nodeCnt " << nodeCnt  << "  size " << nums.size()<< endl;

        m_nums = nums;
        m_tree.resize(nodeCnt, 0);
        buildTree(0, nums.size()-1, 0);

        for (int i = 0; i < m_tree.size(); ++i) {
            cout<< "1 i " << m_tree[i] << endl;
        }

        update(4, 6);
        for (int i = 0; i < m_tree.size(); ++i) {
            cout<< "2 i " << m_tree[i] << endl;
        }

        int sum = sumRange(2, 5);
        cout<< "3 sum " <<sum << endl;
    }

    void updateTree(int start, int end, int node, int id, int value){

        if(start==end){
            m_nums[id] = value;
            m_tree[node] = value;
            return;
        }
        int mid = (start + end)/2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        if(id>=start && id <= mid)  {
            updateTree(start, mid, left_node, id, value);
        }else{
            updateTree(mid+1, end, right_node, id, value);
        }
        m_tree[node] = m_tree[left_node] + m_tree[right_node];
    }
    void update(int i, int val) {
        updateTree(0, m_nums.size()-1, 0, i, val);
    }

    int queryTree(int start, int end, int node, int l, int r){

        if(r < start || end < l){
            return  0;
        }
        else if(start == end || (l<=start && end<=r)) {
            return m_tree[node];
        }

        int mid = (start + end)/2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int left_sum= queryTree(start, mid, left_node, l, r);
        int right_sum = queryTree(mid+1, end, right_node, l, r);
        return  left_sum + right_sum;
    }
    int sumRange(int i, int j) {
        return queryTree(0, m_nums.size()-1, 0, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

class Solution
{
public:
    int leetcode_307_range_sum_query_mutable(vector<int> &nums) {
        NumArray* obj = new NumArray(nums);

        return 1;
    }
};

TEST(leetcode_307_range_sum_query_mutable, leetcode_307_range_sum_query_mutable_1)
{
    Solution s;
    vector<int> in1 = {1, 3, 5, 7, 9, 11};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_307_range_sum_query_mutable(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
