#include <gtest/gtest.h>
#include "tree.h"

TEST(Tree, CanCreateEmptyTree) {
    EXPECT_NO_THROW(Branch *tree = NULL);
}

TEST(Tree, CanInitializeTree) {
    Branch *tree = NULL;
    EXPECT_NO_THROW(Init_tree(&tree));
}

TEST(Tree, CanFindElement_3) {
    Branch *tree = NULL;
    Init_tree(&tree);
    Branch **leaf = find(&tree, 10);
    EXPECT_EQ(10, (*leaf)->data);
}

TEST(Tree, CanFindElement_5) {
    Branch *tree = NULL;
    Init_tree(&tree);
    Branch **leaf = find(&tree, 7);
    EXPECT_EQ(7, (*leaf)->data);
}

TEST(Tree, CanFindAddressForInsert_15) {
    Branch *tree = NULL;
    Init_tree(&tree);
    Branch **act = &(tree->right->left);
    Branch **exp = find(&tree, 11);
    EXPECT_EQ(act, exp);
}

TEST(Tree, CanFindAddressForInsert_5) {
    Branch *tree = NULL;
    Init_tree(&tree);
    Branch **act = &(tree->left->left->left->right);
    Branch **exp = find(&tree, 5);
    EXPECT_EQ(act, exp);
}

int main(int ac, char* av[]) {
    srand(unsigned(time(NULL)));
    Branch *tree = NULL;
    Init_tree(&tree);
    Print_tree(tree);
    cout << endl << "SEARCHING OF VALUE" << endl;
    cout << "|------------------------------------------------" << endl;
    for (int i = 1; i < 4 + rand() % 3; ++i) {
        int value =  i * (rand() % 3 + 1);
        cout << "|      Data       |     " << value << endl;
        if (*find(&tree, value) != NULL) {
            cout << "|  Found_address  |  ";
            cout << "Address of branch: " << *find(&tree, value) << endl;
        } else {
            cout << "|  Found_address  |  ";
            cout << "Address for insert: " << find(&tree, value) << endl;
        }
        cout << "|------------------------------------------------" << endl;
    }
    cout << endl;

    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
