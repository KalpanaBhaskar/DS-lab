#include <iostream>
#include <stack>
#include <memory>
using namespace std;

struct Node {
    char value;
    shared_ptr<Node> left, right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
public:
    shared_ptr<Node> constructTree(const string& postfix) {
        stack<shared_ptr<Node>> s;
        for (char ch : postfix) {
            if (isalnum(ch)) {
                s.push(make_shared<Node>(ch));
            } else {
                auto right = s.top(); s.pop();
                auto left = s.top(); s.pop();
                auto newNode = make_shared<Node>(ch);
                newNode->left = left;
                newNode->right = right;
                s.push(newNode);
            }
        }
        return s.top();
    }

    string preorder(shared_ptr<Node> root) {
        if (!root) return "";
        return string(1, root->value) + " " + preorder(root->left) + preorder(root->right);
    }

    string inorder(shared_ptr<Node> root) {
        if (!root) return "";
        return inorder(root->left) + string(1, root->value) + " " + inorder(root->right);
    }

    string postorder(shared_ptr<Node> root) {
        if (!root) return "";
        return postorder(root->left) + postorder(root->right) + string(1, root->value) + " ";
    }
};

int main() {
    ExpressionTree tree;
    string postfix;
    shared_ptr<Node> root = nullptr;
    int choice;
    
    while (true) {
        cout << "\n1. Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                root = tree.constructTree(postfix);
                cout << "Expression tree constructed.\n";
                break;
            case 3:
                cout << "Preorder: " << tree.preorder(root) << "\n";
                break;
            case 4:
                cout << "Inorder: " << tree.inorder(root) << "\n";
                break;
            case 5:
                cout << "Postorder: " << tree.postorder(root) << "\n";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
