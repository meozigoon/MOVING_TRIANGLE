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
BOOL CtrlHandler(DWORD fdwCtrlType); //X��ư �� ���� Ȯ��
void CursorView_F(); //Ŀ�� ����
void CursorView_T(); //Ŀ�� ����
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
	system("mode con cols=61 lines=34"); //�ܼ� ȭ�� ũ��
	system("color 07"); //�ܼ� ȭ�� ����(����, �⺻ ��)
	system("title �� MOVING TRIANGLE ��"); //�ܼ� â ����
	CursorView_F(); //Ŀ�� ����
	srand((unsigned)time(NULL));
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE); //X��ư �� ���� Ȯ��
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("\n                                             [Made by DH.L]\n");
			if (j == 0)
			{
				puts("                           LOADING ��");
			}
			else if (j == 1)
			{
				puts("                           LOADING ��");
			}
			else if (j == 2)
			{
				puts("                           LOADING ��");
			}
			else if (j == 3)
			{
				puts("                           LOADING ��");
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
	while (1) //���� �˰���
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("              ȭ��ǥ Ű�� �̿��Ͽ� �����ϼ���.\n");
			puts("                    Enter�� �����ϼ���.\n");
			puts("                         ���α��Ρ�\n");
			puts("                           �����");
			break;
		case 1:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("              ȭ��ǥ Ű�� �̿��Ͽ� �����ϼ���.\n");
			puts("                    Enter�� �����ϼ���.\n");
			puts("                           �α���\n");
			puts("                         ������⡼");
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
		while (1) //�α���
		{
			while (kbhit()) //Ű �Է� �ʱ�ȭ
				getch();
			CursorView_T();
			system("cls");
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("                          <�α���>\n");
			printf("                         ID: ");
			rewind(stdin);
			scanf("%s", id);
			printf("                         PW: ");
			scanf("%s", pw);
			strcat(id, "\n");
			strcat(pw, "\n");
			CursorView_F();
			if (strcmp(id, idch) == 0 && strcmp(pw, pwch) == 0) //���� ���
			{
				puts("�α��� �Ǿ����ϴ�.");
				Sleep(500);
				system("cls");
				puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
				printf("ȯ���մϴ�, %s", name);
				Sleep(1000);
				break;
			}
			else //Ʋ�� ���
			{
				if (strcmp(id, idch) != 0 && strcmp(pw, pwch) != 0)
				{
					puts("�߸��� ID�� PW�Դϴ�. �ٽ� �Է����ּ���.");
				}
				else if (strcmp(id, idch) != 0)
				{
					puts("�߸��� ID�Դϴ�. �ٽ� �Է����ּ���.");
				}
				else if (strcmp(pw, pwch) != 0)
				{
					puts("�߸��� PW�Դϴ�. �ٽ� �Է����ּ���.");
				}
				cnt++;
				if (cnt == 5)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X��ư ��Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
					puts("5ȸ Ʋ�Ƚ��ϴ�. 30�� �Ŀ� �õ����ּ���.\n");
					Sleep(30000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X��ư Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt == 10)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X��ư ��Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
					puts("10ȸ Ʋ�Ƚ��ϴ�. 1�� �Ŀ� �õ����ּ���.");
					Sleep(60000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X��ư Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt == 15)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X��ư ��Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
					puts("15ȸ Ʋ�Ƚ��ϴ�. 2�� �Ŀ� �õ����ּ���.");
					Sleep(120000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X��ư Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt > 15 && cnt < 20)
				{
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE, MF_GRAYED); //X��ư ��Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
					printf("%dȸ Ʋ�Ƚ��ϴ�. 5�� �Ŀ� �õ��� �ּ���.\n", cnt);
					Sleep(300000);
					EnableMenuItem(GetSystemMenu(GetConsoleWindow(), TRUE), SC_CLOSE, MF_GRAYED); //X��ư Ȱ��ȭ
					DrawMenuBar(GetConsoleWindow());
				}
				if (cnt == 20)
				{
					puts("20ȸ Ʋ�Ƚ��ϴ�. ���α׷��� ����˴ϴ�.");
					Sleep(750);
					system("cls");
					exit(0);
				}
				Sleep(500);
			}
		}
	}
	if (log_in == 1) //���� ����
	{
		CursorView_T();
		while (kbhit())
			getch();
		system("cls");
		puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
		puts("                          <�����>\n");
		printf("                     ID�� �Է��Ͻÿ�: ");
		scanf("%s", id);
		Sleep(50);
		printf("                     PW�� �Է��Ͻÿ�: ");
		scanf("%s", pw);
		Sleep(50);
		printf("                    �г����� �Է��Ͻÿ�: ");
		scanf("%s", name);
		Sleep(50);
		CursorView_F();
		puts("���� ������ ����Ǿ����ϴ�.");
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
	switch (color) //�ܼ� ���� ����(���� �Է�, ����� ����)
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
	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
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
		MessageBox(NULL, L"����˴ϴ�.", L"MOVING TRIANGLE", MB_OK | MB_ICONINFORMATION); //�˸�â, Ȯ��
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts(name);
			puts("                       �� ���� ���� ��\n");
			puts("                            �� ��\n");
			puts("                            �� ��\n");
			puts("                         ����Ʈ ����\n");
			puts("                          ���� ����");
			break;
		case 1:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts(name);
			puts("                          ���� ����\n");
			puts("                       ��   �� ��   ��\n ");
			puts("                            �� ��\n");
			puts("                         ����Ʈ ����\n");
			puts("                          ���� ����");
			break;
		case 2:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts(name);
			puts("                          ���� ����\n");
			puts("                            �� ��\n");
			puts("                       ��   �� ��   ��\n");
			puts("                         ����Ʈ ����\n");
			puts("                          ���� ����");
			break;
		case 3:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts(name);
			puts("                          ���� ����\n");
			puts("                            �� ��\n");
			puts("                            �� ��\n");
			puts("                       ������Ʈ ������\n");
			puts("                          ���� ����");
			break;
		case 4:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts(name);
			puts("                          ���� ����\n");
			puts("                            �� ��\n");
			puts("                            �� ��\n");
			puts("                         ����Ʈ ����\n");
			puts("                       �� ���� ���� ��");
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
				puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
				puts("                       ��1�� �÷��̡�\n");
				puts("                         2�� �÷���\n");
				puts("         [2�� �÷���]�� ����Ʈ / ������ ���� ����");
			}
			if (ss == 1)
			{
				puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
				puts("                         1�� �÷���\n");
				puts("                       ��2�� �÷��̡�\n");
				puts("         [2�� �÷���]�� ����Ʈ / ������ ���� ����");
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			printf("\n\n���� �ε� ��");
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
		puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
		puts("                       �� : ����(5��)\n");
		puts("                       �� : ����(20��)\n");
		puts("                       �� : ��Ż(�ݴ� ��Ż�� �̵�)\n");
		puts("                       �� : �� ����(-10 / -20��)\n");
		puts("                     ��");
		puts("                   ���䢹, W, A, S, D : MOVE\n");
		puts("                      Esc : GO TO MAIN\n");
		puts("                        F5 : REFRESH\n");
		puts("                       ENTER : SELECT\n");
		puts("                    ���� ������ ���� ����\n");
		puts("\n\n\n                    �������� Space Bar...");
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
	if (IDYES == MessageBox(NULL, L"���ΰ�ħ �Ͻðڽ��ϱ�?", L"MOVING TRIANGLE", MB_YESNO | MB_ICONQUESTION)) //�˸�â('��'�� ���� ��� ���ΰ�ħ ��.)
	{
		PlaySound(NULL, 0, 0); //���� ��� ����
		FILE* fp; //���� �Է� ��
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
			puts("                       ��ĳ���� ������\n");
			puts("                         �׸� �� ����\n");
			puts("                         ����   �Ϸ�");
		}
		if (d == 1)
		{
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
			puts("                         ĳ���� ����\n");
			puts("                       ���׸� �� ������\n");
			puts("                         ����   �Ϸ�");
		}
		if (d == 2)
		{
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
			puts("                         ĳ���� ����\n");
			puts("                         �׸� �� ����\n");
			puts("                       ������   �Ϸ᡼");
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
				puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
				puts("                            ���㡼\n");
				puts("                              ��\n");
				ab = 1;
				break;
			case 1:
				puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
				puts("                              ��\n");
				puts("                            ���⡼\n");
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
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("        ����������           �Ķ���             ��  ��\n");
					puts("          û�ϻ�             ������             ���ֻ�\n");
					puts("          �����             ��  ��             ȸ  ��\n");
					color = 1;
					break;
				case 1:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������           ���Ķ�����           ��  ��\n");
					puts("          û�ϻ�             ������             ���ֻ�\n");
					puts("          �����             ��  ��             ȸ  ��\n");
					color = 2;
					break;
				case 2:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���           ����  ����\n");
					puts("          û�ϻ�             ������             ���ֻ�\n");
					puts("          �����             ��  ��             ȸ  ��\n");
					color = 3;
					break;
				}
				break;
			case 1:
				switch (f)
				{
				case 0:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���             ��  ��\n");
					puts("        ��û�ϻ���           ������             ���ֻ�\n");
					puts("          �����             ��  ��             ȸ  ��\n");
					color = 4;
					break;
				case 1:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���             ��  ��\n");
					puts("          û�ϻ�           ����������           ���ֻ�\n");
					puts("          �����             ��  ��             ȸ  ��\n");
					color = 5;
					break;
				case 2:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���             ��  ��\n");
					puts("          û�ϻ�             ������           �����ֻ���\n");
					puts("          �����             ��  ��             ȸ  ��\n");
					color = 6;
					break;
				}
				break;
			case 2:
				switch (f)
				{
				case 0:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���             ��  ��\n");
					puts("          û�ϻ�             ������             ���ֻ�\n");
					puts("        ���������           ��  ��             ȸ  ��\n");
					color = 7;
					break;
				case 1:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���             ��  ��\n");
					puts("          û�ϻ�             ������             ���ֻ�\n");
					puts("          �����           ����  ����           ȸ  ��\n");
					color = 8;
					break;
				case 2:
					puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
					puts("          ������             �Ķ���             ��  ��\n");
					puts("          û�ϻ�             ������             ���ֻ�\n");
					puts("          �����             ��  ��           ��ȸ  ����\n");
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
		puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
		puts("������ �Ϸ�Ǿ����ϴ�...");
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
						puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
						puts("                         ������ϱ⡼\n");
						puts("                           ��������");
					}
					if (aa == 1)
					{
						puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
						puts("                           ����ϱ�\n");
						puts("                         ���������Ρ�");
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��");
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
			puts("��");
			gotoxy(xy[3].x, xy[3].y);
			puts("��");
			gotoxy(xy[4].x, xy[4].y);
			puts("��");
			gotoxy(xy[5].x, xy[5].y);
			puts("��");
			gotoxy(xy[6].x, xy[6].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			gotoxy(xy[7].x, xy[7].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			gotoxy(xy[8].x, xy[8].y);
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			gotoxy(xy[9].x, xy[9].y);
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			switch (i)
			{
			case 0:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
						puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
						puts("                         ������ϱ⡼\n");
						puts("                           ��������");
					}
					if (aa == 1)
					{
						puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
						puts("                           ����ϱ�\n");
						puts("                         ���������Ρ�");
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��");
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
			puts("��");
			gotoxy(xy[3].x, xy[3].y);
			puts("��");
			gotoxy(xy[10].x, xy[10].y);
			puts("��");
			gotoxy(xy[4].x, xy[4].y);
			puts("��");
			gotoxy(xy[5].x, xy[5].y);
			puts("��");
			gotoxy(xy[6].x, xy[6].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			gotoxy(xy[7].x, xy[7].y);
			xy6 = xy6 % 2;
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			gotoxy(xy[8].x, xy[8].y);
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			gotoxy(xy[9].x, xy[9].y);
			if (xy6 == 0)
			{
				puts("��");
			}
			if (xy6 == 1)
			{
				puts("��");
			}
			switch (i)
			{
			case 0:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("��");
				if (ab == 2)
					puts("��");
				xy[1].y--;
				if (xy[1].y < 5)
				{
					i = 1;
				}
				break;
			case 1:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("��");
				if (ab == 2)
					puts("��");
				xy[1].y++;
				if (xy[1].y > 28)
				{
					i = 0;
				}
				break;
			case 2:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("��");
				if (ab == 2)
					puts("��");
				xy[1].x++;
				if (xy[1].x > 58)
				{
					i = 3;
				}
				break;
			case 3:
				gotoxy(xy[1].x, xy[1].y);
				if (ab == 1)
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
					puts("��");
				if (ab == 2)
					puts("��");
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
	puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
	puts("                          Game Over\n");
	printf("                          score: %d\n\n", sc);
	printf("                          LEVEL : %d\n\n\n", level);
	puts("                     ����Ϸ��� Space Bar...");
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
	puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
	puts("                          Game Over\n");
	printf("                      Player 1 score: %d\n", sc1);
	printf("                      Player 2 score: %d\n", sc2);
	if (sc1 > sc2)
	{
		puts("\n                         Player 1: �¸�");
		puts("                         Player 2: �й�");
	}
	else if (sc1 < sc2)
	{
		puts("\n                         Player 1: �й�");
		puts("                         Player 2: �¸�");
	}
	else if (sc1 == sc2)
	{
		puts("\n                         <���º�>");
	}
	puts("\n                     ����Ϸ��� Space Bar...");
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
	MessageBox(NULL, L"����˴ϴ�.", L"MOVING TRIANGLE", MB_OK | MB_ICONINFORMATION); //�˸�â, Ȯ��
	system("cls");
	gotoxy(0, 0);
	puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n\n");
	puts("                        ������ ���� ��");
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
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("                          < �� �� >");
			printf("\n                        ����Ʈ: %d��\n", point);
			puts("                      <���� ���� ������>");
			printf("                     - [������ ����] - %d��\n", life);
			if (anti == 0)
			{
				printf("                     - [�ص���]      - ����\n");
			}
			else
			{
				printf("                     - [�ص���]      - ����\n");
			}
			printf("                     - ����Ʈ %lld��\n\n", pmul);
			puts("                          < ������ >\n");
			puts("                       �������� ���ࡼ - 100 p\n");
			puts("                           �ص���      - 150 p\n");
			puts("                         ����Ʈ 2��    - 200 p\n");
			puts("                         ����Ʈ 3��    - 250 p\n");
			puts("                        ���� ������\n\n\n");
			puts("                      [���� 1�� �߰�]\n");
			break;
		case 1:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("                          < �� �� >");
			printf("\n                        ����Ʈ: %d��\n", point);
			puts("                      <���� ���� ������>");
			printf("                     - [������ ����] - %d��\n", life);
			if (anti == 0)
			{
				printf("                     - [�ص���]      - ����\n");
			}
			else
			{
				printf("                     - [�ص���]      - ����\n");
			}
			printf("                     - ����Ʈ %lld��\n\n", pmul);
			puts("                          < ������ >\n");
			puts("                         ������ ����   - 100 p\n");
			puts("                       ��  �ص���  ��  - 150 p\n");
			puts("                         ����Ʈ 2��    - 200 p\n");
			puts("                         ����Ʈ 3��    - 250 p\n");
			puts("                        ���� ������\n\n\n");
			puts("                          [�� ��]\n");
			break;
		case 2:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("                          < �� �� >");
			printf("\n                        ����Ʈ: %d��\n", point);
			puts("                      <���� ���� ������>");
			printf("                     - [������ ����] - %d��\n", life);
			if (anti == 0)
			{
				printf("                     - [�ص���]      - ����\n");
			}
			else
			{
				printf("                     - [�ص���]      - ����\n");
			}
			printf("                     - ����Ʈ %lld��\n\n", pmul);
			puts("                          < ������ >\n");
			puts("                         ������ ����   - 100 p\n");
			puts("                           �ص���      - 150 p\n");
			puts("                       ������Ʈ 2�衼  - 200 p\n");
			puts("                         ����Ʈ 3��    - 250 p\n");
			puts("                        ���� ������\n\n\n");
			break;
		case 3:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("                          < �� �� >");
			printf("\n                        ����Ʈ: %d��\n", point);
			puts("                      <���� ���� ������>");
			printf("                     - [������ ����] - %d��\n", life);
			if (anti == 0)
			{
				printf("                     - [�ص���]      - ����\n");
			}
			else
			{
				printf("                     - [�ص���]      - ����\n");
			}
			printf("                     - ����Ʈ %lld��\n\n", pmul);
			puts("                          < ������ >\n");
			puts("                         ������ ����   - 100 p\n");
			puts("                           �ص���      - 150 p\n");
			puts("                         ����Ʈ 2��    - 200 p\n");
			puts("                       ������Ʈ 3�衼  - 250 p\n");
			puts("                        ���� ������\n\n\n");
			break;
		case 4:
			puts("\n��=��=��=��=��=��=��=  MOVING TRIANGLE  =��=��=��=��=��=��=��\n");
			puts("                          < �� �� >");
			printf("\n                        ����Ʈ: %d��\n", point);
			puts("                      <���� ���� ������>");
			printf("                     - [������ ����] - %d��\n", life);
			if (anti == 0)
			{
				printf("                     - [�ص���]      - ����\n");
			}
			else
			{
				printf("                     - [�ص���]      - ����\n");
			}
			printf("                     - ����Ʈ %lld��\n\n", pmul);
			puts("                          < ������ >\n");
			puts("                         ������ ����   - 100 p\n");
			puts("                           �ص���      - 150 p\n");
			puts("                         ����Ʈ 2��    - 200 p\n");
			puts("                         ����Ʈ 3��    - 250 p\n");
			puts("                      ������ �����⡼\n\n\n");
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
			puts("[������ ����]�� ������ϴ�...");
			Sleep(500);
			shop();
		}
		else
		{
			puts("���� ����Ʈ�� �ʹ� �����ϴ�...");
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
				puts("[�ص���]�� �̹� �ֽ��ϴ�...");
				Sleep(500);
				shop();
			}
			else
			{
				point -= 150;
				anti = 1;
				puts("[�ص���]�� ������ϴ�...");
				Sleep(500);
				shop();
			}
		}
		else
		{
			puts("���� ����Ʈ�� �ʹ� �����ϴ�...");
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
			puts("[����Ʈ 2��]�� ������ϴ�...");
			Sleep(500);
			shop();
		}
		else
		{
			puts("���� ����Ʈ�� �ʹ� �����ϴ�...");
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
			puts("[����Ʈ 3��]�� ������ϴ�...");
			Sleep(500);
			shop();
		}
		else
		{
			puts("���� ����Ʈ�� �ʹ� �����ϴ�...");
			Sleep(500);
			shop();
		}
	}
	if (u == 4)
	{
		return;
	}
}