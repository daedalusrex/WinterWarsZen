#pragma once

#include "Seen_Object.h"



class Effect : public Seen_Object
{
public:
	Effect(const std::string &model_, const Zeni::Point3f &position_ = Zeni::Point3f(0,0,0),
              const Zeni::Vector3f &size_ = Zeni::Vector3f(10,10,10));
	
	~Effect(){}
	
	virtual const model_key_t get_model_name() const;

private:
	std::string name;

};


