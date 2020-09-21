#ifndef MYGLDRAWER_H
#define MYGLDRAWER_H
#include <QtOpenGL>//3D视图渲染
#include <gl/GL.h>
#include <QtOpenGL/QGL>
#include <QOpenGLFunctions>//否者会出现 glClearColor无法解析外部符号

class MyGLDrawer:public QGLWidget,protected QOpenGLFunctions//渲染
{
    Q_OBJECT
public:
    MyGLDrawer(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w,int h);
    void paintGL();
};

#endif // MYGLDRAWER_H
