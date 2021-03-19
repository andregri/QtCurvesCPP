#include "renderarea.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <math.h>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0,0,255),
    mPen(Qt::white),
    mShape(Astroid)
{
    mPen.setWidth(2);
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400,400);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,400);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mPen);

    // drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();

    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());

    float step = mIntervalLength / mStepCount;

    for (float t = 0; t < mIntervalLength; t+= step) {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawLine(pixel, prevPixel);

        prevPixel = pixel;
    }

    QPointF point = compute(mIntervalLength);
    QPoint pixel;
    pixel.setX(point.x() * mScale + center.x());
    pixel.setY(point.y() * mScale + center.y());
    painter.drawLine(pixel, prevPixel);
}

void RenderArea::on_shape_changed()
{
    switch (mShape) {
    case Astroid:
        mScale = 90;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Cycloid:
        mScale = 10;
        mIntervalLength = 4 * M_PI;
        mStepCount = 128;
        break;

    case HuygensCycloid:
        mScale = 4;
        mIntervalLength = 4 * M_PI;
        mStepCount = 256;
        break;

    case HypoCycloid:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Line:
        mIntervalLength = 1; // not necessary
        mScale = 100; // line length
        mStepCount = 128;
        break;

    case Circle:
        mScale = 100;
        mIntervalLength = 2 * M_PI;
        mStepCount = 128;
        break;

    case Ellipse:
        mScale = 75;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Flower:
        mScale = 10;
        mIntervalLength = 12 * M_PI;
        mStepCount = 512;
        break;

    case Starfish:
        mScale = 25;
        mIntervalLength = 6 * M_PI;
        mStepCount = 256;
        break;

    default:
        break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (mShape) {
    case Astroid:
        return compute_astroid(t);

    case Cycloid:
        return compute_cycloid(t);

    case HuygensCycloid:
        return compute_huygens(t);

    case HypoCycloid:
        return compute_hypo(t);

    case Line:
        return compute_line(t);

    case Circle:
        return compute_circle(t);

    case Ellipse:
        return compute_ellipse(t);

    case Flower:
        return compute_flower(t);

    case Starfish:
        return compute_starfish(t);

    default:
        break;
    }

    return QPointF(0,0);
}

QPointF RenderArea::compute_astroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;

    return QPointF(x,y);
}

QPointF RenderArea::compute_cycloid(float t)
{
    float x = 1.5 * (1 - cos(t));
    float y = 1.5 * (t - sin(t));

    return QPointF(x,y);
}

QPointF RenderArea::compute_huygens(float t)
{
    float x = 4 * (3 * cos(t) - cos(3 * t));
    float y = 4 * (3 * sin(t) - sin(3 * t));

    return QPointF(x,y);
}

QPointF RenderArea::compute_hypo(float t)
{
    float x = 1.5 * (2 * cos(t) + cos(2 * t));
    float y = 1.5 * (2 * sin(t) - sin(2 * t));

    return QPointF(x,y);
}

QPointF RenderArea::compute_line(float t)
{
    float x = 1 - t;
    float y = 1 - t;

    return QPointF(x,y);
}

QPointF RenderArea::compute_circle(float t)
{
    float x = cos(t);
    float y = sin(t);

    return QPointF(x,y);
}

QPointF RenderArea::compute_ellipse(float t)
{
    float x = 2 * cos(t);
    float y = 1.1 * sin(t);

    return QPointF(x,y);
}

QPointF RenderArea::compute_flower(float t)
{
    float x = 11.0f * cos(t) - 6.0f * cos(11.0f / 6.0f * t);
    float y = 11.0f * sin(t) - 6.0f * sin(11.0f / 6.0f * t);

    return QPointF(x,y);
}

QPointF RenderArea::compute_starfish(float t)
{
    float R = 5.0f;
    float r = 3.0f;
    float d = 5.0f;

    float x = (R-r) * cos(t) + d * cos( (R-r)/r * t );
    float y = (R-r) * sin(t) - d * sin( (R-r)/r * t );

    return QPointF(x,y);
}
