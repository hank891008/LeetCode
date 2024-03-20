/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *now = list2;
        while(now->next != NULL){
            now = now->next;
        }
        ListNode *end_of_list2 = now;
        int idx = 0;
        ListNode *a_of_list1 = NULL, *b_of_list1 = NULL;
        now = list1;
        while(now){
            if(idx == a - 1){
                a_of_list1 = now;
            }
            if(idx == b){
                b_of_list1 = now;
            }
            now = now->next;
            idx++;
        }
        a_of_list1->next = list2;
        end_of_list2->next = b_of_list1->next;
        return list1;
    }
};