#include "TypeManager.h"
class StandardTypeManager : public TypeManager
{
public:
	StandardTypeManager()
	{
		Type ts[] = { 
			{"INT"},
			{"CHAR"},
			{"LONG"},
			{"FLOAT"},
			{"DOUBLE"},
			{"BOOLEAN"}
		};
		for (Type t : ts)
			types.push_back(t);
	}
};

TypeManager* type_manager = new StandardTypeManager();


void addType(Type type)
{
	
}