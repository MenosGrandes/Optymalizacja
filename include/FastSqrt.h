#ifndef FASTSQRT_H
#define FASTSQRT_H


class FastSqrt
{
    public:
        FastSqrt();
        virtual ~FastSqrt();
        const virtual float calculate(const float val) const =0;
        const virtual void showName()const =0 ;
};

#endif // FASTSQRT_H
