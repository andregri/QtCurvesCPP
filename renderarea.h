#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, Circle };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    QColor getBackgroundColor() const { return mBackgroundColor; }

    void setShapeColor(QColor color) { mShapeColor = color; }
    QColor getShapeColor() const { return mShapeColor; }

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
    QColor mShapeColor;
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
};

#endif // RENDERAREA_H
