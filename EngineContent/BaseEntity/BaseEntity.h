#pragma once

#include <String>
#include <Vector>
#include <Map>
#include <iostream>
#include <fcntl.h>
#include <io.h>

#include "../Marcos/Marcos.h"
#include "../BaseComponent/BaseComponent.h"
#include "../RenderingModifier/RenderingModifier.h"

using namespace std;

class BaseComponent;

struct RenderingInfo
{
	int OffsetX = 0;
	int OffsetY = 0;
	vector<string> ContentsToRender = vector<string>();
	int Importance = 0;
	RenderingModifier *MyModifyer = new RenderingModifier();
};

class BaseEntity
{
private:
	map<string, string> KeyValueList;
	static vector<unique_ptr<BaseEntity> *> EntityiesInRunTime;
	vector<unique_ptr<BaseComponent> *> MyComponents;

	unique_ptr<BaseEntity> Test;

protected:
	RenderingInfo MyRenderingInfo;

	virtual void ReceiveFireInstruction(string Message, string Value); //reacts to a message and value

public:
	virtual void Update(float DeltaTime); //runs on tick in endless loop
	virtual void Start(); //runs after spawn
	virtual void OnRemove();
	
	void Fire(string Message, string Value); //send a message and a value

	void SetKeyValue(string Key, string Value); //key = entity setting && value = what it should be set to
	string GetValueOfKey(string Key); //gets the value of a setting
	
	static void AddComponent(BaseEntity* Ent, BaseComponent* Com); //Components are like mini entits that cant render or store keys but they can effect the entity there attached to
	static BaseComponent* GetComponent(BaseEntity* Ent, string Identifyer);
	static void RemoveComponent(BaseEntity* Ent, string Identifyer);

	static void Spawn(BaseEntity* Ent); //regiestes the entity with the engine so it can render stuff and update
	static void Remove(BaseEntity* Ent); //unregiestes the entity with engine
	static void RemoveAll(); //destroys all entitys usful for unloading a level

	static bool IsVaild(BaseEntity* Ent); //is a given ent valid (ie has it been spawned and is it not destroyed)
	static void ProcessUpdate(float DeltaTime);
	static void ProcessRendering(int X, int Y, bool NewLineAfter); //renders a charizals into the console //charizals are like pixles but for letters
	
};
