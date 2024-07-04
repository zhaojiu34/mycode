#pragma once




class game_interface
{
public:
	void BackGround(CDC** ppMemDC, int& level);

	void Myplane_interface(CDC** ppMemDC, int& level,int& blood, int& score,int& bigboll);

	void Function_interface(CDC** ppMemDC);
};