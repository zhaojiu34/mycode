#pragma once


//����Ϸ�ĸ��ֹ��ܺ������ڸ��Ե����ж���ɾ�̬��Ա������
// ����PlanGameView.cpp�е�AI�������е�����ʵ�ָ��ֹ��ܡ�

//��Ϸ����
//������Ϸ����ĳ�����CGameObject��
//��Ϸ����ĸ��ࣺ��������̳��˴���
class CGameObject : public CObject
{
public:

	CGameObject(int x=0,int y=0);

	//���������������������������������ʱ�򣬵�����̳и��࣬�����ָ��ָ������ʱ
	//delete�������ָ�룬�ȵ�������������������ٵ������������������
	//����������
	virtual ~CGameObject();
	
	//���ƶ���
	virtual BOOL Draw(CDC* pDC,BOOL bPause)=0;

	//��þ�������
	virtual CRect GetRect()=0;

	//������Ͻ�����
	CPoint GetPoint()
	{
		return m_ptPos;
	}

protected:
	//����ͼ�� ��̬��Ա����
	static BOOL LoadImage(CImageList& imgList,UINT bmpID,COLORREF crMask,int cx,int cy,int nInitial);
protected:
	//�����λ��
	CPoint  m_ptPos;
	CPoint  m_ptPos_move;
};


