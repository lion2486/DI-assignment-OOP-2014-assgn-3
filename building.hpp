#ifndef BUILDING_HPP_
#define BUILDING_HPP_
#define MAX_FLOORS 4
#include "List.h"
#include "floor.hpp"
#include "elevator.hpp"
#include "office.hpp"
#include "place.hpp"

class building : public place{
private:
	//List * visitors;
	floor * floors[MAX_FLOORS];
	elevator * lift;
//	int maxCapacity;
	int capacity;
	entrance * ent;		// this is the ground floor in order to enter the elevator
public:
	building(int N, int N_floor, int N_lift, int N_office, int N_ground);
	~building();

	/**
	 * Enters a new visitor int the building in order to get served
	 */
	bool enter(visitor * v);

	/**
	 * This method operates the elevator into the building
	 */
	void operate();

	inline int getCapacity() { return this->capacity; }
};

#endif /* BUILDING_HPP_ */
