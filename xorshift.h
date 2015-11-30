#ifndef XORSHIFT_H_INCLUDED
#define XORSHIFT_H_INCLUDED
#include <stdint.h>
#include <time.h>
#define UINT64_C(val) (val##ULL)
///https://en.wikipedia.org/wiki/Xorshift

class Xorshift
{
public :
Xorshift()
{
x=(time(0));//=y=z=w;
x64=(time(0));
s[0]=time(0);
s[1]=time(0);

}
    uint32_t x, y, z, w;

    const uint32_t xorshift128(void)
    {
        uint32_t t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = w ^ (w >> 19) ^ t ^ (t >> 8);
    }
    /////////////////////////////////////////////////
    uint64_t x64; /* The state must be seeded with a nonzero value. */

    uint64_t xorshift64star(void)
    {
        x64 ^= x64 >> 12; // a
        x64 ^= x64 << 25; // b
        x64 ^= x64 >> 27; // c
        return x64 * UINT64_C(2685821657736338717);
    }
    /////////////////////////////////////////////////
    uint64_t s1024[16];
    int p;

    uint64_t xorshift1024star(void)
    {
        uint64_t s0 = s1024[ p ];
        uint64_t s1 = s1024[ p = (p+1) & 15 ];
        s1 ^= s1 << 31; // a
        s1 ^= s1 >> 11; // b
        s0 ^= s0 >> 30; // c
        return ( s1024[p] = s0 ^ s1 ) * UINT64_C(1181783497276652981);
    }
    ///////////////////////////////////////////////
    uint64_t s[2];

    uint64_t xorshift128plus(void)
    {
        uint64_t x = s[0];
        uint64_t const y = s[1];
        s[0] = y;
        x ^= x << 23; // a
        x ^= x >> 17; // b
        x ^= y ^ (y >> 26); // c
        s[1] = x;
        return x + y;
    }
//////////////////////////////////////////////
};

#endif // XORSHIFT_H_INCLUDED
