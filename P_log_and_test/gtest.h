
#ifndef _G_TEST_H_
#define _G_TEST_H_

#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<stddef.h>
#include<stdarg.h>

typedef struct 
{
    int output;
    int a;
    int b; 
    int (*TestEMFunc)(int, int);
    
}T_EMTest;

T_EMTest *addFunc(int (*TestEMFunc)(int, int), int a, int b, int output);
void runEMTest(T_EMTest *p_EMTest);


#endif