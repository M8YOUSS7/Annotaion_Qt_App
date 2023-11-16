#pragma once
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QSpinBox>
#include <QList>
#include "annotationmodele.hh"

class AnnotaionVue : public QMainWindow
{
    Q_OBJECT

public:
    AnnotaionVue(QWidget *parent = nullptr);
    ~AnnotaionVue();

public slots:
    void    eraseAct(bool);

private:
    AnnotationModele*       _monMod;
    QList<QAction*>         _maListeDactions;
    QSpinBox*               _tailleSyto;
};
