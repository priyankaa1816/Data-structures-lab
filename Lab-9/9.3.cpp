//Implementation of Binary serach tree using linked list
#include <stdio.h>
#include <stdlib.h>
class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;
    Node* createNode(int value);
    Node* insert(Node* root, int value);
    void preorder(Node* root);
    void inorder(Node* root);
    void postorder(Node* root);
    bool search(Node* root, int key);

public:
    BST() { root = NULL; }
    ~BST() { root = NULL; } 

    void insert(int value) { root = insert(root, value); }
    void preorder() { preorder(root); printf("\n"); }
    void inorder() { inorder(root); printf("\n"); }
    void postorder() { postorder(root); printf("\n"); }
    bool search(int key) { return search(root, key); }
};

int main() {
    BST tree;
    int choice, value;
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                tree.insert(value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                tree.preorder();
                break;
            case 3:
                printf("Inorder Traversal: ");
                tree.inorder();
                break;
            case 4:
                printf("Postorder Traversal: ");
                tree.postorder();
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (tree.search(value))
                    printf("Value found in the tree.\n");
                else
                    printf("Value not found in the tree.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
//Create a new node
BST::Node* BST::createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//Insert a new node into the tree
BST::Node* BST::insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
//Preorder traversal of the tree
void BST::preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//Inorder traversal of the tree
void BST::inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//Postorder traversal of the tree
void BST::postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
//Search for a value in the tree
bool BST::search(Node* root, int key) {     
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    } else if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
