#ifndef _CONVEX_HULL_ALGS_H
#define _CONVEX_HULL_ALGS_H

#include "Vector.h"
#include <vector>
#include <algorithm>

class ConvexHullAlgs {

public:
	/* find convex hull of points using Graham's Scan,
	 * return true on success, false on error
	 */
	static bool GrahamsScan(std::vector<Vector> *convexHull, std::vector<Vector> *points);
	
	/* find convex hull of points using Jarvis' Match,
	 * return true on success, false on error
	 */
	static bool JarvisMatch(std::vector<Vector> *convexHull, std::vector<Vector> *points);

private:
	

};

#endif /* _CONVEX_HULL_ALGS_H */
