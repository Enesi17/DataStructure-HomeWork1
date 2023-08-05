/**
* @file        		Node.cpp
* @description 		In this file, we have all the functions of Node class
* @course 			1. ogretim, B grubu
* @assignment 		1. ödev
* @date 			22.07.2023
* @author 			B201210590, Enes Smajli, enes.smajli@ogr.sakarya.edu.tr
*/
#include "../include/Node.hpp"
// After includeing its header file it has only a constructor
Node::Node(int value)
{
	//this constructor gets a value and store it as data
    data=value;
	
	// and assings its next pointer to NULL
    next=NULL;
}