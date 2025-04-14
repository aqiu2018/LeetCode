/**
 * 
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:
输入: 1->1->1->2->3
输出: 2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:
    ListNode* leetcode_82_remove_duplicates_from_sorted_list_ii(ListNode* head) {

        if(head== nullptr || head->next == nullptr) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *tmp = nullptr;
        ListNode *cur = &dummy;
        while(cur->next != nullptr && cur->next->next != nullptr){
            if(cur->next->val == cur->next->next->val){
                tmp = cur->next;
                while(tmp && tmp->next && tmp->val == tmp->next->val){
                    tmp = tmp->next;
                }
                cur->next = tmp->next;
            }
            else{
                cur = cur->next;
            }
        }

        return dummy.next;

//        ListNode* pre = head, *next = head->next;
//        while(next != nullptr){
//            if(pre->val == next->val) {
//                if(next->next == nullptr) pre->next = nullptr;
//                next=next->next;
//                continue;
//            }
//            pre->next = next;
//            pre=pre->next;
//            next=next->next;
//        }
//
//        return head;
    }
};

TEST(leetcode_82_remove_duplicates_from_sorted_list_ii, leetcode_82_remove_duplicates_from_sorted_list_ii_1)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(1);
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.print();

    rstList.insert(2);
    rstList.insert(3);
    rstList.print();

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_82_remove_duplicates_from_sorted_list_ii(l.head), rstList.head), true);
}



TEST(leetcode_82_remove_duplicates_from_sorted_list_ii, leetcode_82_remove_duplicates_from_sorted_list_ii_2)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(3);
    l.insert(4);
    l.insert(4);
    l.insert(5);
    l.print();

    rstList.insert(1);
    rstList.insert(2);
    rstList.insert(5);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_82_remove_duplicates_from_sorted_list_ii(l.head), rstList.head), true);
}

TEST(leetcode_82_remove_duplicates_from_sorted_list_ii, leetcode_82_remove_duplicates_from_sorted_list_ii_3)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(3);
    l.insert(4);
    l.insert(4);
    l.print();

    rstList.insert(1);
    rstList.insert(2);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_82_remove_duplicates_from_sorted_list_ii(l.head), rstList.head), true);
}

TEST(leetcode_82_remove_duplicates_from_sorted_list_ii, leetcode_82_remove_duplicates_from_sorted_list_ii_4)
{
    Solution s;
    List l, rstList;
    l.insert(3);
    l.insert(3);
    l.print();

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_82_remove_duplicates_from_sorted_list_ii(l.head), rstList.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
