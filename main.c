#include <windows.h>
#include <stdio.h>

HWND textBox;
int operation = 0;
float operand1 = 0, operand2 = 0;
int isOperand1Set = 0;

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_CREATE: {
			textBox = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT | ES_AUTOHSCROLL | ES_READONLY, 10, 10, 390, 70, hwnd, (HMENU)201, NULL, NULL);	
			
			CreateWindow("BUTTON", "C", WS_CHILD | WS_VISIBLE, 310, 90, 90, 60, hwnd, (HMENU)2009, NULL, NULL);
			CreateWindow("BUTTON", "+", WS_CHILD | WS_VISIBLE, 310, 160, 90, 130, hwnd, (HMENU)2001, NULL, NULL);
			CreateWindow("BUTTON", "=", WS_CHILD | WS_VISIBLE, 310, 300, 90, 130, hwnd, (HMENU)2008, NULL, NULL);
			
			CreateWindow("BUTTON", "/", WS_CHILD | WS_VISIBLE, 10, 90, 90, 60, hwnd, (HMENU)2004, NULL, NULL);
			CreateWindow("BUTTON", "*", WS_CHILD | WS_VISIBLE, 110, 90, 90, 60, hwnd, (HMENU)2003, NULL, NULL);
			CreateWindow("BUTTON", "-", WS_CHILD | WS_VISIBLE, 210, 90, 90, 60, hwnd, (HMENU)2002, NULL, NULL);
			CreateWindow("BUTTON", "C", WS_CHILD | WS_VISIBLE, 310, 90, 90, 60, hwnd, (HMENU)2009, NULL, NULL);
			
			CreateWindow("BUTTON", "7", WS_CHILD | WS_VISIBLE, 10, 160, 90, 60, hwnd, (HMENU)1007, NULL, NULL);
			CreateWindow("BUTTON", "8", WS_CHILD | WS_VISIBLE, 110, 160, 90, 60, hwnd, (HMENU)1008, NULL, NULL);
			CreateWindow("BUTTON", "9", WS_CHILD | WS_VISIBLE, 210, 160, 90, 60, hwnd, (HMENU)1009, NULL, NULL);
			
			CreateWindow("BUTTON", "4", WS_CHILD | WS_VISIBLE, 10, 230, 90, 60, hwnd, (HMENU)1004, NULL, NULL);
			CreateWindow("BUTTON", "5", WS_CHILD | WS_VISIBLE, 110, 230, 90, 60, hwnd, (HMENU)1005, NULL, NULL);
			CreateWindow("BUTTON", "6", WS_CHILD | WS_VISIBLE, 210, 230, 90, 60, hwnd, (HMENU)1006, NULL, NULL);
			
			CreateWindow("BUTTON", "1", WS_CHILD | WS_VISIBLE, 10, 300, 90, 60, hwnd, (HMENU)1001, NULL, NULL);
			CreateWindow("BUTTON", "2", WS_CHILD | WS_VISIBLE, 110, 300, 90, 60, hwnd, (HMENU)1002, NULL, NULL);
			CreateWindow("BUTTON", "3", WS_CHILD | WS_VISIBLE, 210, 300, 90, 60, hwnd, (HMENU)1003, NULL, NULL);
			
			CreateWindow("BUTTON", "0", WS_CHILD | WS_VISIBLE, 10 , 370, 190, 60, hwnd, (HMENU)1000, NULL, NULL);
			CreateWindow("BUTTON", "<=", WS_CHILD | WS_VISIBLE, 210 , 370, 90, 60, hwnd, (HMENU)1010, NULL, NULL);
			
			break;
		}
		
		case WM_COMMAND: {
				switch (LOWORD(wParam)) {
					case 1000: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "0");
						SetWindowTextA(textBox, buffer);
					break;
					}
					
					case 1001: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "1");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1002: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "2");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1003: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "3");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1004: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "4");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1005: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "5");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1006: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "6");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1007: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "7");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1008: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "8");
						SetWindowTextA(textBox, buffer);
					break;
					}
						
					case 1009: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						strcat_s(buffer, sizeof(buffer), "9");
						SetWindowTextA(textBox, buffer);
					break;
					}
					
					case 1010: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						buffer[strlen(buffer)-1] = '\0';
						SetWindowTextA(textBox, buffer);
					break;
					}
					
					
					case 2001: {
						char buffer[50];
						operation = 1;
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						operand1 = atof (buffer);
						if (isOperand1Set == 0) {
							SetWindowTextA(textBox, "");
						}
						isOperand1Set = 1;
					break;
					}
					
					case 2002: {
						char buffer[50];
						operation = 2;
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						operand1 = atof (buffer);
						if (isOperand1Set == 0) {
							SetWindowTextA(textBox, "");
						}
						isOperand1Set = 1;
					break;
					}
					 
					case 2003: {
						char buffer[50];
						operation = 3;
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						operand1 = atof (buffer);
						if (isOperand1Set == 0) {
							SetWindowTextA(textBox, "");
						}
						isOperand1Set = 1;
					break;
					}
					
					case 2004: {
						char buffer[50];
						operation = 4;
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						operand1 = atof (buffer);
						if (isOperand1Set == 0) {
							SetWindowTextA(textBox, "");
						}
						isOperand1Set = 1;
					break;
					}
					
					
					case 2008: {
						char buffer[50];
						GetWindowTextA(textBox, buffer, sizeof(buffer));
						operand2 = atof (buffer);
						switch (operation) {
							case 0: {
								GetWindowTextA(textBox, buffer, sizeof(buffer));
								operand1 = atof (buffer);
							break;
							}
							case 1: {
								operand1 = operand1 + operand2;
							break;
							}
							
							case 2: {
								operand1 = operand1 - operand2;
							break;
							}
							
							case 3: {
								operand1 = operand1 * operand2;
							break;
							}
							
							case 4: {
								operand1 = operand1 / operand2;
							break;
							}
						}
						sprintf (buffer, "%f", operand1);
						SetWindowTextA(textBox, buffer);
						isOperand1Set = 0;
					break;
					}
					
					case 2009: {
						operation = 0;
						operand1 = 0;
						operand2 = 0;
						isOperand1Set = 0;
						SetWindowTextA(textBox, "");
					break;
					}
				}
			break;
		}

		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		430, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
