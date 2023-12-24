#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
* խնդիր N25
* Գտնել իրական թվեր պարունակող բինար ծառի այն մակարդակների համարները, որոնց հանգուցները պարունակում են ծառում առկա փոքրագույն արժեքը։
*/

typedef struct s_node
{
	int data;
	s_node* left;
	s_node* right;
}t_node;

t_node* create_new_node(int data)
{
	t_node* tmp = new t_node;
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return (tmp);
}

int preorder_iterative_find_min(t_node* root)
{
	if (root == NULL)
		return 0;
	stack<t_node*> st;
	int min;
	st.push(root);
	min = root->data;
	while (!st.empty())
	{
		t_node* cur_node = st.top();
		if (cur_node->data < min)
			min = cur_node->data;
		//cout << cur_node->data << " ";
		st.pop();

		if (cur_node->right)
			st.push(cur_node->right);
		if (cur_node->left)
			st.push(cur_node->left);
	}
	return (min);
}

void print_min_lvls(t_node* root, int min)
{
	if (root == NULL)
	{
		cout << "0\n";
		return;
	}

	int lvl = 0;
	queue<t_node*> q;
	queue<int> lvls;
	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count)
		{
			t_node* cur_node = q.front();
			if (cur_node->data == min)
				lvls.push(lvl + 1);
			cout << cur_node->data << " ";
			q.pop();

			if (cur_node->left)
				q.push(cur_node->left);

			if (cur_node->right)
				q.push(cur_node->right);
			count--;
		}
		lvl++;
	}
	cout << endl << "Levels which contain minimum value" <<endl;

	while (!lvls.empty())
	{
		cout << lvls.front() << " ";
		lvls.pop();
	}
	cout << endl;
}

int main()
{
	t_node* root = create_new_node(2);
	root->left = create_new_node(3);
	root->right = create_new_node(4);
	root->left->left = create_new_node(5);
	root->left->right = create_new_node(6);
	root->right->left = create_new_node(1);
	root->right->right = create_new_node(9);
	root->left->left->right = create_new_node(1);

	// Non recursive
	cout << "Printing tree in leveorder" << endl;
	print_min_lvls(root, preorder_iterative_find_min(root));

	// Recursive

	return (0);
}