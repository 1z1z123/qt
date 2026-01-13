#ifndef EXCELREPORT_H
#define EXCELREPORT_H

#include <QObject>

class ExcelReport : public QObject
{
    Q_OBJECT

public:
    explicit ExcelReport(QObject *parent = nullptr);
    
    bool exportToCSV(const QString &filePath);

signals:
    void exportCompleted(bool success);
};

#endif // EXCELREPORT_H

