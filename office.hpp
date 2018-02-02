#ifndef OFFICE_HPP_
#define OFFICE_HPP_
#include "List.h"
#include "room.hpp"
#include "supportPlace.hpp"

class office : public room, public supportPlace{
private:
//	List * visitors;
	int index;
//	int maxCapacity;
public:

	office(int i, int N_office);
	~office();

//	inline int getCapacity()	{ return this->visitors->Get_List_Size(); }
//	inline int getMaxCapacity()	{ return this->maxCapacity; }

	/**
	 * enters a visitor into the office
	 */
	bool enter(visitor * v);

	/**
	 * get an visitor from the office to get off the building
	 */
	visitor * exit();

	/**
	 * Return a list pointer starting at a random visitor.
	 *
	 * NOTE: Read only, do not change the pointer's content of the list!
	 */
	List * getRandomVisitor();

	/**
	 * Calculates the total Anger & patient of all visitors and assign it to the pointers given
	 */
	void calculateVisitorStatus(int * angerSum, int * patientSum);
};

#endif /* OFFICE_HPP_ */
