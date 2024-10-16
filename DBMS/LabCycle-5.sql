5.     Implementation of Order By,Group By & Having clause & implementation of constraints *

Create two tables
Depart(Department ID,Departmentname,managerid,loc)
Emp(emp-no,name,job,salary,hiredate,commission,Department no.)
manager id is the emp-no of the employee whom the emplyee reports to. Department no. is a foreign key. Insert values into the tables.
·       Display the name and salary for all employee whose salary is not in the range of 5000 and 35000;
·       Display the employee name, job ID and start date of employees hired between february 20,1990 and May 1,1998. Order the query in ascending order by start date
·       List the name and salary of employees who earn between 5000 and 12000 and are in department 2 0r 4. Label the columns Employee and Monthly Salary respectively.
·       Display names and hire date of every employee who was hired in 1994.
·       Display the name,salary and commission for all employees who earn commissions. Sort data in descending order of salary and commissions.
·       Display the name and job title of all employees who do not have a manager.
·       Display the name of all employee where the third letter of the name is an  ‘a’.
·       Display the name of all employees who have ana and an e in their name.
·       Display the  name, job, and salary for all employees whose job is sales representative or stock clerk and whose salary is not equal to 2,0000, 4000, or 7,000.
·       Write a query to display the  name, department number, and department name for all employees.
·       Write a query that displays the employee numbers names of all employees who work in a department with any employee whose name contains a u.
·       Write a query to display the name and hire date of any employee in the same department as amit. Exclude JOHN.


mysql> CREATE table Depart (department_id int primary key , dep_name varchar (50) , manager_id int , loc varchar(50));

mysql> CREATE table Emp (emp_no int primary key , name varchar(50) , job varchar(50) ,hiredate date , commission float , department_no int);

mysql> drop table Emp;

mysql> CREATE table Emp (emp_no int primary key , name varchar(50) , job varchar(50), salary decimal (10,2)  ,hiredate date , commission float , department_no int , foreign key (department_no) references Depart(department_id));

mysql> insert into Depart(department_id , dep_name , manager_id , loc) values  (1," Sales" , 101 , "New York" );

mysql> insert into Depart  values  (2,"Marketing" , 102 , "Chicago" );

mysql> insert into Depart  values  (3,"IT" , 103 , "Fransisco" );

mysql> insert into Depart  values  (4,"HR" , 104 , "India" );

mysql> insert into Depart  values  (5,"sales" , 105 , "Indonesia" );

mysql> desc Depart;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| department_id | int         | NO   | PRI | NULL    |       |
| dep_name      | varchar(50) | YES  |     | NULL    |       |
| manager_id    | int         | YES  |     | NULL    |       |
| loc           | varchar(50) | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+

mysql> select * from Depart;
+---------------+-----------+------------+-----------+
| department_id | dep_name  | manager_id | loc       |
+---------------+-----------+------------+-----------+
|             1 |  Sales    |        101 | New York  |
|             2 | Marketing |        102 | Chicago   |
|             3 | IT        |        103 | Fransisco |
|             4 | HR        |        104 | India     |
|             5 | sales     |        105 | Indonesia |
+---------------+-----------+------------+-----------+

mysql> insert into Emp values (101 , "John" , "Manager" , 40000, '1988-01-22' , Null , 1);

mysql> insert into Emp values (102 , "Alice" , "Analyst" , 40000, '1998-09-02' , 500 , 2);

mysql> select * from Depart;
+---------------+-----------+------------+-----------+
| department_id | dep_name  | manager_id | loc       |
+---------------+-----------+------------+-----------+
|             1 |  Sales    |        101 | New York  |
|             2 | Marketing |        102 | Chicago   |
|             3 | IT        |        103 | Fransisco |
|             4 | HR        |        104 | India     |
|             5 | sales     |        105 | Indonesia |
+---------------+-----------+------------+-----------+

mysql> select * from Emp;
+--------+-------+---------+----------+------------+------------+---------------+
| emp_no | name  | job     | salary   | hiredate   | commission | department_no |
+--------+-------+---------+----------+------------+------------+---------------+
|    101 | John  | Manager | 40000.00 | 1988-01-22 |       NULL |             1 |
|    102 | Alice | Analyst | 40000.00 | 1998-09-02 |        500 |             2 |
+--------+-------+---------+----------+------------+------------+---------------+

mysql> insert into Emp values (103 , "James" , "Reporter" , 36000, '2000-01-22' , 300 , 5);

mysql> insert into Emp values (104 , "Alina" , "Manager" , 50000, '1985-11-08' , 1000 , 4);

mysql> insert into Emp values (105 , "Arun" , "Sales" , 10000, '2001-12-08' , 100 , 3);

mysql> select * from Emp;
+--------+-------+----------+----------+------------+------------+---------------+
| emp_no | name  | job      | salary   | hiredate   | commission | department_no |
+--------+-------+----------+----------+------------+------------+---------------+
|    101 | John  | Manager  | 40000.00 | 1988-01-22 |       NULL |             1 |
|    102 | Alice | Analyst  | 40000.00 | 1998-09-02 |        500 |             2 |
|    103 | James | Reporter | 36000.00 | 2000-01-22 |        300 |             5 |
|    104 | Alina | Manager  | 50000.00 | 1985-11-08 |       1000 |             4 |
|    105 | Arun  | Sales    | 10000.00 | 2001-12-08 |        100 |             3 |
+--------+-------+----------+----------+------------+------------+---------------+


