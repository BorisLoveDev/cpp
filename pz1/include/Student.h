//File: Student.h
//Author: Harchenko B.V.
//Group: M3O-221B-18
// Date: 9.10.19

#pragma once

#include <fstream>
#include <string>

	//	The student has a name in the name and on attendance data
class Student {
private:	
	std::string name;	//	student name
	static const unsigned Days = 10;	//	total days	
	bool arr[Days];	//	an array of visits for a certain number of days per student
	Student *next;	//	pointer to the next item in a linked list
public:
	// next editor
	void add_next(Student* head) {
		next = head;
	}

	//	name editor
	void edit_name(std::string& str){
 		name = str;
	}
	//	Access to next
 	Student* get_next()
 	{ return next; }

 	// Access to name
 	std::string get_name()
 	{ return name;}

 	//	filling in visits
 	void note(bool y, unsigned day){
 		if(day<Days)
 		arr[day] = y;

 	}
 	//	student attendance output
 	void write_arr_bool(std::ofstream& file, unsigned day){
 		for(unsigned i = 0; i < day; i++)
 			file << ' ' << arr[i];
 		

 	}

};