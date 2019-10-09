//File: Student.h
//Author: Harchenko B.V.
//Group: M3O-221B-18
// Date: 9.10.19

#pragma once

#include <fstream>
#include <string>

class Student {
private:	
	std::string name;
	static const unsigned Days = 10;
	bool arr[Days];
	Student *next;
public:
	void add_next(Student* head) {
		next = head;
	}


	void edit_name(std::string& str){
 		name = str;
	}
 	Student* get_next()
 	{ return next; }

 	std::string get_name()
 	{ return name;}

 	void note(bool y, unsigned day){
 		if(day<Days)
 		arr[day] = y;

 	}
 	void write_arr_bool(std::ofstream& file, unsigned day){
 		for(unsigned i = 0; i < day; i++)
 			file << ' ' << arr[i];
 		

 	}

};