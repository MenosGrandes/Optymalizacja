#ifndef SQRT_H_INCLUDED
#define SQRT_H_INCLUDED
#include "FastSqrt.h"
#define SQRT_MAGIC_F 0x5f3759df
class FastSqrt1:public FastSqrt
{
public:
    const virtual float calculate(const float x) const
    {
        union
        {
            int i;
            float x;
        } u;
        u.x = x;
        u.i = (1<<29) + (u.i >> 1) - (1<<22);

        // Two Babylonian Steps (simplified from:)
        // u.x = 0.5f * (u.x + x/u.x);
        // u.x = 0.5f * (u.x + x/u.x);
        u.x =       u.x + x/u.x;
        u.x = 0.25f*u.x + x/u.x;

        return u.x;
    }
    const virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt1~~~~~~~~~~\n";
    }
};
class FastSqrt2:public FastSqrt
{
    const virtual float calculate(const float x)const
    {
        const float xhalf = 0.5f*x;

        union // get bits for floating value
        {
            float x;
            int i;
        } u;
        u.x = x;
        u.i = SQRT_MAGIC_F - (u.i >> 1);  // gives initial guess y0
        return x*u.x*(1.5f - xhalf*u.x*u.x);// Newton step, repeating increases accuracy
    }
    const virtual void showName()const
    {
        std::cout<<"~~~~~~~~~~FastSqrt2~~~~~~~~~~\n";
    }
};
class FastSqrt3:public FastSqrt
{
    const virtual float calculate(const float x)const
    {
        union
        {
            int i;
            float x;
        } u;

        u.x = x;
        u.i = (1<<29) + (u.i >> 1) - (1<<22);
        return u.x;
    }
    const virtual void showName()const
    {
        std::cout<<"~~~~~~~~~~FastSqrt3~~~~~~~~~~\n";
    }
};
class FastSqrt4:public FastSqrt
{
    const virtual float calculate(const float m)const
    {
        int i=0;
        while( (i*i) <= m )
            i++;
        i--;
        float d = m - i*i;
        float p=d/(2*i);
        float a=i+p;
        return a-(p*p)/(2*a);
    }
    const   virtual void showName()const
    {
        std::cout<<"~~~~~~~~~~FastSqrt4~~~~~~~~~~\n";
    }
};
class FastSqrt5:public FastSqrt
{
    const virtual float calculate(const float m)const
    {
        float i=0;
        float x1,x2;
        while( (i*i) <= m )
            i+=0.1f;
        x1=i;
        for(int j=0; j<10; j++)
        {
            x2=m;
            x2/=x1;
            x2+=x1;
            x2/=2;
            x1=x2;
        }
        return x2;
    }
    const  virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt5~~~~~~~~~~\n";
    }
};
class FastSqrt6:public FastSqrt
{
    const virtual float calculate(const float y) const
    {
        double x, z, tempf;
        unsigned long *tfptr = ((unsigned long *)&tempf) + 1;
        tempf = y;
        *tfptr = (0xbfcdd90a - *tfptr)>>1;
        x =  tempf;
        z =  y*0.5;
        x = (1.5*x) - (x*x)*(x*z);    //The more you make replicates of this statement
        //the higher the accuracy, here only 2 replicates are used
        x = (1.5*x) - (x*x)*(x*z);
        return x*y;
    }
    const  virtual void showName()const
    {
        std::cout<<"~~~~~~~~~~FastSqrt6~~~~~~~~~~\n";
    }
};
class FastSqrt7:public FastSqrt
{
    const virtual float calculate(const float x)const
    {
        unsigned int i = *(unsigned int*) &x;
        // adjust bias
        i  += 127 << 23;
        // approximation of square root
        i >>= 1;
        return *(float*) &i;
    }
    const  virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt7~~~~~~~~~~\n";
    }
};
class FastSqrt8:public FastSqrt
{
    const   virtual float calculate(const float fg) const
    {
        double n = fg / 2.0;
        double lstX = 0.0;
        while(n != lstX)
        {
            lstX = n;
            n = (n + fg/n) / 2.0;
        }
        return n;
    }
    const   virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt8~~~~~~~~~~\n";
    }
};
class FastSqrt9:public FastSqrt
{
    const  virtual float calculate(const float Nbr)const
    {
        double Number = Nbr / 2;
        const double Tolerance = 1.0e-7;
        do
        {
            Number = (Number + Nbr / Number) / 2;
        }
        while( Abs(Number * Number - Nbr) > Tolerance);

        return Number;
    }
    const double Abs(double Nbr)const
    {
        if( Nbr >= 0 )
            return Nbr;
        else
            return -Nbr;
    }
    const  virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt9~~~~~~~~~~\n";
    }

};
class FastSqrt10:public FastSqrt
{
    const    virtual float calculate(const float number) const
    {
        const double ACCURACY=0.001;
        double lower, upper, guess;

        if (number < 1)
        {
            lower = number;
            upper = 1;
        }
        else
        {
            lower = 1;
            upper = number;
        }

        while ((upper-lower) > ACCURACY)
        {
            guess = (lower + upper)/2;
            if(guess*guess > number)
                upper =guess;
            else
                lower = guess;
        }
        return (lower + upper)/2;
    }
    const    virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt10~~~~~~~~~~\n";
    }
};
class FastSqrt11 : public FastSqrt
{

    const    virtual float calculate(const float number) const
    {
        float n=number;
        __asm__ ("fsqrt" : "+t" (n));
        return n;
    }
    const    virtual void showName() const
    {
        std::cout<<"~~~~~~~~~~FastSqrt11~~~~~~~~~~\n";
    }

};
#endif // SQRT_H_INCLUDED
