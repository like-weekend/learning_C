
#ifndef _Z_LOG_H_
#define _Z_LOG_H_

#include<stdio.h>
#include<stdarg.h>

#define LOG_OPEN 1
#define LOG_LEVEL LOG_DEBUG

typedef enum
{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
}E_LOG_LEVEL;



void EM_LOG(const int level, const char *fun, const int line, const char *fmt, ...);

#define EMlog(level, fmt...) EM_LOG(level, __FUNCTION__,__LINE__,fmt)

#endif