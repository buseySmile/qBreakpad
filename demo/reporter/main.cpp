/* This file is in public domain. */

#include <BreakpadSender.h>

#include <QCoreApplication>
#include <QTimer>
#include <QString>
#include <QUrl>
#include <QDebug>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);
	BreakpadQt::Sender sender(QUrl(QLatin1String("http://localhost:8080/breakpad-test/receiver")));
	sender.addParameter(QLatin1String("param1"), QLatin1String("value1"));
	sender.setFile(qApp->applicationFilePath());
	sender.send();

	app.connect(&sender, SIGNAL(done(bool)), SLOT(quit()));
	int res = app.exec();
	sender.wait();
	return res;
}
