#include <iostream>
#include <queue>
using namespace std;

/*
* խնդիր N39
* Բինար ծառի յուրաքանչյուր հանգույցում գրանցել նրա մակարդակի համարը։
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

void delete_tree(t_node* root)
{
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
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


void print_levels_of_nodes(t_node* root)
{
	if (root == NULL)
		return;

	int level = 1;
	queue<t_node*> q;
	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count)
		{
			t_node* cur_node = q.front();
			cur_node->data = level;
			cout << cur_node->data << " ";
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

}

void update_levels_recursive(t_node* root, int level)
{
	if (root == NULL)
		return;

	root->data = level;
	update_levels_recursive(root->left, level + 1);
	update_levels_recursive(root->right, level + 1);
}

void print_levels_of_nodes_recursive(t_node* root)
{
	if (root == NULL)
		return;
	update_levels_recursive(root, 1);
	print_tree_levelorder(root);
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

	// Recursive version call
	cout << "Binary tree levelorder traversal" << endl;
	print_tree_levelorder(root);
	cout << "Changed all the values of nodes to their level number" << endl;
	print_levels_of_nodes_recursive(root);
	cout << endl;

	// Non recursive version call
	cout << "Binary tree levelorder traversal" << endl;
	print_tree_levelorder(root);
	cout << "Changed all the values of nodes to their level number" << endl;
	print_levels_of_nodes(root);
	delete_tree(root);
	return (0);
}
