#include "Tree_from_Array.h"

int main() {
	CNode *tree = NULL;
	const int size_ar = 5;
	int temp_ar[size_ar] = { 0,1,2,3,4 };

	Init_tree(&tree, temp_ar, size_ar);
	cout << "ARRAY: " << endl;
	for (int i = 0; i < size_ar; ++i)
		cout << temp_ar[i] << ' ';
	cout << endl << endl;
	Print_tree(tree);
}
