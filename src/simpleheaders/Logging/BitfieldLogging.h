#ifndef BitfieldLogging_H
#define BitfieldLogging_H

#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PRINTF_BINARY_PATTERN_INT8 "%c%c%c%c%c%c%c%c"
#define PRINTF_BYTE_TO_BINARY_INT8(i) \
    (((i)&0x80ll) ? '1' : '0'), (((i)&0x40ll) ? '1' : '0'), \
	(((i)&0x20ll) ? '1' : '0'), (((i)&0x10ll) ? '1' : '0'), \
	(((i)&0x08ll) ? '1' : '0'), (((i)&0x04ll) ? '1' : '0'), \
	(((i)&0x02ll) ? '1' : '0'), (((i)&0x01ll) ? '1' : '0')

#define PRINTF_BINARY_PATTERN_INT16 \
    PRINTF_BINARY_PATTERN_INT8 "|" PRINTF_BINARY_PATTERN_INT8
#define PRINTF_BYTE_TO_BINARY_INT16(i) \
    PRINTF_BYTE_TO_BINARY_INT8((i) >> 8), PRINTF_BYTE_TO_BINARY_INT8(i)

#define PRINTF_BINARY_PATTERN_INT32 \
    PRINTF_BINARY_PATTERN_INT16 "|" PRINTF_BINARY_PATTERN_INT16
#define PRINTF_BYTE_TO_BINARY_INT32(i) \
    PRINTF_BYTE_TO_BINARY_INT16((i) >> 16), PRINTF_BYTE_TO_BINARY_INT16(i)

#define PRINTF_BINARY_PATTERN_INT64 \
    PRINTF_BINARY_PATTERN_INT32 "|" PRINTF_BINARY_PATTERN_INT32
#define PRINTF_BYTE_TO_BINARY_INT64(i) \
    PRINTF_BYTE_TO_BINARY_INT32((i) >> 32), PRINTF_BYTE_TO_BINARY_INT32(i)

// TYPENAME is either INT8, INT16, IN32, INT64
#define putb(TYPENAME, value, fmt, ...) \
    printf( \
	fmt PRINTF_BINARY_PATTERN_##TYPENAME "\n", \
	##__VA_ARGS__, \
	PRINTF_BYTE_TO_BINARY_##TYPENAME(value) \
    );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
