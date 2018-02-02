#ifndef ELEVATOR_HPP_
#define ELEVATOR_HPP_
#include "List.h"
#include "visitor.hpp"
#include "room.hpp"

class elevator : public room{
private:
//	List * visitors;
	int floor;
//	int maxCapacity;
public:

	/**
	 * Constructor, creates an elevator with capacity N
	 */
	elevator(int N);

	/*
	 * Destroys an elevator object
	 */
	~elevator();

	/*
	 * Enter a visitor into the elavtor
	 *
	 * @return true if capacity not reached, otherwise false.
	 */
	bool enter(visitor * v);

	/*
	 * increase the current floor of the elevator (0 for ground flour)
	 */
	inline int stop_up()	{ return ++this->floor; }

	/*
	 * decreases the current floor of the elevator (0 for ground flour)
	 */
	inline int stop_down()	{ return --this->floor; }

	/*
	 * pops out a visitor from the elevator in order to visit the floor
	 * if there is no more visitors for the current floor NULL is returned
	 */
	visitor * exit();

	/**
	 * exits all the visitors from the elevator that have done their work
	 */
	void empty_all();
};

#endif /* ELEVATOR_HPP_ */
