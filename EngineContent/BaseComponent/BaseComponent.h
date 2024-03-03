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
	virtual ~BaseComponent() {}

	BaseEntity *SelfOwner = nullptr; //which ent do we belong to

	string GetIdentifyer();

	virtual void OnKeyValueSet(string Key, string Value);
	virtual void ReceiveFireInstruction(string Message, string Value);
	virtual void Update(float DeltaTime); //all of this is the same as the ent
	virtual void Start();
	virtual void OnRemove();

	static bool IsVaild(BaseComponent* EntCom);
};

