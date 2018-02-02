#ifndef ROOM_HPP_
#define ROOM_HPP_
#include "place.hpp"
#include "List.h"

class room : public place{
protected:
	List * visitors;

public:
	room(int cap)
	:place(cap){

		this->visitors = new List();
	}

	virtual ~room(){
		this->visitors->Remove_All_Items();

		delete this->visitors;
	}

	/* Pure virtual, not implemented yet */
//	virtual bool enter(visitor * v) = 0;

	/* Get the room's Current Capacity */
	inline int getCapacity(){	return this->visitors->Get_List_Size(); }


};

#endif /* ROOM_HPP_ */
