class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL)
            return 0;
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL and fast->next!=NULL and slow!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return 1;
            }
        }
        return 0;
    }
};
