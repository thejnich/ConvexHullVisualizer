#include "ConvexHullAlgs.h"

struct VectorPolar {
	Vector v;
	float angle;
	VectorPolar(Vector vec, Vector min) {
		v = vec;
		angle = Vector::getAngle(Vector(1.f,0.f,0.f,0.f), vec-min);	
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
		for(unsigned int i = 0; i < points->size(); ++i) {
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
	std::vector<VectorPolar> polars;
	for(std::vector<Vector>::iterator it = points->begin(); it!=points->end(); ++it) {
		if(!((*it)==(*min))) 
			polars.push_back(VectorPolar((*it), (*min)));
	}

	std::sort(polars.begin(), polars.end(), compareVectorPolar);
	
	convexHull->push_back(*min);
	convexHull->push_back(polars[0].v);
	convexHull->push_back(polars[1].v);

	for(unsigned int i = 2; i<polars.size(); ++i) {
		while(true) {
			// determine if angle between next-to-top(s), top(s) and pi makes left turn
			Vector a = convexHull->back() - convexHull->at(convexHull->size()-2); // top - next-to-top = vector from next-to-top to top
			Vector b = polars[i].v - convexHull->back(); // p_i-top = vector from top to p_i
			Vector normal = Vector::crossProduct(a,b); // a X b, cross product
			if(normal.z > 0) // left turn
				break;
			// non left turn
			convexHull->pop_back();
		}
		convexHull->push_back(polars[i].v); // push p_i
	}

	return true;
}

bool ConvexHullAlgs::JarvisMatch(std::vector<Vector> *convexHull, std::vector<Vector> *points)
{
	return false;
}


