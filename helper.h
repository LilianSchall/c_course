#ifndef HELPER_H
#define HELPER_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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

#endif // HELPER_H
