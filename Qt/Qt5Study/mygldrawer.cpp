#include "mygldrawer.h"

MyGLDrawer::MyGLDrawer(QWidget *parent):
    QGLWidget (parent)
{

}
void MyGLDrawer::initializeGL()
{
    //设置渲染文本  定义展示列表
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);

}
void MyGLDrawer::resizeGL(int w,int h)
{
    //setup viewport  projection ect
    //glViewport(0,0,(GLint)w,(GLint)h);
    //...
    //glFrustum()

}
void MyGLDrawer::paintGL()
{

    //draw the scene
   /* glRotatef();
    glMaterialfv();
    glBegin(GL_QUADS);
    glVertex3f();
    glVertex3f();


    glEnd();
    */
}
