#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>

#include "include/config.h"

#define clear() printf("\e[1;1H\e[2J")
#define hide() printf("\e[?25l")
#define show() printf("\e[?25h")
#define set(x,y) printf("\033[%d;%dH", (y), (x))
#define print_hex(c) printf("\033[38;2;%d;%d;%dm", (int) ((c >> 16) & 0xFF), (int) ((c >> 8) & 0xFF), (int) ((c) & 0xFF))

const char font_ref[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':'};

struct termios orig;

int get_ref_index(char c){
    int i = 0;
    while (i < sizeof(font_ref) / sizeof(char) && font_ref[i] != c) ++i;
    return (i == sizeof(font_ref) / sizeof(char) ? -1 : i);
}

void print_time(char *tstr, int w, int h){
	for (int row = 0; row < CHAR_H; row++){
		for (int numr = 0; numr < PIX_H; numr++){
			set((int) w / 2 - PIX_W * CHAR_W * (int) strlen(tstr) / 2 - SPACE_SIZE * ((int) strlen(tstr) - 1) / 2 + 1 + OFF_X, (int) h / 2 - PIX_H * CHAR_H / 2 + row * PIX_H + numr + 1 + OFF_Y);	
			for (int i = 0; i < strlen(tstr); i++){
				for (int column = 0; column < CHAR_W; column++){
					for (int numc = 0; numc < PIX_W; numc++){
						if (font[get_ref_index(tstr[i])][row][column]){
							printf("%s", FILL_CHAR);
						}else{
							printf("%s", EMPTY_CHAR);
						}
					}
				}
				for (int nums = 0; nums < SPACE_SIZE; nums++)
					printf("%s", SPACE_CHAR);
			}
			printf("\n");
		}
	}
}

void reset(){
	show();
	clear();
	printf("\033[0m");
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
	exit(0);
}

void enable_raw(){
	tcgetattr(STDIN_FILENO, &orig);
	struct termios raw = orig;
	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(int argc, char *argv[]){
	struct winsize w;
	struct tm * tinfo;
	time_t t;
	char tstr[256];
	int p;

	signal(SIGINT, reset);
	enable_raw();
	hide();
	print_hex(COLOR);

	for (;;){
		clear();			
		time(&t);
		tinfo = localtime(&t);
		memset(tstr, 0, 256);
		for (int i = 0; i < strlen(FORMAT); i++){
			p = 0;
			if (FORMAT[i] == 'H')
				p = tinfo->tm_hour;
			if (FORMAT[i] == 'M')
				p = tinfo->tm_min;
			if (FORMAT[i] == 'S')
				p = tinfo->tm_sec;
			
			sprintf(tstr, p < 10 ? "%s0%d" : "%s%d", tstr, p);
			if (i < strlen(FORMAT) - 1)
				sprintf(tstr, "%s:", tstr);
		}
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);	
		print_time(tstr, w.ws_col, w.ws_row);
		sleep(1);
	}
	return 0;
}
