#pragma once

/*
	RENDERABLE

A Seen_Object object is an object that can be 
	rendered by translating, scaling, 
	and rotating some 3D Model.  
*/

#include <zenilib.h>
#include <string>

class Animator;

typedef std::string model_key_t;

class Seen_Object
{
public:
	Seen_Object(const Zeni::Point3f &position_ = Zeni::Point3f(0,0,0),
              const Zeni::Vector3f &size_ = Zeni::Vector3f(1,1,1),
              const Zeni::Quaternion &theta_ 
				= Zeni::Quaternion::Axis_Angle(Zeni::Vector3f(0.0f, 0.0f, 1.0f), 0.0f));

	virtual ~Seen_Object(void) = 0;

	void render(Zeni::Model *model) const;
	void animate(Zeni::Model *model); // go to the next animation frame

	virtual const model_key_t get_model_name() const = 0;

	bool is_on_ground();

	/*returns true if this object is not supposed to be deleted*/
	bool is_alive();
	void mark_for_deletion();

	Zeni::Point3f get_bottom_center() const;
	Zeni::Point3f get_top_center() const;

protected:
	Zeni::Point3f center;
	Zeni::Vector3f size; // TopRightcorner-to-LowerLeftcorner
	Zeni::Quaternion rotation;
	
private:	
	virtual Animator *get_animator() const
		{return 0;} //default no animator

	bool marked_for_deletion;
};

