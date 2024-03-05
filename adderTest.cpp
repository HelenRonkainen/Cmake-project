// adderTest.cpp
#include "adder.hpp"
#include <gtest/gtest.h>

namespace mearlymath {

class CheckoutTest : public ::testing::Test {
public:
  CheckoutTest() : checkout() {}
  ~CheckoutTest() {}

protected:
  Checkout checkout; // Instantiate the Checkout class for testing
};

TEST_F(CheckoutTest, PositiveNumbers) {
  EXPECT_EQ(checkout.add(2, 3), 5);
  EXPECT_EQ(checkout.add(10, 5), 15);
}

TEST_F(CheckoutTest, NegativeNumbers) {
  EXPECT_EQ(checkout.add(-2, -3), -5);
  EXPECT_EQ(checkout.add(-10, -5), -15);
}

TEST_F(CheckoutTest, MixedNumbers) {
  EXPECT_EQ(checkout.add(2, -3), -1);
  EXPECT_EQ(checkout.add(-10, 5), -5);
}

TEST_F(CheckoutTest, ReturnsFizzWith3PassedIn) {
  std::string result = checkout.fizzBuzz(3);
  ASSERT_STREQ("Fizz", result.c_str());
}

TEST_F(CheckoutTest, ReturnsBuzzWith5PassedIn) {
  std::string result = checkout.fizzBuzz(5);
  ASSERT_STREQ("Buzz", result.c_str());
}

TEST_F(CheckoutTest, CanCalculateTotal) {
  checkout.addItemPrice("a", 1);
  checkout.addItemPrice("b", 2);
  checkout.addItem("a");
  checkout.addItem("b");
  int total = checkout.CanCalculateTotal();
  ASSERT_EQ(3, total);
}
TEST_F(CheckoutTest, CanAddDiscount) {
  checkout.AddDiscount("a", 3, 2);
  checkout.addItemPrice("a", 1);
  checkout.AddDiscount("a", 3, 2);
  checkout.addItem("a");
  checkout.addItem("a");
  checkout.addItem("a");
  int total = checkout.CanCalculateTotal();
  ASSERT_EQ(2, total);
}
TEST_F(CheckoutTest, ItemWithNoPriceThrowsEXception) {
  ASSERT_THROW(checkout.addItem("a"), std::invalid_argument);
}
TEST_F(CheckoutTest, CanAddItemPrice) { checkout.addItemPrice("a", 1); }

TEST_F(CheckoutTest, CanAddMultipleItems) {
  checkout.addItemPrice("a", 1);
  checkout.addItemPrice("b", 2);
}
TEST_F(CheckoutTest, CanAddDifferentItems) {
  checkout.addItemPrice("a", 1);
  checkout.addItemPrice("b", 2);
  checkout.addItem("a");
  checkout.addItem("b");
}
TEST_F(CheckoutTest, CanCallTotalWithoutScan) {
  int total = checkout.CanCalculateTotal();
  ASSERT_EQ(0, total);
}
TEST_F(CheckoutTest, areAnagram) {
  char str1[] = "helenlearningcode";
  char str2[] = "codelearninghelen";
  ASSERT_TRUE(checkout.areAnagram(str1, str2));
}

} // namespace mearlymath
