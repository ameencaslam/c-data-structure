
//         1 
//        / \ 
//       /   \ 
//      2     3
//     / \   / \ 
//    /  |   |  \   
//   4   5   6   7


#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
};

struct TreeNode *createNode (int data)
{
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void inOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void main()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("\n\nIn-Order Traversal : ");
    inOrder(root);

    printf("\n\nPre-Order Traversal : ");
    preOrder(root);

    printf("\n\nPost-Order Traversal : ");
    postOrder(root);
}
