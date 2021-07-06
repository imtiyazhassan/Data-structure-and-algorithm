#include <bits/stdc++.h>
#include <stdio.h>


struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* root;

bstnode* insert_bstnode(bstnode* root, int data)
{
    struct bstnode* temp = new bstnode;
    ///temp = (struct bstnode*) malloc(sizeof(struct bstnode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else if(data < root->data)
    {
        root->left = insert_bstnode(root->left, data);
    }
    else
        root->right = insert_bstnode(root->right, data);

    return root;

}

bool is_binary_tree(bstnode*root ,int minvalue , int maxvalue)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data > minvalue && root->data < maxvalue
       && is_binary_tree(root->left, minvalue , root->data)
        &&is_binary_tree(root->right, root->data, maxvalue))
            return true;
    else
        return false;
}

void isbst(bstnode* root)
{
    if(is_binary_tree(root, INT_MIN, INT_MAX)){
        printf("The tree is a bst\n");
    }
    else
    {
        printf("Not\n");
    }
}



/*bool isBST(bstnode* root, int minKey, int maxKey)
{
    // base case
    if (root == NULL) {
        return true;
    }

    // if the node's value falls outside the valid range
    if (root->data < minKey || root->data > maxKey) {
        return false;
    }

    // recursively check left and right subtrees with an updated range
    return isBST(root->left, minKey, root->data) &&
            isBST(root->right, root->data, maxKey);
}

// Function to determine whether a given binary tree is a BST
void isBST(bstnode* root)
{
    if (isBST(root, INT_MIN, INT_MAX)) {
        printf("The tree is a BST.");
    }
    else {
        printf("The tree is not a BST!");
    }
}
*/

int main()
{
    root = NULL;

    root = insert_bstnode(root,15);
    root = insert_bstnode(root,10);
    root = insert_bstnode(root,20);
    root = insert_bstnode(root,25);
    root = insert_bstnode(root,8);
    root = insert_bstnode(root,12);


///    isBST(root);
    isbst(root);

    return 0;
}
