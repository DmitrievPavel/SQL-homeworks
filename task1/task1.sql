CREATE TABLE IF NOT EXISTS Genre(
id serial PRIMARY KEY,
name varchar(60)
);

CREATE TABLE IF NOT EXISTS Performers(
id serial PRIMARY KEY,
name varchar(60)
);

CREATE TABLE IF NOT EXISTS Genre_Performers(
genre_id int NOT NULL REFERENCES Genre(id),
performers_id int NOT NULL REFERENCES Performers(id)
);

CREATE TABLE IF NOT EXISTS Album(
id serial PRIMARY KEY,
Performers_id integer NOT NULL REFERENCES Performers(id),
name varchar(60),
year_of_issue date
);

CREATE TABLE IF NOT EXISTS Performers_album(
album_id int NOT NULL REFERENCES Album(id),
performers_id int NOT NULL REFERENCES Performers(id)
);

CREATE TABLE IF NOT EXISTS Track(
id serial PRIMARY KEY,
album_id integer NOT NULL REFERENCES Album(id),
name varchar(60),
duration integer
);

CREATE TABLE IF NOT EXISTS Playlist(
id serial PRIMARY KEY,
name varchar(60),
year_of_issue date,
tracks integer NOT NULL REFERENCES Track(id)
);
