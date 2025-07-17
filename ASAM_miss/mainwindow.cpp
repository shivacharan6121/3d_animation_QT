#include "mainwindow.h"

#include <QVBoxLayout>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QSceneLoader>

//#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    setWindowTitle("missile viewer");
    resize(800, 600);

    m_container = QWidget::createWindowContainer(m_3dView = new Qt3DExtras::Qt3DWindow());
    m_container->setMinimumSize(QSize(200, 200));
    m_container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_container);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setup3DView();
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //delete ui;
}


void MainWindow::setup3DView(){
    //Root Entity
    m_rootEntity = new Qt3DCore::QEntity;

    //Camera
    m_camera = m_3dView->camera();
    m_camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    m_camera->setPosition(QVector3D(0, 0, 5));
    m_camera->setViewCenter(QVector3D(0, 0, 0));

    //For camera controls
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(m_rootEntity);
    camController->setCamera(m_camera);

    //Scene loader
    Qt3DRender::QSceneLoader *sceneLoader = new Qt3DRender::QSceneLoader(m_rootEntity);
    sceneLoader->setSource(QUrl::fromLocalFile("/home/shiva/Downloads/missile.glb"));

    //Add components to root entity
    m_rootEntity->addComponent(sceneLoader);


    //set root object of the scene
    m_3dView->setRootEntity(m_rootEntity);
}
