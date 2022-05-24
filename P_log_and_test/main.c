#include<stdio.h>
#include"zlog.h"

int main()
{
    int a = 10;
    EMlog(LOG_DEBUG, "app start");
    EMlog(LOG_INFO, "A = %d", a);
    EMlog(LOG_WARN, "app warn");
    EMlog(LOG_ERROR, "app error");
    return 0;
}