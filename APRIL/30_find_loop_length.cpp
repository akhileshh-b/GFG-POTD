// 30. Find Length of Loop
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution {
public:
    int countNodesinLoop(Node* head) {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int c = 1;
                while ((fast = fast->next) != slow) c++;
                return c;
            }
        }
        return 0;
    }
};