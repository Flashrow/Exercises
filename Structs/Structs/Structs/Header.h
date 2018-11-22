#pragma once
#include <vector>

/** Struct representing point in three-dimensional space*/
struct myPoint;

/** Function returns the distance between two myPoint structs
	@param a first of points
	@param b second of points
	@return distance between points */
double myPointDistance(const myPoint & a, const myPoint & b);

/** Function returns vector of N random points
@param N amount of points to generate
@return vector of N points */
std::vector<myPoint> generatePoints(const int N);