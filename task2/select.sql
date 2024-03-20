-- Название и продолжительность самого длительного трека.
select "name" 
from track
order by duration desc 
limit 1;

-- Название треков, продолжительность которых не менее 3,5 минут.
select "name" 
from track
where duration >= '00:03:30';

-- Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
select "name" 
from playlist
where year_of_issue between '2018-01-01' and '2020-12-31';

-- Исполнители, чьё имя состоит из одного слова.
select "name" 
from performers
where "name"  not like '% %';

--Название треков, которые содержат слова «мой» или «my».
select "name"  
from track
where "name"  like '%my%';

--Количество исполнителей в каждом жанре.
select g."name", count(gp.performers_id)  from genre_performers gp
join genre g on g.id = gp.genre_id  
group by g."name" ;

--Количество треков, вошедших в альбомы 2019–2020 годов.
select a."name", count(t.id) from album a 
join track t on a.id = t.album_id 
where year_of_issue between '2019-01-01' and '2020-12-31'
group by a."name" ;

--Средняя продолжительность треков по каждому альбому.
select a."name", avg(t.duration) from album a 
join track t on a.id = t.album_id 
group by a."name";

--Все исполнители, которые не выпустили альбомы в 2020 году.
select p."name" from performers p 
join performers_album pa on pa.performers_id = p.id 
join album a on a.id = pa.album_id 
where a.year_of_issue not between '2020-01-01' and '2020-12-31'
group by p."name";

--Названия сборников, в которых присутствует конкретный исполнитель (выберите его сами).
select pl."name" from performers p
join performers_album pa on pa.performers_id = p.id 
join album a on a.id = pa.album_id 
join track t on t.album_id = a.id 
join playlist_track pt on pt.track_id = t.id 
join playlist pl on pl.id = pt.playlist_id 
where p."name" = 'Alpha Wolf'
group by pl."name" ;
