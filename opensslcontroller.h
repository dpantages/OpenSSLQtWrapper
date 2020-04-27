#ifndef OPENSSLCONTROLLER_H
#define OPENSSLCONTROLLER_H

#include <memory>
#include <QObject>
#include <QProcess>


class OpenSSLController : public QObject
{
    Q_OBJECT
public:
    OpenSSLController();

public:
signals:
    void notifyResultsAvailable(const QString& text);

public slots:
    void getVersionInfo() const;

private:

    std::unique_ptr<QProcess> openSSLProcess;
    QString program;
   // QStringList arguments;

private slots:
    void handleFinishedProcess(int exitCode, QProcess::ExitStatus status);
};

#endif // OPENSSLCONTROLLER_H
