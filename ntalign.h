/**
 * @file ntalign.h
 * @version 0.1.1-dev0
 * @date Sun Feb 16, 2020 08:09:47 PM CST
 * @copyright 2020 John A. Crow <crowja@gmail.com>
 * @license Unlicense <http://unlicense.org/>
 */

#ifndef NTALIGN_H
#define NTALIGN_H

double    ntalign_local_score(size_t lena, char *a, size_t lenb, char *b, double indel,
                              double mismatch, double *wrk);
double    ntalign_global_score(size_t lena, char *a, size_t lenb, char *b, double indel,
                               double mismatch, double *wrk);

#endif
