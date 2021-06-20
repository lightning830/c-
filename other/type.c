#include<stdio.h>
#include<time.h>
#include<conio.h>



int main(void) {
	int i=0;
	int j = 0;
	char a;

	void sleep(double i);

	clock_t start,end;

	//double starttime1 = clock();

	printf("5秒間できるだけ「H」のキーを押してください\n");

	//カウントダウン
	for (i = 0; i < 5; i++) {
		sleep(1);
		printf("%d\n", 5-i);
		
	}
	sleep(1);
	
	printf("Start!!\n");

	sleep(0);

	start = clock();
	//printf("%d", second);
	end = start + 5000;


	while (end-clock()>0) {
		if (_kbhit() == 1) {
			a = _getch();
			if (a == 'h') {
				j++;
			}
		}
	}
	
	printf("Finish!!""\n");
	//end = clock();

	printf("集計しています....\n");
	//printf("\n%d\n", end - start);
	// sleep(5);


	printf("あなたの記録：%d回", j);
	
	return 0;
}

void sleep(double i)
{
	clock_t g;
	g = i * CLOCKS_PER_SEC + clock();
	while (g > clock()){
		if (_kbhit() == 1) {
			char b;
			b = _getch();
		}
	}
}
