#include "include/config.h"
#include <QFile>

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

static SSystemConfig SystemConfigInfo;

SSystemConfig *GetSystemConfigInfo(void){
    return &SystemConfigInfo;
}



void SystemConfigUpdate(){
    QFile file(DEFAULT_CONFIG_FILE);

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(file.isOpen()){
        QJsonObject MainObject;


        QJsonObject rootSerialObj;
        rootSerialObj.insert("Com",SystemConfigInfo.m_SCom);
        rootSerialObj.insert("Baud",SystemConfigInfo.m_SBaud);
        rootSerialObj.insert("DataBits", SystemConfigInfo.m_SDataBits);
        rootSerialObj.insert("StopBits", SystemConfigInfo.m_SStopBits);
        rootSerialObj.insert("Parity", SystemConfigInfo.m_SParity);
        MainObject["Serial"] = rootSerialObj;

        QJsonObject rootDeviceObj;
        rootDeviceObj.insert("ID",SystemConfigInfo.m_SDeviceID);
        MainObject["Device"] = rootDeviceObj;

        QJsonObject rootPSocketObj;
        rootPSocketObj.insert("Protocol",SystemConfigInfo.m_SProtocol);
        rootPSocketObj.insert("IpAddr",SystemConfigInfo.m_SIpAddr);
        rootPSocketObj.insert("TcpPort",SystemConfigInfo.m_STCPPort);
        rootPSocketObj.insert("UdpPort",SystemConfigInfo.m_SUDPPort);
        rootPSocketObj.insert("LocalIpAddr",SystemConfigInfo.m_SLocalIpAddr);
        rootPSocketObj.insert("LocalPort",SystemConfigInfo.m_SLocalPort);
        MainObject["Socket"] = rootPSocketObj;

        QJsonDocument document;
        document.setObject(MainObject);
        QByteArray byteArray = document.toJson(QJsonDocument::Compact);
        QString strJson(byteArray);

        file.write(byteArray,byteArray.size());
        qDebug()<<strJson;

        file.close();
    }
}

void SystemConfigInfoInit(void)
{
    QFile file(DEFAULT_CONFIG_FILE);

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(file.isOpen()){                                 //是否是新创建的文件
        QString JsonConfigString = file.readAll();
        file.close();

        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(JsonConfigString.toUtf8(),&parseJsonErr);

        if(parseJsonErr.error == QJsonParseError::NoError){
            QJsonObject jsonObject = document.object();
            qDebug() << jsonObject;
            if(jsonObject.contains(QStringLiteral("Serial")))
            {
                QJsonValue jsonValueList = jsonObject.value(QStringLiteral("Serial"));
                SystemConfigInfo.m_SCom = jsonValueList.toObject()["Com"].toString();
                SystemConfigInfo.m_SBaud = jsonValueList.toObject()["Baud"].toString();
                SystemConfigInfo.m_SDataBits = jsonValueList.toObject()["DataBits"].toString();
                SystemConfigInfo.m_SStopBits = jsonValueList.toObject()["StopBits"].toString();
                SystemConfigInfo.m_SParity = jsonValueList.toObject()["Parity"].toString();
            }

            if(jsonObject.contains(QStringLiteral("Device")))
            {
                QJsonValue jsonValueList = jsonObject.value(QStringLiteral("ID"));
                SystemConfigInfo.m_SDeviceID = jsonValueList.toObject()["ID"].toString();
            }

            if(jsonObject.contains(QStringLiteral("Socket")))
            {
                QJsonValue jsonValueList = jsonObject.value(QStringLiteral("Socket"));
                SystemConfigInfo.m_SProtocol = jsonValueList.toObject()["Protocol"].toString();
                SystemConfigInfo.m_SIpAddr = jsonValueList.toObject()["IpAddr"].toString();
                SystemConfigInfo.m_STCPPort = jsonValueList.toObject()["TcpPort"].toString();
                SystemConfigInfo.m_SUDPPort = jsonValueList.toObject()["UdpPort"].toString();
                SystemConfigInfo.m_SLocalIpAddr = jsonValueList.toObject()["LocalIpAddr"].toString();
                SystemConfigInfo.m_SLocalPort = jsonValueList.toObject()["LocalPort"].toString();
                qDebug()<<SystemConfigInfo.m_SProtocol;
            }
        }
        else
            qDebug() << QString("Config Json file Parse Error,Use Default");
    }
    else                                //打开失败?什么情况下会打开失败?
        SystemConfigUpdate();

}
