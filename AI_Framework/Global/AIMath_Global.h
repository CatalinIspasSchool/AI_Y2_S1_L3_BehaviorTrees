#pragma once

#include <cmath>

/*
CMP304/MAT501 AI Framework (2025)
*/


class AIMath_Global
{
public:

	struct Vector2f {
		float x;
		float y;

		Vector2f() {
			x =0;
			y =0;
		}

		Vector2f(float _x, float _y) {
			x = _x;
			y = _y;
		}
	};

	AIMath_Global(const AIMath_Global& obj) = delete;

	static AIMath_Global* getInstance();

	int ConvertScreenPosToGridPos(float screenPos);
	float ConvertGridPosToSreenPos(int gridPos);
	bool isPointInTriange(Vector2f _p1, Vector2f _p2, Vector2f _p3, Vector2f _point);
	float CalcDistance(Vector2f _p1, Vector2f _p2);
	float CalcManhattanDistance(Vector2f _p1, Vector2f _p2);
	float CalcRotation(Vector2f _p1);
	Vector2f RotatePoint(Vector2f _p1, float rotation);


private:
	const float mapSectionXY = 64.f;

	static AIMath_Global* instancePointer;
	AIMath_Global() {}
	float calc(Vector2f _p1, Vector2f _p2, Vector2f _p3);
	
};


