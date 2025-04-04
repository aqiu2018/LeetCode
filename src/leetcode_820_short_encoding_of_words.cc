/**

给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？



示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。


提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7
每个单词都是小写字母 。
 * 
 */
#include "headers.h"

class TrieNode{
public:
    TrieNode *m_child[26];
    bool m_isWord;
    TrieNode() : m_isWord(false){
        for(auto &c : m_child) c = nullptr;
    }

};

struct Longest
{
    bool operator()(const string& s1, const string& s2)
    {
        return s1.size() >  s2.size(); //从长到短排序
    }
};

class Solution
{
public:
    int leetcode_820_short_encoding_of_words(vector<string>& words) {

        sort(words.begin(), words.end(), Longest());
        TrieNode *root = new TrieNode();

        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            reverse(words[i].begin(), words[i].end());

            bool newWord = false;
            TrieNode *p = root;
            for(auto &w : words[i]){
                int i = w - 'a';
                if(!p->m_child[i]){
                    p->m_child[i] = new TrieNode();
                    newWord = true;
                }

                p = p->m_child[i];
            }

            ans += (newWord ? words[i].size() + 1 : 0);

        }

        return ans;


//        int res = 0;
//        unordered_set<string> st(words.begin(), words.end());
//        for (string word : st) {
//            for (int i = 1; i < word.size(); ++i) {
//                st.erase(word.substr(i));
//            }
//        }
//        for (string word : st) res += word.size() + 1;
//        return res;
    }
};

TEST(leetcode_820_short_encoding_of_words, leetcode_820_short_encoding_of_words_1)
{
    Solution s;
    vector<string> in1 = {"time", "me", "bell"};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 10;
    EXPECT_EQ(s.leetcode_820_short_encoding_of_words(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
