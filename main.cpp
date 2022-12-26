#include "Life.h"
#include "Rule.h"




int main(int argc,char *argv[]) {
	Life game(12,12);
	game.run_life();
	return 0;
}