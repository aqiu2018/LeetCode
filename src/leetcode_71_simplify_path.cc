/**
 * 
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

 

示例 1：

输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：

输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：

输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：

输入："/a/./b/../../c/"
输出："/c"
示例 5：

输入："/a/../../b/../c//.//"
输出："/c"
示例 6：

输入："/a//b////c/d//././/.."
输出："/a/b/c"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    string leetcode_71_simplify_path(string path) {
        string ans, t;
        stringstream ss(path);
        vector<string> v;
        while(getline(ss, t, '/')){
            if(t=="" || t==".") continue;
            if(t==".." && !v.empty()) v.pop_back();
            else if(t != "..") v.push_back(t);
        }

        for (string s : v) ans += "/" + s;

        return ans.empty()?"/":ans;
    }
};

TEST(leetcode_71_simplify_path, leetcode_71_simplify_path_2)
{
    Solution s;
    string in1 = "/../";
    string ans = "/";
    EXPECT_EQ(s.leetcode_71_simplify_path(in1), ans);
}
TEST(leetcode_71_simplify_path, leetcode_71_simplify_path_1)
{
    Solution s;
    string in1 = "/a/./b/../../c/";
    string ans = "/c";
    EXPECT_EQ(s.leetcode_71_simplify_path(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
