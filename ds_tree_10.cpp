#include <iostream>
#include <queue>
using namespace std;

/*
* խնդիր N10
* Գտնել տրված բինար ծառի բարձրությունը։
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

int tree_height_recursive(t_node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int left_height = tree_height_recursive(node->left);
		int right_height = tree_height_recursive(node->right);
		if (left_height > left_height)
			return (left_height + 1);
		else
			return (left_height + 1);
	}
}

void print_levelorder_height(t_node* root)
{
	if (root == NULL)
	{
		cout << "0\n";
		return ;
	}

	int height = 0;
	queue<t_node*> q;
	q.push(root);

	while (!q.empty())
	{
		int count = q.size();
		while (count)
		{
			t_node* cur_node = q.front();
			cout << cur_node->data << " ";
			q.pop();

			if (cur_node->left)
				q.push(cur_node->left);

			if (cur_node->right)
				q.push(cur_node->right);
			count--;
		}
		height++;
	}
	cout << endl;
	cout << "Height of the given binary tree is : " << height << endl;

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

	// Non recusive
	print_levelorder_height(root);
	cout << endl;
	// Recursive
	cout << "Height = " << tree_height_recursive(root);
	return (0);
}
