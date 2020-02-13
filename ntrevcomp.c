/**
 * @file ntrevcomp.c
 * @version 0.1.0-dev0
 * @date Wed Feb 12 19:43:12 CST 2020
 * @copyright 2020 John A. Crow <crowja@gmail.com>
 * @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include "ntrevcomp.h"

#ifdef  _IS_NULL
#undef  _IS_NULL
#endif
#define _IS_NULL(p)             ((NULL == (p)) ? (1) : (0))

size_t
ntrevcomp(char *s, int is_rna)
{
   /**
    * Reverse complement.
    * s is the sequence as a null terminated string which is treated as a DNA
    * sequence if is_rna == 0, otherwise as RNA. Non IUPAC codes are unchanged,
    * except '>' and '<' which  get flipped. Returns length of s.
    */

   size_t      len = 0;

   if (!_IS_NULL(s)) {
      unsigned    i;
      char       *cp = s;
      for (; *cp != '\0'; len++, cp++)
         switch (*cp) {
            case 'A':
               if (is_rna)
                  *cp = 'U';
               else
                  *cp = 'T';
               break;
            case 'a':
               if (is_rna)
                  *cp = 'u';
               else
                  *cp = 't';
               break;
            case 'C':
               *cp = 'G';
               break;
            case 'c':
               *cp = 'g';
               break;
            case 'G':
               *cp = 'C';
               break;
            case 'g':
               *cp = 'c';
               break;
            case 'T':
               *cp = 'A';
               break;
            case 't':
               *cp = 'a';
               break;
            case 'U':
               *cp = 'A';
               break;
            case 'u':
               *cp = 'a';
               break;
            case 'R':
               *cp = 'Y';
               break;
            case 'r':
               *cp = 'y';
               break;
            case 'Y':
               *cp = 'R';
               break;
            case 'y':
               *cp = 'r';
               break;
            case 'S':
               *cp = 'S';
               break;
            case 's':
               *cp = 's';
               break;
            case 'W':
               *cp = 'W';
               break;
            case 'w':
               *cp = 'w';
               break;
            case 'K':
               *cp = 'M';
               break;
            case 'k':
               *cp = 'm';
               break;
            case 'M':
               *cp = 'K';
               break;
            case 'm':
               *cp = 'k';
               break;
            case 'B':
               *cp = 'V';
               break;
            case 'b':
               *cp = 'v';
               break;
            case 'V':
               *cp = 'B';
               break;
            case 'v':
               *cp = 'b';
               break;
            case 'D':
               *cp = 'H';
               break;
            case 'd':
               *cp = 'h';
               break;
            case 'H':
               *cp = 'D';
               break;
            case 'h':
               *cp = 'd';
               break;
            case 'N':
               *cp = 'N';
               break;
            case 'n':
               *cp = 'n';
               break;
            case '<':
               *cp = '>';
               break;
            case '>':
               *cp = '<';
               break;
         }

      for (i = 0; i < len / 2; i++) {
         char        t = s[i];
         s[i] = s[len - i - 1];
         s[len - i - 1] = t;
      }
   }

   return len;
}
