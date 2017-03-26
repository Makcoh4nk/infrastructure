#include <gtest/gtest.h>
#include "Array.h"

TEST(Conversion, CorrectConversionArray_1_elem) {
	const int size = 1;
	int temp[size] = { 1 };
	int *act = Conversion(temp, size);
	int exp[size] = { 1 };
	for (int i = 0; i < size; ++i)
		EXPECT_EQ(act[i], exp[i]);
}

TEST(Conversion, CorrectConversionArray_3_elem) {
	const int size = 3;
	int temp[size] = { 10,3,24,};
	int *act = Conversion(temp, size);
	int exp[size] = { 72,240,30 };
	for (int i = 0; i < size; ++i)
		EXPECT_EQ(act[i], exp[i]);
}

TEST(Conversion, CorrectConversionArray_5_elem) {
	const int size = 5;
	int temp[size] = { 1,2,3,4,5 };
	int *act = Conversion(temp, size);
	int exp[size] = { 120,60,40,30,24 };
	for (int i = 0; i < size; ++i)
		EXPECT_EQ(act[i], exp[i]);
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
