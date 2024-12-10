/**
 * @file logger.hpp
 */
#pragma once

#include <iostream>
#include <mutex>
#include <string>

namespace Rasterfari {

/// @brief Enum class representing the different log levels.
enum LogLevel {
    Debug = 0,
    Info  = 1,
    Warn  = 2,
    Error = 3,
};

/// @brief The singelton used for logging.
class Logger {
private:
    /// @brief Used to ensure thread safety when logging.
    static std::mutex m_mutex;
    /// @brief The current level of logs to be displayed.
    static LogLevel m_level;

    /// @brief Default constructor.
    Logger() {}

    /**
     * @brief The main logging function used by other log functions.
     * @param indicator A string showing the level to print at
     * @param level The enum level.
     * @param msg The message to be logged.
     * @param args Any number of additional arguments to be logged.
     */
    template <typename... Args>
    static void Log(std::string indicator, LogLevel level, std::string msg,
                    Args... args) {
        // only log levels greater than current log level
        if (level >= m_level) {
            // acquire lock for thread safety
            std::unique_lock lock(m_mutex);

            // log it please :))
            std::cout << indicator << " " << msg;
            ((std::cout << ' ' << args), ...);
            std::cout << std::endl;
        }
    }

public:
    /// @brief Disable copy constructor
    Logger(const Logger &logger) = delete;

    /// @brief Updates the level of logging.
    static void setLevel(LogLevel level) { m_level = level; }

    /// @brief Log at Debug level.
    template <typename... Args>
    static void Debug(const std::string &msg, Args... args) {
        Log("\x1b[92m[Debug]\033[0m", LogLevel::Debug, msg, args...);
    }

    /// @brief Log at Info level.
    template <typename... Args>
    static void Info(const std::string &msg, Args... args) {
        Log("\x1b[94m[Info]\033[0m", LogLevel::Info, msg, args...);
    }

    /// @brief Log at Warn level.
    template <typename... Args>
    static void Warn(const std::string &msg, Args... args) {
        Log("\x1b[93m[Warn]\033[0m", LogLevel::Warn, msg, args...);
    }

    /// @brief Log at Error level.
    template <typename... Args>
    static void Error(const std::string &msg, Args... args) {
        Log("\x1b[91m[Error]\033[0m", LogLevel::Error, msg, args...);
    }
};

} // namespace Rasterfari