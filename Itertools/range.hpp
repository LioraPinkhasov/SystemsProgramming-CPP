//
// Created by LioraPinkhasov on 25/07/2020.
//

#ifndef ITERTOOLS_RANGE_HPP
#define ITERTOOLS_RANGE_HPP
#pragma once
#include <iostream>
#include <math.h>

//using name space to organize code into logical groups and to prevent name collisions.
namespace itertools
{
    /**this class is find the range between to points (start,finish)
       i use in this class inner class "iterator"
       that helps me to go over the range and do my methods.*/
    class range
     {
       //contains the index of the begining of the range.
       int Start;

       //contains the index of the ending of the range.
       int Finish;

       public:/**השימוש באיטרטור במיכלים הוא סוג של תנאי סף
 * זאת מהסיבה הפשוטה שכאשר אנו כותבים מיכל מסוים המכיל נתנונים
                * עלינו לדאוג לדרך שבאמצעותה נוכל לעשות עליו ביצועים
                * כמו למשל לשלוף את הנתונים המדוברים,
                * לעבור על הנתונים, להעתיק וכ"ו,
 * על כן אנו מגדירים איטרטור מסוים שיוכל לעבור על המיכל שלנו
 * בהתאם לתנאי המיכל
                */

              /**as shown up blow this iterator is our way to use the range container */
              class iterator
              {
               //this is the correct index, used next by the iterator for his operations.
               int index;

               public:
               //explicit

               //this is a constructor
               iterator(int c ): index(c){};
               //iterator(const iterator& other) = default;  /// see why its needed

               /**the add operator is increment the index
               and then return value of the iterator.*/
               iterator& operator++()
               {
                   index++;
                   return *this;
               };

               /**the add operation get int and returns a copy
                of the current iterator,
                after doing that it increment the index by adding 1;
                */
               iterator operator++(int)
               {
                   iterator temp = *this;
                   index++; return temp;
               };

               /**the equal operation is make a copy of the
                itertor.
                */
               iterator& operator=(const iterator& it)
               {
                 return *this;
               };

               //used as standard for loop iterators
                bool operator==(const iterator& it )const
                {
                    if(index == it.index)
                    {
                        return true;
                    }
                    return false;
                }

                /**used as standard for loop iterators ,becose we check if the begin index is
                diffrent from the end.
                in others words it is uses fore compere*/
                bool operator!=(const iterator& it )const
                {
                    if(index != it.index)
                    {
                        return true;
                    }
                    return false;
                }

                //uses for access to a value
                int operator *()const
                {
                return index;
                }

        };

        //this is used to handle the type of value in range that are not int.
        typedef int	value_type;

        /**this is the range constructor
         * it is gets 2 values and return the
         * values between the begin (include begin) to end (dont inclue the end value).
         * if the values of the begin and the end are equal it is return null range.
         להוסיף פונקציית בדיקה האם הטווח רייק*/
        range(int Begin , int End ): Start(Begin), Finish(End){}

        //define iterator begin
        iterator begin() const
        {
            return iterator(Start);
        }

        //define iterator end
        iterator end  () const
        {
            return iterator(Finish);
        }


    };
}
#endif //ITERTOOLS_RANGE_HPP
