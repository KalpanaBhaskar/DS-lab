#include <iostream>
using namespace std;

// Node structure for the binary tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node in the binary tree
TreeNode* insert(TreeNode* root, char val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    char choice;
    cout << "Insert " << val << " to the left (l) or right (r) of " << root->data << "? ";
    cin >> choice;

    if (choice == 'l') {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Preorder traversal (Root -> Left -> Right)
void preorder(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal (Left -> Root -> Right)
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal (Left -> Right -> Root)
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Search for a character in the binary tree
bool search(TreeNode* root, char key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    return search(root->left, key) || search(root->right, key);
}

int main() {
    TreeNode* root = nullptr;
    int choice;
    char val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> val;
                if (search(root, val))
                    cout << val << " found in the tree.\n";
                else
                    cout << val << " not found.\n";
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
