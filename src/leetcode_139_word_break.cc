/**
 * 
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"
class Trie
{
private:
    bool m_isWord = false;
    Trie* m_isChild[26] = { nullptr };

public:
    Trie() {}

    void insert(const string& word) { //插入单词
        Trie* root = this;
        for (const auto& w : word) {
            if (!root->m_isChild[w - 'a']) root->m_isChild[w - 'a'] = new Trie();
            root = root->m_isChild[w - 'a'];
        }
        root->m_isWord = true;
    }

    bool search(const string& word) { //查找单词
        Trie* root = this;
        for (const auto& w : word) {
            if (!root->m_isChild[w - 'a']) return false;
            root = root->m_isChild[w - 'a'];
        }
        return root->m_isWord;
    }

    bool startsWith(string prefix) { //查找前缀
        Trie* root = this;
        for (const auto& p : prefix) {
            if (!root->m_isChild[p - 'a']) return false;
            root = root->m_isChild[p - 'a'];
        }
        return true;
    }
};

class Solution
{
public:
    bool leetcode_139_word_break(string s, vector<string>& wordDict) {

        unordered_set<string> sWordDict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i =  0; i <= s.size(); i++) {
            for (int j = 0; j < i; ++j) {
                if(dp[j] == true && sWordDict.find(s.substr(j, i-j)) != sWordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

TEST(leetcode_139_word_break, leetcode_139_word_break_1)
{
    Solution s;
    string in1 = "leetcode";
    vector<string> in2 = {"leet", "code"};
    bool ans = true;
    EXPECT_EQ(s.leetcode_139_word_break(in1, in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
