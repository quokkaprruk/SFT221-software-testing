#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "Test.h"
#include "mapping.h"

double returnDistance(const int loc1[2], const int loc2[2], double* minDest)
{
	if (loc1 == NULL || loc2 == NULL || minDest == NULL) {
		return -1; // Return the error code for null pointers
	}
	double calcValue = sqrt(pow((loc1[0] - loc2[0]), 2) + pow((loc1[1] - loc2[1]), 2));

	if (calcValue < *minDest)
	{
		*minDest = calcValue;
	}

	return calcValue;
}
int checkEmpty(const double weight, double weightLeft, int volumeLeft)
{
	int i = 0;

	if (weight <= weightLeft && weight > 0 && volumeLeft > 0)
	{
		i = 1;
	}

	return i;
}
int checkSize(const double size)
{
	int i = 0;

	if (size == QUARTER_SIZE || size == HALF_SIZE || size == FULL_SIZE)
	{
		i = 1;
	}

	return i;
}

/*int validDestination(const int row, const char column)*/
int validDestination(const int row, const char* column)
{
	int i = 0; // 0 == false

	if (column != NULL) {

		if (row > 0 && row < 26)
		{
			// Convert the column to uppercase
			char upperColumn = toupper(column[0]); // Use column[0] to access the first character

			if (upperColumn >= 'A' && upperColumn <= 'Y')
			{
				i = 1; // 1 == true
			}
		}

	}
	return i;
}

/*struct Shipment run(struct Shipment empty) {
	double weight = -1;
	double size = -1;
	int row = -1;
	char column = '&';

	while (weight != 0 || size != 0 || column != 'x') {
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		if (scanf("%lf %lf %d%c", &weight, &size, &row, &column) == 4) {
			if (weight < 1 || weight > 1000) printf("Invalid weight (must be 1-1000 Kg.)\n");
			else if (!validDestination(row, &column)) printf("Invalid destination\n");
			else if (!checkSize(size)) printf("Invalid size\n");
		}
		else scanf("%c", &column);
	}

	empty.weight = weight;
	empty.box = size;
	empty.row = row;
	empty.column = column;

	return empty;
}*/

void printShippingDetails(double weight, double size, char row, char column, struct Route route) {
	printf("Ship on %s LINE, ", route.routeSymbol == BLUE ? "BLUE" : "GREEN");
	if (route.numPoints == 0) {
		printf("no diversion\n");
	}
	else {
		printf("divert: ");
		for (int i = 0; i < route.numPoints; i++) {
			printf("%c%d", route.points[i].col + 'A', route.points[i].row);
			if (i < route.numPoints - 1) {
				printf(", ");
			}
		}
		printf("\n");
	}
}

//void testCoordinateDistance()
//{
//	int loc1[2] = { 0, 0 };
//	int loc2[2] = { 3, 4 };
//	double minDest = 999999.9;
//
//	printf("Distance between (0, 0) and (3, 4): %.2f\n", coordinateDistance(loc1, loc2));
//
//
//	double result = coordinateDistance(NULL, loc2);
//	if (result == -1)
//	{
//		printf("Test case with NULL pointer passed.\n");
//	}
//	else
//	{
//		printf("Test case with NULL pointer failed.\n");
//	}
//
//
//	int loc3[2] = { 0, 1 };
//	int loc4[2] = { 0, 0 };
//	result = coordinateDistance(loc3, loc4);
//	if (result == 1)
//	{
//		printf("Test case with minimum distance passed.\n");
//	}
//	else
//	{
//		printf("Test case with minimum distance failed.\n");
//	}
//
//
//	int loc5[2] = { 100, 200 };
//	int loc6[2] = { 300, 500 };
//	result = coordinateDistance(loc5, loc6);
//	if (result == 447.21)
//	{
//		printf("Test case with maximum distance passed.\n");
//	}
//	else
//	{
//		printf("Test case with maximum distance failed.\n");
//	}
//}

int canAssignShipment(const struct TruckTest* trucks, int numTrucks, double weight, double size) {
	for (int i = 0; i < numTrucks; i++) {
		if (trucks[i].weightLeft + weight <= MAX_WEIGHT &&
			trucks[i].volumeLeft + size <= MAX_VOLUME) {
			return i; // Return the index of the truck that can accommodate the shipment
		}
	}
	return -1;
}

void flushKey(void) {
	char ch = 'x';
	while (ch != '\n') {
		ch = getchar();
	}
}