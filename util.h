#ifndef util_h
#define util_h

#include <memory.h>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <zlib.h>

struct packet_info {
    std::string src_addr;
    std::string dst_addr;
    bool        is_fin;
    std::string body;
};

extern bool is_atty;

#define USE_ANSI_COLOR

#ifdef USE_ANSI_COLOR
#define ANSI_COLOR_RED     (is_atty ? "\x1b[31m" : "")
#define ANSI_COLOR_GREEN   (is_atty ? "\x1b[32m" : "")
#define ANSI_COLOR_YELLOW  (is_atty ? "\x1b[33m" : "")
#define ANSI_COLOR_BLUE    (is_atty ? "\x1b[34m" : "")
#define ANSI_COLOR_MAGENTA (is_atty ? "\x1b[35m" : "")
#define ANSI_COLOR_CYAN    (is_atty ? "\x1b[36m" : "")
#define ANSI_COLOR_RESET   (is_atty ? "\x1b[0m"  : "")
#else
#define ANSI_COLOR_RED     ""
#define ANSI_COLOR_GREEN   ""
#define ANSI_COLOR_YELLOW  ""
#define ANSI_COLOR_BLUE    ""
#define ANSI_COLOR_MAGENTA ""
#define ANSI_COLOR_CYAN    ""
#define ANSI_COLOR_RESET   ""
#endif  // USE_ANSI_COLOR

std::string encode_base64(const std::string data);

bool is_plain_text(const std::string &s);

void get_join_addr(const std::string &src_addr, const std::string &dst_addr, std::string &ret);

std::string timeval2tr(const struct timeval *ts);

bool gzip_decompress(std::string &src, std::string &dst);

std::string urlencode(const std::string &s);

#endif
