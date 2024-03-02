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

class BaseEntity;
class BaseComponent;

struct BaseEntity_RenderingInfo //for rendering
{
	int OffsetX = 0;
	int OffsetY = 0;
	vector<string> ContentsToRender = vector<string>();
	int Importance = 0;
	RenderingModifier *MyModifyer = new RenderingModifier();
};

struct BaseEntity_FireOutInfo //for firing out to other ents
{
	BaseEntity *Ent = nullptr;
	string Message = "";
	string Value = "";
};

class BaseEntity
{
private:
	map<string, string> KeyValueList;
	static vector<BaseEntity*> EntityiesInRunTime;
	vector<BaseComponent*> MyComponents;

	map<string, vector<BaseEntity_FireOutInfo>> FireOuts;

protected:
	BaseEntity_RenderingInfo MyRenderingInfo;
	string Identifyer = ""; //BASE_ENTITY_IDENTIFYER;

	virtual void ReceiveFireInstruction(string Message, string Value); //reacts to a message and value
	void FireOut(string Condition); //rasies a condition
public:
	virtual ~BaseEntity() {}; //we dont need it but we have it delete is a bitch

	string GetIdentifyer();

	virtual void Update(float DeltaTime); //runs on tick in endless loop
	virtual void Start(); //runs after spawn
	virtual void OnRemove();
	
	void Fire(string Message, string Value); //send a message to an entatity
	void AddFireOut( BaseEntity* FireOutTo, string Condition, string Message, string Value); //if condition is rasied a massage along with a value is sent to fire out //send message from entity
	void RemoveAllFireOut();
	void RemoveAllFireOutByEnt(BaseEntity* FireOutTo, string Condition); //removes the fire outs
	void RemoveAllFireOutByEnt(BaseEntity* FireOutTo); //removes the fire outs
	void RemoveAllFireOutByID(string Identifyer, string Condition); //removes the fire outs
	void RemoveAllFireOutByID(string Identifyer); //removes the fire outs

	void SetKeyValue(string Key, string Value); //key = entity setting && value = what it should be set to
	string GetValueOfKey(string Key); //gets the value of a setting
	
	static void AddComponent(BaseEntity* Ent, BaseComponent* Com); //Components are like mini entits that cant render or store keys but they can effect the entity there attached to
	static vector<BaseComponent *> GetComponents(BaseEntity* Ent, string Identifyer);
	static void RemoveAllComponentsOfID(BaseEntity* Ent, string Identifyer);

	static void Spawn(BaseEntity* Ent); //regiestes the entity with the engine so it can render stuff and update
	static void Remove(BaseEntity* Ent); //unregiestes the entity with engine
	static void RemoveAll(); //destroys all entitys usful for unloading a level
	static void RemoveAllOfID(string Identifyer); //destroys all entitys usful for unloading a level

	static vector<BaseEntity *> GetEntities(string Identifyer); //destroys all entitys usful for unloading a level

	static bool IsVaild(BaseEntity* Ent); //is a given ent valid (ie has it been spawned and is it not destroyed)
	static void ProcessUpdate(float DeltaTime);
	static void ProcessRendering(int X, int Y, bool NewLineAfter); //renders a charizals into the console //charizals are like pixles but for letters
	
};
