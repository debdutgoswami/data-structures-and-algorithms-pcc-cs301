/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* create(int data){
    struct ListNode *ptr;
    ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->val = data;
    ptr->next = NULL;
    return ptr;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum, carry = 0, data;
    struct ListNode *ptr1 = l1, *ptr2 = l2, *ptr=NULL, *root;
    
    while(ptr1 && ptr2){
        sum = ptr1->val + ptr2->val + carry;
        data = sum%10;
        carry = sum/10;
        if(ptr==NULL){
            ptr = create(data);
            root = ptr;
        }
        else{
            ptr->next = create(data);
            ptr = ptr->next;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while(ptr1){
        sum = ptr1->val + carry;
        data = sum%10;
        carry = sum/10;
        ptr->next = create(data);
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    while(ptr2){
        sum = ptr2->val + carry;
        data = sum%10;
        carry = sum/10;
        ptr->next = create(data);
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    if(carry){
        ptr->next = create(carry);
        ptr = ptr->next;
    }
    return root;
}

