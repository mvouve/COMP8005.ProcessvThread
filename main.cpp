
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QString>
#include <QVariant>
#include "controller.h"

/*!
 * \brief main
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[])
{
    Concurrency mode;
    QStringList arguments;

    if(argc < 4)
        parser.showHelp(0);

    mode = getMode(arguments.at(0));
    bool pass;
    quint64 maxPrime = QVariant(arguments.at(1)).toULongLong(&pass);
    if(!pass) {
        qDebug() << "Unrecognised max prime default to 100";
        maxPrime = 100;
    }

    qint32 childern = QVariant(arguments.at(2)).toInt(&pass);
    if(!pass) {
        qDebug() << "Unrecognised max prime default to 5";
        childern = 5;
    }

    Controller ctl(mode, maxPrime, childern);
    ctl.run();

    return 0;
}

//!
//! \brief getMode
//! \param mode
//! \return
//!
Concurrency getMode(QString mode)
{
    Concurrency mode;

    if(!(QString::compare(arguments.at(0), "thread", Qt::CaseInsensitive))) {
        mode = Concurrency::thread;
    } else if(!(QString::compare(arguments.at(0), "process", Qt::CaseInsensitive))) {
        mode = Concurrency::process;
    } else {
        qDebug() << "Unrecognised concurrency model, defaulting to process" << "\n";
        mode = Concurrency::process;
    }

    return mode;
}

//!
//! \brief getOpts
//! \param argc total number of arguments pasted
//! \param argv
//! \return
//!
QStringList getOpts(int argc, char *argv[])
{
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
    const QStringList args = parser.positionalArguments();


    return parser;
}

