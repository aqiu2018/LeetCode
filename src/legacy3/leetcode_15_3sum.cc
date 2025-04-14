/**
 * 
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<vector<int>> leetcode_15_3sum(vector<int>& nums) {

        set<vector<int>> sumSet;
        sort(nums.begin(), nums.end());


        for (int i = 0; i < nums.size(); ++i) {
            int l =0, r = nums.size()-1;
            while(l<r){
                if(l==i || r ==i) break;
                if(nums[i]+nums[l]+nums[r]==0){
                    sumSet.insert(vector<int>{nums[l++],nums[i],nums[r--]});
                }else if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }else{
                    r--;
                }

            }
        }

        return vector<vector<int>>(sumSet.begin(), sumSet.end());

//        set<vector<int>> sumSet;
//        unordered_multimap<int, vector<int>> sumMap;
//
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); ++i) {
//            int j = i+1;
//            while(j < nums.size()){
//                sumMap.insert(std::pair<int, vector<int>>(nums[i]+nums[j], vector<int>{i, j}));
//                j++;
//            }
//        }
//
//        for (int k = 0; k < nums.size(); ++k) {
//            for (auto it = sumMap.find(-nums[k]); it != sumMap.end(); ) {
//
//                if(k == it->second[0] || k == it->second[1]) ;
//                else if(k < it->second[0])
//                    sumSet.insert(vector<int>{nums[k], nums[it->second[0]], nums[it->second[1]]});
//                else if(k > it->second[1])
//                    sumSet.insert(vector<int>{nums[it->second[0]], nums[it->second[1]], nums[k]});
//                else
//                    sumSet.insert(vector<int>{nums[it->second[0]], nums[k], nums[it->second[1]]});
//
//
//                sumMap.erase(it);
//                it = sumMap.find(-nums[k]);
//            }
//        }
//
//        vector<vector<int>> res(sumSet.begin(), sumSet.end());
//
//        return res;
    }
};

TEST(leetcode_15_3sum, leetcode_15_3sum_1)
{
    Solution s;
    vector<int> in = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans.push_back(vector<int>{-1, -1, 2});
    ans.push_back(vector<int>{-1, 0, 1});

    EXPECT_EQ(s.leetcode_15_3sum(in), ans);
}

TEST(leetcode_15_3sum, leetcode_15_3sum_2)
{
    Solution s;
    vector<int> in = {-1, 0};
    vector<vector<int>> ans;

    EXPECT_EQ(s.leetcode_15_3sum(in), ans);
}

TEST(leetcode_15_3sum, leetcode_15_3sum_3)
{
    Solution s;
    vector<int> in = {-2, 0, 1, 1, 2};
    vector<vector<int>> ans;
    ans.push_back(vector<int>{-2, 0, 2});
    ans.push_back(vector<int>{-2, 1, 1});

    EXPECT_EQ(s.leetcode_15_3sum(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
