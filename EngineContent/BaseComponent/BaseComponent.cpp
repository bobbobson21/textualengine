#include "BaseComponent.h"

void BaseComponent::Start()
{
}

string BaseComponent::GetIdentifyer()
{
	return Identifyer;
}

void BaseComponent::ReceiveFireInstruction(string Message, string Value)
{
}


void BaseComponent::Update(float DeltaTime)
{
}


bool BaseComponent::IsVaild(BaseComponent* EntCom)
{
	try
	{
		if (EntCom->SelfOwner == nullptr) { return false; } //if our ent is null pointer we are not valid
		return BaseEntity::IsVaild(EntCom->SelfOwner); //if our ent is valied we are valid
	}
	catch (...)
	{
		return false; //we are not valid
	}

}