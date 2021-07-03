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
    struct bstnode* temp;
    temp = (struct bstnode*) malloc(sizeof(struct bstnode));
    temp ->data = data;
    temp ->left = NULL;
    temp ->right = NULL;


    if(root == NULL)
    {
        root = temp;
    }
    else if(data < root->data)
    {
        root->left = insert_bstnode(root->left , data);
    }
    else
        root->right = insert_bstnode(root->right, data);

    return root;
}




int main()
{
    root = NULL;
    root = insert_bstnode(root,15);
    root = insert_bstnode(root,10);
    root = insert_bstnode(root,20);
    root = insert_bstnode(root,25);
    root = insert_bstnode(root,8);
    root = insert_bstnode(root,12);


    return 0;
}
