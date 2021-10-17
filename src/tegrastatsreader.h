#ifndef TEGRASTATSREADER_H
#define TEGRASTATSREADER_H

#include <iostream>
#include <QObject>
#include <QProcess>

class TegraStatsReader : public QObject
{
    Q_OBJECT

public:
    TegraStatsReader(QObject *parent=nullptr);

private:
    QProcess process;
    QString command = "/usr/bin/tegrastats";

public slots:
    void onReadyStdout();
};

#endif // TEGRASTATSREADER_H
