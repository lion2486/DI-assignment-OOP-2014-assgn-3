#ifndef PATIENT_VISITOR_HPP_
#define PATIENT_VISITOR_HPP_

#include "visitor.hpp"

class patient_visitor : public visitor{
public:
	patient_visitor(int ID, int floor, int office, int anger, int patient)
	:visitor(ID, floor, office, anger%10, patient+10)
	{}

	~patient_visitor (){}

	bool influence(visitor * v)		{ if(v == NULL) return false; else v->get_positive_influence(); return true; }
	void get_positive_influence()	{ if(this->anger_level < ANGER_LIMIT) this->patient_level += 2; }
	void get_negative_influence()	{ std::cout << "You won't get me upset!" << std::endl; }

	inline bool isNormal()			{ return false; }
	inline bool isPatient()			{ return true; }
};

#endif /* PATIENT_VISITOR_HPP_ */
