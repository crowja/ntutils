#include <ctype.h>

double
ntscore(char b1, char b2, double match, double mismatch)
{
   double      s;

   if (b1 == 'U' || b1 == 'u')
      b1 = 'T';
   if (b2 == 'U' || b2 == 'u')
      b2 = 'T';

   switch (b1) {
      case 'A':
      case 'a':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 0 * mismatch) / 1;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'T':
            case 't':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'Y':
            case 'y':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'S':
            case 's':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'K':
            case 'k':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'B':
            case 'b':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'V':
            case 'v':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'D':
            case 'd':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'H':
            case 'h':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'N':
            case 'n':
               s = (1 * match - 3 * mismatch) / 4;
               break;
         }
      case 'C':
      case 'c':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 0 * mismatch) / 1;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'T':
            case 't':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'R':
            case 'r':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'S':
            case 's':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'W':
            case 'w':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'K':
            case 'k':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'B':
            case 'b':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'V':
            case 'v':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'D':
            case 'd':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'H':
            case 'h':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'N':
            case 'n':
               s = (1 * match - 3 * mismatch) / 4;
               break;
         }
      case 'G':
      case 'g':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 0 * mismatch) / 1;
               break;
            case 'T':
            case 't':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'Y':
            case 'y':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'S':
            case 's':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'W':
            case 'w':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'M':
            case 'm':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'B':
            case 'b':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'V':
            case 'v':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'D':
            case 'd':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'H':
            case 'h':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'N':
            case 'n':
               s = (1 * match - 3 * mismatch) / 4;
               break;
         }
      case 'T':
      case 't':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 1 * mismatch) / 1;
               break;
            case 'T':
            case 't':
               s = (1 * match - 0 * mismatch) / 1;
               break;
            case 'R':
            case 'r':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'S':
            case 's':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'M':
            case 'm':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'B':
            case 'b':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'V':
            case 'v':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'D':
            case 'd':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'H':
            case 'h':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'N':
            case 'n':
               s = (1 * match - 3 * mismatch) / 4;
               break;
         }
      case 'R':
      case 'r':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'T':
            case 't':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'R':
            case 'r':
               s = (2 * match - 2 * mismatch) / 4;
               break;
            case 'Y':
            case 'y':
               s = (0 * match - 4 * mismatch) / 4;
               break;
            case 'S':
            case 's':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'B':
            case 'b':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'V':
            case 'v':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'D':
            case 'd':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'H':
            case 'h':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'N':
            case 'n':
               s = (2 * match - 6 * mismatch) / 8;
               break;
         }
      case 'Y':
      case 'y':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'T':
            case 't':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'R':
            case 'r':
               s = (0 * match - 4 * mismatch) / 4;
               break;
            case 'Y':
            case 'y':
               s = (2 * match - 2 * mismatch) / 4;
               break;
            case 'S':
            case 's':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'B':
            case 'b':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'V':
            case 'v':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'D':
            case 'd':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'H':
            case 'h':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'N':
            case 'n':
               s = (2 * match - 6 * mismatch) / 8;
               break;
         }
      case 'S':
      case 's':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'T':
            case 't':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'S':
            case 's':
               s = (2 * match - 2 * mismatch) / 4;
               break;
            case 'W':
            case 'w':
               s = (0 * match - 4 * mismatch) / 4;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'B':
            case 'b':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'V':
            case 'v':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'D':
            case 'd':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'H':
            case 'h':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'N':
            case 'n':
               s = (2 * match - 6 * mismatch) / 8;
               break;
         }
      case 'W':
      case 'w':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'T':
            case 't':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'S':
            case 's':
               s = (0 * match - 4 * mismatch) / 4;
               break;
            case 'W':
            case 'w':
               s = (2 * match - 2 * mismatch) / 4;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'B':
            case 'b':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'V':
            case 'v':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'D':
            case 'd':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'H':
            case 'h':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'N':
            case 'n':
               s = (2 * match - 6 * mismatch) / 8;
               break;
         }
      case 'K':
      case 'k':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'T':
            case 't':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'S':
            case 's':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'K':
            case 'k':
               s = (2 * match - 2 * mismatch) / 4;
               break;
            case 'M':
            case 'm':
               s = (0 * match - 4 * mismatch) / 4;
               break;
            case 'B':
            case 'b':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'V':
            case 'v':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'D':
            case 'd':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'H':
            case 'h':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'N':
            case 'n':
               s = (2 * match - 6 * mismatch) / 8;
               break;
         }
      case 'M':
      case 'm':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 1 * mismatch) / 2;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'T':
            case 't':
               s = (0 * match - 2 * mismatch) / 2;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'S':
            case 's':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'K':
            case 'k':
               s = (0 * match - 4 * mismatch) / 4;
               break;
            case 'M':
            case 'm':
               s = (2 * match - 2 * mismatch) / 4;
               break;
            case 'B':
            case 'b':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'V':
            case 'v':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'D':
            case 'd':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'H':
            case 'h':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'N':
            case 'n':
               s = (2 * match - 6 * mismatch) / 8;
               break;
         }
      case 'B':
      case 'b':
         switch (b2) {
            case 'A':
            case 'a':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'T':
            case 't':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'Y':
            case 'y':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'S':
            case 's':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'K':
            case 'k':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'B':
            case 'b':
               s = (3 * match - 6 * mismatch) / 9;
               break;
            case 'V':
            case 'v':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'D':
            case 'd':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'H':
            case 'h':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'N':
            case 'n':
               s = (3 * match - 9 * mismatch) / 12;
               break;
         }
      case 'V':
      case 'v':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'T':
            case 't':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'R':
            case 'r':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'S':
            case 's':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'W':
            case 'w':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'M':
            case 'm':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'B':
            case 'b':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'V':
            case 'v':
               s = (3 * match - 6 * mismatch) / 9;
               break;
            case 'D':
            case 'd':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'H':
            case 'h':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'N':
            case 'n':
               s = (3 * match - 9 * mismatch) / 12;
               break;
         }
      case 'D':
      case 'd':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'C':
            case 'c':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'T':
            case 't':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'R':
            case 'r':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'Y':
            case 'y':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'S':
            case 's':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'W':
            case 'w':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'K':
            case 'k':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'M':
            case 'm':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'B':
            case 'b':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'V':
            case 'v':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'D':
            case 'd':
               s = (3 * match - 6 * mismatch) / 9;
               break;
            case 'H':
            case 'h':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'N':
            case 'n':
               s = (3 * match - 9 * mismatch) / 12;
               break;
         }
      case 'H':
      case 'h':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'G':
            case 'g':
               s = (0 * match - 3 * mismatch) / 3;
               break;
            case 'T':
            case 't':
               s = (1 * match - 2 * mismatch) / 3;
               break;
            case 'R':
            case 'r':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'Y':
            case 'y':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'S':
            case 's':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'W':
            case 'w':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'K':
            case 'k':
               s = (1 * match - 5 * mismatch) / 6;
               break;
            case 'M':
            case 'm':
               s = (2 * match - 4 * mismatch) / 6;
               break;
            case 'B':
            case 'b':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'V':
            case 'v':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'D':
            case 'd':
               s = (2 * match - 7 * mismatch) / 9;
               break;
            case 'H':
            case 'h':
               s = (3 * match - 6 * mismatch) / 9;
               break;
            case 'N':
            case 'n':
               s = (3 * match - 9 * mismatch) / 12;
               break;
         }
      case 'N':
      case 'n':
         switch (b2) {
            case 'A':
            case 'a':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'C':
            case 'c':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'G':
            case 'g':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'T':
            case 't':
               s = (1 * match - 3 * mismatch) / 4;
               break;
            case 'R':
            case 'r':
               s = (2 * match - 6 * mismatch) / 8;
               break;
            case 'Y':
            case 'y':
               s = (2 * match - 6 * mismatch) / 8;
               break;
            case 'S':
            case 's':
               s = (2 * match - 6 * mismatch) / 8;
               break;
            case 'W':
            case 'w':
               s = (2 * match - 6 * mismatch) / 8;
               break;
            case 'K':
            case 'k':
               s = (2 * match - 6 * mismatch) / 8;
               break;
            case 'M':
            case 'm':
               s = (2 * match - 6 * mismatch) / 8;
               break;
            case 'B':
            case 'b':
               s = (3 * match - 9 * mismatch) / 12;
               break;
            case 'V':
            case 'v':
               s = (3 * match - 9 * mismatch) / 12;
               break;
            case 'D':
            case 'd':
               s = (3 * match - 9 * mismatch) / 12;
               break;
            case 'H':
            case 'h':
               s = (3 * match - 9 * mismatch) / 12;
               break;
            case 'N':
            case 'n':
               s = (4 * match - 12 * mismatch) / 16;
               break;
         }
   }
   return s;
}
