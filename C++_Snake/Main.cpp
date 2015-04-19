#include <iostream>
#include "windows.h"

using namespace std;

bool game_running = true;
const int height = 10;
const int width = 20;
char map[height][width] = {
	"###################",
	"#@                #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"###################"
};

int x = 1;
int y = 1;

int main()
{
	while (game_running == true)
	{
		system("CLS"); //clear screen
		for (int display = 0; display < height; display++){
			cout << map[display] << endl;
		}

		system("PAUSE>NUL"); //ekranin yanip sonmesini engelliyor

		if (GetAsyncKeyState(VK_DOWN)) // DOWN (alt yön tuþu) a basildigini algilamak icin
		{
			int y2 = y + 1;
			if (map[y2][x] == ' ') // hareket edecegimiz yerin bosluk' ' olmasi gerekiyor
			{
				map[y][x] = ' '; // bulundugumuz yeri temizle 
				y++; // konumumuz degistigi icin y yonunde 1 artir
				map[y][x] = '@'; // yeni konumumuza karakteri yerlestir
			}
		}
		if (GetAsyncKeyState(VK_UP)) // UP (ust yon tusu) a basildigini algilamak icin
		{
			int y2 = y - 1;
			if (map[y2][x] == ' ')
			{
				map[y][x] = ' ';
				y--;
				map[y][x] = '@';
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) // RIGHT (sag yon tusu) a basildigini algilamak icin
		{
			int x2 = x + 1;
			if (map[y][x2] == ' ')
			{
				map[y][x] = ' ';
				x++;
				map[y][x] = '@';
			}
		}

		if (GetAsyncKeyState(VK_LEFT)) // LEFT (sol yon tusu) a basildigini algilamak icin
		{
			int x2 = x - 1;
			if (map[y][x2] == ' ')
			{
				map[y][x] = ' ';
				x--;
				map[y][x] = '@';
			}
		}
		//close the program
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			game_running = false;
		}
	}

	cout << "GAME OVER" << endl;
	return 0;
}