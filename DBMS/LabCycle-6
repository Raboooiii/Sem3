6. Implementation of set operators, nested queries and Join queries and verify the relationship*
Consider the schema for the Movie Database.

ACTOR(Act_id, Act_Name, Act_Geander)
DIRECTOR(Dir_id, Dir_Name, Dir_Phone)
MOVIES(Mov_id, Mov_Title, Mov_Year, Mov_Lang, Dir_id)
MOVIE_CAST(Act_id, Mov_id, Role)
RATING(Mov_id, Rev_Stars)

Write queries to:
·       List the title of all movies directed by 'Hitch Cock'.
·       Find the movie names where one or more actors acted in two or more movies.
·       List all actors who acted in a movie before 2000 or in a movie after 2015 (use JOIN operation)
·       Update rating of all movies directed by 'Steven Spielberg' to 5.
·       Find the title of movies and number of stars for each movie that has atleast one rating and find the highest number of stars that movie received. Sort the result by movie title.

mysql> create database Cinema;

mysql> use Cinema;
Database changed
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| Cinema             |
| Student            |
| Work               |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| university         |
+--------------------+

mysql> create table ACTOR (Act_id int primary key, Act_name varchar(20), Act_Gender varchar(6));

mysql> create table DIRECTOR (Dir_id int primary key, Dir_name varchar(20), Dir_Phone int(10));

mysql> create table MOVIES (Mov_id int primary key, Mov_Title varchar(20), Mov_Year int(4), Mov_Lang varchar(10), Dir_id int, foreign key (Dir_id) references DIRECTOR(Dir_id));

mysql> create table MOVIE (Mov_id int primary key, Mov_Title varchar(20), Mov_Year int(4), Mov_Lang varchar(10), Dir_id int, foreign key (Dir_id) references DIRECTOR(Dir_id));

mysql> delete table MOVIE;

mysql> drop table MOVIE;

mysql> create table MOVIE_CAST (Act_id int, foreign key (Act_id) references ACTOR(Act_id), Mov_id int, foreign key (Mov_id) references MOVIES(Mov_id), Role varchar(20));

mysql> create table RATING (Mov_id int, foreign key (Mov_id) references MOVIES(Mov_id), Rev_Stars int);

mysql> desc ACTOR;
+------------+-------------+------+-----+---------+-------+
| Field      | Type        | Null | Key | Default | Extra |
+------------+-------------+------+-----+---------+-------+
| Act_id     | int         | NO   | PRI | NULL    |       |
| Act_name   | varchar(20) | YES  |     | NULL    |       |
| Act_Gender | varchar(6)  | YES  |     | NULL    |       |
+------------+-------------+------+-----+---------+-------+

mysql> desc MOVIES;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| Mov_id    | int         | NO   | PRI | NULL    |       |
| Mov_Title | varchar(20) | YES  |     | NULL    |       |
| Mov_Year  | int         | YES  |     | NULL    |       |
| Mov_Lang  | varchar(10) | YES  |     | NULL    |       |
| Dir_id    | int         | YES  | MUL | NULL    |       |
+-----------+-------------+------+-----+---------+-------+

mysql> desc MOVIE_CAST;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| Act_id | int         | YES  | MUL | NULL    |       |
| Mov_id | int         | YES  | MUL | NULL    |       |
| Role   | varchar(20) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+

mysql> desc DIRECTOR;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| Dir_id    | int         | NO   | PRI | NULL    |       |
| Dir_name  | varchar(20) | YES  |     | NULL    |       |
| Dir_Phone | int         | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+

mysql> desc RATING;
+-----------+------+------+-----+---------+-------+
| Field     | Type | Null | Key | Default | Extra |
+-----------+------+------+-----+---------+-------+
| Mov_id    | int  | YES  | MUL | NULL    |       |
| Rev_Stars | int  | YES  |     | NULL    |       |
+-----------+------+------+-----+---------+-------+

mysql> insert into ACTOR values (100, 'Tom Holland', 'M'),(101, 'RDJ', 'M'), (102, 'Marget Robbie', 'F'),(103, 'Scarlet Johanson', 'F');

mysql> insert into DIRECTOR values (11, 'Christopher Nolan', 123456789),(22, 'Hitch Cock', 987654321), (33, 'Prithviraj', 147258369);
mysql> insert into DIRECTOR values(44, 'Steven Spielberg', 702595820);

