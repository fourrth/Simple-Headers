#ifndef PUBLIC_TYPES_H_
#define PUBLIC_TYPES_H_
#include <stdlib.h>

typedef struct myArray
{
    size_t len;
    size_t elementsize;
    void* data;
} myArray;

#define myArray_ISVALID(myArray_) \
    (((myArray_).data == NULL && (myArray_).len == 0 && \
      (myArray_).elementsize == 0) \
         ? 0 \
         : 1)

#endif // PUBLIC_TYPES_H_
