/**
 * 
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *tmp = q.front(); q.pop();
            if(tmp) {
                q.push(tmp->left);
                q.push(tmp->right);
                ans += to_string(tmp->val) + " ";
            }else{
                ans += "null ";
            }
        }
        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        TreeNode *ans = NULL;
        stringstream ss(data);
        string str;
        queue<TreeNode *> q;
        ss >> str;
        if(ss.fail()) return ans;
        else if(str == "null") return ans;
        else{
            ans = new TreeNode(stoi(str));
            q.push(ans);
        }

        while (true) {
            int size = q.size();
            if(size == 0) return ans;
            for (int i = 0; i < size; ++i) {
                TreeNode *root = q.front(); q.pop();
                ss >> str;
                if(ss.fail()) return ans;
                else if(str != "null") {
                    TreeNode *tmp = new TreeNode(stoi(str));
                    q.push(tmp);
                    root->left = tmp;
                }

                ss >> str;
                if(ss.fail()) return ans;
                else if(str != "null") {
                    TreeNode *tmp = new TreeNode(stoi(str));
                    q.push(tmp);
                    root->right = tmp;
                }
            }

        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

class Solution
{
public:
    int leetcode_297_serialize_and_deserialize_binary_tree(vector<int> &nums) {

//        Tree t{1, 2, NULL,  3, 4, 5, NULL, NULL};

//        Tree t{1};

        Tree t{NULL};
//        t.print();
        Codec codec;
        cout << " string : " << codec.serialize(t.root).c_str() << endl;
        TreeNode* ans = codec.deserialize(codec.serialize(t.root));
        print_tree(ans);

        return 1;
    }
};

TEST(leetcode_297_serialize_and_deserialize_binary_tree, leetcode_297_serialize_and_deserialize_binary_tree_1)
{
    Solution s;
    vector<int> in1 = {1, 2, 3};
    vector<vector<int>> in2 = {{1,2,3},{2,3,4}};
    int ans = 1;
    EXPECT_EQ(s.leetcode_297_serialize_and_deserialize_binary_tree(in1), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
