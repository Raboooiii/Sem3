Implement DML commands like Insertion, Deletion, Modifying, Altering, and Updating records based on conditions.*
Consider the employee database given below
  emp (emp_id,emp_name, Street_No, city)
  works (emp_id, company name, salary)
  company (company name, city)
  manages (emp_id, manager_id)  

Note: Emp_id should start with ‘E’ in Emp table and emp_id in works table must be the emp_id from emptable .emp_id and manager_id in manages table must be the emp_id from emp table.

· Add these four tables with sufficient constraints.
· Alter table emp add a constraint that emp_name cannot be null
· Find the names of all employees who work for SBI.
· Find all employees in the database who live in the same cities as the companies for which they work.
· Find all employees and their managers in the database who live in the same cities and on the same street number as do their managers.
· Find all employees who earn more than the average salary of all employees of their company.
· Find the company that pay least total salary along with the salary paid.
· Give all managers of SBI a 10 percent raise.
· Find the company that has the most employees
· Find those companies whose employees earn a higher salary, on average than the average salary at Indian Bank.

Query to find the name and salary of all employees who earn more than each employee of ‘Indian Bank’

mysql> create database Works;

mysql> use Works;

mysql> CREATE TABLE emp (
    -> emp_id VARCHAR(10) PRIMARY KEY,
    -> emp_name VARCHAR(50) NOT NULL,
    -> Street_No INT,
    -> city VARCHAR(50)
    -> );

mysql> INSERT INTO emp (emp_id, emp_name, Street_No, city) VALUES
    -> ('E001', 'Rabeah', 101, 'Thiruvananthapuram'),
    -> ('E002', 'Amal', 102, 'Kochi'),
    -> ('E003', 'Thejus', 103, 'Kollam'),
    -> ('E004', 'Majida', 104, 'Alappuzha'),
    -> ('E005', 'Muhsina', 105, 'Kannur');

mysql> CREATE TABLE works (
    -> emp_id VARCHAR(10) PRIMARY KEY,
    -> company_name VARCHAR(50),
    -> salary DECIMAL(10,2),
    -> FOREIGN KEY (emp_id) REFERENCES emp(emp_id)
    -> );

mysql> INSERT INTO works (emp_id, company_name, salary) VALUES
    -> ('E001', 'SBI', 50000.00),
    -> ('E002', 'HDFC', 55000.00),
    -> ('E003', 'ICICI', 60000.00),
    -> ('E004', 'Axis Bank', 52000.00),
    -> ('E005', 'Canara Bank', 53000.00);

mysql> CREATE TABLE company (
    -> company_name VARCHAR(50) PRIMARY KEY,
    -> city VARCHAR(50)
    -> );

mysql> INSERT INTO company (company_name, city) VALUES
    -> ('SBI', 'Thiruvananthapuram'),
    -> ('HDFC', 'Kochi'),
    -> ('ICICI', 'Kollam'),
    -> ('Axis Bank', 'Alappuzha'),
    -> ('Canara Bank', 'Kannur');

mysql> CREATE TABLE manages (
    -> emp_id VARCHAR(10),
    -> manager_id VARCHAR(10),
    -> PRIMARY KEY (emp_id, manager_id),
    -> FOREIGN KEY (emp_id) REFERENCES emp(emp_id),
    -> FOREIGN KEY (manager_id) REFERENCES emp(emp_id)
    -> );

mysql> INSERT INTO manages (emp_id, manager_id) VALUES
    -> ('E001', 'E002'),
    -> ('E003', 'E004');

mysql> SELECT * FROM emp;
+--------+----------+-----------+--------------------+
| emp_id | emp_name | Street_No | city               |
+--------+----------+-----------+--------------------+
| E001   | Rabeah   |       101 | Thiruvananthapuram |
| E002   | Amal     |       102 | Kochi              |
| E003   | Thejus   |       103 | Kollam             |
| E004   | Majida   |       104 | Alappuzha          |
| E005   | Muhsina  |       105 | Kannur             |
+--------+----------+-----------+--------------------+

mysql> SELECT * FROM works;
+--------+--------------+----------+
| emp_id | company_name | salary   |
+--------+--------------+----------+
| E001   | SBI          | 50000.00 |
| E002   | HDFC         | 55000.00 |
| E003   | ICICI        | 60000.00 |
| E004   | Axis Bank    | 52000.00 |
| E005   | Canara Bank  | 53000.00 |
+--------+--------------+----------+

mysql> SELECT * FROM company;
+--------------+--------------------+
| company_name | city               |
+--------------+--------------------+
| Axis Bank    | Alappuzha          |
| Canara Bank  | Kannur             |
| HDFC         | Kochi              |
| ICICI        | Kollam             |
| SBI          | Thiruvananthapuram |
+--------------+--------------------+

