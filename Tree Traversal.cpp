#include <bits/stdc++.h>
using namespace std;
struct node{

  node *left, *right;

  int data;

  node()
  {
      this->data = data;
      left = right = NULL;
  }

};

void inorderShow(node *root)
{
    if(root == NULL)
    {
        return;
    }

    inorderShow(root->left);
    printf("%d ", root->data);
    inorderShow(root->right);
}
node* createNode(int value){

    node *newNode = new node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insertLeft( node *root, int value) {
    root->left = createNode(value);
    return root->left;
}
node* insertRight( node *root, int value){
    root->right = createNode(value);
    return root->right;
}
void preorderShow(node *root)
{
    if(root == NULL)
    {
        return;
    }
     printf("%d ", root->data);
    preorderShow(root->left);

    preorderShow(root->right);
}

void postordershow(node *root)
{
    if(root == NULL)
    {
        return;
    }
    postordershow(root->left);
    postordershow(root->right);
    printf("%d ", root->data);
}

int main()
{
    node *root = new node();
    root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);

    insertLeft(root->left, 5);
    insertRight(root->left, 6);
    printf("In order tree: ");
    inorderShow(root);
    cout<< endl;

    printf("Pre order tree: ");
    preorderShow(root);
    cout<< endl;

    printf("Post order tree: ");
    postordershow(root);
    cout<< endl;

}
