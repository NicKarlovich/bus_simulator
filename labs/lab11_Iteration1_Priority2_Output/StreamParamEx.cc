/*
 * StreamParamEx.cc
 * 
 * Copyright 2019 Daniel J. Challou <chal0006@ubuntu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

/* 
 * The comments in this file and the example in it server a guide to performing LAB 11
 * 
 * The function report defined below will accept any output stream (e.g., a file descriptor or cout)
 * and write the contents of the string passed as a parameter to it to the output stream.
 * The main program below demonstrates the functionality of the report function. 
 * 
 * You can compile this file in your terminal window, eg.
 * % g++ StreamParamEx.cc -o testReport 
 * 
 * and then run the executable:
 * % ./testReport
 * 
 * The content of the string aStr will be printed out to the file named:Results.txt and 
 * to the terminal window from which the program was run (that is, std::cout).
 *  
 * (You should look at the contents of Results.txt and the output
 * of your terminal window to confirm this)
 * 
 * This functionality is required for iteration 1, Priority Level 2 output refactoring:
 * 
 * As per the requirements:
 * 
 * In early prototyping and debugging of individual units, 
 * it is very common to simply use the display for output of information. 
 * std::cout is a familiar friend in this. However, once we get to a point 
 * where we want to have a persistent access to results, 
 * flexibility in operation, and easier ability to test program output we
 * may want to save our Report output to a file for later analysis.
 *  
 * To this end, in this lab, you should refactor the code we gave you for iteration 1
 * to allow for the use of other ostream objects 
 * in place of std::cout for the Report() methods that exist within the code we gave you.
 * 
 * Specifically, for this lab, find each instance of thie Report method 
 * and refactor the code to include the ability to give the method an 
 * instance of an ostream object (which may or may not be std::cout in the end). 
 * Remember: refactoring means to modify the internal functionality of the code 
 * while maintaining the same observable behavior outside the system. 
 * Our methods should still work the same way from the outside 
 * (assume that our simulator will be similarly updated to use this new functionality -
 *  You may also do this yourself in your testing.)
 * 
 */
#include <iostream>
#include <fstream>
#include <string>

void Report(std::ostream &  out, std::string stuff){
	
	out << stuff << std::endl;
}

int main() {
	std::string aStr = "Here is some example text\n";
	std::ofstream myfile;
	myfile.open("Results.txt");
	
	
	Report(myfile,aStr);
	
	myfile.close();
	
	std::cout << aStr;
	
	return 0;
}

