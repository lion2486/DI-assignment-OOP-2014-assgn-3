#ifndef ENTRANCE_HPP_
#define ENTRANCE_HPP_
#include "visitor.hpp"
#include "List.h"
#include "room.hpp"

class entrance : public room{
private:
//	List * visitors;
//	int maxCapacity;
public:
	entrance(int cap);

	~entrance();

	/**
	 * enters a visitor into the floor (or ground) entrance space
	 */
	bool enter(visitor * v);

	/**
	 * gets the visitor with the min priority num
	 */
	inline visitor * exit()	{ return this->exit(-1); }

	/**
	 * gets the visitor with the min priority num for the target office
	 */
	visitor * exit(int office);

	/**
	 * Return a list pointer starting at a random visitor.
	 *
	 * NOTE: Read only, do not change the pointer's content of the list!
	 */
	List * getRandom();

	/**
	 * Calculates the total Anger & patient of all visitors and assign it to the pointers given
	 */
	void calculateVisitorStatus(int * angerSum, int * patientSum);

};

#endif /* ENTRANCE_HPP_ */
