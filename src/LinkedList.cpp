/**
* @file        		LinkedList.cpp
* @description 		In this file, we have all functions of LinkedList class
* @course 			1. ogretim, B grubu
* @assignment 		1. ödev
* @date 			22.07.2023
* @author 			B201210590, Enes Smajli, enes.smajli@ogr.sakarya.edu.tr
*/
#include "../include/LinkedList.hpp"

// each lists constructor will give the head a null value
LinkedList::LinkedList()
{
    head=NULL;
}

// insert function will insert parameter as a element in the list
void LinkedList::insert(int value)
{
	// it will do it by creating a new Node
    Node* newNode = new Node(value);
	
	//it connects the new element with the head
    newNode->next = head;
	
	// it gives the head the newNode
    head = newNode;
}

// display function will display all the elements of the list
void LinkedList::display()
{
	// assign a node cuurent to be able to iterate until that node
	// in the first place we give this node the head value
    Node* current =head;
	
	// if it is not null we go through the list
    while(current != NULL)
    {
		// a printing pattern that will pattern the values of list
        cout << current->data << " => ";
		
		// after displaying one elements it sends the current to the next one
        current = current->next;
    }
	// and it outpts the NULL value in the end of each list
    cout << "Null" << endl;
}

// this function will clear all the elemetns of the list if there are any
void LinkedList::clear()
{
	// to start from the head it gives the current node the value of the head
    Node* current = head;
	
	// iterates untill NULL
    while(current!=NULL)
    {
		//temporary node to save the pointer to the next node of the list
        Node *temp =current;
		
		// putting current node to the next one
        current = current->next;
		
		//deleteing the previous one
        delete temp;
    }
	// making the head NULL as in the first place 
    head = NULL;
}

// this function will revers the list
// it is needed because our list is one-way list 
void LinkedList::reverse() 
{
	// it makes the needed assigns of nodes
    Node* previousNode = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

	// iterates until NULL
    while (current != nullptr) 
	{
		// using current and prevoius and next node it will reverse each element of list
        nextNode = current->next;
        current->next = previousNode;
        previousNode = current;
        current = nextNode;
    }
	
	// now setting the new head	
    head = previousNode;
}

// function that will return elements given the index
int LinkedList::getElementAt(int index) 
{
		// also uses cuurent node
        Node* current = head;
		// currentIndex to iterate until it is equal to index given
        int currentIndex = 0;

		// iterates until NULL
        while (current != nullptr) 
        {
			// checks if we are in the index we want
            if (currentIndex == index) 
            {
				// if we reached it we it returns element
                return current->data;
            }
			// if not it contionues the iteration
            current = current->next;
            currentIndex++;
        }
		
		// if the element is not found it return this value
        return -1;
}

// this function is used to count elements
int LinkedList::countElements() {
        int count = 0;
        Node* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

// this is the destructor of class linkedList
LinkedList::~LinkedList()
{
    clear();
}