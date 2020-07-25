//
// Created by LioraPinkhasov on 24/07/2020.
//

#ifndef SOLVER_SOLVER_HPP
#define SOLVER_SOLVER_HPP


#pragma once
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

namespace solver
{

    //define real variable class
    class RealVariable
    {
    public:

           double number;

           //define varibales we may nedd
           double Apower = 0; //as we did in opp
           double Bcoff = 1; //as we did in opp
           double Canswer = 0; //as we did in opp

           //constructors
            RealVariable() : Apower(0), Bcoff(1), Canswer(0){}
            RealVariable(double a, double b, double c) : Apower(a), Bcoff(b), Canswer(c) {}

           //put everything into a vector and do the equation from there
           vector <string> realnumbers (string text);


           // ==
           friend RealVariable operator==(RealVariable x, double number);
           friend RealVariable operator==(double number, RealVariable x);
           friend RealVariable operator==(RealVariable x, RealVariable y);

          //+
          friend RealVariable operator+(RealVariable x,double number);
          friend RealVariable operator+( double number,  RealVariable x);
          friend RealVariable operator+( RealVariable x, RealVariable y);


          //-
          friend RealVariable operator-(RealVariable x, double number);
          friend RealVariable operator-(double number, RealVariable x);
          friend RealVariable operator-(RealVariable x, RealVariable y);


          //*
          friend RealVariable operator*(RealVariable x, double number);
          friend RealVariable operator*(double number, RealVariable x);
          friend RealVariable operator*(RealVariable x, RealVariable y);

          //^
          friend RealVariable operator^(RealVariable x, double number);

          // /
          friend RealVariable operator/(RealVariable x, double number);
          friend RealVariable operator/(RealVariable x, RealVariable y);

    };


    //define complex variable class
    class ComplexVariable
    {
    public:
        //put in there all the values in the string
        vector <string> realnumbers (string text);

        //define varibales we may nedd
        complex <double> Ca = 0; //as we did in opp
        complex <double> Cb = 1; //as we did in opp
        complex <double> Cc = 0; //as we did in opp

        //define varibles for now use
        //complex<double> comp = 0. + 0i;
        ComplexVariable() : Ca(0),Cb(1),Cc(0) {}
        ComplexVariable(complex<double> a,complex<double> b , complex<double> c) : Ca(a), Cb(b) , Cc(c) {}

        //==
        friend ComplexVariable operator==(ComplexVariable x, complex<double> complexnumber);
        friend ComplexVariable operator==(complex<double> complexnumber, ComplexVariable x);
        friend ComplexVariable operator==(ComplexVariable x, ComplexVariable y);

        //+
        friend ComplexVariable operator+(ComplexVariable x, complex<double> complexnumber);
        friend ComplexVariable operator+(complex<double> complexnumber, ComplexVariable x);
        friend ComplexVariable operator+(ComplexVariable x, ComplexVariable y);

        //-
        friend ComplexVariable operator-(ComplexVariable x, complex<double> complexnumber);
        friend ComplexVariable operator-(complex<double> complexnumber, ComplexVariable x);
        friend ComplexVariable operator-(ComplexVariable x, ComplexVariable y);

        //*
        friend ComplexVariable operator*(ComplexVariable x, complex<double> complexnumber);
        friend ComplexVariable operator*(complex<double> complexnumber, ComplexVariable x);
        friend ComplexVariable operator*(ComplexVariable x, ComplexVariable y);


        // /
        friend ComplexVariable operator/(ComplexVariable x, complex<double> complexnumber);
        friend ComplexVariable operator/(ComplexVariable x, ComplexVariable y);

        //^
        friend ComplexVariable operator^(ComplexVariable x, double complexnumber);



    };

    //solve func
    double solve(RealVariable x); //get real variable and return answer in double.
    double solve(bool ex);
    complex<double> solve(ComplexVariable x); //get complex variable and return answer in complex double.


}

#endif //SOLVER_SOLVER_HPP
