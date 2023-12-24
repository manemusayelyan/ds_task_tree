#include <iostream>
#include <queue>
#include <climits>
using namespace std;
/*
* խնդիր N47
* Որոշել տրված բինար ծառի մեծագույն տարրը պարունակող առաջին մակարդակի հանգույցների քանակը։
*/
typedef struct s_node
{
    int val;
    struct s_node* left;
    struct s_node* right;
    s_node(int x) : val(x), left(nullptr), right(nullptr) {}
} t_node;

void delete_tree(t_node* root)
{
    if (root == NULL)
        return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int find_level_of_max(t_node* root) {
    if (root == nullptr)
        return 0;

    int max_val = INT_MIN;
    int level = 0;

    queue<t_node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i)
        {
            t_node* current = q.front();
            q.pop();

            if (current->val > max_val)
            {
                max_val = current->val;
                level = size;
            }

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }

    return level;
}

int count_nodes_at_level(t_node* root, int target_level) {
    if (root == nullptr)
        return 0;

    int current_level = 1;
    queue<t_node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            t_node* current = q.front();
            q.pop();

            if (current_level == target_level) {
                return size;
            }

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }

        current_level++;
    }

    return 0;
}

int main() {
    t_node* root = new t_node(3);
    root->left = new t_node(5);
    root->right = new t_node(8);
    root->left->left = new t_node(1);
    root->left->right = new t_node(4);
    root->right->left = new t_node(6);

    int target_level = find_level_of_max(root);

    if (target_level > 0) {
        int node_count = count_nodes_at_level(root, target_level);
        cout << target_level << " " << node_count << endl;
    }
    else
        cout << "0\n" << endl;
    delete_tree(root);
    return 0;
}
