#include <iostream>
#include "building.hpp"

building::building(int N, int N_floor, int N_lift, int N_office, int N_ground)
:place(N), lift(NULL), capacity(0){

	for(int i=0; i<MAX_FLOORS; i++)
		this->floors[i] = new floor(N_floor, i+1, N_office);

	this->lift = new elevator(N_lift);

	this->ent = new entrance(N_ground);

	std::cout << "A new building is ready for serving citizens!" << std::endl;
}

building::~building(){

	for(int i=0; i<MAX_FLOORS; i++)
		delete this->floors[i];

	delete this->lift;

	delete this->ent;

	std::cout << "Service not available any longer." << std::endl;
}

bool building::enter(visitor * v){
	if(this->capacity >= this->maxCapacity){
		std::cout << "Please, come tomorrow" << std::endl;
		return false;
	}
	//this->visitors->Add_List_Item_at_End(v);
	this->ent->enter(v);
	this->capacity ++;

	return true;
}

void building::operate(){


	while(ent->getCapacity() > 0 && this->lift->getCapacity() < this->lift->getMaxCapacity()){

		this->lift->enter(ent->exit());
	}
	//lift is full now, or entrance empty
	for(int i =0; i<4; i++){
		this->lift->stop_up();
		while(this->floors[i]->getCapacity() < this->floors[i]->getMaxCapacity()){
			visitor * v = this->lift->exit();

			//there are no more visitors for this floor
			if(v == NULL)
				break;

			this->floors[i]->enter(v);
		}
	}



	//for each office and entrance trigger the influence at random
	for(int i = 0; i<4; i++){
		List * l = this->floors[i]->getRandomVisitor();
		visitor * v;

		//std::cout << "Floor " << i << " random visitor " << l->Get_List_Next()->getId() << std::endl;
		this->floors[i]->influenceOffices();

		//if l is NULL, there are no visitors
		if(l != NULL){
			v = l->Get_List_Next();	//Next, not first, list has a random current item!

			while(v != NULL){
				visitor * v2 = l->Get_List_Next();
				if(v2 == NULL)
					break;

				//if the visitor was not influenced, then the loop stops
				if(!v->influence(v2))
					break;
				else
					std::cout << "Visitor influenced" << std::endl;//TODO

				v = v2;
			}
		}

		//now check the sum of anger & patient of all visitors
		this->floors[i]->checkVisitorStatus();

	}

	//elevator down move
	for(int i=3; i >= 0; i--){
		visitor * v;

		this->lift->stop_down();
		int avail_space = this->lift->getMaxCapacity() - this->lift->getCapacity();

		for(int j=0; j<avail_space;j++){
			v = this->floors[i]->exit();
			if(v != NULL){
				v->setWorkDone();
				this->lift->enter(v);
			}
		}
	}

	//exit all visitors with work-done status
	this->lift->empty_all();

}
