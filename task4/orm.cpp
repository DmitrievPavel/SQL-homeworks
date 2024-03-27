#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>

class Book;

class Publisher {
public:
    std::string name = "";
    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Stock;

class Book {
public:
    std::string title = "";
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Shop {
public:
    std::string name = "";
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
    }
};

class Sale;

class Stock {
public:
    int count = 0;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale {
public:
    int price = 0;
    std::string date = "";
    int count = 0;
    Wt::Dbo::ptr<Stock> stock;

    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, date, "date");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, stock, "stock");
    }

};

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    std::string connectionStr = "host=localhost "
                                "port=5432 "
                                "dbname=homeworkbase "
                                "user=postgres "
                                "password=";

    try {
        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionStr);
        Wt::Dbo::Session session;
        session.setConnection(std::move(postgres));
        Wt::Dbo::Transaction transaction{ session };
        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");


        session.dropTables();
        session.createTables();

        std::unique_ptr<Publisher> p1{ new Publisher{"publisher1", {}} };
        std::unique_ptr<Publisher> p2{ new Publisher{"publisher2", {}} };
        std::unique_ptr<Publisher> p3{ new Publisher{"publisher3", {}} };

        auto p1db = session.add<Publisher>(std::move(p1));
        auto p2db = session.add<Publisher>(std::move(p2));
        auto p3db = session.add<Publisher>(std::move(p3));

        std::unique_ptr<Shop> s1{ new Shop {"shop1", {}} };
        std::unique_ptr<Shop> s2{ new Shop {"shop2", {}} };
        std::unique_ptr<Shop> s3{ new Shop {"shop3", {}} };

        auto s1db = session.add<Shop>(std::move(s1));
        auto s2db = session.add<Shop>(std::move(s2));
        auto s3db = session.add<Shop>(std::move(s3));

        std::unique_ptr<Book> b1{ new Book {"book1", p3db, {}} };
        std::unique_ptr<Book> b2{ new Book {"book2", p2db, {}} };
        std::unique_ptr<Book> b3{ new Book {"book3", p1db, {}} };

        auto b1db = session.add<Book>(std::move(b1));
        auto b2db = session.add<Book>(std::move(b2));
        auto b3db = session.add<Book>(std::move(b3));

        std::unique_ptr<Stock> st1{ new Stock{26,b1db,s1db,{}} };
        std::unique_ptr<Stock> st2{ new Stock{30,b2db,s2db,{}} };
        std::unique_ptr<Stock> st3{ new Stock{10,b3db,s3db,{}} };

        auto st1db = session.add<Stock>(std::move(st1));
        auto st2db = session.add<Stock>(std::move(st2));
        auto st3db = session.add<Stock>(std::move(st3));

        std::unique_ptr<Sale> sl1{ new Sale{150,"2024-01-09",10,st1db} };
        std::unique_ptr<Sale> sl2{ new Sale{110,"2024-04-29",15,st2db} };
        std::unique_ptr<Sale> sl3{ new Sale{90,"2024-11-11",24,st3db} };

        session.add<Sale>(std::move(sl1));
        session.add<Sale>(std::move(sl2));
        session.add<Sale>(std::move(sl3));
        transaction.commit();
        {
            Wt::Dbo::Transaction transaction2{ session };
            std::string input;
            int id = 0;
            bool is_num;
            std::cout << "Enter publisher name or id: " << std::endl;
            std::cin >> input;
            try {
                id = std::stoi(input);
                is_num = true;
            }
            catch (...) {
                is_num = false;
            }
            Wt::Dbo::ptr<Publisher> pub;
            if (is_num) {
                id = std::stoi(input);
                pub = session.find<Publisher>().where("id = ?").bind(id);
            }
            else {
                pub = session.find<Publisher>().where("name = ?").bind(input);
            }

            if (pub) {
                std::cout << "Publisher found: " << pub->name << std::endl;
                std::set<std::string> shops;
                std::set<std::string> books;
                for (const auto& book : pub->books) {
                    for (const auto& stock : book->stocks) {
                        shops.insert(stock->shop->name);
                    }
                    books.insert(book->title);
                }
                std::cout << "Publisher books: " << std::endl;
                for (const auto& books_title : books) {
                    std::cout << books_title << std::endl;
                }
                std::cout << "Shop names: " << std::endl;
                for (const auto& shopnames : shops) {
                    std::cout << shopnames << std::endl;
                }
            }
            else {
                std::cout << "Publisher not found" << std::endl;
            }

        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


