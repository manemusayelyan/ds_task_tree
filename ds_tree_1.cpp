#include <iostream>
#include <stack>
using namespace std;

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

void print_inorder_iterative(t_node* root)
{
    stack<t_node*> st;
    t_node *cur_node = root;

    while (cur_node || !st.empty())
    {
        while (cur_node)
        {
            st.push(cur_node);
            cur_node = cur_node->left;
        }
        cur_node = st.top();
        st.pop();

        cout << cur_node->data << " ";
        cur_node = cur_node->right;
    }
    cout << endl;
}

void print_inorder_recursive(t_node* node)
{
    if (node == NULL)
        return;
    print_inorder_recursive(node->left);
    cout << node->data << " ";
    print_inorder_recursive(node->right);
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
    cout << "Non recursive inorder traversal of binary tree" << endl;
    print_inorder_iterative(root);
    // Recursive
    cout << "Recursive inorder traversal of binary tree" << endl;
    print_inorder_recursive(root);
    return (0);
}