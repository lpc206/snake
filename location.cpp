#include "location.h"
Location::Location(int x, int y)
{
	m_x = 40*x;
	m_y = 40*y;
}
//Location::Location() {}
//静态成员类外初始化
int Location::len = 5;
Location* Location::array[5] = {new Location(1,7),new Location(2,7),
						new	Location(3,7),new Location(4,7),new Location(5,7) };