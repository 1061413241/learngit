#ifndef HEROES_H
#define HEROES_H
#include<string>
#include<iostream>
#include<time.h>

class skill;
clock_t currentTime;
using namespace std;
class heroes
{
public:
	skill *s;
	heroes *anm;
	double HP, HPmax, level , EXP , EXPmax, speed, attack, attack_range , attack_speed;//一般属性
	int x, y;
	int initial_x, initial_y;
	clock_t dieTime,attime;
	string name;//英雄名称
	bool death;
    void Attack(heroes &p);//普通攻击纯虚函数
	void skill_attack(heroes &p,string a);//技能攻击纯虚函数
	void islevelup();//判断是否升级纯虚函数
	void dead();//告知英雄是否死亡的函数
	void HPfull();//复活后生命值回满
	void attribute_up();//升级后生命值上限和攻击力提升
	void feedback();//根据消灭敌方的类型得到反馈
	void reset();//英雄死亡后限制行动、位置重置
	void move(char c);
	heroes(int a=0, int b=0){
		attime=clock();
	initial_x=a;
	initial_y=b;
	level = 10, EXP = 0, EXPmax = 100, speed, attack, attack_range = 3, attack_speed = 1;
	}
	~heroes(){}
};
heroes *hero1[2];


class skills
{
protected:

public:
	int CD, attack_range, hurt, recovery, shift, add_attack;
	clock_t bg,ed;
	virtual bool judge(heroes &p)=0;//判断等级是否可以使用技能
	skills(){
	}
	~skills(){
	}
};

class chengjie :public skills {
public:
	chengjie()
	{
		bg=clock();
		CD = 30;
		attack_range = 3;
		hurt = 650;
	}
	void Hurt(heroes &p)//对英雄造成伤害
	{
		if(p.HP<=0)return ;
		p.HP -= hurt;
		p.dead();
	}
	void use(heroes &p)
	{
		ed=clock();
		if(ed-bg<CD*1000)return ;
		bg=ed;
		Hurt(p);
	}
	virtual bool judge(heroes &p)
	{
		if (p.level >= 6) return true;
		return false;
	}
};

class zhansha :public skills {
public:
	zhansha()
	{
		CD = 10;
		attack_range = 5;
		hurt = 600;
	}
	void Hurt(heroes &p)//对英雄造成伤害
	{
		if(p.HP<=0)return ;
		p.HP -= hurt;
		p.dead();
	}
	void use(heroes &p)
	{
		ed=clock();
		if(ed-bg<CD*1000)return ;
		bg=ed;
		Hurt(p);
	}
	virtual bool judge(heroes &p)
	{
		if (p.level >= 4) return true;
		return false;
	}
};
class kuangbao :public skills
{
public:
	kuangbao()
	{
		CD = 90;
	}
	void AddAttack(heroes &p)//增加攻击力
	{
		if(p.HP<=0)return ;
		p.attack *= 1.5;
	}
	void use(heroes &p)
	{
		ed=clock();
		if(ed-bg<CD*1000)return ;
		bg=ed;
		AddAttack(p);
	}
	virtual bool judge(heroes &p)
	{
		if (p.level >= 5) return true;
		return false;
	}
};
class shanxian :public skills 
{
public:
	int move_dis;
	shanxian()
	{
		CD = 75;
		move_dis = 3;
	}
	void Shift(heroes &p)//实现英雄的移动（闪现）
	{
		p.x += 3;
	}
	void use(heroes &p)
	{
		ed=clock();
		if(ed-bg<CD*1000)return ;
		bg=ed;
		Shift(p);
	}
	virtual bool judge(heroes &p)
	{
		if (p.level >= 6) return true;
		return false;
	}
};

class zhiliaoshu :public skills {
	int recover;
public:
	zhiliaoshu()
	{
		CD = 120;
		recover = 1000;
	}
	void Recovery(heroes &p)//实现生命值恢复
	{
		p.HP += recover;
	}
	void use(heroes &p)
	{
		ed=clock();
		if(ed-bg<CD*1000)return ;
		bg=ed;
		Recovery(p);
	}
	virtual bool judge(heroes &p)
	{
		if (p.level >= 3) return true;
		return false;
	}
};











