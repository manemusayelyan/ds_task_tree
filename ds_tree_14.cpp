#include <iostream>
#include <queue>
using namespace std;

/*
* խնդիր N14
* Տպել տրված բինար ծառի յուրաքանչյուր մակարդակում պարունակվող հանգույցների քանակը։
*/
typedef struct s_node
{
	int data;
	s_node* left;
	s_node* right;
	s_node(int data) : data(data), left(nullptr), right(nullptr) {}
} t_node;

void node_count_on_lvls(t_node* root)
{
	t_node* tmp = root;
	queue<t_node*> q;
	int lvl = 1;
	int k = 1;
	int j;

	q.push(tmp);
	while (!q.empty())
	{
		j = 0;
		cout << "Level " << lvl << " has " << k << " nodes" << endl;
		for (int i = 0; i < k; i++)
		{
			tmp = q.front();
			q.pop();
			if (tmp->left)
			{
				q.push(tmp->left);
				j++;
			}
			if (tmp->right)
			{
				q.push(tmp->right);
				j++;
			}
		}
		lvl++;
		k = j;
	}
}

int main()
{
	t_node* root = new s_node(1);
	root->left = new s_node(2);
	root->right = new s_node(3);
	root->left->left = new s_node(4);
	root->left->right = new s_node(5);

	node_count_on_lvls(root);
	return 0;
}