mysql> Select * from ACTOR;
+--------+------------------+------------+
| Act_id | Act_name         | Act_Gender |
+--------+------------------+------------+
|    100 | Tom Holland      | M          |
|    101 | RDJ              | M          |
|    102 | Marget Robbie    | F          |
|    103 | Scarlet Johanson | F          |
+--------+------------------+------------+

mysql> Select * from DIRECTOR;
+--------+-------------------+-----------+
| Dir_id | Dir_name          | Dir_Phone |
+--------+-------------------+-----------+
|     11 | Christopher Nolan | 123456789 |
|     22 | Hitch Cock        | 987654321 |
|     33 | Prithviraj        | 147258369 |
|     44 | Steven Spielberg  | 702595820 |
+--------+-------------------+-----------+
4 rows in set (0.00 sec)

mysql> insert into MOVIES values(1, 'Sherlock Holmes', 2011, 'Eng', 22),(2, 'Now You See Me', 2009, 'Eng', 22),(3, 'Theja Bhai & Family', 2002, 'Malayalam', 33), (4, 'Interstellar', 1998, 'Japanese',11), (5, 'Prestige', 1999, 'Hindi', 44), (6, 'Coco', 2018, 'English', 44);

mysql> Select * from MOVIES;
+--------+---------------------+----------+-----------+--------+
| Mov_id | Mov_Title           | Mov_Year | Mov_Lang  | Dir_id |
+--------+---------------------+----------+-----------+--------+
|      1 | Sherlock Holmes     |     2011 | Eng       |     22 |
|      2 | Now You See Me      |     2009 | Eng       |     22 |
|      3 | Theja Bhai & Family |     2002 | Malayalam |     33 |
|      4 | Interstellar        |     1998 | Japanese  |     11 |
|      5 | Prestige            |     1999 | Hindi     |     44 |
|      6 | Coco                |     2018 | English   |     44 |
+--------+---------------------+----------+-----------+--------+

mysql> Select * from ACTOR;
+--------+------------------+------------+
| Act_id | Act_name         | Act_Gender |
+--------+------------------+------------+
|    100 | Tom Holland      | M          |
|    101 | RDJ              | M          |
|    102 | Marget Robbie    | F          |
|    103 | Scarlet Johanson | F          |
+--------+------------------+------------+

mysql> Select * from DIRECTOR;
+--------+-------------------+-----------+
| Dir_id | Dir_name          | Dir_Phone |
+--------+-------------------+-----------+
|     11 | Christopher Nolan | 123456789 |
|     22 | Hitch Cock        | 987654321 |
|     33 | Prithviraj        | 147258369 |
|     44 | Steven Spielberg  | 702595820 |
+--------+-------------------+-----------+

mysql> insert into MOVIES values(1, 'Sherlock Holmes', 2011, 'Eng', 22),(2, 'Now You See Me', 2009, 'Eng', 22),(3, 'Theja Bhai & Family', 2002, 'Malayalam', 33), (4, 'Interstellar', 1998, 'Japanese',11), (5, 'Prestige', 1999, 'Hindi', 44), (6, 'Coco', 2018, 'English', 44);

mysql> Select * from MOVIES;
+--------+---------------------+----------+-----------+--------+
| Mov_id | Mov_Title           | Mov_Year | Mov_Lang  | Dir_id |
+--------+---------------------+----------+-----------+--------+
|      1 | Sherlock Holmes     |     2011 | Eng       |     22 |
|      2 | Now You See Me      |     2009 | Eng       |     22 |
|      3 | Theja Bhai & Family |     2002 | Malayalam |     33 |
|      4 | Interstellar        |     1998 | Japanese  |     11 |
|      5 | Prestige            |     1999 | Hindi     |     44 |
|      6 | Coco                |     2018 | English   |     44 |
+--------+---------------------+----------+-----------+--------+

mysql> desc MOVIE_CAST;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| Act_id | int         | YES  | MUL | NULL    |       |
| Mov_id | int         | YES  | MUL | NULL    |       |
| Role   | varchar(20) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+

mysql> insert into MOVIE_CAST values(101, 1, 'Detective'),(102, 2, 'Con Artist'),(100, 4, 'Protagonist'), (103, 3, 'MC'), (101, 5, 'Time Traveller'), (100, 6,'Voice Actor'); 
mysql> insert into MOVIE_CAST values(101, 1, 'Detective'),(102, 2, 'Con Artist'),(100, 4, 'Protagonist'), (103, 3, 'MC'), (101, 5, 'Time Traveller'), (100, 6,'Voice Actor');

