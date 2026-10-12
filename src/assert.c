#include "emu_assert.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void emu_assert_fail(const char *expr,
                    const char *file,
                    int line,
                    const char *func,
                    const char *fmt, ...)
{
    fflush(stdout); /* 尽量保证已有输出先刷出去 */

    fprintf(stderr, "Assertion failed: %s\n", expr);
    fprintf(stderr, "  file: %s\n", file);
    fprintf(stderr, "  line: %d\n", line);
    if (func) {
        fprintf(stderr, "  func: %s\n", func);
    }

    if (fmt) {
        va_list ap;
        va_start(ap, fmt);
        fputs("  message: ", stderr);
        vfprintf(stderr, fmt, ap);
        va_end(ap);
        fputc('\n', stderr);
    }

    fflush(stderr);
    abort();
}
