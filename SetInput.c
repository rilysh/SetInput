/*
SetInput Version-1.0
Copyright (C) 2018-2020 MathInDOS
License: GNU GPLv3
*/

#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
	if(argv[1])
	{
		if(!strcmp(argv[1], "-h"))
		{
			printf("SetInput Version-1.0\n"
			       "Copyright (C) 2018-2020 MathInDOS\n"
				   "Build Date: 17 December 2020\n\n"
				   "Usage:\n\n"
				   "SetInput m (Turn on mouse input\n"
				   "SetInput k (Turn on keyboard input\n"
				   "SetInput (Default start with Mouse + KeyBoard)\n\n"
				   "Spcial Thanks to Kvc Input utility to get this idea.\n"
				   "Kvc at https://batch-man.com\n\n"
				   "Check out my GitHub Account: https://github.com/MathInDOS\n");				   
			return 0;
		}
	}
	int x,y,key,but;
	HANDLE hOut = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	LPDWORD lpMode = &mode;
	GetConsoleMode(hOut, lpMode);
	SetConsoleMode(hOut, ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT);

	INPUT_RECORD ir;
	PINPUT_RECORD pir = &ir;
	DWORD numOfEve;
	
	while(1)
	{
		ReadConsoleInput(hOut, pir, 1, &numOfEve);
		if(ir.EventType == MOUSE_EVENT)
		{
			if(ir.Event.MouseEvent.dwButtonState)
			{
			x = ir.Event.MouseEvent.dwMousePosition.X;
			y = ir.Event.MouseEvent.dwMousePosition.Y;
			but = ir.Event.MouseEvent.dwButtonState;
			printf("M:%d x:%d y:%d", but, x, y);
			break;
			}
			if (argv[1]) {
				if(!strcmp(argv[1], "M") || !strcmp(argv[1], "m"))
				{
					x = ir.Event.MouseEvent.dwMousePosition.X;
					y = ir.Event.MouseEvent.dwMousePosition.Y;
					but = ir.Event.MouseEvent.dwButtonState;
					printf("M:%d x:%d y:%d", but, x, y);
					break;
				}
			}
		}
		if(ir.EventType == KEY_EVENT)
		{
			ReadConsoleInput(hOut, pir, 1, &numOfEve);
			key = ir.Event.KeyEvent.uChar.UnicodeChar;
			printf("K:%d", key);
			return 0;
		}
		if(argv[1])
		{
			if(!strcmp(argv[1], "K") || !strcmp(argv[1], "k"))
			{
			ReadConsoleInput(hOut, pir, 1, &numOfEve);
			key = ir.Event.KeyEvent.uChar.UnicodeChar;
			printf("K:%d", key);
			return 0;
			}
		}
	}

}


