#include "opensslcontroller.h"
#include <memory>


OpenSSLController::OpenSSLController():
    program("openssl")
    //arguments()
{
    openSSLProcess = std::make_unique<QProcess>(this);
    openSSLProcess->setProgram(program);
    QObject::connect(openSSLProcess.get(), QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &OpenSSLController::handleFinishedProcess);
}

void OpenSSLController::getVersionInfo() const
{
    QStringList arguments = {"version"};
    openSSLProcess->setArguments(arguments);
    openSSLProcess->start();

}

void OpenSSLController::handleFinishedProcess(int exitCode, QProcess::ExitStatus status)
{
    QByteArray result = openSSLProcess->readAll();
    QString processOutput(result);
    emit notifyResultsAvailable(result);
}
