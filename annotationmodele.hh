#pragma once
#include <QWidget>
#include <QPixmap>
#include <QPen>
#include <QPoint>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include <QFileDialog>
#include <QCursor>

class AnnotationModele : public QWidget
{
    Q_OBJECT

public:
    AnnotationModele(QWidget *parent=nullptr);
    ~AnnotationModele();

signals:
    void erasedWid(bool);

public slots:
    void    loadImage(bool);
    void    setColorPen(bool);
    void    setPenSize(int);
    void    eraseAct(bool);

protected:
    void        paintEvent(QPaintEvent*) override;
    void        mousePressEvent(QMouseEvent *event) override;
    void        mouseReleaseEvent(QMouseEvent *event) override;
    void        mouseMoveEvent(QMouseEvent *event) override;

private:
    QPixmap     _monPix;
    QPen        _monStylo;
    QPoint      _pointActuel;
    QString     _nomImage;
    QCursor     _monCur;
};
