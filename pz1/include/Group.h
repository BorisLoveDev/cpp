#pragma once

#include <iostream>
#include "Student.h"

class Group {
private:
	unsigned day;
	Student *head;
public:
	Group(): day(0), head(NULL)
	{}
 	~Group()
 	{
 	 	Student *buf;

 		while (head != NULL){
			buf = head->get_next();
 			delete head;
 			head = buf;
		}

 	}

  	void add(std::string& temp)	{
 		Student *buf = new Student;
 		buf->edit_name(temp);
 		buf->add_next(head);
 		head = buf;
	}

 	void init_name(std::string& s){
 		std::string buf;
 		for ( unsigned i = 0; i < s.length(); i++){
 			while (s.at(i) != '0' && s.at(i) != '1'){
 				buf += s[i];
 				i++;
 			}

 			buf.erase( buf.size()-1, 1 );
 			add(buf);


 			buf.erase( 0, buf.size() );

 			i++;//так надо
		}
 	}
 	void init_bool(std::string& s){
 		Student* temp = head;
 		int pos;
 		bool a;

 
 		while(temp){
 			pos = s.find(temp->get_name());
 			if ( pos == -1){
 				a = false;
 			}
 			else{

 				while(s.at(pos) != '0' && s.at(pos) != '1')
 					pos++;

 				if (s[pos] == '1')
 					a = true;

 				else 
 					a = false;
 			
 			}

 			temp->note(a, day);
 		temp = temp->get_next();
		}

		day++;

	}
	void output(const std::string& path){
		std::ofstream out(path);
	
		if(!out){//не открылся
			std::cout << "ERROR! can not output file"  << std::endl;
			exit(1);
		}

		Student* temp;
		if(!head){
			out.close();
			return;

		}

		temp = head;
		while(temp){
			out << temp->get_name();
			temp->write_arr_bool(out, day);
			out << std::endl;
			temp = temp->get_next();

		}

    	out.close();

	}	
};