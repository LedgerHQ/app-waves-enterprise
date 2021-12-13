#ifndef __ED25519_REF10_H__
#define __ED25519_REF10_H__

#include <stddef.h>
#include <stdint.h>

#include "ed25519_ref10_fe_25_5.h"

void fe25519_invert(fe25519 out, const fe25519 z);

/*
 ge means group element.

 Here the group is the set of pairs (x,y) of field elements
 satisfying -x^2 + y^2 = 1 + d x^2y^2
 where d = -121665/121666.

 Representations:
 ge25519_p2 (projective): (X:Y:Z) satisfying x=X/Z, y=Y/Z
 ge25519_p3 (extended): (X:Y:Z:T) satisfying x=X/Z, y=Y/Z, XY=ZT
 ge25519_p1p1 (completed): ((X:Z),(Y:T)) satisfying x=X/Z, y=Y/T
 */

typedef struct {
  fe25519 X;
  fe25519 Y;
  fe25519 Z;
} ge25519_p2;

typedef struct {
  fe25519 X;
  fe25519 Y;
  fe25519 Z;
  fe25519 T;
} ge25519_p3;

typedef struct {
  fe25519 X;
  fe25519 Y;
  fe25519 Z;
  fe25519 T;
} ge25519_p1p1;

int ge25519_has_small_order(const unsigned char s[32]);

#endif
