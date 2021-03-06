#pragma once


#include <vector>
#include <set>
#include <map>

#include "Seen_Object.h"

class Player_View;
//class Seen_Object;

class View
{
public:
	View(void);
	~View(void);

	void render() const;
	void animate() const; // don't do in render loop

	void remove_renderable(Seen_Object *);
	void add_renderable(Seen_Object *);

	void add_player_view(Player_View *pv);

private:
	std::vector<Player_View*> player_views;
	std::set<Seen_Object*> to_render;

	std::map<model_key_t, Zeni::Model*> model_map;

	void render_player(int player, const Zeni::Point2f &topLeft, const Zeni::Point2f &bottomRight) const;
	void render_player_hud(int player, const Zeni::Point2f &topLeft, const Zeni::Point2f &bottomRight) const;
	void render_world() const;
	void render_renderable(const Seen_Object *to_rend) const;

	Zeni::Model *get_model(const Seen_Object*) const;
};
