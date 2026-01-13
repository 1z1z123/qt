#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QObject>
#include <QThread>
#include <QString>

class ReportGenerator : public QObject
{
    Q_OBJECT

public:
    explicit ReportGenerator(QObject *parent = nullptr);

public slots:
    void generateReport(const QString &filePath);

signals:
    void reportGenerated(const QString &filePath);
    void reportError(const QString &error);
    void progressChanged(int percentage);

private:
    QString generateCSVReport(const QString &filePath);
};

#endif // REPORTGENERATOR_H

