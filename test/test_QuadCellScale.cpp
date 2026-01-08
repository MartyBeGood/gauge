#include <unity.h>

void test_doesThisWork() {
  TEST_ASSERT_EQUAL(1, 1);
}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_doesThisWork);
  return UNITY_END();
}
