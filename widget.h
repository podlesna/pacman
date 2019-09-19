#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <vector>

#include <triangle.h>
#include <node.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void drawMap(const std::vector<std::vector<int> > &vec);
    void fill(int x, int y);
    void fillBall( int x, int y);

private:
    Ui::Widget      *ui;
    QGraphicsScene  *scene;     /// Объявляем графическую сцену
    Triangle        *triangle;  /// и треугольник
    QTimer          *timer;

};

#endif // WIDGET_H
