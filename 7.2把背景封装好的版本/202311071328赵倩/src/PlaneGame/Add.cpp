#include "stdafx.h"
#include "resource.h"
#include"Add.h"




GameLevelHandler::GameLevelHandler()
{
	_level = 1;
}


void GameLevelHandler::BackGround(int level, CDC* pMemDC)
{

	//��������
	if (level == 1)
	{
		static int ImageLocation = 0;//����ͼƬ��ȡλ�ó�ʼλ��
		CDC m_CDC;//������
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BACKGROUNAD1);//����λͼ
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//���ö�̬����
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}
	if (level == 2)
	{
		static int ImageLocation = 0;//����ͼƬ��ȡλ�ó�ʼλ��
		CDC m_CDC;//������
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BACKAGROUND2);//����λͼ
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//���ö�̬����
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}
	if (level == 3)
	{
		static int ImageLocation = 0;//����ͼƬ��ȡλ�ó�ʼλ��
		CDC m_CDC;//������
		m_CDC.CreateCompatibleDC(pMemDC);
		CBitmap m_bmp;
		m_bmp.LoadBitmapW(IDB_BACKGROUND3);//����λͼ
		CBitmap* pbmpold = m_CDC.SelectObject(&m_bmp);
		pMemDC->BitBlt(0, ImageLocation, GAME_WIDTH, GAME_HEIGHT - ImageLocation, &m_CDC, 0, 0, SRCCOPY);//���ö�̬����
		pMemDC->BitBlt(0, 0, GAME_WIDTH, ImageLocation, &m_CDC, 0, GAME_HEIGHT - ImageLocation, SRCCOPY);
		m_CDC.SelectObject(pbmpold);
		ImageLocation++;
		if (ImageLocation == GAME_HEIGHT)
			ImageLocation = 0;
	}

}
