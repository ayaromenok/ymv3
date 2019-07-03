#include "view.h"

#include <QtWidgets>

#include <Qt3DCore>
#include <Qt3DInput>
#include <Qt3DRender>
#include <Qt3DExtras>

View::View(QWidget *parent) : QWidget(parent) {
    _view  = new Qt3DExtras::Qt3DWindow();
    _view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x8F0F0F)));
    QWidget *container = QWidget::createWindowContainer(_view);
    QSize scrnSize = _view->screen()->size();
    qDebug() << "screensize" << scrnSize;
    container->setMinimumSize(QSize(640,480));
    container->setMaximumSize(scrnSize);

    QVBoxLayout* loutV = new QVBoxLayout(this);
    loutV->setAlignment(Qt::AlignTop);
    loutV->addWidget(container);

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect();
    _view->registerAspect(input);

    _root = new Qt3DCore::QEntity();
    addTorusTo(_root);
    addConeTo(_root);
    _view->setRootEntity(_root);

}

void
View::addTorusTo(Qt3DCore::QEntity *entity) {

    Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(entity);
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh();

    torusMesh->setRadius(1.0f);
    torusMesh->setMinorRadius(0.1f);
    torusMesh->setRings(40);
    torusMesh->setSlices(16);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale3D(QVector3D(2.0f, 1.0f, 0.5f));
    //torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
    //torusTransform->setTranslation(QVector3D(5.0f, 0.0f, 0.0f));
    //torusTransform->setScale(2.0f);

    Qt3DExtras::QPhongMaterial *torusMat = new Qt3DExtras::QPhongMaterial();
    torusMat->setDiffuse(QColor(QRgb(0x0FFF0F)));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusMat);
    torusEntity->addComponent(torusTransform);
}

void
View::addConeTo(Qt3DCore::QEntity *entity) {

    Qt3DCore::QEntity *coneEntity = new Qt3DCore::QEntity(entity);
    Qt3DExtras::QConeMesh *coneMesh = new Qt3DExtras::QConeMesh();

    coneMesh->setTopRadius(0.1f);
    coneMesh->setBottomRadius(1.0f);
    coneMesh->setLength(3);
    coneMesh->setRings(40);
    coneMesh->setSlices(16);

    Qt3DCore::QTransform *coneTransform = new Qt3DCore::QTransform();
    coneTransform->setTranslation(QVector3D(0.0f, 0.0f, -2.0f));

    Qt3DExtras::QPhongMaterial *coneMat = new Qt3DExtras::QPhongMaterial();
    coneMat->setDiffuse(QColor(QRgb(0x0F0FFF)));

    coneEntity->addComponent(coneMesh);
    coneEntity->addComponent(coneMat);
    coneEntity->addComponent(coneTransform);
}
void
View::setCamPersp() {
    Qt3DRender::QCamera *cameraEntity = _view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
}

void
View::setCamFront() {
    Qt3DRender::QCamera *cameraEntity = _view->camera();

    cameraEntity->lens()->setOrthographicProjection(-16.0f, 19.0f, -9.0f, 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
}

void
View::setCamTop() {
    Qt3DRender::QCamera *cameraEntity = _view->camera();
    cameraEntity->lens()->setOrthographicProjection(-16.0f, 19.0f, -9.0f, 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 20.0f, 0));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
}

void
View::setCamLeft() {
    Qt3DRender::QCamera *cameraEntity = _view->camera();
    cameraEntity->lens()->setOrthographicProjection(-16.0f, 19.0f, -9.0f, 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(20.0f, 0, 0));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));
}

