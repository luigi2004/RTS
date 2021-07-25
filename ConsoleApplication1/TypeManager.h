#pragma once
#include <functional>

struct Type
{
	std::string name;
	int modifiers;
	std::function<void*()> creator;
	std::function<void()> destroyer;
};



class TypeManager
{
protected:
	Type NULLTYPE;
	TypeManager()
	{
	}
	std::vector<Type> types;
public:
	
	Type getTypeByName(std::string name)
	{
		for (Type i : types)
		{
			if (i.name == name)
			{
				return i;
			}
		}
		return {"NULLTYPE"};
	}
};

extern TypeManager* type_manager;


void addType(Type type);