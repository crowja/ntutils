/**
 * @file ntmatch.c
 * @version 0.1.0-dev0
 * @date Wed Feb 12 19:43:12 CST 2020
 * @copyright 2020 John A. Crow <crowja@gmail.com>
 * @license Unlicense <http://unlicense.org/>
 */

#include "ntmatch.h"

double
ntmatch(char b1, char b2, double penalty)
{
   double      s;

   switch (b1) {
      case 'A':
      case 'a':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 0 * penalty) / (double) 1;
               break;
            case 'C':
            case 'c':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'G':
            case 'g':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'R':
            case 'r':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'Y':
            case 'y':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'S':
            case 's':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'W':
            case 'w':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'K':
            case 'k':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'M':
            case 'm':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'B':
            case 'b':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'V':
            case 'v':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'D':
            case 'd':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'H':
            case 'h':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'N':
            case 'n':
            default:
               s = (1 - 3 * penalty) / (double) 4;
               break;
         }
         break;
      case 'C':
      case 'c':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'C':
            case 'c':
               s = (1 - 0 * penalty) / (double) 1;
               break;
            case 'G':
            case 'g':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'R':
            case 'r':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'Y':
            case 'y':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'S':
            case 's':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'W':
            case 'w':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'K':
            case 'k':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'M':
            case 'm':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'B':
            case 'b':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'V':
            case 'v':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'D':
            case 'd':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'H':
            case 'h':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'N':
            case 'n':
            default:
               s = (1 - 3 * penalty) / (double) 4;
               break;
         }
         break;
      case 'G':
      case 'g':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'C':
            case 'c':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'G':
            case 'g':
               s = (1 - 0 * penalty) / (double) 1;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'R':
            case 'r':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'Y':
            case 'y':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'S':
            case 's':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'W':
            case 'w':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'K':
            case 'k':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'M':
            case 'm':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'B':
            case 'b':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'V':
            case 'v':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'D':
            case 'd':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'H':
            case 'h':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'N':
            case 'n':
            default:
               s = (1 - 3 * penalty) / (double) 4;
               break;
         }
         break;
      case 'T':
      case 't':
      case 'U':
      case 'u':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'C':
            case 'c':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'G':
            case 'g':
               s = (0 - 1 * penalty) / (double) 1;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 0 * penalty) / (double) 1;
               break;
            case 'R':
            case 'r':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'Y':
            case 'y':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'S':
            case 's':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'W':
            case 'w':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'K':
            case 'k':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'M':
            case 'm':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'B':
            case 'b':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'V':
            case 'v':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'D':
            case 'd':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'H':
            case 'h':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'N':
            case 'n':
            default:
               s = (1 - 3 * penalty) / (double) 4;
               break;
         }
         break;
      case 'R':
      case 'r':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'C':
            case 'c':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'G':
            case 'g':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'R':
            case 'r':
               s = (2 - 2 * penalty) / (double) 4;
               break;
            case 'Y':
            case 'y':
               s = (0 - 4 * penalty) / (double) 4;
               break;
            case 'S':
            case 's':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'W':
            case 'w':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'K':
            case 'k':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'M':
            case 'm':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'B':
            case 'b':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'V':
            case 'v':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'D':
            case 'd':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'H':
            case 'h':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'N':
            case 'n':
            default:
               s = (2 - 6 * penalty) / (double) 8;
               break;
         }
         break;
      case 'Y':
      case 'y':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'C':
            case 'c':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'G':
            case 'g':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'R':
            case 'r':
               s = (0 - 4 * penalty) / (double) 4;
               break;
            case 'Y':
            case 'y':
               s = (2 - 2 * penalty) / (double) 4;
               break;
            case 'S':
            case 's':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'W':
            case 'w':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'K':
            case 'k':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'M':
            case 'm':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'B':
            case 'b':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'V':
            case 'v':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'D':
            case 'd':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'H':
            case 'h':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'N':
            case 'n':
            default:
               s = (2 - 6 * penalty) / (double) 8;
               break;
         }
         break;
      case 'S':
      case 's':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'C':
            case 'c':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'G':
            case 'g':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'R':
            case 'r':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'Y':
            case 'y':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'S':
            case 's':
               s = (2 - 2 * penalty) / (double) 4;
               break;
            case 'W':
            case 'w':
               s = (0 - 4 * penalty) / (double) 4;
               break;
            case 'K':
            case 'k':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'M':
            case 'm':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'B':
            case 'b':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'V':
            case 'v':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'D':
            case 'd':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'H':
            case 'h':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'N':
            case 'n':
            default:
               s = (2 - 6 * penalty) / (double) 8;
               break;
         }
         break;
      case 'W':
      case 'w':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'C':
            case 'c':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'G':
            case 'g':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'R':
            case 'r':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'Y':
            case 'y':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'S':
            case 's':
               s = (0 - 4 * penalty) / (double) 4;
               break;
            case 'W':
            case 'w':
               s = (2 - 2 * penalty) / (double) 4;
               break;
            case 'K':
            case 'k':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'M':
            case 'm':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'B':
            case 'b':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'V':
            case 'v':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'D':
            case 'd':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'H':
            case 'h':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'N':
            case 'n':
            default:
               s = (2 - 6 * penalty) / (double) 8;
               break;
         }
         break;
      case 'K':
      case 'k':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'C':
            case 'c':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'G':
            case 'g':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'R':
            case 'r':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'Y':
            case 'y':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'S':
            case 's':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'W':
            case 'w':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'K':
            case 'k':
               s = (2 - 2 * penalty) / (double) 4;
               break;
            case 'M':
            case 'm':
               s = (0 - 4 * penalty) / (double) 4;
               break;
            case 'B':
            case 'b':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'V':
            case 'v':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'D':
            case 'd':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'H':
            case 'h':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'N':
            case 'n':
            default:
               s = (2 - 6 * penalty) / (double) 8;
               break;
         }
         break;
      case 'M':
      case 'm':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'C':
            case 'c':
               s = (1 - 1 * penalty) / (double) 2;
               break;
            case 'G':
            case 'g':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 2 * penalty) / (double) 2;
               break;
            case 'R':
            case 'r':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'Y':
            case 'y':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'S':
            case 's':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'W':
            case 'w':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'K':
            case 'k':
               s = (0 - 4 * penalty) / (double) 4;
               break;
            case 'M':
            case 'm':
               s = (2 - 2 * penalty) / (double) 4;
               break;
            case 'B':
            case 'b':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'V':
            case 'v':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'D':
            case 'd':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'H':
            case 'h':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'N':
            case 'n':
            default:
               s = (2 - 6 * penalty) / (double) 8;
               break;
         }
         break;
      case 'B':
      case 'b':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'C':
            case 'c':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'G':
            case 'g':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'R':
            case 'r':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'Y':
            case 'y':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'S':
            case 's':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'W':
            case 'w':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'K':
            case 'k':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'M':
            case 'm':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'B':
            case 'b':
               s = (3 - 6 * penalty) / (double) 9;
               break;
            case 'V':
            case 'v':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'D':
            case 'd':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'H':
            case 'h':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'N':
            case 'n':
            default:
               s = (3 - 9 * penalty) / (double) 12;
               break;
         }
         break;
      case 'V':
      case 'v':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'C':
            case 'c':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'G':
            case 'g':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'R':
            case 'r':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'Y':
            case 'y':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'S':
            case 's':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'W':
            case 'w':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'K':
            case 'k':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'M':
            case 'm':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'B':
            case 'b':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'V':
            case 'v':
               s = (3 - 6 * penalty) / (double) 9;
               break;
            case 'D':
            case 'd':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'H':
            case 'h':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'N':
            case 'n':
            default:
               s = (3 - 9 * penalty) / (double) 12;
               break;
         }
         break;
      case 'D':
      case 'd':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'C':
            case 'c':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'G':
            case 'g':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'R':
            case 'r':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'Y':
            case 'y':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'S':
            case 's':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'W':
            case 'w':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'K':
            case 'k':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'M':
            case 'm':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'B':
            case 'b':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'V':
            case 'v':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'D':
            case 'd':
               s = (3 - 6 * penalty) / (double) 9;
               break;
            case 'H':
            case 'h':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'N':
            case 'n':
            default:
               s = (3 - 9 * penalty) / (double) 12;
               break;
         }
         break;
      case 'H':
      case 'h':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'C':
            case 'c':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'G':
            case 'g':
               s = (0 - 3 * penalty) / (double) 3;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 2 * penalty) / (double) 3;
               break;
            case 'R':
            case 'r':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'Y':
            case 'y':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'S':
            case 's':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'W':
            case 'w':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'K':
            case 'k':
               s = (1 - 5 * penalty) / (double) 6;
               break;
            case 'M':
            case 'm':
               s = (2 - 4 * penalty) / (double) 6;
               break;
            case 'B':
            case 'b':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'V':
            case 'v':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'D':
            case 'd':
               s = (2 - 7 * penalty) / (double) 9;
               break;
            case 'H':
            case 'h':
               s = (3 - 6 * penalty) / (double) 9;
               break;
            case 'N':
            case 'n':
            default:
               s = (3 - 9 * penalty) / (double) 12;
               break;
         }
         break;
      case 'N':
      case 'n':
      default:
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'C':
            case 'c':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'G':
            case 'g':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'T':
            case 't':
            case 'U':
            case 'u':
               s = (1 - 3 * penalty) / (double) 4;
               break;
            case 'R':
            case 'r':
               s = (2 - 6 * penalty) / (double) 8;
               break;
            case 'Y':
            case 'y':
               s = (2 - 6 * penalty) / (double) 8;
               break;
            case 'S':
            case 's':
               s = (2 - 6 * penalty) / (double) 8;
               break;
            case 'W':
            case 'w':
               s = (2 - 6 * penalty) / (double) 8;
               break;
            case 'K':
            case 'k':
               s = (2 - 6 * penalty) / (double) 8;
               break;
            case 'M':
            case 'm':
               s = (2 - 6 * penalty) / (double) 8;
               break;
            case 'B':
            case 'b':
               s = (3 - 9 * penalty) / (double) 12;
               break;
            case 'V':
            case 'v':
               s = (3 - 9 * penalty) / (double) 12;
               break;
            case 'D':
            case 'd':
               s = (3 - 9 * penalty) / (double) 12;
               break;
            case 'H':
            case 'h':
               s = (3 - 9 * penalty) / (double) 12;
               break;
            case 'N':
            case 'n':
            default:
               s = (4 - 12 * penalty) / (double) 16;
               break;
         }
         break;
   }

   return s;
}
