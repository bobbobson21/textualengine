#include "BaseSaveObject.h"

bool BaseSaveObject::GetBool(unsigned int Index)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        return BoolArray[Index];
    }

    return false;
}

int BaseSaveObject::GetInt(unsigned int Index)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        return IntArray[Index];
    }

    return 0;
}

float BaseSaveObject::GetFloat(unsigned int Index)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        return FloatArray[Index];
    }

    return 0.0f;
}

char BaseSaveObject::GetChar(unsigned int Index)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        return CharArray[Index];
    }

    return 0;
}

string BaseSaveObject::GetString(unsigned int Index)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        return StringArray[Index];
    }

    return STR_NULL;
}


bool BaseSaveObject::SetBool(unsigned int Index, bool Value)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        BoolArray[Index] = Value;
        return true;
    }

    return false;
}

bool BaseSaveObject::SetInt(unsigned int Index, int Value)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        IntArray[Index] = Value;
        return true;
    }

    return false;
}

bool BaseSaveObject::SetFloat(unsigned int Index, float Value)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        FloatArray[Index] = Value;
        return true;
    }

    return false;
}

bool BaseSaveObject::SetChar(unsigned int Index, char Value)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        CharArray[Index] = Value;
        return true;
    }

    return false;
}

bool BaseSaveObject::SetString(unsigned int Index, string Value)
{
    if (Index < EngineSettings::Setting::SaveObjectSize)
    {
        StringArray[Index] = Value;
        return true;
    }

    return false;
}

