#include <iostream>
#include <stack>
using namespace std;

/*
* խնդիր N2
* Տպել տրված բինար ծառի գագաթներում պարունակվող արժեքները կատարելով ծառի ուղիղ շրջանցում ռեկեւրսիվ և ոչ ռեկուրսիվ եղանակներով։
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
	st.push(root);
	while (!st.empty())
	{
		t_node* cur_node = st.top();
		cout << cur_node->data << " ";
		st.pop();

		if (cur_node->right)
			st.push(cur_node->right);
		if (cur_node->left)
			st.push(cur_node->left);
	}
	cout << endl;
}

void preorder_recursive(t_node* node)
{
	if (node == NULL)
		return ;
	cout << node->data << " ";
	preorder_recursive(node->left);
	preorder_recursive(node->right);
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

	cout << "Preorder Traversal Iterative" << endl;
	preorder_iterative(root);
	cout << "Preorder Traversal recursive" << endl;
	preorder_recursive(root);
	delete_tree(root);
	return (0);
}
