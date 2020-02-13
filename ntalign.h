/**
 * @file ntalign.h
 * @version 0.1.0-dev0
 * @date Wed Feb 12 19:43:12 CST 2020
 * @copyright 2020 John A. Crow <crowja@gmail.com>
 * @license Unlicense <http://unlicense.org/>
 */

#ifndef _NTALIGN_H_
#define _NTALIGN_H_

double      ntalign_local_score(size_t lena, char *a, size_t lenb, char *b, double indel,
                                double mismatch, double *wrk);
double      ntalign_global_score(size_t lena, char *a, size_t lenb, char *b, double indel,
                                 double mismatch, double *wrk);

#endif
