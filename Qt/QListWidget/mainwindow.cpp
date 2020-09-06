#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;
//屏蔽一些警告
#pragma warning(disable : 4189)

//每次必需要取够30 个 不够就循环取出

static const int NUM = 3;
static const int len = 30;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cur(0),
    max_page(0),
    jieshu(0),//10
    kaishi(0),
    other_page(0),
    other(false),
    flag(false),
    s_a(0),
    e_a(30),
    is_small_th(false),
    first_load(true),
    first_index(0),
    last_index(0),
    less_first(0),
    less_last(0)
{
    ui->setupUi(this);
    initilize();
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(preClick()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(nextClick()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(loadData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//前提都是在30 以上。。。。如果不足30 就报错
void MainWindow::loadData()
{
    QString str = ui->lineEdit->text();
    res.push_back(str.toInt());
    qDebug() <<"loadData" << endl;
}


void MainWindow::initilize()
{
    for(int i=1;i<=29;i++)//小于30 出错
    {
       res.push_back(i);
    }

    max_page = ceil(double(res.size())/NUM);

   // other_page = ceil(double(res.size()%len)/NUM);
    //ceil向上取整
    /*if(res.size() < 30) //不足30的全部都修改
    {
        jieshu = res.size();
        if(e_a > res.size()) e_a = res.size();
        is_small_th = true;//小于30
    }
    else is_small_th = false;*/
    if(first_load)
    {
        e_a = res.size();
        if(e_a < 30){
            s_a = 0;
            //other_page = ceil(double(res.size())/NUM);//最大页数
            //cur = other_page;
            less_last = e_a;//初始索引位置
            less_first = e_a-3;
        }
        else
        {
            s_a = e_a-30;
            cur = 9;
        }
        vec.insert(vec.begin(),res.begin()+s_a,res.begin()+e_a);//初始化的时候

        first_index = s_a;
        last_index = res.size();
    }
    else
        vec.insert(vec.begin(),res.begin()+s_a,res.begin()+e_a);//初始化的时候

    for(int i=vec.size()-3;i<vec.size();i++)//
    {
        QString str = QString::number(vec[i]);
        ui->textEdit->append(str);
    }

    if(vec.size() < 3)
    {
        for(int i=0;i<vec.size();i++)//
        {
            QString str = QString::number(vec[i]);
            ui->textEdit->append(str);
        }
    }

    ui->pushButton_2->setEnabled(max_page>1);
    ui->pushButton->setEnabled(max_page>1);

    first_load = false;
}

bool MainWindow::valueSort(int &left,int &right)
{
    return left < right;
}

void MainWindow::getInfo()
 {
     //排序
     std::sort(res.begin(),res.end(),MainWindow::valueSort);

     max_page = ceil(double(res.size())/NUM);

     other_page = ceil(double(res.size()%len)/NUM);
     //ceil向上取整
     ui->textEdit->clear();

     if(s_a < 0)
     {
         if(e_a < 0)
         {
             int temp_end = res.size() + e_a;
             int temp_start = res.size() + s_a;
             vec.insert(vec.begin(),res.begin() + temp_start,res.begin()+ temp_end);
         }
         else {
             vec.insert(vec.begin(),res.begin(),res.begin()+ e_a);
             vec.insert(vec.end(),res.begin()+(res.size()+s_a),res.end());
         }

     }
     else if (e_a > res.size()) {
         int len1 = e_a- res.size();
         if(s_a == res.size())
         {
             vec.insert(vec.begin(),res.begin(),res.begin()+ len1);
         }
         else {
             vec.insert(vec.begin(),res.begin()+s_a,res.end());
             vec.insert(vec.end(),res.begin(),res.begin()+ len1);
         }

     }
     else {
           vec.insert(vec.begin(),res.begin()+s_a,res.begin()+ e_a);
     }


     ui->pushButton_2->setEnabled(max_page>1);
     ui->pushButton->setEnabled(max_page>1);
 }

void MainWindow::preClick()
{
    bool flag_change = false;//标记是否改变
    ui->textEdit->clear();
    int count =0;
    int start = 0;
    int end = 0;
    cur--;

    /*if(res.size()%30 == 0)
    {
        if((cur-1) < -1)
        {

           if(kaishi-10 < 0) jieshu = max_page;
           else jieshu = kaishi;
           kaishi = jieshu-10;

           s_a = kaishi*3;
           e_a = jieshu*3;

           cur = (len/3)-1;
           flag_change = true;
           //vec.clear();

           //vec.insert(vec.begin(),res.begin()+s_a,res.begin()+e_a);
        }
    }*/
    if(res.size() < 30)//向前翻页
    {
        //getInfo();
        int a =0;
        int less_s = 0;
        int less_e =0;
        less_e = less_first;//前移3个
        less_s = less_first - 3;
        if(less_s < 0)
        {
            if(less_e < 0)
            {
                less_e = res.size() + less_e;//前移3个
                less_s = res.size() + less_s;
            }
            else
            {
                a = res.size() + less_s;
            }
            less_first = res.size() + less_s;
        }
        else
        {
            less_last = less_first;
            less_first = less_first - 3;
        }
        if(a == 0)
        {
            for(int i =less_s;i<less_e;i++)
            {
                QString str = QString::number(vec[i]);
                ui->textEdit->append(str);
            }
        }
        else
        {
            for(int i =0;i<less_e;i++)
            {
                QString str = QString::number(vec[i]);
                ui->textEdit->append(str);
            }
            for(int i =a;i<vec.size();i++)
            {
                QString str = QString::number(vec[i]);
                ui->textEdit->append(str);
            }
        }
        flag_change = false;
    }
    else
    {
        //if(vec.size() < len)//余数页      如果小于30 一直在余数页里面
        {
            if(cur<0)//像前到达 最大页
            {

                e_a = first_index;
                s_a = first_index -30;
                if(s_a < 0)
                {
                    last_index = e_a;
                    first_index = res.size() + s_a;
                }
                else {
                    last_index = first_index;
                    first_index = first_index - 30; //在这里直接判断是否小于0
                }
                flag_change = true;
            }
        }
        if(flag_change)//有改变才执行
        {
            vec.clear();
            cur = 9;
            getInfo();
        }

        start = cur*3;
        end = cur*3 + 3;

        for(int i =start;i<end&&i<vec.size();i++,count++)
        {
            if(count==3) break;
            int temp = vec[i];
            QString str = QString::number(temp);
            ui->textEdit->append(str);
         }
    }

    qDebug() << "preClick" <<endl;
}


void MainWindow::nextClick()
{
    bool flag_change = false;//标记是否改变
    ui->textEdit->clear();
    int count =0;
    int start = 0;
    int end = 0;
    cur++;

    //判断是否刚好能够是30的倍数
    /*if(res.size()%len == 0)
    {
        if(cur > (len/3)-1)
        {


            if(jieshu + 10 > max_page) kaishi = 0;
            else kaishi = jieshu;
            jieshu = kaishi + 10;

            s_a = kaishi*3;
            e_a = jieshu*3;
            flag_change = true;

            cur = 0;


        }
    }*/
    if(res.size() < 30)
    {
        //getInfo();
        int a =0;
        int less_s = 0;
        int less_e =0;
        less_s = less_last;
        less_e = less_s + 3;//后移3个
        if(less_e > vec.size())
        {
            if(less_s == vec.size())
            {
                //less_s = 0;
                less_first = 0;
            }
            else less_first = less_s;

            a = less_e - vec.size();//从头取几个
            less_last = a;

        }
        else
        {
            less_first = less_last;
            less_last = less_last +3;
        }
        if(a == 0)
        {
            for(int i =less_s;i<less_e;i++)
            {
                QString str = QString::number(vec[i]);
                ui->textEdit->append(str);
            }
        }
        else
        {
            for(int i =less_s;i<vec.size();i++)
            {
                QString str = QString::number(vec[i]);
                ui->textEdit->append(str);
            }
            for(int i =0;i<a;i++)
            {
                QString str = QString::number(vec[i]);
                ui->textEdit->append(str);
            }
        }

        flag_change = false;
    }
    else
    {

        {
            if(cur > 9)//不在余数 增加
            {

                s_a = last_index;
                e_a = s_a + 30;
                if(e_a > res.size())
                {
                    if(s_a == res.size()) first_index = 0;
                    else first_index = s_a;
                    last_index = e_a - res.size();
                }
                else {
                    first_index = last_index;
                    last_index = last_index +30;
                }
                flag_change = true;
            }

        }
        if(flag_change)
        {
            vec.clear();
            cur = 0;
            getInfo();
        }
        start = cur*3;
        end = cur*3 + 3;
        {
            for(int i =start;i<end&&i<vec.size();i++,count++)
            {
                if(count==3) break;
                int temp = vec[i];
                QString str = QString::number(temp);
                ui->textEdit->append(str);
            }
        }
    }


    qDebug() << "nextClick" <<endl;
}
