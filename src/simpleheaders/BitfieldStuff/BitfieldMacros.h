#ifndef BitfieldMacros_H
#define BitfieldMacros_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// MASK(length,place) gives a mask that is 'length' length and 'place' places over (e.g. MASK(5,3) is 11111000 because 3 '0's over, then set 5 1)
#define MASK(length, place) (~(UINT64_MAX << (length)) << (place))

static inline uint32_t BitCount(uint32_t i)
{
     i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
     i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
     return (i * 0x01010101) >> 24;          // horizontal sum of bytes
}

#define GET_VAL(bitfield, length, place) \
    (((bitfield)&MASK(length, place)) >> (place))

// #define SET_BIT(bitfield, place) ((bitfield) |= MASK(1, place))
// #define UNSET_BIT(bitfield, place) ((bitfield) &= ~MASK(1, place))
#define SET_BITS(bitfield, length, place) SET_VAL(bitfield, length, place, 1)
#define UNSET_BITS(bitfield, length, place) SET_VAL(bitfield, length, place, 0)
// SET_VAL(bitfield,length,place,number) is the same as MASK(length,place), but applies a number 'number' onto bitfield 'bitfield'
#define SET_VAL(bitfield, length, place, number) \
    ((bitfield) = ((bitfield) & ~MASK(length, place)) | \
                  (((number) << (place)) & MASK(length, place)))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
