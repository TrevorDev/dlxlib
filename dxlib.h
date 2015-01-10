/********
dlxlib.h -- header file for dlxlib.c
summary: commonly used functions for c programming
author: Trevor Baron
date: Nov 11 2013
********/
#ifndef DLXLIB_H
#define DLXLIB_H 1
#define DLXLIB_VERSION 0.9f

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>    // time()

typedef struct vector {
   void * ar;
   int size;
} vector;

typedef struct timer {
   double start;
} timer;

double get_wall_time();
timer createTimer();
double getTime(timer t);

double dlxlibVersion();

vector * createVector();

char * fileToString(char * filename);

char * dupStr(char * str);
char * strAdd(char * a,char * b);
int * strToInt(char * str);
vector * split(char * str, char * delim);

int print(const char * format, ...) __attribute__((format(printf, 1, 2)));

#endif