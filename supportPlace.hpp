#ifndef SUPPORTPLACE_HPP_
#define SUPPORTPLACE_HPP_

#define TOTAL_FLOOR_ANGER_LIMIT 40
#define TOTAL_FLOOR_PATIENT_LIMIT 40

class supportPlace{
public:
	virtual ~supportPlace(){}

	virtual List * getRandomVisitor() = 0;

	virtual void checkVisitorStatus(){};
};

#endif /* SUPPORTPLACE_HPP_ */
