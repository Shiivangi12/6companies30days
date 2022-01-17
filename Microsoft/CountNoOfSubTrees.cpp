#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* getNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countSubtreesWithSumXUtil(Node* root, int x)
{
    static int count=0;
    static Node* ptr=root;
    int l=0,r=0;
    if(root==NULL)
    return 0;

    l+=countSubtreesWithSumXUtil(root->left,x);

    r+=countSubtreesWithSumXUtil(root->right,x);

    if(l+r+root->data==x)
    count++;

    if(ptr!=root)
        return l+root->data+r;

    return count;


}

int main()
{
    Node* root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);

    int x = 7;

    cout << "Count = "
        << countSubtreesWithSumXUtil(root, x);

    return 0;
}
