#include <QCoreApplication>
#include <QUdpSocket>
#include <QTextCodec>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(qApp->arguments().count() > 1)
    {
        QStringList vstr = qApp->arguments().at(1).split(",,");
        QUdpSocket *udpSocket = new QUdpSocket();
        if(udpSocket->bind(QHostAddress::AnyIPv4, 5566))
        {
            QHostAddress hostIP = QHostAddress(vstr.at(0));//IP地址
            int iPort = vstr.at(1).toUInt();//端口号
            QString strType = vstr.at(2);//消息类型，HEX或STR
            QString strMsg = vstr.at(3);//待发送消息
            QByteArray baMsg;//待发送消息

            if(strType == "HEX")
            {
                baMsg = QByteArray::fromHex(strMsg.toLatin1());
            }
            else if(strType == "STR")
            {
                QTextCodec *codec = QTextCodec::codecForName("GBK");
                baMsg = codec->fromUnicode(strMsg);
            }

            if(!baMsg.isEmpty())
            {
                udpSocket->writeDatagram(baMsg, hostIP, iPort);
            }

            udpSocket->close();//关闭连接
        }
    }

    //延时关闭
    QTimer::singleShot(50, [=]{
        qApp->exit(0);
    });

    return a.exec();
}
