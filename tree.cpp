#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

bool failed = false;

struct Node
{
	bool have_value;
	int v;
	Node *left,*right;
	Node():have_value(false),left(NULL),right(NULL){};
};
Node *root;

Node* newnode()
{
	return new Node();
}

void addnode(int v,char *s)
{
	int n = strlen(s);	
	Node *u = root;
	for(int i = 0;i < n;i++)
	{
		if(s[i] == 'L')
		{
			if(u->left == NULL) 
				u->left = newnode();
			u = u->left;
		}
		else if(s[i] == 'R')
		{
			if(u->right == NULL)
				u->right = newnode();
			u = u->right;
		}
	}
	if(u->have_value == true)
		failed = true;	
		
	u->have_value = true;
	u->v = v;	
}

void remove_tree(Node *u)
{
	if(u == NULL)
		return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}

bool bfs(vector<int> &res)
{
	queue<Node*> q;
	Node *u = NULL;
	res.clear();
	
	q.push(root);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		if(u->have_value == false)
			return false;
		res.push_back(u->v);
		if(u->left != NULL) q.push(u->left);
		if(u->right != NULL) q.push(u->right);	
	}
	return true;
}

bool dfs(vector<int> &res)
{
	stack<Node*> s;
	Node *u = NULL;
	
	s.push(root);
	while(!s.empty())
	{
		u = s.top();
		s.pop();
		if(u->have_value == false)
			return false;
		res.push_back(u->v);
		if(u->left != NULL) s.push(u->left);
		if(u->right != NULL) s.push(u->right);
	}	
}

int main()
{
	char s[256];
	root = newnode();
	while(1)
	{
		cin >> s;
		if(!strcmp(s,"()"))
			break;
		int v;
		sscanf(&s[1],"%d",&v);
		addnode(v,strchr(s,',')+1);
	}
	if(failed == true)
	{
		cout << -1 <<endl;
		remove_tree(root);
		return 0;
	}
	vector<int> res;
	if(dfs(res))
	{
		int num = res.size();
		for(int i = 0 ; i < num ; i++)
		{
			cout << res.at(i)<<' ';
		}	
		cout << endl;
	}
	else 
		cout << -1 << endl;

	remove_tree(root);		

	return 0;	
}
