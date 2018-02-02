#ifndef VISITOR_HPP_
#define VISITOR_HPP_
#include <iostream>

#define ANGER_LIMIT 25
#define PATIENT_LIMIT 25

class visitor{
private:
	int id;
	int targetFloor;
	int targetOffice;
protected:
	int anger_level;
	int patient_level;
public:
	visitor(int ID, int floor, int office, int anger, int patient)
	:id(ID), targetFloor(floor), targetOffice(office), anger_level(anger), patient_level(patient){

	}

	virtual ~visitor(){}

	inline int getTargetFloor()	{ return this->targetFloor; }
	inline int getId()			{ return this->id; }
	inline int getTargetOffice(){ return this->targetOffice; }

	/**
	 * set work as done for the visitor
	 */
	inline void setWorkDone()	{ this->targetFloor = 0; }
	inline void exit(){
		std::cout << "I cannot believe I finished!" << std::endl;
	}

	/* a visitor influences an other one, the result of this action is returned */
	virtual bool influence(visitor * v)		{ /* nothing happened */ return false; }
	virtual void get_positive_influence()	{ if(this->anger_level < ANGER_LIMIT) this->patient_level ++; }
	virtual void get_negative_influence()	{ if(this->patient_level < PATIENT_LIMIT) this->anger_level ++; }

	inline virtual bool isNormal()			{ return true; }
	inline virtual bool isAnger()			{ return false; }
	inline virtual bool isPatient()			{ return false; }

	inline int getAnger()					{ return this->anger_level; }
	inline int getPatient()					{ return this->patient_level; }
};

#endif /* VISITOR_HPP_ */
