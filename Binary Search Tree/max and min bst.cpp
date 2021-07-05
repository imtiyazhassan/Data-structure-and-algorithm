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

bstnode* insert_tree(bstnode*root, int value)
{
    struct bstnode* temp;
    temp = (struct bstnode*)malloc(sizeof(struct bstnode));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else if(value < root->data)
    {
        root->left = insert_tree(root->left, value);
    }
    else
        root->right = insert_tree(root->right, value);

    return root;
}

/*int find_max(struct bstnode* root)
{
    struct bstnode* temp;
    temp = root;

    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return(temp->data);
}*/


///find maximum element in bst;
int find_max(bstnode* root)
{
    if(root == NULL || root->right == NULL)
        return -1;

    while(root-> right!= NULL)
    {
        root = root->right;
    }

    return(root->data);
}


int find_min(bstnode* root)
{
    if(root == NULL || root->left == NULL)
        return -1;

    while(root->left!= NULL)
    {
        root = root->left;
    }
    return(root->data);
}



void preorder(bstnode* root)
{
    if (root == NULL)
        return;

    printf("%d ",root->data);

    preorder(root->left);
    preorder(root->right);

}




int main()
{
    root = NULL;
    struct bstnode* ptr;
    while(1)
    {
        int n,op,m;

        printf("\n1. insert the element \n");
        printf("2. find max element \n");
        printf("3. find minimum element \n");
        printf("4. preorder \n");
        printf("5. Exit\n");

        scanf("%d",&op);

        if(op == 1)
        {
            printf("insert element in the tree : ");
            scanf("%d",&n);
            root = insert_tree(root,n);
        }
        if(op == 2)
        {
            printf("find the max element\n");
            ///ptr = find_max(root);
            m = find_max(root);
            printf("Max element in bst :%d\n",m);

        }

        if(op == 3)
        {
            printf("Minimum element \n");
            ///m = find_min(root);
            printf("The minimum value is :%d\n",find_min(root));

        }

        if(op == 4)
        {
            printf("preorder\n");
            preorder(root);
        }

        if(op == 5)
        {
            break;
        }


    }

    return 0;
}
