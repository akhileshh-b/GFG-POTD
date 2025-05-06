// 29. Sort a Linked List of 0s, 1s, and 2s
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution {
public:
    Node* segregate(Node* head) {
        int count[3] = {0};
        for (Node* curr = head; curr; curr = curr->next) count[curr->data]++;
        Node* curr = head;
        for (int i = 0; i < 3; i++)
            while (count[i]--) curr->data = i, curr = curr->next;
        return head;
    }
};