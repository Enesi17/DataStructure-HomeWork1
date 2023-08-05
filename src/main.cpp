/**
* @file        		main.cpp
* @description 		In this file, I put the main function and it does all the mathematical and logical functions.
* @course 			1. ogretim, B grubu
* @assignment 		1. ödev
* @date 			22.07.2023
* @author 			B201210590, Enes Smajli, enes.smajli@ogr.sakarya.edu.tr
*/

// including the libraries needed
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

// including the header files needed
#include "../include/Node.hpp"
#include "../include/LinkedList.hpp"


using namespace std;

int main()
{
	// For a better view, I added this command that will clean the console
	system("cls");
	
	//First we creat 2 string one to store the name of the file we gonna get from the user
	//and the secoond to store each line while reading the file
	string filename, line;
	
	//This variable will be used later on the program
    int rowCount=0;
	
	//Asking the user to enter name of file
    cout << "Enter the file name you want to read: " << endl;
	
	//Getting the filename 
    cin >> filename;
	
	// Creating a ifstream obj to read the file
    ifstream file(filename);
    
	// Controlling if the file is opened succsesfully 
    if(!file.is_open())
    {
		//if there is a problem opening the file it will throw this error text
        cout << "Error opening file" << endl;
        return 1;
    }
    
	//Reading the file to count how many rows does it contain
	//we will need this info to procede with assigning of the arrays and lists later
    while(getline(file,line))
    {
        rowCount++;
    }
	
	//clearing the file obj in case we need to re-read the file
    file.clear();
	//putting the coursore in the line 0 of the file
    file.seekg(0);
	
	//Based on the number of lines we reserve a place in heap for
	//2 arrays that will store our one-way linked lists so we can move them later
	//as asked in the homework paper
	// ptrForlistUps = array of pointers for list that will be stored in the up position
	// as asked for in the figure in the homework paper
	// these lists will store the 10th place digits 
    LinkedList* ptrForListsUps = new LinkedList[rowCount]; 
	
	// ptrForlistDowns = array of pointers for list that will be stored in the down position
	// as asked for in the figure in the homework paper
	// these lists will store the 1st place digits
    LinkedList* ptrForListsDowns = new LinkedList[rowCount];
	
    //We will use this integer variable inside the while loop
	int i =0;
	
	//while loop for re-reading the file, getting every line sotred in string line
    while(getline(file,line))
    {
		// creating a istringstream obj to seperate each number in the line and store it
		// in the num variable so we can add it to the list 
        istringstream iss(line);
        int num;
        
		// while loop to get every num inside the line read by file obj
        while (iss >> num) 
		{
			
			// we insert using the insert function we created in the class linkedList
			// the formula we use will get us the 10th place digit from the num iss got from the line
			// and it will be stored in the i list of ups
            ptrForListsUps[i].insert((num/10)%10);
			
			// we insert using the insert function we created in the class linkedList
			// the formula we use will get us the 1st place digit from the num iss got from the line
			// and it will be stored in the i list of downs
            ptrForListsDowns[i].insert(num%10);
        }
		// increasing i to be able to navigate in the arrays of lists
        i++;
    }
	
	// i used this for loop to be able to reverse each list because while inserting the elements 
	// the vies was not as asked in the paper
    for(int i=0;i<rowCount;i++)
    {
		//reversing using the reverse() function of linkedList class
        ptrForListsUps[i].reverse();
		
		//reversing using the reverse() function of linkedList class
        ptrForListsDowns[i].reverse();
    }
    
	// displaying the fixed form of lists
	// this one is only for testing reasons (optional, it can be commented by the teacher if needed) 
    for(int i=0;i<rowCount;i++)
    {
			cout << setw(8)<< "Row "<< i+1 << " of read file:" << endl; 
			cout << "============================" << endl;
			// displaying using display() function of linkedList class
			cout << "10's place list: " << endl;
			ptrForListsUps[i].display();
		
			// displaying using display() function of linkedList class
			cout << "1st plac list:" << endl;
			ptrForListsDowns[i].display();
			cout << endl;
    }
	// closing the file by close() function cuz the reading is done and we got all the things stored as wanted
    file.close();

	// in the assignment is asked to perform a change of lists and this to variables will be index
	// for lists that will change places 
    int changeUp=0, changeDown=0;
	
	// asking the user to enter a numbers that will be index for 10th place lists
    cout << "Enter a index for up: " << endl;
    cout << "Up: "; cin >> changeUp;

	// asking the user to enter a numbers that will be index for 1st place lists
    cout << "Enter a index for down: " << endl;
    cout << "Down: "; cin >> changeDown;
    
	// this controll chechks if the index given by the user is inside the range allowed
    if (changeUp >= 0 && changeUp < rowCount && changeDown >= 0 && changeDown < rowCount) 
    {
		// to make the change we use list temp = temporary
        LinkedList temp;
		
		// more specificlly we use heads of each list to make the moves
		// storing the upper list to temp 
        temp.head = ptrForListsUps[changeUp].head;
		
		// making the head of upper list NULL so it will not cause any problems 
        ptrForListsUps[changeUp].head=NULL;
		
		// making the change by giving the downs list head to the upper lists head
        ptrForListsUps[changeUp].head = ptrForListsDowns[changeDown].head;
		
		// making downs lists head NULL so it will not cause any problems
        ptrForListsDowns[changeDown].head=NULL;
		
		// making the 2. change by givin the head of temp to down which means the upper to down list
        ptrForListsDowns[changeDown].head = temp.head;
		
		// just in case we will use it again we make the head of temp null so it won't show anything
        temp.head=NULL;
    } else 
    {
		// in case index is out of range we throw this error 
        cout << "Invalid indices. The swap cannot be performed." << endl;
        return -1;
    }

	// assigning avarage and upAvg to store the arithmetical avarages we find from for each elements of each list
	// also assigning sum that will help the process
    double avarage=0, upAvg=0, sum=0;
	
	// assigning elements to count so we can find avarage in the right way
    int elements=0;

	// this nested for loop will find the avarage for the elements in the 10s place or 
	// as we call it through the program ups lists elements 
	// the first loop or outer loop will iterate as mucuh as the number of the ups list size
	// we find the size of it using countElements() function of linkedList class
    for(int i=0; i<ptrForListsUps->countElements(); i++)
    {
		// making sum and elements 0 in every iteration of the outer loop
        sum=0;
        elements=0;
		
		// the inner loop will iterate as much as rowCount which is the number of rows of the file
        for(int j=0;j<rowCount;j++)
        {
			// controlling if the element is null 
			// getElementAt(int) function of linkedList class will return a negative value if the element is NULL 
			// or if the element does not exsist at all 
            if(ptrForListsUps[j].getElementAt(i) < 0)
			{
				// it continues to the next iteration
                continue;
            }else{  
				//if it is not NULL it finds the sum of the same place elements
                sum=sum+ptrForListsUps[j].getElementAt(i);
				
				//also counts the number of the elements tha formed that sum 
                elements++;
            }
        }
		// it find the avarge of that place elements
        avarage = sum/elements;
		
		// then find the general avarge that will be outputed to the console
        upAvg=upAvg+avarage;
    }
    // clears the console to provide a bettwe view
    system("cls");
	
	//Prints out the general avarge for up list elements
    cout << "Up: " <<  upAvg << endl;

	// now to find the down general avarge we should make all of these variables 0 again
    avarage=0; 
    elements=0;
    sum=0;
	
	//also assign this variable for the general avarage of down lists
	double downAvg=0;

	// this nested for loop will find the avarage for the elements in the 1st place or 
	// as we call it through the program downs lists elements 
	// the first loop or outer loop will iterate as mucuh as the number of the down list size
	// we find the size of it using countElements() function of linkedList class
    for(int i=0; i<ptrForListsDowns->countElements(); i++)
    {
		// making sum and elements 0 in every iteration of the outer loop
        sum=0;
        elements=0;
		
		// the inner loop will iterate as much as rowCount which is the number of rows of the file
        for(int j=0;j<rowCount;j++)
        {
			// controlling if the element is null 
			// getElementAt(int) function of linkedList class will return a negative value if the element is NULL 
			// or if the element does not exsist at all 
            if(ptrForListsDowns[j].getElementAt(i) < 0)
			{
				// it continues to the next iteration
                continue;
            }else{  
				//if it is not NULL it finds the sum of the same place elements
                sum=sum+ptrForListsDowns[j].getElementAt(i);
				
				//also counts the number of the elements tha formed that sum 
                elements++;
            }
        }
		// it find the avarge of that place elements
        avarage = sum/elements;
		
		// then find the general avarge that will be outputed to the console
        downAvg=downAvg+avarage;
    }
	
    //Prints out the general avarge for down list elements
    cout << "Down: " <<  downAvg << endl;

	// delete for all the location we got in heap in the beggining of the program
    delete[] ptrForListsDowns;
    delete[] ptrForListsUps;
	
	return 0;
}