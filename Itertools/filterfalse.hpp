//
// Created by LioraPinkhasov on 25/07/2020.
//

#ifndef ITERTOOLS_FILTERFALSE_HPP
#define ITERTOOLS_FILTERFALSE_HPP
#pragma once
#include <iostream>
#include <vector>
namespace itertools
{
    //define a template
    template <typename T , typename Container>

    /**this is the filer false class
     *i used in this class and inner class - itrerator
     need iterator to do thing over the container
     the filterfalse fun in the class gets two parmeters
     the first is boolean functor wich represnt condition
     and the second is the container
     the func returns new container witch contains
     only the uncondionable values
     (like if the condion is return the even
     the container will contain the odds).
     */
    class filterfalse
    {
        //
        T iterable;

        //contains the values in the cont
        Container& cont;

        //define
        typedef typename Container::value_type value_type;

         public:
                 //write in a diffrent way
                 filterfalse(T function , Container& container): iterable(function), cont(container){}
                 filterfalse(T function, Container&& container): iterable(function), cont(container){}



                 /**this is the itertaor classs
                  * used to do operations on the container
                  */
                 class iterator
                 {
                  typename Container::iterator  Begin;
                  typename Container::iterator  End;
                  T function1;

                  public:
                     //explicit
                   iterator(typename Container::iterator begin, typename Container::iterator end, T function): Begin(begin), End(end), function1(function)
                   {
                   while(Begin != End && function(*Begin))
                    Begin++;
                   }

                  //used for making a copy
                  iterator& operator=(const iterator &dif)
                  {
                   if(this != &dif)
                   {
                    this->Begin  = dif.Begin;
                    this->End    = dif.End;
                    this->function1    = dif.function1;
                   }
                  return *this;
                 };

                  //first increment then return value. ++i
                  iterator& operator++()
                  {
                   Begin++;
                   while(Begin != End && function1(*Begin))
                   {
                       Begin++;
                   }
                   return *this;
                   };


                   iterator operator++(int)
                   {
                   iterator temp = *this;
                   (*this)++;
                   return temp;
                   };

                     //used for comparision
                    bool operator==(const iterator& other )
                    {
                        if(Begin == other.Begin)
                        {
                            return true;
                        }
                        return false;

                    }

                    //used for comparision
                    bool operator!=(const iterator& other )
                    {
                        if(Begin != other.Begin)
                        {
                            return true;
                        }
                        return false;
                    }

                    //uses for access to a value
                    auto operator *()
                    {
                        if(function1(*Begin)) {
                            ++(*this);
                        }
                        return *Begin;
                     }
                 };

        iterator begin() const
        {
            return iterator(cont.begin(), cont.end(), iterable);
        }

        iterator end()   const
        {
            return iterator(cont.end(), cont.end(), iterable);
        }

    };


}


#endif //ITERTOOLS_FILTERFALSE_HPP
