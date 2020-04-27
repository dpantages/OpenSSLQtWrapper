#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opensslcontroller.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller = std::make_unique<OpenSSLController>();
    connect(controller.get(), &OpenSSLController::notifyResultsAvailable, this, &MainWindow::displayResults);
    connect(ui->versionButton, &QPushButton::clicked, this, &MainWindow::verifyButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayResults(const QString &result)
{
    ui->textEdit->setText(result);
}

void MainWindow::verifyButtonClicked()
{
    controller->getVersionInfo();
}

