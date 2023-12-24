#include <iostream>
#include <stack>
using namespace std;

typedef struct s_node
{
    int data;
    s_node* left;
    s_node* right;

    s_node(int data) : data(data), left(nullptr), right(nullptr) {}
} t_node;

int count_vertices_recursive(t_node* root)
{
    if (root == nullptr)
        return 0;

    int leftVertices = count_vertices_recursive(root->left);
    int rightVertices = count_vertices_recursive(root->right);

    return 1 + leftVertices + rightVertices;
}

int count_vertices_iterative(t_node* root)
{
    if (root == nullptr)
        return 0;

    int vertices = 0;
    stack<t_node*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        t_node* current = nodes.top();
        nodes.pop();
        vertices++;

        if (current->right)
            nodes.push(current->right);

        if (current->left)
            nodes.push(current->left);
    }

    return vertices;
}

int main()
{

    t_node* root = new s_node(1);
    root->left = new s_node(2);
    root->right = new s_node(3);
    root->left->left = new s_node(4);
    root->left->right = new s_node(5);

    cout << "Number of vertices in the binary tree (Recursive): " << count_vertices_recursive(root) << endl;
    cout << "Number of vertices in the binary tree (Iterative): " << count_vertices_iterative(root) << endl;
    return 0;
}