mysql> SELECT * FROM manages;
+--------+------------+
| emp_id | manager_id |
+--------+------------+
| E001   | E002       |
| E003   | E004       |
+--------+------------+

mysql> ALTER TABLE emp ADD CONSTRAINT emp_name_not_null CHECK (emp_name IS NOT NULL);
mysql> desc emp;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| emp_id    | varchar(10) | NO   | PRI | NULL    |       |
| emp_name  | varchar(50) | NO   |     | NULL    |       |
| Street_No | int(11)     | YES  |     | NULL    |       |
| city      | varchar(50) | YES  |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+

mysql> SELECT e.emp_name
    -> FROM emp e
    -> INNER JOIN works w ON e.emp_id = w.emp_id
    -> WHERE w.company_name = 'SBI';
+----------+
| emp_name |
+----------+
| Rabeah   |
+----------+

mysql> SELECT e.emp_name, e.city
FROM emp e
INNER JOIN works w ON e.emp_id = w.emp_id
INNER JOIN company c ON w.company_name = c.company_name
WHERE e.city = c.city;
+----------+--------------------+
| emp_name | city               |
+----------+--------------------+
| Rabeah   | Thiruvananthapuram |
| Amal     | Kochi              |
| Thejus   | Kollam             |
| Majida   | Alappuzha          |
| Muhsina  | Kannur             |
+----------+--------------------+

mysql> SELECT e.emp_name AS Employee, m.emp_name AS Manager
    -> FROM emp e
    -> JOIN manages mg ON e.emp_id = mg.emp_id
    -> JOIN emp m ON mg.manager_id = m.emp_id
    -> WHERE e.city = m.city AND e.Street_No = m.Street_No;
Empty set (0.00 sec)

mysql> SELECT e.emp_name
    -> FROM emp e
    -> JOIN works w ON e.emp_id = w.emp_id
    -> WHERE w.salary > (
    ->     SELECT AVG(w2.salary)
    ->     FROM works w2
    ->     WHERE w2.company_name = w.company_name
    -> );
Empty set (0.00 sec)

mysql> SELECT w.company_name, SUM(w.salary) AS total_salary
    -> FROM works w
    -> GROUP BY w.company_name
    -> ORDER BY total_salary ASC
    -> LIMIT 1;
+--------------+--------------+
| company_name | total_salary |
+--------------+--------------+
| SBI          |     50000.00 |
+--------------+--------------+

mysql> UPDATE works w
    -> JOIN manages m ON w.emp_id = m.manager_id
    -> JOIN company c ON w.company_name = c.company_name
    -> SET w.salary = w.salary * 1.10
    -> WHERE c.company_name = 'SBI';

mysql> SELECT * FROM works;
+--------+--------------+----------+
| emp_id | company_name | salary   |
+--------+--------------+----------+
| E001   | SBI          | 50000.00 |
| E002   | HDFC         | 55000.00 |
| E003   | ICICI        | 60000.00 |
| E004   | Axis Bank    | 52000.00 |
| E005   | Canara Bank  | 53000.00 |
+--------+--------------+----------+

mysql> SELECT w.company_name
    -> FROM works w
    -> GROUP BY w.company_name
    -> ORDER BY COUNT(w.emp_id) DESC
    -> LIMIT 1;
+--------------+
| company_name |
+--------------+
| SBI          |
+--------------+

mysql> SELECT DISTINCT w.company_name
    -> FROM works w
    -> JOIN company c ON w.company_name = c.company_name
    -> WHERE (
    ->     SELECT AVG(w2.salary)
    ->     FROM works w2
    ->     JOIN company c2 ON w2.company_name = c2.company_name
    ->     WHERE c2.company_name = 'Indian Bank'
    -> ) < (
    ->     SELECT AVG(w3.salary)
    ->     FROM works w3
    ->     WHERE w3.company_name = w.company_name
    -> );
Empty set (0.00 sec)

mysql> SELECT e.emp_name, w.salary
    -> FROM emp e
    -> JOIN works w ON e.emp_id = w.emp_id
    -> WHERE w.salary > ALL (
    ->     SELECT w2.salary
    ->     FROM works w2
    ->     JOIN company c ON w2.company_name = c.company_name
    ->     WHERE c.company_name = 'Indian Bank'
    -> );
+----------+----------+
| emp_name | salary   |
+----------+----------+
| Rabeah   | 50000.00 |
| Amal     | 55000.00 |
| Thejus   | 60000.00 |
| Majida   | 52000.00 |
| Muhsina  | 53000.00 |
+----------+----------+
