#include<stdio.h>
#include"zlog.h"
#include"gtest.h"

// #define LOG_OPEN_ZLOG 1
#define LOG_OPEN_GOOGLE_TEST 1

int add(int a, int b)
{
    return a+b;
}

int main()
{
    int a = 10;

#ifdef LOG_OPEN_GOOGLE_TEST
    printf("app start!\n");
    T_EMTest *m_EMTest = addFunc(add, 1, 2, 3);
    runEMTest(m_EMTest);
#endif

#ifdef LOG_OPEN_ZLOG
    EMlog(LOG_DEBUG, "app start");
    EMlog(LOG_INFO, "A = %d", a);
    EMlog(LOG_WARN, "app warn");
    EMlog(LOG_ERROR, "app error");
#endif
    return 0;
}
