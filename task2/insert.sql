insert into genre(name)
values ('metalcore');

insert into genre(name)
values ('progressive metalcore');

insert into genre(name)
values ('deathcore');

insert into genre(name)
values ('hardcore');

insert into genre(name)
values ('post hardcore');

insert into genre(name)
values ('djent');

insert into performers (name)
values ('Every Hour Kills');

insert into performers (name)
values ('By The Thousands');

insert into performers (name)
values ('Erra');

insert into performers (name)
values ('Vildhjarta');

insert into performers (name)
values ('Alpha Wolf');

insert into performers (name)
values ('Reflections');

insert into performers (name)
values ('Chelsea Grin');

insert into performers (name)
values ('S');

insert into album (name, year_of_issue)
values ('The Descent', '2019-01-08');

insert into album (name, year_of_issue)
values ('Cure', '2020-04-05');

insert into album (name, year_of_issue)
values ('Willow', '2018-10-13');

insert into album (name, year_of_issue)
values ('Passing', '2021-11-21');

insert into album (name, year_of_issue)
values ('Inward', '2020-09-26');

insert into album (name, year_of_issue)
values ('Heavener', '2019-03-03');

insert into album (name, year_of_issue)
values ('Eternal blue', '2020-08-22');

insert into genre_performers 
values (1, 1);

insert into genre_performers 
values (1, 2);

insert into genre_performers 
values (2, 1);

insert into genre_performers 
values (2, 2);

insert into genre_performers 
values (3, 6);

insert into genre_performers 
values (3, 7);

insert into genre_performers 
values (4, 8);

insert into genre_performers 
values (5, 8);

insert into genre_performers 
values (6, 4);

insert into performers_album 
values (1, 1);

insert into performers_album 
values (2, 2);

insert into performers_album 
values (3, 3);

insert into performers_album 
values (4, 4);

insert into performers_album 
values (5, 5);

insert into performers_album 
values (6, 6);

insert into performers_album 
values (7, 7);

insert into performers_album 
values (7, 8);

insert into track (album_id, "name",duration)
values (1, 'Comatose', '00:03:20');

insert into track (album_id, "name",duration)
values (1, 'Unbound', '00:04:48');

insert into track (album_id, "name",duration)
values (2, 'Acheron', '00:04:32');

insert into track (album_id, "name",duration)
values (2, 'Cursed', '00:03:40');

insert into track (album_id, "name",duration)
values (3, 'The Flood', '00:02:52');

insert into track (album_id, "name",duration)
values (3, 'Deadweight', '00:03:30');

insert into track (album_id, "name",duration)
values (4, 'Shiver', '00:04:25');

insert into track (album_id, "name",duration)
values (4, 'Parasite', '00:02:53');

insert into track (album_id, "name",duration)
values (5, 'Tempest', '00:02:56');

insert into track (album_id, "name",duration)
values (5, 'Darkest Frame', '00:03:52');

insert into track (album_id, "name",duration)
values (6, 'Werifesteria', '00:04:06');

insert into track (album_id, "name",duration)
values (6, 'mytrack', '00:04:08');

insert into track (album_id, "name",duration)
values (7, 'Nemesis', '00:05:17');

insert into playlist ("name", year_of_issue)
values ('playlist1','2017-03-21');

insert into playlist ("name", year_of_issue)
values ('playlist2','2019-03-21');

insert into playlist ("name", year_of_issue)
values ('playlist3','2018-05-23');

insert into playlist ("name", year_of_issue)
values ('playlist4','2020-12-21');

insert into playlist ("name", year_of_issue)
values ('playlist5','2021-08-24');

insert into playlist_track 
values (1, 1);

insert into playlist_track 
values (1, 5);

insert into playlist_track 
values (1, 6);

insert into playlist_track 
values (2, 4);

insert into playlist_track 
values (2, 1);

insert into playlist_track 
values (2, 7);

insert into playlist_track 
values (3, 8);

insert into playlist_track 
values (3, 9);

insert into playlist_track 
values (4, 10);

insert into playlist_track 
values (4, 11);

insert into playlist_track 
values (5, 12);
