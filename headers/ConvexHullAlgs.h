#ifndef _CONVEX_HULL_ALGS_H
#define _CONVEX_HULL_ALGS_H

#include "Vector.h"
#include <vector>
#include <algorithm>

class ConvexHullAlgs {

public:
   /* 
    * Find convex hull of points using Graham's Scan.
    * Return true on success, false on error.
   */
   static bool GrahamsScan(std::vector<Vector> *convexHull, std::vector<Vector> *points);

   /* 
    * Find convex hull of points using Jarvis' Match.
    * Return true on success, false on error
   */
   static bool JarvisMatch(std::vector<Vector> *convexHull, std::vector<Vector> *points);

private:

};

#endif /* _CONVEX_HULL_ALGS_H */
