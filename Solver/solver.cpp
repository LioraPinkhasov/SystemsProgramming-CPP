//
// Created by LioraPinkhasov on 24/07/2020.
//
#include "solver.hpp"
#include <complex>
#include <stdexcept>

using namespace solver;
using namespace std;
RealVariable temp(0,0,0);
ComplexVariable tempcomp(0,0,0);

double solver::solve(RealVariable x)
{
    double answer=-1;
    double answer2=-1;
    double a = x.Apower;
    double b = x.Bcoff;
    double c= x.Canswer;

    //double a = x.Apower, b = x.Bcoff, c = x.Canswer;

    //if there are no data at x
    if (a==0 && b==0 && c==0)
    {
        return INFINITY;
    }

    //if the equation is a liner one
    if (a==0)
    {
        if ((b==0) && (c!=0))
        {
            throw invalid_argument ("invalid solution :: there is no solution");
        }
        else
        {
            answer = (-1)*c;
            answer=answer/b;
            return answer;
        }

    }

    if (b==0)
    {
        if (a==1 && c<0)
        {
            c=c*(-1);
            answer=sqrt(c);
            return answer;
        }

        if (a>0 && c<0)
        {
            c=c*(-1);
            c=c/a;
            answer=sqrt(c);
            return answer;
        }
    }

    double t = b * b - 4.0 * a * c;
    if (t >= 0)
    {
        answer = (-b) + sqrt(t);
        answer = answer/(2*a);

        answer2 = (-b) + sqrt(t);
        answer2 = answer2/(2*a);
        return answer;
    }

    throw invalid_argument ("There is no real solution");


}

double solver::solve(bool ex)
{
    return 0.0;
}

complex<double> solver::solve(ComplexVariable x)
{
    complex<double> answer=-1.0;

    complex <double> a = x.Ca;
    complex <double> b = x.Cb;
    complex <double> c = x.Cc;
    complex <double> t = b * b - complex<double>(4.0, 0.0) * a * c;



    if (a == complex<double> (0,0) && b == complex <double> (0,0) && c == complex <double> (0,0))
    {
        return INFINITY;
    }

    if (a == complex<double> (0.0,0.0 ))
    {
        if (b == complex<double>(0.0, 0.0) && c != complex<double>(0.0, 0.0)) {
            throw invalid_argument("There is no real solution");
        } else {
            answer = -c / b;
            return answer;
        }
    }


        answer = (-b + sqrt(t));
        answer = answer/(complex<double>(2.0, -0.0) * a);
        return answer;


};


////////////////////////////////////////////////RealVariable sega\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//RealVariable class

//==
RealVariable solver::operator==(RealVariable x, double number)//real = double
{
    RealVariable temp(0,0,0);
    temp = x-number;
    return temp;

}

RealVariable solver::operator==(double number, RealVariable x)//double = real
{
    RealVariable temp(0,0,0);
    temp = number-x;
    return temp;

}

RealVariable solver::operator==(RealVariable x, RealVariable y)//real a = real b
{

    return x-y;
}


//+
RealVariable solver::operator+(RealVariable x,double number) //real+number
{
    RealVariable temp(0,0,0);
    temp.Apower=x.Apower;
    temp.Bcoff=x.Bcoff;
    temp.Canswer=x.Canswer+number;
    return temp;
}

RealVariable solver::operator+( double number,  RealVariable x)//number+real
{
    RealVariable temp(0,0,0);
    temp.Apower=x.Apower;
    temp.Bcoff=x.Bcoff;
    temp.Canswer=number+x.Canswer;
    return temp;
}

RealVariable solver::operator+( RealVariable x, RealVariable y)//real+real
{
    RealVariable temp(0,0,0);
    temp.Apower=x.Apower+y.Apower;
    temp.Bcoff=x.Bcoff+y.Bcoff;
    temp.Canswer=x.Canswer+y.Canswer;
    return temp;
}


