#include <iostream>
#include <map>
#include <math.h>
#include <string>

using namespace std;
#define NO_OF_CHARS 256
namespace mearlymath {

class Checkout {
public:
  Checkout();
  ~Checkout();

  static bool isMultiple(int value, int base);
  static int add(int a, int b);
  static float add(float a, float b);
  static std::string fizzBuzz(int value);

  void addItemPrice(const std::string& item, int price);
  void addItem(const std::string& item);
  int CanCalculateTotal();
  void AddDiscount(const std::string& item, int nbrOfItems, int discountPrice);
  static bool areAnagram(const char *str1, const char *str2);

protected:
  struct Discount {
    int numberofitems;
    int discountPrice;
  };

  int total;
  std::map<string, int> prices;
  std::map<string, Discount> discounts;
  std::map<string, int> items;

  void calculateItem(const string& item, int itemCnt);
  void calculateDiscount(const std::string& item, int itemCnt, Discount discount);
};
} // namespace mearlymath