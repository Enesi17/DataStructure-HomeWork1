# DataStructure-HomeWork1
Data Structure course 1st homework

This home work was given by Data Structure professor. 

The assignment was:
The program will be written in MinGW C++ environment. 

As the program runs, it will read the file named Numbers.txt. The file format is given below. Two-digit numbers in each line are added, separated by a space. The number of lines in the file and the number of lines to be found in each line can be variable. The only certainty is that the numbers will be two-digit numbers.For example:
17 25 30 12
19 78 37
62 30 28 56

As this file is read, the numbers will be broken down and placed in the structure given in the picture below.
(the image in the file of assignment) 

As seen in the figure on the right, the digit in the tens place of the numbers in each row is placed in the upward one-way relative list. The digit in the ones place is placed in the downward one-way relative list. After the insertion is complete, the user will be prompted for two index locations:
Position A: It will represent upward lists.
Position B: Will represent downward lists.

For example, when values like the following are entered, the lists will change places:
Position A: 0
Position B: 2

(the image in the file of assignment) 

In this new image, the lists above and below will bring the average of the first nodes, and the average of the second nodes, bringing the sum among themselves.
Let's continue with the example below:
(2+1+6)/3=3 (0+7+3)/3=3.3 (8+3+2)/3=4.3 (6+5)/2=5.5
3+3.3+4.3+5.5= 16.1
(7+9+1)/3=5.6 (5+8+2)/3=5 (0+7+3)/3=3.3 (2+1)/2=1.5
5.6+5+3.3+1.5= 15.4

Screen Output to be given at the end should be as below
Top: 16.1
Bottom : 15.4

The program should be written in such a way that it can read very large files. The occurrence of garbage in the program causes the score to be broken.
Under no circumstances can the Template (Generic) data structure be used. A ready data structure cannot be used.
