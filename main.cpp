#include <iostream>
#include "sqrt.h"
#include "fastSqrtF.h"
#include <vector>
#include <random>
#include <chrono>
#include <stdio.h>
#include "xorshift.h"
using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;



int main()
{
int samples=0;
    std::cin>> samples;

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




    float sqrtN=0.f,fastSqrtN=0.f,precisionSQRT=0.f,precisionFastSQRT=0.f;

    auto t0 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {
        precisionSQRT+=sqrt((float)i);
    }
    auto t1 = Time::now();
    fsec fs = t1 - t0;

    ms d = std::chrono::duration_cast<ms>(fs);

    precisionSQRT/=(float)samples;


    std::cout<<"\t\tSQRT :\n";
    std::cout <<"\t\tTIME: "<< d.count() << "ms\n";
    std::cout <<"\t\tPRECISION: "<< precisionSQRT << "\n\n";

////////////////////////////////////////////////
    for(const FastSqrt * n : sqrt_v)
    {



        precisionFastSQRT=0;
        auto t02 = Time::now();
        for (size_t i=1; i<samples+1; ++i)
        {


            precisionFastSQRT+=n->calculate((float)i);
            //std::cout<<precisionFastSQRT<<" @#!\n";

        }
        auto t12 = Time::now();
        fsec fs2 = t12 - t02;
        n->showName();
        ms d2 = std::chrono::duration_cast<ms>(fs2);
        std::cout << "SPEED: "<<d2.count() << "ms\n";
        std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
        precisionFastSQRT=0;

    }
    std::cout<<"\n\n\t\t\tFROM METHOD : \n\n";
//////////////////////    SQRT1    ////////////////////////////



    precisionFastSQRT=0;
    auto t02 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt1((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t12 = Time::now();
    fsec fs2 = t12 - t02;
    std::cout<<"~~~~~~~~~~~~SQRT1~~~~~~~~~~~~\n";
    ms d2 = std::chrono::duration_cast<ms>(fs2);
    std::cout << "SPEED: "<<d2.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;

//////////////////////    SQRT2    ////////////////////////////

    precisionFastSQRT=0;
    auto t03 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt2((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t13 = Time::now();
    fsec fs3 = t13 - t03;
    std::cout<<"~~~~~~~~~~~~SQRT2~~~~~~~~~~~~\n";
    ms d3 = std::chrono::duration_cast<ms>(fs3);
    std::cout << "SPEED: "<<d3.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;


//////////////////////    SQRT3    ////////////////////////////





    precisionFastSQRT=0;
    auto t04 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt3((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t14 = Time::now();
    fsec fs4 = t14 - t04;
    std::cout<<"~~~~~~~~~~~~SQRT3~~~~~~~~~~~~\n";
    ms d4 = std::chrono::duration_cast<ms>(fs4);
    std::cout << "SPEED: "<<d4.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;
//////////////////////    SQRT4    ////////////////////////////





    precisionFastSQRT=0;
    auto t05 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt4((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t15 = Time::now();
    fsec fs5 = t15 - t05;
    std::cout<<"~~~~~~~~~~~~SQRT4~~~~~~~~~~~~\n";
    ms d5 = std::chrono::duration_cast<ms>(fs5);
    std::cout << "SPEED: "<<d5.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;


//////////////////////    SQRT5    ////////////////////////////





    precisionFastSQRT=0;
    auto t06 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt5((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t16 = Time::now();
    fsec fs6= t16 - t06;
    std::cout<<"~~~~~~~~~~~~SQRT5~~~~~~~~~~~~\n";
    ms d6 = std::chrono::duration_cast<ms>(fs6);
    std::cout << "SPEED: "<<d6.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;


    //////////////////////    SQRT6   ////////////////////////////





    precisionFastSQRT=0;
    auto t07 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt6((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t17 = Time::now();
    fsec fs7 = t17 - t07;
    std::cout<<"~~~~~~~~~~~~SQRT6~~~~~~~~~~~~\n";
    ms d7 = std::chrono::duration_cast<ms>(fs7);
    std::cout << "SPEED: "<<d7.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;

    //////////////////////    SQRT7    ////////////////////////////





    precisionFastSQRT=0;
    auto t08 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt7((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t18 = Time::now();
    fsec fs8 = t18 - t08;
    std::cout<<"~~~~~~~~~~~~SQRT7~~~~~~~~~~~~\n";
    ms d8 = std::chrono::duration_cast<ms>(fs8);
    std::cout << "SPEED: "<<d8.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;

    //////////////////////    SQRT8    ////////////////////////////





    precisionFastSQRT=0;
    auto t09 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt8((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t19 = Time::now();
    fsec fs9 = t19 - t09;
    std::cout<<"~~~~~~~~~~~~SQRT8~~~~~~~~~~~~\n";
    ms d9 = std::chrono::duration_cast<ms>(fs9);
    std::cout << "SPEED: "<<d9.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;

    //////////////////////    SQRT9   ////////////////////////////





    precisionFastSQRT=0;
    auto t020 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt9((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t120 = Time::now();
    fsec fs20 = t120 - t020;
    std::cout<<"~~~~~~~~~~~~SQRT9~~~~~~~~~~~~\n";
    ms d20 = std::chrono::duration_cast<ms>(fs20);
    std::cout << "SPEED: "<<d20.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;


    //////////////////////    SQRT10    ////////////////////////////





    precisionFastSQRT=0;
    auto t0201 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=sqrt10((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t1201 = Time::now();
    fsec fs201 = t1201 - t0201;
    std::cout<<"~~~~~~~~~~~~SQRT10~~~~~~~~~~~~\n";
    ms d201 = std::chrono::duration_cast<ms>(fs201);
    std::cout << "SPEED: "<<d201.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;

//////////////////////////////// SQRT 11////////////////////////////


    precisionFastSQRT=0;
    auto t021 = Time::now();
    for (size_t i=1; i<samples+1; ++i)
    {


        precisionFastSQRT+=asmSqrt((float)i);
        //std::cout<<precisionFastSQRT<<" @#!\n";

    }
    auto t121 = Time::now();
    fsec fs21 = t121 - t021;
    std::cout<<"~~~~~~~~~~~~SQRT11~~~~~~~~~~~~\n";
    ms d21 = std::chrono::duration_cast<ms>(fs21);
    std::cout << "SPEED: "<<d21.count() << "ms\n";
    std::cout<<"PRECISION: "<<precisionFastSQRT/samples<<"\n";
    precisionFastSQRT=0;


    //// XORSHIFT////

std::cout<<"~~~~~~~~~~~~~~~~~!!!~~~~~~~~~~~~~~~~~~~~~~~!!!~~~~~~~~~~~~~~!!!~~~~~~~\n";

    for(int i=0;i<samples;++i)
    {
            std::cout<<xorshift64star(i)%100<<"\n";

    }

    return 0 ;
}

