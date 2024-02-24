#pragma once

#include <String>
#include <Vector>
#include <Map>
#include <iostream>

#include "../Marcos/Marcos.h"
#include "../BaseComponent/BaseComponent.h"
#include "../RenderingModifier/RenderingModifier.h"

using namespace std;

class BaseComponent;

struct RenderingInfo
{
	int OffsetX = 0;
	int OffsetY = 0;
	vector<string> ContentsToRender;
	int Importance;
	RenderingModifier MyModifyer;
};

class BaseEntity
{
private:
	map<string, string> KeyValueList;
	static vector<BaseEntity *> EntityiesInRunTime;

protected:
	RenderingInfo MyRenderingInfo;
	vector<BaseComponent> MyComponents;
	int MyIndex = 0;

	virtual void ReceiveFireInstruction(string Message, string Value); //reacts to a message and value

public:
	virtual void Update(float DeltaTime); //runs on tick in endless loop
	virtual void Start(); //runs after spawn
	
	void Fire(string Message, string Value); //send a message and a value

	void SetKeyValue(string Key, string Value); //key = entity setting && value = what it should be set to
	string GetValueOfKey(string Key); //gets the value of a setting
	
	void AddComponent(BaseComponent& Com); //Components are like mini entits that cant render or store keys but they can effect the entity there attached to
	BaseComponent& GetComponent(string Identifyer);
	void RemoveComponent(string Identifyer);

	void Spawn(); //regiestes the entity with the engine so it can render stuff and update
	void Remove(); //unregiestes the entity with engine
	static void RemoveAll(); //destroys all entitys usful for unloading a level

	static bool IsVaild(BaseEntity* Ent); //is a given ent valid (ie has it been spawned and is it not destroyed)
	static void ProcessUpdate(float DeltaTime);
	static void ProcessRendering(int X, int Y, bool NewLineAfter); //renders a charizals into the console //charizals are like pixles but for letters
	
};
