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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* tail = head;
   
        int len = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            len++; //len of the list
        }
        k = k%len;
        int r = len - k - 1;
        tail->next = head; //circullar linked list

        ListNode* newTail = head;

        for(int i = 0; i < r; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
