#ifndef FIGUREITEM_H
#define FIGUREITEM_H

#include <QGraphicsItem>
#include "2DFigure.h"
#include <QPainter>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QStyleOptionGraphicsItem>
class FigureItem : public QGraphicsItem
{
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QPointF point;
    QPointF position;
    QColor color;

protected:
    QPainterPath path;
    QRectF bounding;
    TwDFigure* figure;
    FigureItem(QPoint position, QColor color);
    void updateInfo();
public:
    virtual ~FigureItem();
};

class CircleItem : public FigureItem
{
private:
    void setPaint();
public:
    CircleItem(Circle circle, QPoint position, QColor color);
    ~CircleItem();
};

class TriangleItem : public FigureItem
{
private:
    void setPaint();
public:
    TriangleItem(Triangle triangle, QPoint position, QColor color);
    ~TriangleItem();
};

class HexagrammItem : public FigureItem
{
private:
    void setPaint();
public:
    HexagrammItem(Hexagramm hexagramm, QPoint position, QColor color);
    ~HexagrammItem();
};

class RingItem : public FigureItem
{
private:
    void setPaint();
public:
    RingItem(Ring ring, QPoint position, QColor color);
    ~RingItem();
};

#endif // FIGUREITEM_H
