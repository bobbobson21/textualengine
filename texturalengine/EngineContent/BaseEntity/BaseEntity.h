#pragma once

#include <String>
#include <Vector>
#include <Map>
#include <iostream>

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

public:
	virtual void Update(float DeltaTime);
	virtual void Start();

	static bool IsVaild(BaseEntity* Ent);

	void SetKeyValue(string Key, string Value);
	string GetValueOfKey(string Key);
	
	void AddComponent(BaseComponent& Com);
	BaseComponent& GetComponent(string Identifyer);
	void RemoveComponent(string Identifyer);

	void Spawn();
	void Remove();
	static void RemoveAll();

	static void ProcessUpdate(float DeltaTime);
	static void ProcessRendering(int X, int Y, bool NewLineAfter);
	
};
