typedef unsigned size_t;
# define __LINE__ (0)
# define __FILE__ "__FILE__"
# define __asm__(a...) 
struct __builtin_va_list { };
typedef struct __builtin_va_list va_list;
# define __null 0

int __builtin___sprintf_chk (char *s, int flag, size_t os, const char *fmt, ...);
int __builtin___snprintf_chk (char *s, size_t maxlen, int flag, size_t os, const char *fmt, ...);
int __builtin___vsprintf_chk (char *s, int flag, size_t os, const char *fmt,  va_list ap);
int __builtin___vsnprintf_chk (char *s, size_t maxlen, int flag, size_t os, const char *fmt, va_list ap);
                                                                                                          
extern int __builtin_snprintf  (char *__restrict __s, size_t __maxlen, __const char *__restrict __format, ...);
extern int __builtin_vsnprintf (char *__restrict __s, size_t __maxlen, __const char *__restrict __format, va_list __arg);

extern void __builtin_va_start (va_list & ap, void const * fmt);
# define __builtin_va_arg(s,t)  ((t)0)
extern void __builtin_va_copy (va_list, va_list);
extern void __builtin_va_end (va_list & ap);
extern void *__builtin_alloca (size_t size);
extern long __builtin_expect (long exp, long c);
extern long __builtin_constant_p (long exp);
extern void __builtin_prefetch (const void *addr, ...);

extern void * __builtin_return_address (int); 
# define __builtin_offsetof(t,f)  ((unsigned)&((t *)0)->f)

extern double __builtin_fabs  (double);
extern double __builtin_fabsl (double);
extern double __builtin_fabsf (double);
extern double __builtin_acosf (double);
extern double __builtin_acosl (double);
extern double __builtin_asinf (double);
extern double __builtin_asinl (double);
extern double __builtin_atanf (double);
extern double __builtin_atanl (double);
extern double __builtin_atan2f (double);
extern double __builtin_atan2l (double);

extern double __builtin_huge_val (void);
extern float __builtin_huge_valf (void);
extern long double __builtin_huge_vall (void);
extern double __builtin_inf (void);
extern float __builtin_inff (void);
extern long double __builtin_infl (void);
extern double __builtin_nan (const char *str);
extern float __builtin_nanf (const char *str);
extern long double __builtin_nanl (const char *str);
extern double __builtin_nans (const char *str);
extern float __builtin_nansf (const char *str);
extern long double __builtin_nansl (const char *str);
extern int __builtin_ffs (unsigned int x);
extern int __builtin_clz (unsigned int x);
extern int __builtin_ctz (unsigned int x);
extern int __builtin_popcount (unsigned int x);
extern int __builtin_parity (unsigned int x);
extern int __builtin_ffsl (unsigned long);
extern int __builtin_clzl (unsigned long);
extern int __builtin_ctzl (unsigned long);
extern int __builtin_popcountl (unsigned long);
extern int __builtin_parityl (unsigned long);
extern int __builtin_ffsll (unsigned long long);
extern int __builtin_clzll (unsigned long long);
extern int __builtin_ctzll (unsigned long long);
extern int __builtin_popcountll (unsigned long long);
extern int __builtin_parityll (unsigned long long);
extern double __builtin_powi (double, int);
extern float __builtin_powif (float, int);
extern long double __builtin_powil (long double, int);

extern int __builtin_strcmp (__const char *__s1, __const char *__s2);

extern unsigned __builtin_bswap32 (unsigned);
extern long long unsigned __builtin_bswap64 (long long unsigned);

//--------------------------------------------------------------------------

# define ___SYNC_FETCH_ANDX(type) \
type __sync_fetch_and_add (type  volatile * ptr, type value); \
type __sync_fetch_and_sub (type  volatile * ptr, type value); \
type __sync_fetch_and_or (type  volatile * ptr, type value);  \
type __sync_fetch_and_and (type  volatile * ptr, type value); \
type __sync_fetch_and_xor (type  volatile * ptr, type value); \
type __sync_fetch_and_nand (type  volatile * ptr, type value);\
type __sync_add_and_fetch (type  volatile * ptr, type value); \
type __sync_sub_and_fetch (type  volatile * ptr, type value); \
type __sync_or_and_fetch (type  volatile * ptr, type value);  \
type __sync_and_and_fetch (type  volatile * ptr, type value); \
type __sync_xor_and_fetch (type  volatile * ptr, type value); \
type __sync_nand_and_fetch (type  volatile * ptr, type value);
___SYNC_FETCH_ANDX (int);
___SYNC_FETCH_ANDX (long);
___SYNC_FETCH_ANDX (long long);
___SYNC_FETCH_ANDX (unsigned int);
___SYNC_FETCH_ANDX (unsigned long);
___SYNC_FETCH_ANDX (unsigned long long);
# undef ___SYNC_FETCH_ANDX

//-------------------- limits ---------------------------

# define __CHAR_BIT__  8
# define __SCHAR_MAX__ 0x7f
# define __INT_MAX__  0x7FFFFFFF
# define __LONG_MAX__  0x7FFFFFFFl
# define __LONG_LONG_MAX__  0x7FFFFFFFFFFFFFFFll

//------------------- undefs -----------------------------

# ifdef __FUNCTION__
#  undef __FUNCTION__
# endif

# ifdef __PRETTY_FUNCTION__
#  undef __PRETTY_FUNCTION__
# endif
