/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include<queue>
using namespace std;

class Solution {
private:
    void enqueue_child(Node* node, queue<Node*>& q) {
        if (nullptr != node->left) {
            q.push(node->left);
        }
        if (nullptr != node->right) {
            q.push(node->right);
        }
    }

public:
    Node* connect(Node* root) {
        if (nullptr == root) {
            return nullptr;
        }

        queue<Node*> nodes;
        Node* node, *post_node;
        int size, i;

        nodes.push(root);
        while(!nodes.empty()) {

            size = nodes.size();
            node = nodes.front();
            nodes.pop();
            enqueue_child(node, nodes); // bfs enqueue
            while(--size) {
                post_node = nodes.front();
                enqueue_child(post_node, nodes);
                nodes.pop();

                // process
                node->next = post_node;

                node = post_node;
            }
            node->next = nullptr;
        }

        return root;
    }
};