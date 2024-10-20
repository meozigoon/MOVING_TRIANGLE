#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<string.h>
#include<mmsystem.h>
#include<conio.h>
#pragma warning(disable:4996)

#pragma comment(lib,"winmm.lib")

int a, b, c, d, e, f, color, i, j, ab = 1, i2;
int sc, sc1, sc2;
int ii;
int xy6;
int u;
int aa, aaa;
int ss;
int anti;
char id[20], pw[20];
int point;
int life;
int level;
char idch[20], pwch[20];
char name[100];
unsigned long long pmul;

struct Pos
{
	int x;
	int y;
};

void gotoxy(int x, int y);
BOOL CtrlHandler(DWORD fdwCtrlType); //X버튼 등 종료 확인
void CursorView_F(); //커서 숨김
void CursorView_T(); //커서 보임
void setup();
void shop();
void play();
void F5();
void mainplay();
void finish();
void finish2();
void gameend();

int main()
{
	system("mode con cols=61 lines=34"); //콘솔 화면 크기
	system("color 07"); //콘솔 화면 색상(검정, 기본 값)
	system("title § MOVING TRIANGLE §"); //콘솔 창 제목
	CursorView_F(); //커서 숨김
	srand((unsigned)time(NULL));
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE); //X버튼 등 종료 확인
	FILE* fp;
	fp = fopen("Score.txt", "r");
	char ch[100];
	int log_in = 0;
	if (fp != NULL)
	{
		fgets(idch, sizeof(idch), fp);
		fgets(pwch, sizeof(pwch), fp);
		fgets(name, sizeof(name), fp);
		fgets(ch, sizeof(ch), fp);
		point = atoi(ch);
		fgets(ch, sizeof(ch), fp);
		pmul = atoi(ch);
		fgets(ch, sizeof(ch), fp);
		life = atoi(ch);
		fgets(ch, sizeof(ch), fp);
		anti = atoi(ch);
		fgets(ch, sizeof(ch), fp);
		color = atoi(ch);
		fgets(ch, sizeof(ch), fp);
		ab = atoi(ch);
		fclose(fp);
	}
	else
	{
		point = 0;
		pmul = 1;
		life = 0;
		anti = 0;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		main();
	}
	a = 0;
	for (int iii = 0; iii < 5; iii++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoxy(0, 10);
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("\n                                             [Made by DH.L]\n");
			if (j == 0)
			{
				puts("                           LOADING △");
			}
			else if (j == 1)
			{
				puts("                           LOADING ▷");
			}
			else if (j == 2)
			{
				puts("                           LOADING ▽");
			}
			else if (j == 3)
			{
				puts("                           LOADING ◁");
			}
			if (GetAsyncKeyState(VK_F5))
			{
				FILE* fp;
				char ch[20];
				fp = fopen("Score.txt", "w");
				strcat(id, "\n");
				fputs(id, fp);
				strcat(pw, "\n");
				fputs(pw, fp);
				strcat(name, "\n");
				fputs(name, fp);
				itoa(point, ch, 10);
				strcat(ch, "\n");
				fputs(ch, fp);
				itoa(pmul, ch, 10);
				strcat(ch, "\n");
				fputs(ch, fp);
				itoa(life, ch, 10);
				strcat(ch, "\n");
				fputs(ch, fp);
				itoa(anti, ch, 10);
				strcat(ch, "\n");
				fputs(ch, fp);
				itoa(color, ch, 10);
				strcat(ch, "\n");
				fputs(ch, fp);
				itoa(ab, ch, 10);
				strcat(ch, "\n");
				fputs(ch, fp);
				fclose(fp);
				main();
			}
			Sleep(100);
		}
	}
	while (1) //선택 알고리즘
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			log_in++;
			if (log_in > 1)
				log_in = 0;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			log_in--;
			if (log_in < 0)
				log_in = 1;
		}
		if (GetAsyncKeyState(VK_F5))
		{
			F5();
		}
		Sleep(50);
		system("cls");
		switch (log_in)
		{
		case 0:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("              화살표 키를 이용하여 조작하세요.\n");
			puts("                    Enter로 선택하세요.\n");
			puts("                         】로그인【\n");
			puts("                           만들기");
			break;
		case 1:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("              화살표 키를 이용하여 조작하세요.\n");
			puts("                    Enter로 선택하세요.\n");
			puts("                           로그인\n");
			puts("                         】만들기【");
			break;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			rewind(stdin);
			break;
		}
	}
	if (log_in == 0)
	{
		int cnt = 0;
		while (1) //로그인
		{
			while (kbhit()) //키 입력 초기화
				getch();
			CursorView_T();
			system("cls");
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("                          <로그인>\n");
			printf("                         ID: ");
			rewind(stdin);
			scanf("%s", id);
			printf("                         PW: ");
			scanf("%s", pw);
			strcat(id, "\n");
			strcat(pw, "\n");
			CursorView_F();
			if (strcmp(id, idch) == 0 && strcmp(pw, pwch) == 0) //옳은 경우
			{
				puts("로그인 되었습니다.");
				Sleep(500);
				system("cls");
				puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
				printf("환영합니다, %s", name);
				Sleep(1000);
				break;
			}
			else //틀릴 경우
			{
				if (strcmp(id, idch) != 0 && strcmp(pw, pwch) != 0)
				{
					puts("잘못된 ID와 PW입니다. 다시 입력해주세요.");
				}
				else if (strcmp(id, idch) != 0)
				{
					puts("잘못된 ID입니다. 다시 입력해주세요.");
				}
				else if (strcmp(pw, pwch) != 0)
				{
					puts("잘못된 PW입니다. 다시 입력해주세요.");
				}
				cnt++;
				if (cnt == 5)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X버튼 비활성화
					DrawMenuBar(GetConsoleWindow());
					puts("5회 틀렸습니다. 30초 후에 시도해주세요.\n");
					Sleep(30000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X버튼 활성화
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt == 10)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X버튼 비활성화
					DrawMenuBar(GetConsoleWindow());
					puts("10회 틀렸습니다. 1분 후에 시도해주세요.");
					Sleep(60000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X버튼 활성화
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt == 15)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X버튼 비활성화
					DrawMenuBar(GetConsoleWindow());
					puts("15회 틀렸습니다. 2분 후에 시도해주세요.");
					Sleep(120000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X버튼 활성화
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt > 15 && cnt < 20)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X버튼 비활성화
					DrawMenuBar(GetConsoleWindow());
					printf("%d회 틀렸습니다. 5분 후에 시도해 주세요.\n", cnt);
					Sleep(300000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X버튼 활성화
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt == 20)
				{
					puts("20회 틀렸습니다. 프로그램이 종료됩니다.");
					Sleep(750);
					system("cls");
					exit(0);
				}
				Sleep(500);
			}
		}
	}
	if (log_in == 1) //계정 생성
	{
		CursorView_T();
		while (kbhit())
			getch();
		system("cls");
		puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
		puts("                          <만들기>\n");
		printf("                     ID를 입력하시오: ");
		scanf("%s", id);
		Sleep(50);
		printf("                     PW를 입력하시오: ");
		scanf("%s", pw);
		Sleep(50);
		printf("                    닉네임을 입력하시오: ");
		scanf("%s", name);
		Sleep(50);
		CursorView_F();
		puts("계정 정보가 저장되었습니다.");
		Sleep(500);
		FILE* fp;
		char ch[20];
		fp = fopen("Score.txt", "w");
		strcat(id, "\n");
		fputs(id, fp);
		strcat(pw, "\n");
		fputs(pw, fp);
		strcat(name, "\n");
		fputs(name, fp);
		itoa(point, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(pmul, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(life, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(anti, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(color, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(ab, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		fclose(fp);
		main();
	}
	switch (color) //콘솔 색상 설정(파일 입력, 사용자 설정)
	{
	case 1:
		system("color 07");
		break;
	case 2:
		system("color 16");
		break;
	case 3:
		system("color 25");
		break;
	case 4:
		system("color 34");
		break;
	case 5:
		system("color 43");
		break;
	case 6:
		system("color 52");
		break;
	case 7:
		system("color 61");
		break;
	case 8:
		system("color 70");
		break;
	case 9:
		system("color 80");
		break;
	}
	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //음악 재생
	play();
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView_F()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void CursorView_T()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
	case CTRL_BREAK_EVENT:
	default:
		PlaySound(NULL, 0, 0);
		MessageBox(NULL, L"종료됩니다.", L"MOVING TRIANGLE", MB_OK | MB_ICONINFORMATION); //알림창, 확인
		FILE* fp;
		char ch[20];
		fp = fopen("Score.txt", "w");
		fputs(id, fp);
		fputs(pw, fp);
		fputs(name, fp);
		itoa(point, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(pmul, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(life, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(anti, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(color, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(ab, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		fclose(fp);
	}
	return FALSE;
}

bool cal = true;
void play()
{
	sc = 0;
	sc1 = 0;
	sc2 = 0;

	if (cal == true && GetAsyncKeyState(VK_RETURN))
	{
		cal = false;
		play();
	}
	cal = true;
	while (1)
	{
		if (GetAsyncKeyState(VK_DOWN))
		{
			a++;
			if (a > 4)
				a = 0;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			a--;
			if (a < 0)
				a = 4;
		}
		if (GetAsyncKeyState(VK_F5))
		{
			F5();
		}
		Sleep(50);
		system("cls");
		switch (a)
		{
		case 0:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts(name);
			puts("                       】 게임 시작 【\n");
			puts("                            설 정\n");
			puts("                            설 명\n");
			puts("                         포인트 상점\n");
			puts("                          게임 종료");
			break;
		case 1:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts(name);
			puts("                          게임 시작\n");
			puts("                       】   설 정   【\n ");
			puts("                            설 명\n");
			puts("                         포인트 상점\n");
			puts("                          게임 종료");
			break;
		case 2:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts(name);
			puts("                          게임 시작\n");
			puts("                            설 정\n");
			puts("                       】   설 명   【\n");
			puts("                         포인트 상점\n");
			puts("                          게임 종료");
			break;
		case 3:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts(name);
			puts("                          게임 시작\n");
			puts("                            설 정\n");
			puts("                            설 명\n");
			puts("                       】포인트 상점【\n");
			puts("                          게임 종료");
			break;
		case 4:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts(name);
			puts("                          게임 시작\n");
			puts("                            설 정\n");
			puts("                            설 명\n");
			puts("                         포인트 상점\n");
			puts("                       】 게임 종료 【");
			break;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(70);
			break;
		}
	}
	if (a == 0)
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				ss--;
				if (ss < 0)
				{
					ss = 1;
				}
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				ss++;
				if (ss > 1)
				{
					ss = 0;
				}
			}
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				play();
			}
			Sleep(50);
			system("cls");
			if (ss == 0)
			{
				puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
				puts("                       】1인 플레이【\n");
				puts("                         2인 플레이\n");
				puts("         [2인 플레이]는 포인트 / 아이템 적용 없음");
			}
			if (ss == 1)
			{
				puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
				puts("                         1인 플레이\n");
				puts("                       】2인 플레이【\n");
				puts("         [2인 플레이]는 포인트 / 아이템 적용 없음");
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				Sleep(50);
				break;
			}
		}
		ii = 0;
		while (ii < 2)
		{
			system("cls");
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			printf("\n\n게임 로딩 중");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".");
			Sleep(500);
			ii++;
		}
		system("cls");
		mainplay();
	}
	if (a == 1)
	{
		setup();
	}
	if (a == 2)
	{
		system("cls");
		puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
		puts("                       ● : 먹이(5점)\n");
		puts("                       ♪ : 먹이(20점)\n");
		puts("                       ◎ : 포탈(반대 포탈로 이동)\n");
		puts("                       ◐ : 독 먹이(-10 / -20점)\n");
		puts("                     △");
		puts("                   ◁▽▷, W, A, S, D : MOVE\n");
		puts("                      Esc : GO TO MAIN\n");
		puts("                        F5 : REFRESH\n");
		puts("                       ENTER : SELECT\n");
		puts("                    벽에 닿으면 게임 오버\n");
		puts("\n\n\n                    나가려면 Space Bar...");
		while (1)
		{
			if (GetAsyncKeyState(VK_SPACE))
			{
				play();
			}
		}
	}
	if (a == 3)
	{
		shop();

	}
	if (a == 4)
	{
		gameend();
	}
	play();
}

void F5()
{
	if (IDYES == MessageBox(NULL, L"새로고침 하시겠습니까?", L"MOVING TRIANGLE", MB_YESNO | MB_ICONQUESTION)) //알림창('예'를 누를 경우 새로고침 됨.)
	{
		PlaySound(NULL, 0, 0); //음악 재생 멈춤
		FILE* fp; //파일 입력 ↓
		char ch[20];
		fp = fopen("Score.txt", "w");
		strcat(id, "\n");
		fputs(id, fp);
		strcat(pw, "\n");
		fputs(pw, fp);
		strcat(name, "\n");
		fputs(name, fp);
		itoa(point, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(pmul, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(life, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(anti, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(color, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		itoa(ab, ch, 10);
		strcat(ch, "\n");
		fputs(ch, fp);
		fclose(fp);
		main();
	}
}

void setup()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			d--;
			if (d < 0)
				d = 2;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			d++;
			if (d > 2)
				d = 0;
		}
		if (GetAsyncKeyState(VK_F5))
		{
			F5();
		}
		Sleep(50);
		system("cls");
		if (d == 0)
		{
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
			puts("                       】캐릭터 설정【\n");
			puts("                         테마 색 설정\n");
			puts("                         설정   완료");
		}
		if (d == 1)
		{
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
			puts("                         캐릭터 설정\n");
			puts("                       】테마 색 설정【\n");
			puts("                         설정   완료");
		}
		if (d == 2)
		{
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
			puts("                         캐릭터 설정\n");
			puts("                         테마 색 설정\n");
			puts("                       】설정   완료【");
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(50);
			break;
		}
	}
	if (d == 0)
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				j--;
				if (j < 0)
				{
					j = 1;
				}
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				j++;
				if (j > 1)
				{
					j = 0;
				}
			}
			Sleep(50);
			system("cls");
			switch (j)
			{
			case 0:
				puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
				puts("                            】▲【\n");
				puts("                              △\n");
				ab = 1;
				break;
			case 1:
				puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
				puts("                              ▲\n");
				puts("                            】△【\n");
				ab = 2;
				break;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				Sleep(50);
				break;
			}
		}
		setup();
	}
	if (d == 1)
	{
		while (1)
		{
			if (GetAsyncKeyState(VK_DOWN))
			{
				e++;
				if (e > 2)
				{
					e = 0;
				}
			}
			if (GetAsyncKeyState(VK_UP))
			{
				e--;
				if (e < 0)
				{
					e = 2;
				}
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				f++;
				if (f > 2)
				{
					f = 0;
					e++;
					if (e > 2)
					{
						e = 0;

					}
				}
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				f--;
				if (f < 0)
				{
					f = 2;
					e--;
					if (e < 0)
					{
						e = 2;
					}
				}
			}
			Sleep(50);
			system("cls");
			switch (e)
			{
			case 0:
				switch (f)
				{
				case 0:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("        】검은색【           파란색             녹  색\n");
					puts("          청록색             빨간색             자주색\n");
					puts("          노란색             흰  색             회  색\n");
					color = 1;
					break;
				case 1:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색           】파란색【           녹  색\n");
					puts("          청록색             빨간색             자주색\n");
					puts("          노란색             흰  색             회  색\n");
					color = 2;
					break;
				case 2:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색           】녹  색【\n");
					puts("          청록색             빨간색             자주색\n");
					puts("          노란색             흰  색             회  색\n");
					color = 3;
					break;
				}
				break;
			case 1:
				switch (f)
				{
				case 0:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색             녹  색\n");
					puts("        】청록색【           빨간색             자주색\n");
					puts("          노란색             흰  색             회  색\n");
					color = 4;
					break;
				case 1:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색             녹  색\n");
					puts("          청록색           】빨간색【           자주색\n");
					puts("          노란색             흰  색             회  색\n");
					color = 5;
					break;
				case 2:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색             녹  색\n");
					puts("          청록색             빨간색           】자주색【\n");
					puts("          노란색             흰  색             회  색\n");
					color = 6;
					break;
				}
				break;
			case 2:
				switch (f)
				{
				case 0:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색             녹  색\n");
					puts("          청록색             빨간색             자주색\n");
					puts("        】노란색【           흰  색             회  색\n");
					color = 7;
					break;
				case 1:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색             녹  색\n");
					puts("          청록색             빨간색             자주색\n");
					puts("          노란색           】흰  색【           회  색\n");
					color = 8;
					break;
				case 2:
					puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
					puts("          검은색             파란색             녹  색\n");
					puts("          청록색             빨간색             자주색\n");
					puts("          노란색             흰  색           】회  색【\n");
					color = 9;
					break;
				}
				break;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				Sleep(50);
				switch (color)
				{
				case 1:
					system("color 07");
					break;
				case 2:
					system("color 16");
					break;
				case 3:
					system("color 25");
					break;
				case 4:
					system("color 34");
					break;
				case 5:
					system("color 43");
					break;
				case 6:
					system("color 52");
					break;
				case 7:
					system("color 61");
					break;
				case 8:
					system("color 70");
					break;
				case 9:
					system("color 80");
					break;
				}
				setup();
			}
		}
	}
	if (d == 2)
	{
		system("cls");
		puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
		puts("설정이 완료되었습니다...");
		Sleep(1000);
		play();
	}
}

void mainplay()
{
	struct Pos xy[11];
	int speed = 100;
	if (ss == 0)
	{
		xy[1].x = 29;
		xy[1].y = 16;
		xy[2].x = 29;
		xy[2].y = 21;
		xy[3].x = 29;
		xy[3].y = 11;
		xy[4].x = 39;
		xy[4].y = 16;
		xy[5].x = 19;
		xy[5].y = 16;
		xy[6].x = 39;
		xy[6].y = 11;
		xy[7].x = 19;
		xy[7].y = 21;
		xy[8].x = 19;
		xy[8].y = 11;
		xy[9].x = 39;
		xy[9].y = 21;
		xy6 = 0;
		while (1)
		{
			level = sc / 50 + 1;
			speed = (10 - (level - 1)) * 10;
			if (speed <= 0)
			{
				speed = 1;
			}
			xy6++;
			if (GetAsyncKeyState(VK_UP))
			{
				i = 0;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				i = 1;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				i = 2;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				i = 3;
			}
			if (GetAsyncKeyState(VK_F5))
			{
				F5();
			}
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				while (1)
				{
					system("cls");
					if (GetAsyncKeyState(VK_UP))
					{
						aa--;
						if (aa < 0)
						{
							aa = 1;
						}
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						aa++;
						if (aa > 1)
						{
							aa = 0;
						}
					}
					if (aa == 0)
					{
						puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
						puts("                         】계속하기【\n");
						puts("                           메인으로");
					}
					if (aa == 1)
					{
						puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
						puts("                           계속하기\n");
						puts("                         】메인으로【");
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						Sleep(50);
						break;
					}
				}
				if (aa == 1)
				{
					finish();
				}
			}
			system("cls");
			gotoxy(0, 0);
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■");
			printf("score : %d    |    LEVEL : %d\n", sc, level);
			puts("\n+-----------------------------------------------------------+");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("+-----------------------------------------------------------+");
			gotoxy(xy[2].x, xy[2].y);
			puts("●");
			gotoxy(xy[3].x, xy[3].y);
			puts("●");
			gotoxy(xy[4].x, xy[4].y);
			puts("♪");
			gotoxy(xy[5].x, xy[5].y);
			puts("●");
			gotoxy(xy[6].x, xy[6].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("◐");
			}
			if (xy6 == 1)
			{
				puts("◑");
			}
			gotoxy(xy[7].x, xy[7].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("◐");
			}
			if (xy6 == 1)
			{
				puts("◑");
			}
			gotoxy(xy[8].x, xy[8].y);
			if (xy6 == 0)
			{
				puts("◎");
			}
			if (xy6 == 1)
			{
				puts("⊙");
			}
			gotoxy(xy[9].x, xy[9].y);
			if (xy6 == 0)
			{
				puts("◎");
			}
			if (xy6 == 1)
			{
				puts("⊙");
			}
			switch (i)
			{
			case 0:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("▲");
				if (ab == 2)
					puts("△");
				Sleep(speed);
				xy[1].y--;
				if (xy[1].y < 5)
				{
					if (life == 0)
					{
						finish();
					}
					else
					{
						life--;
						i += 2;
						if (i > 3)
						{
							i = i + i - 3;
						}
					}
				}
				break;
			case 1:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("▼");
				if (ab == 2)
					puts("▽");
				Sleep(speed);
				xy[1].y++;
				if (xy[1].y > 29)
				{
					if (life == 0)
					{
						finish();
					}
					else
					{
						life--;
						i += 2;
						if (i > 3)
						{
							i = i + i - 3;
						}
					}
				}
				break;
			case 2:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("▶");
				if (ab == 2)
					puts("▷");
				Sleep(speed / 2);
				xy[1].x++;
				if (xy[1].x > 58)
				{
					if (life == 0)
					{
						finish();
					}
					else
					{
						life--;
						i += 2;
						if (i > 3)
						{
							i = i + i - 3;
						}
					}
				}
				break;
			case 3:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("◀");
				if (ab == 2)
					puts("◁");
				Sleep(speed / 2);
				xy[1].x--;
				if (xy[1].x < 1)
				{
					if (life == 0)
					{
						finish();
					}
					else
					{
						life--;
						i += 2;
						if (i > 3)
						{
							i = i + i - 3;
						}
					}
				}
				break;
			}
			if (xy[1].x == xy[2].x && xy[1].y == xy[2].y)
			{
				sc += 5;
				while (1)
				{
					xy[2].x = (rand() % 58) + 1;
					xy[2].y = (rand() % 24) + 5;
					if (xy[1].x != xy[2].x && xy[1].y != xy[2].y)
						break;
				}
			}
			if (xy[1].x == xy[3].x && xy[1].y == xy[3].y)
			{
				sc += 5;
				while (1)
				{
					xy[3].x = (rand() % 58) + 1;
					xy[3].y = (rand() % 24) + 5;
					if (xy[1].x != xy[3].x && xy[1].y != xy[3].y)
						break;
				}
			}
			if (xy[1].x == xy[4].x && xy[1].y == xy[4].y)
			{
				sc += 20;
				while (1)
				{
					xy[4].x = (rand() % 58) + 1;
					xy[4].y = (rand() % 24) + 5;
					if (xy[1].x != xy[4].x && xy[1].y != xy[4].y)
						break;
				}
			}
			if (xy[1].x == xy[5].x && xy[1].y == xy[5].y)
			{
				sc += 5;
				while (1)
				{
					xy[5].x = (rand() % 58) + 1;
					xy[5].y = (rand() % 24) + 5;
					if (xy[1].x != xy[5].x && xy[1].y != xy[5].y)
						break;
				}
			}
			if (xy[1].x == xy[6].x && xy[1].y == xy[6].y)
			{
				if (anti == 1)
				{
					sc -= 5;
				}
				else
				{
					sc -= 10;
				}
				while (1)
				{
					xy[6].x = (rand() % 58) + 1;
					xy[6].y = (rand() % 24) + 5;
					if (xy[1].x != xy[6].x && xy[1].y != xy[6].y)
						break;
				}
			}
			if (xy[1].x == xy[7].x && xy[1].y == xy[7].y)
			{
				if (anti == 1)
				{
					sc -= 10;
				}
				else
				{
					sc -= 20;
				}
				while (1)
				{
					xy[7].x = (rand() % 58) + 1;
					xy[7].y = (rand() % 24) + 5;
					if (xy[1].x != xy[7].x && xy[1].y != xy[7].y)
						break;
				}
			}
			if (xy[1].x == xy[8].x && xy[1].y == xy[8].y)
			{
				if (i == 0)
				{
					xy[1].x = xy[9].x;
					xy[1].y = xy[9].y - 1;
				}
				if (i == 1)
				{
					xy[1].x = xy[9].x;
					xy[1].y = xy[9].y + 1;
				}
				if (i == 2)
				{
					xy[1].x = xy[9].x + 1;
					xy[1].y = xy[9].y;
				}
				if (i == 3)
				{
					xy[1].x = xy[9].x - 1;
					xy[1].y = xy[9].y;
				}
				while (1)
				{
					xy[8].x = (rand() % 58) + 1;
					xy[8].y = (rand() % 24) + 5;
					if (xy[1].x != xy[8].x && xy[1].y != xy[8].y)
						break;
				}
			}
			if (xy[1].x == xy[9].x && xy[1].y == xy[9].y)
			{
				if (i == 0)
				{
					xy[1].x = xy[8].x;
					xy[1].y = xy[8].y - 1;
				}
				if (i == 1)
				{
					xy[1].x = xy[8].x;
					xy[1].y = xy[8].y + 1;
				}
				if (i == 2)
				{
					xy[1].x = xy[8].x + 1;
					xy[1].y = xy[8].y;
				}
				if (i == 3)
				{
					xy[1].x = xy[8].x - 1;
					xy[1].y = xy[8].y;
				}
				while (1)
				{
					xy[9].x = (rand() % 58) + 1;
					xy[9].y = (rand() % 24) + 5;
					if (xy[1].x != xy[9].x && xy[1].y != xy[9].y)
						break;
				}
			}
		}
	}
	if (ss == 1)
	{
		xy[10].x = 29;
		xy[10].y = 16;
		xy[2].x = 29;
		xy[2].y = 21;
		xy[3].x = 29;
		xy[3].y = 11;
		xy[4].x = 39;
		xy[4].y = 16;
		xy[5].x = 19;
		xy[5].y = 16;
		xy[6].x = 39;
		xy[6].y = 11;
		xy[7].x = 19;
		xy[7].y = 21;
		xy[8].x = 19;
		xy[8].y = 11;
		xy[9].x = 39;
		xy[9].y = 21;
		xy[1].x = 49;
		xy[1].y = 16;
		xy[0].x = 9;
		xy[0].y = 16;
		xy6 = 0;
		while (1)
		{
			xy6++;
			if (GetAsyncKeyState(VK_UP))
			{
				i = 0;
			}
			if (GetAsyncKeyState(VK_DOWN))
			{
				i = 1;
			}
			if (GetAsyncKeyState(VK_RIGHT))
			{
				i = 2;
			}
			if (GetAsyncKeyState(VK_LEFT))
			{
				i = 3;
			}
			if (GetAsyncKeyState(0x57))
			{
				i2 = 0;
			}
			if (GetAsyncKeyState(0x53))
			{
				i2 = 1;
			}
			if (GetAsyncKeyState(0x44))
			{
				i2 = 2;
			}
			if (GetAsyncKeyState(0x41))
			{
				i2 = 3;
			}
			if (GetAsyncKeyState(VK_F5))
			{
				F5();
			}
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				while (1)
				{
					system("cls");
					if (GetAsyncKeyState(VK_UP))
					{
						aa--;
						if (aa < 0)
						{
							aa = 1;
						}
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						aa++;
						if (aa > 1)
						{
							aa = 0;
						}
					}
					if (aa == 0)
					{
						puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
						puts("                         】계속하기【\n");
						puts("                           메인으로");
					}
					if (aa == 1)
					{
						puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
						puts("                           계속하기\n");
						puts("                         】메인으로【");
					}
					if (GetAsyncKeyState(VK_RETURN))
					{
						Sleep(50);
						break;
					}
				}
				if (aa == 1)
				{
					finish2();
				}
			}
			system("cls");
			gotoxy(0, 0);
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■");
			printf("player 1 score : %d / player 2 score : %d\n", sc1, sc2);
			puts("\n+-----------------------------------------------------------+");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("|                                                                                                                        |");
			puts("+-----------------------------------------------------------+");
			gotoxy(xy[2].x, xy[2].y);
			puts("●");
			gotoxy(xy[3].x, xy[3].y);
			puts("●");
			gotoxy(xy[10].x, xy[10].y);
			puts("♪");
			gotoxy(xy[4].x, xy[4].y);
			puts("●");
			gotoxy(xy[5].x, xy[5].y);
			puts("●");
			gotoxy(xy[6].x, xy[6].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("◐");
			}
			if (xy6 == 1)
			{
				puts("◑");
			}
			gotoxy(xy[7].x, xy[7].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("◐");
			}
			if (xy6 == 1)
			{
				puts("◑");
			}
			gotoxy(xy[8].x, xy[8].y);
			if (xy6 == 0)
			{
				puts("◎");
			}
			if (xy6 == 1)
			{
				puts("⊙");
			}
			gotoxy(xy[9].x, xy[9].y);
			if (xy6 == 0)
			{
				puts("◎");
			}
			if (xy6 == 1)
			{
				puts("⊙");
			}
			switch (i)
			{
			case 0:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("▲");
				if (ab == 2)
					puts("△");
				xy[1].y--;
				if (xy[1].y < 5)
				{
					i = 1;
				}
				break;
			case 1:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("▼");
				if (ab == 2)
					puts("▽");
				xy[1].y++;
				if (xy[1].y > 28)
				{
					i = 0;
				}
				break;
			case 2:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("▶");
				if (ab == 2)
					puts("▷");
				xy[1].x++;
				if (xy[1].x > 58)
				{
					i = 3;
				}
				break;
			case 3:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("◀");
				if (ab == 2)
					puts("◁");
				xy[1].x--;
				if (xy[1].x < 1)
				{
					i = 2;
				}
				break;
			}
			switch (i2)
			{
			case 0:
				gotoxy(xy[0].x, xy[0].y);
				if (ab == 1)
					puts("▲");
				if (ab == 2)
					puts("△");
				Sleep(100);
				xy[0].y--;
				if (xy[0].y < 5)
				{
					i2 = 1;
				}
				break;
			case 1:
				gotoxy(xy[0].x, xy[0].y);
				if (ab == 1)
					puts("▼");
				if (ab == 2)
					puts("▽");
				Sleep(100);
				xy[0].y++;
				if (xy[0].y > 28)
				{
					i2 = 0;
				}
				break;
			case 2:
				gotoxy(xy[0].x, xy[0].y);
				if (ab == 1)
					puts("▶");
				if (ab == 2)
					puts("▷");
				Sleep(50);
				xy[0].x++;
				if (xy[0].x > 58)
				{
					i2 = 3;
				}
				break;
			case 3:
				gotoxy(xy[0].x, xy[0].y);
				if (ab == 1)
					puts("◀");
				if (ab == 2)
					puts("◁");
				Sleep(50);
				xy[0].x--;
				if (xy[0].x < 1)
				{
					i2 = 2;
				}
				break;
			}
			if (xy[1].x == xy[2].x && xy[1].y == xy[2].y)
			{
				sc1 += 5;
				while (1)
				{
					xy[2].x = (rand() % 58) + 1;
					xy[2].y = (rand() % 24) + 5;
					if (xy[1].x != xy[2].x && xy[1].y != xy[2].y && xy[0].x != xy[2].x && xy[0].y != xy[2].x)
						break;
				}
			}
			if (xy[1].x == xy[3].x && xy[1].y == xy[3].y)
			{
				sc1 += 5;
				while (1)
				{
					xy[3].x = (rand() % 58) + 1;
					xy[3].y = (rand() % 24) + 5;
					if (xy[1].x != xy[3].x && xy[1].y != xy[3].y && xy[0].x != xy[3].x && xy[0].y != xy[3].x)
						break;
				}
			}
			if (xy[1].x == xy[4].x && xy[1].y == xy[4].y)
			{
				sc1 += 5;
				while (1)
				{
					xy[4].x = (rand() % 58) + 1;
					xy[4].y = (rand() % 24) + 5;
					if (xy[1].x != xy[4].x && xy[1].y != xy[4].y && xy[0].x != xy[4].x && xy[0].y != xy[4].x)
						break;
				}
			}
			if (xy[1].x == xy[5].x && xy[1].y == xy[5].y)
			{
				sc1 += 5;
				while (1)
				{
					xy[5].x = (rand() % 58) + 1;
					xy[5].y = (rand() % 24) + 5;
					if (xy[1].x != xy[5].x && xy[1].y != xy[5].y && xy[0].x != xy[5].x && xy[0].y != xy[5].x)
						break;
				}
			}
			if (xy[1].x == xy[6].x && xy[1].y == xy[6].y)
			{
				sc1 -= 10;
				while (1)
				{
					xy[6].x = (rand() % 58) + 1;
					xy[6].y = (rand() % 24) + 5;
					if (xy[1].x != xy[6].x && xy[1].y != xy[6].y && xy[0].x != xy[6].x && xy[0].y != xy[6].x)
						break;
				}
			}
			if (xy[1].x == xy[7].x && xy[1].y == xy[7].y)
			{
				sc1 -= 20;
				while (1)
				{
					xy[7].x = (rand() % 58) + 1;
					xy[7].y = (rand() % 24) + 5;
					if (xy[1].x != xy[7].x && xy[1].y != xy[7].y && xy[0].x != xy[7].x && xy[0].y != xy[7].x)
						break;
				}
			}
			if (xy[1].x == xy[8].x && xy[1].y == xy[8].y)
			{
				if (i == 0)
				{
					xy[1].x = xy[9].x;
					xy[1].y = xy[9].y - 1;
				}
				if (i == 1)
				{
					xy[1].x = xy[9].x;
					xy[1].y = xy[9].y + 1;
				}
				if (i == 2)
				{
					xy[1].x = xy[9].x + 1;
					xy[1].y = xy[9].y;
				}
				if (i == 3)
				{
					xy[1].x = xy[9].x - 1;
					xy[1].y = xy[9].y;
				}
				while (1)
				{
					xy[8].x = (rand() % 58) + 1;
					xy[8].y = (rand() % 24) + 5;
					if (xy[1].x != xy[8].x && xy[1].y != xy[8].y && xy[0].x != xy[8].x && xy[0].y != xy[8].x)
						break;
				}
			}
			if (xy[1].x == xy[9].x && xy[1].y == xy[9].y)
			{
				if (i == 0)
				{
					xy[1].x = xy[8].x;
					xy[1].y = xy[8].y - 1;
				}
				if (i == 1)
				{
					xy[1].x = xy[8].x;
					xy[1].y = xy[8].y + 1;
				}
				if (i == 2)
				{
					xy[1].x = xy[8].x + 1;
					xy[1].y = xy[8].y;
				}
				if (i == 3)
				{
					xy[1].x = xy[8].x - 1;
					xy[1].y = xy[8].y;
				}
				while (1)
				{
					xy[9].x = (rand() % 58) + 1;
					xy[9].y = (rand() % 24) + 5;
					if (xy[1].x != xy[9].x && xy[1].y != xy[9].y && xy[0].x != xy[9].x && xy[0].y != xy[9].x)
						break;
				}
			}
			if (xy[1].x == xy[10].x && xy[1].y == xy[10].y)
			{
				sc1 += 20;
				while (1)
				{
					xy[10].x = (rand() % 58) + 1;
					xy[10].y = (rand() % 24) + 5;
					if (xy[1].x != xy[10].x && xy[1].y != xy[10].y && xy[0].x != xy[10].x && xy[0].y != xy[10].x)
						break;
				}
			}
			if (xy[0].x == xy[2].x && xy[0].y == xy[2].y)
			{
				sc2 += 5;
				while (1)
				{
					xy[2].x = (rand() % 58) + 1;
					xy[2].y = (rand() % 24) + 5;
					if (xy[1].x != xy[2].x && xy[1].y != xy[2].y && xy[0].x != xy[2].x && xy[0].y != xy[2].x)
						break;
				}
			}
			if (xy[0].x == xy[3].x && xy[0].y == xy[3].y)
			{
				sc2 += 5;
				while (1)
				{
					xy[3].x = (rand() % 58) + 1;
					xy[3].y = (rand() % 24) + 5;
					if (xy[1].x != xy[3].x && xy[1].y != xy[3].y && xy[0].x != xy[3].x && xy[0].y != xy[3].x)
						break;
				}
			}
			if (xy[0].x == xy[4].x && xy[0].y == xy[4].y)
			{
				sc2 += 5;
				while (1)
				{
					xy[4].x = (rand() % 58) + 1;
					xy[4].y = (rand() % 24) + 5;
					if (xy[1].x != xy[4].x && xy[1].y != xy[4].y && xy[0].x != xy[4].x && xy[0].y != xy[4].x)
						break;
				}
			}
			if (xy[0].x == xy[5].x && xy[0].y == xy[5].y)
			{
				sc2 += 5;
				while (1)
				{
					xy[5].x = (rand() % 58) + 1;
					xy[5].y = (rand() % 24) + 5;
					if (xy[1].x != xy[5].x && xy[1].y != xy[5].y && xy[0].x != xy[5].x && xy[0].y != xy[5].x)
						break;
				}
			}
			if (xy[0].x == xy[6].x && xy[0].y == xy[6].y)
			{
				sc2 -= 10;
				while (1)
				{
					xy[6].x = (rand() % 58) + 1;
					xy[6].y = (rand() % 24) + 5;
					if (xy[1].x != xy[6].x && xy[1].y != xy[6].y && xy[0].x != xy[6].x && xy[0].y != xy[6].x)
						break;
				}
			}
			if (xy[0].x == xy[7].x && xy[0].y == xy[7].y)
			{
				sc2 -= 20;
				while (1)
				{
					xy[7].x = (rand() % 58) + 1;
					xy[7].y = (rand() % 24) + 5;
					if (xy[1].x != xy[7].x && xy[1].y != xy[7].y && xy[0].x != xy[7].x && xy[0].y != xy[7].x)
						break;
				}
			}
			if (xy[0].x == xy[8].x && xy[0].y == xy[8].y)
			{
				if (i == 0)
				{
					xy[0].x = xy[9].x;
					xy[0].y = xy[9].y - 1;
				}
				if (i == 1)
				{
					xy[0].x = xy[9].x;
					xy[0].y = xy[9].y + 1;
				}
				if (i == 2)
				{
					xy[0].x = xy[9].x + 1;
					xy[0].y = xy[9].y;
				}
				if (i == 3)
				{
					xy[0].x = xy[9].x - 1;
					xy[0].y = xy[9].y;
				}
				while (1)
				{
					xy[8].x = (rand() % 58) + 1;
					xy[8].y = (rand() % 24) + 5;
					if (xy[1].x != xy[8].x && xy[1].y != xy[8].y && xy[0].x != xy[8].x && xy[0].y != xy[8].x)
						break;
				}
			}
			if (xy[0].x == xy[9].x && xy[0].y == xy[9].y)
			{
				if (i == 0)
				{
					xy[0].x = xy[8].x;
					xy[0].y = xy[8].y - 1;
				}
				if (i == 1)
				{
					xy[0].x = xy[8].x;
					xy[0].y = xy[8].y + 1;
				}
				if (i == 2)
				{
					xy[0].x = xy[8].x + 1;
					xy[0].y = xy[8].y;
				}
				if (i == 3)
				{
					xy[0].x = xy[8].x - 1;
					xy[0].y = xy[8].y;
				}
				while (1)
				{
					xy[9].x = (rand() % 58) + 1;
					xy[9].y = (rand() % 24) + 5;
					if (xy[1].x != xy[9].x && xy[1].y != xy[9].y && xy[0].x != xy[9].x && xy[0].y != xy[9].x)
						break;
				}
			}
			if (xy[0].x == xy[10].x && xy[0].y == xy[10].y)
			{
				sc2 += 20;
				while (1)
				{
					xy[10].x = (rand() % 58) + 1;
					xy[10].y = (rand() % 24) + 5;
					if (xy[1].x != xy[10].x && xy[1].y != xy[10].y && xy[0].x != xy[10].x && xy[0].y != xy[10].x)
						break;
				}
			}
			if (sc1 >= 100 || sc2 >= 100)
			{
				finish2();
			}
		}
	}
}

void finish()
{
	system("cls");
	gotoxy(0, 0);
	puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
	puts("                          Game Over\n");
	printf("                          score: %d\n\n", sc);
	printf("                          LEVEL : %d\n\n\n", level);
	puts("                     계속하려면 Space Bar...");
	sc *= pmul;
	point += sc;
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			Sleep(50);
			play();
		}
		if (GetAsyncKeyState(VK_F5))
		{
			F5();
		}
	}
}

