#pragma once
#include "Collidable.h"
#include "Seen_Object.h"

#include <zenilib.h>

//These enums represnt the different types of buildings for now

enum Structure_Type	{
	NOTHING, SNOWMAN, FORT, SNOW_FACTORY, HEALING_POOL, TREE
};

const int Build_Cost[5] = { 0, 300, 100, 200, 400 };

const float Struct_Integrity[5] = {1, 50, 200, 20, 100};

enum	Universal_State	{
	PRESENT_MODE, BUILT, DAMAGED, DESTROYED
};

class Team;
class Collision_Table;
class Tile;
class Snowball;

class Structure :
	public Collidable, public Seen_Object
{
public:
	Structure(Team *team, Tile* tile_,
				const Zeni::Point3f &base_,	 float radius = 100.0f);
	~Structure(void);

	void update(const float&);

	void change_height(const float &delta);

	void receive_hit(Snowball *S); 

	void perform_destruction_effects();

	virtual int get_resourses_needed();
	
	int get_ID() const 
		{return structure_ID_c;}

private:
	// State?  Building -> Built -> Damaged? -> Destroyed??
	//Would the damaged state look different? like a broken version of the model???
	//could be cool
	
protected:
	float Health;
	Universal_State Status;
	bool Connected_to_Team;

	// maybe Collision capsule??? If each structure needs Collision Object, 
	// Collision table becomes much more complicated to code
	// But some effects might need players to run into them
	// Solution: make defualt body, but can overwrite in derived classes if need to

	Team *owner;

	Tile *hex;

	
	void create_body();
	Zeni::Collision::Capsule body;
		
	// Collison Stuff
	const static int structure_ID_c;
	friend Collision_Table;

};