void heroes::move(char c)
{
	if(HP<=0)
	reset();
	if(HP<=0)return ;
	switch(c)
	{
		case 'w':y--;if(y<0)y=0;break;
		case 's':y++;if(y>9)y=9;break;
		case 'a':x--;if(x<0)x=0;break;
		case 'd':x++;if(x>27)x=27;break;
		case 'u':skill_attack(*this,"shanxian");break;
		case 'i':skill_attack(*this,"zhiliaoshu");break;
		case 'j':skill_attack(*anm,"zhansha");break;
		case 'k':skill_attack(*this,"kuangbao");break;
		case 'l':skill_attack(*anm,"chengjie");break;
		
		case '1':skill_attack(*this,"shanxian");break;
		case '2':skill_attack(*this,"zhiliaoshu");break;
		case '3':skill_attack(*anm,"zhansha");break;
		case '4':skill_attack(*this,"kuangbao");break;
		case '5':skill_attack(*anm,"zhansha");break;
		case 'H':y--;if(y<0)y=0;break;
		case 'P':y++;if(y>9)y=9;break;
		case 'K':x--;if(x<0)x=0;break;
		case 'M':x++;if(x>27)x=27;break;
	}
}

class lianpo :public heroes {
public:
	lianpo(int a,int b):heroes(a,b)
	{
		name="廉颇";
     HP = HPmax = 3165;
	attack = 161;
	speed = 1;
	death = false;
	}
	
};

class xiaoqiao :public heroes {
public:
	xiaoqiao(int a,int b):heroes(a,b)
	{
		name="小乔"; 
   HP = HPmax = 2497;
	attack = 151;
	speed = 2;
	death = false;
	}
	
};

class houyi :public heroes {
public:
	houyi(int a,int b):heroes(a,b)
	{
		name="后羿";
		HP = HPmax = 2728;
		attack = 171;
		speed = 1;
		death = false;
	}
};

class liubang :public heroes {
public:
	liubang(int a,int b):heroes(a,b)
	{
		name="刘邦";
		HP = HPmax = 3369;
		attack = 158;
		speed = 1;
		death = false;
	}
};

class sunwukong :public heroes {
public:
sunwukong(int a,int b):heroes(a,b)
	{
		name="猴男" ;
		HP = HPmax = 2876;
		attack = 167;
		speed = 2;
		death = false;
	}
};

class sunshangxiang :public heroes {
public:
	sunshangxiang(int a,int b):heroes(a,b)
	{
		name="炮女"; 
		HP = HPmax = 2604;
		attack = 171;
		speed = 1;
		death = false;
	}
};










void heroes::Attack(heroes &p)
{
	currentTime=clock();
	if(currentTime - attime < 1000)return ;
	attime=currentTime;
	p.HP -= attack;
	p.dead();
}
void heroes::skill_attack(heroes &p,string a)
{  
    if(a=="chengjie")
   {
   	chengjie r;
   	 if(r.judge(p))
   	 {
   		r.use(p);
	}
   }
   else if(a=="zhansha")
   {
   	zhansha r;
   	 if(r.judge(p))
   	 {
   	r.use(p);
	}
   }
   else if(a=="shanxian")
   {
   	shanxian r;
   	if(r.judge(p))
   	{
   		r.use(p);
	}
   }
   else if(a=="kuangbao")
   {
   	kuangbao r;
   	if(r.judge(p))
   	{
   		r.use(p);
	}
   }
   else if(a=="zhiliaoshu")
   {
   	zhiliaoshu r ;
   	if(r.judge(p))
   	{
   		r.use(p);
	}
   }
}
void  heroes::islevelup()
{
	if (EXP >= EXPmax) {
		level++;
	}
}
void heroes::dead()
{
	if (HP <= 0)
	{
		HP=0;
		x=-initial_x;
		y=-initial_y;
		dieTime=clock();
	}
}
void heroes::HPfull()
{
	HP = HPmax;
}
void heroes::attribute_up()
{
		HP = HPmax * 1.05;
		attack *= 1.05;
		EXP -= EXPmax;
		EXPmax *= 1.2;
}

void heroes::feedback()
{
	HP += 5;
	if (HP > HPmax)
		HP = HPmax;
	EXP += 10;
}

void heroes::reset()
{
	currentTime=clock();
	if (currentTime - dieTime < 10000)return ;
	dieTime=currentTime;
	HP = HPmax;
	x=initial_x;
	y=initial_y;
}
//bool heroes::judge()
//{

//}
class turret
{
	public:
	int HP;
	string name;
	int attack ,x ,y;
	turret(int a=0, int b=0,string x="0"):HP(3000),attack(300),x(a),y(b),name(x){} ;
	void attack_action(heroes &p)
	{
		if((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)<=3) 
		{
			p.HP-=attack;
			HP-=p.attack;
		}
	}
};
class spring
{
   public:
   int recover,x,y;
   spring(int a, int b):recover(500),x(a),y(b){};
   void recovery(heroes &p)
   {
   	 if((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)<=3) p.HP+=recover;
   }	
};
#endif
