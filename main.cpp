#include <QCoreApplication>
#include <QCommandLineParser>
#include "controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("File Hasher");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("hashes all files in a directory");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("sorce", QCoreApplciation::translate("main", "Directory to hash"));

    parser.process(a);

    const QStringList args = parser.positionalArguments();
    Conntroller ctl = new Controller(args.at(0));
    ctl.run();

    return a.exec();
}

