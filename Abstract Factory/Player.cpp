#include "Player.h"

using std::endl;

void Player::show(ostream &os) {
	os << "\nStatus health:" << health << " resources:" << resources;
	os << " ammo:" << ammo << endl;
}


