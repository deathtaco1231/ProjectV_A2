#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct STUDENT_DATA {
	string FirstName;
	string LastName;
};

int main(void) {
	std::ifstream studentDataFile; 
	studentDataFile.open("StudentData.txt");
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
		getline(curLine, curStudent.LastName);
		studentDataVector.push_back(curStudent);
	}


	return 1;
}