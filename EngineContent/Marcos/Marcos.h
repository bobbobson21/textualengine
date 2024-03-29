#pragma once
#include <String>

#define STR_NULL "NULL"
#define WSTR_NULL L"NULL"

#define BASE_ENTITY_IDENTIFYER "NONE_ENT"
#define BASE_COMPONENT_IDENTIFYER "NONE_COMPONENT"

#define INT_INVALID INT_MIN +2

#define TYPE_REP( X ) X()

#define CHARIZAL_AS_PIXLES_X 9
#define CHARIZAL_AS_PIXLES_Y 19

#define INVALIDATE_DELETE( X ) delete X; X = nullptr

#define DELTA_SHINK( X ) X/100000000