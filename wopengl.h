#ifndef WOPENGL_H
#define WOPENGL_H

#include <QGLWidget>

class WOpenGL : public QGLWidget
{
public:
    WOpenGL();
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

private:
    void scene();
};

#endif // WOPENGL_H
