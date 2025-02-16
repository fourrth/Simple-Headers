#ifndef CommonMacros_H
#define CommonMacros_H
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

// NOTE: this may run at runtime and not compile time
// NOTE: This is quite bloaty and probably should not be used
#define __FILENAME__ (strrchr("/" __FILE__, '/') + 1)
// #define __FILENAME__ \
//     (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define CONCAT_(A, B) A##B
#define CONCAT(A, B) CONCAT_(A, B)

#define STR(A) #A
#define obs(A) CONCAT(_MACROVAR___##A, __FILENAME__)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
