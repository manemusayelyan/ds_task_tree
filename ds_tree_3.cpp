#include <iostream>
#include <stack>
using namespace std;

/*
* խնդիր N3
* Տպել տրված բինար ծառի գագաթներում պարունակվող արժեքները կատարելով ծառի հակադարձ շրջանցում ռեկեւրսիվ և ոչ ռեկուրսիվ եղանակներով։
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

void print_postorder_recursive(t_node* node)
{
    if (node == NULL)
        return;
    print_postorder_recursive(node->left);
    print_postorder_recursive(node->right);
    cout << node->data << " ";
}

void print_postorder_iterative(t_node* root)
{
    if (root == NULL)
        return;
    stack<t_node*> s1, s2;

    s1.push(root);
    t_node* node;
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node); 
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
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

    // Iterative
    cout << "Non recursive postorder traversal of binary tree" << endl;
    print_postorder_iterative(root);
    // Recursive
    cout << "Recursive postorder traversal of binary tree" << endl;
    print_postorder_recursive(root);
    delete_tree(root);
    return (0);
}
