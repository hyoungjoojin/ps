SELECT
    DISTINCT results
FROM
    (
        SELECT
            u.name AS results
        FROM
            MovieRating AS r
            JOIN Users AS u ON r.user_id = u.user_id
        GROUP BY
            u.name
        ORDER BY
            COUNT(*) DESC,
            u.name
        LIMIT
            1
    )
UNION
ALL (
    SELECT
        m.title AS results
    FROM
        MovieRating AS r
        JOIN Movies AS m ON r.movie_id = m.movie_id
    WHERE
        r.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY
        m.title
    ORDER BY
        AVG(r.rating) DESC,
        m.title
    LIMIT
        1
);
