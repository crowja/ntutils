#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntrevcomp.h"
#include "tinytest.h"
#include "tinyhelp.h"

static void
test_revcomp1(void)
{
   char      seq1[] = "acgtacgtggg";        /* odd-length seq */
   char      seq2[] = "cccacgtacgt";

   fprintf_test_info(stdout, "test_revcomp1", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_revcomp2(void)
{
   char      seq1[] = "acgtacgtgggg";       /* even-length seq */
   char      seq2[] = "ccccacgtacgt";

   fprintf_test_info(stdout, "test_revcomp2", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
   ASSERT_STRING_EQUALS(seq2, seq1);
}

static void
test_revcomp3(void)
{
   char      seq1[] = "acGtacgt gggG";
   char      seq2[] = "Cccc acgtaCgt";

   fprintf_test_info(stdout, "test_revcomp3", "ntrevcomp");
   ASSERT_EQUALS(strlen(seq1), ntrevcomp(seq1, 0));
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
   RUN(test_revcomp1);
   RUN(test_revcomp2);
   RUN(test_revcomp3);
   return TEST_REPORT();
}
