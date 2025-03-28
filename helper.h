#ifndef HELPER_H
#define HELPER_H

#define _GNU_SOURCE
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FIX_ME_MAISON                                                          \
  int pieces;                                                                  \
  int etages;

/**
 * @brief print_error in red color
 * @param format
 * @param ...
 */
static void print_error(const char *format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stdout, "\033[1;31m");
  vfprintf(stdout, format, args);
  fprintf(stdout, "\033[0m");
  va_end(args);
}

/**
 * @brief print_success in green color
 * @param format
 * @param ...
 */
static void print_success(const char *format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stdout, "\033[1;32m");
  vfprintf(stdout, format, args);
  fprintf(stdout, "\033[0m");
  va_end(args);
}

#define ASSERT_EQUALS_INT(expected, actual, expr)                              \
  if (expected != actual) {                                                    \
    print_error("%s: Expected %d but got %d\n", expr, expected, actual);       \
    exit(1);                                                                   \
  } else {                                                                     \
    print_success("Test passed\n");                                            \
  }

#define ASSERT_EQUALS_STRING(expected, actual, expr)                           \
  if (strcmp(expected, actual) != 0) {                                         \
    print_error("%s: Expected %s but got %s\n", expr, expected, actual);       \
    exit(1);                                                                   \
  } else {                                                                     \
    print_success("Test passed\n");                                            \
  }
#
#define ASSERT_EQUALS_FLOAT(expected, actual, expr)                            \
  if (expected != actual) {                                                    \
    print_error("%s: Expected %f but got %f\n", expr, expected, actual);       \
    return 1;                                                                  \
  } else {                                                                     \
    print_success("Test passed\n");                                            \
  }

#define ASSERT_NOT_NULL(actual, expr)                                          \
  if (actual == NULL) {                                                        \
    print_error("%s: Expected not NULL but got NULL\n", expr);                 \
    return 1;                                                                  \
  } else {                                                                     \
    print_success("Test passed\n");                                            \
  }

#define ASSERT_STDOUT(expected, command, expr)                                 \
  int stdout_fd = dup(fileno(stdout));                                         \
  int pipefd[2];                                                               \
  pipe2(pipefd, 0);                                                            \
  dup2(pipefd[1], fileno(stdout));                                             \
  command;                                                                     \
  fflush(stdout);                                                              \
  char buffer[1024];                                                           \
  read(pipefd[0], buffer, 1024);                                               \
  dup2(stdout_fd, fileno(stdout));                                             \
  if (strcmp(buffer, expected) != 0) {                                         \
    print_error("%s: Expected %s but got %s\n", expr, expected, buffer);       \
    return 1;                                                                  \
  } else {                                                                     \
    print_success("Test passed\n");                                            \
  }

#define ASSERT_STDIN(content, command)                                   \
  int stdin_fd = dup(fileno(stdin));                                           \
  int pipefd[2];                                                               \
  pipe2(pipefd, 0);                                                            \
  write(pipefd[1], content, strlen(content));                                  \
  dup2(pipefd[0], fileno(stdin));                                              \
  command;                                                                     \
  fflush(stdin);                                                               \
  dup2(stdin_fd, fileno(stdin));

/**
 * This macro should be instantiated with the keyword TEST_CASE. The idea is
 * that it instantiates a function that returns a boolean value.
 * The macro should be call like this:
 * TEST_CASE(test_name) { [the code that the user will write to run its test.] }
 * The "test_name" param should be the name of the function.
 * At the end of the instantiated function, a return 0 should be added.
 */
#define TEST_CASE(name)                                                        \
  int name() {                                                                 \
    printf("Running test %s\n", #name);

/**
 * This macro should be instantiated with the keyword END_TEST_CASE. The idea
 * its to close the function that was instantiated with the TEST_CASE macro.
 * The macro should be call like this:
 * END_TEST_CASE
 */
#define END_TEST_CASE                                                          \
  return 0;                                                                    \
  }

#define RETURN_ON_FAILURE(test)                                                \
  if (test) {                                                                  \
    return 1;                                                                  \
  }

#endif // HELPER_H
