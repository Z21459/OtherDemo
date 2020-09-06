#include "mainwindow.h"
#include <QApplication>
#include "testqthread.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();*/

    /*ClickedLabel label("<h2>test</h2>");
    QObject::connect( &label, SIGNAL( Clicked(ClickedLabel*) ),&label,
                      SLOT( OnCLicked(ClickedLabel*) ) ) ;
    label.show();*/
    QObject *obj = new QObject;


    Counter1 b1(11);
    Produce producer;
    producer.SetCount(&b1);
    Produce producer1;
    producer1.SetCount(&b1);
    producer.run();
    producer1.run();
    int i = 0;
    cin >> i;

    return a.exec();
}
