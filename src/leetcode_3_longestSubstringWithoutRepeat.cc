/**
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 */
#include "headers.h"
//using namespace std;
using namespace MyLog;

class Solution
{
public:
    int leetcode_3_longestSubstringWithoutRepeat(string s) {

#if 0
        if(s.size() == 0) return 0;

        std::unordered_set<char> dst;

        int maxLength = 0;
        int left = 0, right = 0;
        for (int i = 0, size = s.size(); i < size; ++i) {

            while(dst.find(s[i]) != dst.end()){
                dst.erase(s[left]);
                left ++;
            }

            maxLength = std::max(maxLength, i-left+1);
            dst.insert(s[i]);
        }
        return maxLength;

#else
      int freq[256] = {0};
      int l=0,r=-1, res = 0;

      while(l < s.size()) {
          if(r+1 < s.size() && freq[s[r+1]] == 0)
              freq[s[++r]]++;
          else
              freq[s[l++]] --;

          res = max(res, r-l+1);
      }

      return res;

#endif
    }
};

TEST(leetcode_3_longestSubstringWithoutRepeat, leetcode_3_longestSubstringWithoutRepeat_1)
{
    Solution s;
    string in = "bacabcab";
    int ans = 3;

    EXPECT_EQ(s.leetcode_3_longestSubstringWithoutRepeat(in), ans);
}

int main(int argc, char **argv)
{
//    std::set<int> sett;
//    sett.insert(1);
//    sett.insert(3);
//    sett.insert(2);
//    auto iter = sett.begin();
//    while(iter != sett.end()){
//        std::cout << *iter << " ";
//        iter ++;
//    }
//    std::cout << " max: " << std::endl;
//
//    std::set<char> setts;
//    setts.insert('b');
//    setts.insert('a');
//    setts.insert('c');
//    std::set<char>::iterator iters = setts.begin();
//    while(iters != setts.end()){
//        std::cout << *iters << " ";
//        iters ++;
//    }
//    std::cout << " max: " << std::endl;

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
