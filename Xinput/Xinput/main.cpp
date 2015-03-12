


#include <Windows.h>
#include <Xinput.h>

#include <iostream>
#include <string>
#include "GameController.h"
using namespace System;
using namespace std;

/*
Build Config:
	1.linker->input-> dependency-> add XINPUT9_1_0.LIB
	2.add <Xinput.h>
	3.add <Windows.h>
	4.enable CLR
*/

GameController gameControl;
int winTop;
int winLef;


void WriteAt(String^ s, int x, int y)
{
	try
	{
		Console::SetCursorPosition(winTop + x, winLef + y);
		Console::Write(s);
	}
	catch (ArgumentOutOfRangeException^ e)
	{
		Console::Clear();
		Console::WriteLine(e->Message);
	}

}

int main() {
	int winTop = Console::CursorTop;
	int winLef = Console::CursorLeft;

	while (1) {
		gameControl.update();

		if (gameControl.isConnected) {
			float normLX = gameControl.lx_thumb;
			float normLY = gameControl.ly_thumb;

			String^ lxtStr = "LX: " + normLX.ToString();
			String^ lrStr = "LR: " + normLY.ToString();
			WriteAt(lxtStr, 5, winTop);
			WriteAt(lrStr, 30, winTop);

			if (normLX == 1 || normLY == 1) {
				cout << "vibrate" << endl;
				gameControl.vibrate(2);
			}
		}
		Sleep(50);
		Console::Clear();
	}
}