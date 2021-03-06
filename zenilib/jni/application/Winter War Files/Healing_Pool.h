#pragma once
#include "Structure.h"

extern const float Healing_rate;

class Healing_Pool : public Structure
{
public:
	Healing_Pool(Team *team, Tile* tile_,
				const Zeni::Point3f &base_);
	~Healing_Pool(void);

	void update(const float&);

	virtual Structure_Type get_type()
	{ return HEALING_POOL;}

	void handle_player_collision(Player *P);

	const model_key_t get_model_name() const;

private:
	//anything?
	void create_body();
	Animator *Healing_Pool::get_animator() const;

};