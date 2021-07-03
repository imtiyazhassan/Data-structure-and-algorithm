#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* root;
struct bstnode* key;

bstnode* insert_bstnode(bstnode* root, int data)
{
    struct bstnode* temp;
    temp = (struct bstnode*) malloc(sizeof(struct bstnode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;



    if(root == NULL)
    {
        root  = temp;
    }
    else if(data < root->data)
    {
        root->left = insert_bstnode(root->left, data);
    }
    else
    {
        root->right = insert_bstnode(root->right,data);
    }
    return root;

}



void Preorder(bstnode*root)
{
    if (root ==NULL)
        return;

    printf("%d  ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}


void inorder(bstnode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ",root->data);

    inorder(root->right);

}

void postorder(bstnode* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    printf("%d ", root->data);

}


int main()
{
    int value;

    root = NULL;
    root = insert_bstnode(root,15);
    root = insert_bstnode(root,10);
    root = insert_bstnode(root,20);
    root = insert_bstnode(root,25);
    root = insert_bstnode(root,8);
    root = insert_bstnode(root,12);

    printf("Binary tree preorder\n");
    Preorder(root);

    printf("\nbinary tree inorder\n");
    inorder(root);


    printf("\nBinary tree postorder\n");
    postorder(root);



    return 0;
}
