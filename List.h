#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include "visitor.hpp"

class ListNode{
public:
	visitor * data;
	ListNode * next;
};

/**
 * A single Linked List implementation
 * All data inserted are by pointer and no deletion is performed.
 * Note: Consider adding items at front or back to increase performace.
 */

class List{
protected:
	ListNode * first;
	ListNode * last;
	int size;
	ListNode * cur;

	/**
	 * Create and Initialise the new Node in order to
	 * insert it into the list.
	 */
	ListNode * Create_List_Item(visitor * data){
		ListNode * tmp;

		tmp = new ListNode();

		tmp->data = data;
		tmp->next = NULL;

		return tmp;
	}
public:
	List()
	:first(NULL), last(NULL), size(0), cur(NULL)
	{ }
	virtual ~List();

	/**
	 * Returns 1 if the list is empty
	 */
	inline int Empty_List(){ return (this->size == 0) ? 1 : 0; }

	/**
	 * Returns the number of the nodes of the list
	 */
	inline int Get_List_Size(){ return this->size;	}

	/**
	 * Adds item (by pointer) to the end of the list
	 */
	inline void Add_List_Item_at_End(visitor * item){
		this->Add_List_Item(item, this->size-1);
	}

	/**
	 * Adds item (by pointer) to the list in #pos of the list
	 * If no second param supplied, the item is inserting at
	 * the beggining of the list.
	 */
	virtual void Add_List_Item(visitor * item, int pos = 0);

	/**
	 * Removes the item of the list in #pos
	 *
	 * Note: It only unlinks the node, it doesn't
	 * delete the node data.
	 */
	bool Remove_List_Item(int pos);

	/**
	 * Removes the Current list item from the list
	 *
	 * Note: It only unlinks the node, it doesn't
	 * delete the node data.
	 * Also, method-itteration have to be used before.
	 */
	bool Remove_Cur_Item();

	/**
	 * Returns the item of the #pos possition.
	 */
	visitor * Get_List_Item(int pos);

	/**
	 * Get list first item and initialises the
	 * itteration.
	 */
	visitor * Get_List_First();

	/**
	 * Get the next list item from itteration.
	 * If there is no next item NULL is returned.
	 */
	visitor * Get_List_Next();

	/**
	 * Deletes all items into the list, after that delete the list
	 */
	void Remove_All_Items();

	/**
	 * Set list current item the item #i
	 */
	void setListCurrent(int i);
};

#endif /* LIST_H_ */
