#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    firstPageWidget = new QFirstPageWidget(this);     /*启动QWidget页面需要制定父对象this指针，不然会出现闪屏bug*/
    secondPageWidget = new QSecondPageWidget(this);
    firstPageBtn = new QPushButton("1");
    secondPageBtn = new QPushButton("2");//初始化一般在 构造函数  其余在析构函数
    mainLayout = new QVBoxLayout;
    setupUI();
}

Widget::~Widget()
{
    /*delete firstPageBtn;
    delete secondPageBtn;
    delete firstPageWidget;
    delete secondPageWidget;*/
}

void Widget::setupUI()
{
    //mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    QWidget *mainWidget = new QWidget(this);    /*启动QWidget页面需要制定父对象this指针，不然会出现闪屏bug*/
    mainWidget->setLayout(mainLayout);
    mainWidget->setObjectName("mainWidget");
    mainWidget->setStyleSheet("#mainWidget{border-image:url(:/resource/main_bg.jpg)}"); /*设置主界面背景图片*/
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(mainWidget);
    this->setLayout(layout);

    /*初始化顶层菜单栏、底层功能区*/
    initMenu();
    initStackWidget();
}

void Widget::initMenu()
{
    const QSize btnSize(120,90);

    /*菜单按钮初始化*/
    //firstPageBtn = new QPushButton("1");
    firstPageBtn->setObjectName("firstPageBtn");
    firstPageBtn->setCheckable(true);
    firstPageBtn->setChecked(true);
    firstPageBtn->setFixedSize(btnSize);
    firstPageBtn->setStyleSheet("QPushButton{border-image: url(:/resource/icon_page1.png) 0 0 0 0;background-repeat: no-repeat;background-position:center;border:none;color:rgb(255, 255, 255);}"
                                    "QPushButton:hover{border-image: url(:/resource/icon_page1.png) 5 0 0 0;background-repeat: no-repeat;background-position:center;border:none;color:rgb(255, 255, 255);}"
                                    "QPushButton:checked{border-image: url(:/resource/icon_page1.png) 4 0 0 0;background-repeat: no-repeat;background-position:center;border:none;color:rgb(255, 255, 255);}");
    //secondPageBtn = new QPushButton("2");
    secondPageBtn->setObjectName("secondPageBtn");
    secondPageBtn->setCheckable(true);
    secondPageBtn->setFixedSize(btnSize);
    secondPageBtn->setStyleSheet("QPushButton{border-image: url(:/resource/icon_page2.png) 0 0 0 0;background-repeat: no-repeat;background-position:center;border:none;color:rgb(255, 255, 255);}"
                                    "QPushButton:hover{border-image: url(:/resource/icon_page2.png) 5 0 0 0;background-repeat: no-repeat;background-position:center;border:none;color:rgb(255, 255, 255);}"
                                    "QPushButton:checked{border-image: url(:/resource/icon_page2.png) 4 0 0 0;background-repeat: no-repeat;background-position:center;border:none;color:rgb(255, 255, 255);}");



    /*单选菜单效果*/
    buttonGroup = new QButtonGroup();
    buttonGroup->setObjectName("buttonGroup");
    buttonGroup->addButton(firstPageBtn);
    buttonGroup->addButton(secondPageBtn);
    buttonGroup->setExclusive(true);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonGroupSlot(int)));
    /*connect(buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
          [=](int id){ qDebug() << id; });*/
    //connect(firstPageBtn, SIGNAL(clicked()),this,SLOT(button1()));


    /*容器包含*/
    menuLayout = new QHBoxLayout();
    menuLayout->setMargin(0);
    menuLayout->setSpacing(0);

    menuLayout->addWidget(firstPageBtn);//有问题啊
    menuLayout->addWidget(secondPageBtn);
    menuLayout->addStretch();

    mainLayout->addLayout(menuLayout);

    qDebug() << children();    // 输出所有子部件的列表
}

void Widget::button1()
{
    qDebug() << "11";
}

void Widget::initStackWidget()
{
    /*启动菜单栏界面*/
    //firstPageWidget = new QFirstPageWidget(this);     /*启动QWidget页面需要制定父对象this指针，不然会出现闪屏bug*/
    //secondPageWidget = new QSecondPageWidget(this);
    stackLayout = new QStackedLayout;
    stackLayout->addWidget(firstPageWidget);
    stackLayout->addWidget(secondPageWidget);
    stackLayout->setCurrentIndex(0);

    mainLayout->addLayout(stackLayout);
}

void Widget::buttonGroupSlot(int)
{
    QPushButton* checkedButton = qobject_cast<QPushButton*>(buttonGroup->checkedButton());
    QString objectNameCheckedBtn = checkedButton->objectName();
    qDebug() << tr("第一个按钮") << objectNameCheckedBtn.compare(QStringLiteral("firstPageBtn"));
    qDebug() << tr("第二个按钮") <<objectNameCheckedBtn.compare(QStringLiteral("secondPageBtn"));
    if(objectNameCheckedBtn.compare(QStringLiteral("firstPageBtn"))==0)
    {
        qDebug()<<tr("单击了第二页菜单按钮");
        stackLayout->setCurrentIndex(0);
    }
    else if(objectNameCheckedBtn.compare(QStringLiteral("secondPageBtn"))==0)
    {
        qDebug()<<tr("单击了第二页菜单按钮");
        stackLayout->setCurrentIndex(1);
    }
}
