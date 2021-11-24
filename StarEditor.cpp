#include "StarEditor.h"



StarEditor::StarEditor(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
}


void StarEditor::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    myStarRating.paint(&painter, rect(), palette(),
                       StarRating::EditMode::Editable);
}



void StarEditor::mouseMoveEvent(QMouseEvent *event)
{
    const int star = starAtPosition(event->x());

    if (star != myStarRating.starCount() && star != -1) {
        myStarRating.setStarCount(star);
        update();
    }
    QWidget::mouseMoveEvent(event);
}



void StarEditor::mouseReleaseEvent(QMouseEvent *event)
{
    emit editingFinished();
    QWidget::mouseReleaseEvent(event);
}


int StarEditor::starAtPosition(int x) const
{
    const int star = (x / (myStarRating.sizeHint().width()
                           / myStarRating.maxStarCount())) + 1;
    if (star <= 0 || star > myStarRating.maxStarCount())
        return -1;

    return star;
}



