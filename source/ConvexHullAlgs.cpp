#include "ConvexHullAlgs.h"

bool ConvexHullAlgs::GrahamsScan(std::vector<Vector> *convexHull, std::vector<Vector> *points)
{
	if( NULL == convexHull || NULL == points )
		return false;

	convexHull->clear();

	if( points->size() <= 3 ) {
		convexHull->resize(points->size());
		//copy points into convexHull
		std::copy(points->begin(), points->end(), convexHull->begin());
		return true;
	}

	// find point with min y value, leftmost breaks ties
	Vector *min = &(*points)[0];
	for(std::vector<Vector>::iterator it = points->begin()+1; it != points->end(); ++it) {
		if(it->y < min->y)
			min = &(*it);
		else if(it->y == min->y && it->x < min->x)
			min = &(*it);
	}
	convexHull->resize(2);
//	std::copy(min, min+1, convexHull);
//	(*convexHull)[1] = Vector(0.f, 0.f, 0.f, 1.f);

	return true;
}

bool ConvexHullAlgs::JarvisMatch(std::vector<Vector> *convexHull, std::vector<Vector> *points)
{
	return false;
}


