
#include"gtest.h"

T_EMTest *addFunc(int (*TestEMFunc)(int, int), int a, int b, int output)
{
    T_EMTest *m_EMTest = (T_EMTest *)malloc(sizeof(T_EMTest));
    m_EMTest->a = a;
    m_EMTest->b = b;
    m_EMTest->TestEMFunc = TestEMFunc;
    m_EMTest->output = output;
    return m_EMTest;
}

void runEMTest(T_EMTest *p_EMTest)
{
    if(p_EMTest != NULL)
    {
        int count = p_EMTest->TestEMFunc(p_EMTest->a, p_EMTest->b);
        if(count == p_EMTest->output) printf("success \n");
        else printf("fail %d != %d \n", count, p_EMTest->output);
        free(p_EMTest);
    }
}