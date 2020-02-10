#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntrevcomp.h"
#include "tinytest.h"

#ifdef _COLOR_CODE
#undef _COLOR_CODE
#endif
#define _COLOR_CODE      0x1B
#ifdef _COLOR_RED
#undef _COLOR_RED
#endif
#define _COLOR_RED       "[1;31m"
#ifdef _COLOR_GREEN
#undef _COLOR_GREEN
#endif
#define _COLOR_GREEN     "[1;32m"
#ifdef _COLOR_YELLOW
#undef _COLOR_YELLOW
#endif
#define _COLOR_YELLOW    "[1;33m"
#ifdef _COLOR_RESET
#undef _COLOR_RESET
#endif
#define _COLOR_RESET     "[0m"

static void
_printf_test_name(char *name, char *info)
{
   printf("%c%s%s%c%s", _COLOR_CODE, _COLOR_YELLOW, name, _COLOR_CODE, _COLOR_RESET);

   if (NULL != info)
      printf(" [%s]\n", info);
   else
      printf("\n");
}

static int
_two_doubles_equal(double x, double y)
{
   double      t = fabs(x) + fabs(y);
   return fabs(x - y) < 4 * DBL_EPSILON * t ? 1 : 0;
}

static void
test_revcomp1(void)
{
   char        seq1[] = "acgtacgtggg";      /* odd-length seq */
   char        seq2[] = "cccacgtacgt";

   _printf_test_name("test_revcomp1", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_revcomp2(void)
{
   char        seq1[] = "acgtacgtgggg";     /* even-length seq */
   char        seq2[] = "ccccacgtacgt";

   _printf_test_name("test_revcomp2", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_revcomp3(void)
{
   char        seq1[] = "acGtacgt gggG";
   char        seq2[] = "Cccc acgtaCgt";

   _printf_test_name("test_revcomp3", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

/* 7 yy */
static void
test_stub(void)
{
   ASSERT("test 1 in test_stub", _two_doubles_equal(0.0, 0.0));
   _printf_test_name("test_stub", NULL);
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
