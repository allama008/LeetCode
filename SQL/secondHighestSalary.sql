/* Write your PL/SQL query statement below */
SELECT MAX(SALARY) AS SecondHighestSalary 
FROM EMPLOYEE
WHERE SALARY NOT IN
(SELECT MAX(SALARY)
FROM EMPLOYEE);