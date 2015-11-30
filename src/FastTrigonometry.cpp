#include "FastTrigonometry.h"

FastTrigonometry::FastTrigonometry()
{
    //ctor
}

FastTrigonometry::~FastTrigonometry()
{
    //dtor
}
float FastTrigonometry::sin1(float x) const
{
    int k;
	double y;
	double z;

	z  = x;
	z *= 0.3183098861837907;
	z += 6755399441055744.0;
	k  = *((int *) &z);
	z  = k;
	z *= 3.1415926535897932;
	x -= z;
	y  = x;
	y *= x;
	z  = 0.0073524681968701;
	z *= y;
	z -= 0.1652891139701474;
	z *= y;
	z += 0.9996919862959676;
	x *= z;
	k &= 1;
	k += k;
	z  = k;
	z *= x;
	x -= z;

	return x;
}



