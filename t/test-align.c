#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntalign.h"
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
test_align_global_score(void)
{
   double     *wrk = malloc(10000);
   char seq1[] = "acgttgagagagaa";
   char seq2[] = "acgttgaga";

   printf_test_name("test_align1", "ntalign_global_score");
   printf("Alignment score is %f\n", ntalign_global_score(14, seq1, 9, seq2, 3, 2, wrk));

   free(wrk);
}

/* 7 yy */
#if 0
static void
test_stub(void)
{
   ASSERT("test 1 in test_stub", two_doubles_equal(0.0, 0.0));
   printf_test_name("test_stub", NULL);
   ASSERT_EQUALS(0, 0);
}
#endif

int
main(void)
{
   RUN(test_align_global_score);

   return TEST_REPORT();
}
