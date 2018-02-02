#include <iostream>
#include "floor.hpp"

floor::floor(int cap, int f, int N_office)
:place(cap), floor_num(f){

	for(int i=0; i<MAX_OFFICES; i++)
		this->offices[i] = new office(i, N_office);

	this->ent = new entrance(cap);

	std::cout << "A Floor has been created with number " << f << std::endl;
}

floor::~floor(){

	for(int i=0; i<MAX_OFFICES; i++)
			delete this->offices[i];

	delete this->ent;

	std::cout << "End of service!" << std::endl;
}

bool floor::enter(visitor * v){
	if(this->ent->enter(v)){
		std::cout << "Entering floor number " << this->floor_num << " " <<  v->getId() << std::endl;

		//try to enter a visitor int office
		for(int i=0; i<MAX_OFFICES && this->ent->getCapacity(); i++){
			if( this->offices[i]->getMaxCapacity() > this->offices[i]->getCapacity()){
				visitor * v = this->ent->exit();
				this->offices[i]->enter(v);
			}
		}

		return true;
	}else{
		std::cout << "Sorry, floor number " << this->floor_num << " is full " << v->getId() << std::endl;

		return false;
	}
}

visitor * floor::exit(){
	visitor * v;

	//pops out a visitor from an office
	for(int i=0; i<MAX_OFFICES; i++){
		v = this->offices[i]->exit();
		if(v != NULL)
			break;
	}

	//try to enter a visitor int office
	for(int i=0; i<MAX_OFFICES && this->ent->getCapacity(); i++){
		if( this->offices[i]->getMaxCapacity() > this->offices[i]->getCapacity()){
			visitor * v = this->ent->exit();
			this->offices[i]->enter(v);
		}
	}

	return v;
}

void floor::checkVisitorStatus(){
	int angerSum = 0, patientSum = 0;

	this->ent->calculateVisitorStatus(&angerSum, &patientSum);

	for(int o = 0; o < 10 && this->floor_num != 0; o++)
		this->offices[o]->calculateVisitorStatus(&angerSum, &patientSum);

	if(angerSum >= TOTAL_FLOOR_ANGER_LIMIT)
		std::cout << "What a mess in floor number: " << this->floor_num << std::endl;

	if(patientSum >= TOTAL_FLOOR_PATIENT_LIMIT)
		std::cout << "Peace and cerenity in floor number: " << this->floor_num << std::endl;
}

void floor::influenceOffices(){
	List * l;
	visitor * v;

	//now, on each floor, check for every office in it, except floor 0 - ground floor
	for(int o = 0; o<10 && this->floor_num!=0; o++){
		l = this->offices[o]->getRandomVisitor();

		//if l is NULL, that means that there are no visitors
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
	}
}
