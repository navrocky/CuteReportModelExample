#include <QApplication>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>

#include <reportcore.h>
#include <reportinterface.h>
#include <reportpreview.h>

using namespace CuteReport;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ReportCore core;

    QString err;
    ReportInterface* reportObject = core.loadReport("file::/reports/test.qtrp", &err);
    if (!err.isEmpty())
    {
        qCritical() << err;
        return 1;
    }

    QStandardItemModel rootModel;
    rootModel.setHorizontalHeaderLabels(QStringList() << "column1" << "column2");
    rootModel.appendRow(QList<QStandardItem*>()
                    << new QStandardItem("value1")
                    << new QStandardItem("value2"));

    QStandardItemModel tableModel;
    tableModel.setHorizontalHeaderLabels(QStringList() << "column1" << "column2");
    tableModel.appendRow(QList<QStandardItem*>()
                        << new QStandardItem("row1.value1")
                        << new QStandardItem("row1.value2"));
    tableModel.appendRow(QList<QStandardItem*>()
                         << new QStandardItem("row2.value1")
                         << new QStandardItem("row2.value2"));

    reportObject->setVariableValue("root", qlonglong(&rootModel));
    reportObject->setVariableValue("table", qlonglong(&tableModel));

    ReportPreview reportPreview;
    reportPreview.setReportCore(&core);
    reportPreview.connectReport(reportObject);
    reportPreview.show();
    reportPreview.run();

    return a.exec();
}
