#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to zero
    score = 0;

    //Draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("consolas", 16));
}

void Score::increase()
{
    ++score;
     setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
