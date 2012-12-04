#ifndef SHIP_FACTORY_H
#define SHIP_FACTORY_H

#include <string>
#include <zenilib.h>

class Player;
class Team;
class Tile;
class Structure;

// gender can be "MALE" or "FEMALE"
Player *create_player(Team* team_, const std::string &gender);

Team	*create_team(Tile * Base_Tile);

// creates a structure and adds it to the tile
Structure *create_structure(int type, Tile* ti, Team* team_);

#endif
