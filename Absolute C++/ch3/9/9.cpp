#include <iostream>
#include <ctime>

using namespace std;

int roll_two_dice();
bool play();

int main(void) {

	int win = 0, lose = 0;
	srand(time(NULL));
	
	for (int i = 0;i < 10000;i++) {
		
		if (play())
			win++;
		else
			lose++;
	
	}
		
	cout << "Win rate : " << (double)win / (win + lose) * 100 << "%" << endl;

	system("pause");
	return 0;

}

int roll_two_dice() {

	return (rand() % 6 + 1) + (rand() % 6 + 1);

}

bool play() {

	int now_point, the_point;

	now_point = roll_two_dice();

	if (now_point == 7 || now_point == 11)
		return true;
	else if (now_point == 2 || now_point == 3 || now_point == 12)
		return false;
	else
		the_point = now_point;

	do {
	
		now_point = roll_two_dice();
	
	} while (now_point != 7 && now_point != the_point);

	if (now_point == the_point)
		return true;
	else
		return false;

}