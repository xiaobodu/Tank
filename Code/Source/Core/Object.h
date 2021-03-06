#ifndef ___OBJECT__20150122___
#define ___OBJECT__20150122___

#include <windows.h>
#pragma warning(disable : 4786)
#include <set>

class CObject
{
public:
	CObject();
	virtual ~CObject();

public:
	void AddChild(CObject *pChild);
	void RemoveChild(CObject *pChild);
	
	void MoveTo(int x, int y);
	void Offset(int dx, int dy);
	int  GetLeft() const { return m_nPosX; }
	int  GetTop() const { return m_nPosY; }

	void SetWidth(int nWidth);
	void SetHeight(int nHeight);
	int  GetWidth() const { return m_nWidth; }
	int  GetHeight() const { return m_nHeight; }

	void Show(bool bShow) { m_bShow = bShow; }
	bool HitTest(CObject *pOther) const;

public:
	virtual void OnFrame(float fDelta);
	virtual void OnRender();
	virtual void OnKey(int nKey);

protected:
	std::set<CObject *>			m_childrenSet;
	int							m_nPosX;
	int							m_nPosY;
	int							m_nWidth;
	int							m_nHeight;
	bool						m_bShow;
};

#endif
