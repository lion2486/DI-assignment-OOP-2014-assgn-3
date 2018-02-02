#include "List.h"

List::~List(){
	ListNode * cur, * next;

	cur = this->first;
	while(cur){
		next = cur->next;

		//We do not delete the Linked data in the Node
		//delete cur->data;
		delete cur;
		cur = next;
	}

	return;
}

void List::Add_List_Item(visitor * item, int pos){
	ListNode * tmp, * tmp2;
	int i;

	tmp2 = Create_List_Item(item);
	if(pos == 0){
		//at beginning
		tmp = this->first;
		this->first = tmp2;
		this->first->next = tmp;
		this->size ++;
	}else if(pos >= this->size-1){
		//at last pos
		//if posistion is size of greater
		tmp = this->last;
		this->last = tmp2;
		if(tmp)
			tmp->next = this->last;
		if(!this->first)
			this->first = this->last;
		this->size ++;
	}else{
		//at a middle point
		i = 0;
		tmp = this->first;
		while(i++<pos)
			tmp = tmp->next;

		if(tmp){
			if(tmp == this->last){
				this->last->next = tmp2;
				this->last = tmp2;
			}else{
				tmp2->next = tmp->next;
				tmp->next = tmp2;
			}
			this->size ++;
		}
	}

	return;
}

bool List::Remove_List_Item(int pos){
	ListNode * tmp, * next, * prev = NULL;
	int i = 0;

	if(pos >= this->size)
		//Out of range
		return false;

	if(pos == 0){
		next = this->first->next;
		//We do not delete the Linked data in the Node
		//delete this->first->data;
		delete this->first;

		if(this->first == this->last)
			this->last = next;
		this->first = next;
		this->size--;

		return true;
	}

	tmp = this->first;
	while(i < pos){
		prev = tmp;
		tmp = prev->next;
		i++;
	}

	prev->next = tmp->next;
	//We do not delete the Linked data in the Node
	//delete tmp->data;
	delete tmp;

	this->size--;

	return true;
}

bool List::Remove_Cur_Item(){
	ListNode * prev = NULL;
	ListNode * tmp;

	if(this->cur == NULL)
		return false;

	tmp = this->first;
	while(tmp){
		if(tmp == this->cur){
			if(prev)
				prev->next = this->cur->next;
			if(tmp == this->first)
				this->first = this->cur->next;
			if(tmp == this->last)
				this->last = prev;
			//We do not delete the Linked data in the Node
			//delete this->cur->data;
			delete this->cur;
			this->size--;
			return true;
		}
		prev = tmp;
		tmp = tmp->next;
	}

	return false;
}

visitor * List::Get_List_Item(int pos){
	ListNode * tmp;
	int i = 0;

	if(pos >= this->size)
		//Out of range
		return NULL;

	if(pos == 0)
		return this->first->data;

	if(pos == this->size-1)
		return this->last->data;

	tmp = this->first;
	while(i < pos){
		tmp = tmp->next;
		i++;
	}

	return tmp->data;
}

visitor * List::Get_List_First(){
	this->cur = this->first;

	if(!this->first)
		return NULL;

	return this->first->data;
}

visitor * List::Get_List_Next(){
	if(this->cur == NULL)
		return NULL;

	this->cur = this->cur->next;

	if(this->cur)
		return this->cur->data;
	else
		return NULL;
}

void List::Remove_All_Items(){
	ListNode * tmp = this->first;
	while(tmp != NULL){
		delete tmp->data;
		tmp = tmp->next;
	}
}

void List::setListCurrent(int i){
	if(i >= this->size)
		this->cur = this->last;
	else{
		this->cur = this->first;
		do{
			this->cur = this->cur->next;
		}while(--i > 0);
	}
}
