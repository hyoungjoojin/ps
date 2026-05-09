CREATE
OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS
$$
BEGIN
RETURN QUERY (
    SELECT
        DISTINCT t.salary
    FROM
        (
            SELECT
                e.salary,
                DENSE_RANK() OVER(
                    ORDER BY
                        e.salary DESC
                ) AS r
            FROM
                Employee AS e
        ) AS t
    WHERE
        t.r = N
);

END;

$$
LANGUAGE plpgsql;
