#include "Play_State_Base.h"

#include "Game_Model.h"

Play_State_Base::Play_State_Base()	:
	m_prev_clear_color(get_Video().get_clear_Color())
	, time_passed(0.0f)
	
{
		PlayTime.start();
		set_pausable(true);
		for(int i = 0; i < 4; i++)	{
			controllers.push_back(new Controls());
		}
		
}

Play_State_Base::~Play_State_Base()	 {
	for(int i = 0; i < 4; i++)	{
		delete controllers[i];
	}
}

void Play_State_Base::on_push()	{
		get_Window().mouse_hide(true);
		get_Window().mouse_grab(true);
		get_Video().set_clear_Color(Color(0,.1,.1,.1));
		get_Game().joy_mouse.enabled = false;
}

void Play_State_Base::on_pop()	{
		get_Window().mouse_hide(false);
		get_Window().mouse_grab(false);
		get_Video().set_clear_Color(m_prev_clear_color);
    //get_Game().joy_mouse.enabled = true;
}

void Play_State_Base::on_key(const SDL_KeyboardEvent &event) {
	if(!controllers[0]->take_keyboard_input(event, 0)	||
			!controllers[1]->take_keyboard_input(event, 1))
				Gamestate_Base::on_key(event); // Let Gamestate_Base handle it
} 

void Play_State_Base::on_mouse_motion(const SDL_MouseMotionEvent &event) {
			
	for (int i = 0 ; i < 4 ; i++)
	{
		Game_Model::get().get_player(i)->adjust_pitch(event.yrel / 500.0f);
		Game_Model::get().get_player(i)->turn_left(-event.xrel / 500.0f);    
	}
}

void Play_State_Base::on_joy_axis(const SDL_JoyAxisEvent &event)	{
	if(!controllers[event.which]->HandleJoy(event))
		Gamestate_Base::on_joy_axis(event);
}

void Play_State_Base::on_joy_hat(const SDL_JoyHatEvent &event)	{
	if(!controllers[event.which]->HandleJoy(event))
		Gamestate_Base::on_joy_hat(event);
}

void Play_State_Base::on_joy_button(const SDL_JoyButtonEvent &event)	{
	if(!controllers[event.which]->HandleJoy(event))	{}
		Gamestate_Base::on_joy_button(event);
}



void Play_State_Base::perform_logic()	
{
	
	const float frametime_passed = PlayTime.seconds();
	const float currentStep = frametime_passed - time_passed;
	time_passed = frametime_passed;
	time_step = currentStep;


	for(int i = 0; i < 4; i++)	
		controllers[i]->adjust_Cam(Game_Model::get().get_player(i));


//	Game_Model::get().get_player(0)->move_strafe(time_step, 100, Vector3f(test.input.move_x, test.input.move_y, 0));

	Game_Model::get().update();
}

void Play_State_Base::render()	{
	Game_Model::get().render();

	int width = get_Window().get_width();
	int height = get_Window().get_height();
	get_Video().set_2d(pair<Point2f, Point2f>(Point2f(0,0), Point2f(width, height)));
	get_Fonts()["system_36_800x600"].render_text(controllers[0]->give_stick_status().c_str(), Point2f(0, 0), Color(1, 0.1, 0.85, 0.1 ));

}