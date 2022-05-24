
#include"zlog.h"

char * EM_LOG_level_get(const int level)
{
    if(level == LOG_DEBUG)      return "DEBUG";
    else if(level == LOG_INFO)  return "INFO";
    else if(level == LOG_WARN)  return "LOG_WARN";
    else if(level == LOG_ERROR) return "LOG_ERROR";
    return "UNKNOW";
}


void EM_LOG(const int level, const char *fun, const int line, const char *fmt, ...)
{
#ifdef LOG_OPEN
    va_list arg;
    va_start(arg, fmt);
    char buf[1+vsnprintf(NULL, 0, fmt, arg)];
    vsnprintf(buf, sizeof(buf), fmt, arg);
    va_end(arg);
    if(level >= LOG_LEVEL)  printf("[%s] [%s %d] %s\n", EM_LOG_level_get(level), fun, line, buf);
#endif
}
#define EMlog(level, fmt...)  EM_LOG(level, __FUNCTION__,__LINE__,fmt)