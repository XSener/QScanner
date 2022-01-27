#ifndef SCANNER_H
#define SCANNER_H

#include <QWidget>
#include <QAbstractSocket>                                                  // für die Sockets
#include <QTcpSocket>                                                          // für die Sockets

QT_BEGIN_NAMESPACE
namespace Ui { class Scanner; }
QT_END_NAMESPACE

class Scanner : public QWidget
{
    Q_OBJECT

public:
    Scanner(QWidget *parent = nullptr);
    ~Scanner();



private slots:
    void on_scanButton_clicked();


private:
    Ui::Scanner *ui;
    std::vector<int> m_ports;                   // vector in dem die Ports stehen
    QString m_hostname;                      // String für den Hostnamen
    QString m_portsStr;                         // String wo alle Ports drinnen stehen die nacher noch gesplitet werden
    QTcpSocket* m_socket;
};
#endif // SCANNER_H