mysql> Select * from MOVIE_CAST;
+--------+--------+----------------+
| Act_id | Mov_id | Role           |
+--------+--------+----------------+
|    101 |      1 | Detective      |
|    102 |      2 | Con Artist     |
|    100 |      4 | Protagonist    |
|    103 |      3 | MC             |
|    101 |      5 | Time Traveller |
|    100 |      6 | Voice Actor    |
|    101 |      1 | Detective      |
|    102 |      2 | Con Artist     |
|    100 |      4 | Protagonist    |
|    103 |      3 | MC             |
|    101 |      5 | Time Traveller |
|    100 |      6 | Voice Actor    |
+--------+--------+----------------+

mysql> desc RATING;
+-----------+------+------+-----+---------+-------+
| Field     | Type | Null | Key | Default | Extra |
+-----------+------+------+-----+---------+-------+
| Mov_id    | int  | YES  | MUL | NULL    |       |
| Rev_Stars | int  | YES  |     | NULL    |       |
+-----------+------+------+-----+---------+-------+

mysql> insert into RATING values(1, 3),(2, 2),(3, 4), (4, 5), (5, 2), (6, 1);

mysql> Select * from RATING;
+--------+-----------+
| Mov_id | Rev_Stars |
+--------+-----------+
|      1 |         3 |
|      2 |         2 |
|      3 |         4 |
|      4 |         5 |
|      5 |         2 |
|      6 |         1 |
+--------+-----------+

mysql> SELECT Mov_Title 
    -> FROM MOVIES 
    -> WHERE Dir_id = (SELECT Dir_id FROM DIRECTOR WHERE Dir_Name = 'Hitch Cock');
+-----------------+
| Mov_Title       |
+-----------------+
| Sherlock Holmes |
| Now You See Me  |
+-----------------+

mysql> SELECT DISTINCT M.Mov_Title
    -> FROM MOVIES M
    -> JOIN MOVIE_CAST MC ON M.Mov_id = MC.Mov_id
    -> WHERE MC.Act_id IN (
    ->     SELECT Act_id
    ->     FROM MOVIE_CAST
    ->     GROUP BY Act_id
    ->     HAVING COUNT(DISTINCT Mov_id) >= 2
    -> );
+-----------------+
| Mov_Title       |
+-----------------+
| Sherlock Holmes |
| Interstellar    |
| Prestige        |
| Coco            |
+-----------------+

mysql> SELECT DISTINCT A.Act_Name
    -> FROM ACTOR A
    -> JOIN MOVIE_CAST MC ON A.Act_id = MC.Act_id
    -> JOIN MOVIES M ON MC.Mov_id = M.Mov_id
    -> WHERE M.Mov_Year < 2000 OR M.Mov_Year > 2015;
+-------------+
| Act_Name    |
+-------------+
| Tom Holland |
| RDJ         |
+-------------+

mysql> UPDATE RATING
    -> SET Rev_Stars = 5
    -> WHERE Mov_id IN (
    ->     SELECT Mov_id
    ->     FROM MOVIES
    ->     WHERE Dir_id = (SELECT Dir_id FROM DIRECTOR WHERE Dir_Name = 'Steven Spielberg')
    -> );

mysql> Select * from RATING;
+--------+-----------+
| Mov_id | Rev_Stars |
+--------+-----------+
|      1 |         3 |
|      2 |         2 |
|      3 |         4 |
|      4 |         5 |
|      5 |         5 |
|      6 |         5 |
+--------+-----------+

mysql> SELECT M.Mov_Title, MAX(R.Rev_Stars) AS Highest_Stars
    -> FROM MOVIES M
    -> JOIN RATING R ON M.Mov_id = R.Mov_id
    -> GROUP BY M.Mov_Title
    -> HAVING COUNT(R.Rev_Stars) > 0
    -> ORDER BY M.Mov_Title;
+---------------------+---------------+
| Mov_Title           | Highest_Stars |
+---------------------+---------------+
| Coco                |             5 |
| Interstellar        |             5 |
| Now You See Me      |             2 |
| Prestige            |             5 |
| Sherlock Holmes     |             3 |
| Theja Bhai & Family |             4 |
+---------------------+---------------+
+--------+-------------+------+-----+---------+-------+
| Act_id | int         | YES  | MUL | NULL    |       |
| Mov_id | int         | YES  | MUL | NULL    |       |
| Role   | varchar(20) | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+

mysql> insert into MOVIE_CAST values(101, 1, 'Detective'),(102, 2, 'Con Artist'),(100, 4, 'Protagonist'), (103, 3, 'MC'), (101, 5, 'Time Traveller'), (100, 6,'Voice Actor'); 

