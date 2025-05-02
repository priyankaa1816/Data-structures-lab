//Implement binary tree using linked list
#include <stdio.h>
#include <stdlib.h>

class BinaryTree {
private:
    struct Node {
        char data;
        struct Node* left;
        struct Node* right;
    };
    Node* root;
    Node* createNode(char data);
    Node* insertHelper(Node* node, char data);
    void preorderHelper(Node* node);
    void inorderHelper(Node* node);
    void postorderHelper(Node* node);
    int searchHelper(Node* node, char key);
public:
    BinaryTree();
    void insertNode(char data);
    void preorder();
    void inorder();
    void postorder();
    void searchNode(char key);
};

int main() {
    BinaryTree tree;
    int choice;
    char data;
    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &data);
                tree.insertNode(data);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                printf("Enter character to search: ");
                scanf(" %c", &data);
                tree.searchNode(data);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
// Constructor
BinaryTree::BinaryTree() {
    root = NULL;
}
// Create Node
BinaryTree::Node* BinaryTree::createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Insert Helper
BinaryTree::Node* BinaryTree::insertHelper(Node* node, char data) {
    if (node == NULL) return createNode(data);
    char direction;
    printf("Insert %c to (L)eft or (R)ight of %c? ", data, node->data);
    scanf(" %c", &direction);
    if (direction == 'L' || direction == 'l')
        node->left = insertHelper(node->left, data);
    else
        node->right = insertHelper(node->right, data);

    return node;
}
// Insert Node
void BinaryTree::insertNode(char data) {
    root = insertHelper(root, data);
}
// Preorder Traversal
void BinaryTree::preorderHelper(Node* node) {
    if (node == NULL) return;
    printf("%c ", node->data);
    preorderHelper(node->left);
    preorderHelper(node->right);
}
void BinaryTree::preorder() {
    printf("Preorder: ");
    preorderHelper(root);
    printf("\n");
}
// Inorder Traversal
void BinaryTree::inorderHelper(Node* node) {
    if (node == NULL) return;
    inorderHelper(node->left);
    printf("%c ", node->data);
    inorderHelper(node->right);
}
void BinaryTree::inorder() {
    printf("Inorder: ");
    inorderHelper(root);
    printf("\n");
}
// Postorder Traversal
void BinaryTree::postorderHelper(Node* node) {
    if (node == NULL) return;
    postorderHelper(node->left);
    postorderHelper(node->right);
    printf("%c ", node->data);
}
void BinaryTree::postorder() {
    printf("Postorder: ");
    postorderHelper(root);
    printf("\n");
}
// Search Helper
int BinaryTree::searchHelper(Node* node, char key) {
    if (node == NULL) return 0;
    if (node->data == key) return 1;
    return searchHelper(node->left, key) || searchHelper(node->right, key);
}
// Search Node
void BinaryTree::searchNode(char key) {
    if (searchHelper(root, key))
        printf("Element %c found in the tree\n", key);
    else
        printf("Element %c not found in the tree\n", key);
}
