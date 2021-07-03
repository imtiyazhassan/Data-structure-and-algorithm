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
    temp = (struct bstnode*) malloc(sizeof(struct bstnode));

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
    {
        root->right = insert_bstnode(root->right,data);
    }
    return root;

}


/*bstnode* search_element(bstnode* root, int value)
{
    if(root->data == value || root == NULL)
    {
        return root;
    }
    else if(root->data > value)
    {
        return search_element(root->left, value);
    }
    else
        return search_element(root->right,value);
}

*/

///another way to search element

void search_element(int value)
{
    struct bstnode* temp;
    temp = root;

    int flag =0;
    while(1)
    {
        if(value == temp->data)
        {
            flag++;
            break;
        }
        else if(value < temp->data)
        {
            temp = temp->left;
        }
        else
            temp = temp->right;


        if(temp==NULL)
            break;
    }
    if(flag == 1)
        printf("found\n");
    else
        printf("Not found\n");

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

    printf("The element you want to search \n");
    scanf("%d",&value);

   /**int flag = 0;

    if(search_element(root, value))
    {
        flag+=1;
    }
    if(flag == 0)
        printf("element not found\n");
    else
        printf("found\n");
*/

    search_element(value);


    return 0;
}

