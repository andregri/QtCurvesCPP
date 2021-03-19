#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, Circle, Ellipse, Flower, Starfish,
                   Cloud1, Cloud2};

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    QColor getBackgroundColor() const { return mBackgroundColor; }

    void setShapeColor(QColor color) { mPen.setColor(color); }
    QColor getShapeColor() const { return mPen.color(); }

    ShapeType getShape() const { return mShape; }
    void setShape(ShapeType shape) { mShape = shape; on_shape_changed(); }

    float getIntervalLength() const { return mIntervalLength; }
    void setIntervalLength(float length) { mIntervalLength = length; }

    float getScale() const { return mScale; }
    void setScale(float scale) { mScale = scale; }

    int getStepCount() const { return mStepCount; }
    void setStepCount(int stepCount) { mStepCount = stepCount; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    QColor mBackgroundColor;
    QPen mPen;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int   mStepCount;

    void on_shape_changed();
    QPointF compute(float); // dispatch compute_ functions based on ShapeType
    QPointF compute_astroid(float);
    QPointF compute_cycloid(float);
    QPointF compute_huygens(float);
    QPointF compute_hypo(float);
    QPointF compute_line(float);
    QPointF compute_circle(float);
    QPointF compute_ellipse(float);
    QPointF compute_flower(float);
    QPointF compute_starfish(float);
    QPointF compute_cloud1(float);
    QPointF compute_cloud2(float);
    QPointF compute_cloud_with_sign(float, float);
};

#endif // RENDERAREA_H
