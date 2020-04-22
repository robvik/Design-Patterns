#ifndef GameH
#define GameH

#include <vector>
#include "Action.h"
#include "Obstacle.h"
#include "GameFactory.h"

using std::vector;

class Action;
class Obstacle;
class GameFactory;


class Game {
private:
	string title;
	vector<Obstacle*> obstacles;
	vector<Action*> actions;
	Player* player;

public:
	Game(GameFactory *gFact);
	~Game();
	void play();
};


#endif
