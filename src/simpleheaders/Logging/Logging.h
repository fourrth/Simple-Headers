#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#include "../CommonMacros.h"

#ifdef __cplusplus
extern "C" {
#endif

// you can define this to whatever FILE* you want
#ifndef LOGGING_PROBLEM_HOLDER_FILE
#define LOGGING_PROBLEM_HOLDER_FILE stderr
#endif

#define LOGGING_PROBLEM_HOLDER_FILE_SYS_STRERROR strerror(errno)

#pragma region /* MAINS */

// just prints sys info (like perror/PRINT_ERROR)
#define __PRINT_SYS_(File) \
    do \
    { \
    if(LOGGING_PROBLEM_HOLDER_FILE != NULL) \
    { \
    fprintf(File, \
    " (%s)\n", \
    LOGGING_PROBLEM_HOLDER_FILE_SYS_STRERROR); \
    } \
    } while(0)


#pragma endregion /* MAINS */

#pragma region /* BLANKS */

#define ___PRINTF_BLANK_INFO___(TYPENAME_s, fmt, ...) \
    do \
    { \
    if(LOGGING_PROBLEM_HOLDER_FILE != NULL) \
    { \
    fprintf( \
	LOGGING_PROBLEM_HOLDER_FILE, \
	TYPENAME_s " in %s() : %s, at line: %i --> " fmt, \
	__func__, \
	__FILE__, \
	__LINE__, \
	##__VA_ARGS__ \
    ); \
    } \
    }while(0)

#define ___PRINTF_BLANK_INFO_SYS___(TYPENAME_s, fmt, ...) \
    ___PRINTF_BLANK_INFO___(TYPENAME_s, fmt, ##__VA_ARGS__); \
    __PRINT_SYS_(LOGGING_PROBLEM_HOLDER_FILE)

#pragma endregion /* BLANKS */

#pragma region /* PRINTOUTS */

// Printf-like formatting with "WARNING" attached
#define PRINTF_WARNING_INFO(fmt, ...) \
    ___PRINTF_BLANK_INFO___("WARNING", fmt, ##__VA_ARGS__)

// Printf-like formatting with "ERROR" attached
#define PRINTF_ERROR_INFO(fmt, ...) \
    ___PRINTF_BLANK_INFO___("ERROR", fmt, ##__VA_ARGS__)

// Printf-like formatting with "INFO" attached
#define PRINTF_INFO_INFO(fmt, ...) \
    ___PRINTF_BLANK_INFO___("INFO", fmt, ##__VA_ARGS__)

// Printf-like formatting with "WARNING" attached, also with perror info
#define PRINTF_WARNING_INFO_SYS(fmt, ...) \
    ___PRINTF_BLANK_INFO_SYS___("WARNING", fmt, ##__VA_ARGS__)

// Printf-like formatting with "ERROR" attached, also with perror info
#define PRINTF_ERROR_INFO_SYS(fmt, ...) \
    ___PRINTF_BLANK_INFO_SYS___("ERROR", fmt, ##__VA_ARGS__)

// Printf-like formatting with "INFO" attached, also with perror info
#define PRINTF_INFO_INFO_SYS(fmt, ...) \
    ___PRINTF_BLANK_INFO_SYS___("INFO", fmt, ##__VA_ARGS__)

#pragma endregion /* PRINTOUTS */
#ifdef __cplusplus
}
#endif
#endif
