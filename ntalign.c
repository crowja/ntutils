#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <math.h>
#include <float.h>
#include <ctype.h>
#include "ntmatch.h"
#include "ntalign.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

static double
_align_score(unsigned type, size_t lena, char *a, size_t lenb, char *b, double indel,
             double mismatch, double *wrk)
{
   /* Computes best score only for global (type = 0) and local (type = 1) alignments */
   unsigned    i, j;
   unsigned    mp1 = lena + 1;
   unsigned    np1 = lenb + 1;
   double      score = -DBL_MAX;
   double      maxscore = (lena < lenb ? lena : lenb);  /* maximum possible score */
   double      tol = DBL_EPSILON;
   double     *wrk1 = wrk;                  /* needs to be at least 2 * m + 2 doubles */
   double     *wrk2 = wrk + mp1;

   for (i = 0; i < mp1; i++)
      wrk1[i] = wrk2[i] = 0;

   for (j = 1; j < np1; j++) {
      for (i = 1; i < mp1; i++) {
         double      s0, s1;
         double      w = ntmatch(a[i - 1], b[j - 1], mismatch);

         s0 = wrk1[i - 1] + w;                   /* score without indels */
         s1 = (wrk1[i] > wrk2[i - 1] ? wrk1[i] : wrk2[i - 1]) - indel;  /* score with indels */
         wrk2[i] = s0 > s1 ? s0 : s1;            /* pick the best of the two */

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
ntalign_local(size_t lena, char *a, size_t lenb, char *b, double indel, double mismatch,
              double *wrk)
{
   if (lena < lenb)
      return _align_score(0, lena, a, lenb, b, indel, mismatch, wrk);

   else
      return _align_score(0, lenb, b, lena, a, indel, mismatch, wrk);
}

double
ntalign_global(size_t lena, char *a, size_t lenb, char *b, double indel, double mismatch,
               double *wrk)
{
   if (lena < lenb)
      return _align_score(1, lena, a, lenb, b, indel, mismatch, wrk);

   else
      return _align_score(1, lenb, b, lena, a, indel, mismatch, wrk);
}

#undef _IS_NULL
