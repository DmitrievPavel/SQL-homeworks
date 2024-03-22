#include"base.h"

void Database::createTables() {
	pqxx::work tr(connection);
	tr.exec("CREATE TABLE IF NOT EXISTS Clientinfo("
		"id SERIAL PRIMARY KEY,"
		"firstname VARCHAR(50) NOT NULL,"
		"lastname VARCHAR(50) NOT NULL,"
		"email VARCHAR(50) NOT NULL);"
		"CREATE TABLE IF NOT EXISTS ClientPhoneNumbers("
		"client_id INTEGER NOT NULL REFERENCES Clientinfo(id),"
		"Phonenumber VARCHAR(50) NOT NULL);");
	tr.commit();
}

void Database::addClient(const std::string&& firstname, const std::string&& lastname, const std::string&& email) {
	pqxx::work tr(connection);
	tr.exec("INSERT INTO Clientinfo(firstname,lastname,email) "
		"VALUES('" + tr.esc(firstname) + "', '" + tr.esc(lastname) + "', '" + tr.esc(email) + "')");
	tr.commit();
}

void Database::addPhone(const int&& id, const std::string&& phonenumber) {
	pqxx::work tr(connection);
	tr.exec("INSERT INTO ClientPhoneNumbers "
		"VALUES(" + std::to_string(id) + ", '" + tr.esc(phonenumber) + "')");
	tr.commit();
}

void Database::updateClient(const int&& id, const std::string&& firstname, const std::string&& lastname, const std::string&& email) {
	pqxx::work tr(connection);
	tr.exec("UPDATE Clientinfo "
		"SET firstname = '" + tr.esc(firstname) + "', lastname = '" + tr.esc(lastname) + "', email = '" + tr.esc(email) + "'"
		"WHERE id = " + std::to_string(id));
	tr.commit();
}

void Database::deletePhone(const int&& client_id) {
	pqxx::work tr(connection);
	tr.exec("DELETE FROM ClientPhoneNumbers WHERE client_id = " + std::to_string(client_id));
	tr.commit();
}

void Database::deleteClient(const int&& client_id) {
	pqxx::work tr(connection);
	tr.exec("DELETE FROM Clientinfo WHERE id = " + std::to_string(client_id));
	tr.commit();
}

void Database::findClient(const std::string&& data) {
	pqxx::work tr(connection);
	std::string query = "SELECT id from clientinfo c "
		"LEFT JOIN clientphonenumbers n ON c.id = n.client_id "
		"WHERE firstname = '" + tr.esc(data) + "' OR lastname = '" + tr.esc(data) + "' OR email = '" + tr.esc(data) + "' OR n.phonenumber = '" + tr.esc(data) + "'";
	for (auto [id] : tr.query<int>(query)) {
		std::cout << "id: " << id << std::endl;
	}
	tr.commit();
}