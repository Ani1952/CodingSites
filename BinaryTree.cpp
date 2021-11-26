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

class HDpair
{
public:
    int dia;
    int h;
};

class Pair{
public:
	int inc;
	int exc;

};

Node *levelbiuld()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int c1, c2;
        cin >> c1 >> c2;
        Node *curr = q.front();
        q.pop();
        if (c1 != -1)
        {
            curr->left = new Node(c1);
            q.push(curr->left);
        }

        if (c2 != -1)
        {
            curr->right = new Node(c2);
            q.push(curr->right);
        }
    }
    return root;
}

HDpair diameter(Node *root)
{
    HDpair p;
    if (root == NULL)
    {
        p.h = p.dia = 0;
        return p;
    }

    HDpair l = diameter(root->left);
    HDpair r = diameter(root->right);

    p.h = max(l.h, r.h) + 1;

    int d1, d2, d3;
    d1 = l.h + r.h;
    d2 = l.dia;
    d3 = r.dia;

    p.dia = max(d1, max(d2, d3));
    return p;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);

    return max(h1, h2) + 1;
}
int replaceWithSum(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;

    int temp = root->data;
    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    root->data = LS + RS;
    return temp + root->data;
}

pair<int, bool> isBalanced(Node *root)
{
    pair<int, bool> p, l, r;

    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }

    l = isBalanced(root->left);
    r = isBalanced(root->right);

    int h = max(l.first, r.first);

    if (abs(l.first - r.first) <= 1 && l.second && r.second)
    {
        return make_pair(h, true);
    }
    return make_pair(h, false);
}

Pair maxSubsetSum(Node* root){
	Pair p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}

	Pair Left = maxSubsetSum(root->left);
	Pair Right = maxSubsetSum(root->right);

	p.inc = root->data + Left.exc + Right.exc;
	p.exc = max(Left.inc,Left.exc) + max(Right.inc,Right.exc);

	return p;
}

void print(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *t = q.front();
        if (t == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            q.pop();
            cout << t->data << " ";

            if (t->left)
                q.push(t->left);

            if (t->right)
                q.push(t->right);
        }
    }
    return;
}

int main()
{
    Node *root = levelbiuld();
    print(root);

    replaceWithSum(root);
    cout << endl;
    print(root);

    cout << endl;
    cout << diameter(root).dia << endl;

    (isBalanced(root).second) ? cout << "True\n" : cout << "False\n";

    Pair p = maxSubsetSum(root);
	cout <<"Max Sum : "<< max(p.inc, p.exc) <<endl;
    
    return 0;
}