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
	//�й���ѧ������ѧ��������2��¥ ���ȣ�117��14��57.98�壬γ�ȣ�31��50��34.33�壬����33��  ������Դ���ȸ����[2017/10/27]
	const Vec target(convert(117 + 28.0 / 60 + 9.47 / 3600, 30 + 40.0 / 60 + 2.0 / 3600, 19.0));
	//�����������ſڻ�̳ ���ȣ�117��28��09.47�壬γ�ȣ�30��40��02.00�壬����19�� ������Դ���ȸ����[2017/1/21]
	for(double i=-622;i<-615;i+=0.2)
		for (double j = 860; j<940; j+=0.2)
			for (double k = -400; k < -100; k+=0.2)
			{
				Vec v(i, j, k);
				if ((angle(target - home, v) <50) && (angle(target - home, v) >25))//����
				{
					if (angle(target - home, v*home) > 88 && angle(target - home, v*home) < 92)//��Ŀ��ص�ļнǣ���Ҫ�ɿ��������Ӱ�죬��ҲӦ����һ�����·�Χ
					{

						Object projectile(10, home, v);
						while (projectile.distance() > Round)
						{
							projectile.move();
						}

						if ((projectile.Position() - target).mo() < 40) 
						{
							cout << "��Ŀ��صļн�Ϊ" << angle(target - home, v*home) - 90 << endl;
							cout << "��λ��Ϊ" << 180 - angle(v*home, home*north) << endl;
							cout << "����Ϊ" << angle(target - home, v) << endl;
							cout << "�ٶȴ�СΪ" << v.mo() << endl;
							v.print(cout);

							cout << (projectile.Position() - target).mo() << endl << endl;
						}
					}
				}
			}


	system("pause");
	return 0;
}

