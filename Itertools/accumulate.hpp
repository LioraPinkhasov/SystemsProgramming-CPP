//
// Created by LioraPinkhasov on 25/07/2020.
//

#ifndef ITERTOOLS_ACCUMULATE_HPP
#define ITERTOOLS_ACCUMULATE_HPP
namespace itertools
{
    /**
     * function adds two types of values.
     */
    typedef struct
    {
    public:
        template <typename Kplus>
        Kplus operator() (Kplus p1 ,Kplus p2) const
        {
            return p1+p2;
        } //default set to adds two template values.
    } Plus;

    template <typename C, typename F = Plus>

    class accumulate
    {
        C& container;
        F&  function;

        typedef typename C::value_type value_type;

        public:
        //explicit
        accumulate(C& cont , F func = Plus()): container(cont), function(func){}
        //explicit
        accumulate(C&& cont, F func = Plus()): container(cont), function(func){}

        class iterator
         {
            typename C::iterator   BeginItrator;
            typename C::iterator   EndItrator;
            typename C::value_type info;
            F function;

            public:
           // explicit
                    iterator(typename C::iterator begiter, typename C::iterator enditer, F function): BeginItrator(begiter), EndItrator(enditer), function(function)
                    {
                      if(begiter != enditer)
                      {
                       info = *begiter;

                      }
                    };


                   iterator& operator++()
                   {
                   BeginItrator++;
                   if(BeginItrator != EndItrator)
                     {
                         info = function(info, *BeginItrator);
                     }
                   return *this;
                   };


                   iterator operator++(int)
                   {
                       iterator temp = *this;
                       (*this)++;
                       return temp;
                   };

                   //used for making a copy
                  iterator& operator=(const iterator &other)
                  {
                    if(this != &other)
                     {
                       this->info = other.info;
                       this->BeginItrator = other.BeginItrator;
                       this->EndItrator = other.EndItrator;
                       this->function = other.function;
                     }
                    return *this;
                   }

                   //used for comparision
                   bool operator==(const iterator& temp )const
                   {
                       if(BeginItrator == temp.BeginItrator)
                       {
                           return true;
                       }
                       return false;
                   }

                   //used for comparision
                   bool operator!=(const iterator& temp )const
                   {
                       if(BeginItrator != temp.BeginItrator)
                       {
                           return true;
                       }
                       return false;
                   }

                   //uses for access to a value
                   auto operator *()
                   {
                       return info;
                   }


         };

        iterator begin() const
        {
            return iterator(container.begin(), container.end(), function);
        }


        iterator end()   const
        {
            return iterator(container.end(), container.end(), function);
        }
    };
}
#endif //ITERTOOLS_ACCUMULATE_HPP
