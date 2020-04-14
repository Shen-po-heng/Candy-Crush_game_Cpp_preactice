#ifndef UTIL
	#define UTIL
	#define consoleH GetStdHandle(STD_OUTPUT_HANDLE)
	#define consoleW GetConsoleWindow()
	enum color {BLACK=0, BLUE, GREEN, AQUA, RED, PURPLE, YELLOW, WHITE, 
				GRAY, L_BLUE, L_GREEN, L_AQUA, L_RED, L_PURPLE, L_YELLOW, L_WHITE};
	void curPos(int x, int line){
	    COORD pos = {x, line};
	    SetConsoleCursorPosition(consoleH, pos);
	}
	
	void setColor(int fg=WHITE, int bg=BLACK);
	void setColor(int fg, int bg){
		SetConsoleTextAttribute(consoleH, fg + bg*16); 
	}
	void setConsoleSize(int width, int height, bool repos=false);
	void setConsoleSize(int width, int height, bool repos){
		RECT r;
		GetWindowRect(consoleW, &r);
		if(repos){
			r.left=-4;
			r.top=-4;
		}
		SetWindowPos(consoleW, 0, r.left, r.top, width*10, height*22, SWP_NOZORDER);
	}
	void hidecursor()
	{
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleH, &info);
	}
	
	bool isDown(int key){
		return (GetKeyState(key)>>1)!=0;
	}
	
	int constrain(int n, int l, int h){
		if(n<l)return l;
		if(n>h)return h;
		return n;
	}
#endif
