#include "Life.h"
#include "Rule.h"
#include "View.h"




int main(int argc,char *argv[]) {
	View game(30, 40);
	game.run_game();
	return 0;
}