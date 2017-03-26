#include "Tree_from_Array.h"

void Init_tree(CNode **tree, int *ar, int size_ar) {
	std::stack <int> s;

	int first = 0;
	int last = size_ar - 1;
	int temp = 0;
	bool b_flag = 0;
	int i_flag = (first + last) / 2;
	int *temp_ar = new int[size_ar];
	for (int i = 0; i < size_ar; ++i)
		temp_ar[i] = 0;

	s.push(last);
	while (first != last) {
		if ((first >= i_flag) && (!b_flag)) {
			temp = first + (s.top() - first) / 2 + 1;
			b_flag = 1;
		} else {
			temp = first + (s.top() - first) / 2;
		}

		if (temp_ar[temp] == 0) {
			*tree = Add_leaf(*tree, ar[temp]);
			s.push(temp);
			temp_ar[temp] = 1;
		} else { 
			first++;
			s.pop();
		}

		if (first == temp) {
			s.pop();
			first = s.top();
			s.pop();
			}
		}

	if (s.empty())
		*tree = Add_leaf(*tree, ar[last]);
}

CNode *Add_leaf(CNode *root, int val) {
	if (root == NULL) {
		root = new CNode;
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

void Print_tree(CNode *tree) {
	std::queue <CNode*> q;
	q.push(tree);
	cout << "STRUCTURE OF TREE" << endl;
	while (!q.empty()) {
		cout << "------------------------------------" << endl;
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			CNode *temp = q.front();
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
