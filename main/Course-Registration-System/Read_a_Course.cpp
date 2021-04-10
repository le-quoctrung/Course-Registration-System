#include"Tokenizer.h"
#include"Console.h"
#include"School.h"
void readfile(fstream f, course& C) {
	f.open("course.txt", ios::in);
	string data;
	string line;
	vector<string>read;
	while (!f.eof()) {
		getline(f, line);
		data += line;
	}
	read = split(data, ",");
	f.close();
	C.ID = read[0];
	C.name = read[1];
	C.TeacherName = read[2];
	C.credit = stoi(read[3]);
	C.max = stoi(read[4]);

}