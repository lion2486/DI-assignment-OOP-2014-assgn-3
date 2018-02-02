#include <iostream>
#include "elevator.hpp"

elevator::elevator(int N)
:room(N), floor(0){
	std::cout << "A lift has been created" << std::endl;
}

elevator::~elevator(){
}

bool elevator::enter(visitor * v){
	if(this->visitors->Get_List_Size() < this->maxCapacity){
		this->visitors->Add_List_Item_at_End(v);

		std::cout << "Visitor in the lift " << v->getId() << std::endl;

		return true;
	}else{
		std::cout << "You are not allowed to enter!" << std::endl;

		return false;
	}
}

visitor * elevator::exit(){
	visitor * tmp;

	tmp = this->visitors->Get_List_First();
	while(tmp != NULL){
		if(tmp->getTargetFloor() == this->floor){
			this->visitors->Remove_Cur_Item();

			return tmp;
		}
		tmp = this->visitors->Get_List_Next();
	}

	return NULL;
}

void elevator::empty_all(){
	visitor * v = this->visitors->Get_List_First();

	while(v != NULL){
		if(v->getTargetFloor() == 0){
			v->exit();
			this->visitors->Remove_Cur_Item();
			delete v;

			v = this->visitors->Get_List_First();
		}else
			v = this->visitors->Get_List_Next();
	}
}
