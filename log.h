#ifndef LOG_H_

int l_init();
/*
* Looks for and creates a 'logs' directory where log files are placed.
* Logs are named in the format: "YYYY-MM-DD--HH:MM:SS.log"
*/

int l_close();
/*
* Close the log file.
* Call before end of program.
*/

#define l_log(flag, msg) \
    _l_flog(__FILE__, __LINE__, flag, msg)
/*
* Writes into the logfile at a given time the program is ran.
* Flags gives nicer formatting of messages.
* Flags include:
*   - INFO
*   - ERR
*/

#define l_flog(flag, msg, ...) \
    _l_flog(__FILE__, __LINE__, flag, msg, __VA_ARGS__)
/*
* Formatted logging.
* Otherwise same as l_log.
*/

void _l_flog(char *file, int line, int flag, const char *msg, ...);
void _l_log(char *file, int line, int flag, char *msg);

#include <string.h>
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdarg.h>

#define INFO 0
#define ERR 1


FILE *lgfd;

int l_init() {
    // check/create /logs directory
    int mk = mkdir("./logs", 0777);

    // get and format current date-time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    size_t ret = strftime(s, sizeof(s), "%F--%T", tm);

    // format log filename with date-time
    char *path = "./logs/";
    char fname[80];
    strcpy(fname, path);
    strcat(fname, s);
    strcat(fname, ".log");

    // create log file
    FILE *fd = fopen(fname, "w+");
    if (fd == NULL) {
        perror("error finding/creating file\n");
        return -1;
    }

    lgfd = fd;
    return 0;
}

void _l_log(char *file, int line, int flag, char *msg) {
    if (flag == INFO) {
        fprintf(lgfd, "%s:%i [INFO] --> %s", file, line, msg);
    } else if (flag == ERR) {
        fprintf(lgfd, "%s:%i [ERROR] --> %s", file, line, msg);
    }
    fflush(lgfd);
    return;
}

void _l_flog(char *file, int line, int flag, const char *msg, ...) {
    va_list args;
    va_start(args, msg);
    if (flag == INFO) {
        fprintf(lgfd, "%s:%i [INFO] --> ", file, line);
        vfprintf(lgfd, msg, args);
        fprintf(lgfd, "\n");
    } else if (flag == ERR) {
        fprintf(lgfd, "%s:%i [ERROR] --> ", file, line);
        vfprintf(lgfd, msg, args);
        fprintf(lgfd, "\n");
    }
    va_end(args);
    fflush(lgfd);
    return;
}

int l_close() {
    if (fclose(lgfd) == EOF) {
        perror("Error closing file");
        return -1;
    }
    return 0;
}

#endif // LOG_H_
