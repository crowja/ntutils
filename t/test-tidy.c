#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "nttidy.h"
#include "tinytest.h"
#include "tinyhelp.h"

static void
test_tidy1(void)
{
   char      seq1[] = "AcGtUaVnnN";
   char      seq2[] = "acgtuavnnn";

   fprintf_test_info(stdout, "test_tidy1", "nttidy");
   ASSERT_EQUALS(strlen(seq1), nttidy(seq1, -1));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_tidy2(void)
{
   char      seq1[] = "AcGtUaVnnN";
   char      seq2[] = "ACGTUAVNNN";

   fprintf_test_info(stdout, "test_tidy2", "nttidy");
   ASSERT_EQUALS(strlen(seq1), nttidy(seq1, 1));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_tidy3(void)
{
   char      seq1[] = "\t   ac Gta      cgt gggG   \n";
   char      seq2[] = "acGtacgtgggG";

   fprintf_test_info(stdout, "test_tidy3", "nttidy");
   nttidy(seq1, 0);
   ASSERT_STRING_EQUALS(seq2, seq1);
}

/* 7 yy */
static void
test_stub(void)
{
   fprintf_test_info(stdout, "test_stub", NULL);
   ASSERT_EQUALS(0, 0);
}

int
main(void)
{
   test_stub();                                  /* only to quiet compiler warnings */
   RUN(test_tidy1);
   RUN(test_tidy2);
   RUN(test_tidy3);

   return TEST_REPORT();
}
