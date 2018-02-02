#include <iostream>
#include <cstdlib>
#include "List.h"
#include "building.hpp"
#include "visitor.hpp"
#include "anger_visitor.hpp"
#include "patient_visitor.hpp"

int main(int argc, char * argv[]) {
	int N, N_floor, N_ground, N_office, N_lift, K, L;
	building * b;
	List visitors;
	int visitorID = 0;
	List * queue;

	//list to add visitors to enter later in the building
	queue = new List();

	srand(time(NULL));

	if(argc < 7){
		std::cerr << "Call with exact 7 arguments, N, Nf, Ng, No, Nl, K, L" << std::endl;

		return EXIT_FAILURE;
	}

	//add arguments to variables
	N 			= atoi(argv[1]);
	N_floor 	= atoi(argv[2]);
	N_ground 	= atoi(argv[3]);
	N_office 	= atoi(argv[4]);
	N_lift		= atoi(argv[5]);
	K			= atoi(argv[6]);
	L			= atoi(argv[7]);

	//validation tests
	if(N_floor >= N/3 || N_ground >= N/2 || N_office >= N_floor || N_lift <= N_office ){
		std::cerr << "Data given are invalid, exiting..." << std::endl;

		return EXIT_FAILURE;
	}

	//create the building
	b = new building(N, N_floor, N_lift, N_office, N_ground);



	//create K visitors
	for(int i=0; i<K; i++){

		//Here randomly creates a angry of patient visitor

		visitor * v;
		switch(rand() % 10){
			case 0:
			case 1:
					v = new visitor(++visitorID, rand() % 4 + 1, rand() % 10, rand() % 20, rand() % 20);
					break;
			case 2:
			case 3:
			case 4:
			case 5:
					v = new anger_visitor(++visitorID, rand() % 4 + 1, rand() % 10, rand() % 20, rand() % 20);
					break;
			case 6:
			case 7:
			case 8:
			case 9:
			default:
					v = new patient_visitor(++visitorID, rand() % 4 + 1, rand() % 10, rand() % 20, rand() % 20);
					break;
		}

		//if the enter fails, push the visitor to the list to enter later
		if(!b->enter(v)){
			queue->Add_List_Item_at_End(v);
		}
	}

	for(int i=0; i<L; i++){

		//try to enter the rest visitors in the building
		while(b->getMaxCapacity() > b->getCapacity() && queue->Get_List_Size() > 0){
			b->enter(queue->Get_List_First());
			queue->Remove_List_Item(0);
		}

		b->operate();
	}

	delete queue;

	//destroy the building
	delete b;

	return EXIT_SUCCESS;
}
