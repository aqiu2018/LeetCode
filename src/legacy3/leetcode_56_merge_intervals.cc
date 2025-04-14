/**
 * 
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:

    int m_row, m_col;

    int Partition(vector<vector<int>> &intervals, int low, int high) {

        int pivot = intervals[high].front();
        int l = low;
        for (int i = l; i < high; ++i) {
            if(intervals[i].front() < pivot){
                swap(intervals[i], intervals[l++]);
            }
        }

        swap(intervals[l], intervals[high]);
        return l;
    }

    void QuickSort(vector<vector<int>>& intervals, int low, int high){
        if(low<high){
            int pivot = Partition(intervals, low, high);
            QuickSort(intervals, low, pivot-1);
            QuickSort(intervals, pivot+1, high);
        }
    }

    vector<vector<int>> leetcode_56_merge_intervals(vector<vector<int>>& intervals) {

//        m_row = intervals.size();
//        if(m_row == 0 || m_row == 1) return intervals;
//        m_col = intervals.front().size();
//
////        QuickSort(intervals, 0, m_row-1);
//        sort(intervals.begin(), intervals.end(),
//                [](vector<int> &a, vector<int> &b){return a.front() < b.front();});
//
//        vector<vector<int>> ans;
//        int minValue = intervals[0].front(), maxValue = intervals[0].back();
//        for (int i = 0; i < m_row-1; ++i) {
//            if(maxValue < intervals[i+1].front()) {
//                ans.push_back({minValue, maxValue});
//
//                minValue = intervals[i+1].front();
//                maxValue = intervals[i+1].back();
//                continue;
//            }
//            minValue = min(minValue, intervals[i+1].front());
//            maxValue = max(maxValue, intervals[i+1].back());
//        }
//
//        if(ans.empty() || ans.back() != vector<int>{minValue, maxValue}) ans.push_back({minValue, maxValue});
//

        if(intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b){return a.front() < b.front();});

        vector<vector<int>> ans{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            if(ans.back().back() < intervals[i].front()) ans.push_back(intervals[i]);
            else ans.back().back() = max(ans.back().back(), intervals[i].back());
        }

        return ans;
    }
};

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_5)
{
    Solution s;
    vector<vector<int>> in = {{2,4}, {4,5}};
    vector<vector<int>> ans = {{2,5}};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_6)
{
    Solution s;
    vector<vector<int>> in = {{2,4}, {1,3},{5,6},{6,6}};
    vector<vector<int>> ans = {{1,4},{5,6}};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_7)
{
    Solution s;
    vector<vector<int>> in = {{2,4}, {1,3},{5,6},{7,7}};
    vector<vector<int>> ans = {{1,4},{5,6},{7,7}};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_8)
{
    Solution s;
    vector<vector<int>> in = {};
    vector<vector<int>> ans = {};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_9)
{
    Solution s;
    vector<vector<int>> in = {{1,3}};
    vector<vector<int>> ans = {{1,3}};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_10)
{
    Solution s;
    vector<vector<int>> in = {{2,4}, {1,3},{5,6}};
    vector<vector<int>> ans = {{1,4},{5,6}};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

TEST(leetcode_56_merge_intervals, leetcode_56_merge_intervals_20)
{
    Solution s;
    vector<vector<int>> in = {{1,3},{5,6}};
    vector<vector<int>> ans = {{1,3},{5,6}};
    EXPECT_EQ(s.leetcode_56_merge_intervals(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
