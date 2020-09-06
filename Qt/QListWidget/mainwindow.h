#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <vector>
#include <QObject>
#include <QLabel>
#include <QMessageBox>
using namespace std;

namespace Ui {
class MainWindow;
}

//QLabel点击相应
class ClickedLabel : public QLabel
{
    Q_OBJECT
signals:
    void Clicked(ClickedLabel* clicked);
public:
    ClickedLabel(const QString &text,QWidget *parent=0): QLabel(text,parent){	};
    ~ClickedLabel() {};
protected:
    void mouseReleaseEvent( QMouseEvent* ){emit Clicked(this);};
public slots:
    void OnCLicked( ClickedLabel* ) {QMessageBox::information(topLevelWidget(), "Message from Qt", "Label Clicked!");	};
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initilize();
    void getInfo();

protected slots:
    void nextClick();
    void preClick();
    void loadData();

private:
    Ui::MainWindow *ui;
    vector<int> res;
    vector<int> vec;

    int cur;
    int max_page;
    int jieshu;
    int kaishi;
    int other_page;
    bool other;
    bool flag;
    int s_a;
    int e_a;
    bool is_small_th;
    bool first_load;

    int first_index;
    int last_index;

    int less_first;
    int less_last;

private:
    static bool valueSort(int &left,int &right);

};

#endif // MAINWINDOW_H
