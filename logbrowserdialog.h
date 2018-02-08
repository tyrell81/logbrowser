#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QTextBrowser;
class QPushButton;

class LogBrowserDialog : public QDialog
{
 Q_OBJECT

public:
 LogBrowserDialog(QWidget *parent = 0);
 ~LogBrowserDialog();

public slots:
 void outputMessage( QtMsgType type, const QString &msg );

protected slots:
 void save();

protected:
 virtual void keyPressEvent( QKeyEvent *e );
 virtual void closeEvent( QCloseEvent *e );

QTextBrowser *browser;
 QPushButton *clearButton;
 QPushButton *saveButton;
};

#endif // DIALOG_H