//-
RealVariable solver::operator-(RealVariable x, double number)//real-number
{
    RealVariable temp(0,0,0);
    temp.Apower=x.Apower;
    temp.Bcoff=x.Bcoff;
    temp.Canswer=x.Canswer-number;
    return temp;
}

RealVariable solver::operator-(double number, RealVariable x)//number-real
{
    RealVariable temp(0,0,0);
    temp.Apower=x.Apower;
    temp.Bcoff=x.Bcoff;
    temp.Canswer=number-x.Canswer;
    return temp;
}

RealVariable solver::operator-(RealVariable x, RealVariable y)//real-real
{
    RealVariable temp(0,0,0);
    temp.Apower=x.Apower-y.Apower;
    temp.Bcoff=x.Bcoff-y.Bcoff;
    temp.Canswer=x.Canswer-y.Canswer;
    return temp;
}


//*
RealVariable solver::operator*(RealVariable x, double number)//real*number
{
    RealVariable temp(0,0,0);
    temp.Apower=number*x.Apower;
    temp.Bcoff=number*x.Bcoff;
    temp.Canswer=number*x.Canswer;
    return temp;
}
RealVariable solver::operator*(double number, RealVariable x)//number*real
{
    RealVariable temp (0,0,0);
    temp.Apower=number*x.Apower;
    temp.Bcoff=number*x.Bcoff;
    temp.Canswer=number*x.Canswer;
    return temp;
}

RealVariable solver::operator*(RealVariable x, RealVariable y)//reala*realb
{
    if (x.Apower!=0 && y.Apower!=0)
    {
        throw invalid_argument ("invalid power :: too big");
    }

    if (x.Apower!=0 && y.Bcoff!=0)
    {
        throw invalid_argument ("invalid power :: too big");
    }

    if (x.Bcoff!=0 && y.Apower!=0)
    {
        throw invalid_argument("invalid power :: too big");
    }

    RealVariable temp(0,0,0);
    temp.Apower=x.Apower*y.Canswer+y.Apower*x.Canswer+x.Bcoff+y.Bcoff;
    temp.Bcoff=x.Bcoff*y.Canswer+x.Canswer*y.Bcoff;
    temp.Canswer=x.Canswer*y.Canswer;
    return temp;
}

//^
RealVariable solver::operator^(RealVariable x, double number)//x^number
{
    RealVariable temp(0,0,0);
    if (number == 2)
    {
        temp.Apower=x.Apower+x.Bcoff*x.Bcoff;
        temp.Bcoff=0;
        temp.Canswer=x.Canswer;
        return temp;
        return x*x;
    }

    if (number == 1)
    {
        return x;
    }

    if (number == 0)
    {
        temp.Apower=0;
        temp.Bcoff=0;
        temp.Canswer=1;
    }


    throw invalid_argument ("invalid power :: the power is not valid");
}

// /
RealVariable solver::operator/(RealVariable x, double number)//real/number
{
    RealVariable temp(0,0,0);
    if (number == 0)
    {
        throw invalid_argument ("invalid division :: you cant divide by zero");
    }

    temp.Apower=x.Apower/number;
    temp.Bcoff=x.Bcoff/number;
    temp.Canswer=x.Canswer/number;
    return temp;
}

