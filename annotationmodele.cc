#include "annotationmodele.hh"
#include "qaction.h"

AnnotationModele::AnnotationModele(QWidget *parent)
    :   QWidget(parent), _monPix(QPixmap(800, 600)), _monStylo(QPen()), _pointActuel(QPoint()), _monCur(QCursor())
{
    this->setMinimumSize(800, 600);
    QPainter _device(&_monPix); // int z(0)
    _monPix.fill();
    _monStylo.setColor(Qt::black);
    _monStylo.setWidth(1);
    _device.setPen(_monStylo);
    _device.drawText(_monPix.rect(), Qt::AlignCenter, "Load a picture to annotate it...");
}

AnnotationModele::~AnnotationModele() {
}

void AnnotationModele::paintEvent(QPaintEvent *)
{
    QPainter _device(this);
    if(this->_monPix.rect().size() != this->rect().size()) {
        QPixmap monpix(this->rect().size());
        QPainter _devicePix(&monpix);
        _devicePix.drawPixmap(this->rect(), _monPix);
        _monPix = monpix;
    }

        _device.drawPixmap(_monCur.pixmap().rect(), _monCur.pixmap());
        _device.drawPixmap(this->rect(), _monPix);
}

void AnnotationModele::mousePressEvent(QMouseEvent *event)
{
    /*QPainter _device(&_monPix);
    _device.setPen(_monStylo);
    _device.drawPoint(event->pos());*/
    _pointActuel =event->pos();
    //update();
}

void AnnotationModele::mouseReleaseEvent(QMouseEvent *event)
{
    QPainter _device(&_monPix);
    _device.setPen(_monStylo);
    _device.drawLine(_pointActuel, event->pos());
    update();
}

void AnnotationModele::mouseMoveEvent(QMouseEvent *event)
{
    QPainter _device(&_monPix);
    _device.setPen(_monStylo);
    _device.drawLine(_pointActuel, event->pos());
    _pointActuel =event->pos();
    update();
}


void AnnotationModele::loadImage(bool)
{
    _nomImage = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/ymaster", tr("Images (*.png *.jpg)"));
    if(_nomImage != "") {
        auto image(new QImage(_nomImage));
        if(!image->isNull())
            _monPix =_monPix.fromImage(*image);
        update();
    }
}

void AnnotationModele::setColorPen(bool)
{
    auto envoyeur(dynamic_cast<QAction*>(sender()));
    auto str (envoyeur->text());
    if(str != "") {
        if(str == "&Blue") _monStylo.setColor(Qt::blue);
            else if(str == "&Red") _monStylo.setColor(Qt::red);
                else if(str == "&Black") _monStylo.setColor(Qt::black);
                    else if(str == "&Green") _monStylo.setColor(Qt::green);
    }
}

void AnnotationModele::setPenSize(int t)
{
    _monStylo.setWidth(t);
}

void AnnotationModele::eraseAct(bool)
{
    this->_monPix = QPixmap(this->size());
    QPainter _device(&_monPix);
    _monPix.fill();
    _monStylo.setColor(Qt::black);
    _monStylo.setWidth(1);
    _device.setPen(_monStylo);
    _device.drawText(_monPix.rect(), Qt::AlignCenter, "Load a picture to annotate it...");
    emit    AnnotationModele::erasedWid(true);
    update();
}
