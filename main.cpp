#include "Life.h"
#include "Rule.h"
#include "View.h"




int main(int argc,char *argv[]) {
	View game(30, 30);
	game.run_game();
	return 0;
}