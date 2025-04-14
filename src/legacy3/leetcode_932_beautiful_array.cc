/**
 * 
 * Copyright (c) 2018
 * 
 * @file
 * @author   qzc (1457615966@qq.com)
 * @date     2019-11
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-11-20
 * Modified By:    qzc (1457615966@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
public:
    map<int, vector<int>> oddEvenCaches{
            {1, {1}},
            {2, {1, 2}},
            {3, {3, 1, 2}},
            {4, {2, 1, 4, 3}},
            {5, {3, 1, 2, 5, 4}},
    };

    vector<int> leetcode_932_beautiful_array(int N) {
//        if(oddEvenCaches.count(N) != 0) return oddEvenCaches[N];
//
//        vector<int> ans{};
//        vector<int> oddNum = leetcode_932_beautiful_array((N+1)/2);
//        vector<int> evenNum = leetcode_932_beautiful_array(N/2);
//
//        for(auto v: oddNum) ans.push_back(v*2-1);
//        for(auto v: evenNum) ans.push_back(v*2);
//
//        return ans;


        vector<int> res{1};
        while (res.size() < N) {
            vector<int> t;
            for (int num : res) {
                if (num * 2 - 1 <= N) t.push_back(num * 2 - 1);
            }
            for (int num : res) {
                if (num * 2 <= N) t.push_back(num * 2);
            }
            res = t;
        }
        return res;
    }
};

TEST(leetcode_932_beautiful_array, leetcode_932_beautiful_array_3)
{
    Solution s;
    int in1 = 5;
    vector<int> ans {3,1,2,5,4};
    EXPECT_EQ(s.leetcode_932_beautiful_array(in1), ans);
}
TEST(leetcode_932_beautiful_array, leetcode_932_beautiful_array_2)
{
    Solution s;
    int in1 = 100;
    vector<int> ans {1,65,33,97,17,81,49,9,73,41,25,89,57,5,69,37,21,85,53,13,77,45,29,93,61,3,67,35,99,19,83,51,11,75,43,27,91,59,7,71,39,23,87,55,15,79,47,31,95,63,2,66,34,98,18,82,50,10,74,42,26,90,58,6,70,38,22,86,54,14,78,46,30,94,62,4,68,36,100,20,84,52,12,76,44,28,92,60,8,72,40,24,88,56,16,80,48,32,96,64};
    EXPECT_EQ(s.leetcode_932_beautiful_array(in1), ans);
}

TEST(leetcode_932_beautiful_array, leetcode_932_beautiful_array_1)
{
    Solution s;
    int in1 = 4;
    vector<int> ans {2,1,4,3};
    EXPECT_EQ(s.leetcode_932_beautiful_array(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
