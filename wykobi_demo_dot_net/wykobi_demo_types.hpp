#ifndef INCLUDE_WYKOBI_DEMO_TYPES_HPP
#define INCLUDE_WYKOBI_DEMO_TYPES_HPP


#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"

const static unsigned int clAqua      =  0;
const static unsigned int clBlack     =  1;
const static unsigned int clBlue      =  2;
const static unsigned int clBrown     =  3;
const static unsigned int clCyan      =  4;
const static unsigned int clGray      =  5;
const static unsigned int clGreen     =  6;
const static unsigned int clIndigo    =  7;
const static unsigned int clLimeGreen =  8;
const static unsigned int clMagenta   =  9;
const static unsigned int clOrange    = 10;
const static unsigned int clPurple    = 11;
const static unsigned int clRed       = 12;
const static unsigned int clViolet    = 13;
const static unsigned int clWhite     = 14;
const static unsigned int clYellow    = 15;


template<typename T, typename Graphic>
class task_interface
{
public:

   virtual void operator()(const Graphic& graphic) = 0;
   virtual std::string name() = 0;
};

template<typename T, typename Graphic>
class null_demo : public task_interface<T,Graphic>
{
public:

   virtual void operator()(const Graphic& graphic) {};

   virtual std::string name ()
   {
      return "N/A";
   };
};

#endif
