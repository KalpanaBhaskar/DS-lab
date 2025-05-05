#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int value;
    shared_ptr<Node> left, right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BST {
public:
    shared_ptr<Node> insert(shared_ptr<Node> root, int val) {
        if (!root) return make_shared<Node>(val);
        if (val < root->value) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }

    string preorder(shared_ptr<Node> root) {
        if (!root) return "";
        return to_string(root->value) + " " + preorder(root->left) + preorder(root->right);
    }

    string inorder(shared_ptr<Node> root) {
        if (!root) return "";
        return inorder(root->left) + to_string(root->value) + " " + inorder(root->right);
    }

    string postorder(shared_ptr<Node> root) {
        if (!root) return "";
        return postorder(root->left) + postorder(root->right) + to_string(root->value) + " ";
    }

    bool search(shared_ptr<Node> root, int val) {
        if (!root) return false;
        if (root->value == val) return true;
        return val < root->value ? search(root->left, val) : search(root->right, val);
    }
};

int main() {
    BST tree;
    shared_ptr<Node> root = nullptr;
    int choice, val;
    
    while (true) {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = tree.insert(root, val);
                cout << "Inserted " << val << "\n";
                break;
            case 2:
                cout << "Preorder: " << tree.preorder(root) << "\n";
                break;
            case 3:
                cout << "Inorder: " << tree.inorder(root) << "\n";
                break;
            case 4:
                cout << "Postorder: " << tree.postorder(root) << "\n";
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (tree.search(root, val) ? "Found" : "Not Found") << "\n";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}