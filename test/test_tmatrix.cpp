#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(2);
	TMatrix<int> copy(m);
	EXPECT_EQ(m, copy);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(2);
	TMatrix<int> m1(m);
	EXPECT_NE(&m, &m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(3);
	EXPECT_EQ(3, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(3);
	TVector<int> v(3);
	for (int i = 0; i < 3; i++)
		v[i] = i * i - 3;
	m[1] = v;
	EXPECT_EQ(v, m[1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(3);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(3);
	ASSERT_ANY_THROW(m[3]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(3);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(m);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i; j++)
			m[i][j] = 7;
	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(4);
	m1 = m;
	EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(4);
	ASSERT_NO_THROW(m1 = m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(m);
	EXPECT_EQ(true, m1 == m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(3); 
	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(4);
	EXPECT_EQ(false, m1 == m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(3);
	for (int i = 0; i < 3; i++)
		m1[i][2 - i] += 8;
	TMatrix<int> standart(m);
	for (int i = 0; i < 3; i++)
		standart[i] = m1[i] + standart[i];
	EXPECT_EQ(standart, (m1 + m));
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(4);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2-i; j++)
			m1[i][j] = 1 + i - j;
	TMatrix<int> standart(m);
	for (int i = 0; i < 3; i++)
		standart[i] = m1[i] - standart[i];
	EXPECT_EQ(standart, (m1 - m));
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(3);
	TMatrix<int> m1(4);
	ASSERT_ANY_THROW(m1 - m);
}

