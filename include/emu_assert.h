#ifndef JIDAO_EMU_ASSERT_H_
#define JIDAO_EMU_ASSERT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef JIDAO_ASSERT_ENABLED
    #ifdef NDEBUG
        #define JIDAO_ASSERT_ENABLED 0
    #else
        #define JIDAO_ASSERT_ENABLED 1
    #endif
#endif

void emu_assert_fail(const char *expr,
                    const char *file,
                    int line,
                    const char *func,
                    const char *fmt, ...)
#if defined(__GNUC__) || defined(__clang__)
    __attribute__((noreturn, format(printf, 5, 6)))
#endif
;
#ifdef __cplusplus
}
#endif



#if JIDAO_ASSERT_ENABLED

#  define EMU_ASSERT(expr)                                             \
      do {                                                            \
          if (!(expr)) {                                              \
              emu_assert_fail(#expr, __FILE__, __LINE__, __func__,     \
                             "Assert Failed!!!");                              \
          }                                                           \
      } while (0)

#  define EMU_ASSERT_MSG(expr, ...)                                    \
      do {                                                            \
          if (!(expr)) {                                              \
              emu_assert_fail(#expr, __FILE__, __LINE__, __func__,     \
                             __VA_ARGS__);                            \
          }                                                           \
      } while (0)

#else

#  define MY_ASSERT(expr) ((void)0)
#  define MY_ASSERT_MSG(expr, ...) ((void)0)
#endif


#endif
