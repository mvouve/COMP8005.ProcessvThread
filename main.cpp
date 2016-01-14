#include <QCoreApplication>
#include <QCommandLineParser>
#include <QString>
#include <QVariant>
#include "controller.h"

int main(int argc, char *argv[])
{
    Concurrency mode;

    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("File Hasher");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("hashes all files in a directory");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("[concurrency]", QCoreApplication::translate("main", "thread | process the type of concurrency to use"));
    parser.addPositionalArgument("[maximum prime]", QCoreApplication::translate("main", "the maximum value that could be processed"));
    parser.addPositionalArgument("[number of childern]", QCoreApplication::translate("main", "the maximum number of child threads or processes to use"));

    parser.process(a);


    if(argc < 4)
    {
        parser.showHelp();
    }

    const QStringList args = parser.positionalArguments();

    if(!(QString::compare(args.at(0), "thread", Qt::CaseInsensitive))) {
        mode = Concurrency::thread;
    }
    else if(!(QString::compare(args.at(0), "process", Qt::CaseInsensitive))) {
        mode = Concurrency::process;
    } else {
        qDebug() << "Unrecognised concurrency model, defaulting to process" << "\n";
        mode = Concurrency::process;
    }

    bool pass;
    quint64 maxPrime = QVariant(args.at(1)).toULongLong(&pass);
    if(!pass) {
        qDebug() << "Unrecognised max prime default to 100";
        maxPrime = 100;
    }

    qint32 childern = QVariant(args.at(2)).toInt(&pass);
    if(!pass) {
        qDebug() << "Unrecognised max prime default to 5";
        childern = 5;
    }


    Controller ctl(mode, maxPrime, childern);
    ctl.run();

    return 0;
}

