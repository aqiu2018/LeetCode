/**
 * 
给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。

数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

示例:

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"
注:

letters长度范围在[2, 10000]区间内。
letters 仅由小写字母组成，最少包含两个不同的字母。
目标字母target 是一个小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    char leetcode_744_find_smallest_letter_greater_than_target(vector<char>& letters, char target) {

        if(letters[0]>target|| letters[letters.size() - 1] <= target) return letters[0];

        int left = 0, right = letters.size()-1, cur = letters.size()/2;
        while(left <= right){
            if(letters[cur] <= target){
                left = cur+1;
            }
            else{
                if (letters[cur - 1] <= target) return letters[cur];
                else right = cur - 1;
            }

            cur = left + (right - left)/2;
        }

    }
};

TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_0)
{
    Solution s;
    vector<char> in = {'e', 'e', 'e','e', 'e', 'e','n', 'n', 'n','n'};
    char target = 'n';
    char ans = 'e';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}

TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_1)
{
    Solution s;
    vector<char> in = {'c', 'f', 'j'};
    char target = 'a';
    char ans = 'c';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}

TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_2)
{
    Solution s;
    vector<char> in = {'c', 'f', 'j'};
    char target = 'c';
    char ans = 'f';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}


TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_3)
{
    Solution s;
    vector<char> in = {'c', 'f', 'j'};
    char target = 'd';
    char ans = 'f';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}

TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_4)
{
    Solution s;
    vector<char> in = {'c', 'f', 'j'};
    char target = 'g';
    char ans = 'j';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}


TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_5)
{
    Solution s;
    vector<char> in = {'c', 'f', 'j'};
    char target = 'j';
    char ans = 'c';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}

TEST(leetcode_744_find_smallest_letter_greater_than_target, leetcode_744_find_smallest_letter_greater_than_target_6)
{
    Solution s;
    vector<char> in = {'c', 'f', 'j'};
    char target = 'k';
    char ans = 'c';
    EXPECT_EQ(s.leetcode_744_find_smallest_letter_greater_than_target(in, target), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
