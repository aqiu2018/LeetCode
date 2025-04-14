/**
 * 
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include "headers.h"

class Solution
{
public:
    ListNode* leetcode_21_merge_two_sorted_lists(ListNode* l1, ListNode* l2) {
        ListNode *pre = nullptr, *head = l2;
        if((l1 != nullptr) && (l2 != nullptr) && (l2->val < l1->val)) {pre = l2; l2 = l1; l1 = pre;}
        if (l1 != nullptr) head = l1;

        int flag = 0;
        while (l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val) {
                pre = l1;
                l1= l1->next;
            }else{
                pre->next = l2;
                pre = l2;
                l2=l2->next;

                pre->next = l1;
            }
            flag = 1;
        }

        if (flag == 1 && l2 != nullptr) pre->next = l2;

        pre = nullptr;

        return head;
    }
};

TEST(leetcode_21_merge_two_sorted_lists, leetcode_21_merge_two_sorted_lists_1)
{
    Solution s;
    ListNode *l1 = nullptr;
    List *l2 = new List;

    l2->insert(1);
    l2->insert(3);
    l2->insert(4);

    List *ans  = new List;
    ans->insert(1);
    ans->insert(3);
    ans->insert(4);

    ListNode * rst = s.leetcode_21_merge_two_sorted_lists(l1, l2->head);
    print_list(rst);
    print_list(ans->head);

    EXPECT_EQ(is_same_list(rst, ans->head), true);
}


TEST(leetcode_21_merge_two_sorted_lists, leetcode_21_merge_two_sorted_lists_2)
{
    Solution s;
    List *l1 = new List, *l2 = new List;
    l1->insert(2);
    l1->insert(4);

    l2->insert(1);
    l2->insert(3);
    l2->insert(4);

    List *ans  = new List;
    ans->insert(1);
    ans->insert(2);
    ans->insert(3);
    ans->insert(4);
    ans->insert(4);

    ListNode * rst = s.leetcode_21_merge_two_sorted_lists(l1->head, l2->head);
    print_list(rst);
    print_list(ans->head);

    EXPECT_EQ(is_same_list(rst, ans->head), true);
}

TEST(leetcode_21_merge_two_sorted_lists, leetcode_21_merge_two_sorted_lists_3)
{
    Solution s;
    List *l1 = new List, *l2 = new List;

    l2->insert(0);

    List *ans  = new List;
    ans->insert(0);

    ListNode * rst = s.leetcode_21_merge_two_sorted_lists(l1->head, l2->head);
    print_list(rst);
    print_list(ans->head);

    EXPECT_EQ(is_same_list(rst, ans->head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
