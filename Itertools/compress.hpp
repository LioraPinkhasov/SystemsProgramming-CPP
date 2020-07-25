//
// Created by LioraPinkhasov on 25/07/2020.
//

#ifndef ITERTOOLS_COMPRESS_HPP
#define ITERTOOLS_COMPRESS_HPP
#pragma once



namespace itertools
{

    template<typename CA, typename CB>
    class compress
     {

        CA &containerA;
        CB &ContainerB;
        typedef typename CA::value_type value_type;

    public:
       compress(CA &&container1, CB &container_b) : containerA(container1), ContainerB(container_b) {}

        class iterator
         {
            typename CA::iterator Cbegin;
            typename CA::iterator Cend;
            typename CB::iterator Bbegin;
            typename CB::iterator Bend;

             public:
                // explicit
                 iterator(typename CA::iterator begin, typename CA::iterator end, typename CB::iterator BBgin) : Cbegin(begin), Cend(end), Bbegin(BBgin)
                 {
                    while (Cbegin != Cend && !(*Bbegin))
                    {
                        Cbegin++;
                        Bbegin++;
                    }

                  };

                  iterator(const iterator& temp) = default;

                   //used for making a copy
                  iterator &operator=(const iterator &dif)
                  {
                      if (this != &dif)
                      {
                      this->Cbegin = dif.Cbegin;
                      this->Cend  = dif.Cend;
                      this->Bbegin = dif.Bbegin;
                      this->Bend = dif.Bend;
                      }
                  return *this;
                  };



                 iterator &operator++()
                 {
                    Cbegin++;
                    Bbegin++;
                    while (Cbegin != Cend && !(*Bbegin))
                     {
                       ++Cbegin;
                       ++Bbegin;
                     }
                    return *this;
                  };


                 iterator operator++(int)
                 {
                 iterator temp = *this;
                 ++(*this);
                 return temp;
                 };

                //used for comparision
                bool operator==(const iterator &other)
                {
                return Cbegin == other.Cbegin;
                }

                //used for comparision
                bool operator!=(const iterator &other)
                {
                return Cbegin != other.Cbegin;
                }

                //uses for access to a value
                auto operator*()
                {
                return *Cbegin;
               }
         };

        iterator begin() const
        {
            return iterator(containerA.begin(), containerA.end(), ContainerB.begin());
        }

        iterator end() const
        {
            return iterator(containerA.end(), containerA.end(), ContainerB.end());
        }

    };
}
#endif //ITERTOOLS_COMPRESS_HPP
