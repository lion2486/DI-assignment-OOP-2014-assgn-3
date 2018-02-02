#include <iostream>
#include <cstdlib>
#include "entrance.hpp"


entrance::entrance(int cap)
:room(cap){

}

entrance::~entrance(){
	std::cout << "End of waiting people!" << std::endl;
}

bool entrance::enter(visitor * v){
	if(this->visitors->Get_List_Size() < this->maxCapacity){
		this->visitors->Add_List_Item_at_End(v);

		return true;
	}else{
		return false;
	}
}

visitor * entrance::exit(int office){
	visitor * v = NULL, * tmp;
	int minId = -1, pos = 0, minPos = -1;

	tmp = this->visitors->Get_List_First();
	while(tmp != NULL){
		if((tmp->getId() < minId || minId == -1) && (tmp->getTargetOffice() == office || office == -1)){
			minId = tmp->getId();
			v = tmp;
			minPos = pos;
		}

		tmp = this->visitors->Get_List_Next();
		pos ++;
	}

	if(minPos >= 0)
		this->visitors->Remove_List_Item(minPos);

	return v;
}

List * entrance::getRandom(){
	if(this->visitors->Get_List_Size() == 0)
		return NULL;

	this->visitors->setListCurrent(rand() % this->visitors->Get_List_Size());

	return this->visitors;
}

void entrance::calculateVisitorStatus(int * angerSum, int * patientSum){
	visitor * v;

	v = this->visitors->Get_List_First();

	while(v != NULL){
		(*angerSum) += v->getAnger();
		(*patientSum) += v->getPatient();

		v = this->visitors->Get_List_Next();
	}
}
