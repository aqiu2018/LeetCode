/**
 * 

You are given two non-empty linked lists representing two non-negative integers.

The digits are stored in reverse order and each of their nodes contain a single digit.

Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 *
 */

//TODO: 更好的解法
//		直接在输入链上操作，同时修改两条链，并返回最长的那一条链

#include "headers.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* leetcode_2_add_two_num(ListNode* l1, ListNode* l2) {
    	ListNode* head, *tail;
    	head = tail = nullptr;

    	ListNode* pL1 = l1, *pL2 = l2;
    	// LeetCode::print_list(pL1);
    	// LeetCode::print_list(pL2);
    	int sum = 0;

    	while(pL1 || pL2){

    		if (pL1)
    		{
    			// std::cout << " pL1 " << pL1->val << " sum: " << sum << std::endl;
    			sum = sum + pL1->val;
    			pL1 = pL1->next;
    		}

    		if (pL2)
    		{
    			// std::cout << " pL2 " << pL2->val << " sum: " << sum << std::endl;
    			sum = sum + pL2->val;
    			pL2 = pL2->next;
    		}


		    if (head == nullptr)
	        	head = tail = new ListNode(sum%10);
			else
			{
				tail->next = new ListNode(sum%10);
				tail = tail->next;
				tail->next = nullptr;
			}

    		sum = sum/10;
    		// std::cout << " sum: " << sum << std::endl;

    	}

	    if (sum > 0)
		{
			// std::cout << " sum1: " << sum << std::endl;
			tail->next = new ListNode(sum%10);
			tail = tail->next;
			tail->next = nullptr;
		}

    	// LeetCode::print_list(head);

    	return head;
    }
};

TEST(leetcode_2_add_two_num, leetcode_2_add_two_num_1)
{
    Solution s;
    // vector<int> in = {1, 2, 3};
    // int ans = 1;
    // EXPECT_EQ(s.leetcode_2_add_two_num(in), ans);

    List *in1, *in2;
    in1 = new List();
    in2 = new List();
    for (int i = 0; i < 5; ++i)
    {
    	in1->insert(i);
    	in2->insert(i*3);
    }
    LeetCode::print_list(in1->head);
    LeetCode::print_list(in1->head);
    LeetCode::print_list(in2->head);
    std::cout << "-------begin-----" << std::endl;
    s.leetcode_2_add_two_num(in1->head, in2->head);

    // LeetCode::freeMem(in1->head);
    // LeetCode::freeMem(in2->head);
}

TEST(leetcode_2_add_two_num, leetcode_2_add_two_num_2)
{
    Solution s;

    List in1{1,2,3}, in2{4,9,1,2};
    List ans{5,1,5,2};

    LeetCode::print_list(in1.head);
    LeetCode::print_list(in2.head);
    std::cout << "-------begin-----" << std::endl;

    EXPECT_TRUE(is_same_list(s.leetcode_2_add_two_num(in1.head, in2.head), ans.head));
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}


