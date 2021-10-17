#include "tegrastatsreader.h"

TegraStatsReader::TegraStatsReader(QObject* parent) :
    QObject(parent),
    process(parent)
{
    connect(&process, &QProcess::readyReadStandardOutput, this, &TegraStatsReader::onReadyStdout);

    process.setProgram(command);
    process.start();
}

void TegraStatsReader::onReadyStdout()
{
    QString stdout = process.readAllStandardOutput();
    std::cout << stdout.toStdString() << std::endl;
}
