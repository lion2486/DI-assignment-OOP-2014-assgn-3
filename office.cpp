#include <iostream>
#include <cstdlib>
#include "office.hpp"

office::office(int i, int N_office)
:room(N_office), index(i){

	std::cout << "Office number " << i << " has been created" << std::endl;
}

office::~office(){

	std::cout << "End of the work!" << std::endl;
}

bool office::enter(visitor * v){

	if(this->visitors->Get_List_Size() < this->maxCapacity){
		this->visitors->Add_List_Item_at_End(v);
		std::cout << "Entering office number " << this->index << " " <<  v->getId() << std::endl;

		return true;
	}else{
		std::cout << "Please, wait outside for entrance in office number " << this->index << " " << v->getId() << std::endl;

		return false;
	}
}

visitor * office::exit(){
	visitor * v;

	if(this->visitors->Get_List_Size() == 0)
		return NULL;

	v = this->visitors->Get_List_First();
	this->visitors->Remove_List_Item(0);

	return v;
}

inline List * office::getRandomVisitor(){
	if(this->visitors->Get_List_Size() == 0)
		return NULL;

	this->visitors->setListCurrent(rand() % this->visitors->Get_List_Size());
	return this->visitors;
}

void office::calculateVisitorStatus(int * angerSum, int * patientSum){
	visitor * v;

	v = this->visitors->Get_List_First();

	while(v != NULL){
		(*angerSum) += v->getAnger();
		(*patientSum) += v->getPatient();

		v = this->visitors->Get_List_Next();
	}
}
