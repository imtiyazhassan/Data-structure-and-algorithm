#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;

struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* root;

bstnode* insert_bstnode(bstnode* root, int value)
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
    else if(value <root->data)
    {
        root->left = insert_bstnode(root->left, value);
    }
    else
        root->right = insert_bstnode(root->right, value);

    return root;
}


///Find minimum value in right subtree for delete operations. or maximum value in left subtree
bstnode* find_min(bstnode* root)
{

    while(root->left!= NULL)
    {
        root = root->left;
    }
    return root;
}


///Delete function
struct bstnode* deletenode(struct bstnode* root, int data)
{
    if(root == NULL)
        return root;

    else if(data < root->data)
        root->left = deletenode(root->left, data);

    else if(data > root->data)
        root->right = deletenode(root->right, data);

    else
    {
        ///Case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        ///case 2: one child
        else if(root->left == NULL)
        {
            struct bstnode* temp = root;
            root = root->right;
            delete temp;

        }
        else if(root->right == NULL)
        {
            struct bstnode* temp = root;
            root = root->left;
            delete temp;
        }
        ///case 3: two child. first need to find minimum right subtree or maximum in left subtree;
        else
        {
            struct bstnode* temp = find_min(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }

    return root;
}


///Level order traversal
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
   //// printf("\n right %d \n",root->data);
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
    root == NULL;

    while(1)
    {
        int n,op,m;

        printf("\n");
        printf("1. Insert node in bst\n");
        printf("2. Delete node in bst\n");
        printf("3. Levelorder Traversal in bst\n");

        scanf("%d",&op);

        if(op == 1)
        {
            printf("Enter the element: ");
            scanf("%d",&n);
            root = insert_bstnode(root,n);
        }
        if(op == 2)
        {
            printf("The node you want to delete\n");
            scanf("%d",&m);
            deletenode(root,m);
        }
        if(op ==3)
        {
            printf("levelorder\n");
            ///inorder(root);
            levelorder(root);
        }
    }

    return 0;
}
