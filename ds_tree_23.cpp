#include <iostream>
#include <stack>
using namespace std;

/*
* խնդիր N23
* Իրական թվեր պարունակող բինար ծառի համար գտնել զրոյական արժեքով հանգույցների քանակը։
*/

typedef struct s_node
{
	int data;
	s_node* left;
	s_node* right;
} t_node;


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

void preorder_iterative(t_node* root)
{
	if (root == NULL)
		return;
	stack<t_node*> st;
	int count_zeros = 0;
	st.push(root);
	while (!st.empty())
	{
		t_node* cur_node = st.top();
		if (!cur_node->data)
			count_zeros++;
		cout << cur_node->data << " ";
		st.pop();

		if (cur_node->right)
			st.push(cur_node->right);
		if (cur_node->left)
			st.push(cur_node->left);
	}
	cout << endl;
	cout << count_zeros << " zero value nodes in given tree" << endl;
}

int preorder_recursive(t_node* node)
{
	if (node == NULL)
		return 0;
	int count = 0;
	if (!node->data)
		count++;
	cout << node->data << " ";
	count += preorder_recursive(node->left);
	count += preorder_recursive(node->right);
	return (count);
}
int main()
{
	t_node* root = create_new_node(1);
	root->left = create_new_node(2);
	root->right = create_new_node(0);
	root->left->left = create_new_node(0);
	root->left->left->left = create_new_node(8);
	root->left->right = create_new_node(5);
	root->left->right->left = create_new_node(0);
	root->right->left = create_new_node(6);
	root->right->right = create_new_node(0);

	preorder_iterative(root);
	cout << endl;
	cout << endl << preorder_recursive(root) << " zero value nodes in given tree" << endl;
	delete_tree(root);
	return (0);
}
