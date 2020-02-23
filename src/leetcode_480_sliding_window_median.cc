/**
 *
中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是 3

[2,3]，中位数是 (2 + 3) / 2 = 2.5

给出一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

 

示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

 

提示：

你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-median
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 **/

#include "headers.h"

class Solution
{
public:

    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        int ret = low;
        for (int i = low; i < high; ++i) {
            if(nums[i] < pivot){
                swap(nums[i], nums[ret]);
                ret++;
            }
        }
        swap(nums[ret], nums[high]);
        return ret;
    }

    void quickSort(vector<int>& nums, int low, int high){
        if(low < high){
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot-1);
            quickSort(nums, pivot+1, high);
        }
    }

    vector<double> leetcode_480_sliding_window_median(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.begin()+k-1);
//        quickSort(nums,0,k-1);

        vector<double> rst;
        if(k == 0) return rst;

        multimap<int, int> mapKey;
        for (int l = 0; l < k; ++l) {
            mapKey.insert(pair<int, int>(nums[l], l));
        }

        auto mid = next(mapKey.begin(), k/2);;
        for (int j = 0; j < nums.size() - k + 1; ++j) {
            double first = (double(next(mid, k%2-1)->first) + double(mid->first))/2;
            rst.push_back(first);

            if (j + k < nums.size()) mapKey.insert(pair<int, int>(nums[j+k], j+k));
            else break;

            if(nums[j+k] < mid->first) mid--;
            if(nums[j] <= mid->first) mid++;

            mapKey.erase(mapKey.lower_bound(nums[j]));
        }

        return rst;
    }
};

TEST(leetcode_480_sliding_window_median, leetcode_480_sliding_window_median_0)
{
    Solution s;
    vector<int> in = {1,4,2,3};
    vector<double>ans = {2.5};
    EXPECT_EQ(s.leetcode_480_sliding_window_median(in, 4), ans);
}

TEST(leetcode_480_sliding_window_median, leetcode_480_sliding_window_median_1)
{
    Solution s;
    vector<int> in = {1,3,-1,-3,5,3,6,7};
    vector<double>ans = {1,-1,-1,3,5,6};
    EXPECT_EQ(s.leetcode_480_sliding_window_median(in, 3), ans);
}

TEST(leetcode_480_sliding_window_median, leetcode_480_sliding_window_median_2)
{
    Solution s;
    vector<int> in = {1,3,-1};
    vector<double>ans = {2, 1};
    EXPECT_EQ(s.leetcode_480_sliding_window_median(in, 2), ans);
}

TEST(leetcode_480_sliding_window_median, leetcode_480_sliding_window_median_3)
{
    Solution s;
    vector<int> in = {1,3};
    vector<double>ans = {2};
    EXPECT_EQ(s.leetcode_480_sliding_window_median(in, 2), ans);
}

TEST(leetcode_480_sliding_window_median, leetcode_480_sliding_window_median_4)
{
    Solution s;
    vector<int> in = {1};
    vector<double>ans = {1};
    EXPECT_EQ(s.leetcode_480_sliding_window_median(in, 1), ans);
}


TEST(leetcode_480_sliding_window_median, leetcode_480_sliding_window_median_5)
{
    Solution s;
    vector<int> in = {1};
    vector<double>ans = {};
    EXPECT_EQ(s.leetcode_480_sliding_window_median(in, 0), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}