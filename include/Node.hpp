/**
* @file        		Node.hpp
* @description 		In this file, we have all the definitions of all the functions of Node class
* @course 			1. ogretim, B grubu
* @assignment 		1. ödev
* @date 			22.07.2023
* @author 			B201210590, Enes Smajli, enes.smajli@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP
// defines Node.hpp
#include <iostream>

using namespace std;

// this class will be used by linked list
class Node
{
    public: 
	// it has only a data to store values
        int data;
	// a pointer to store the next nodes address
        Node* next;
	// and a constructor
        Node(int);
};

#endif