#ifndef ISP_01_EQUATION_MY_TEST_H
#define ISP_01_EQUATION_MY_TEST_H

#include <cstdio>

#define FAILED 0
#define SUCCESS 1
#define FAILED_FORMAT "%-30s %-6s on line %d\n"
#define SUCCESS_FORMAT "%-30s %-6s\n"

#define TESTS_BEGIN                                                            \
  int main() {                                                                 \
    char *name;                                                                \
    char res = SUCCESS;

#define TESTS_END                                                              \
  return 0;                                                                    \
  }

#define TEST(testName)                                                         \
  name = (char *)#testName;                                                    \
  res = SUCCESS;

#define assertTrue(predicate)                                                  \
  if (res != FAILED) {                                                         \
    if (!(predicate)) {                                                        \
      fprintf(stderr, FAILED_FORMAT, name, "FAILED", __LINE__);                \
      res = FAILED;                                                            \
    }                                                                          \
  }

#define assertFalse(predicate) assertTrue(!(predicate))

#define END                                                                    \
  if (res == SUCCESS) {                                                        \
    printf(SUCCESS_FORMAT, name, "OK");                                        \
  }

#endif // ISP_01_EQUATION_MY_TEST_H
