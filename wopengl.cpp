#include "wopengl.h"

WOpenGL::WOpenGL()
{
}

void WOpenGL::initializeGL()
{
    //задаём цвет фона
    qglClearColor(Qt::white);

    //Задаем режим обработки полигонов - переднюю и заднюю часть,
    //полигоны полностью закрашенные
    //(а можно просто рамку отображать)
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void WOpenGL::resizeGL(int nWidth, int nHeight)
{
    //Устанавливаем точку обзора. Последние два параметры одинаковы -
    // чтобы не нарушать пропорции у широких экранов
    //(можете поэкспериментировать)
    glViewport(0, 0, nHeight, nHeight);

    //Устанавливаем режим матрицы
    glMatrixMode(GL_PROJECTION);

    //Загружаем матрицу
    glLoadIdentity();
}

void WOpenGL::paintGL()
{
    //Очищаем экран
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Задаем режим матрицы
    glMatrixMode(GL_PROJECTION);

    //Загружаем матрицу
    glLoadIdentity();

    //Здесь рисуем - для удобства в отдельной функции
    scene();

    //выводим на экран
    swapBuffers();
}

void WOpenGL::scene()
{
    //Задаем цвет изображения
    qglColor(Qt::blue);

    //Начинаем отрисовку, аргумент означает отрисовку прямоугольника.
    //Каждый вызов glVertex3f задает одну вершину прямоугольника
    glBegin(GL_QUADS);
    glVertex3f(0.51, 0.51, 0.51);
    glVertex3f(-0.51, 0.51, 0.51);
    glVertex3f(-0.51, -0.51, 0.51);
    glVertex3f(0.51, -0.51, 0.51);
    glEnd();
}
