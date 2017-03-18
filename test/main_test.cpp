#include <gtest/gtest.h>
#include "Tree_from_Array.h"

int main(int ac, char* av[]) {
	Branch *tree = NULL;
	int temp[5] = { 1,2,5,7,9 };
	Init_tree(&tree, temp);
	Print_tree(tree);

  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
