#pragma once
#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

//一对多设计   一个主题  多个观察  报纸和订阅报纸的实例
//Head First
static const int FLAGSAVE = 1;
class Object
{
public:
	Object(){}
	~Object(){}
public:
	virtual void update(float temp, float humid, float pressur) {};
};

class Subject
{
public:
	Subject(){}
	~Subject(){}

public:
	virtual void registObject(Object *obj) {};
	virtual void removeObject(Object *obj) {};
	virtual void notifyAll() {};//主题改变通知所有
};

class Display
{
public:
	Display(){}
	~Display(){}
public:
	virtual void display() {};//显示面板使用
};
typedef map<Object*, int> ObjectMap;
class Weather :public Subject
{
public:
	Weather(){}
	~Weather(){}
private:
	float _temp;
	float _humid;
	float _pressur;
	ObjectMap _obj_map;
public:
	void registObject(Object *obj)
	{
		if (obj)
			_obj_map.insert(ObjectMap::value_type(obj, FLAGSAVE));
	}
	void removeObject(Object *obj)
	{
		ObjectMap::iterator iter = _obj_map.find(obj);
		if (iter != _obj_map.end())
		{
			_obj_map.erase(iter);
		}
	}
	void notifyAll()
	{
		ObjectMap::iterator iter = _obj_map.begin();
		for (; iter != _obj_map.end(); iter++)
		{
			Object *object = iter->first;//得到 每个通知
			object->update(_temp,_humid,_pressur);
		}
	}
	//有新数据 就通知
	void dataChange()
	{
		notifyAll();
	}
	//得到内部属性状态
	float getTemp()
	{
		return _temp;
	}
	float getHumid()
	{
		return _humid;
	}
	float  getPressur()
	{
		return _pressur;
	}

	void setData(float temp, float humid, float pressur)
	{
		_temp = temp;
		_humid = humid;
		_pressur = pressur;
		dataChange();
	}
	//其他方法
};

//显示布告栏 具体布告栏 多重继承
class CurDiaplay :public Object, public Display
{
public:
	CurDiaplay(){}
	CurDiaplay(){}
private:
	float _temp;
	float _humid;
	float _pressur;
	Weather *_wea_data;//天气数据
	
public:
	CurDiaplay(Weather *wea_data)//构建主题  不能够定义虚函数类
	{
		this->_wea_data = wea_data;
		wea_data->registObject(this);
	}
	void update(float temp, float humid, float pressur)
	{
		_temp = temp;
		_humid = humid;
		display();
	}
	void diaplay()
	{
		cout << "111" << endl;
	}
};

//客户端
void ClientStart()
{

	Weather *wea = new Weather();
	CurDiaplay *cur_dis = new CurDiaplay(wea);
	//其他类实现的方法 和CurDiaply相似
	wea->setData(80, 65, 30.1);
};













//抽象接口 通知类  通知可能是两个或者多个  不确定
class Subject
{
public:
	virtual void Attach(/*GuanCaZhe* guanca*/) {}
	virtual void Detach(/*GuanCaZhe* guanca*/) {}
	virtual void Notify() {}
	string SubjectState() { return ""; }
};


class GuanCaZhe
{
public:
	GuanCaZhe();
	~GuanCaZhe();
public:
	//具体的改成抽象通知者Subject
	GuanCaZhe(string name, Subject *sub)
	{
		this->name = name;
		this->sub = sub;
	}
	virtual void upDate()
	{
		//cout << "close" << name;
	}
private:
	string name;
	Subject *sub;
};




class Boss :public Subject
{
private:
	list<GuanCaZhe*>list_guan;
	string action;

public:
	void Attach(GuanCaZhe *obser)
	{
		list_guan.push_back(obser);//将观察者 加入列表 用来通知
	}

	void Detach(GuanCaZhe *obser)
	{
		list_guan.remove(obser);
	}

	void Notify()
	{
		//通知 所有登记的人
		for (auto o : list_guan)
		{
			//通知列表里面的人
			o->upDate();
		}
	}
	//前台得到状态
	string BossAction()
	{
		return action;//
	}
};

class Secretary:public Subject
{
private:
	list<GuanCaZhe*>list_guan;
	string action;

public:
	void Attach(GuanCaZhe *obser) 
	{
		list_guan.push_back(obser);//将观察者 加入列表 用来通知
	}
	
	void Detach(GuanCaZhe *obser)
	{
		list_guan.remove(obser);
	}
	
	void Notify()
	{
		//通知 所有登记的人
		for (auto o : list_guan)
		{
			//通知列表里面的人
			o->upDate();
		}
	}
	//前台得到状态
	string SecretAction()
	{
		return action;//
	}
};

//具体观察者 继承基类
class GuanCaA :public GuanCaZhe
{
public:
	//具体的改成抽象通知者Subject *sub
	GuanCaA(string name, Subject *sub) :GuanCaZhe(name, sub)
	{

	}
	void upDate()
	{
		cout << "closeA";
	}
};

