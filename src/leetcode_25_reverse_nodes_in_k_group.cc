/**
 * 
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include "headers.h"

class Solution
{
public:


    ListNode* iteration(ListNode* head, int k) {

        ListNode* new_head = head;
        ListNode* pre = nullptr, *lastReverse = head, *cur = head, *tmp= nullptr;
        bool isFirstReverse = true;
        while (true)
        {
            pre = nullptr, lastReverse = head, cur = head, tmp= nullptr;
            if(head== nullptr || head->next == nullptr) {
                break;
            }


            int n=1;
            while(n<=k && cur != nullptr){
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
                n++;
            }

            // pre 最后一个节点;  cur 新节点
            if(n<=k) {
                cur = pre;
                ListNode* last = nullptr;
                while(cur != nullptr){
                    tmp = cur->next;
                    cur->next = last;
                    last = cur;
                    cur = tmp;
                }
                pre = last;
//                return pre;
            }

//            lastReverse->next = recursion(cur, k);
//            return pre;

            lastReverse->next = cur;
            head = cur;
            if(isFirstReverse){
                isFirstReverse = false;
                new_head = pre;
            }

        }

        return new_head;

    }
    ListNode* recursion(ListNode* head, int k) {


        if(head== nullptr || head->next == nullptr) return head;

        ListNode* pre = nullptr, *lastReverse = head, *cur = head, *tmp= nullptr;
        int n=1;
        while(n<=k && cur != nullptr){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            n++;
        }

        // pre 最后一个节点;  cur 新节点
        if(n<=k) {
            cur = pre;
            ListNode* last = nullptr;
            while(cur != nullptr){
                tmp = cur->next;
                cur->next = last;
                last = cur;
                cur = tmp;
            }
            return last;
        }

        lastReverse->next = recursion(cur, k);
        return pre;
    }

    ListNode* leetcode_25_reverse_nodes_in_k_group(ListNode* head, int k) {
//        return iteration(head, k);
        return recursion(head, k);
    }
};

TEST(leetcode_25_reverse_nodes_in_k_group, leetcode_25_reverse_nodes_in_k_group_1)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.print();

    rstList.insert(2);
    rstList.insert(1);
    rstList.insert(4);
    rstList.insert(3);
    rstList.insert(5);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_25_reverse_nodes_in_k_group(l.head, 2), rstList.head), ans);
}

TEST(leetcode_25_reverse_nodes_in_k_group, leetcode_25_reverse_nodes_in_k_group_2)
{
    Solution s;
    List l, rstList;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.print();

    rstList.insert(3);
    rstList.insert(2);
    rstList.insert(1);
    rstList.insert(4);
    rstList.insert(5);

    bool ans = true;
    EXPECT_EQ(is_same_list(s.leetcode_25_reverse_nodes_in_k_group(l.head, 3), rstList.head), ans);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
