#ifndef STATISTICSTHREAD_H
#define STATISTICSTHREAD_H

#include <QThread>
#include <QMap>
#include <QVariant>

class StatisticsThread : public QThread
{
    Q_OBJECT

public:
    explicit StatisticsThread(QObject *parent = nullptr);

signals:
    void statisticsReady(const QMap<QString, QVariant> &stats);

protected:
    void run() override;

private:
    QMap<QString, QVariant> calculateStatistics();
};

#endif // STATISTICSTHREAD_H

