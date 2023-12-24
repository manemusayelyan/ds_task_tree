#include <iostream>
#include <queue>
using namespace std;

/*
* խնդիր N16
* Գտնել տրված բինար ծառի այն մակարդակների համարները, որոնք պարունակում են ամենաշատ թվով գագաթներ։
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

void print_lvls_with_max_num_of_nodes(t_node* root)
{
	if (root == NULL)
		return;

	int max_count = 0;

	queue<t_node*> q;
	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		if (count > max_count)
			max_count = count;

		while (count)
		{
			t_node* cur_node = q.front();
			q.pop();

			if (cur_node->left)
				q.push(cur_node->left);

			if (cur_node->right)
				q.push(cur_node->right);

			count--;
		}
	}

	cout << "Levels with the maximum number of nodes: ";
	int lvl = 0;
	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		if (count == max_count)
			cout << lvl + 1 << " ";

		while (count)
		{
			t_node* cur_node = q.front();
			q.pop();

			if (cur_node->left)
				q.push(cur_node->left);

			if (cur_node->right)
				q.push(cur_node->right);

			count--;
		}

		lvl++;
	}

	cout << endl;
}

int main()
{
	t_node* root = create_new_node(1);
	root->left = create_new_node(2);
	root->right = create_new_node(3);
	root->left->left = create_new_node(4);
	root->left->right = create_new_node(5);
	root->right->left = create_new_node(6);
	root->right->right = create_new_node(7);
	root->left->left->left = create_new_node(8);
	root->left->left->right = create_new_node(9);
	root->left->right->left = create_new_node(10);
	root->left->right->right = create_new_node(11);
	// Non recursive
	cout << "Printing tree in leveorder" << endl;
	print_tree_levelorder(root);
	print_lvls_with_max_num_of_nodes(root);
	delete_tree(root);
	return (0);
}
