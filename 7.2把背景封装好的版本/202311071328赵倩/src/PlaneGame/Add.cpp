#include "stdafx.h"
#include "resource.h"
#include"Add.h"




GameLevelHandler::GameLevelHandler()
{
	_level = 1;
}


void GameLevelHandler::BackGround(int level, CDC* pMemDC)
{

	//¹ö¶¯±³¾°
	if (level == 1)
	{
		static int ImageLocation = 0;//±³¾°Í¼Æ¬½ØÈ¡Î»ÖÃ³õÊ¼Î»ÖÃ
		CDC m_CDC;//»º³åÇø
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BACKGROUNAD1);//´´½¨Î»Í¼
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//ÉèÖÃ¶¯Ì¬±³¾°
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}
	if (level == 2)
	{
		static int ImageLocation = 0;//±³¾°Í¼Æ¬½ØÈ¡Î»ÖÃ³õÊ¼Î»ÖÃ
		CDC m_CDC;//»º³åÇø
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BACKAGROUND2);//´´½¨Î»Í¼
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//ÉèÖÃ¶¯Ì¬±³¾°
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}
	if (level == 3)
	{
		static int ImageLocation = 0;//±³¾°Í¼Æ¬½ØÈ¡Î»ÖÃ³õÊ¼Î»ÖÃ
		CDC m_CDC;//»º³åÇø
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BACKGROUND3);//´´½¨Î»Í¼
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//ÉèÖÃ¶¯Ì¬±³¾°
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}

}
