//	File: pz1.cpp
//	Author: Harchenko B.V.
//	Group: M3O-221B-18
//	Date: 9.10.19

#include "Group.h"

using namespace std;

//	main arguments are student visit file names
int main(int argc, char* argv[]){

	Group mai221;	//	initialization of the main object
	ifstream in;	//	input stream initialization
	char temp[128];	//	temp string for getline
	string str;		//	buffer string for text
	string text;	//	string for all text
	string fname;	//	input file direction
	const string path_out = "out/output.txt";	//output file directory
	const string prefix = "days_in/";	//input	file directory

	//pass through all input files	
	for (int i = 1; i < argc; i++){ 
 
		fname = prefix + argv[i];
		in.open(fname);

		if (in.is_open()) {	//	open check
    
    		// reading line by line
    		while (in.getline(temp, 128, '\n')) {
    			str = temp;
 				text += (str + '\n');
    
			}

			text.erase(text.size()-1, 1);	//space adjustment
			in.close(); //	file close

		}

		//	if file not open
		else{
			cout << "file not found!" << endl;
			exit(0);
		}
			//	initialize the first
			if (i == 1)
		 		mai221.init_name(text);

		 	mai221.init_bool(text);	//	attendance filling
		 	text.erase(0, text.size());	//buffer clearing

	}

	mai221.output(path_out);	//	saving results in output file

	return 0;


}