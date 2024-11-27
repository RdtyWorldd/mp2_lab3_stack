#include "../lab3_stack/TCalc.h"
#include "gtest.h"

TEST(TCalc, can_set_and_get_infix)
{
  TCalc c;
  c.setInfix("123");
  EXPECT_EQ(c.getInfix(), "123");
}

TEST(TCalc, can_set_and_get_postfix)
{
  TCalc c;
  c.setPostfix("123");
  EXPECT_EQ(c.getPostfix(), "123");
}


TEST(TCalc, can_convert_infix_to_postfix)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) * (1 - 2^2)");
  c.toPostfix();
  EXPECT_EQ(c.getPostfix(), "2.22 3.33 + 1 2 2 ^ - *");
}


TEST(TCalc, can_calc_postfix)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) * (1 - 2^2)");
  c.toPostfix();
  EXPECT_LE(c.postfixCalc(), -16.65);
}

TEST(TCalc, throw_when_calc_postfix_with_uncorrect_operations_expression)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) * ");
  c.toPostfix();
  ASSERT_ANY_THROW(c.postfixCalc());
}

TEST(TCalc, throw_when_calc_postfix_with_uncorrect_operands_expression)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) 3 ");
  c.toPostfix();
  ASSERT_ANY_THROW(c.postfixCalc());
}

TEST(TCalc, can_calc_infix)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) * (1 - 2^2)");
  EXPECT_LE(c.calc(), -16.65);
}

TEST(TCalc, throw_when_calc_infix_with_uncorrect_operations_expression)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) * ");
  ASSERT_ANY_THROW(c.calc());
}

TEST(TCalc, throw_when_calc_infix_with_uncorrect_operands_expression)
{
  TCalc c;
  c.setInfix("(2.22 + 3.33) 3 ");
  ASSERT_ANY_THROW(c.calc());
}