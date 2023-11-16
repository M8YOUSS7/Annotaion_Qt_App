#include "annotationvue.hh"

AnnotaionVue::AnnotaionVue(QWidget *parent)
    : QMainWindow(parent), _monMod(new AnnotationModele(parent)), _tailleSyto(new QSpinBox(this))
{
    this->setWindowTitle("Annotations");

    auto status(new QStatusBar(this));

    auto file(this->menuBar()->addMenu(tr("File")));
    QAction *openAct(new QAction(tr("&Load a picture"), this));
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    file->addAction(openAct);
    _maListeDactions.push_back(openAct);

    QAction *exitAct(new QAction(tr("&Quit"), this));
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exiting will close all projects"));
    file->addAction(exitAct);
    _maListeDactions.push_back(exitAct);

    auto edit(this->menuBar()->addMenu(tr("Edit")));

    QAction *redPen(new QAction(tr("&Red"), this));
    //QObject::connect(exitAct, QAction::triggered, );
    redPen->setStatusTip(tr("Red color to paint"));
    edit->addAction(redPen);
    _maListeDactions.push_back(redPen);

    QAction *blackPen(new QAction(tr("&Black"), this));
    //QObject::connect(exitAct, QAction::triggered, );
    blackPen->setStatusTip(tr("Black color to paint"));
    edit->addAction(blackPen);
    _maListeDactions.push_back(blackPen);

    QAction *greenPen(new QAction(tr("&Green"), this));
    //QObject::connect(exitAct, QAction::triggered, );
    greenPen->setStatusTip(tr("Green color to paint"));
    edit->addAction(greenPen);
    _maListeDactions.push_back(greenPen);

    QAction *bluePen(new QAction(tr("&Blue"), this));
    //QObject::connect(exitAct, QAction::triggered, );
    bluePen->setStatusTip(tr("Blue color to paint"));
    edit->addAction(bluePen);
    _maListeDactions.push_back(bluePen);

    QAction *eraseAct(new QAction(tr("&Erase annotations"), this));
    //QObject::connect(exitAct, QAction::triggered, );
    eraseAct->setStatusTip(tr("Clic to make a new one"));
    _maListeDactions.push_back(eraseAct);

    QAction *reSizeAct(new QAction(tr("&Pen size"), this));
    //QObject::connect(exitAct, QAction::triggered, );
    reSizeAct->setStatusTip(tr("Resize pen larger"));
    _tailleSyto->setRange(1,3);
    _maListeDactions.push_back(reSizeAct);

    QToolBar *matBar(new QToolBar(this));
    matBar->addSeparator();
    matBar->addSeparator();
    matBar->addAction(reSizeAct);
    matBar->addWidget(_tailleSyto);
    matBar->addSeparator();
    matBar->addAction(redPen);
    matBar->addAction(blackPen);
    matBar->addAction(greenPen);
    matBar->addAction(bluePen);
    matBar->addSeparator();
    matBar->addAction(eraseAct);
    matBar->setMovable(false);

    QObject::connect(exitAct, &QAction::triggered, this, &QWidget::close);
    QObject::connect(openAct, &QAction::triggered, _monMod, &AnnotationModele::loadImage);
    QObject::connect(_tailleSyto, QOverload<int>::of(&QSpinBox::valueChanged), _monMod, &AnnotationModele::setPenSize);
    QObject::connect(redPen, &QAction::triggered, _monMod, &AnnotationModele::setColorPen);
    QObject::connect(bluePen, &QAction::triggered, _monMod, &AnnotationModele::setColorPen);
    QObject::connect(blackPen, &QAction::triggered, _monMod, &AnnotationModele::setColorPen);
    QObject::connect(greenPen, &QAction::triggered, _monMod, &AnnotationModele::setColorPen);
    QObject::connect(eraseAct, &QAction::triggered, _monMod, &AnnotationModele::eraseAct);
    QObject::connect(_monMod, &AnnotationModele::erasedWid, this, &AnnotaionVue::eraseAct);

    this->addToolBar(matBar);

    this->setStatusBar(status);

    this->setCentralWidget(_monMod);
}

AnnotaionVue::~AnnotaionVue() {
}

void AnnotaionVue::eraseAct(bool) {
    _tailleSyto->setValue(1);
}