RealVariable solver::operator/(RealVariable x, RealVariable y)//reala//realb
{
    RealVariable temp(0,0,0);
    if (y.Apower==0 && y.Bcoff==0 &&y.Canswer==0)
    {
        throw invalid_argument("cannot divided by zero");
    }

    if (y.Apower == x.Apower && y.Bcoff == x.Bcoff && y.Canswer == x.Canswer)
    {
        temp.Apower=0;
        temp.Bcoff=0;
        temp.Canswer=1;
        return temp;
    }

    if (x.Apower == 0 && x.Bcoff == 0 && x.Canswer == 0)
    {
        temp.Apower=0;
        temp.Bcoff=0;
        temp.Canswer=1;
        return temp;
    }

    if (x.Apower==y.Apower && x.Canswer==0 && y.Canswer==0 && x.Bcoff != 0)
    {
        temp.Apower=0;
        temp.Bcoff=x.Bcoff/y.Bcoff;//? if make problem change to y/x
        temp.Canswer=1;
        return temp;
    }

    if (y.Bcoff == x.Bcoff && y.Canswer == 0 && x.Canswer == 0 && x.Apower != 0)
    {
        temp.Apower=x.Apower/y.Apower;
        temp.Bcoff=0;
        temp.Canswer=0;
        return temp;
    }

    if (y.Bcoff== x.Bcoff && y.Apower == 0 && x.Apower == 0 && x.Canswer!=0)
    {
        temp.Apower=0;
        temp.Bcoff=0;
        temp.Canswer=y.Canswer/x.Canswer;
        return temp;
    }

    throw invalid_argument ("invalid data :: cant find a way to division");

}

//////////////////////complex values sega////////////////////

//==
ComplexVariable solver::operator==(ComplexVariable x, complex<double> complexnumber)//complexv = double complex
{
    ComplexVariable temp(0,0,0);
    temp = x - complexnumber;
    return temp;
}

ComplexVariable solver::operator==(complex<double> complexnumber, ComplexVariable x)//double complex = complexv
{
    ComplexVariable temp(0,0,0);
    temp = complexnumber - x;
    return temp;
}

ComplexVariable solver::operator==(ComplexVariable x, ComplexVariable y)//complexva = complexvb
{
    ComplexVariable temp((0.0),(0.0),(0.0));
    temp.Ca=x.Ca-y.Ca;
    temp.Cb=x.Cb-y.Cb;
    temp.Cc=x.Cc-y.Cc;
    return temp;
}

//+
ComplexVariable solver::operator+(ComplexVariable x, complex<double> complexnumber)// double complex + complexv
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca;
    temp.Cb=x.Cb;
    temp.Cc=x.Cc+complexnumber;
    return temp;
}

ComplexVariable solver::operator+(complex<double> complexnumber, ComplexVariable x)//complexv + double complex
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca;
    temp.Cb=x.Cb;
    temp.Cc=complexnumber+x.Cc;
    return temp;
}
ComplexVariable solver::operator+(ComplexVariable x, ComplexVariable y)//complexva + complexvb
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca+y.Ca;
    temp.Cb=x.Cb+y.Cb;
    temp.Cc=x.Cc+y.Cc;
    return temp;
}

//-
ComplexVariable solver::operator-(ComplexVariable x, complex<double> complexnumber)//complexv - double complex
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca;
    temp.Cb=x.Cb;
    temp.Cc=x.Cc-complexnumber;
    return temp;
}

ComplexVariable solver::operator-(complex<double> complexnumber, ComplexVariable x)//double complex - complexv
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca;
    temp.Cb=x.Cb;
    temp.Cc=complexnumber-x.Cc;
    return temp;
}

ComplexVariable solver::operator-(ComplexVariable x, ComplexVariable y)//complexva - complexvb
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca-y.Ca;
    temp.Cb=x.Cb-y.Cb;
    temp.Cc=x.Cc-y.Cc;
    return temp;
}

//*
ComplexVariable solver::operator*(ComplexVariable x, complex<double> complexnumber) //complexv * double complex
{
    ComplexVariable temp(0,0,0);
    temp.Ca=x.Ca*complexnumber;
    temp.Cb=x.Cb*complexnumber;
    temp.Cc=x.Cc*complexnumber;
    return temp;
}

ComplexVariable solver::operator*(complex<double> complexnumber, ComplexVariable x)//double complex * complexv
{
    ComplexVariable temp(0,0,0);
    temp.Ca=complexnumber*x.Ca;
    temp.Cb=complexnumber*x.Cb;
    temp.Cc=complexnumber*x.Cc;
    return temp;
}

