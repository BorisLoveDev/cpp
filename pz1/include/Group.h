//File: Group.h
//Author: Harchenko B.V.
//Group: M3O-221B-18
// Date: 9.10.19

#pragma once

#include <iostream>
#include "Student.h"


/*	The group contains a pointer to the head of a linked list of students 
And information about the current day 	*/
class Group {
private:
	unsigned day;	//	current day
	Student *head;	//	point to head
public:
	//	at the beginning
	Group(): day(0), head(NULL)
	{}
	//	clear linked list
 	~Group()
 	{
 	 	Student *buf;	//	buffer variable
 	 	//	go through the entire list and delete items
 		while (head != NULL){
			buf = head->get_next();
 			delete head;
 			head = buf;
		}

 	}
 	//	adding a new item to the list
  	void add(std::string& temp)	{
 		Student *buf = new Student;
 		buf->edit_name(temp);
 		buf->add_next(head);
 		head = buf;
	}
	//	filling the student's name from the general text
 	void init_name(std::string& s){
 		std::string buf;

 		//	full line pass
 		for ( unsigned i = 0; i < s.length(); i++){
 			//	passage to visit mark
 			while (s.at(i) != '0' && s.at(i) != '1'){
 				buf += s[i];
 				i++;
 			}
 			//	line adjustment
			buf.erase( buf.size()-1, 1 );

 			add(buf);	//	add to list

 			//	buffer cleaning	
 			buf.erase( 0, buf.size() );

 			i++;	//	for correct output
		}
 	}
 	//	attendance accounting
 	void init_bool(std::string& s){
 		Student* temp = head;	// buffer = head
 		int pos;	//	position in genearal text
 		bool a;	//attendance

 		//	not yet temp != NULL	
		while(temp){
 			pos = s.find(temp->get_name());

 			//	exception handling
 			if ( pos == -1){
 				a = false;
 			}
 			//	when all is well
 			else{
 				//	attendance trapping cycle
 				while(s.at(pos) != '0' && s.at(pos) != '1')
 					pos++;

 				if (s[pos] == '1')
 					a = true;

 				else 
 					a = false;
 			
 			}
 			//	attendance mark
 			temp->note(a, day);
 		temp = temp->get_next();
		}

		day++;

	}
	//	output to a text file
	void output(const std::string& path){
		std::ofstream out(path);
	
		if(!out){	// if not open
			std::cout << "ERROR! can not output file"  << std::endl;
			exit(1);
		}

		Student* temp;
		//	when NULL, file close
		if(!head){
			out.close();
			return;

		}
		temp = head;
		//	while the list is there, process it
		while(temp){
			out << temp->get_name();
			temp->write_arr_bool(out, day);
			out << std::endl;
			temp = temp->get_next();

		}

    	out.close();	//	when end, file close

	}	
};