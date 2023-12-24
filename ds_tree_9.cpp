#include <iostream>
#include <stack>
using namespace std;
/*
* խնդիր N9
* Գտնել տրված բինար ծառի տերևների քանակը։
*/
typedef struct s_node
{
    int data;
    s_node* left;
    s_node* right;

    s_node(int data) : data(data), left(nullptr), right(nullptr) {}
} t_node;

void delete_tree(t_node* root)
{
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int count_leaves_recursive(t_node* root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;
    int left_leaves = count_leaves_recursive(root->left);
    int right_leaves = count_leaves_recursive(root->right);

    return left_leaves + right_leaves;
}

int count_leaves_iterative(t_node* root)
{
    if (root == nullptr)
        return 0;

    int leaves = 0;
    stack<t_node*> st;
    st.push(root);

    while (!st.empty())
    {
        t_node* cur = st.top();
        st.pop();

        if (!cur->left && !cur->right)
            leaves++;

        if (cur->right)
            st.push(cur->right);

        if (cur->left)
            st.push(cur->left);
    }

    return leaves;
}

int main()
{
    t_node* root = new s_node(1);
    root->left = new s_node(2);
    root->right = new s_node(3);
    root->left->left = new s_node(4);
    root->left->right = new s_node(5);

    cout << "Number of leaves in the binary tree: (Recursive) " << count_leaves_recursive(root) << endl;
    cout << "Number of leaves in the binary tree: (Iterative) " << count_leaves_iterative(root) << endl;
    delete_tree(root);
    return 0;
}
