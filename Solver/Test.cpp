#include "doctest.h"
#include "solver.hpp"
#include <complex>


TEST_CASE("not real test - Real Variable")
{
    solver::RealVariable x;
    CHECK_NOTHROW(3*x==x);
    CHECK_NOTHROW(x+4==x);
    CHECK_NOTHROW(x-6==x);
    CHECK_NOTHROW(5+5*x==x);
    CHECK_NOTHROW(x/5==x);
    CHECK_NOTHROW(5*x==x);
    CHECK_NOTHROW(6*x==x);
    CHECK_NOTHROW(7*x==x);
    CHECK_NOTHROW(8*x==x);
    CHECK_NOTHROW(9*x==x);
    CHECK_NOTHROW(10*x==x);
    CHECK_NOTHROW(1+x==x);
    CHECK_NOTHROW(2+x==x);
    CHECK_NOTHROW(3+x==x);
    CHECK_NOTHROW(4+x==x);
    CHECK_NOTHROW(5+x==x);
    CHECK_NOTHROW(6+x==x);
    CHECK_NOTHROW(9+x==x);
    CHECK_NOTHROW(10+x==x);
    CHECK_NOTHROW(x-1==x);
    CHECK_NOTHROW(x-2==x);
    CHECK_NOTHROW(x-3==x);
    CHECK_NOTHROW(x-4==x);
    CHECK_NOTHROW(x-5==x);
    CHECK_NOTHROW(x-6==1);
    CHECK_NOTHROW(x-7==1);
    CHECK_NOTHROW(x-8==1);
    CHECK_NOTHROW(x-9==1);
    CHECK_NOTHROW(x/1==1);
    CHECK_NOTHROW(x/2==1);
    CHECK_NOTHROW(x/3==1);
    CHECK_NOTHROW(x/4==1);
    CHECK_NOTHROW(2+2*x==1);
    CHECK_NOTHROW(1+1*x==1);
    CHECK_NOTHROW(3+3*x==1);
    CHECK_NOTHROW(4*x+4==1);
    CHECK_NOTHROW(6*x+5==1);
    CHECK_NOTHROW(5*x+6==1);
    CHECK_NOTHROW(7*x+7==1);
    CHECK_NOTHROW(8*x+8==1);
    CHECK_NOTHROW(9*x+9==1);
    CHECK_NOTHROW(x/6==1);
    CHECK_NOTHROW(x/7==1);
}


TEST_CASE("not real test - Real Variable")
{
    solver::RealVariable z;
    CHECK_NOTHROW(3*z==1);
    CHECK_NOTHROW(z+4==1);
    CHECK_NOTHROW(z-6==1);
    CHECK_NOTHROW(5+5*z==1);
    CHECK_NOTHROW(z/5==1);
    CHECK_NOTHROW(5*z==1);
    CHECK_NOTHROW(6*z==1);
    CHECK_NOTHROW(7*z==1);
    CHECK_NOTHROW(8*z==1);
    CHECK_NOTHROW(9*z==1);
    CHECK_NOTHROW(10*z==1);
    CHECK_NOTHROW(1+z==1);
    CHECK_NOTHROW(2+z==1);
    CHECK_NOTHROW(3+z==1);
    CHECK_NOTHROW(4+z==1);
    CHECK_NOTHROW(5+z==1);
    CHECK_NOTHROW(6+z==1);
    CHECK_NOTHROW(9+z==1);
    CHECK_NOTHROW(10+z==1);
    CHECK_NOTHROW(z-1==1);
    CHECK_NOTHROW(z-2==1);
    CHECK_NOTHROW(z-3==1);
    CHECK_NOTHROW(z-4==1);
    CHECK_NOTHROW(z-5==1);
    CHECK_NOTHROW(z-6==1);
    CHECK_NOTHROW(z-7==1);
    CHECK_NOTHROW(z-8==1);
    CHECK_NOTHROW(z-9==1);
    CHECK_NOTHROW(z/1==1);
    CHECK_NOTHROW(z/2==1);
    CHECK_NOTHROW(z/3==1);
    CHECK_NOTHROW(z/4==1);
    CHECK_NOTHROW(1*z+1==1);
    CHECK_NOTHROW(2*z+2==1);
    CHECK_NOTHROW(3*z+3==1);
    CHECK_NOTHROW(4*z+4==1);
    CHECK_NOTHROW(5*z+5==1);
    CHECK_NOTHROW(6*z+6==1);
    CHECK_NOTHROW(7*z+7==1);
    CHECK_NOTHROW(8*z+8==1);
    CHECK_NOTHROW(9*z+9==1);
    CHECK_NOTHROW(z/6==1);
    CHECK_NOTHROW(z/7==1);
}


