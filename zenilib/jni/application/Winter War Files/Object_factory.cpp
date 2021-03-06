#include "Object_factory.h"

#include <zenilib.h>

#include "Collidable.h"
#include "Player.h"
#include "Team.h"
#include "Tile.h"

#include "Game_Model.h"

#include "Fortress.h"
#include "Healing_Pool.h"
#include "Snow_Factory.h"
#include "Snowman.h"
#include "Tree.h"
#include "Base.h"


#include <vector>
using namespace Zeni;


Player *create_player(Team* team_,const Zeni::String &gender)
{
	std::string gen;
	if (gender == "Boy" || gender == "boy")
		gen = "boy";
	else if (gender == "Girl" || gender == "girl")
		gen = "girl";
	
	Player* player = new Player(team_, gen);
	team_->add_player(player);
	return player;
}


Player *create_player(Team* team_,const Zeni::String &gender, Tile *tile)
{//This is only used in the tutorial. But it seems, ..odd
	std::string gen;
	if (gender == "Boy" || gender == "boy")
		gen = "boy";
	else if (gender == "Girl" || gender == "girl")
		gen = "girl";
	
	Player* player = new Player(team_, gen);
	player->teleport(tile->get_bottom_center() + Zeni::Point3f(0,0,50));
	team_->add_player(player);
	return player;
}

Team *create_team(Tile * Base_Tile, TEAM_INDEX color)	{
	return new Team(Base_Tile, color);
}

/*
 * Creates the structure object, and modifies relevant tile
 */
Structure *create_structure(int type, Tile* ti, Team* team_)	{
	Structure * st = 0;
	Point3f base = ti->get_structure_base();
	
	switch(type)	{
	case SNOWMAN:
		st =  new Snowman(team_, ti, base);		
		break;
	case FORT:
		st =  new Fortress(team_, ti, base);
		break;
	case SNOW_FACTORY:
		st =  new Snow_Factory(team_, ti, base);
		break;
	case HEALING_POOL:
		st =  new Healing_Pool(team_, ti, base);
		break;
	case TREE:
		st = new Tree(team_, ti, base);
		break;
	case BASE:
		st = new Base(team_, ti, base);
		break;
	default:
		st =  new Fortress(team_, ti, base);
		break;
	}

	//In a normal game this should already be taken care of.
	//But in tutorial and possibly network, this will allow create structure to override
	//and enforce a correct game state
	if(ti->has_building() && ti->get_building()->get_team_pt() != 0)	{
		ti->get_building()->get_team_pt()->remove_tile(ti);
	}

	//Enforce the team requirements for structures
	if(team_ != NULL)	{
		team_->pay_for_building(st);
		team_->add_tile_to_team_network(ti);
		team_->stats.structures[type]++;
	}
	ti->build_structure(st, team_);
	Game_Model::get().add_structure(st);
	return st;
}


/*
	int lowest_area = 1;
	if (Game_Model::get().difficulty < 3)
		lowest_area = 3;	

	else if (Game_Model::get().difficulty == 3)
		lowest_area = 2;
	*/

//	if (type == "Player")

//	else
//		throw Error("Trying to create object of unknown type!");


/*
Game_Object *create_target(const String& type, const Point3f &init)
{
	int lowest_area = 1;

	if (type == "small")
		return new Target(init, 25, 20);
	if (type == "medium")
		return new Target(init, 50, 10);
	if (type == "large")
		return new Target(init, 100, 5);
	
	else
		throw Error("Trying to create object of unknown type!");
}
*/

/*
Game_Object *get_rand_target()
{
	Random r;
	
	int num_targets_c = 3;
	int map_size = 2000;

//	if (Game_Model::get().difficulty < 2 || Game_Model::get().difficulty == 4)
//		num_targets_c = 2;
	
	int z_start = 0;
	int z_large = map_size;
	
	z_start = map_size * (Game_Model::get().difficulty - 1);

	if (Game_Model::get().difficulty > 2)
		z_large = map_size*2;

	Point3f init(r.rand_lte(map_size)-map_size/2, r.rand_lte(map_size)-map_size/2, r.rand_lte(z_large)-z_start);

	switch (r.rand_lte(num_targets_c-1))
	{
		case 0:
			return create_target("small", init);
			break;

		case 1:
			return create_target("medium", init);
			break;

		case 2:
			return create_target("large", init);
			break;
	}
}
*/