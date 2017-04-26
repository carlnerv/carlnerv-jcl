#include "colormaker.h"
#include <QTimerEvent>
#include <QDateTime>

ColorMaker::ColorMaker(QObject *parent)
    : QObject(parent)
    , m_algorithm(RandomRGB)
    , m_currentColor(Qt::black)
    , m_nColorTimer(0)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}

ColorMaker::~ColorMaker()
{

}

QColor ColorMaker::color() const
{
    return m_currentColor;
}
