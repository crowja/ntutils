#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <math.h>
#include <float.h>
#include <string.h>                              /* FIXME */
#include <ctype.h>
#include "nsequtils.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

static double
_align_score(unsigned type, char *a, char *b, double match, double indel, double mismatch,
             double ambig, double *wrk)
{
   /* Computes best score only for global (type = 0) and local (type = 1) alignments */
   unsigned    i, j;
   unsigned    m = strlen(a);
   unsigned    mp1 = m + 1;
   unsigned    n = strlen(b);
   unsigned    np1 = n + 1;
   double      score = -DBL_MAX;
   double      maxscore = (m < n ? m : n) * match;      /* maximum possible score */
   double      tol = DBL_EPSILON;
   double     *wrk1 = wrk;                  /* note that wrk needs to provide at least 2 * mp1 doubles */
   double     *wrk2 = wrk + mp1;

   for (i = 0; i < mp1; i++)
      wrk1[i] = wrk2[i] = 0;

   for (j = 1; j < np1; j++) {
      for (i = 1; i < mp1; i++) {
         double      s0, s1, w;

         if (_IS_NULL(strchr("ACGTUacgtu", a[i - 1]))
             || _IS_NULL(strchr("ACGTUacgtu", b[j - 1])))
            w = -ambig;                          /* comparing one or more ambiguity codes */

         else
            w = (a[i - 1] == b[j - 1] ? match : -mismatch);     /* unambiguous match/mismatch */

         s0 = wrk1[i - 1] + w;                   /* score without indels */
         s1 = (wrk1[i] > wrk2[i - 1] ? wrk1[i] : wrk2[i - 1]) - indel;  /* score with indels */
         wrk2[i] = s0 > s1 ? s0 : s1;

         if (type == 1)
            wrk2[i] = wrk2[i] > 0 ? wrk2[i] : 0;

         score = wrk2[i] > score ? wrk2[i] : score;

         if (fabs(score - maxscore) < tol * fabs(maxscore))
            goto DONE;
      }

      for (i = 0; i < mp1; i++)
         wrk1[i] = wrk2[i];
   }

 DONE:

   return score;
}

double
nsequtils_nwscore(char *a, char *b, double match, double indel, double mismatch,
                  double ambig, double *wrk)
{
   if (strlen(a) < strlen(b))
      return _align_score(0, a, b, match, indel, mismatch, ambig, wrk);

   else
      return _align_score(0, b, a, match, indel, mismatch, ambig, wrk);
}

double
nsequtils_swscore(char *a, char *b, double match, double indel, double mismatch,
                  double ambig, double *wrk)
{
   if (strlen(a) < strlen(b))
      return _align_score(1, a, b, match, indel, mismatch, ambig, wrk);

   else
      return _align_score(1, b, a, match, indel, mismatch, ambig, wrk);
}

#undef _IS_NULL
#undef _FREE
