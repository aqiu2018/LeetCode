/**
 * 
 给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
你需要计算完成所有任务所需要的最短时间。

示例 1：
输入: tasks = ["A","A","A","B","B","B"], n = 2
输出: 8
执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
注：
任务的总个数为 [1, 10000]。
n 的取值范围为 [0, 100]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/task-scheduler
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    struct CmpByValueAndKey {
        bool operator()(pair<int, int> &k1, const pair<int, int> &k2) {
            return k1.first > k2.first;
        }
    };

    int leetcode_621_task_scheduler(vector<char>& tasks, int n) {

//        unordered_map<int, int> charMap;
//        for (auto c : tasks) {
//            if(charMap.count(c-'A') == 0) charMap[c-'A']=1;
//            else charMap[c-'A']++;
//        }
//
//        priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValueAndKey> p;
//        for (auto mp : charMap) {
//            p.push(make_pair(mp.second, mp.first));
//        }

        int rst = 0;
        vector<int> v1(26);
        for(auto c : tasks) v1[c-'A']++;

        sort(v1.begin(), v1.end(), greater<int>());

        rst = (v1[0] - 1)*(n + 1) ;
        for (int i = 0; i < v1.size(); i--) {
            if(v1[i] != v1[0]){
                continue;
            }
            rst++;
        }

        int size = tasks.size();
        rst = max(rst, size);

        return rst;
    }
};

TEST(leetcode_621_task_scheduler, leetcode_621_task_scheduler_1)
{
    Solution s;
    vector<char> in {'A','A','A','B','B','B'};
    int n = 2;
    int ans = 8;
    EXPECT_EQ(s.leetcode_621_task_scheduler(in, n), ans);
}

TEST(leetcode_621_task_scheduler, leetcode_621_task_scheduler_2)
{
    Solution s;
    vector<char> in {'A','A','A','B','B','B','C'};
    int n = 2;
    int ans = 8;
    EXPECT_EQ(s.leetcode_621_task_scheduler(in, n), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
