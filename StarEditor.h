#ifndef STAREDITOR_H
#define STAREDITOR_H

#include <QWidget>
#include "StarRating.h"
#include <QMouseEvent>


class StarEditor : public QWidget
{
    Q_OBJECT
public:
    StarEditor(QWidget *parent = nullptr);


    void setStarRating(const StarRating &starRating) {
        myStarRating = starRating;
    }
    StarRating starRating() { return myStarRating; }

signals:
    void editingFinished();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int starAtPosition(int x) const;

    StarRating myStarRating;
};

#endif // STAREDITOR_H