ComplexVariable solver::operator*(ComplexVariable x, ComplexVariable y)//complexva * complexvb
{
    ComplexVariable temp(0,0,0);
    if (x.Ca != complex<double>(0.0,0.0) && y.Ca != complex<double>(0.0, 0.0))
    {
        throw invalid_argument("invalid power :: the power is too big");
    }

    if (x.Ca != complex<double>(0.0, 0.0) && y.Cb != complex<double>(0.0, 0.0))
    {
        throw invalid_argument("invalid power :: the power is too big");
    }

    if (x.Cb != complex<double>(0.0, 0.0) && y.Ca != complex<double>(0.0, 0.0))
    {
        throw invalid_argument("invalid power :: the power is too big");
    }

    temp.Ca = x.Ca * y.Cb + y.Ca * x.Cb + x.Cb * y.Cb;
    temp.Cb = x.Cb * y.Cb + y.Cb * x.Cb;
    temp.Cc = x.Cb * y.Cb;

    return temp;
}


// /
ComplexVariable solver::operator/(ComplexVariable x, complex<double> complexnumber)//double complex
{
    ComplexVariable temp(0,0,0);
    if (complexnumber == complex<double>(0, 0))
    {
        throw invalid_argument ("invalid division :: cannot divide by zero");
    }

    temp.Ca = x.Ca/complexnumber;
    temp.Cb = x.Cb/complexnumber;
    temp.Cc = x.Cc/complexnumber;

    return temp;
}

ComplexVariable solver::operator/(ComplexVariable x, ComplexVariable y) //complexva /complexvb
{
    ComplexVariable temp(0,0,0);
    if (y.Ca == complex<double>(0, 0) && y.Cb == complex<double>(0, 0) && y.Cc == complex<double>(0, 0)) {
        throw invalid_argument("invalid divison :: cannot divide by zero");
    }

    if (y.Ca == x.Ca && y.Cb == x.Cb && y.Cc == x.Cc) {
        temp.Ca = 0;
        temp.Cb = 0;
        temp.Cc = 1;
        return temp;
    }

    if (x.Ca == complex<double>(0, 0) && x.Cb == complex<double>(0, 0) && x.Cc == complex<double>(0, 0)) {
        temp.Ca = 0;
        temp.Cb = 0;
        temp.Cc = 1;
        return temp;
    }

    if (x.Ca == y.Ca && x.Cc == complex<double>(0, 0) && y.Cc == complex<double>(0, 0) &&
        y.Cb != complex<double>(0, 0)) {
        temp.Ca = 0;
        temp.Cb = x.Cb / y.Cb;
        temp.Cc = 0;
        return temp;
    }
    if (x.Cb == y.Cb && x.Cc == complex<double>(0, 0) && y.Cc == complex<double>(0, 0) &&
        y.Ca != complex<double>(0, 0)) {
        temp.Ca = x.Ca / y.Ca;
        temp.Cb = 0;
        temp.Cc = 0;
        return temp;
    }
    if (x.Cb == y.Cb && x.Ca == complex<double>(0, 0) && y.Ca == complex<double>(0, 0) &&
        y.Cc != complex<double>(0, 0)) {
        temp.Ca = 0;
        temp.Cb = 0;
        temp.Cc = x.Cc / y.Cc;
        return temp;
    }

    throw invalid_argument("no option to divid in this class");

}

//^
ComplexVariable solver::operator^(ComplexVariable x, double complexnumber)//complexv ^double complex
{
    ComplexVariable temp(0,0,0);

    if (complexnumber == 2)
    {
        temp.Ca=x.Ca+x.Cb*x.Cb;
        temp.Cb=0;
        temp.Cc=x.Cc;
        return temp;
    }

    if (complexnumber == 1)
    {
        return x;
    }

    if (complexnumber == 0)
    {
        temp.Ca = 0;
        temp.Cb = 0;
        temp.Cc = 1;
        return temp;
    }

    throw invalid_argument ("invalid power :: the power is not valid");

}

