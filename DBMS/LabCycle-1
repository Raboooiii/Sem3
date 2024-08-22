· Create a database using DDL commands and writes DQL queries to retrieve information from the database.*
· Create a table STUDENT with following attributes: student_id, Name, department, mark 1, mark 2, cgpa and insert a minimum of 5 values to it.
· Create table hostel_details with following attributes: std_id, stud_name, block, roomno and insert 5 rows for the table
· Display the details of student and hostel_details table
· Rename table hostel_details to hostel
· Update the value of CGPA whose student_id is 5 from cgpa 9.1 to 8
· Display the name of the students whose cgpa is more than 8
· Display the name of student staying in block A of the table hostel
· Display name of student who belong to cs dept.
· Delete the name of student whose room number is 108
Modify the department of the student’ anu’ from cs to ec


mysql> CREATE TABLE STUDENT (
    ->     student_id INT PRIMARY KEY,
    ->     Name VARCHAR(50),
    ->     department VARCHAR(50),
    ->     mark1 INT,
    ->     mark2 INT,
    ->     cgpa FLOAT
    -> );

mysql> INSERT INTO STUDENT VALUES 
    ->     (01, 'Rabeah', 'CS', 85, 90, 8.5),
    ->     (02, 'Karthik', 'ME', 75, 85, 8.0),
    ->     (03, 'Jeevan', 'IT', 90, 96, 9.3),
    ->     (04, 'Anu', 'CS',70, 85, 7.5),
    ->     (05, 'Krishna', 'EC', 90, 92, 9.1),
    ->     (06, 'Amal', 'EEE', 8);

mysql> CREATE TABLE hostel_details (
    ->     std_id INT PRIMARY KEY,
    ->     stud_name VARCHAR(50),
    ->     block VARCHAR(10),
    ->     roomno INT
    -> );

mysql> INSERT INTO hostel_details VALUES 
    ->     (01, 'Rabeah', 'A', 101),
    ->     (02, 'Karthik', 'B', 102),
    ->     (03, 'Jeevan', 'A', 101),
    ->     (04, 'Anu', 'C',104 ),
    ->     (05, 'Krishna', 'C', 105),
    ->     (06, 'Amal', 'B', '108');

mysql> SELECT * FROM STUDENT;
+------------+---------+------------+-------+-------+------+
| student_id | Name    | department | mark1 | mark2 | cgpa |
+------------+---------+------------+-------+-------+------+
|          1 | Rabeah  | CS         |    85 |    90 |  8.5 |
|          2 | Karthik | ME         |    75 |    85 |    8 |
|          3 | Jeevan  | IT         |    90 |    96 |  9.3 |
|          4 | Anu     | CS         |    70 |    85 |  7.5 |
|          5 | Krishna | EC         |    90 |    92 |  9.1 |
|          6 | Amal    | EEE        |    86 |    96 |  9.2 |
+------------+---------+------------+-------+-------+------+

mysql> SELECT * FROM hostel_details;
+--------+-----------+-------+--------+
| std_id | stud_name | block | roomno |
+--------+-----------+-------+--------+
|      1 | Rabeah    | A     |    101 |
|      2 | Karthik   | B     |    102 |
|      3 | Jeevan    | A     |    101 |
|      4 | Anu       | C     |    104 |
|      5 | Krishna   | C     |    105 |
|      6 | Amal      | B     |    108 |
+--------+-----------+-------+--------+

mysql> RENAME TABLE hostel_details TO Hostel;

mysql> SELECT * FROM Hostel;
+--------+-----------+-------+--------+
| std_id | stud_name | block | roomno |
+--------+-----------+-------+--------+
|      1 | Rabeah    | A     |    101 |
|      2 | Karthik   | B     |    102 |
|      3 | Jeevan    | A     |    101 |
|      4 | Anu       | C     |    104 |
|      5 | Krishna   | C     |    105 |
|      6 | Amal      | B     |    108 |
+--------+-----------+-------+--------+

mysql> UPDATE STUDENT
    -> SET cgpa = 8.0
    -> WHERE student_id = 5;

mysql> SELECT Name
    -> FROM STUDENT
    -> WHERE cgpa > 8;
+--------+
| Name   |
+--------+
| Rabeah |
| Jeevan |
+--------+

mysql> SELECT stud_name
    -> FROM Hostel
    -> WHERE block = 'A';
+-----------+
| stud_name |
+-----------+
| Rabeah    |
| Jeevan    |
+-----------+

mysql> SELECT Name
    -> FROM STUDENT
    -> WHERE department = 'CS';
+--------+
| Name   |
+--------+
| Rabeah |
| Anu    |
+--------+

mysql> DELETE FROM STUDENT
    -> WHERE student_id = (
    ->     SELECT std_id
    ->     FROM Hostel
    ->     WHERE roomno = 108
    -> );

mysql> UPDATE STUDENT
    -> SET department = 'EC'
    -> WHERE Name = 'anu' AND department = 'CS';

mysql> SELECT * FROM STUDENT;
+------------+---------+------------+-------+-------+------+
| student_id | Name    | department | mark1 | mark2 | cgpa |
+------------+---------+------------+-------+-------+------+
|          1 | Rabeah  | CS         |    85 |    90 |  8.5 |
|          2 | Karthik | ME         |    75 |    85 |    8 |
|          3 | Jeevan  | IT         |    90 |    96 |  9.3 |
|          4 | Anu     | EC         |    70 |    85 |  7.5 |
|          5 | Krishna | EC         |    90 |    92 |    8 |
+------------+---------+------------+-------+-------+------+

mysql> SELECT * FROM Hostel;
+--------+-----------+-------+--------+
| std_id | stud_name | block | roomno |
+--------+-----------+-------+--------+
|      1 | Rabeah    | A     |    101 |
|      2 | Karthik   | B     |    102 |
|      3 | Jeevan    | A     |    101 |
|      4 | Anu       | C     |    104 |
|      5 | Krishna   | C     |    105 |
|      6 | Amal      | B     |    108 |
+--------+-----------+-------+--------+
