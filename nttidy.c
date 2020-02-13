/**
 * @file nttidy.c
 * @version 0.1.1-dev0
 * @date Wed Feb 12 19:43:12 CST 2020
 * @copyright 2020 John A. Crow <crowja@gmail.com>
 * @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <ctype.h>
#include "nttidy.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)             ((NULL == (p)) ? (1) : (0))

size_t
nttidy(char *s, int to_case)
{
   /**
    * Remove whitespace, skip nonalphabetic chars. Change case to uppercase
    * (flag > 0), to lowercase (flag < 0), no change (flag == 0).
    */

   if (_IS_NULL(s))
      return 0;

   else {
      size_t      i = 0;
      char       *cp = s;

      for (; *cp != '\0'; cp++) {

         if (!isalpha(*cp))
            continue;

         if (to_case > 0)
            s[i] = toupper(*cp);

         else if (to_case < 0)
            s[i] = tolower(*cp);

         else
            s[i] = *cp;

         i++;
      }

      s[i] = '\0';

      return i;
   }
}
