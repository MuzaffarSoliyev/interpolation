������������
============

������: ������������ ��������������� ��������� (������� ��������������� ���� � ������������ ��������).
--------------------------------------------------------------------------

��������: ������ �������� / ������: �1-15
-------------------------------------------

==================
������ ���������:

> <�������� ������������ �����>(.exe) <������� ����> <�������� ����> <���������>

��� ���������:
  -d    	����� � ������� ��������� ������� � ���� ������� [��-��������� ����]
  -e    	����� ������ [��-��������� ����]
  -p    	����� ������� � ����� ������ [��-��������� ����]
  -t    	����� ������� ���������� ��������� [��-��������� ����]
  -h, -?	�������
  
�� ��������� �������/�������� ����:
46_21_in.txt
46_21_out.txt
==================
error - ���� ������
debug - ���� �������

���� ������
	 0 - ������ ���.
	-1 - ������� ���� �� ������.
	-2 - ���� ���� ���� ���������� �������� ������ ����.
	-3 - �� ������� �������� ������.
	-4 - �� ������� ������� ������� �������.
	-5 - �������� ���� �� ������.
	-6 - ������ �������� ��������.


______________________________________
size_t stringLength(const char *str)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
���������:
const char *str - ��������� �� ������
- ������� ���������� ���������� �������� � ������ str.
���������� ��� �������, ���� �� ���������� ������('\0') � �����������
�������. ����� ����������� ������ ������� ������ ���������� �������� ��������.

_______________________________________________________
int stringComp(const char *str1, const char *str2)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
���������:
const char *str1 - ��������� �� ������ ������
const char *str2 - ��������� �� ������ ������
- ������� ����������� ���������� ��� ������ (str1 � str2) � ������:
	-1 - ����� ����� ���� ����� ������ ��� ��� ������ ������
	 0 - ����� ��� ������ ���������
	 
______________________________________________________________________________________________________________________________________________
void Coeff_46_21(int n, double *x, double *f_x, double *ksi, double *c1, double *c2, double *c3,double x0,double f_x0,double xn1,double f_xn1)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
���������:
n - ���������� �������� �����
x - �������� �����
f_x - �������� ������� � �������� ������
ksi - �������������� �����, �� ������� �������� ��������� ��������������� �������
c1 - ������ ����������� ������������
c2 - ������ ����������� ������������
c3 - ������ ����������� ������������
x0 - ������ �������������� �����
f_x0 - �������� ������� � ������ �������������� �����
xn1 - ������ �������������� ����� 
f_xn1 - �������� ������� �� ������ �������������� �����
- ������ ��������� ������ ��������������� �������� 
��������:
������� ������ n-1 ���������c n+1 ������������ �� �������: (8) ������� �.�"��������� �� ���. ������ ����������� �������". ��� 83
� ������� �������������� ������� � ������������ ������ �������� ��� ������������� ���������.
�������� ��������������� �������.

______________________________________________________________________________
void SolveSystem(int n, double *a, double *c, double *d, double *b, double *x)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
���������:
n - ����� ��������� � �������
a - �������� ������� ��������� ��������������� �������
c - �������� ����������� ��� ������� ���������� 
d - �������� ����������� ��� ������� ���������� 
b - ������ ��������� ������
x - ������ ����������
��������:
 - ������ ��������� ������� �������� ������ ������� �������� ���������. ����� ����� ������� � ������ x.

__________________________________________________________________________________
double Value_46_21(double t, int n, double *c1,double *c2,double *c3, double *ksi)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
���������:
t - ����� � ������� ����� ��������� �������� �������
n - ��������� ������� �����
c1 - ������ ����������� ������������
c2 - ������ ����������� ������������
c3 - ������ ����������� ������������
ksi - �������������� �����, �� ������� �������� ��������� ��������������� �������
��������:
������� ������� � ����� ������� ��������� t(�� ksi) � ��������� �������� �������.
