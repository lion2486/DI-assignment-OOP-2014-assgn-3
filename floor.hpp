#ifndef FLOOR_HPP_
#define FLOOR_HPP_
#define MAX_OFFICES 10
#include "List.h"
#include "visitor.hpp"
#include "office.hpp"
#include "entrance.hpp"
#include "place.hpp"
#include "supportPlace.hpp"


class floor : public place, public supportPlace{
private:
//	int maxCapacity;
	int floor_num;
	office * offices[MAX_OFFICES];
	entrance * ent;
public:
	floor(int cap, int f, int N_office);
	~floor();

	inline int getCapacity()	{ return this->ent->getCapacity(); }
//	inline int getMaxCapacity()	{ return this->maxCapacity; }

	/**
	 * the method to enter a visitor into a floor
	 */
	bool enter(visitor * v);

	/**
	 * returns an available visitor to get off the building
	 */
	visitor * exit();

	/**
	 * Return a list pointer starting at a random visitor.
	 *
	 * NOTE: Read only, do not change the pointer's content of the list!
	 */
	inline List * getRandomVisitor(){ return this->ent->getRandom(); }

	void checkVisitorStatus();

	void influenceOffices();
};

#endif /* FLOOR_HPP_ */
