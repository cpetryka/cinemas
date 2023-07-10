//
// Created by Cezary Petryka on 20.10.2020.
//

#include "../seance_repository.hpp"

void SeanceRepository::insert(const Seance &seance) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "insert into seances(movie_id, cinema_room_id, date_time) values (?, ?, ?)";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance.movie_id);
    sqlite3_bind_int(stmt, 2, seance.cinema_room_id);
    sqlite3_bind_text(stmt, 3, seance.date_time.c_str(), -1, SQLITE_STATIC);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

void SeanceRepository::update(const int id, const Seance &seance) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "update seances set movie_id = ?, cinema_room_id = ?, date_time = ? where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance.movie_id);
    sqlite3_bind_int(stmt, 2, seance.cinema_room_id);
    sqlite3_bind_text(stmt, 3, seance.date_time.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 4, id);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

void SeanceRepository::remove(const int id) {
    const auto connection = DbConnection::get_instance()->get_connection();
    const std::string sql = "delete from seances where id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    if(sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_errmsg(connection);
        throw TableOperationException{ sqlite3_errmsg(connection) };
    }

    sqlite3_finalize(stmt);
}

std::optional<int> SeanceRepository::find_pos(const Seance &seance) {
    const std::string sql = "select id from seances where movie_id = ? and cinema_room_id = ? and date_time = ?";
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, seance.movie_id);
    sqlite3_bind_int(stmt, 2, seance.cinema_room_id);
    sqlite3_bind_text(stmt, 3, seance.date_time.c_str(), -1, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        return std::make_optional(sqlite3_column_int(stmt, 0));
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

std::vector<std::unique_ptr<SeanceWithMovie>>
SeanceRepository::find_all_by_parameters(const std::string &genre, const std::string &city, const std::string& date, const std::string &time) {
    std::vector<std::unique_ptr<SeanceWithMovie>> seance_with_movie;

    const std::string sql = "select s.id, s.movie_id, s.cinema_room_id, s.date_time, m.title, m.genre, m.author from seances s join movies m on s.movie_id = m.id join cinema_rooms cr on s.cinema_room_id = cr.id join cinemas c on cr.cinema_id = c.id where m.genre = ? and c.city = ? and ((strftime('%s', s.date_time) - strftime('%s', ?)) between 0 and 86399) and strftime('%H', s.date_time) >= ?";
    // 86400 to liczba sekund w jednym dniu, operator between ... and bierze rowniez pod uwage maksymalna wartosc, dlatego daje 86399
    const auto connection = DbConnection::get_instance()->get_connection();
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(connection, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, genre.c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 2, city.c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 3, date.c_str(), -1, nullptr);
    sqlite3_bind_text(stmt, 4, time.c_str(), -1, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        seance_with_movie.emplace_back(std::make_unique<SeanceWithMovie>(
                sqlite3_column_int(stmt, 0),
                sqlite3_column_int(stmt, 1),
                sqlite3_column_int(stmt, 2),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 3)),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 4)),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 5)),
                Utils::convert_sqlite3_column_text_to_string(sqlite3_column_text(stmt, 6))
        ));
    }

    sqlite3_finalize(stmt);
    return seance_with_movie;
}