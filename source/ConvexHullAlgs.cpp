#include "ConvexHullAlgs.h"

struct VectorPolar {
	Vector v;
	float angle;
	VectorPolar(Vector vec, Vector ref) {
		v = vec;
		angle = Vector::getAngle(ref, vec);	
	}
};

bool compareVectorPolar(VectorPolar a, VectorPolar b)
{
	return (a.angle < b.angle);
}

bool ConvexHullAlgs::GrahamsScan(std::vector<Vector> *convexHull, std::vector<Vector> *points)
{
	if( NULL == convexHull || NULL == points )
		return false;

	convexHull->clear();

	if( points->size() <= 3 ) {
		//copy points into convexHull
		for(int i = 0; i < points->size(); ++i) {
			convexHull->push_back((*points)[i]);
		}
	
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

	// sort points based on polar angle relative to min
	Vector temp = Vector(min->x + 1, min->y, min->z, 1.f);
	Vector ref = temp - *min;

	std::vector<VectorPolar> polars;
	for(std::vector<Vector>::iterator it = points->begin(); it!=points->end(); ++it) {
		if(!((*it)==(*min))) {
			polars.push_back(VectorPolar((*it), ref));
		}
	}

	std::sort(polars.begin(), polars.end(), compareVectorPolar);
	for(std::vector<VectorPolar>::iterator it = polars.begin(); it!=polars.end(); ++it) {
		printf("%f\n", it->angle);
	}

	convexHull->push_back(*min);
	convexHull->push_back(polars[0].v);
	convexHull->push_back(polars[1].v);

	for(int i = 2; i<polars.size(); ++i) {
		while(true) {
			// determine if angle between next-to-top(s), top(s) and pi makes left turn
			Vector a = convexHull->back() - *(&(convexHull->back())-1); // top - next-to-top = vector from next-to-top to top
			Vector b = polars[i].v - convexHull->back(); // pi-top = vector from top to pi
			Vector normal = Vector::crossProduct(a,b); // a X b, cross product
			if(normal.z > 0) // left turn
				break;
			// non left turn
			convexHull->pop_back();
		}
		convexHull->push_back(polars[i].v); // push pi
	}

	return true;
}

bool ConvexHullAlgs::JarvisMatch(std::vector<Vector> *convexHull, std::vector<Vector> *points)
{
	return false;
}


