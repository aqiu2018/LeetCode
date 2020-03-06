/**
 * 
排排坐，分糖果。

我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。

给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。

然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。

重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。

返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

 

示例 1：

输入：candies = 7, num_people = 4
输出：[1,2,3,1]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0,0]。
第三次，ans[2] += 3，数组变为 [1,2,3,0]。
第四次，ans[3] += 1（因为此时只剩下 1 颗糖果），最终数组变为 [1,2,3,1]。
示例 2：

输入：candies = 10, num_people = 3
输出：[5,2,3]
解释：
第一次，ans[0] += 1，数组变为 [1,0,0]。
第二次，ans[1] += 2，数组变为 [1,2,0]。
第三次，ans[2] += 3，数组变为 [1,2,3]。
第四次，ans[0] += 4，最终数组变为 [5,2,3]。
 

提示：

1 <= candies <= 10^9
1 <= num_people <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-candies-to-people
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    vector<int> leetcode_1103_distribute_candies_to_people(int candies, int num_people) {

        vector<int> ans(num_people, 0);
        int root = sqrt(candies*2);
        int r2 = root*(root+1);;
        while (r2 <= 2*candies){
            root= root+1;
            r2 = root*(root+1);
        }
        root = root - 1;

//        cout << "root " << root << endl;

        int round = root/num_people;
        int yushu = root%num_people;
//        cout << " people " << num_people << " round " << round << " yushu " << yushu << endl;
        for (int i = 0; i < num_people; ++i) {
            int roundTemp = round;
            if(i < yushu) roundTemp++;
            if (i == yushu) ans[i] += (candies - (root*root+root)/2);
            ans[i] += num_people*roundTemp*(roundTemp-1)/2 + roundTemp*(i+1);
        }

        return ans;
    }
};

TEST(leetcode_1103_distribute_candies_to_people, leetcode_1103_distribute_candies_to_people_5)
{
    Solution s;
    int in3 = 80, in4 = 4;
    vector<int> ans = {17,18,21,24};
    EXPECT_EQ(s.leetcode_1103_distribute_candies_to_people(in3, in4), ans);
}
TEST(leetcode_1103_distribute_candies_to_people, leetcode_1103_distribute_candies_to_people_4)
{
    Solution s;
    int in3 = 2, in4 = 2;
    vector<int> ans = {1, 1};
    EXPECT_EQ(s.leetcode_1103_distribute_candies_to_people(in3, in4), ans);
}

TEST(leetcode_1103_distribute_candies_to_people, leetcode_1103_distribute_candies_to_people_3)
{
    Solution s;
    int in3 = 0, in4 = 3;
    vector<int> ans = {0, 0, 0};
    EXPECT_EQ(s.leetcode_1103_distribute_candies_to_people(in3, in4), ans);
}

TEST(leetcode_1103_distribute_candies_to_people, leetcode_1103_distribute_candies_to_people_2)
{
    Solution s;
    int in3 = 10, in4 = 3;
    vector<int> ans = {5, 2, 3};
    EXPECT_EQ(s.leetcode_1103_distribute_candies_to_people(in3, in4), ans);
}


TEST(leetcode_1103_distribute_candies_to_people, leetcode_1103_distribute_candies_to_people_1)
{
    Solution s;
    int in3 = 7, in4 = 4;
    vector<int> ans = {1, 2, 3, 1};
    EXPECT_EQ(s.leetcode_1103_distribute_candies_to_people(in3, in4), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
