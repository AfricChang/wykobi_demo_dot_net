#ifndef INCLUDE_WYKOBI_DEMO_MIN_BALL_HPP
#define INCLUDE_WYKOBI_DEMO_MIN_BALL_HPP


#include <vector>
#include <string>

#include "wykobi.hpp"
#include "wykobi_algorithm.hpp"
#include "wykobi_demo_types.hpp"


template<typename T, typename Graphic>
class minimum_bounding_ball : public task_interface<T,Graphic>
{
public:

   void operator()(const Graphic& graphic)
   {
      const std::size_t max_points = 1000;

      graphic.clear(clWhite);

      std::vector< wykobi::point2d<T> > point_list;
      point_list.reserve(max_points);

      wykobi::circle<T> base_circle =
                        wykobi::make_circle<T>
                                (
                                  T(graphic.width() / T(2)),
                                  T(graphic.height() / T(2)),
                                  std::min<T>(T((graphic.width () - T(15)) / T(2)),
                                              T((graphic.height() - T(15)) / T(2)))
                                );

      wykobi::generate_random_points
      (base_circle, max_points, std::back_inserter(point_list));

      wykobi::circle<T> minimum_bounding_ball;
      wykobi::algorithm::randomized_minimum_bounding_ball< wykobi::point2d<T> >
                         (point_list.begin(), point_list.end(), minimum_bounding_ball);

      graphic.draw(point_list.begin(),point_list.end());

      graphic.set_pen_width(3);
      graphic.set_color(clRed);

      graphic.draw(minimum_bounding_ball);
   }

   std::string name() { return "Minimum Bounding Ball"; }
};

#endif
