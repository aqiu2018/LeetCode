/**
 * 

给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。


示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
 *
 * 注意：
假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
 *
 */
#include "headers.h"

class Solution
{
public:


    struct CmpByValueAndKey {
        bool operator()(pair<int,string> &k1, const pair<int,string> &k2) {
            if (k1.first != k2.first){
                return k1.first < k2.first;
            }
            else return k1.second.compare(k2.second) > 0;
        }
    };

    vector<string> leetcode_692_top_k_frequent_words(vector<string>& words, int k) {

        vector<string> ans;
        unordered_map<string, int> wordsMap;
        for(auto s:words) wordsMap[s]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, CmpByValueAndKey> p;
        for (auto mp : wordsMap)
            p.push(make_pair(mp.second, mp.first));


        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }

        return ans;
    }
};

TEST(leetcode_692_top_k_frequent_words, leetcode_692_top_k_frequent_words_1)
{
    Solution s;
    vector<string> in = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> ans = {"i", "love"};
    EXPECT_EQ(s.leetcode_692_top_k_frequent_words(in, 2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
