// MyClass.h: interface for the CMyClass class.        //MyClass�����ͷ�ļ�
//
//////////////////////////////////////////////////////////////////////
typedef  double   array2d[5][5];
typedef  double   array[24];

/***********************************************************
* ����˵���� X, Y, C,Ϊһά ���飬���ͼ�ζ���������꣬
XT, YT,��Ϊһά���飬���ͼ�ζ��㾭�任�������ֵ��*
* A, A1��ά�����������ձ任����                   *
***********************************************************/

class CMyClass  // ����һ������
{
public:
	int       xx, yy;
	array     X, Y, Z, C, XT, YT;
	array2d   A1,A;
public:
	CMyClass();
	virtual ~CMyClass();
	void ReadWorkpiece();
	void Calculate(array2d B);
	void Display ();
	void DrawView (CDC* pdc,CRect rr);
	void moveto(double x,double y,CDC* pdc);
	void lineto(double x,double y,CDC* pdc);
};
