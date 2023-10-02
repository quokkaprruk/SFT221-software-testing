#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "Test.h"

void printDiversions(struct Route* route) {
	if (route->numPoints == 0) {
		printf("no diversion");
	}
	else {
		for (int i = 0; i < route->numPoints; i++) {
			if (i == 0) {
				printf("divert: ");
			}
			if (i == route->numPoints - 1)
				printf("%d%c", route->points[i].row + 1, route->points[i].col + 65);
			else
				printf("%d%c, ", route->points[i].row + 1, route->points[i].col + 65);
		}
	}

	printf("\n");
}

void run() {
	double weight = -1;
	double size = -1;
	int row = -1;
	char column = NULL;

	struct Map map = populateMap();

	//creating the routes
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	map = addRoute(&map, &blueRoute);
	map = addRoute(&map, &greenRoute);
	map = addRoute(&map, &yellowRoute);

	int blueRouteWeightLeft = 1000;
	int blueRouteSizeLeft = 36;
	int greenRouteWeightLeft = 1000;
	int greenRouteSizeLeft = 36;
	int yellowRouteWeightLeft = 1000;
	int yellowRouteSizeLeft = 36;

	while (weight != 0 || size != 0 || column != 'x') {
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		if (scanf("%lf %lf %d%c", &weight, &size, &row, &column) == 4) {
			if (weight < 1 || weight > MAX_WEIGHT) printf("Invalid weight (must be 1-1000 Kg.)\n");
			else if (!validDestination(row, &column)) printf("Invalid destination\n");
			else if (!checkSize(size)) printf("Invalid size\n");
			else {
				struct Point destination = { row - 1, column - 65 };

				//getting the closest points of the routes to the destinaion
				/*
				int blueClosestPoint = getClosestPoint(&blueRoute, destination);
				int greenClosestPoint = getClosestPoint(&greenRoute, destination);
				int yellowClosestPoint = getClosestPoint(&yellowRoute, destination);
				*/
				int blueClosestPoint = getClosestPoint(&blueRoute, destination, &map);
				int greenClosestPoint = getClosestPoint(&greenRoute, destination, &map);
				int yellowClosestPoint = getClosestPoint(&yellowRoute, destination, &map);

				//calculating the distance between the route's closest points and destinaion
				double blueDistance = distance(&blueRoute.points[blueClosestPoint], &destination);
				double greenDistance = distance(&greenRoute.points[greenClosestPoint], &destination);
				double yellowDistance = distance(&yellowRoute.points[yellowClosestPoint], &destination);

				if (blueDistance <= greenDistance && blueDistance <= yellowDistance) {
					if (blueRouteWeightLeft >= weight && blueRouteSizeLeft > 0) {
						// Ship using blue truck
						printf("Ship on BLUE LINE, ");
						struct Route route = shortestPath(&map, blueRoute.points[blueClosestPoint], destination);
						printDiversions(&route);
						//addPtToRoute(&blueRoute, destination);
						blueRouteWeightLeft -= weight;
						blueRouteSizeLeft -= size;
					}
					else if (greenDistance <= yellowDistance && greenRouteWeightLeft >= weight && greenRouteSizeLeft > 0) {
						// Ship using green truck 
						printf("Ship on GREEN LINE, ");
						struct Route route = shortestPath(&map, greenRoute.points[greenClosestPoint], destination);
						printDiversions(&route);
						//addPtToRoute(&greenRoute, destination);
						greenRouteWeightLeft -= weight;
						greenRouteSizeLeft -= size;
					}
					else if (yellowRouteWeightLeft >= weight && yellowRouteSizeLeft > 0) {
						// Ship using yellow truck
						printf("Ship on YELLOW LINE, ");
						struct Route route = shortestPath(&map, yellowRoute.points[yellowClosestPoint], destination);
						printDiversions(&route);
						//addPtToRoute(&yellowRoute, destination);
						yellowRouteWeightLeft -= weight;
						yellowRouteSizeLeft -= size;
					}
					else {
						printf("All trucks are not available\n");
					}
				}
				else if (greenDistance <= blueDistance && greenDistance <= yellowDistance) {
					if (greenRouteWeightLeft >= weight && greenRouteSizeLeft > 0) {
						// Ship using green truck
						printf("Ship on GREEN LINE, ");
						//struct Route route = shortestPath(&map, greenRoute.points[greenClosestPoint], destination);
						struct Route route = shortestPath(&map, getGreenRoute().points[greenClosestPoint], destination);

						printDiversions(&route);
						//addPtToRoute(&greenRoute, destination);
						greenRouteWeightLeft -= weight;
						greenRouteSizeLeft -= size;
					}
					else if (blueDistance <= yellowDistance && blueRouteWeightLeft >= weight && blueRouteSizeLeft > 0) {
						//struct Route route = shortestPath(&map, greenRoute, destination )
						// Ship using blue truck 
						printf("Ship on BLUE LINE, ");
						//blueRoute.numPoints = 0;
						//struct Route route = shortestPath(&map, blueRoute.points[blueClosestPoint], destination);
						struct Route route = shortestPath(&map, getBlueRoute().points[blueClosestPoint], destination);
						printDiversions(&route);
						//addPtToRoute(&blueRoute, destination);
						blueRouteWeightLeft -= weight;
						blueRouteSizeLeft -= size;
					}
					else if (yellowRouteWeightLeft >= weight && yellowRouteSizeLeft > 0) {
						// Ship using yellow truck
						printf("Ship on YELLOW LINE, ");
						struct Route route = shortestPath(&map, yellowRoute.points[yellowClosestPoint], destination);
						printDiversions(&route);
						//addPtToRoute(&yellowRoute, destination);
						yellowRouteWeightLeft -= weight;
						yellowRouteSizeLeft -= size;
					}
					else {
						printf("All trucks are not available\n");
					}
				}
				else if (yellowRouteWeightLeft >= weight && yellowRouteSizeLeft > 0) {
					// Ship using yellow truck
					printf("Ship on YELLOW LINE, ");
					struct Route route = shortestPath(&map, yellowRoute.points[yellowClosestPoint], destination);
					printDiversions(&route);
					//addPtToRoute(&yellowRoute, destination);
					yellowRouteWeightLeft -= weight;
					yellowRouteSizeLeft -= size;
				}
				else if (greenDistance <= blueDistance && greenRouteWeightLeft >= weight && greenRouteSizeLeft > 0) {
					// Ship using green truck 
					printf("Ship on GREEN LINE, ");
					struct Route route = shortestPath(&map, greenRoute.points[greenClosestPoint], destination);
					printDiversions(&route);
					//addPtToRoute(&greenRoute, destination);
					greenRouteWeightLeft -= weight;
					greenRouteSizeLeft -= size;
				}
				else if (blueRouteWeightLeft >= weight && blueRouteSizeLeft > 0) {
					// Ship using blue truck
					printf("Ship on BLUE LINE, ");
					struct Route route = shortestPath(&map, blueRoute.points[blueClosestPoint], destination);
					printDiversions(&route);
					//addPtToRoute(&blueRoute, destination);
					blueRouteWeightLeft -= weight;
					blueRouteSizeLeft -= size;
				}
				else {
					printf("All trucks are not available\n");
				}
			}
		}
		else scanf("%c", &column);
	}

	printf("Thanks for shipping with Seneca!");
}

int main(void)
{
	/*struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	routeMap = addRoute(&routeMap, &greenRoute);
	routeMap = addRoute(&routeMap, &yellowRoute);

	printMap(&routeMap, 1, 1);

	struct Shipment localShip = { 0.0, 0.0, 0, '&' };

	localShip = run(localShip);*/

	run();

	return 0;
}