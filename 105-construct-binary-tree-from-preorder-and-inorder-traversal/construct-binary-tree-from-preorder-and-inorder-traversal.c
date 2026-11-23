/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder,
                       int preStart, int inStart, int inEnd) {

    if (inStart > inEnd) {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = preorder[preStart];
    root->left = NULL;
    root->right = NULL;
    int index = findIndex(inorder, inStart, inEnd, root->val);
    int leftSize = index - inStart;
    root->left = build(preorder, inorder,
                       preStart + 1,
                       inStart, index - 1);

    root->right = build(preorder, inorder,
                        preStart + leftSize + 1,
                        index + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    return build(preorder, inorder, 0, 0, inorderSize - 1);
}
