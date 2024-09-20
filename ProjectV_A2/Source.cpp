#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct STUDENT_DATA {
	string FirstName;
	string LastName;
#ifdef PRE_RELEASE
	string Email;
#endif
};

int main(void) {
	std::ifstream studentDataFile;
	#ifdef PRE_RELEASE
		std::cout << "This application is runing pre-release software." << endl;
		studentDataFile.open("StudentData_Emails.txt");
	#else
		std::cout << "This application is running standard software." << endl;
		studentDataFile.open("StudentData.txt");
	#endif
	std::string line;
	std::vector<STUDENT_DATA> studentDataVector;
	while (!studentDataFile.eof()) {
		getline(studentDataFile, line);
		#ifdef _DEBUG
		cout << line << endl;
		#endif
		std::stringstream curLine(line);
		STUDENT_DATA curStudent;
		getline(curLine, curStudent.FirstName, ',');
		#ifdef PRE_RELEASE
			getline(curLine, curStudent.LastName, ',');
			getline(curLine, curStudent.Email);
		#else
			getline(curLine, curStudent.LastName);
		#endif
		studentDataVector.push_back(curStudent);
	}


	return 1;
}