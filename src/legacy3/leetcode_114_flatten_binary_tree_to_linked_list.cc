/**
 * 
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    TreeNode* Recursion(TreeNode* root){

        if(root == nullptr) return root;

        TreeNode* temp1 = Recursion(root->left);
        TreeNode* temp2 = Recursion(root->right);

        if(temp1 == nullptr && temp2 == nullptr){
            return root;
        }
        else if(temp1!=nullptr && temp2!=nullptr){
            TreeNode* right = root->right;
            root->right = root->left;
            root->left = nullptr;
            temp1->right = right;
            return temp2;
        }else if(temp1!=nullptr){
            root->right = root->left;
            root->left = nullptr;
            return temp1;
        }
        else{
            return temp2;
        }
    }
    void leetcode_114_flatten_binary_tree_to_linked_list(TreeNode* root) {
        Recursion(root);
    }
};

TEST(leetcode_114_flatten_binary_tree_to_linked_list, leetcode_114_flatten_binary_tree_to_linked_list_1)
{
    Solution s;
    Tree t{1,2,5,3,4,NULL,6};
    t.print();


    bool ans = true;
//    EXPECT_EQ(is_same_tree(s.leetcode_206_ReverseLinkedList(t.root), rstList.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
