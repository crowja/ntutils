#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntrevcomp.h"
#include "tinytest.h"

#ifdef COLOR_CODE
#undef COLOR_CODE
#endif
#define COLOR_CODE      0x1B
#ifdef COLOR_RED
#undef COLOR_RED
#endif
#define COLOR_RED       "[1;31m"
#ifdef COLOR_GREEN
#undef COLOR_GREEN
#endif
#define COLOR_GREEN     "[1;32m"
#ifdef COLOR_YELLOW
#undef COLOR_YELLOW
#endif
#define COLOR_YELLOW    "[1;33m"
#ifdef COLOR_RESET
#undef COLOR_RESET
#endif
#define COLOR_RESET     "[0m"

static void
printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", COLOR_CODE, COLOR_YELLOW, name, COLOR_CODE, COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}

static int
two_doubles_equal(double x, double y)
{
   double      t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}

static void
test_revcomp1(void)
{
   char        seq1[] = "acgtacgtggg";      /* odd-length seq */
   char        seq2[] = "cccacgtacgt";

   printf_test_name("test_revcomp1", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_revcomp2(void)
{
   char        seq1[] = "acgtacgtgggg";     /* even-length seq */
   char        seq2[] = "ccccacgtacgt";

   printf_test_name("test_revcomp2", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_revcomp3(void)
{
   char        seq1[] = "acGtacgt gggG";
   char        seq2[] = "Cccc acgtaCgt";

   printf_test_name("test_revcomp3", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

/* 7 yy */
static void
test_stub(void)
{
   ASSERT("test 1 in test_stub", two_doubles_equal(0.0, 0.0));
   printf_test_name("test_stub", NULL);
   ASSERT_EQUALS(0, 0);
}

int
main(void)
{
   test_stub();                                  /* only to quiet compiler warnings */
   RUN(test_revcomp1);
   RUN(test_revcomp2);
   RUN(test_revcomp3);

   return TEST_REPORT();
}
