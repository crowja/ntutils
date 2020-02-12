#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "ntmatch.h"
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
test_match1(void)
{
   double s;

   _printf_test_name("test_match1", "ntmatch");

   s = ntmatch('A', 'A', 2.0);
   ASSERT("A vs A", _two_doubles_equal(1.0, s));
   s = ntmatch('a', 'a', 2.0);
   ASSERT("a vs a", _two_doubles_equal(1.0, s));
   s = ntmatch('C', 'C', 2.0);
   ASSERT("C vs C", _two_doubles_equal(1.0, s));
   s = ntmatch('c', 'c', 2.0);
   ASSERT("c vs c", _two_doubles_equal(1.0, s));
   s = ntmatch('G', 'G', 2.0);
   ASSERT("G vs G", _two_doubles_equal(1.0, s));
   s = ntmatch('g', 'g', 2.0);
   ASSERT("g vs g", _two_doubles_equal(1.0, s));
   s = ntmatch('T', 'T', 2.0);
   ASSERT("T vs T", _two_doubles_equal(1.0, s));
   s = ntmatch('t', 't', 2.0);
   ASSERT("t vs t", _two_doubles_equal(1.0, s));
   s = ntmatch('A', 'T', 2.0);
   ASSERT("A vs T", _two_doubles_equal(-2.0, s));
   s = ntmatch('t', 'a', 2.0);
   ASSERT("t vs a", _two_doubles_equal(-2.0, s));
   s = ntmatch('g', 'C', 2.0);
   ASSERT("g vs C", _two_doubles_equal(-2.0, s));
   s = ntmatch('C', 'g', 2.0);
   ASSERT("C vs g", _two_doubles_equal(-2.0, s));

   s = ntmatch('a', 'n', 2.0);
   ASSERT("a vs n", _two_doubles_equal(-1.25, s));
   s = ntmatch('n', 't', 2.0);
   ASSERT("n vs t", _two_doubles_equal(-1.25, s));

   s = ntmatch('m', 'w', 2.0);
   ASSERT("m vs w", _two_doubles_equal(-1.25, s));
   s = ntmatch('n', 'n', 2.0);
   ASSERT("n vs n", _two_doubles_equal(-1.25, s));

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
   RUN(test_match1);

   return TEST_REPORT();
}
