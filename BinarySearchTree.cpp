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

class LinkedList
{
public:
    Node *head;
    Node *tail;
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

LinkedList tree2LL(Node *root)
{
    LinkedList l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
    }

    else if (root->left != NULL and root->right == NULL)
    {
        LinkedList leftll = tree2LL(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail = root;
    }
    else if (root->left == NULL and root->right != NULL)
    {
        LinkedList rightll = tree2LL(root->right);
        root->right = rightll.head;
        l.head = root;
        l.tail = rightll.tail;
    }

    else
    {
        LinkedList leftll = tree2LL(root->left);
        LinkedList rightll = tree2LL(root->right);

        leftll.tail->right = root;
        root->right = rightll.head;

        l.head = leftll.head;
        l.tail = rightll.tail;
    }

    return l;
}
int nearest(Node *root, int ele)
{

    int close;
    int diff = INT_MAX;
    Node *temp = root;

    while (temp != NULL)
    {
        int curr = abs(temp->data - ele);
        if (curr == 0)
            return temp->data;

        if (curr < diff)
        {
            diff = curr;
            close = temp->data;
        }

        if (temp->data < ele)
            temp = temp->right;
        temp = temp->left;
    }
    return close;
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
    int n, a, ele;
    cin >> n;
    vector<int> arr;
    cout << "Enter Elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    for (auto x : arr)
        root = insert(root, x);

    InOrder(root);
    cout << endl;

    cout << "Enter Element to search" << endl;
    cin >> ele;
    (search(root, ele))
        ? cout << "Found" << endl
        : cout << "Not Found" << endl;

    return 0;
}