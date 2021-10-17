#ifndef TEGRASTATSREADER_H
#define TEGRASTATSREADER_H

#include <iostream>
#include <QObject>
#include <QProcess>
#include <QRegularExpression>

class TegraStatsReader : public QObject
{
    Q_OBJECT

    // CPU cores (there`s probably a better way of writing this)
    Q_PROPERTY(QString cpu0 READ getCpu0 WRITE setCpu0 NOTIFY cpu0Changed)
    Q_PROPERTY(QString cpu1 READ getCpu1 WRITE setCpu1 NOTIFY cpu1Changed)
    Q_PROPERTY(QString cpu2 READ getCpu2 WRITE setCpu2 NOTIFY cpu2Changed)
    Q_PROPERTY(QString cpu3 READ getCpu3 WRITE setCpu3 NOTIFY cpu3Changed)

public:
    TegraStatsReader(QObject *parent=nullptr);

    // CPU core usages
    void setCpu0(const QString &usage);
    QString getCpu0();

    void setCpu1(const QString &usage);
    QString getCpu1();

    void setCpu2(const QString &usage);
    QString getCpu2();

    void setCpu3(const QString &usage);
    QString getCpu3();

    QString getTest();

private:
    QProcess process;
    QString command = "/usr/bin/tegrastats";    

    QString m_cpu0;
    QString m_cpu1;
    QString m_cpu2;
    QString m_cpu3;

public slots:
    void onReadyStdout();

signals:
    void onDataReceived(QString receivedData);

    void cpu0Changed();
    void cpu1Changed();
    void cpu2Changed();
    void cpu3Changed();

};

#endif // TEGRASTATSREADER_H
