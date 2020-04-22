#include "GameFactory.h"
#include "Obstacle.h"
#include "Action.h"

string NiceGameFactory::setGameTitle()
{
	return "Nice Game";
}

vector<Obstacle*> NiceGameFactory::makeObstacles()
{
	vector<Obstacle*> obstacles;
	obstacles.push_back(new Wizard());
	obstacles.push_back(new Wall());
	obstacles.push_back(new Elephant());
	obstacles.push_back(new DPexam());

	return obstacles;
}

vector<Action*> NiceGameFactory::makeActions()
{

	vector<Action*> actions;
	actions.push_back(new BowAndShakeHandsAction());
	actions.push_back(new RunAndHideAction());
	actions.push_back(new BargainAndBuyAction());
	actions.push_back(new ChainsawAction());
	actions.push_back(new ClimbAction());
	actions.push_back(new CastAspellAction());
	actions.push_back(new SurrenderAction());

	return actions;
}

Player * NiceGameFactory::makePlayer()
{
	return new OrdinaryPlayer();
}

string NastyGameFactory::setGameTitle()
{
	return "Nasty Game";
}

vector<Obstacle*> NastyGameFactory::makeObstacles()
{
	vector<Obstacle*> obstacles;
	obstacles.push_back(new Dragon());
	obstacles.push_back(new Bomb());
	obstacles.push_back(new Samuray());
	obstacles.push_back(new SumoWrestler());
	obstacles.push_back(new Gangster());

	return obstacles;
}

vector<Action*> NastyGameFactory::makeActions()
{
	vector<Action*> actions;
	actions.push_back(new BowAndShakeHandsAction());
	actions.push_back(new RunAndHideAction());
	actions.push_back(new SwordAction());
	actions.push_back(new RifleAction());
	actions.push_back(new OfferFoodAction());
	actions.push_back(new ChainsawAction());
	actions.push_back(new CastAspellAction());
	actions.push_back(new BargainAndBuyAction());
	actions.push_back(new SurrenderAction());

	return actions;
}

Player * NastyGameFactory::makePlayer()
{
	return new HeroPlayer();
}
