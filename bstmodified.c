// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *create(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int x)
{
    if(root==NULL)
    {
        return create(x);
    }
    if(x<root->data)
    {
        root->left=insert(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
    }
    return root;
}
struct node *minvalue(struct node *nnode)
{
    struct node *current=nnode;
    while(current && current->left !=NULL)
    {
        current = current->left;
    }
    return current;
}
struct node *deleten(struct node *root,int x)
{
    if(root==NULL)
    {
        return root;
    }
    if(x<root->data)
    {
        root->left=deleten(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=deleten(root->right,x);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=minvalue(root->right);
        root->data=temp->data;
        root->right=deleten(root->right,temp->data);
    }
    return root;
}
int search(struct node *root,int key)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data == key)
    {
        return 1;
    }
    if(key<root->data)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}
void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
void decending(struct node *root)
{
    if(root!=NULL)
    {
        decending(root->right);
        printf("%d\t",root->data);
        decending(root->left);
    }
}
int main() {
    struct node *root=NULL;
    int val,n,choice;
    printf("enter the number of elements you want to insert:\n");
    scanf("%d",&n);
    printf("enter the %d elements\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        root = insert(root,val);
    }
while(1)
{
printf("\nenter the choice\n");
printf("1.delete\t,2.inorder traversal\t,3.preorder traversal\t,4.postorder traversal\t5.decending order\t6.search\t7.exit\n");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    printf("enter the number to be deleted:\n");
    scanf("%d",&val);
    root=deleten(root,val);
    break;
    case 2:
    printf("entered elements in inorder order:\n");
    inorder(root);
    break;
    case 3:
    printf("entered elements in preorder order:\n");
    preorder(root);
    break;
    case 4:
    printf("entered elements in postorder order:\n");
    postorder(root);
    break;
    case 5:
    printf("entered elements in decending order:\n");
    decending(root);
    break;
    case 6:
    printf("enter the element to be searched:\n");
    scanf("%d",&val);
    if(search(root,val))
    {
        printf("the value %d found in the tree\n",val);
    
    }
    else
    {
        printf("the value %d not found in the tree\n",val); 
    }
    break;
    case 7:
    exit(0);
    break;
    default:
    printf("enter the valid choice");
}
}
    return 0;
}