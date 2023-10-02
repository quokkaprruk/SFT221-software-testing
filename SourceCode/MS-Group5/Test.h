#ifndef TEST_H
#define TEST_H

#define MAX_WEIGHT 1000
#define MAX_VOLUME 36
#define QUARTER_SIZE 0.25
#define HALF_SIZE 0.5
#define FULL_SIZE 1.0

struct RouteTest {
	double minDestination;
	char* bestRoute;
};

struct TruckTest {
	int volumeLeft; ////will be set to 36 at first
	double weightLeft; //will be set to 1000 at first
};

struct Shipment {
	double weight;
	double box; // 1/4 or 1/2 or 1 cubic meter
	int row; // 1 to 25
	char column; // A to Y
};

/*
* Returns the distance between two locations
* @param loc1 - location 1
* @param loc2 - location 2
* @param minDest - current min destination value
* @returns - the distance of 2 destination in double
*/
double returnDistance(const int loc1[2], const int loc[2], double* minDest);

/*
* Determine whether the given weight is
less than or equal to weightLeft, while also checking if volumeLeft is
greater than zero.
* @param weight - location 1
* @param weightLeft - location 2
* @param volumeLeft - current min destination value
* @returns - if both conditions were met, return 1. Otherwise, return 0.
*/
int checkEmpty(const double weight, double weightLeft, int volumeLeft);


/*
* Determine whether the box size is valid or not
* @param size - user's input box size
* @returns - return 1 if box size is equal to 1/4, 1/2, or 1. Otherwise, return 0.
*/
int checkSize(const double size);

/*
* Determine whether the destination  is valid or not
* @param row
* @param column
* @returns - return 1 if the destination is valid. Otherwise, return 0.
*/
int validDestination(const int row, const char* column);

/**
* Gets the shipment weight, box size, and destination from the user.
* @returns - void
*/
//struct Shipment run(struct Shipment empty);

/*
* Prints shipping details for package.
* @param weight - the weight of the package
* @param size - the size of te package
* @param row -
* @param column -
* @param route -
* @returns - true if p1 is equal to p2
*/
void printShippingDetails(double weight, double size, char row, char column, struct Route route);

//void testCoordinateDistance();

int canAssignShipment(const struct TruckTest* trucks, int numTrucks, double weight, double size);

void flushKey(void);


#endif // !TEST_H






