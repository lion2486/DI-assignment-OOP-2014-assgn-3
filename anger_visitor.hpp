#ifndef ANGER_VISITOR_HPP_
#define ANGER_VISITOR_HPP_

#include "visitor.hpp"

class anger_visitor : public visitor{
public:
	anger_visitor(int ID, int floor, int office, int anger, int patient)
	:visitor(ID, floor, office, anger+10, patient%10)
	{}

	~anger_visitor(){}

	bool influence(visitor * v)		{ if(v == NULL) return false; else v->get_negative_influence(); return true; }
	void get_negative_influence()	{ if(this->patient_level < PATIENT_LIMIT) this->anger_level += 2; }

	inline bool isNormal()			{ return false; }
	inline bool isAnger()			{ return true; }
};


#endif /* ANGER_VISITOR_HPP_ */
