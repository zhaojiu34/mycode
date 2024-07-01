#pragma once
#include "GameObject.h"


class GameLevelHandler
{
public:

	GameLevelHandler();

	void BackGround(int level, CDC* pMemDC);


private:
	int _level;

};
