// adder.cpp
#include "adder.hpp"
#include <bits/stdc++.h>
#include <iostream>

namespace mearlymath {

Checkout::Checkout() : total(0), prices(), discounts(), items(){
  // constructor implementation
}

Checkout::~Checkout() {
  // destructor implementation
}

auto Checkout::isMultiple(int value, int base) -> bool { return (0 == (value % base)); }

auto Checkout::add(int a, int b) -> int { return a + b; }

auto Checkout::add(float a, float b) -> float { return a + b; }

auto Checkout::fizzBuzz(int value) -> std::string {
  if (isMultiple(value, 3)) {
    return "Fizz";
  }
  if (isMultiple(value, 5)) {
    return "Buzz";
  }
  return std::to_string(value);
}

void Checkout::addItemPrice(const std::string& item, int price) {
  prices[item] = price;
}

void Checkout::addItem(const std::string& item) {
  auto priceIter = prices.find(item);
  if (priceIter == prices.end()) {
    throw std::invalid_argument("invalid item. No price");
  }
  items[item]++;
}

void Checkout::AddDiscount(const std::string& item, int nbrOfItems,
                           int discountPrice) {
  Discount discount;
  discount.numberofitems = nbrOfItems;
  discount.discountPrice = discountPrice;
  discounts[item] = discount;
}

auto Checkout::CanCalculateTotal() -> int {
  total = 0;
  for (auto & itemIter : items) {
    string item = itemIter.first;
    int itemCnt = itemIter.second;
    calculateItem(item, itemCnt);
  }
  return total;
}

void Checkout::calculateItem(const string& item, int itemCnt) {
  std::map<string, Discount>::iterator discountIter;
  discountIter = discounts.find(item);
  if (discountIter != discounts.end()) {
    Discount discount = discountIter->second;
    calculateDiscount(item, itemCnt, discount);
  } else {
    total += itemCnt * prices[item];
  }
}

void Checkout::calculateDiscount(const std::string& item, int itemCnt,
                                 Discount discount) {
  if (itemCnt >= discount.numberofitems) {
    int nbrOfDiscounts = itemCnt / discount.numberofitems;
    total += nbrOfDiscounts * discount.discountPrice;
    int remainingItems = itemCnt % discount.numberofitems;
    total += remainingItems * prices[item];
  } else {
    total += itemCnt * prices[item];
  }
}

auto Checkout::areAnagram(const char *str1, const char *str2) -> bool {
  int count[NO_OF_CHARS] = {0};
  int count2[NO_OF_CHARS] = {0};
  int i;

  for (i = 0; (str1[i] != 0) && (str2[i] != 0); i++) {
    count[static_cast<unsigned char>(str1[i])]++;
    count2[static_cast<unsigned char>(str2[i])]++;
  }

  if ((str1[i] != 0) || (str2[i] != 0)) {
    return false;
}
  for (i = 0; i < NO_OF_CHARS; i++) {
    if (count[i] != count2[i]) {
      return false;
}
}
  return true;
}

} // namespace mearlymath
