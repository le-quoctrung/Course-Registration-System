#include"school.h"
#include"file.h"
void readScore(string path, char username[], char password[], int type, ScoreList& List) {
	fstream file(path);
	string tr;
	Score* cur = nullptr;
	if (file.is_open()) {
		getline(file, tr, ',');
		getline(file, List.CourseCode, ',');
		getline(file, tr);
		getline(file, tr);
		while (file.eof() != true) {
			Score* S = new Score;
			S->next = nullptr;
			S->prev = nullptr;
			getline(file, S->No, ',');
			getline(file, S->StudentID, ',');
			getline(file, S->StudentFullName, ',');
			getline(file, S->TotalMark, ',');
			getline(file, S->MidTermMark, ',');
			getline(file, S->FinalMark, ',');
			getline(file, S->OtherMark, ',');
			if (List.Head == nullptr) {
				List.Head = S;
				cur = S;
			}
			else {
				cur->next = S;
				S->prev = cur;
				cur = S;
			}

		}
	}
	else {
		cout << "Not Found the Score board";
	}
}