#include <iostream>
#include <queue>
using namespace std;

/*
* խնդիր N51
* Որոշել ամբողջ թվեր պարունակող բինար ծառի մինչև տրված i-րդ մակարդակը եղած տարրերի գումարը։
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

int sum_of_nodes(t_node* root, int i)
{
	if (root == NULL)
		return 0;

	int level = 0;
	queue<t_node*> q;
	q.push(root);

	int sum = 0;
	while (!q.empty())
	{
		int count = q.size();
		while (count)
		{
			t_node* cur_node = q.front();
			if (level + 1 < i)
				sum += cur_node->data;
			q.pop();

			if (cur_node->left)
				q.push(cur_node->left);

			if (cur_node->right)
				q.push(cur_node->right);
			count--;
		}
		level++;
	}
	cout << endl;
	return (sum);
}

void print_tree_levelorder(t_node* root)
{
	if (root == NULL)
		return;

	queue<t_node*> q;
	q.push(root);

	while (!q.empty())
	{
		t_node* cur_node = q.front();
		cout << cur_node->data << " ";
		q.pop();

		if (cur_node->left)
			q.push(cur_node->left);
		if (cur_node->right)
			q.push(cur_node->right);
	}
	cout << endl;
}

int main()
{
	t_node* root = create_new_node(1);
	root->left = create_new_node(2);
	root->right = create_new_node(3);
	root->left->left = create_new_node(4);
	root->left->left->left = create_new_node(8);
	root->left->right = create_new_node(5);
	root->left->right->left = create_new_node(9);
	root->right->left = create_new_node(6);
	root->right->right = create_new_node(7);

	cout << "Binary tree levelorder traversal" << endl;
	print_tree_levelorder(root);
	cout << "Sum of nodes till third level is: " << sum_of_nodes(root, 3);
	return (0);
}