mysql> insert into MOVIE_CAST values(101, 1, 'Detective'),(102, 2, 'Con Artist'),(100, 4, 'Protagonist'), (103, 3, 'MC'), (101, 5, 'Time Traveller'), (100, 6,'Voice Actor');

mysql> Select * from MOVIE_CAST;
+--------+--------+----------------+
| Act_id | Mov_id | Role           |
+--------+--------+----------------+
|    101 |      1 | Detective      |
|    102 |      2 | Con Artist     |
|    100 |      4 | Protagonist    |
|    103 |      3 | MC             |
|    101 |      5 | Time Traveller |
|    100 |      6 | Voice Actor    |
|    101 |      1 | Detective      |
|    102 |      2 | Con Artist     |
|    100 |      4 | Protagonist    |
|    103 |      3 | MC             |
|    101 |      5 | Time Traveller |
|    100 |      6 | Voice Actor    |
+--------+--------+----------------+

mysql> desc RATING;
+-----------+------+------+-----+---------+-------+
| Field     | Type | Null | Key | Default | Extra |
+-----------+------+------+-----+---------+-------+
| Mov_id    | int  | YES  | MUL | NULL    |       |
| Rev_Stars | int  | YES  |     | NULL    |       |
+-----------+------+------+-----+---------+-------+

mysql> insert into RATING values(1, 3),(2, 2),(3, 4), (4, 5), (5, 2), (6, 1);

mysql> Select * from RATING;
+--------+-----------+
| Mov_id | Rev_Stars |
+--------+-----------+
|      1 |         3 |
|      2 |         2 |
|      3 |         4 |
|      4 |         5 |
|      5 |         2 |
|      6 |         1 |
+--------+-----------+

mysql> SELECT Mov_Title 
    -> FROM MOVIES 
    -> WHERE Dir_id = (SELECT Dir_id FROM DIRECTOR WHERE Dir_Name = 'Hitch Cock');
+-----------------+
| Mov_Title       |
+-----------------+
| Sherlock Holmes |
| Now You See Me  |
+-----------------+

mysql> SELECT DISTINCT M.Mov_Title
    -> FROM MOVIES M
    -> JOIN MOVIE_CAST MC ON M.Mov_id = MC.Mov_id
    -> WHERE MC.Act_id IN (
    ->     SELECT Act_id
    ->     FROM MOVIE_CAST
    ->     GROUP BY Act_id
    ->     HAVING COUNT(DISTINCT Mov_id) >= 2
    -> );
+-----------------+
| Mov_Title       |
+-----------------+
| Sherlock Holmes |
| Interstellar    |
| Prestige        |
| Coco            |
+-----------------+

mysql> SELECT DISTINCT A.Act_Name
    -> FROM ACTOR A
    -> JOIN MOVIE_CAST MC ON A.Act_id = MC.Act_id
    -> JOIN MOVIES M ON MC.Mov_id = M.Mov_id
    -> WHERE M.Mov_Year < 2000 OR M.Mov_Year > 2015;
+-------------+
| Act_Name    |
+-------------+
| Tom Holland |
| RDJ         |
+-------------+

mysql> UPDATE RATING
    -> SET Rev_Stars = 5
    -> WHERE Mov_id IN (
    ->     SELECT Mov_id
    ->     FROM MOVIES
    ->     WHERE Dir_id = (SELECT Dir_id FROM DIRECTOR WHERE Dir_Name = 'Steven Spielberg')
    -> );

mysql> Select * from RATING;
+--------+-----------+
| Mov_id | Rev_Stars |
+--------+-----------+
|      1 |         3 |
|      2 |         2 |
|      3 |         4 |
|      4 |         5 |
|      5 |         5 |
|      6 |         5 |
+--------+-----------+

mysql> SELECT M.Mov_Title, MAX(R.Rev_Stars) AS Highest_Stars
    -> FROM MOVIES M
    -> JOIN RATING R ON M.Mov_id = R.Mov_id
    -> GROUP BY M.Mov_Title
    -> HAVING COUNT(R.Rev_Stars) > 0
    -> ORDER BY M.Mov_Title;
+---------------------+---------------+
| Mov_Title           | Highest_Stars |
+---------------------+---------------+
| Coco                |             5 |
| Interstellar        |             5 |
| Now You See Me      |             2 |
| Prestige            |             5 |
| Sherlock Holmes     |             3 |
| Theja Bhai & Family |             4 |
+---------------------+---------------+
