SELECT DISTINCT name FROM people
JOIN ratings, directors, movies
ON people.id = directors.person_id
AND  movies.id = ratings.movie_id
AND movies.id = ratings.movie_id
WHERE rating >= 9.0;
