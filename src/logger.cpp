#include "logger.hpp"

// Define static members here
LogLevel Logger::m_level = LogLevel::Info; // Default log level
std::mutex Logger::m_mutex;                // Mutex for thread safety
