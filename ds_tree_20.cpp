#include <iostream>
#include <stack>
using namespace std;

/*
* խնդիր N20
* Գտնել տրված բինար ծառի երկու որդի ունեցող հանգույցների քանակը։
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

void preorder_iterative(t_node* root)
{
	if (root == NULL)
		return;
	stack<t_node*> st;
	int count = 0;
	st.push(root);
	while (!st.empty())
	{
		t_node* cur_node = st.top();
		if (cur_node->left && cur_node->right)
			count++;
		cout << cur_node->data << " ";
		st.pop();

		if (cur_node->right)
			st.push(cur_node->right);
		if (cur_node->left)
			st.push(cur_node->left);
	}
	cout << endl;
	cout << "Number of nodes with 2 childs in given tree is " << count << endl;
}

int preorder_recursive(t_node* node)
{
	if (node == NULL)
		return 0;
	int count = 0;
	if (node->left && node->right)
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
	root->right = create_new_node(3);
	root->left->left = create_new_node(4);
	root->left->left->left = create_new_node(8);
	root->left->right = create_new_node(5);
	root->left->right->left = create_new_node(9);
	root->right->left = create_new_node(6);
	root->right->right = create_new_node(7);

	preorder_iterative(root);
	cout << endl;
	cout << endl << "Number of nodes with 2 childs in given tree is " << preorder_recursive(root) << endl;
	return (0);
}
