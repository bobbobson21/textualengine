#include "BaseComponent.h"

void BaseComponent::Start()
{
}


void BaseComponent::Update(float DeltaTime)
{
}


bool BaseComponent::IsValid()
{

	try
	{
		return BaseEntity::IsVaild(SelfOwner);
	}
	catch (...)
	{
		return false;
	}

}