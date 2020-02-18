#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntmatch.h"
#include "tinytest.h"
#include "tinyhelp.h"

static void
test_match1(void)
{
   double s;

   fprintf_test_info(stdout, "test_match1", "ntmatch");
   s = ntmatch('A', 'A', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('a', 'a', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('C', 'C', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('c', 'c', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('G', 'G', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('g', 'g', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('T', 'T', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('t', 't', 2.0);
   ASSERT_DOUBLE_EQUALS(1.0, s);
   s = ntmatch('A', 'T', 2.0);
   ASSERT_DOUBLE_EQUALS(-2.0, s);
   s = ntmatch('t', 'a', 2.0);
   ASSERT_DOUBLE_EQUALS(-2.0, s);
   s = ntmatch('g', 'C', 2.0);
   ASSERT_DOUBLE_EQUALS(-2.0, s);
   s = ntmatch('C', 'g', 2.0);
   ASSERT_DOUBLE_EQUALS(-2.0, s);
   s = ntmatch('a', 'n', 2.0);
   ASSERT_DOUBLE_EQUALS(-1.25, s);
   s = ntmatch('n', 't', 2.0);
   ASSERT_DOUBLE_EQUALS(-1.25, s);
   s = ntmatch('m', 'w', 2.0);
   ASSERT_DOUBLE_EQUALS(-1.25, s);
   s = ntmatch('n', 'n', 2.0);
   ASSERT_DOUBLE_EQUALS(-1.25, s);
}

/* 6 yy */
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
   RUN(test_match1);

   return TEST_REPORT();
}
