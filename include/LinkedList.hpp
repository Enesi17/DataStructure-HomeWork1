/**
* @file        		LinkedList.hpp
* @description 		In this file, we have the definitions of all the functions of class LinkedList class
* @course 			1. ogretim, B grubu
* @assignment 		1. ödev
* @date 			22.07.2023
* @author 			B201210590, Enes Smajli, enes.smajli@ogr.sakarya.edu.tr
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
// After defining the header file for LinkedList we include Node.hpp because we will need it
#include "../include/Node.hpp"
#include <iostream>

using namespace std;

// class name could have been onewaylinkedlist to but this was shorter
class LinkedList
{      
    public:
		// object from clas node for the head of the list
        Node* head;
		
		// The constructer of the list
        LinkedList();
		
		// this function will insert values to the list
        void insert(int);
		
		// this function will output the values of the list
        void display();
		
		// this function will delete all the elements of the list from it
        void clear();
		
		// this fucntion will reverse the list because it is one-way linked list we need to do this will a function
		// cuz we can go only one-way through the elements
        void reverse();
		
		// this function will get us any element of list given the index of it
        int getElementAt(int);
		
		// this function returns us the size of the list
        int countElements();
		
		// deconstructor of the list
        ~LinkedList();
};


#endif