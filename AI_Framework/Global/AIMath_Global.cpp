#include "AIMath_Global.h"


AIMath_Global* AIMath_Global::instancePointer = nullptr;

AIMath_Global* AIMath_Global::getInstance()
{

	if (instancePointer == nullptr)
	{
		instancePointer = new AIMath_Global();
	}

	return(instancePointer);
}


int AIMath_Global::ConvertScreenPosToGridPos(float screenPos)
{

    return (int) (screenPos / mapSectionXY);
}

float AIMath_Global::ConvertGridPosToSreenPos(int gridPos)
{

    return (gridPos * mapSectionXY);
}




float AIMath_Global::calc(Vector2f _p1, Vector2f _p2, Vector2f _p3)
{

	
	return(_p1.x - _p3.x) * (_p2.y - _p3.y) - (_p2.x - _p3.x) * (_p1.y - _p3.y);
}



bool AIMath_Global::isPointInTriange(Vector2f _p1, Vector2f _p2, Vector2f _p3, Vector2f _point)
{
	bool n1 = false;
	bool n2 = false;

	float d1 = calc(_point, _p1, _p2);
	float d2 = calc(_point, _p2, _p3);
	float d3 = calc(_point, _p3, _p1);

	n1 = (d1 < 0) || (d2 < 0) || (d3 < 0);
	n2 = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(n1 && n2);
}


float AIMath_Global::CalcDistance(Vector2f _p1, Vector2f _p2)
{
	return sqrt( ( (_p1.x - _p2.x) * (_p1.x - _p2.x) ) + ( (_p1.y - _p2.y) * (_p1.y - _p2.y) ) );
}


float AIMath_Global::CalcManhattanDistance(Vector2f _p1, Vector2f _p2)
{
	return abs(_p1.x - _p2.x) + abs(_p1.y - _p2.y);
}

float AIMath_Global::CalcRotation(Vector2f _p1)
{
	Vector2f vecD(0, 1);

	float _r = atan2(_p1.y, _p1.x) - atan2(vecD.y, vecD.x);
	return(_r);
}

AIMath_Global::Vector2f AIMath_Global::RotatePoint(Vector2f _p1, float rotation)
{
	Vector2f p1_rot(_p1.x * cos(rotation) - _p1.y * sin(rotation), _p1.x * sin(rotation) + _p1.y * cos(rotation));

	return (p1_rot);
}