void finish2()
{
	system("cls");
	gotoxy(0, 0);
	puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
	puts("                          Game Over\n");
	printf("                      Player 1 score: %d\n", sc1);
	printf("                      Player 2 score: %d\n", sc2);
	if (sc1 > sc2)
	{
		puts("\n                         Player 1: 승리");
		puts("                         Player 2: 패배");
	}
	else if (sc1 < sc2)
	{
		puts("\n                         Player 1: 패배");
		puts("                         Player 2: 승리");
	}
	else if (sc1 == sc2)
	{
		puts("\n                         <무승부>");
	}
	puts("\n                     계속하려면 Space Bar...");
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			Sleep(50);
			play();
		}
		if (GetAsyncKeyState(VK_F5))
		{
			F5();
		}
	}
}

void gameend()
{
	PlaySound(NULL, 0, 0);
	MessageBox(NULL, L"종료됩니다.", L"MOVING TRIANGLE", MB_OK | MB_ICONINFORMATION); //알림창, 확인
	system("cls");
	gotoxy(0, 0);
	puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n\n");
	puts("                        게임이 종료 됨");
	FILE* fp;
	char ch[20];
	fp = fopen("Score.txt", "w");
	fputs(id, fp);
	fputs(pw, fp);
	fputs(name, fp);
	itoa(point, ch, 10);
	strcat(ch, "\n");
	fputs(ch, fp);
	itoa(pmul, ch, 10);
	strcat(ch, "\n");
	fputs(ch, fp);
	itoa(life, ch, 10);
	strcat(ch, "\n");
	fputs(ch, fp);
	itoa(anti, ch, 10);
	strcat(ch, "\n");
	fputs(ch, fp);
	itoa(color, ch, 10);
	strcat(ch, "\n");
	fputs(ch, fp);
	itoa(ab, ch, 10);
	strcat(ch, "\n");
	fputs(ch, fp);
	fclose(fp);
	Sleep(2000);
	system("cls");
	exit(2);
}

