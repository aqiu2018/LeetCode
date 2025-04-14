/**
 * 
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [3,2,3]
输出: 3

示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    int leetcode_169_majority_element(vector<int> &nums)
    {
        cout << "qzc " << nums.size()/2 << " " << floor(nums.size()/2) << endl;
        int rst = nums[0], cnt = 0;

//        unordered_map<int, int> mapTable;
//        for (int i = 0; i < nums.size(); ++i){
//            if(mapTable.find(nums[i]) != mapTable.end()) {
//                mapTable[nums[i]] ++;
//                if(mapTable[nums[i]] > floor(nums.size()/2)) rst = nums[i];
//            }
//            else mapTable[nums[i]] = 1;
//        }

        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == rst) cnt++;
            else cnt--;

            if(cnt <= 0) rst = nums[j+1];
        }

        return rst;
    }
};

TEST(leetcode_169_majority_element, leetcode_169_majority_element_1)
{
    Solution s;
    vector<int> in = {3,2,3};
    int ans = 3;
    EXPECT_EQ(s.leetcode_169_majority_element(in), ans);
}

TEST(leetcode_169_majority_element, leetcode_169_majority_element_2)
{
    Solution s;
    vector<int> in = {2,2,1,1,1,2,2};
    int ans = 2;
    EXPECT_EQ(s.leetcode_169_majority_element(in), ans);
}

TEST(leetcode_169_majority_element, leetcode_169_majority_element_3)
{
    Solution s;
    vector<int> in = {3,3,4};
    int ans = 3;
    EXPECT_EQ(s.leetcode_169_majority_element(in), ans);
}

TEST(leetcode_169_majority_element, leetcode_169_majority_element_4)
{
    Solution s;
    vector<int> in = {3};
    int ans = 3;
    EXPECT_EQ(s.leetcode_169_majority_element(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
