#include "Group.h"


using namespace std;



int main(int argc, char* argv[]){



Group mai221;


	ifstream in;
	char temp[128];
	string str;
	string text;
	string fname;
	const	string path_out = "out/output.txt";
	const string prefix = "days_in/";
	for (int i = 1; i < argc; i++){
 
		fname = prefix + argv[i];
		in.open(fname);

		if (in.is_open()) {
    
    		while (in.getline(temp, 128, '\n')) {
    			str = temp;
 				text += (str + '\n');
    
			}

			text.erase(text.size()-1, 1);
			in.close();

		}
		else{
			cout << "file not found!" << endl;
			exit(0);
		}

			if (i == 1)
		 		mai221.init_name(text);
		 	mai221.init_bool(text);
		 	text.erase(0, text.size());

	}

	mai221.output(path_out);

	return 0;


}