#include <stdio.h>
#include <string.h>

int Percentage2GPA(int score){
	int gpa = (score - 50) / 10;
	
	gpa = gpa > 4 ? 4 : gpa < 0 ? 0 : gpa;	

	return gpa;
}

int main(){
	char* rScores[] = {"A", "B", "C", "D", "F"};
	char* rDescriptions[] = {"Atomic!", "Badass", "Cool", "Dirty", "Failure"};

	int score = 59;
	int gpa = Percentage2GPA(score);

	printf("Your score is %d which is equivalent to %d\n", score, gpa);
	printf("Your GPA is %s\n", rScores[4 - gpa]);
	printf("Your results were '%s'\n", rDescriptions[4 - gpa]);
}
