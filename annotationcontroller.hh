#pragma once
#include <QObject>

class AnnotationController : public QObject
{
    Q_OBJECT

public:
    AnnotationController(QObject *parent = nullptr);
    ~AnnotationController();



public slots:
    void    backGroundPicChanged(bool);

private:
};
