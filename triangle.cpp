#include "triangle.h"
#include <cassert>
#include <cmath>

Triangle::Triangle(QObject *parent) :
    QObject(parent), QGraphicsItem(), direction(Direction:: NONE)
{

    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
}

Triangle::~Triangle()
{
}

QRectF Triangle::boundingRect() const
{
    return QRectF(-10,-10,20,20);   /// Ограничиваем область, в которой лежит треугольник
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


        QRectF rectangle(-10, -10, 20, 20);

        painter->setBrush(QBrush(Qt::yellow));
        painter->drawEllipse(rectangle);

}

bool Triangle::frontBloked(const std::vector<std::vector<int> > vec,int xx,int yy, Direction direction){
    switch(direction){
      case Direction::UP:
        if(vec[yy-1][xx] == 0)
            return true;
        else
            return false;
     case Direction::DOWN:
        if(vec[yy+1][xx] == 0)
            return true;
        else
            return false;
        case Direction::LEFT:
        if(vec[yy][xx-1] == 0)
            return true;
        else
            return false;
      case Direction::RIGHT:
        if(vec[yy][xx-1] == 0)
            return true;
        else
            return false;
    case Direction::NONE:
        return true;

    }
}

void Triangle::slotGameTimer()
{
    direction = Direction::NONE;
    if(GetAsyncKeyState(VK_LEFT)){
        direction = Direction::LEFT;
    }
    if(GetAsyncKeyState(VK_RIGHT)){
        direction = Direction::RIGHT;
        /*angle += 10;        // Задаём поворот на 10 градусов вправо
        setRotation(angle); */
    }
    if(GetAsyncKeyState(VK_UP)){

        direction = Direction::UP;
    }
    if(GetAsyncKeyState(VK_DOWN)){
        direction = Direction::DOWN;
    }
    if (frontBloked(vec,xx, yy, direction)){

    switch (direction){
        case Direction::UP:
            moveUp();
            break;
        case Direction::DOWN:
            moveDown();
            break;
        case Direction::LEFT:
            moveLeft();
            break;
        case Direction::RIGHT:
            moveRight();
            break;
        case Direction::NONE:
            // do nothing (do not move if no direction)
            break;
        default:
            assert(false); // should not get here
        }
    }
}

void Triangle::moveUp(){
 setPos(x(),y()-25);
 yy = (y()+12.5)/25;
}


void Triangle::moveDown(){
    setPos(x(),y()+25);
    yy = (y()+12.5)/25;
}

void Triangle::moveRight(){
    setPos(x()+25,y());
    xx = (x()+12.5)/25;
}


void Triangle::moveLeft(){
    setPos(x()-25,y());
    xx = (x()+12.5)/25;
}








