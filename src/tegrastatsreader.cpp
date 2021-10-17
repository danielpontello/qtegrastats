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

    QStringList fields = stdout.split(" ");

    QRegularExpression bracketRe("\\[|\\]");
    QString CPU = fields.at(9);
    CPU = CPU.replace(bracketRe, "");

    QStringList cpuCores = CPU.split(",");

    QString cpu0Usage = cpuCores.at(0).split("@").at(0);
    QString cpu1Usage = cpuCores.at(1).split("@").at(0);
    QString cpu2Usage = cpuCores.at(2).split("@").at(0);
    QString cpu3Usage = cpuCores.at(3).split("@").at(0);

    setCpu0(cpu0Usage);
    setCpu1(cpu1Usage);
    setCpu2(cpu2Usage);
    setCpu3(cpu3Usage);

    std::cout << CPU.toStdString() << std::endl;
}

void TegraStatsReader::setCpu0(const QString &usage)
{
    if (m_cpu0 != usage) {
        m_cpu0 = usage;
        emit cpu0Changed();
    }
}

QString TegraStatsReader::getCpu0()
{
    return m_cpu0;
}

void TegraStatsReader::setCpu1(const QString &usage)
{
    if (m_cpu1 != usage) {
        m_cpu1 = usage;
        emit cpu1Changed();
    }
}

QString TegraStatsReader::getCpu1()
{
    return m_cpu1;
}

void TegraStatsReader::setCpu2(const QString &usage)
{
    if (m_cpu2 != usage) {
        m_cpu2 = usage;
        emit cpu2Changed();
    }
}

QString TegraStatsReader::getCpu2()
{
    return m_cpu2;
}

void TegraStatsReader::setCpu3(const QString &usage)
{
    if (m_cpu3 != usage) {
        m_cpu3 = usage;
        emit cpu3Changed();
    }
}

QString TegraStatsReader::getCpu3()
{
    return m_cpu3;
}