mysql> select name , salary from Emp where salary not between 5000 and 35000;
+-------+----------+
| name  | salary   |
+-------+----------+
| John  | 40000.00 |
| Alice | 40000.00 |
| James | 36000.00 |
| Alina | 50000.00 |
+-------+----------+

mysql> select name , job , hiredate  from Emp where hiredate between "1990-02-20" and "1998-05-01";
Empty set (0.00 sec)

mysql> select name as Employee ,salary as "monthly salary"  from Emp where salary  between 5000 and 12000 and department_no in (2,4);
Empty set (0.00 sec)

mysql> select name , job , hiredate  from Emp where hiredate between "1990-02-20" and "2000-05-01";
+-------+----------+------------+
| name  | job      | hiredate   |
+-------+----------+------------+
| Alice | Analyst  | 1998-09-02 |
| James | Reporter | 2000-01-22 |
+-------+----------+------------+

mysql> select name as Employee ,salary as "monthly salary"  from Emp where salary  between 50000 and 12000 and department_no in (2,5);
Empty set (0.00 sec)

mysql> select name , hiredate  from Emp where year(hiredate)="1994";
Empty set (0.00 sec)

mysql> select name , hiredate  from Emp where year(hiredate)="1998";
+-------+------------+
| name  | hiredate   |
+-------+------------+
| Alice | 1998-09-02 |
+-------+------------+

mysql> select name , salary , commission from Emp 
    -> where commission is not null
    -> order by salary , commission desc;
+-------+----------+------------+
| name  | salary   | commission |
+-------+----------+------------+
| Arun  | 10000.00 |        100 |
| James | 36000.00 |        300 |
| Alice | 40000.00 |        500 |
| Alina | 50000.00 |       1000 |
+-------+----------+------------+

mysql> select name from Emp;
+-------+
| name  |
+-------+
| John  |
| Alice |
| James |
| Alina |
| Arun  |
+-------+

mysql> select name , salary , commission from Emp
    -> where commission is not null
    -> order by salary , commission DESC;
+-------+----------+------------+
| name  | salary   | commission |
+-------+----------+------------+
| Arun  | 10000.00 |        100 |
| James | 36000.00 |        300 |
| Alice | 40000.00 |        500 |
| Alina | 50000.00 |       1000 |
+-------+----------+------------+

mysql> select name , salary , commission from Emp
    -> where commission is not null
    -> order by salary , commission ASC;
+-------+----------+------------+
| name  | salary   | commission |
+-------+----------+------------+
| Arun  | 10000.00 |        100 |
| James | 36000.00 |        300 |
| Alice | 40000.00 |        500 |
| Alina | 50000.00 |       1000 |
+-------+----------+------------+

mysql> select name , salary , commission from Emp
    -> where commission is not null
    -> order by salary DESC , commission DESC;
+-------+----------+------------+
| name  | salary   | commission |
+-------+----------+------------+
| Alina | 50000.00 |       1000 |
| Alice | 40000.00 |        500 |
| James | 36000.00 |        300 |
| Arun  | 10000.00 |        100 |
+-------+----------+------------+

mysql> select name , job
    -> from Emp
    -> where emp_no not in (select manager_id from Depart);
Empty set (0.00 sec)

mysql> select name from Emp where name like '__a%';
Empty set (0.01 sec)

mysql> select name from Emp where name like '__i%';
+-------+
| name  |
+-------+
| Alice |
| Alina |
+-------+

mysql> select name from Emp where name like '*n%';
Empty set (0.00 sec)

mysql> select name from Emp where name like '_n_%';
Empty set (0.00 sec)

mysql> select name from Emp where name like '___n_%';
+-------+
| name  |
+-------+
| Alina |
+-------+

mysql> select name from Emp where name like '%a%' and name like '%e%';
+-------+
| name  |
+-------+
| Alice |
| James |
+-------+

mysql> select name , job ,salary from Emp where job in ('Clerk' , 'Analyst' ) and salary not in (2000,700,10000);
+-------+---------+----------+
| name  | job     | salary   |
+-------+---------+----------+
| Alice | Analyst | 40000.00 |
+-------+---------+----------+

mysql> select emp_no , name from Emp where department_no in(select department_no from Emp where name like '%u%' );
+--------+------+
| emp_no | name |
+--------+------+
|    105 | Arun |
+--------+------+

mysql> select name , hiredate from Emp where department_no = ( select department_no from Emp where name ='Alice') and Name <> 'JOHN';
+-------+------------+
| name  | hiredate   |
+-------+------------+
| Alice | 1998-09-02 |
+-------+------------+

mysql> insert into Depart  values  (6,"sales" , Null , "Canada" );

mysql> select * from Depart;
+---------------+-----------+------------+-----------+
| department_id | dep_name  | manager_id | loc       |
+---------------+-----------+------------+-----------+
|             1 |  Sales    |        101 | New York  |
|             2 | Marketing |        102 | Chicago   |
|             3 | IT        |        103 | Fransisco |
|             4 | HR        |        104 | India     |
|             5 | sales     |        105 | Indonesia |
|             6 | sales     |       NULL | Canada    |
+---------------+-----------+------------+-----------+

mysql> select name , job from Emp where emp_no not in (select manager_id from Depart);
Empty set (0.00 sec)
