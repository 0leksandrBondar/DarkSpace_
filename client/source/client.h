#pragma once

#include "ClientData/clientdata.h"

#include <QObject>

class QTcpSocket;

class Client : public QObject
{
	Q_OBJECT
public:
	Client();

	void onRedyRead();

signals:
	void recivedSignUpRequestStatus(bool status);
	void recivedSignInRequestStatus(bool status);
	void userIsConnectedToServer(const QString& userName);
	void getMessageFromServer(const QString& data, const QString& userName);

public slots:
	void setUsername(const QString& newUsername);

	// ----- send some data to server
	void sendClientDataToServer(const ClientData& data);

	// ----- init message data from UI

	void fillMessageData(const QString& text);
	void fillSignInData(const QString& login, const QString& password);
	void fillSignUpData(const QString& login, const QString& password, const QString& userName);

	// ----- search user in server

	void searchUser(const QString& userName);

private:
	void processingClientDataFromServer(ClientDataType type);

private:
	QString _username;
	QTcpSocket* _socket;
	ClientData _dataFromServer;
	QVector<QString> _listOfOwnChats;
};
