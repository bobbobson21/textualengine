#pragma once

#include <Vector>
#include <String>

#include "../BaseEntity/BaseEntity.h"

using namespace std;

class BaseEntity;

class BaseComponent
{
public:
	string Identifyer = "NONE";
	BaseEntity *SelfOwner = nullptr;
	virtual void Update(float DeltaTime);
	virtual void Start();

	bool IsValid();
};

