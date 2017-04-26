#include "colormaker.h"
#include <QTimerEvent>
#include <QDateTime>
//#include <QTimer>

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

void ColorMaker::setColor(const QColor &color)
{
    m_currentColor = color;
    emit colorChanged(m_currentColor);
}

QColor ColorMaker::timeColor() const
{
    QTime time = QTime::currentTime();
    int r = time.hour();
    int g = time.minute()*2;
    int b = time.second()*4;
    return QColor::fromRgb(r,g,b);
}

ColorMaker::GenerateAlogrithm ColorMaker::algorithm() const
{
    return m_algorithm;
}

void ColorMaker::setAlgorithm(GenerateAlgorithm algorithm)
{
    m_algorithm = algorithm;
}

void ColorMaker::start()
{
    if(m_nColorTimer == 0)
    {
        m_nColorTimer = startTimer(1000);
    }
}

void ColorMaker::stop()
{
    if(m_nColorTimer > 0)
    {
        killTimer(m_nColorTimer);
        m_nColorTimer = 0;
    }
}