void shop()
{
	if (point < 0)
	{
		point = 0;
	}
	while (1)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			u--;
			if (u < 0)
			{
				u = 4;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			u++;
			if (u > 4)
			{
				u = 0;
			}
		}
		Sleep(50);
		system("cls");
		switch (u)
		{
		case 0:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("                          < 상 점 >");
			printf("\n                        포인트: %d점\n", point);
			puts("                      <현재 보유 아이템>");
			printf("                     - [생명의 물약] - %d개\n", life);
			if (anti == 0)
			{
				printf("                     - [해독제]      - 없음\n");
			}
			else
			{
				printf("                     - [해독제]      - 있음\n");
			}
			printf("                     - 포인트 %lld배\n\n", pmul);
			puts("                          < 아이템 >\n");
			puts("                       】생명의 물약【 - 100 p\n");
			puts("                           해독제      - 150 p\n");
			puts("                         포인트 2배    - 200 p\n");
			puts("                         포인트 3배    - 250 p\n");
			puts("                        상점 나가기\n\n\n");
			puts("                      [생명 1개 추가]\n");
			break;
		case 1:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("                          < 상 점 >");
			printf("\n                        포인트: %d점\n", point);
			puts("                      <현재 보유 아이템>");
			printf("                     - [생명의 물약] - %d개\n", life);
			if (anti == 0)
			{
				printf("                     - [해독제]      - 없음\n");
			}
			else
			{
				printf("                     - [해독제]      - 있음\n");
			}
			printf("                     - 포인트 %lld배\n\n", pmul);
			puts("                          < 아이템 >\n");
			puts("                         생명의 물약   - 100 p\n");
			puts("                       】  해독제  【  - 150 p\n");
			puts("                         포인트 2배    - 200 p\n");
			puts("                         포인트 3배    - 250 p\n");
			puts("                        상점 나가기\n\n\n");
			puts("                          [독 ½]\n");
			break;
		case 2:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("                          < 상 점 >");
			printf("\n                        포인트: %d점\n", point);
			puts("                      <현재 보유 아이템>");
			printf("                     - [생명의 물약] - %d개\n", life);
			if (anti == 0)
			{
				printf("                     - [해독제]      - 없음\n");
			}
			else
			{
				printf("                     - [해독제]      - 있음\n");
			}
			printf("                     - 포인트 %lld배\n\n", pmul);
			puts("                          < 아이템 >\n");
			puts("                         생명의 물약   - 100 p\n");
			puts("                           해독제      - 150 p\n");
			puts("                       】포인트 2배【  - 200 p\n");
			puts("                         포인트 3배    - 250 p\n");
			puts("                        상점 나가기\n\n\n");
			break;
		case 3:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("                          < 상 점 >");
			printf("\n                        포인트: %d점\n", point);
			puts("                      <현재 보유 아이템>");
			printf("                     - [생명의 물약] - %d개\n", life);
			if (anti == 0)
			{
				printf("                     - [해독제]      - 없음\n");
			}
			else
			{
				printf("                     - [해독제]      - 있음\n");
			}
			printf("                     - 포인트 %lld배\n\n", pmul);
			puts("                          < 아이템 >\n");
			puts("                         생명의 물약   - 100 p\n");
			puts("                           해독제      - 150 p\n");
			puts("                         포인트 2배    - 200 p\n");
			puts("                       】포인트 3배【  - 250 p\n");
			puts("                        상점 나가기\n\n\n");
			break;
		case 4:
			puts("\n■=■=■=■=■=■=■=  MOVING TRIANGLE  =■=■=■=■=■=■=■\n");
			puts("                          < 상 점 >");
			printf("\n                        포인트: %d점\n", point);
			puts("                      <현재 보유 아이템>");
			printf("                     - [생명의 물약] - %d개\n", life);
			if (anti == 0)
			{
				printf("                     - [해독제]      - 없음\n");
			}
			else
			{
				printf("                     - [해독제]      - 있음\n");
			}
			printf("                     - 포인트 %lld배\n\n", pmul);
			puts("                          < 아이템 >\n");
			puts("                         생명의 물약   - 100 p\n");
			puts("                           해독제      - 150 p\n");
			puts("                         포인트 2배    - 200 p\n");
			puts("                         포인트 3배    - 250 p\n");
			puts("                      】상점 나가기【\n\n\n");
			break;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(50);
			break;
		}
	}
	if (u == 0)
	{
		if (point >= 100)
		{
			point -= 100;
			life++;
			puts("[생명의 물약]을 얻었습니다...");
			Sleep(500);
			shop();
		}
		else
		{
			puts("보유 포인트가 너무 적습니다...");
			Sleep(500);
			shop();
		}
	}
	if (u == 1)
	{
		if (point >= 150)
		{
			if (anti == 1)
			{
				puts("[해독제]가 이미 있습니다...");
				Sleep(500);
				shop();
			}
			else
			{
				point -= 150;
				anti = 1;
				puts("[해독제]를 얻었습니다...");
				Sleep(500);
				shop();
			}
		}
		else
		{
			puts("보유 포인트가 너무 적습니다...");
			Sleep(500);
			shop();
		}
	}
	if (u == 2)
	{
		if (point >= 200)
		{
			point -= 200;
			pmul *= 2;
			puts("[포인트 2배]를 얻었습니다...");
			Sleep(500);
			shop();
		}
		else
		{
			puts("보유 포인트가 너무 적습니다...");
			Sleep(500);
			shop();
		}
	}
	if (u == 3)
	{
		if (point >= 250)
		{
			point -= 250;
			pmul *= 3;
			puts("[포인트 3배]를 얻었습니다...");
			Sleep(500);
			shop();
		}
		else
		{
			puts("보유 포인트가 너무 적습니다...");
			Sleep(500);
			shop();
		}
	}
	if (u == 4)
	{
		return;
	}
}