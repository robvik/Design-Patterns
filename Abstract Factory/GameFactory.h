#ifndef GameFactoryH
#define GameFactoryH

#include <vector>
#include <string>

using std::vector;
using std::string;

class Player;
class Obstacle;
class Action;

class GameFactory {
protected:
	GameFactory() { }

public:
	virtual ~GameFactory() = default;
	virtual string setGameTitle() = 0;
	virtual vector<Obstacle*> makeObstacles() = 0;
	virtual vector<Action*> makeActions() = 0;
	virtual Player* makePlayer() = 0;
};


class NiceGameFactory : public GameFactory {
public:
	string setGameTitle() override;
	vector<Obstacle*> makeObstacles() override;
	vector<Action*> makeActions() override;
	Player* makePlayer() override;
};

class NastyGameFactory : public GameFactory {
public:
	string setGameTitle() override;
	vector<Obstacle*> makeObstacles() override;
	vector<Action*> makeActions() override;
	Player* makePlayer() override;
};

#endif
