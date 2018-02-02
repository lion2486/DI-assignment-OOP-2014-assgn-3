#ifndef PLACE_HPP_
#define PLACE_HPP_

class place{
protected:
	int maxCapacity;
public:
	place(int cap)
	:maxCapacity(cap){

	}

	virtual ~place(){}

	/* Pure virtual */
	virtual bool enter(visitor * v) = 0;

	virtual int getCapacity() = 0;

	/* Get the room's max Capacity */
	inline int getMaxCapacity(){	return this->maxCapacity; }
};

#endif /* PLACE_HPP_ */
