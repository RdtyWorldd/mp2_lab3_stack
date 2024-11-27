#include "../lab3_stack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> stack(10));
}

TEST(TStack, cant_create_too_large_stack)
{
  ASSERT_ANY_THROW(TStack<int> stack(STACK_MAX_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> stack(-1));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> s(5);
  ASSERT_NO_THROW(TStack<int> s1(s));
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
  TStack<int> s(5);
  for (int i = 0; i < 5; i++)
	s.push(i);
  TStack<int> s1(s);
  EXPECT_EQ(s, s1);
}

TEST(TStack, copied_stack_has_its_own_memory)
{
  TStack<int> s(5);
  for (int i = 0; i < 5; i++)
	s.push(i);
  TStack<int> s1(s);
  s1.pop();
  s1.push(6);
  EXPECT_NE(s1.pop(), s.pop());
}

TEST(TStack, can_check_top_element)
{
  TStack<int> s(3);
  s.push(3);
  EXPECT_EQ(s.top(), 3);
}

TEST(TStack, can_push_and_pop_element)
{
  TStack<int> s(3);
  s.push(3);
  EXPECT_EQ(s.pop(), 3);
}

TEST(TStack, isFull_return_true_when_stack_full)
{
  TStack<int> s(3);
  for (int i = 0; i < 3; i++)
	s.push(i);
  EXPECT_EQ(s.isFull(), true);
}

TEST(TStack, isFull_return_false_when_stack_isnt_full)
{
  TStack<int> s(3);
  s.push(1);
  EXPECT_EQ(s.isFull(), false);
}

TEST(TStack, isFull_return_true_when_stack_empty)
{
  TStack<int> s(3);
  EXPECT_EQ(s.isEmpty(), true);
}

TEST(TStack, isEmpty_return_false_when_stack_isnt_full)
{
  TStack<int> s(3);
  s.push(1);
  EXPECT_EQ(s.isEmpty(), false);
}

TEST(TStack, throw_when_push_to_full_stack)
{
  TStack<int> s(3);
  for (int i = 0; i < 3; i++)
	s.push(i);
  ASSERT_ANY_THROW(s.push(4));
}

TEST(TStack, throw_when_pop_from_empty_stack)
{
  TStack<int> s(3);
  ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, cleared_stack_isEmpty)
{
  TStack<int> s(3);
  for (int i = 0; i < 3; i++)
	s.push(i);
  s.clear();
  EXPECT_EQ(s.isEmpty(), true);
}

TEST(TStack, can_assign_stack_to_itself)
{
  TStack<int> s1(3), s2(3);
  for (int i = 0; i < 3; i++) {
	s1.push(i);
	s2.push(i);
  }
  s1 = s1;
  EXPECT_EQ(s1, s2);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
  TStack<int> s1(3), s2(3), res(3);
  for (int i = 0; i < 3; i++) {
	s1.push(i);
	s2.push(3);
	res.push(3);
  }
  s1 = s2;
  EXPECT_EQ(s1, res);
}

TEST(TStack, can_assign_stacks_with_of_different_size)
{
  TStack<int> s1(3), s2(4),res(4);
  for (int i = 0; i < 3; i++) {
	s1.push(i);
  }
  for (int i = 0; i < 4; i++) {
	s2.push(i); 
	res.push(i);
  }
  s1 = s2;
  EXPECT_EQ(s1, res);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
  TStack<int> s1(3);
  for (int i = 0; i < 3; i++) {
	s1.push(i);
  }
  EXPECT_EQ(s1, s1);
}

TEST(TStack, compare_equal_stacks_return_true)
{
  TStack<int> s1(3), s2(3);
  for (int i = 0; i < 3; i++) {
	s1.push(i);
	s2.push(i);
  }
  s1 = s2;
  EXPECT_EQ(s1, s2);
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
  TStack<int> s1(3), s2(4);
  for (int i = 0; i < 3; i++) {
	s1.push(i);
  }
  for (int i = 0; i < 4; i++) {
	s2.push(i);
  }
  EXPECT_NE(s1, s2);
}