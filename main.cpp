#include <iostream>
#include "sqrt.h"
#include "fastSqrtF.h"
#include <vector>
#include <random>
#include <chrono>
#include <stdio.h>
#include <cstdlib>
#include "xorshift.h"
using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::nanoseconds ns;
typedef std::chrono::duration<float> fsec;



int main()
{




    int samples=100000;
    int inSamples=10;
//    std::cin>> samples;
//    std::cin>>inSamples;

/*
Create vector of constFastSqrt pointers to get less code.
*/
    std::vector<const FastSqrt*> sqrt_v;
    sqrt_v.push_back(new const FastSqrt1());
    sqrt_v.push_back(new const FastSqrt2());
    sqrt_v.push_back(new const FastSqrt3());
    sqrt_v.push_back(new const FastSqrt4());
    sqrt_v.push_back(new const FastSqrt5());
    sqrt_v.push_back(new const FastSqrt6());
    sqrt_v.push_back(new const FastSqrt7());
    sqrt_v.push_back(new const FastSqrt8());
    sqrt_v.push_back(new const FastSqrt9());
    sqrt_v.push_back(new const FastSqrt10());
    sqrt_v.push_back(new const FastSqrt11());



/*
precisionSQRT     - accumulated values of std::sqrt
precisionFastSQRT - accumulated values of FastSqrt
*/
    float precisionSQRT=0.f,precisionFastSQRT=0.f;
    fsec fs=ns(0);
    ns d,d2;

/*
Standard sqrt implementation. Accumulate results of std::sqrt and get time of all calculations.
*/
    for(size_t j=0; j<inSamples; j++)
    {
        auto t0 = Time::now();
        for (size_t i=1; i<samples+1; ++i)
        {
            precisionSQRT+=std::sqrt((float)i);
        }
        auto t1 = Time::now();
        fs = t1 - t0;

        d+= std::chrono::duration_cast<ns>(fs);

    }
/*
Divide time and precision by number of samples, to get accurate values.
*/
    d/=samples;
    precisionSQRT/=samples;


    std::cout<<"\t\tSQRT :\n";
    std::cout <<"\t\tTIME: "<< 100<< "%\n";
    std::cout <<"\t\tPRECISION: "<< 100<< "\n\n";
    std::cout.precision(8);
////////////////////////////////////////////////
/*
FastSqrt implementation.
*/
    for(const FastSqrt * n : sqrt_v)
    {
        ns d2(0);

        for(size_t j=0; j<inSamples; j++)
        {
            auto t0 = Time::now();
            for (size_t i=1; i<samples; ++i)
            {
                precisionFastSQRT+=n->calculate((float)i);
            }
            auto t1 = Time::now();
            fs = t1 - t0;

            d2+= std::chrono::duration_cast<ns>(fs);

        }

        precisionFastSQRT/=samples;
        d2/=samples;

//    std::cout<<"\t\tSQRT :\n";
        n->showName();
        std::cout <<"TIME: "<< (double)100.0f*d.count()/d2.count() << "%\n";

        std::cout <<"PRECISION: "<<(double)precisionSQRT*100/precisionFastSQRT<< "\n\n";


        precisionFastSQRT=0;



    }
{


//    std::cout<<"\n\n\t\t\tFROM METHOD : \n\n";
////////////////////////    SQRT1    ////////////////////////////
//
//
//
//    precisionFastSQRT=0;
//    auto t02 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt1((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t12 = Time::now();
//    fsec fs2 = t12 - t02;
//    std::cout<<"~~~~~~~~~~~~SQRT1~~~~~~~~~~~~\n";
//    ms d2 = std::chrono::duration_cast<ms>(fs2);
//    std::cout << "SPEED: "<<d2.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
////////////////////////    SQRT2    ////////////////////////////
//
//    precisionFastSQRT=0;
//    auto t03 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt2((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t13 = Time::now();
//    fsec fs3 = t13 - t03;
//    std::cout<<"~~~~~~~~~~~~SQRT2~~~~~~~~~~~~\n";
//    ms d3 = std::chrono::duration_cast<ms>(fs3);
//    std::cout << "SPEED: "<<d3.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//
////////////////////////    SQRT3    ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t04 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt3((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t14 = Time::now();
//    fsec fs4 = t14 - t04;
//    std::cout<<"~~~~~~~~~~~~SQRT3~~~~~~~~~~~~\n";
//    ms d4 = std::chrono::duration_cast<ms>(fs4);
//    std::cout << "SPEED: "<<d4.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
////////////////////////    SQRT4    ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t05 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt4((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t15 = Time::now();
//    fsec fs5 = t15 - t05;
//    std::cout<<"~~~~~~~~~~~~SQRT4~~~~~~~~~~~~\n";
//    ms d5 = std::chrono::duration_cast<ms>(fs5);
//    std::cout << "SPEED: "<<d5.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//
////////////////////////    SQRT5    ////////////////////////////
//
//
//double
//
//
//    precisionFastSQRT=0;
//    auto t06 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt5((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t16 = Time::now();
//    fsec fs6= t16 - t06;
//    std::cout<<"~~~~~~~~~~~~SQRT5~~~~~~~~~~~~\n";
//    ms d6 = std::chrono::duration_cast<ms>(fs6);
//    std::cout << "SPEED: "<<d6.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//
//    //////////////////////    SQRT6   ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t07 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt6((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t17 = Time::now();
//    fsec fs7 = t17 - t07;
//    std::cout<<"~~~~~~~~~~~~SQRT6~~~~~~~~~~~~\n";
//    ms d7 = std::chrono::duration_cast<ms>(fs7);
//    std::cout << "SPEED: "<<d7.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//    //////////////////////    SQRT7    ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t08 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt7((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t18 = Time::now();
//    fsec fs8 = t18 - t08;
//    std::cout<<"~~~~~~~~~~~~SQRT7~~~~~~~~~~~~\n";
//    ms d8 = std::chrono::duration_cast<ms>(fs8);
//    std::cout << "SPEED: "<<d8.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//    //////////////////////    SQRT8    ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t09 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt8((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t19 = Time::now();
//    fsec fs9 = t19 - t09;
//    std::cout<<"~~~~~~~~~~~~SQRT8~~~~~~~~~~~~\n";
//    ms d9 = std::chrono::duration_cast<ms>(fs9);
//    std::cout << "SPEED: "<<d9.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//    //////////////////////    SQRT9   ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t020 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt9((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t120 = Time::now();
//    fsec fs20 = t120 - t020;
//    std::cout<<"~~~~~~~~~~~~SQRT9~~~~~~~~~~~~\n";
//    ms d20 = std::chrono::duration_cast<ms>(fs20);
//    std::cout << "SPEED: "<<d20.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
//
//    //////////////////////    SQRT10    ////////////////////////////
//
//
//
//
//
//    precisionFastSQRT=0;
//    auto t0201 = Time::now();
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=sqrt10((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t1201 = Time::now();
//    fsec fs201 = t1201 - t0201;
//    std::cout<<"~~~~~~~~~~~~SQRT10~~~~~~~~~~~~\n";
//    ms d201 = std::chrono::duration_cast<ms>(fs201);
//    std::cout << "SPEED: "<<d201.count() << "ms\n";
//    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
////////////////////////////////// SQRT 11////////////////////////////
//
//
//    precisionFastSQRT=0;
//    auto t021 = Time::now();}
//    for (size_t i=1; i<samples+1; ++i)
//    {
//
//
//        precisionFastSQRT+=asmSqrt((float)i);
//        //std::cout<<precisionFastSQRT<<" @#!\n";
//
//    }
//    auto t121 = Time::now();
//    fsec fs21 = t121 - t021;
//    std::cout<<"~~~~~~~~~~~~SQRT11~~~~~~~~~~~~\n";
//    ms d21 = std::chrono::duration_cast<ms>(fs21);
//    std::cout << "SPEED: "<<d21.count() << "ms\n";
//    std::cout<<"PRECISION: "<<(float)precisionFastSQRT/samples<<"\n";
//    precisionFastSQRT=0;
//
    //// XORSHIFT////
//
}
std::cout<<"~~~~~~~~~~~~~~~~~!!!~~~~~~~~~~~~~~~~~~~~~~~!!!~~~~~~~~~~~~~~!!!~~~~~~~\n";


    fsec fsRand=ns(0);
    ns dRand(0),dXor(0);

/*
Standard rand implementation.
*/
srand(time(0));
    for(size_t j=0; j<inSamples; j++)
    {
        auto t0 = Time::now();
        for (size_t i=1; i<samples+1; ++i)
        {
           rand();
        }
        auto t1 = Time::now();
        fsRand = t1 - t0;

        dRand+= std::chrono::duration_cast<ns>(fsRand);

    }
    //dRand/=samples;
std::cout<<"RAND TIME: 100 %\n";
std::cout<<"RAND TIME: "<<dRand.count()<< "%\n";



 Xorshift * rand= new Xorshift();
for(size_t j=0; j<inSamples; j++)
    {
        auto t0 = Time::now();
        for (size_t i=1; i<samples+1; ++i)
        {
           rand->xorshift128plus();
        }
        auto t1 = Time::now();
        fsRand = t1 - t0;

        dXor+= std::chrono::duration_cast<ns>(fsRand);

    }
    dXor/=samples;
    std::cout<<"Xorshift128+ TIME: "<<(float)100.0f*dXor.count()/dRand.count()<<"\n";
   std::cout<<"Xorshift128+ TIME: "<<dXor.count()<<"\n";

///////////////////////////////////////////////
dXor=ns(0);
for(size_t j=0; j<inSamples; j++)
    {
        auto t0 = Time::now();
        for (size_t i=1; i<samples+1; ++i)
        {
           rand->xorshift128();
        }
        auto t1 = Time::now();
        fsRand = t1 - t0;

        dXor+= std::chrono::duration_cast<ns>(fsRand);

    }
        dXor/=samples;

    std::cout<<"Xorshift128 TIME: "<<(float)100.0f*dXor.count()/dRand.count()<<"\n";
       std::cout<<"Xorshift128 TIME: "<<dXor.count()<<"\n";

///////////////////////////////////////////////
dXor=ns(0);
for(size_t j=0; j<inSamples; j++)
    {
        auto t0 = Time::now();
        for (size_t i=1; i<samples+1; ++i)
        {
           rand->xorshift64star();
        }
        auto t1 = Time::now();
        fsRand = t1 - t0;

        dXor+= std::chrono::duration_cast<ns>(fsRand);

    }
        dXor/=samples;

    std::cout<<"Xorshift64* TIME: "<<(float)100.0f*dXor.count()/dRand.count()<<"\n";
   std::cout<<"Xorshift64* TIME: "<<dXor.count()<<"\n";

///////////////////////////////////////////////
//dXor=ns(0);
//for(size_t j=0; j<inSamples; j++)
//    {
//        auto t0 = Time::now();
//        for (size_t i=1; i<samples+1; ++i)
//        {
//           rand->xorshift1024star;
//        }
//        auto t1 = Time::now();
//        fsRand = t1 - t0;
//
//        dXor+= std::chrono::duration_cast<ns>(fsRand);
//
//    }
//    std::cout<<"Xorshift64* TIME: "<<(float)100.0f*dXor.count()/dRand.count()<<"\n";
//


    return 0 ;
}

