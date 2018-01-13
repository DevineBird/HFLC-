#include"Object.h"
#include<cmath>
#include<iostream>
#include<fstream>
#define Round 6478137
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
const Vec north(0, 0, 1);
int main()
{
	//ofstream cout("D:/cout2.txt",ofstream::out);
	const Vec home(convert(117 + 14.0 / 60 + 57.98 / 3600, 31 + 50.0 / 60 + 34.33 / 3600, 33.0));
	//中国科学技术大学男生寝室2号楼 经度：117°14′57.98″，纬度：31°50′34.33″，海拔33米  数据来源：谷歌地球[2017/10/27]
	const Vec target(convert(117 + 28.0 / 60 + 9.47 / 3600, 30 + 40.0 / 60 + 2.0 / 3600, 19.0));
	//池州市政府门口花坛 经度：117°28′09.47″，纬度：30°40′02.00″，海拔19米 数据来源：谷歌地球[2017/1/21]
	for(double i=-622;i<-615;i+=0.2)
		for (double j = 860; j<940; j+=0.2)
			for (double k = -400; k < -100; k+=0.2)
			{
				Vec v(i, j, k);
				if ((angle(target - home, v) <50) && (angle(target - home, v) >25))//仰角
				{
					if (angle(target - home, v*home) > 88 && angle(target - home, v*home) < 92)//与目标地点的夹角，主要由科氏力造成影响，但也应该有一个大致范围
					{

						Object projectile(10, home, v);
						while (projectile.distance() > Round)
						{
							projectile.move();
						}

						if ((projectile.Position() - target).mo() < 40) 
						{
							cout << "与目标地的夹角为" << angle(target - home, v*home) - 90 << endl;
							cout << "方位角为" << 180 - angle(v*home, home*north) << endl;
							cout << "仰角为" << angle(target - home, v) << endl;
							cout << "速度大小为" << v.mo() << endl;
							v.print(cout);

							cout << (projectile.Position() - target).mo() << endl << endl;
						}
					}
				}
			}


	system("pause");
	return 0;
}

