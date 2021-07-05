#include <bits/stdc++.h>

using namespace std;


struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* root;


bstnode* insert_bstnode(bstnode*root, int value)
{
    struct bstnode* temp;
    temp = (struct bstnode*)malloc(sizeof(struct bstnode));

    temp ->data = value;
    temp ->left = NULL;
    temp ->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }

    else if(value < root->data)
    {
        root->left = insert_bstnode(root->left, value);
    }
    else
        root->right = insert_bstnode(root->right, value);

    return root;
}

int max_height(bstnode* root)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = max_height(root->left);
    int right = max_height(root->right);

    if(left > right)
        return (left+1);
    else
        return (right+1);

}


int min_height(bstnode* root)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = min_height(root->left);
    int right = min_height(root->right);

    if(left < right)
        return (left+1);
    else
        return (right+1);
}




int main()
{
    root = NULL;

    while(1)
    {
        int n,op;

        printf("\n");
        printf("1. Insert in bst\n");
        printf("2. Max height in bst\n");
        printf("3. Min height in bst\n");
        printf("4. Exit \n");

        printf("Enter your choice\n");
        scanf("%d",&op);

        if(op == 1)
        {
            printf("Enter the value : ");
            scanf("%d",&n);
            root = insert_bstnode(root, n);
        }

        if(op == 2)
        {
            int m;
            m = max_height(root);
            printf("Maximum height of a binary tree is: %d\n",m);
        }

        if(op == 3)
        {
            int n;
            n = min_height(root);
            printf("Minimum height of a binary tree is: %d\n",n);
        }

        if(op == 4)
        {
            break;
        }



    }
    return 0;
}

