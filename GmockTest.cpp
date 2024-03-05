/*
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using ::testing::_;
using ::testing::Return;
class QueueInterface {
public:
  virtual ~QueueInterface() { ; }
  virtual void enqueue(int data) = 0;
  virtual int dequeue() = 0;
};

class Mockqueue : public QueueInterface {
public:
  MOCK_METHOD0(dequeue, int());
  MOCK_METHOD1(enqueue, void(int data));
};
class DataHolder {
public:
  DataHolder(QueueInterface *queue) : queue(queue) { ; }
  void addData(int data) { queue->enqueue(data); }
  int getData() { return queue->dequeue(); }

protected:
  QueueInterface *queue;
};

TEST(GMockTests, CanAddData) {
  Mockqueue myMockObj;
  DataHolder dh(&myMockObj);

  EXPECT_CALL(myMockObj, enqueue(_));
  dh.addData(1);
}
TEST(GMockTests, CanAddAndGetData) {
  Mockqueue myMockObj;
  DataHolder dh(&myMockObj);
  EXPECT_CALL(myMockObj, enqueue(1));
  EXPECT_CALL(myMockObj, dequeue()).WillOnce(Return(1));
  dh.addData(1);
  int data = dh.getData();
  ASSERT_EQ(1, data);
}
TEST(MatchersTest, MatchersAreUser) {
  std::string test_string("Hello, this is a test string. We are here to help");
  EXPECT_THAT(test_string, testing::StartsWith("Hello"));
  EXPECT_THAT(test_string, MatchesRegex(".*is. *help.*"));

  int test_value = 10;
  EXPECT_THAT(test_value, Allof(Gt(1), Lt(100)));
}
TEST(ReferenceTest, CanPassReference) {
  char char_a = 'a';
  int int_a = 'a';
  EXPECT_THAT(char_a, TypedEq<char>('a'));
  EXPECT_THAT(int_a, NOT(TypedEq<int>('a')));

  EXPECT_THAT(int_a, TypedEq<int>('a'));
}
*/
/*
int main(int argc, char **argv){

    cout << "Hello World" << endl;
    return 0;

}*/