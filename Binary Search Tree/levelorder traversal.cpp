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

bstnode* insert_bstnode(bstnode* root, int data)
{
    struct bstnode* temp;
    temp =(struct bstnode*)malloc(sizeof(struct bstnode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else if(data <root->data)
    {
        root->left = insert_bstnode(root->left, data);
    }
    else
        root->right = insert_bstnode(root->right, data);

}
///fist find the maximum height of bst
///print level by level
///Find maximum height of bst
int height(bstnode* root) {
    if (root==NULL)
        return -1;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}


void printLevel(bstnode* root, int level)
 {
    if (root == NULL)
        return;
    if (level==0) {
        printf("%d ",root->data);
        return;
    }
    printLevel(root->left, level - 1);
    ///printf("\n left %d \n",root->data);
    printLevel(root->right, level - 1);
   /// printf("\n right %d \n",root->data);
}


void levelorder(bstnode* root) {
    int h=height(root);
    for (int i = 0; i <= h ; i++) {
        printf("Level %d: ",i);
        printLevel(root, i);

        printf("\n");
    }
    printf("\n");

}



int main()
{
    root = NULL;
    int op,n;

    while(1)
    {
        printf("\n");
        printf("1. Insert Elements in  Tree\n");
        printf("2. Level Order Traversal in Tree\n");
        printf("3. Exit\n");

        printf("Enter your choice\n");
        scanf("%d",&op);
        if(op == 1)
        {
            printf("Enter a elements ");
            scanf("%d",&n);
            root = insert_bstnode(root,n);
        }
        if(op == 2)
        {
            levelorder(root);

        }
        if(op == 3)
        {
            break;
        }

    }

    return 0;
}
