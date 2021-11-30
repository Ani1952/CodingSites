#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key <= root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    Node *root = NULL;
    cout << "Enter size of TREE" << endl;
    int n, a,ele;
    cin >> n;
    vector<int> arr;
    cout<<"Enter Elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    for (auto x : arr)
        root = insert(root, x);

    InOrder(root);
    cout << endl;

    cout<<"Enter Element to search"<<endl;
    cin>>ele;
    (search(root, ele))
        ? cout << "Found" << endl
        : cout << "Not Found" << endl;

    return 0;
}