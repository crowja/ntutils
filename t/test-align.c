#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntalign.h"
#include "tinytest.h"
#include "tinyhelp.h"

static void
test_align_global_score(void)
{
   double     *wrk = malloc(10000);
   double score;
   char seq1[] = "acgttgagagagaa";
   char seq2[] = "acgttgaga";

   fprintf_test_info(stdout, "test_align1", "ntalign_global_score");
   score = ntalign_global_score(14, seq1, 9, seq2, 3, 2, wrk);
   ASSERT_DOUBLE_EQUALS(9.0, score);
   free(wrk);
}

/* 7 yy */
#if 0
static void
test_stub(void)
{
   ASSERT("test 1 in test_stub", two_doubles_equal(0.0, 0.0));
   fprintf_test_info(stdout, "test_stub", NULL);
   ASSERT_EQUALS(0, 0);
}
#endif

int
main(void)
{
   RUN(test_align_global_score);

   return TEST_REPORT();
}
