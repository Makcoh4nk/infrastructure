#include "Tree_from_Array.h"

Branch **find(Branch **root, int value) {
	Branch **temp = root;
	while (*root) {
		if ((*root)->data == value) {
			return root;
		}
		else if ((*root)->data < value) {
			root = &(*root)->right;
		}
		else { root = &(*root)->left; }
	}
	return root;
}

void Init_tree(Branch **tree) {
	*tree = Add_leaf((*tree), 10);
	*tree = Add_leaf((*tree), 12);
	*tree = Add_leaf((*tree), 8);
	*tree = Add_leaf((*tree), 6);
	*tree = Add_leaf((*tree), 7);
	*tree = Add_leaf((*tree), 4);
}

Branch *Add_leaf(Branch *root, int val) {
	if (root == NULL) {
		root = new Branch;
		root->data = val;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > val) {
		root->left = Add_leaf(root->left, val);
	}
	else if (root->data < val) {
		root->right = Add_leaf(root->right, val);
	}
	return root;
}

void Print_tree(Branch *tree) {
	std::queue <Branch*> q;
	q.push(tree);
	cout << "STRUCTURE OF TREE" << endl;
	while (!q.empty()) {
		cout << "------------------------------------" << endl;
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			Branch *temp = q.front();
			q.pop();
			if (temp == NULL) continue;
			cout << "   Data: " << temp->data << endl;
			cout << "   Current address: " << temp << endl;
			cout << "   Left branch: " << temp->left << endl;
			cout << "   Right branch: " << temp->right << endl << endl;
			q.push(temp->left);
			q.push(temp->right);
		}
	}
}
