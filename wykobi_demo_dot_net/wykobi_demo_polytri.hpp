#ifndef INCLUDE_WYKOBI_DEMO_POLYTRI_HPP
#define INCLUDE_WYKOBI_DEMO_POLYTRI_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"
#include "wykobi_demo_utils.hpp"


template<typename T>
wykobi::triangle<T,2> shrink_down(const T& amount, const wykobi::triangle<T,2>& triangle)
{
   wykobi::triangle<T,2> _triangle = triangle;

   wykobi::point2d<T> original_center = wykobi::centroid(_triangle);

   _triangle = wykobi::center_at_location<T>
               (
                 wykobi::scale(amount, amount,wykobi::center_at_location<T>(_triangle, T(0), T(0))),
                 original_center
               );

   return _triangle;
}


template<typename T, typename Graphic>
class polygon_triangulation : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      graphic.clear(clWhite);

      std::vector<wykobi::point2d<T> > point_list;

      wykobi::polygon<T,2> polygon;

      generate_polygon_type2<T>(graphic.width() - T(1), graphic.height() - T(1), polygon);

      graphic.set_color(clBlue);
      graphic.set_pen_width(2);
      graphic.draw(polygon);

      std::vector< wykobi::triangle<T,2> > triangle_list;

      wykobi::algorithm::polygon_triangulate< wykobi::point2d<T> >
                         (polygon, std::back_inserter(triangle_list));

      graphic.set_pen_width(1);
      graphic.set_color(clRed);

      for (std::size_t i = 0; i < triangle_list.size(); ++i)
      {
         graphic.draw(shrink_down(0.97,triangle_list[i]));
      }
   }

   std::string name() { return "Simple Polygon Ear Clipping"; }
};

#endif