TEST_CASE("not real test - Complex Variable")
{
    solver::ComplexVariable y;
    CHECK_NOTHROW(solve(3*y==y));
    CHECK_NOTHROW(solve(y+4==y));
    CHECK_NOTHROW(solve(y-6==1));
    CHECK_NOTHROW(solve(5+5*y==1));
    CHECK_NOTHROW(solve(y/5==1));
    CHECK_NOTHROW(solve(5*y==1));
    CHECK_NOTHROW(solve(6*y==1));
    CHECK_NOTHROW(solve(7*y==1));
    CHECK_NOTHROW(solve(8*y==1));
    CHECK_NOTHROW(solve(9*y==1));
    CHECK_NOTHROW(solve(10*y==1));
    CHECK_NOTHROW(solve(1+y==1));
    CHECK_NOTHROW(solve(2+y==1));
    CHECK_NOTHROW(solve(3+y==1));
    CHECK_NOTHROW(solve(4+y==1));
    CHECK_NOTHROW(solve(5+y==1));
    CHECK_NOTHROW(solve(6+y==1));
    CHECK_NOTHROW(solve(9+y==1));
    CHECK_NOTHROW(solve(10+y==1));
    CHECK_NOTHROW(solve(1-y==1));
    CHECK_NOTHROW(solve(2-y==1));
    CHECK_NOTHROW(solve(3-y==1));
    CHECK_NOTHROW(solve(4-y==1));
    CHECK_NOTHROW(solve(5-y==1));
    CHECK_NOTHROW(solve(6-y==1));
    CHECK_NOTHROW(solve(7-y==1));
    CHECK_NOTHROW(solve(8-y==1));
    CHECK_NOTHROW(solve(9-y==1));
    CHECK_NOTHROW(solve(y/1==1));
    CHECK_NOTHROW(solve(y/2==1));
    CHECK_NOTHROW(solve(y/3==1));
    CHECK_NOTHROW(solve(y/4==1));
    CHECK_NOTHROW(solve(1*y+1==1));
    CHECK_NOTHROW(solve(y*2+2==1));
    CHECK_NOTHROW(solve(y*3+3==1));
    CHECK_NOTHROW(solve(y*4+4==1));
    CHECK_NOTHROW(solve(y*5+5==1));
    CHECK_NOTHROW(solve(y*6+6==1));
    CHECK_NOTHROW(solve(y*7+7==1));
    CHECK_NOTHROW(solve(y*8+8==1));
    CHECK_NOTHROW(solve(y*9+9==1));
    CHECK_NOTHROW(solve(y/6==1));
    CHECK_NOTHROW(solve(y/7==1));
}




TEST_CASE("true solver - liner equation")
{
    solver::RealVariable x;
            CHECK(solve(1*x == 2) == 2);
            CHECK(solve(2*x == 2) == 1);
            CHECK(solve(3*x == 2) == 2/3);
            CHECK(solve(4*x == 2) == 1/2);
            CHECK(solve(5*x == 10) == 2);
            CHECK(solve(6*x == 12) == 2);
            CHECK(solve(7*x == 14) == 2);
            CHECK(solve(8*x == 16) == 2);
            CHECK(solve(9*x == 18) == 2);
            CHECK(solve(10*x == 20) == 2);
            CHECK(solve(11*x == 22) == 2);

            CHECK(solve(2*x-2 == 10) == 6);
            CHECK(solve(3*x-3 == 9) == 4);
            CHECK(solve(4*x-4 == 8) == 3);
            CHECK(solve(5*x-5 == 10) == 3);
            CHECK(solve(6*x-6 == 12) == 3);
            CHECK(solve(7*x-7 == 7) == 2);
            CHECK(solve(8*x-8 == 16) == 3);
            CHECK(solve(9*x-9 == 0) == 1);
            CHECK(solve(10*x-10 == 0) == 1);
            CHECK(solve(1*x-1 == 0) == 1);
            CHECK(solve(1*x+1 == 0) == -1);
            CHECK(solve(2*x+2 == 0) == -1);
            CHECK(solve(3*x+3 == 0) == -1);
            CHECK(solve(4*x+4 == 0) == -1);
            CHECK(solve(5*x+5 == 0) == -1);
            CHECK(solve(6*x+6 == 0) == -1);
            CHECK(solve(7*x+7 == 0) == -1);
            CHECK(solve(8*x+8 == 0) == -1);
            CHECK(solve(9*x+9 == 0) == -1);
            CHECK(solve(10*x+10 == 0) == -1);

}

TEST_CASE("true solver - polinom equation")
{
    solver::RealVariable x;
            CHECK(solve((x^2) == 1) == 1);
            CHECK(solve((x^2) == 1) == -1);
            CHECK(solve((x^2) == 4) == 2);
            CHECK(solve((x^2) == 4) == -2);
            CHECK(solve((x^2) == 9) == 3);
            CHECK(solve((x^2) == 9) == -3);
            CHECK(solve((x^2) == 16) == 4);
            CHECK(solve((x^2) == 16) == -4);
            CHECK(solve((x^2) == 25) == 5);
            CHECK(solve((x^2) == 25) == -5);
            CHECK(solve((x^2) == 36) == 6);
            CHECK(solve((x^2) == 36) == -6);
            CHECK(solve((x^2) == 49) == 7);
            CHECK(solve((x^2) == 49) == -7);
            CHECK(solve((x^2) == 64) == 8);
            CHECK(solve((x^2) == 64) == -8);
            CHECK(solve((x^2) == 81) == 9);
            CHECK(solve((x^2) == 81) == -9);
            CHECK(solve((x^2) == 100) == 10);
            CHECK(solve((x^2) == 100) == -10);
}