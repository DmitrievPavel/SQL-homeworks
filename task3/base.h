#pragma once
#include<iostream>
#include<pqxx/pqxx>

class Database {
private:
	pqxx::connection connection;
public:
	Database(const std::string& connectionstr) : connection(connectionstr) {};
	Database(const Database& other) = delete;
	Database& operator=(const Database& other) = delete;
	Database() = delete;
	~Database() = default;
	void createTables();
	void addClient(const std::string&& firstname, const std::string&& lastname, const std::string&& email);
	void addPhone(const int&& id, const std::string&& phonenumber);
	void updateClient(const int&& id, const std::string&& firstname, const std::string&& lastname, const std::string&& email);
	void deletePhone(const int&& client_id);
	void deleteClient(const int&& client_id);
	void findClient(const std::string&& data);
};