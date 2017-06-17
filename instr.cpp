#include "instr.h"
#include <QGraphicsTextItem>
#include <QFont>

Instructions::Instructions(QGraphicsItem *parent) : QGraphicsTextItem()
{
    /*setPlainText(QString("Instructions:      "));
    setPlainText(QString(" W - foward        "));
    setPlainText(QString(" S - reverse       "));
    setPlainText(QString(" A - left          "));
    setPlainText(QString(" D - right         "));
    setPlainText(QString(" E - up right      "));
    setPlainText(QString(" Q - up left       "));
    setPlainText(QString(" C - down right    "));
    setPlainText(QString(" Z - down left     "));*/
    setPlainText(QString("Hint: Front is sideways"));
    setDefaultTextColor(Qt::cyan);
    setFont(QFont("consolas", 12));
}
