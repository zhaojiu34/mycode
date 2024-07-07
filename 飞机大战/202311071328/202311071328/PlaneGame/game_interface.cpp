#define _CRT_SECURE_NO_WARNINGS 1


#include "stdafx.h"

#include "resource.h"
#include "game_interface.h"
extern int level;



//绘制滚动背景
void game_interface::BackGround(CDC** ppMemDC,int& level)
{

	if (level == 1)
	{
		static int imagelocation = 0;
		CDC memDC;
		memDC.CreateCompatibleDC(*ppMemDC);
		CBitmap bmpDraw;
		bmpDraw.LoadBitmapW(IDB_BITMAP2);//创建位图
		CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
		(*ppMemDC)->BitBlt(0, imagelocation, 553, 945 - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
		(*ppMemDC)->BitBlt(0, 0, 553, imagelocation, &memDC, 0, 945 - imagelocation, SRCCOPY);
		imagelocation++;
		if (imagelocation == 945)
			imagelocation = 0;
	}
	if (level == 2)
	{
		static int imagelocation = 0;
		CDC memDC;
		memDC.CreateCompatibleDC((*ppMemDC));
		CBitmap bmpDraw;
		bmpDraw.LoadBitmapW(IDB_BITMAP10);//创建位图
		CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
		(*ppMemDC)->BitBlt(0, imagelocation, 553, 926 - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
		(*ppMemDC)->BitBlt(0, 0, 553, imagelocation, &memDC, 0, 926 - imagelocation, SRCCOPY);
		imagelocation++;
		if (imagelocation == 926)
			imagelocation = 0;
	}
	if (level == 3)
	{
		static int imagelocation = 0;
		CDC memDC;
		memDC.CreateCompatibleDC((*ppMemDC));
		CBitmap bmpDraw;
		bmpDraw.LoadBitmapW(IDB_BITMAP11);//创建位图
		CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
		(*ppMemDC)->BitBlt(0, imagelocation, 553, 926 - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
		(*ppMemDC)->BitBlt(0, 0, 553, imagelocation, &memDC, 0, 930 - imagelocation, SRCCOPY);
		imagelocation++;
		if (imagelocation == 926)
			imagelocation = 0;
	}
	if (level == 4)
	{
		static int imagelocation = 0;
		CDC memDC;
		memDC.CreateCompatibleDC((*ppMemDC));
		CBitmap bmpDraw;
		bmpDraw.LoadBitmapW(IDB_BITMAP13);//创建位图
		CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
		(*ppMemDC)->BitBlt(0, imagelocation, 553, 902 - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
		(*ppMemDC)->BitBlt(0, 0, 553, imagelocation, &memDC, 0, 902 - imagelocation, SRCCOPY);
		imagelocation++;
		if (imagelocation == 901)
			imagelocation = 0;
	}
	if (level == 5)
	{
		static int imagelocation = 0;
		CDC memDC;
		memDC.CreateCompatibleDC((*ppMemDC));
		CBitmap bmpDraw;
		bmpDraw.LoadBitmapW(IDB_BITMAP12);//创建位图
		CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
		(*ppMemDC)->BitBlt(0, imagelocation, 553, 881 - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
		(*ppMemDC)->BitBlt(0, 0, 553, imagelocation, &memDC, 0, 881 - imagelocation, SRCCOPY);
		imagelocation++;
		if (imagelocation == 881)
			imagelocation = 0;
	}

}


void game_interface::Myplane_interface(CDC** ppMemDC, int& level, int& blood, int& score,int& bigboll)
{
	CString strs = _T("My plane");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(30, 0, strs);//

	CString str;
	CString str1 = _T("Blood：");
	str.Format(_T("%d"), blood);
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(35, 20, str1);
	(*ppMemDC)->TextOut(65, 21, str);

	CString str2;
	CString str12 = _T("Score：    ");
	str2.Format(_T("   %d"), score);
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(35, 35, str12);
	(*ppMemDC)->TextOut(65, 36, str2);

	CString str3;
	CString str13 = _T("Level：");
	str3.Format(_T("%d"), level);
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(35, 50, str13);
	(*ppMemDC)->TextOut(65, 51, str3);

	CString str4;
	CString str14 = _T("Num of bomb:  ");
	str4.Format(_T("  %2d"), bigboll);
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(53, 65, str14);
	(*ppMemDC)->TextOut(105, 66, str4);


	CString st = _T("模式（切换）:");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(50, 90, st);
}


void game_interface::Function_interface(CDC** ppMemDC)
{
	CString str5 = _T("功能：");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(430, 0, str5);

	CString str6;
	CString str16 = _T("空格：炸弹");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(450, 20, str16);

	CString str7 = _T("Ctrl键：三发子弹");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(470, 40, str7);

	CString str8 = _T("P键：暂停");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(450, 60, str8);

	CString str9 = _T("C键：继续");
	(*ppMemDC)->SetBkMode(TRANSPARENT);
	(*ppMemDC)->SetTextAlign(TA_CENTER);
	(*ppMemDC)->SetTextColor(RGB(90, 90, 90));
	(*ppMemDC)->TextOut(450, 80, str9);

}