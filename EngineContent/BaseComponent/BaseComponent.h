#pragma once

#include <Vector>
#include <String>

#include "../Marcos/Marcos.h"
#include "../BaseEntity/BaseEntity.h"

using namespace std;

class BaseEntity;

class BaseComponent
{
protected:
	string Identifyer = BASE_COMPONENT_IDENTIFYER; //used to tell ents which component is which

public:
	BaseEntity *SelfOwner = nullptr; //which ent do we belong to

	string GetIdentifyer();

	virtual void ReceiveFireInstruction(string Message, string Value);
	virtual void Update(float DeltaTime); //all of this is the same as the ent
	virtual void Start();

	static bool IsVaild(BaseComponent* EntCom);
};

