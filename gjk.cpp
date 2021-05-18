#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>

/*
 * Initialization:

1. Pick an arbitrary starting direction.

2. Find a point in the Minkowski difference using the support function.

3. Add this point to a Simplex, a shape created using the minimum number of
   points in a given dimension. For example, a point in 0 dimensions, a
   line in 2, a triangle in 3, and a tetrahedron in 4.

   These shapes are easy to test for intersection, so we will find simplex
   subsets of the convex hull and perform the intersection tests on them.

Main Loop:

4. Choose a new direction from the simplex towards the origin.

5. Get a point with the support function using the direction.

6. If the point didn't pass the origin, then the origin must be outside the
   convex hull. Terminate and return false.

7. Add the new point to the simplex.

8. Test to see if the origin intersects the simplex.

   If it does, keep the entire simplex.

   If it does not, reduce to the closest, largest simplex that surrounds
   the origin when it is mapped onto the simplex's dimension.

9. If we found a simplex of the maximum dimension that surrounds the origin,
   terminate and return true. Otherwise, return to step 4.
 */
const double pi = std::acos(-1);

float to_rad(int deg){
   return deg*pi/180 ; 
}

float mag(std::array<float, 2> point){
   return std::sqrt( std::pow(point[0], 2) + std::pow(point[1], 2) );
}

float dot(std::array<float, 2> X, std::array<float, 2> Y){
   return X[0]*Y[0] + X[1]*Y[1];
}

bool gjk_algo(std::vector<std::array<float, 2>> shape1, std::vector<std::array<float, 2>> shape2){

   std::array<float, 2> support_vector = {0.0f, 0.0f};
   std::array<float, 2> p1, p2;
   std::vector<float> temp ;

   p1 = shape1[0];
   support_vector = {p1[0]/mag(p1), p1[1]/mag(p1)};

   for(auto itr = shape2.begin(); itr != shape2.end(); ++ itr){
      temp.push_back(dot(*itr, support_vector));
   } 

   return true; 
}

