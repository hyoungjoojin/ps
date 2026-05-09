SELECT
    e.employee_id
FROM
    Employees AS e
WHERE
    e.salary < 30000
    AND e.manager_id IS NOT NULL
    AND e.manager_id NOT IN (
        SELECT
            m.employee_idd
        FROM
            Employees AS m
    )
ORDER BY
    e.employee_id;
