# Write your MySQL query statement below
Select
    class
From
    Courses
Group by 
    class
having count(student) >= 5